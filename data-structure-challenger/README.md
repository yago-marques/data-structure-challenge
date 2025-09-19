# Data Structure Challenger - Detective Quest 🕵️‍♂️

Uma série progressiva de algoritmos desenvolvida para treinar **estruturas de dados** de forma prática e envolvente através de um jogo de investigação criminal interativa.

## 📋 Visão Geral

O **Data Structure Challenger** é uma coleção de três níveis progressivos do jogo **Detective Quest**, onde cada nível introduz novas estruturas de dados e conceitos algorítmicos. Os jogadores assumem o papel de um detetive explorando uma mansão misteriosa, coletando pistas e resolvendo casos criminais.

### 🎯 Objetivos Educacionais

- Ensinar estruturas de dados fundamentais através de aplicação prática
- Demonstrar algoritmos de busca, inserção e percurso
- Desenvolver habilidades de resolução de problemas
- Promover compreensão de complexidade computacional
- Gamificar o aprendizado de programação em C

## 🏗️ Estrutura do Projeto

```
data-structure-challenger/
├── README.md                   # Documentação principal
├── .gitignore                  # Arquivos para ignorar no Git
├── novato/                     # Nível iniciante
│   ├── detective_quest.c       # Programa principal
│   ├── Makefile               # Build system
│   ├── README.md              # Documentação específica
│   └── EXEMPLO_EXECUCAO.md    # Exemplos de uso
├── aventureiro/               # Nível intermediário  
│   ├── detective_quest_pistas.c
│   ├── Makefile
│   ├── README.md
│   ├── EXEMPLOS_EXECUCAO.md
│   └── COMPARACAO_NOVATO_AVENTUREIRO.md
└── mestre/                    # Nível avançado
    ├── detective_quest_mestre.c
    ├── Makefile
    └── README.md
```

## 📊 Comparação dos Níveis

| Aspecto | 🟢 Novato | 🟡 Aventureiro | 🔴 Mestre |
|---------|-----------|----------------|-----------|
| **Estruturas de Dados** | Árvore Binária | Árvore Binária + BST | Árvore Binária + BST + Hash Table |
| **Complexidade** | Básica | Intermediária | Avançada |
| **Funcionalidades** | Navegação | Navegação + Coleta | Navegação + Coleta + Julgamento |
| **Algoritmos** | Percurso simples | Inserção BST + In-order | Hash + Contagem + Análise |
| **Linhas de Código** | ~150 | ~350 | ~650+ |
| **Conceitos Novos** | Ponteiros, Alocação | Ordenação, BST | Hash Tables, Algoritmos complexos |

## 🟢 Nível Novato - Fundamentos

### 📚 O que você aprenderá:
- **Árvore Binária** básica
- **Ponteiros** e estruturas em C
- **Alocação dinâmica** de memória
- **Navegação** em estruturas hierárquicas
- **Modularização** de código

### 🎮 Gameplay:
- Explore uma mansão representada como árvore binária
- Navegue escolhendo caminhos à esquerda ou direita
- Objetivo: Alcançar uma sala sem saídas (nó folha)

### 🚀 Como executar:
```bash
cd novato
make run
```

### 🌳 Estrutura de Dados:
```
                    Hall de Entrada
                   /              \
            Sala de Estar        Cozinha
            /         \          /      \
      Biblioteca  Escritório  Despensa  Jardim
        /              \                   \
  Sala Secreta    Cofre do Tesouro      Estufa
```

---

## 🟡 Nível Aventureiro - Organização

### 📚 O que você aprenderá:
- **Árvore Binária de Busca (BST)**
- **Ordenação automática** de dados
- **Recursividade** avançada
- **Percurso In-Order**
- **Múltiplas estruturas** trabalhando juntas

### 🎮 Gameplay:
- Mesma navegação do nível novato
- **NOVO:** Coleta automática de pistas
- **NOVO:** Organização alfabética de evidências
- **NOVO:** Relatório final detalhado

### 🚀 Como executar:
```bash
cd aventureiro
make run
```

### 🔍 Pistas Disponíveis:
- 7 pistas espalhadas pela mansão
- Organização automática em ordem alfabética
- Sistema de coleta inteligente

### ✨ Novidades:
- Interface aprimorada com emojis
- Feedback em tempo real
- Sistema de relatórios

---

## 🔴 Nível Mestre - Resolução Completa

### 📚 O que você aprenderá:
- **Tabela Hash** com função djb2
- **Algoritmos de contagem** recursiva
- **Tomada de decisão** baseada em dados
- **Sistemas complexos** integrados
- **Análise algorítmica** avançada

### 🎮 Gameplay:
- Navegação e coleta dos níveis anteriores
- **NOVO:** Sistema de suspeitos
- **NOVO:** Associação pista-suspeito via hash table
- **NOVO:** Fase de julgamento inteligente
- **NOVO:** Veredicto baseado em evidências

### 🚀 Como executar:
```bash
cd mestre
make run
```

