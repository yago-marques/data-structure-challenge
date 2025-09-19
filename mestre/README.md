# Detective Quest - Nível Mestre 🕵️‍♂️👑

## 📖 Descrição

O **Nível Mestre** representa o ápice da série Detective Quest, combinando **três estruturas de dados fundamentais** em um sistema completo de investigação criminal. Os jogadores exploram uma mansão, coletam pistas automaticamente organizadas, e utilizam um sistema de julgamento baseado em evidências para resolver o mistério.

## 🎯 Objetivo do Desafio

Implementar um sistema completo que demonstra o domínio de:
- **Árvore Binária** para navegação espacial
- **Árvore BST** para organização ordenada de dados
- **Tabela Hash** para associações eficientes
- **Algoritmos de contagem** para tomada de decisões

## 🏗️ Arquitetura do Sistema

### 🌳 Estrutura da Mansão
```
                    Hall de Entrada
                   /              \
              Biblioteca        Cozinha
              /       \        /      \
       Laboratório  Escritório Quarto  Jardim
                        \      Principal   \
                       Adega            Cofre Secreto
```

### 🔗 Mapeamento Pista → Suspeito
| Pista | Suspeito Apontado |
|-------|-------------------|
| Pegadas molhadas de sapatos caros | Dr. Marcus |
| Livro de toxicologia com páginas marcadas | Prof. Viktor |
| Frasco de cianeto parcialmente vazio | Prof. Viktor |
| Testamento alterado recentemente | Lady Catherine |
| Restos de plantas venenosas no liquidificador | Sra. Helena |
| Carta de chantagem escondida na gaveta | James Butler |
| Ferramentas de jardinagem com traces suspeitos | Sra. Helena |
| Garrafa de vinho adulterada | Dr. Marcus |
| Documentos comprometedores sobre heranças | Lady Catherine |

## 🚀 Como Executar

### Pré-requisitos
- Compilador GCC (C99 ou superior)
- Sistema Unix/Linux/macOS ou Windows com ambiente C

### Comandos Principais

1. **Execução padrão:**
   ```bash
   make run
   ```

2. **Execução com detalhes:**
   ```bash
   make test
   ```

3. **Demonstração das funcionalidades:**
   ```bash
   make demo
   ```

4. **Verificar estruturas de dados:**
   ```bash
   make check-structures
   ```

5. **Ajuda completa:**
   ```bash
   make help
   ```

## 🎮 Como Jogar

### Fase 1: Exploração 🔍
1. **Navegação**: Use `e` (esquerda), `d` (direita), `s` (sair)
2. **Coleta Automática**: Pistas são coletadas automaticamente ao entrar nas salas
3. **Organização**: Pistas são inseridas na BST mantendo ordem alfabética
4. **Associação**: Sistema mostra qual suspeito cada pista aponta

### Fase 2: Julgamento ⚖️
1. **Revisão de Evidências**: Todas as pistas são exibidas ordenadamente
2. **Análise de Suspeitos**: Lista dos 5 suspeitos com descrições
3. **Acusação**: Escolher um suspeito baseado nas evidências
4. **Veredicto**: Sistema verifica se há evidências suficientes (≥2 pistas)

## 📚 Estruturas de Dados Implementadas

### 1. Árvore Binária (Mapa da Mansão)
```c
typedef struct Sala {
    char nome[50];          // Nome da sala
    struct Sala* esquerda;  // Sala à esquerda
    struct Sala* direita;   // Sala à direita
} Sala;
```

**Características:**
- Navegação hierárquica pela mansão
- Cada nó representa uma sala específica
- Estrutura fixa definida no código

### 2. Árvore BST (Organização de Pistas)
```c
typedef struct PistaNode {
    char pista[100];                // Conteúdo da pista
    struct PistaNode* esquerda;     // Subárvore esquerda
    struct PistaNode* direita;      // Subárvore direita
} PistaNode;
```

**Características:**
- Ordenação automática alfabética
- Inserção eficiente O(log n) no melhor caso
- Percurso in-order para exibição ordenada
- Evita duplicatas automaticamente

