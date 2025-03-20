# Trabalho 1 - TBO

Alunos: Daniel Corona de Aguiar e João Henrique Valbusa Lima

## Introdução

Este relatório compara o uso de memória, tempo de execução e complexidade entre duas implementações do algoritmo de Dijkstra: uma utilizando uma MinHeap e outra utilizando uma matriz de adjacências dinamicamente alocada.

## Análise de Complexidade

### Implementação com MinHeap

1. **Criação da Heap (`heapCreate`)**
   - **Complexidade:** 𝑂(𝑉)
   - Inicializar a heap com 𝑉 vértices envolve inserir todos os vértices na heap com uma distância inicial infinita, que foi escolhido como o valor -1, pois não existem arestas negativas no grafo, e sem um pai. A exceção é o vértice fonte, que tem distância 0.

2. **Inserção na Heap (`heapAddNode`)**
   - **Complexidade:** 𝑂(log 𝑉)
   - Cada inserção na MinHeap leva 𝑂(log 𝑉), pois a heap deve manter sua propriedade de ordem após a inserção usando o `heapFixUp`.

3. **Extração do Mínimo (`heapPopMin`)**
   - **Complexidade:** 𝑂(log 𝑉)
   - A cada iteração do algoritmo de Dijkstra, o vértice com a menor distância é extraído da heap. Isso requer 𝑂(log 𝑉) para manter a propriedade da heap após a remoção usando o `heapFixDown`.

4. **Atualização de Distância (`heapAtualizaDistancia`)**
   - **Complexidade:** 𝑂(log 𝑉)
   - Quando a distância de um vértice é atualizada (`relaxarAresta`), sua posição na heap pode mudar. Isso requer 𝑂(log 𝑉) para reordenar a heap.

5. **Iteração sobre Todas as Arestas (`while(!heapIsEmpty)`)**
   - **Complexidade:** 𝑂(𝐸)
   - O loop interno do algoritmo de Dijkstra percorre todas as arestas do grafo uma vez. Para cada aresta, pode ser necessário atualizar a distância de um vértice na heap.

6. **Complexidade Total**
   - **Complexidade Total:** 𝑂((𝑉 + 𝐸) log 𝑉)
   - A complexidade total do algoritmo de Dijkstra com uma MinHeap é a soma das operações acima. Para grafos esparsos, a complexidade é 𝑂((𝑉 + 𝐸) log 𝑉), enquanto para grafos densos, a complexidade se aproxima de 𝑂(𝑉² log 𝑉).

### Implementação com Matriz de Adjacências

1. **Inicialização (`lerArquivoEntradaMatrixToken`)**
   - **Complexidade:** 𝑂(𝑉²)
   - A matriz de adjacências requer 𝑂(𝑉²) para inicialização, pois cada vértice pode estar conectado a todos os outros vértices. Além disso, é necessário inicializar o array que guarda o pai do vértice `i` na posição `pais[i]`, e a distância de `i` para o vértice fonte na posição `distancias[i]`.

2. **Extração do Menor Vértice (`extraiMin`)**
   - **Complexidade:** 𝑂(𝑉)
   - Para cada iteração, o algoritmo percorre todas as distâncias para encontrar o vértice com a menor distância. Foi escolhido fazer uma busca sequencial pelo mínimo, uma vez que dessa forma não seria necessário reorganizar a ordem das distâncias a cada iteração.

3. **Relaxamento das Arestas (`relaxarArestas`)**
   - **Complexidade:** 𝑂(𝑉)
   - Para cada vértice, o algoritmo percorre todos os vizinhos para atualizar as distâncias. Também foi escolhido fazer por busca sequencial.

4. **Complexidade Total**
   - **Complexidade Total:** 𝑂(𝑉²)
   - A complexidade total do algoritmo de Dijkstra com matriz de adjacências é 𝑂(𝑉²), pois para cada vértice, o algoritmo percorre todos os outros vértices para encontrar o menor caminho.

### Conclusão da Análise de Complexidade

- **MinHeap:** A implementação com MinHeap é mais eficiente para grafos esparsos, onde o número de arestas 𝐸 é próximo ao número de vértices 𝑉. A complexidade é 𝑂((𝑉 + 𝐸) log 𝑉), o que é melhor do que a implementação com matriz para grafos esparsos.
  
- **Matriz de Adjacências:** A implementação com matriz é mais eficiente para grafos densos, onde o número de arestas 𝐸 é próximo a 𝑉². A complexidade é 𝑂(𝑉²), o que é melhor do que a implementação com MinHeap para grafos densos.

## Testes e Resultados

Os testes foram executados utilizando o Valgrind para monitorar o uso de memória, e sem o Valgrind para computar os tempos de execução. Os tempos são uma média de 5 execuções. Os seguintes comandos foram utilizados para executar os testes:

```bash
./testador.sh both                # tem a saída dos tempos de execução no terminal
./testador.sh both valgrind       # tem a saída do valgrind nos logs no diretório 'saidas/' 
```

### Resultados da Implementação com Heap

