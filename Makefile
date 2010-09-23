CFLAGS = -Iinclude -Ivernier_goio_sdk -DTARGET_OS_MAC -arch i386 -arch ppc -arch x86_64

CC=g++

SWIG = swig
# SWIG = /cygdrive/c/swig-1.3.21/swig

QUERY_OBJS = nativelib/test/QueryDevice.o nativelib/test/CCSensorUtils.o 
PRINTDATA_OBJS = nativelib/test/PrintData.o nativelib/test/CCSensorUtils.o 
PSEUDO_OBJS = nativelib/PseudoSensorDevice.o
TI_OBJS = nativelib/TISensorDevice.o

SWIG_OUTPUT_DIR = src/swig/java

#OSX_LINK_FLAGS = -framework IOKit -framework CoreFoundation -framework CoreServices -framework Carbon -lstdc++
# scytacki: To compile this for older operating systems something 
# like this is needed: -isysroot /Developer/SDKs/MacOSX10.4.sdk -Wl,-syslibroot,/Developer/SDKs/MacOSX10.4.sdk 
OSX_LINK_FLAGS = -bind_at_load -framework IOKit -framework Cocoa -framework Carbon -I/System/Library/Frameworks/JavaVM.framework/Headers -arch i386 -arch ppc -arch x86_64

# this is used to build native test executables
# this filter grabs the .o and .lib files from the dependency list
define build-static-executable
$(CC) -o $@  $(filter %.o %.lib %.a %.dylib ,$^)  $(OSX_LINK_FLAGS)
endef

# this builds a jni comptable dll with gcc
# this filter grabs the .o and .lib files from the dependency list
define build-jni-dll
$(CC) -bundle $(filter %.o %.lib %.a,$^) -o $@ -framework JavaVM $(OSX_LINK_FLAGS)
#gcc -bundle $(filter %.o %.lib %.dylib,$^) -o $@ -framework JavaVM
endef

all: vernier_swig

nativelib/test/%.o : src/c/test/%.c include/CCSensorDevice.h src/c/test/CCSensorUtils.h nativelib/test
	$(CC) $(CFLAGS) -c $< -o $@

nativelib/swig/%.o : src/swig/%.c nativelib/swig
	$(CC) -c $< -I/System/Library/Frameworks/JavaVM.framework/Headers -Iinclude -o $@
#  This was used to force the native library to use the 1.3.1 headers, I think 
#    this was need before, but now 1.4 is required.
#	$(CC) -c $< -I/System/Library/Frameworks/JavaVM.framework/Versions/1.3.1/Headers -Iinclude -o $@

nativelib/%.o : src/c/%.c include/CCSensorDevice.h nativelib nativelib/test
	$(CC) $(CFLAGS) -c $< -o $@

bin bin/local nativelib nativelib/test nativelib/swig $(SWIG_OUTPUT_DIR)/ccsd/vernier $(SWIG_OUTPUT_DIR)/ccsd/pseudo $(SWIG_OUTPUT_DIR)/ccsd/ti:
	mkdir -p $@

.PHONY : vernier_swig vernier_mac_jnilib vernier_mac_lipo vernier_mac_nar_archives ti_swig pseudo_swig

# you must install swig to run this target. http://swig.org
# it expects the binary to be on your path and the include files to
# be in a stardard include folder.

######### Vernier targets ###########
GOLINK_OBJS = nativelib/GoLinkSensorDevice.o vernier_goio_sdk/libGoIO_DLL.a
#GOLINK_OBJS = nativelib/GoLinkSensorDevice.o vernier_goio_sdk/libGoIO_DLL.dylib

vernier_swig : include/CCSensorDevice.h src/swig/CCSensorDevice.i $(SWIG_OUTPUT_DIR)/ccsd/vernier
	$(SWIG) -java -c++ -Iinclude -package ccsd.vernier -outdir src/swig/java/ccsd/vernier -o src/swig/VernierSensorDevice_wrap.c src/swig/CCSensorDevice.i  

bin/local/libvernier_ccsd.jnilib : 	$(GOLINK_OBJS) nativelib/swig/VernierSensorDevice_wrap.o bin/local
	$(build-jni-dll)

