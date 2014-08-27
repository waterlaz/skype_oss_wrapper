CFLAGS += -O0 -ggdb ${INC}

.PHONY : all clean

all:
	cc ${CFLAGS} -O0 -ggdb -m32 -shared -o libpulse.so libpulse.c

clean:
	rm libpulse.so 
