# Trabalho 1 - TBO

# Para fazer o teste e ver as diferancas na saida
./testador both
./comparador

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


## Introdução

Este relatório compara o uso de memória, tempo de execução e complexidade entre duas implementações do algoritmo de Dijkstra: uma utilizando uma MinHeap e outra utilizando uma matriz de adjacências dinamicamente alocadas.

## Análise de Complexidade

### Implementação com Heap
Criação da Heap (heapCreate)	
𝑂(𝑉)	Inicializa a heap com 𝑉 vértices.

Inserção na Heap (heapPush)	𝑂(log⁡𝑉)	
Cada inserção na MinHeap leva 𝑂(log⁡𝑉).

Extração do Mínimo (heapPopMin)	𝑂(log⁡𝑉)	
A cada iteração, o nó com menor distância é removido da MinHeap.

Atualização de distância (heapAtualizaDistancia)	𝑂(log⁡𝑉)	
A cada relaxamento, a distância do nó pode ser atualizada e a heap reordenada.

Iteração sobre todas as arestas	𝑂(𝐸)
O loop interno percorre todas as arestas uma vez.

Total 
O(V log V + E log V) = O((V+E) log V) 

Como em um grafo denso,  𝐸 pode ser próximo de  𝑉 2 V  2  , o pior caso pode ser  𝑂 ( 𝑉 2 log ⁡ 𝑉 ) O(V  2  logV). Mas para grafos esparsos (onde  𝐸 ≈ 𝑉 E≈V), a complexidade se aproxima de  𝑂 ( 𝑉 log ⁡ 𝑉 ) O(VlogV).

### 1. **Criação da Heap (heapCreate)**
- **Complexidade: 𝑂(𝑉)**
  - Inicializar a heap com 𝑉 vértices envolve inserir todos os vértices na heap com uma distância inicial (geralmente infinita, exceto para o vértice de origem, que tem distância 0).
  - Isso pode ser feito em 𝑂(𝑉) se a heap for construída de forma eficiente (por exemplo, usando o algoritmo de Floyd para construir uma heap em tempo linear).

---

### 2. **Inserção na Heap (heapPush)**
- **Complexidade: 𝑂(log 𝑉)**
  - Cada inserção na MinHeap leva 𝑂(log 𝑉), pois a heap deve manter sua propriedade de ordem após a inserção.

---

### 3. **Extração do Mínimo (heapPopMin)**
- **Complexidade: 𝑂(log 𝑉)**
  - A cada iteração do algoritmo de Dijkstra, o vértice com a menor distância é extraído da heap. Isso requer 𝑂(log 𝑉) para manter a propriedade da heap após a remoção.

---

### 4. **Atualização de Distância (heapAtualizaDistancia)**
- **Complexidade: 𝑂(log 𝑉)**
  - Quando a distância de um vértice é atualizada (relaxamento), sua posição na heap pode mudar. Isso requer 𝑂(log 𝑉) para reordenar a heap.

---

### 5. **Iteração sobre Todas as Arestas**
- **Complexidade: 𝑂(𝐸)**
  - O loop interno do algoritmo de Dijkstra percorre todas as arestas do grafo uma vez. Para cada aresta, pode ser necessário atualizar a distância de um vértice na heap.

---

### 6. **Complexidade Total**
A complexidade total do algoritmo de Dijkstra com uma MinHeap é a soma das operações acima:
- **Inicialização:** 𝑂(𝑉)
- **Operações de Heap (inserção, extração, atualização):** 𝑂((𝑉 + 𝐸) log 𝑉)
  - Cada vértice é extraído uma vez (𝑉 operações de extração).
  - Cada aresta pode levar a uma atualização na heap (𝐸 operações de atualização).
- **Iteração sobre arestas:** 𝑂(𝐸)

Portanto, a complexidade total é:
\[
𝑂(𝑉) + 𝑂((𝑉 + 𝐸) \log 𝑉) = 𝑂((𝑉 + 𝐸) \log 𝑉)
\]

---

### 7. **Análise para Grafos Densos e Esparsos**
- **Grafos Densos (𝐸 ≈ 𝑉²):**
  \[
  𝑂((𝑉 + 𝑉²) \log 𝑉) = 𝑂(𝑉² \log 𝑉)
  \]
  - Neste caso, o termo dominante é 𝑉², pois o número de arestas é grande.

- **Grafos Esparsos (𝐸 ≈ 𝑉):**
  \[
  𝑂((𝑉 + 𝑉) \log 𝑉) = 𝑂(𝑉 \log 𝑉)
  \]
  - Aqui, o termo dominante é 𝑉, pois o número de arestas é proporcional ao número de vértices.

---

### 8. **Comparação com Outras Implementações**
- **Sem Heap (usando lista simples):**
  - Complexidade: 𝑂(𝑉²)
  - Adequado para grafos densos, mas ineficiente para grafos esparsos.

- **Com Heap Binária:**
  - Complexidade: 𝑂((𝑉 + 𝐸) \log 𝑉)
  - Mais eficiente para grafos esparsos.

