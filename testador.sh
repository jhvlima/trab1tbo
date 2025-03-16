#!/bin/bash

# Para o script funcionar deve existir o diretório casos_teste_v3 com os arquivos de teste de entrada
# Serão criados os arquivos de saída no diretório saidas/
# O script compila o código e executa os testes
# Uso: ./testador.sh {heap|matrix|both} [valgrind]
# Exemplo: ./testador.sh heap valgrind
# Pode escolher executar os testes com mainHeap, mainMatrix ou ambos
# Pode escolher usar o valgrind

# Variáveis
TEST_DIR="casos_teste_v3"
OUTPUT_DIR="saidas"
BIN="./trab1"
VALGRIND="valgrind"
NUM_RUNS=1  # Número de execuções para calcular a média

# Função para calcular a média dos tempos de execução
calculate_average() {
    local total=0
    local count=0
    for time in "$@"; do
        total=$(echo "$total + $time" | bc)
        count=$((count + 1))
    done
    echo "scale=6; $total / $count" | bc
}

# Função para executar testes com trab1 (Heap)
testHeap() {
    for test in $TEST_DIR/*.txt; do
        output=$OUTPUT_DIR/saida_heap$(basename $test)
        times=()
        for i in $(seq 1 $NUM_RUNS); do
            if [ "$USE_VALGRIND" == "true" ]; then
                valgrind_output=$OUTPUT_DIR/valgrind_heap_$(basename $test .txt).log
                $VALGRIND --log-file=$valgrind_output $BIN $test $output
            else
                start_time=$(date +%s.%N)
                $BIN $test $output
                end_time=$(date +%s.%N)
                elapsed_time=$(echo "$end_time - $start_time" | bc)
                times+=($elapsed_time)
            fi
            sleep 1  # Aguarda 1 segundo para que a memória seja liberada antes de executar o próximo teste
        done
        if [ "$USE_VALGRIND" != "true" ]; then
            average_time=$(calculate_average "${times[@]}")
            echo "Heap - $(basename $test): Tempo médio de execução: $average_time segundos"
        fi
    done
}

# Função para executar testes com trab1 (Matrix)
testMatrix() {
    for test in $TEST_DIR/*.txt; do
        output=$OUTPUT_DIR/saida_matrix$(basename $test)
        times=()
        for i in $(seq 1 $NUM_RUNS); do
            if [ "$USE_VALGRIND" == "true" ]; then
                valgrind_output=$OUTPUT_DIR/valgrind_matrix_$(basename $test .txt).log
                $VALGRIND --log-file=$valgrind_output $BIN $test $output
            else
                start_time=$(date +%s.%N)
                $BIN $test $output
                end_time=$(date +%s.%N)
                elapsed_time=$(echo "$end_time - $start_time" | bc)
                times+=($elapsed_time)
            fi
            sleep 1  # Aguarda 1 segundo para que a memória seja liberada antes de executar o próximo teste
        done
        if [ "$USE_VALGRIND" != "true" ]; then
            average_time=$(calculate_average "${times[@]}")
            echo "Matrix - $(basename $test): Tempo médio de execução: $average_time segundos"
        fi
    done
}

# Verifica os argumentos passados para o script
if [ "$1" == "heap" ]; then
    make heap
    if [ "$2" == "valgrind" ]; then
        USE_VALGRIND="true"
    else
        USE_VALGRIND="false"
    fi
    testHeap
elif [ "$1" == "matrix" ]; then
    make matrix
    if [ "$2" == "valgrind" ]; then
        USE_VALGRIND="true"
    else
        USE_VALGRIND="false"
    fi
    testMatrix
elif [ "$1" == "both" ]; then
    make heap
    if [ "$2" == "valgrind" ]; then
        USE_VALGRIND="true"
    else
        USE_VALGRIND="false"
    fi
    testHeap
    make matrix
    if [ "$2" == "valgrind" ]; then
        USE_VALGRIND="true"
    else
        USE_VALGRIND="false"
    fi
    testMatrix
else
    echo "Uso: $0 {heap|matrix|both} [valgrind]"
    exit 1
fi