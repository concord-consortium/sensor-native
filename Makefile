CFLAGS = -Iinclude -Iinclude/GoIO

#SWIG = swig
SWIG = /cygdrive/c/swig-1.3.21/swig

QUERY_OBJS = nativelib/test/QueryDevice.o nativelib/test/CCSensorUtils.o 
PRINTDATA_OBJS = nativelib/test/PrintData.o nativelib/test/CCSensorUtils.o 
PSEUDO_OBJS = nativelib/PseudoSensorDevice.o
GOLINK_OBJS = nativelib/GoLinkSensorDevice.o GoIO_DLL.lib
TI_OBJS = nativelib/TISensorDevice.o

SWIG_OUTPUT_DIR = src/swig/java

# this is used to build native test executables
# this filter grabs the .o and .lib files from the dependency list
define build-static-executable
gcc -o $@ $(filter %.o %.lib,$^)  
endef

# this builds a jni comptable dll with gcc
# this filter grabs the .o and .lib files from the dependency list
define build-jni-dll
gcc -mno-cygwin -shared $(filter %.o %.lib,$^) -Wl,--add-stdcall-alias -o $@
endef

all: vernier_swig

nativelib/test/%.o : src/c/test/%.c include/CCSensorDevice.h src/c/test/CCSensorUtils.h nativelib/test
	$(CC) $(CFLAGS) -c $< -o $@

nativelib/swig/%.o : src/swig/%.c nativelib/swig
	$(CC) -c $< -I/usr/java/include -I/usr/java/include/win32 -Iinclude -o $@

nativelib/%.o : src/c/%.c include/CCSensorDevice.h nativelib nativelib/test
	$(CC) $(CFLAGS) -c $< -o $@

bin nativelib nativelib/test nativelib/swig $(SWIG_OUTPUT_DIR)/ccsd/vernier $(SWIG_OUTPUT_DIR)/ccsd/pseudo $(SWIG_OUTPUT_DIR)/ccsd/ti:
	mkdir -p $@

.PHONY : vernier_swig ti_swig pseudo_swig

# you must install swig to run this target. http://swig.org
# it expects the binary to be on your path and the include files to
# be in a stardard include folder.

######### Vernier targets ###########
vernier_swig : include/CCSensorDevice.h src/swig/CCSensorDevice.i $(SWIG_OUTPUT_DIR)/ccsd/vernier
	$(SWIG) -java -Iinclude -package ccsd.vernier -outdir src/swig/java/ccsd/vernier -o src/swig/VernierSensorDevice_wrap.c src/swig/CCSensorDevice.i  

bin/vernier_ccsd.dll : 	vernier_swig $(GOLINK_OBJS) nativelib/swig/VernierSensorDevice_wrap.o
	$(build-jni-dll)

bin/GoLinkQuery : $(QUERY_OBJS) $(GOLINK_OBJS) bin
	$(build-static-executable)

bin/GoLinkPrintData : $(GOLINK_OBJS) $(PRINTDATA_OBJS) bin
	$(build-static-executable)

######## TI targets ############
ti_swig : include/CCSensorDevice.h src/swig/CCSensorDevice.i $(SWIG_OUTPUT_DIR)/ccsd/ti $(GOLINK_OBJS)
	$(SWIG) -java -Iinclude -package ccsd.ti -outdir src/swig/java/ccsd/ti -o src/swig/TISensorDevice_wrap.c src/swig/CCSensorDevice.i  
	
bin/ti_ccsd.dll : 	ti_swig $(TI_OBJS) nativelib/swig/TISensorDevice_wrap.o
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