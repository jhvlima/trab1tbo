# Variáveis de compilação
CC = gcc
CFLAGS = -Wall
VALGRIND = valgrind
BIN = main

# Regras de compilação
all: $(BIN)

$(BIN): main.o
	$(CC) $(CFLAGS) -o $(BIN) main.o

main.o: main.c
	$(CC) $(CFLAGS) -c main.c

# Regras de execução
run: $(BIN)
	./$(BIN)

valgrind: $(BIN)
	$(VALGRIND) ./$(BIN)

clean:
	rm -f *.o $(BIN)