### 3. Tabela Hash (Associação Pista-Suspeito)
```c
typedef struct HashNode {
    char pista[100];            // Chave: pista
    char suspeito[50];          // Valor: suspeito
    struct HashNode* proximo;   // Resolução de colisões
} HashNode;
```

**Características:**
- Função hash djb2 para distribuição uniforme
- Resolução de colisões por encadeamento
- Acesso O(1) no caso médio
- Associações pré-definidas pista → suspeito

## 🔧 Funções Principais

### Gerenciamento de Salas
- **`criarSala(nome)`** - Cria sala dinamicamente
- **`explorarSalas(sala, pistas)`** - Controla navegação e coleta
- **`obterPistaPorSala(nome)`** - Retorna pista específica da sala

### Gerenciamento de Pistas (BST)
- **`criarPistaNode(pista)`** - Cria nó da BST
- **`inserirPista(raiz, pista)`** - Insere mantendo ordem
- **`exibirPistas(raiz, contador)`** - Exibe ordenadamente
- **`contarPistasPorSuspeito(raiz, suspeito)`** - Conta evidências

### Gerenciamento da Tabela Hash
- **`funcaoHash(str)`** - Calcula índice hash (algoritmo djb2)
- **`inserirNaHash(pista, suspeito)`** - Insere associação
- **`encontrarSuspeito(pista)`** - Busca suspeito por pista
- **`inicializarTabelaHash()`** - Popula tabela inicial

### Sistema de Julgamento
- **`verificarSuspeitoFinal(pistas)`** - Conduz julgamento completo
- Interface completa de acusação e veredicto

## 👥 Suspeitos Disponíveis

1. **Dr. Marcus** - *Médico da família, tem acesso a venenos*
2. **Sra. Helena** - *Governanta, conhece todos os segredos da casa*
3. **Prof. Viktor** - *Professor de química, especialista em substâncias*
4. **James Butler** - *Mordomo, tem acesso a todas as áreas*
5. **Lady Catherine** - *Herdeira, tem motivos financeiros*

## 🏆 Exemplo de Execução Completa

```
🎮 === DETECTIVE QUEST - NÍVEL MESTRE ===
🕵️  Bem-vindo à investigação mais complexa!

🏰 === DETECTIVE QUEST - INVESTIGAÇÃO MESTRE ===
📍 Você está na: Hall de Entrada
🔍 PISTA DESCOBERTA: Pegadas molhadas de sapatos caros
🎯 Esta pista aponta para: Dr. Marcus
✅ Pista adicionada ao seu dossiê!

[... exploração continua ...]

⚖️  FASE DE JULGAMENTO - DETECTIVE QUEST
📋 DOSSIÊ COMPLETO - Pistas coletadas:

  1. Frasco de cianeto parcialmente vazio
     👤 Aponta para: Prof. Viktor
  2. Garrafa de vinho adulterada
     👤 Aponta para: Dr. Marcus
  3. Pegadas molhadas de sapatos caros
     👤 Aponta para: Dr. Marcus

📊 Total de pistas coletadas: 3

👥 SUSPEITOS DISPONÍVEIS:
  1. Dr. Marcus - Médico da família, tem acesso a venenos
  2. Sra. Helena - Governanta, conhece todos os segredos da casa
  3. Prof. Viktor - Professor de química, especialista em substâncias
  4. James Butler - Mordomo, tem acesso a todas as áreas
  5. Lady Catherine - Herdeira, tem motivos financeiros

🎯 Baseado nas evidências, quem você acusa?
Digite o número do suspeito (1-5): 1

⚖️  ACUSAÇÃO FORMAL: Dr. Marcus

📈 ANÁLISE DAS EVIDÊNCIAS:
   Pistas que apontam para Dr. Marcus: 2
   Evidências necessárias para condenação: 2

==========================================
✅ VEREDICTO: CULPADO!
🎉 Parabéns, Detective! Você reuniu evidências suficientes!
⚖️  Dr. Marcus foi considerado culpado com base em 2 pistas sólidas.
🏆 Caso resolvido com sucesso!
==========================================
```

## 🎓 Conceitos Educacionais Avançados

### Algoritmos Implementados

