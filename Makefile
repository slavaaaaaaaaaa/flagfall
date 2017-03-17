TARGET = flagfall

SRCDIR = src
TSTDIR = tests
OBJDIR = obj
BINDIR = bin

SOURCES  := $(wildcard $(SRCDIR)/*.c)
INCLUDES := $(wildcard $(SRCDIR)/*.h)
OBJECTS  := $(SOURCES:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

CC=g++
DEBUG=-g
CFLAGS_FUNCTIONAL=-Wall $(DEBUG)
CFLAGS=-Wall -c $(DEBUG)
LFLAGS=-Wall $(DEBUG)

$(BINDIR)/pawntests: $(SOURCES)
	$(CC) $(CFLAGS_FUNCTIONAL) $(TSTDIR)/pawntests.cpp -o $(BINDIR)/pawntests
	./$(BINDIR)/pawntests

$(BINDIR)/kingtests: $(SOURCES)
	$(CC) $(CFLAGS_FUNCTIONAL) $(TSTDIR)/kingtests.cpp -o $(BINDIR)/kingtests
	./$(BINDIR)/kingtests


$(BIN):
	mkdir $@

tar:
	tar cfz flagfall.tar.gz $(SRCDIR) README LICENSE Makefile

clean:
	rm $(OBJDIR)/*.o a.out $(BINDIR)/flagfall
	echo done
