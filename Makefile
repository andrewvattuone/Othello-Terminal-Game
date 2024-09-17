CC = gcc

CFLAGS = -g

PROG = main.exe

OBJS = main.o bestMove.o advancedScoreFunctions.o standardScoreFunctions.o partialScoreFunctions.o moveFunctions.o copyFunctions.o displayFunctions.o testFunctions.o

HEADERS = constants.h

all: $(PROG)

$(PROG): $(OBJS) $(HEADERS)
	$(CC) $(CFLAGS) -o $(PROG) $(OBJS)

%.o: %.c %.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(PROGS)