| Caso de Teste                     | Total Heap Usage (bytes) | In Use at Exit (bytes) | Total Allocs | Tempo de Execução (segundos) |
|-----------------------------------|--------------------------|------------------------|--------------|-----------------------------|
| caso_teste_muito_pequeno_1.txt    | 11,123                   | 0                      | 42           | 0.00428                    |
| caso_teste_muito_pequeno_2.txt    | 11,959                   | 0                      | 77           | 0.003515                    |
| caso_teste_pequeno_1.txt          | 9,812                    | 0                      | 249,026      | 0.007898                    |
| caso_teste_pequeno_2.txt          | 9,880                    | 0                      | 250,658      | 0.008328                    |
| caso_teste_pequeno_3.txt          | 954,613                  | 0                      | 22,978,858   | 0.334593                    |
| caso_teste_pequeno_4.txt          | 955,011                  | 0                      | 22,988,410   | 0.345895                    |
| caso_teste_medio_1.txt            | 571,843,978              | 0                      | 23,815,481   | 7.610155                    |
| caso_teste_medio_2.txt            | 571,875,514              | 0                      | 23,816,795   | 8.132415                    |
| caso_teste_medio_3.txt            | 571,869,034              | 0                      | 23,816,525   | 7.543149                    |
| caso_teste_medio_4.txt            | 823,425,570              | 0                      | 34,297,964   | 12.191991                    |

### Resultados da Implementação com Matriz

| Caso de Teste                     | Total Heap Usage (bytes) | In Use at Exit (bytes) | Total Allocs | Tempo de Execução (segundos) |
|-----------------------------------|--------------------------|------------------------|--------------|-----------------------------|
| caso_teste_muito_pequeno_1.txt    | 10,779                   | 0                      | 28           | 0.022364                    |
| caso_teste_muito_pequeno_2.txt    | 11,207                   | 0                      | 40           | 0.005207                    |
| caso_teste_pequeno_1.txt          | 59,114                   | 0                      | 316          | 0.007293                    |
| caso_teste_pequeno_2.txt          | 59,114                   | 0                      | 316          | 0.012808                    |
| caso_teste_pequeno_3.txt          | 4,120,594                | 0                      | 3,019        | 0.412837                    |
| caso_teste_pequeno_4.txt          | 4,120,594                | 0                      | 3,019        | 0.155937                    |
| caso_teste_medio_1.txt            | 100,532,978              | 0                      | 15,023       | 4.463961                    |
| caso_teste_medio_2.txt            | 100,532,978              | 0                      | 15,023       | 5.187632                    |
| caso_teste_medio_3.txt            | 100,532,978              | 0                      | 15,023       | 8.340785                    |
| caso_teste_medio_4.txt            | 144,586,978              | 0                      | 18,023       | 11.951307                    |

### Considerações Finais

De acordo com os dados das tabelas acima, percebe-se que na maioria dos casos a implementação com matriz de adjacências é mais rápida e usa menos alocação de memória, com exceção dos casos muito pequenos, onde a implementação com heap é mais eficiente em termos de uso de memória. Essa superioridade no desempenho da implementação com matriz de adjacências se deve ao fato de que os casos de teste utilizados eram grafos densos, ou seja, 𝐸 ≈ 𝑉². Nesses casos, a complexidade da implementação com matriz (𝑂(𝑉²)) é mais eficiente do que a implementação com heap (𝑂(𝑉² log 𝑉)).

Portanto, a escolha da estrutura de dados depende do tipo de grafo e dos requisitos de desempenho. Para grafos densos, a matriz de adjacências é a melhor escolha, enquanto para grafos esparsos, a MinHeap é mais eficiente.

# **Mais detalhes sobre o repositório**

Para fazer os teste e ver as diferenças na saída temos scripts para usar

```bash
./testador both         # compila e executa cada implementacao gerando suas respectivas saidas
./comparador            # faz um diff entre as saidas de cada implementação
```
---
Também é possível executar o programa manualmente com o seguinte padrão de execução
```bash
make
./trab1 entrada.txt saida.txt
```

Exemplo de execução
```bash
make
./trab1 casos_teste_v3/caso_teste_muito_pequeno_1.txt saidas/saida_caso_teste_muito_pequeno_1.txt
```

# Disposição do repositório
    .
    ├── T1_2024_2_especificacao_v2.pdf
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
    ├── comparador.sh
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
    │   ├── saida_heap_caso_teste_medio_1.txt
    │   ├── saida_heap_caso_teste_medio_2.txt
    │   ├── saida_heap_caso_teste_medio_3.txt
    │   ├── saida_heap_caso_teste_medio_4.txt
    │   ├── saida_heap_caso_teste_muito_pequeno_1.txt
    │   ├── saida_heap_caso_teste_muito_pequeno_2.txt
    │   ├── saida_heap_caso_teste_pequeno_1.txt
    │   ├── saida_heap_caso_teste_pequeno_2.txt
    │   ├── saida_heap_caso_teste_pequeno_3.txt
    │   ├── saida_heap_caso_teste_pequeno_4.txt
    │   ├── saida_matrix_caso_teste_medio_1.txt
    │   ├── saida_matrix_caso_teste_medio_2.txt
    │   ├── saida_matrix_caso_teste_medio_3.txt
    │   ├── saida_matrix_caso_teste_medio_4.txt
    │   ├── saida_matrix_caso_teste_muito_pequeno_1.txt
    │   ├── saida_matrix_caso_teste_muito_pequeno_2.txt
    │   ├── saida_matrix_caso_teste_pequeno_1.txt
    │   ├── saida_matrix_caso_teste_pequeno_2.txt
    │   ├── saida_matrix_caso_teste_pequeno_3.txt
    │   └── saida_matrix_caso_teste_pequeno_4.txt
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
    ├── testador.sh
    ├── testes.log
    └── trab1