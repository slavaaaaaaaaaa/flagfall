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

$(BINDIR)/alltests: $(SOURCES) $(BINDIR)
	for i in $(TSTDIR)/*; do \
		BINARY=$$(echo $$i | sed -e 's/$(TSTDIR)//' -e 's/.cpp/.out/'); \
		$(CC) $(CFLAGS_FUNCTIONAL) $$i -o $(BINDIR)/$$BINARY; \
		./$(BINDIR)/$$BINARY; \
	done && touch $(BINDIR)/alltests

$(BINDIR)/pawntests: $(SOURCES) $(BINDIR)
	$(CC) $(CFLAGS_FUNCTIONAL) $(TSTDIR)/pawntests.cpp -o $(BINDIR)/pawntests
	./$(BINDIR)/pawntests

$(BINDIR)/kingtests: $(SOURCES) $(BINDIR)
	$(CC) $(CFLAGS_FUNCTIONAL) $(TSTDIR)/kingtests.cpp -o $(BINDIR)/kingtests
	./$(BINDIR)/kingtests

$(BINDIR):
	mkdir $@

tar:
	tar cfz flagfall.tar.gz $(SRCDIR) README LICENSE Makefile

clean:
	rm $(OBJDIR) $(BINDIR)
