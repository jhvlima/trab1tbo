#!/bin/bash

# Diretórios
OUTPUT_DIR="saidas"

# Função para comparar saídas
compare_outputs() {
    for heap_output in $OUTPUT_DIR/saida_heapcaso*.txt; do
        base_name=$(basename $heap_output)
        matrix_output="${OUTPUT_DIR}/saida_matrix${base_name#saida_heap}"
        
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