#### **Função Hash (djb2)**
```c
unsigned int funcaoHash(const char* str) {
    unsigned long hash = 5381;
    int c;
    while ((c = *str++)) {
        hash = ((hash << 5) + hash) + c; // hash * 33 + c
    }
    return hash % HASH_SIZE;
}
```

#### **Contagem Recursiva**
```c
int contarPistasPorSuspeito(PistaNode* raiz, char* suspeitoAlvo) {
    if (raiz == NULL) return 0;
    
    int count = 0;
    char* suspeito = encontrarSuspeito(raiz->pista);
    if (suspeito && strcmp(suspeito, suspeitoAlvo) == 0) {
        count = 1;
    }
    
    return count + 
           contarPistasPorSuspeito(raiz->esquerda, suspeitoAlvo) +
           contarPistasPorSuspeito(raiz->direita, suspeitoAlvo);
}
```

### Complexidade Computacional

| Operação | Estrutura | Melhor Caso | Caso Médio | Pior Caso |
|----------|-----------|-------------|------------|-----------|
| Navegação | Árvore Binária | O(1) | O(1) | O(1) |
| Inserção Pista | BST | O(log n) | O(log n) | O(n) |
| Busca Suspeito | Hash Table | O(1) | O(1) | O(n) |
| Contagem | BST | O(n) | O(n) | O(n) |
| Exibição | BST | O(n) | O(n) | O(n) |

## 🔍 Estratégias de Investigação

### Para Máxima Eficiência:
1. **Exploração Sistemática**: Visite todas as salas disponíveis
2. **Análise de Padrões**: Observe quais suspeitos têm mais evidências
3. **Coleta Completa**: Colete todas as 9 pistas disponíveis
4. **Julgamento Estratégico**: Acuse suspeitos com 2+ evidências

### Distribuição de Evidências:
- **Dr. Marcus**: 2 pistas (Pegadas + Garrafa de vinho)
- **Prof. Viktor**: 2 pistas (Livro toxicologia + Frasco cianeto)
- **Lady Catherine**: 2 pistas (Testamento + Documentos heranças)
- **Sra. Helena**: 2 pistas (Plantas venenosas + Ferramentas jardim)
- **James Butler**: 1 pista (Carta chantagem)

## 🔄 Comparação com Níveis Anteriores

| Aspecto | Novato | Aventureiro | Mestre |
|---------|--------|-------------|--------|
| **Estruturas** | 1 árvore | 2 árvores | 3 estruturas |
| **Algoritmos** | Navegação | Nav. + Ordenação | Nav. + Ord. + Hash + Contagem |
| **Complexidade** | Básica | Intermediária | Avançada |
| **Tomada de Decisão** | Manual | Semi-automática | Automática baseada em dados |
| **Interface** | Simples | Aprimorada | Profissional |

## 📈 Extensões Possíveis

### Melhorias Algorítmicas:
- **Balanceamento AVL/Red-Black** para BST garantida O(log n)
- **Hash table dinâmica** com redimensionamento automático
- **Algoritmos de ranking** para suspeitos mais prováveis

### Funcionalidades Adicionais:
- **Sistema de pontuação** baseado em qualidade das evidências
- **Múltiplos casos** com diferentes configurações
- **Modo cooperativo** para múltiplos detetives
- **Análise estatística** de padrões de investigação

## 🏆 Critérios de Sucesso

### ✅ Domínio Técnico
- Implementação correta de 3 estruturas de dados
- Gerenciamento adequado de memória
- Algoritmos eficientes para cada operação

### ✅ Design de Software
- Modularização clara e responsabilidades definidas
- Interface intuitiva e informativa
- Tratamento de casos extremos

### ✅ Experiência do Usuário
- Feedback imediato e informativo
- Progressão lógica através do caso
- Conclusão satisfatória baseada em evidências

## 📝 Observações Finais

O **Nível Mestre** representa a culminação da série Detective Quest, demonstrando como diferentes estruturas de dados podem trabalhar em harmonia para resolver problemas complexos. Este projeto serve como uma excelente ponte entre conceitos acadêmicos e aplicações práticas, preparando estudantes para desafios de programação do mundo real.

**Parabéns por chegar ao nível mestre! 🎓👑**
