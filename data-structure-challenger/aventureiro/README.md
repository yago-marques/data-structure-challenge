# Detective Quest - Versão Aventureiro 🕵️‍♂️

## 📖 Descrição

A **Versão Aventureiro** do Detective Quest expande o jogo original com um sistema avançado de **coleta de pistas**. O jogador agora explora a mansão coletando automaticamente pistas que são organizadas em uma **Árvore Binária de Busca (BST)** para exibição em ordem alfabética.

## 🎯 Objetivo do Desafio

Implementar um sistema completo que combina:
- **Árvore Binária** para representar o mapa da mansão
- **Árvore BST** para organizar pistas coletadas
- **Coleta automática** de pistas durante a exploração
- **Exibição ordenada** das pistas em ordem alfabética

## 🏗️ Estrutura da Mansão com Pistas

```
                    Hall de Entrada
                   [Pegadas molhadas]
                   /              \
            Sala de Estar        Cozinha
               [Vazia]        [Xícara quente]
            /         \          /      \
      Biblioteca  Escritório  Despensa  Jardim
    [Livro venenos] [Vazia]  [Frasco]  [Flores]
        /              \                   \
  Sala Secreta    Cofre do Tesouro      Estufa
[Carta ameaça]   [Combinação cofre]  [Plantas venenosas]
```

## 🚀 Como Executar

### Pré-requisitos
- Compilador GCC instalado
- Sistema operacional Unix/Linux/macOS ou Windows com ambiente C

### Comandos Disponíveis

1. **Compilar e executar:**
   ```bash
   make run
   ```

2. **Teste completo com informações:**
   ```bash
   make test
   ```

3. **Apenas compilar:**
   ```bash
   make
   ```

4. **Ver ajuda:**
   ```bash
   make help
   ```

5. **Limpar arquivos:**
   ```bash
   make clean
   ```

## 🎮 Como Jogar

### Controles
- `e` ou `E` - Ir para a esquerda
- `d` ou `D` - Ir para a direita  
- `s` ou `S` - Sair e ver relatório final

### Mecânicas de Jogo

1. **Exploração**: Navegue pela mansão usando os comandos
2. **Coleta Automática**: Pistas são coletadas automaticamente ao entrar na sala
3. **Organização**: Pistas são inseridas na BST mantendo ordem alfabética
4. **Relatório Final**: Ao sair, todas as pistas são exibidas ordenadamente

## 📚 Conceitos Implementados

### Estruturas de Dados

#### 1. Árvore Binária (Mapa da Mansão)
```c
typedef struct Sala {
    char nome[50];          // Nome da sala
    char pista[100];        // Pista encontrada (pode estar vazia)
    struct Sala* esquerda;  // Sala à esquerda
    struct Sala* direita;   // Sala à direita
} Sala;
```

#### 2. Árvore BST (Organização de Pistas)
```c
typedef struct PistaNode {
    char pista[100];                // Conteúdo da pista
    struct PistaNode* esquerda;     // Subárvore esquerda
    struct PistaNode* direita;      // Subárvore direita
} PistaNode;
```

### Algoritmos Implementados

#### **Inserção em BST**
- Mantém propriedade de ordenação alfabética
- Evita duplicatas automaticamente
- Complexidade: O(log n) no melhor caso

#### **Percurso In-Order**
- Visita nós em ordem alfabética
- Implementado recursivamente
- Usado para exibir pistas organizadas

## 🔧 Funções Principais

### Gerenciamento de Salas
- **`criarSala(nome, pista)`** - Cria sala com pista opcional
- **`explorarSalasComPistas()`** - Controla navegação e coleta
- **`liberarMemoriaSalas()`** - Libera memória das salas

### Gerenciamento de Pistas  
- **`criarPistaNode(pista)`** - Cria nó da BST
- **`inserirPista(raiz, pista)`** - Insere pista mantendo ordem
- **`exibirPistas(raiz, contador)`** - Mostra pistas ordenadas
- **`liberarMemoriaPistas()`** - Libera memória da BST

