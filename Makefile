CFLAGS = -Wall -Wextra -Werror -pedantic -fPIC

TARGET = libkutils.so
SRC = src/kutils.c
OBJ = bin/kutils.o

PREFIX = /usr/local

debug: CFLAGS += -DDEBUG -ggdb -Og
debug: $(TARGET)

release: CFLAGS += -Os
release: $(TARGET)

$(TARGET): bin/kutils.o
	$(CC) $(CFLAGS) -shared -Wl,-soname,$@ -o $@ $<

bin/kutils.o: src/kutils.c
	@mkdir -p bin
	$(CC) $(CFLAGS) -o $@ -c $<

tests: debug test_kutils.c
	$(CC) $(CFLAGS) test_kutils.c -o test_kutils -L. -lkutils

clean:
	$(RM) $(TARGET) test_kutils bin/*

install: release
	install -Dm644 src/kutils.h $(PREFIX)/include/
	install -D $(TARGET) $(PREFIX)/lib/

uninstall:
	$(RM) $(PREFIX)/include/kutils.h
	$(RM) $(PREFIX)/lib/libkutils.a

.PHONY: clean all debug release tests install uninstall
