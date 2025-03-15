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
    ├── casos_teste_v3
    │   ├── caso_teste_medio_1.txt
    │   ├── caso_teste_medio_2.txt
    │   ├── caso_teste_medio_3.txt
    │   ├── caso_teste_medio_4.txt
    │   ├── caso_teste_muito_pequeno_1.txt
    │   ├── caso_teste_muito_pequeno_2.txt
    │   ├── caso_teste_pequeno_1.txt
    │   ├── caso_teste_pequeno_2.txt
    │   ├── caso_teste_pequeno_3.txt
    │   └── caso_teste_pequeno_4.txt
    ├── mainHeap
    ├── mainMatrix
    ├── makefile
    ├── obj
    │   ├── dijkstraHeap.o
    │   ├── dijkstraMatrix.o
    │   ├── graph.o
    │   ├── heap.o
    │   ├── ioHandler.o
    │   ├── mainHeap.o
    │   ├── mainMatrix.o
    │   ├── matrix.o
    │   └── node.o
    ├── readme.md
    ├── saidas
    │   ├── saida_caso_teste_medio_1.txt
    │   ├── saida_caso_teste_medio_2.txt
    │   ├── saida_caso_teste_medio_3.txt
    │   ├── saida_caso_teste_medio_4.txt
    │   ├── saida_caso_teste_muito_pequeno_1.txt
    │   ├── saida_caso_teste_muito_pequeno_2.txt
    │   ├── saida_caso_teste_pequeno_1.txt
    │   ├── saida_caso_teste_pequeno_2.txt
    │   ├── saida_caso_teste_pequeno_3.txt
    │   └── saida_caso_teste_pequeno_4.txt
    ├── src
    │   ├── dijkstraHeap.c
    │   ├── dijkstraHeap.h
    │   ├── dijkstraMatrix.c
    │   ├── dijkstraMatrix.h
    │   ├── graph.c
    │   ├── graph.h
    │   ├── heap.c
    │   ├── heap.h
    │   ├── ioHandler.c
    │   ├── ioHandler.h
    │   ├── mainHeap.c
    │   ├── mainMatrix.c
    │   ├── matrix.c
    │   ├── matrix.h
    │   ├── node.c
    │   └── node.h
    ├── T1_2024_2_especificacao_v2.pdf
    └── testador.sh

# Testes de tempo

Testando a implementação com a heap

    joao@inspiron-3421:~/Desktop/trab1tbo$ ./testador.sh heap
    Tempo de execução (heap) [casos_teste_v3/caso_teste_medio_1.txt]: 24.207167 segundos
    Tempo de execução (heap) [casos_teste_v3/caso_teste_medio_2.txt]: 24.132980 segundos
    Tempo de execução (heap) [casos_teste_v3/caso_teste_medio_3.txt]: 24.161776 segundos
    Tempo de execução (heap) [casos_teste_v3/caso_teste_medio_4.txt]: 35.831821 segundos
    Tempo de execução (heap) [casos_teste_v3/caso_teste_muito_pequeno_1.txt]: 0.001227 segundos
    Tempo de execução (heap) [casos_teste_v3/caso_teste_muito_pequeno_2.txt]: 0.001115 segundos
    Tempo de execução (heap) [casos_teste_v3/caso_teste_pequeno_1.txt]: 0.024425 segundos
    Tempo de execução (heap) [casos_teste_v3/caso_teste_pequeno_2.txt]: 0.017196 segundos
    Tempo de execução (heap) [casos_teste_v3/caso_teste_pequeno_3.txt]: 1.351158 segundos
    Tempo de execução (heap) [casos_teste_v3/caso_teste_pequeno_4.txt]: 1.320026 segundos

Testando a implementação com matriz de adjascencias

    joao@inspiron-3421:~/Desktop/trab1tbo$ ./testador.sh matrix
    Tempo de execução (matrix) [casos_teste_v3/caso_teste_medio_1.txt]: 17.314111 segundos
    Tempo de execução (matrix) [casos_teste_v3/caso_teste_medio_2.txt]: 15.941921 segundos
    Tempo de execução (matrix) [casos_teste_v3/caso_teste_medio_3.txt]: 15.867615 segundos
    Tempo de execução (matrix) [casos_teste_v3/caso_teste_medio_4.txt]: 22.862210 segundos
    Tempo de execução (matrix) [casos_teste_v3/caso_teste_muito_pequeno_1.txt]: 0.000984 segundos
    Tempo de execução (matrix) [casos_teste_v3/caso_teste_muito_pequeno_2.txt]: 0.001095 segundos
    Tempo de execução (matrix) [casos_teste_v3/caso_teste_pequeno_1.txt]: 0.008836 segundos
    Tempo de execução (matrix) [casos_teste_v3/caso_teste_pequeno_2.txt]: 0.009480 segundos
    Tempo de execução (matrix) [casos_teste_v3/caso_teste_pequeno_3.txt]: 0.664994 segundos
    Tempo de execução (matrix) [casos_teste_v3/caso_teste_pequeno_4.txt]: 0.667558 segundos