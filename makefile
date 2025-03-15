# Variáveis de compilação
CC = gcc
CFLAGS = -Wall -Wextra -g
VALGRIND = valgrind
BIN_HEAP = mainHeap
BIN_MATRIX = mainMatrix
SRC_DIR = src
OBJ_DIR = obj
TEST_DIR = casos_teste_v3
OUTPUT_DIR = saidas

# Lista de objetos
OBJ_HEAP = $(OBJ_DIR)/mainHeap.o $(OBJ_DIR)/dijkstraHeap.o $(OBJ_DIR)/heap.o $(OBJ_DIR)/graph.o $(OBJ_DIR)/ioHandler.o $(OBJ_DIR)/node.o $(OBJ_DIR)/matrix.o
OBJ_MATRIX = $(OBJ_DIR)/mainMatrix.o $(OBJ_DIR)/dijkstraMatrix.o $(OBJ_DIR)/matrix.o $(OBJ_DIR)/graph.o $(OBJ_DIR)/ioHandler.o $(OBJ_DIR)/node.o

# Regra padrão: compila ambas as versões
all: $(BIN_HEAP) $(BIN_MATRIX)

# Compilar a versão Heap
$(BIN_HEAP): $(OBJ_HEAP)
	$(CC) $(CFLAGS) -o $@ $^

# Compilar a versão Matrix
$(BIN_MATRIX): $(OBJ_MATRIX)
	$(CC) $(CFLAGS) -o $@ $^

# Criar diretório de objetos, se necessário
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Regras de compilação dos objetos
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Limpeza
clean:
	rm -rf $(OBJ_DIR) $(BIN_HEAP) $(BIN_MATRIX) $(OUTPUT_DIR)/*.txt

# PHONY targets
.PHONY: all runHeap runMatrix valgrindHeap valgrindMatrix testHeap testMatrix clean