- **Com Heap de Fibonacci:**
  - Complexidade: 𝑂(𝑉 \log 𝑉 + 𝐸)
  - Ainda mais eficiente, mas com overhead maior na implementação.

---

### Conclusão
A implementação do algoritmo de Dijkstra com uma **MinHeap** é eficiente para grafos esparsos, com complexidade 𝑂((𝑉 + 𝐸) \log 𝑉). Para grafos densos, a complexidade se aproxima de 𝑂(𝑉² \log 𝑉), o que ainda é melhor do que a implementação sem heap (𝑂(𝑉²)). A escolha da estrutura de dados depende do tipo de grafo e dos requisitos de desempenho.

### Implementação com Matrix
Matrix* matrix -> V(float + char)
int* pais -> [V]
float* distancias -> [V]
Node** arvoreMin -> maximo V


Inicializa estruturas:
arvoreMin para armazenar os nós processados.
pais para armazenar os pais dos nós.
distancias para armazenar a menor distância encontrada até cada nó.
Define todas as distâncias como -1 (infinito), exceto a do nó de origem (distancias[source] = 0).
Para cada iteração:
Extrai o nó com a menor distância (extraiMin).
Define o pai do nó na árvore mínima.
Relaxa as arestas dos vizinhos (relaxarArestas).
Libera memória para pais e distancias, e retorna a árvore mínima.

## Testes

Os testes foram executados utilizando o Valgrind para monitorar o uso de memória e sem o valgrind para computar os tempos de execução. Os tempos são uma média de 10 execuções. Os seguintes comandos foram utilizados para executar os testes:

```bash
testador.sh both                # tem a saida dos tempos de execucao no terminal
testador.sh both valgrind       # tem a saida do valgrind nos logs no diretorio 'saidas/' 
```

### Resuldados da Implementação com Heap

| Caso de Teste                     | Total Heap Usage (bytes) | In Use at Exit (bytes) | Total Allocs | Tempo de Execução (segundos) |
|-----------------------------------|--------------------------|------------------------|--------------|-----------------------------|
| caso_teste_muito_pequeno_1.txt    | 11,123                   | 0                      | 42           | 0.009915                    |
| caso_teste_muito_pequeno_2.txt    | 11,959                   | 0                      | 77           | 0.005652                    |
| caso_teste_pequeno_1.txt          | 9,812                    | 0                      | 249,026      | 0.029793                    |
| caso_teste_pequeno_2.txt          | 9,880                    | 0                      | 250,658      | 0.011586                    |
| caso_teste_pequeno_3.txt          | 954,613                  | 0                      | 22,978,858   | 0.269650                    |
| caso_teste_pequeno_4.txt          | 955,011                  | 0                      | 22,988,410   | 0.270477                    |
| caso_teste_medio_1.txt            | 571,843,978              | 0                      | 23,815,481   | 6.283894                    |
| caso_teste_medio_2.txt            | 571,875,514              | 0                      | 23,816,795   | 6.109730                    |
| caso_teste_medio_3.txt            | 571,869,034              | 0                      | 23,816,525   | 5.970471                    |
| caso_teste_medio_4.txt            | 823,425,570              | 0                      | 34,297,964   | 8.739837                    |

### Resultados da Implementação com Matrix

| Caso de Teste                     | Total Heap Usage (bytes) | In Use at Exit (bytes) | Total Allocs | Tempo de Execução (segundos) |
|-----------------------------------|--------------------------|------------------------|--------------|-----------------------------|
| caso_teste_muito_pequeno_1.txt    | 10,779                   | 0                      | 28           | 0.005019                    |
| caso_teste_muito_pequeno_2.txt    | 11,207                   | 0                      | 40           | 0.006240                    |
| caso_teste_pequeno_1.txt          | 59,114                   | 0                      | 316          | 0.013385                    |
| caso_teste_pequeno_2.txt          | 59,114                   | 0                      | 316          | 0.006920                    |
| caso_teste_pequeno_3.txt          | 4,120,594                | 0                      | 3,019        | 0.202453                    |
| caso_teste_pequeno_4.txt          | 4,120,594                | 0                      | 3,019        | 0.188479                    |
| caso_teste_medio_1.txt            | 100,532,978              | 0                      | 15,023       | 3.639112                    |
| caso_teste_medio_2.txt            | 100,532,978              | 0                      | 15,023       | 4.056108                    |
| caso_teste_medio_3.txt            | 100,532,978              | 0                      | 15,023       | 3.612667                    |
| caso_teste_medio_4.txt            | 144,586,978              | 0                      | 18,023       | 5.467426                    |

## Conclusão
De acordo com os dados das tabelas acima percebe-se que na maioria dos casos a implementação Matrix é mais rápida e usa menos alocação de memória na maioria dos casos de teste, com exeção do uso da heap nos casos pequenos. Essa superioridade no desenpenho da implementação de matriz de adjascencias se deve por conta da entrada dos casos de teste, uma vez que os grafos passados eram densos, ou seja, E ≈ V² , dessa forma 