### Interface e Relatórios
- **`exibirRelatorioFinal()`** - Relatório completo ao final
- **`main()`** - Inicialização e controle principal

## 🎯 Pistas Disponíveis na Mansão

| Sala | Pista |
|------|-------|
| Hall de Entrada | "Pegadas molhadas no chão de mármore" |
| Sala de Estar | *(Nenhuma pista)* |
| Cozinha | "Xícara de café ainda quente na mesa" |
| Biblioteca | "Livro aberto na página sobre venenos" |
| Escritório | *(Nenhuma pista)* |
| Despensa | "Frasco de vidro quebrado no chão" |
| Jardim | "Flores cortadas recentemente" |
| Sala Secreta | "Carta de ameaça escondida na gaveta" |
| Cofre do Tesouro | "Combinação do cofre anotada em papel" |
| Estufa | "Plantas venenosas bem cuidadas" |

## 🏆 Exemplo de Execução

```
🎮 === BEM-VINDO AO DETECTIVE QUEST - VERSÃO AVENTUREIRO ===
🔍 Explore a mansão, colete pistas e resolva o mistério!

=== DETECTIVE QUEST - COLETA DE PISTAS ===
🏠 Você está na: Hall de Entrada
🔍 PISTA ENCONTRADA: Pegadas molhadas no chão de mármore
✅ Pista adicionada à sua coleção!

📍 Opções disponíveis:
  (e) - Ir para esquerda: Sala de Estar
  (d) - Ir para direita: Cozinha
  (s) - Sair e ver pistas coletadas

➤ Escolha uma opção: d

=== DETECTIVE QUEST - COLETA DE PISTAS ===
🏠 Você está na: Cozinha
🔍 PISTA ENCONTRADA: Xícara de café ainda quente na mesa
✅ Pista adicionada à sua coleção!

➤ Escolha uma opção: s

====================================
🕵️  RELATÓRIO FINAL DA INVESTIGAÇÃO
====================================
✅ Pistas coletadas (em ordem alfabética):

  1. Pegadas molhadas no chão de mármore
  2. Xícara de café ainda quente na mesa

📊 Total de pistas coletadas: 2
🎉 Parabéns! Você está mais próximo de resolver o mistério!
====================================
```

## 🎓 Características do Nível Aventureiro

### ✅ Funcionalidades Avançadas
- Duas estruturas de árvore trabalhando em conjunto
- Coleta automática de pistas
- Organização automática em ordem alfabética
- Sistema de relatórios detalhado
- Interface melhorada com emojis e formatação

### ✅ Conceitos Técnicos
- **BST (Binary Search Tree)** para organização eficiente
- **Recursividade** para percurso e inserção
- **Modularização** com separação clara de responsabilidades
- **Gerenciamento de memória** completo
- **Validação de entrada** e tratamento de erros

### ✅ Aspectos Educacionais
- Demonstra diferença entre árvore binária e BST
- Mostra aplicação prática de ordenação
- Ensina gerenciamento de múltiplas estruturas
- Incentiva exploração através de gamificação

## 🔍 Estratégias de Exploração

### Para Coletar Todas as Pistas:
1. **Caminho Completo**: Explore todas as salas sistematicamente
2. **Lado Esquerdo Primeiro**: Hall → Sala de Estar → Biblioteca → Sala Secreta
3. **Depois Lado Direito**: Retorne e vá Hall → Cozinha → Jardim → Estufa
4. **Não Esqueça**: Despensa e Cofre do Tesouro também têm pistas

### Total de Pistas Disponíveis: **7 pistas**
- 3 pistas no lado esquerdo da mansão
- 4 pistas no lado direito da mansão

## 📈 Próximos Passos

A versão aventureiro prepara o terreno para o **nível mestre**, que pode incluir:
- Balanceamento automático de árvores (AVL/Red-Black)
- Sistema de pontuação baseado em pistas
- Múltiplos detetives (multiplayer)
- Pistas com diferentes categorias e prioridades
