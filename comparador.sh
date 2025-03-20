#!/bin/bash

# Diretórios
OUTPUT_DIR="saidas"

# Prefixos dos arquivos de saída
HEAP_PREFIX="saida_heap_"
MATRIX_PREFIX="saida_matrix_"

# Função para comparar saídas
compare_outputs() {
    for heap_output in $OUTPUT_DIR/$HEAP_PREFIX*.txt; do
        base_name=$(basename $heap_output)
        matrix_output="${OUTPUT_DIR}/$MATRIX_PREFIX${base_name#$HEAP_PREFIX}"        
        if [ -f "$matrix_output" ]; then
            echo "Comparando $heap_output com $matrix_output"
            diff $heap_output $matrix_output
        else
            echo "Arquivo correspondente para $heap_output não encontrado."
        fi
    done
}

# Executa a comparação
compare_outputs