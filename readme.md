# Trabalho 1 - TBO

Padrão de execução do executável
```bash
make
./trab1 entrada.txt saida.txt
```

Exemplo de execução
```bash
make
./main casos_teste_v3/caso_teste_muito_pequeno_1.txt saidas/saida_caso_teste_muito_pequeno_1.txt
```

# Para o relatório
Deve ser comparado o desempenho da versão implementada com heap e filas de prioridades com a segunda implementação da solução para Dijkstra.
A comparação deve ser realizada em termos de tempo de execução, consumo de memória e casos de teste executados com sucesso

# Disposição do repositório
    .
    ├── T1_2024_2_especificacao_v2.pdf
    ├── makefile
    ├── readme.md
    ├── saidas
    │   └── saida_caso_teste_muito_pequeno_1.txt
    ├── header
    │   └── heap.h
    ├── src
    |    ├── heap.c
    |    └── main.c
    └── casos_teste_v3
       ├── caso_teste_medio_1.txt
       ├── caso_teste_medio_2.txt
       ├── caso_teste_medio_3.txt
       ├── caso_teste_medio_4.txt
       ├── caso_teste_muito_pequeno_1.txt
       ├── caso_teste_muito_pequeno_2.txt
       ├── caso_teste_pequeno_1.txt
       ├── caso_teste_pequeno_2.txt
       ├── caso_teste_pequeno_3.txt
       └── caso_teste_pequeno_4.txt