bin/GoLinkQuery : $(QUERY_OBJS) $(GOLINK_OBJS) bin
	$(build-static-executable)
 
bin/GoLinkPrintData : $(GOLINK_OBJS) $(PRINTDATA_OBJS) bin
	$(build-static-executable)

vernier_mac_jnilib :
	g++ -mmacosx-version-min=10.4 -Iinclude -Ivernier_goio_sdk -DTARGET_OS_MAC -arch i386 -arch ppc -arch x86_64 -c src/swig/VernierSensorDevice_wrap.c -I/System/Library/Frameworks/JavaVM.framework/Headers -Iinclude -o nativelib/swig/VernierSensorDevice_wrap.o
	g++ -mmacosx-version-min=10.4 -Iinclude -Ivernier_goio_sdk -DTARGET_OS_MAC -arch i386 -arch ppc -arch x86_64 -c src/c/GoLinkSensorDevice.c -I/System/Library/Frameworks/JavaVM.framework/Headers -Iinclude -o nativelib/GoLinkSensorDevice.o
	g++ -mmacosx-version-min=10.4 -bundle nativelib/GoLinkSensorDevice.o nativelib/swig/VernierSensorDevice_wrap.o vernier_goio_sdk/libGoIO_DLL.a -o bin/local/libvernier_ccsd.jnilib -framework JavaVM -bind_at_load -framework IOKit -framework Cocoa -framework Carbon -lstdc++ -I/System/Library/Frameworks/JavaVM.framework/Headers -arch i386 -arch ppc -arch x86_64
	
vernier_mac_lipo : 
	mkdir -p bin/ppc7400
	mkdir -p bin/i386
	mkdir -p bin/x86_64
	lipo -extract ppc7400 bin/local/libvernier_ccsd.jnilib -output bin/ppc7400/libvernier_ccsd.jnilib
	lipo -extract i386    bin/local/libvernier_ccsd.jnilib -output bin/i386/libvernier_ccsd.jnilib
	lipo -extract x86_64  bin/local/libvernier_ccsd.jnilib -output bin/x86_64/libvernier_ccsd.jnilib

vernier_mac_nar_archives :
	mkdir -p target/native-lib
	rm -rf target/native-lib/*
	cp bin/ppc7400/libvernier_ccsd.jnilib target/native-lib
	jar cf target/vernier-goio-macosx-ppc-nar.jar -C target/native-lib .
	rm -rf target/native-lib/*
	cp bin/i386/libvernier_ccsd.jnilib target/native-lib
	jar cf target/vernier-goio-macosx-i386-nar.jar -C target/native-lib .
	rm -rf target/native-lib/*
	cp bin/x86_64/libvernier_ccsd.jnilib target/native-lib
	jar cf target/vernier-goio-macosx-x86_64-nar.jar -C target/native-lib .

######## TI targets ############
ti_swig : include/CCSensorDevice.h src/swig/CCSensorDevice.i $(SWIG_OUTPUT_DIR)/ccsd/ti
	$(SWIG) -java -Iinclude -package ccsd.ti -outdir src/swig/java/ccsd/ti -o src/swig/TISensorDevice_wrap.c src/swig/CCSensorDevice.i  

bin/ti_ccsd.dll : 	ti_swig $(TI_OBJS) nativelib/swig/TISensorDevice_wrap.o bin
	$(build-jni-dll)

bin/TIQuery : $(QUERY_OBJS) $(TI_OBJS)
	$(build-static-executable)

bin/TIPrintData : $(PRINTDATA_OBJS) $(TI_OBJS) 
	$(build-static-executable)

######## Pseudo targets ############
pseudo_swig : include/CCSensorDevice.h src/swig/CCSensorDevice.i $(SWIG_OUTPUT_DIR)/ccsd/pseudo
	$(SWIG) -java -Iinclude -package ccsd.pseudo -outdir src/swig/java/ccsd/pseudo -o src/swig/PseudoSensorDevice_wrap.c src/swig/CCSensorDevice.i  

bin/QueryPseudo : $(QUERY_OBJS) $(PSEUDO_OBJS) 
	$(build-static-executable)

clean:

# remove the default rule so we can change the source
# and lib folders
%.o : %.c	