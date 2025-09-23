# Macros
CC = gcc
CFLAGS = -Wall -Werror -I../include
OBJDIR = ../obj
BINDIR = ../bin
INCDIR = ../include
LIBDIR = ../lib
PREFIX = /usr/local
MANDIR = $(PREFIX)/share/man/man1

OBJS = $(OBJDIR)/main.o $(OBJDIR)/myfilefunctions.o $(OBJDIR)/mystrfunctions.o
PICOBJS = $(OBJDIR)/main.pic.o $(OBJDIR)/myfilefunctions.pic.o $(OBJDIR)/mystrfunctions.pic.o
LIBSTATIC = $(LIBDIR)/libmyutils.a
LIBDYNAMIC = $(LIBDIR)/libmyutils.so
TARGET_STATIC = $(BINDIR)/client_static
TARGET_DYNAMIC = $(BINDIR)/client_dynamic

# Default target
all: $(TARGET_STATIC) $(TARGET_DYNAMIC)

$(TARGET_STATIC): $(OBJDIR)/main.o $(LIBSTATIC)
	$(CC) -o $@ $< -L$(LIBDIR) -lmyutils

# Build static library
$(LIBSTATIC): $(OBJS)
	ar -r $@ $^
	
$(TARGET_DYNAMIC): $(OBJDIR)/main.pic.o $(LIBDYNAMIC)
	$(CC) -o $@ $< -L$(LIBDIR) -lmyutils

$(LIBDYNAMIC): $(PICOBJS)
	$(CC) -shared -o $@ $^

# Compile .c -> .o
$(OBJDIR)/main.o: main.c $(INCDIR)/mystrfunctions.h $(INCDIR)/myfilefunctions.h
	$(CC) $(CFLAGS) -c $< -o $@
$(OBJDIR)/mystrfunctions.o: mystrfunctions.c $(INCDIR)/mystrfunctions.h
	$(CC) $(CFLAGS) -c $< -o $@
$(OBJDIR)/myfilefunctions.o: myfilefunctions.c $(INCDIR)/myfilefunctions.h
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR)/main.pic.o: main.c $(INCDIR)/mystrfunctions.h $(INCDIR)/myfilefunctions.h
	$(CC) $(CFLAGS) -fPIC -c $< -o $@
$(OBJDIR)/mystrfunctions.pic.o: mystrfunctions.c $(INCDIR)/mystrfunctions.h
	$(CC) $(CFLAGS) -fPIC -c $< -o $@
$(OBJDIR)/myfilefunctions.pic.o: myfilefunctions.c $(INCDIR)/myfilefunctions.h
	$(CC) $(CFLAGS) -fPIC -c $< -o $@

install: $(TARGET_STATIC) $(TARGET_DYNAMIC)
	@echo "Installing clients and man page..."
	install -d $(PREFIX)/bin
	install -m 755 $(TARGET_STATIC) $(PREFIX)/bin/client_static
	install -m 755 $(TARGET_DYNAMIC) $(PREFIX)/bin/client_dynamic
	install -d $(MANDIR)
	install -m 644 ../man/man1/client.1 $(MANDIR)/
	install -m 644 ../man/man1/client_static.1 $(MANDIR)/
	install -m 644 ../man/man1/client_dynamic.1 $(MANDIR)/

uninstall:
	@echo "Uninstalling clients and man page..."
	rm -f $(PREFIX)/bin/client_static
	rm -f $(PREFIX)/bin/client_dynamic
	rm -f $(MANDIR)/client.1
	rm -f $(MANDIR)/client_static.1
	rm -f $(MANDIR)/client_dynamic.1


clean:
	rm -f $(OBJDIR)/*.o $(OBJDIR)/*.pic.o $(BINDIR)/* $(LIBDIR)/*
	@echo "Cleaned src/"
	
.PHONY: all clean