### ⚖️ Sistema de Julgamento:
- 5 suspeitos únicos com motivações
- 9 pistas distribuídas pela mansão
- Algoritmo de contagem de evidências
- Veredicto automático (necessário ≥2 pistas)

### 👥 Suspeitos:
1. **Dr. Marcus** - Médico com acesso a venenos
2. **Sra. Helena** - Governanta com todos os segredos
3. **Prof. Viktor** - Químico especialista em substâncias
4. **James Butler** - Mordomo com acesso total
5. **Lady Catherine** - Herdeira com motivos financeiros

---

## 🛠️ Requisitos do Sistema

### Pré-requisitos:
- **GCC** (GNU Compiler Collection)
- **Make** utility
- Sistema **Unix/Linux/macOS** ou Windows com ambiente C

### Compilação:
Cada nível possui seu próprio Makefile com comandos padronizados:
```bash
make        # Compila o programa
make run    # Compila e executa
make clean  # Remove arquivos gerados
make help   # Mostra ajuda específica
```

## 📈 Progressão Recomendada

### 🎯 Para Iniciantes:
1. **Comece pelo Novato** - Domine conceitos básicos
2. **Pratique navegação** - Entenda ponteiros e estruturas
3. **Explore completamente** - Teste diferentes caminhos

### 🎯 Para Intermediários:
1. **Complete o Novato** rapidamente
2. **Foque no Aventureiro** - Entenda BST e ordenação
3. **Compare implementações** - Veja a evolução do código

### 🎯 Para Avançados:
1. **Atravesse todos os níveis** sequencialmente
2. **Analise complexidade** - Compare algoritmos
3. **Domine o Mestre** - Integre múltiplas estruturas

## 📊 Análise de Complexidade

### Operações por Nível:

| Operação | Novato | Aventureiro | Mestre |
|----------|--------|-------------|--------|
| **Navegação** | O(1) | O(1) | O(1) |
| **Busca** | - | O(log n) | O(1) hash, O(log n) BST |
| **Inserção** | - | O(log n) | O(log n) BST, O(1) hash |
| **Ordenação** | - | O(n) in-order | O(n) in-order |
| **Contagem** | - | - | O(n) recursiva |

## 🎓 Conceitos Educacionais por Nível

### Estruturas de Dados:
- **Novato:** Árvore Binária
- **Aventureiro:** + Árvore BST
- **Mestre:** + Tabela Hash

### Algoritmos:
- **Novato:** Navegação simples
- **Aventureiro:** + Inserção ordenada, Percurso in-order
- **Mestre:** + Hash function, Contagem recursiva, Análise de dados

### Padrões de Programação:
- **Novato:** Estruturas básicas, Alocação dinâmica
- **Aventureiro:** + Recursividade, Múltiplas estruturas
- **Mestre:** + Sistemas integrados, Algoritmos complexos

## 🔧 Extensões e Melhorias

### Possíveis Adições:
- **Nível Expert:** Grafos e algoritmos de caminho mínimo
- **Modo Multiplayer:** Múltiplos detetives cooperando
- **Sistema de Pontuação:** Rankings baseados em eficiência
- **Interface Gráfica:** Visualização das estruturas de dados
- **Análise de Performance:** Medição de tempo de execução

### Melhorias Algorítmicas:
- **Balanceamento AVL/Red-Black** para BST
- **Hash tables dinâmicas** com redimensionamento
- **Algoritmos de machine learning** para suspeitos

## 🤝 Contribuindo

### Como Contribuir:
1. **Fork** o repositório
2. **Crie uma branch** para sua feature
3. **Implemente melhorias** ou correções
4. **Teste** thoroughly em todos os níveis
5. **Submeta um Pull Request**

### Áreas de Contribuição:
- 🐛 **Bug fixes** e correções
- ✨ **Novas funcionalidades** e níveis
- 📚 **Documentação** aprimorada
- 🎨 **Interface** e experiência do usuário
- ⚡ **Otimizações** de performance

## 📝 Licença

Este projeto é desenvolvido para fins educacionais. Sinta-se livre para usar, modificar e distribuir para propósitos de aprendizado.

## 🏆 Créditos

Desenvolvido como parte do **Data Structure Challenger** - uma iniciativa para tornar o aprendizado de estruturas de dados mais envolvente e prático.

**Enigma Studios** - *"Transformando conceitos complexos em aventuras educativas"*

---

## 🚀 Quick Start

### Para começar imediatamente:

```bash
# Clone o repositório
git clone <repository-url>
cd data-structure-challenger

# Comece pelo nível novato
cd novato
make run

# Quando se sentir confortável, avance
cd ../aventureiro
make run

# Desafie-se no nível mestre
cd ../mestre
make run
```

### 🎯 Dica Final:
Cada nível foi cuidadosamente projetado para construir sobre o anterior. **Não pule níveis!** A progressão gradual é fundamental para um aprendizado sólido.

**Boa sorte, Detective! 🔍🕵️‍♂️**
