CFLAGS += -O0 -ggdb -fPIC

INSTALL_PATH := $(INSTALL_PATH)


ifndef INSTALL_PATH
	INSTALL_PATH = /opt
endif

LIB_DIR = ${INSTALL_PATH}/lib/skype_oss_wrapper
BIN_DIR = ${INSTALL_PATH}/bin

.PHONY : all clean

all:
	cc ${CFLAGS} -m32 -shared -o libpulse.so.0 libpulse.c
	echo "#!/bin/sh" > skype_oss && echo "LD_LIBRARY_PATH=${LIB_DIR}:\$$LD_LIBRARY_PATH skype" >> skype_oss && chmod +x skype_oss
	echo "#!/bin/sh" > installer && echo "mkdir -p ${LIB_DIR} && mkdir -p ${BIN_DIR} && cp skype_oss ${BIN_DIR}/ && cp libpulse.so.0 ${LIB_DIR}/" >> installer && chmod +x installer

install:
	./installer

clean:
	rm libpulse.so.0 skype_oss installer
