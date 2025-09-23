# Macros
CC = gcc
CFLAGS = -Wall -Werror -I../include
OBJDIR = ../obj
BINDIR = ../bin
INCDIR = ../include
LIBDIR = ../lib

OBJS = $(OBJDIR)/main.o $(OBJDIR)/myfilefunctions.o $(OBJDIR)/mystrfunctions.o
LIBSTATIC = $(LIBDIR)/libmyutils.a
TARGET = $(BINDIR)/client_static

# Default target
all: $(TARGET)

$(TARGET): $(OBJDIR)/main.o $(LIBSTATIC)
	$(CC) $(CFLAGS) -o $@ $< -L$(LIBDIR) -lmyutils

# Build static library
$(LIBSTATIC): $(OBJS)
	ar -r $@ $^

# Compile .c -> .o
$(OBJDIR)/main.o: main.c $(INCDIR)/mystrfunctions.h $(INCDIR)/myfilefunctions.h
	$(CC) $(CFLAGS) -c $< -o $@
$(OBJDIR)/mystrfunctions.o: mystrfunctions.c $(INCDIR)/mystrfunctions.h
	$(CC) $(CFLAGS) -c $< -o $@
$(OBJDIR)/myfilefunctions.o: myfilefunctions.c $(INCDIR)/myfilefunctions.h
	$(CC) $(CFLAGS) -c $< -o $@


clean:
	rm -f $(OBJDIR)/*.o $(TARGET)
	@echo "Cleaned src/"
	
.PHONY: all clean
