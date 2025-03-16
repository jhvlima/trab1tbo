# Variáveis de compilação
CC = gcc
CFLAGS = -Wall -Wextra -g
VALGRIND = valgrind
SRC_DIR = src
OBJ_DIR = obj
TEST_DIR = casos_teste_v3
OUTPUT_DIR = saidas
BIN = trab1

# Lista de objetos
OBJ_HEAP = $(OBJ_DIR)/mainHeap.o $(OBJ_DIR)/dijkstraHeap.o $(OBJ_DIR)/heap.o $(OBJ_DIR)/graph.o $(OBJ_DIR)/ioHandler.o $(OBJ_DIR)/node.o $(OBJ_DIR)/matrix.o
OBJ_MATRIX = $(OBJ_DIR)/mainMatrix.o $(OBJ_DIR)/dijkstraMatrix.o $(OBJ_DIR)/matrix.o $(OBJ_DIR)/graph.o $(OBJ_DIR)/ioHandler.o $(OBJ_DIR)/node.o

#
# Regra padrão: compila a versão desejada
# Muddar para matrix ou heap para compilar a versão desejada
#
all: heap

# Compilar a versão Heap
heap: $(OBJ_HEAP)
	$(CC) $(CFLAGS) -o $(BIN) $^

# Compilar a versão Matrix
matrix: $(OBJ_MATRIX)
	$(CC) $(CFLAGS) -o $(BIN) $^

# Criar diretório de objetos, se necessário
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Regras de compilação dos objetos
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Limpeza
clean:
	rm -rf $(OBJ_DIR) $(BIN) $(OUTPUT_DIR)/*.txt

# PHONY targets
.PHONY: all runHeap runMatrix valgrindHeap valgrindMatrix testHeap testMatrix clean