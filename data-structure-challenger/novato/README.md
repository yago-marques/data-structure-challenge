# Detective Quest - Desafio Novato

## 📖 Descrição

Detective Quest é um jogo eletrônico educativo desenvolvido para ensinar conceitos de estrutura de dados, especificamente **árvores binárias**. O jogador explora uma mansão misteriosa representada por uma árvore binária, navegando pelos cômodos através de escolhas entre caminhos à esquerda ou à direita.

## 🎯 Objetivo do Desafio

Implementar um sistema que controla o mapa da mansão usando uma árvore binária, permitindo exploração interativa até chegar a um cômodo sem saídas (nó folha).

## 🏗️ Estrutura da Mansão

```
                    Hall de Entrada
                   /              \
            Sala de Estar        Cozinha
            /         \          /      \
      Biblioteca  Escritório  Despensa  Jardim
        /              \                   \
  Sala Secreta    Cofre do Tesouro      Estufa
```

## 🚀 Como Executar

### Pré-requisitos
- Compilador GCC instalado
- Sistema operacional Unix/Linux/macOS ou Windows com ambiente de desenvolvimento C

### Compilação e Execução

1. **Usando o Makefile (recomendado):**
   ```bash
   make run
   ```

2. **Compilação manual:**
   ```bash
   gcc -Wall -Wextra -std=c99 -g -o detective_quest detective_quest.c
   ./detective_quest
   ```

3. **Apenas compilar:**
   ```bash
   make
   ```

4. **Limpar arquivos gerados:**
   ```bash
   make clean
   ```

## 🎮 Como Jogar

1. O jogo inicia no **Hall de Entrada**
2. A cada sala, você verá:
   - Nome da sala atual
   - Opções de caminhos disponíveis
   - Menu de navegação

3. **Comandos:**
   - `e` ou `E` - Ir para a esquerda
   - `d` ou `D` - Ir para a direita
   - `s` ou `S` - Sair do jogo

4. O jogo termina quando você alcança uma sala sem saídas (nó folha)

## 📚 Conceitos Trabalhados

### Estruturas de Dados
- **Árvore Binária**: Estrutura hierárquica com no máximo dois filhos por nó
- **Nós Folha**: Nós sem filhos (salas sem saídas)
- **Navegação em Árvore**: Percurso através de decisões do usuário

### Programação em C
- **Structs**: Tipo personalizado `Sala` com nome e ponteiros
- **Alocação Dinâmica**: Uso de `malloc()` para criar nós
- **Ponteiros**: Conexões entre salas da árvore
- **Modularização**: Funções com responsabilidades específicas

## 🔧 Funções Implementadas

### `criarSala(char* nome)`
- **Propósito**: Cria uma nova sala dinamicamente
- **Parâmetros**: Nome da sala
- **Retorno**: Ponteiro para a sala criada

### `explorarSalas(Sala* salaAtual)`
- **Propósito**: Controla a navegação interativa do jogador
- **Parâmetros**: Sala onde o jogador está
- **Retorno**: void

### `liberarMemoria(Sala* raiz)`
- **Propósito**: Libera toda a memória alocada para a árvore
- **Parâmetros**: Ponteiro para a raiz da árvore
- **Retorno**: void

### `main()`
- **Propósito**: Constrói o mapa inicial e inicia a exploração
- **Retorno**: 0 se executado com sucesso

## 🎓 Características do Nível Novato

- ✅ Árvore binária simples (sem busca ou inserção dinâmica)
- ✅ Navegação baseada em menu de opções
- ✅ Estrutura da mansão definida manualmente no código
- ✅ Foco na compreensão de conceitos básicos
- ✅ Interface de usuário simples e intuitiva

## 🏆 Exemplo de Execução

```
=== BEM-VINDO AO DETECTIVE QUEST ===
Explore a mansão misteriosa e descubra seus segredos!
Use 'e' para ir à esquerda, 'd' para ir à direita, 's' para sair.

=== DETECTIVE QUEST ===
Você está na: Hall de Entrada

Opções disponíveis:
(e) - Ir para esquerda: Sala de Estar
(d) - Ir para direita: Cozinha
(s) - Sair do jogo

Escolha uma opção: e

=== DETECTIVE QUEST ===
Você está na: Sala de Estar

Opções disponíveis:
(e) - Ir para esquerda: Biblioteca
(d) - Ir para direita: Escritório
(s) - Sair do jogo

Escolha uma opção: d

=== DETECTIVE QUEST ===
Você está na: Escritório

Opções disponíveis:
(d) - Ir para direita: Cofre do Tesouro
(s) - Sair do jogo

Escolha uma opção: d

=== DETECTIVE QUEST ===
Você está na: Cofre do Tesouro
Esta sala não possui mais caminhos!
Fim da exploração. Obrigado por jogar!
```

## 📝 Observações

- O programa gerencia automaticamente a memória alocada
- Validação de entradas do usuário
- Interface clara e educativa
- Código bem comentado e documentado
- Estrutura modular para fácil compreensão
