CFLAGS += -O0 -ggdb -fPIC

PREFIX := $(PREFIX)


ifndef PREFIX
	PREFIX = /usr
endif

LIB_DIR = ${PREFIX}/lib/skype_oss_wrapper
BIN_DIR = ${PREFIX}/bin

.PHONY : all clean

all:
	cc ${CFLAGS} -m32 -shared -o libpulse.so.0 libpulse.c
	echo "#!/bin/sh" > skype_oss && echo "LD_LIBRARY_PATH=${LIB_DIR}:\$$LD_LIBRARY_PATH skype" >> skype_oss && chmod +x skype_oss
	echo "#!/bin/sh" > installer && echo "mkdir -p \$$DESTDIR/${LIB_DIR} && mkdir -p \$$DESTDIR/${BIN_DIR} && cp skype_oss \$$DESTDIR/${BIN_DIR}/ && cp libpulse.so.0 \$$DESTDIR/${LIB_DIR}/" >> installer && chmod +x installer

install:
	./installer

clean:
	rm libpulse.so.0 skype_oss installer
