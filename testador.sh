#!/bin/bash

# Para o script funcionar deve existir o direorio casos_teste_v3 com os arquivos de teste e o diretorio saidas para armazenar as saidas dos testes
# Pode escolher usar o valgrind


# Diretórios
TEST_DIR="casos_teste_v3"
OUTPUT_DIR="saidas"
BIN_HEAP="./mainHeap"
BIN_MATRIX="./mainMatrix"
VALGRIND="valgrind"

# Função para executar testes com mainHeap
testHeap() {
    for test in $TEST_DIR/*.txt; do
        output=$OUTPUT_DIR/saida_$(basename $test)
        if [ "$USE_VALGRIND" == "true" ]; then
            valgrind_output=$OUTPUT_DIR/valgrind_heap_$(basename $test .txt).log
            $VALGRIND --log-file=$valgrind_output $BIN_HEAP $test $output
        else
            $BIN_HEAP $test $output
        fi
    done
}

# Função para executar testes com mainMatrix
testMatrix() {
    for test in $TEST_DIR/*.txt; do
        output=$OUTPUT_DIR/saida_$(basename $test)
        if [ "$USE_VALGRIND" == "true" ]; then
            valgrind_output=$OUTPUT_DIR/valgrind_matrix_$(basename $test .txt).log
            $VALGRIND --log-file=$valgrind_output $BIN_MATRIX $test $output
        else
            $BIN_MATRIX $test $output
        fi
    done
}

# Verifica os argumentos passados para o script
make

if [ "$1" == "heap" ]; then
    if [ "$2" == "valgrind" ]; then
        USE_VALGRIND="true"
    else
        USE_VALGRIND="false"
    fi
    testHeap
elif [ "$1" == "matrix" ]; then
    if [ "$2" == "valgrind" ]; then
        USE_VALGRIND="true"
    else
        USE_VALGRIND="false"
    fi
    testMatrix
elif [ "$1" == "both" ]; then
    if [ "$2" == "valgrind" ]; then
        USE_VALGRIND="true"
    else
        USE_VALGRIND="false"
    fi
    testHeap
    testMatrix
else
    echo "Uso: $0 {heap|matrix|both} [valgrind]"
    exit 1
fi