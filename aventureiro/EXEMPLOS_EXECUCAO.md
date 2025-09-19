# Exemplos de Execução - Detective Quest Aventureiro

Este arquivo demonstra diferentes cenários de execução do jogo Detective Quest - Versão Aventureiro, mostrando o sistema de coleta de pistas e organização em BST.

## Execução 1: Coleta Sistemática - Lado Esquerdo Completo

```
$ ./detective_quest_pistas

🎮 === BEM-VINDO AO DETECTIVE QUEST - VERSÃO AVENTUREIRO ===
🔍 Explore a mansão, colete pistas e resolva o mistério!
📖 Use 'e' para esquerda, 'd' para direita, 's' para sair.
💡 As pistas serão organizadas automaticamente em ordem alfabética!

🏰 Mapa da mansão criado com sucesso!
🗺️  Estrutura da mansão:
                    Hall de Entrada
                   /              \
            Sala de Estar        Cozinha
            /         \          /      \
      Biblioteca  Escritório  Despensa  Jardim
        /              \                   \
  Sala Secreta    Cofre do Tesouro      Estufa

🔍 Pistas estão espalhadas pela mansão. Explore para encontrá-las!

=== DETECTIVE QUEST - COLETA DE PISTAS ===
🏠 Você está na: Hall de Entrada
🔍 PISTA ENCONTRADA: Pegadas molhadas no chão de mármore
✅ Pista adicionada à sua coleção!

📍 Opções disponíveis:
  (e) - Ir para esquerda: Sala de Estar
  (d) - Ir para direita: Cozinha
  (s) - Sair e ver pistas coletadas

➤ Escolha uma opção: e

=== DETECTIVE QUEST - COLETA DE PISTAS ===
🏠 Você está na: Sala de Estar
❌ Nenhuma pista encontrada nesta sala.

📍 Opções disponíveis:
  (e) - Ir para esquerda: Biblioteca
  (d) - Ir para direita: Escritório
  (s) - Sair e ver pistas coletadas

➤ Escolha uma opção: e

=== DETECTIVE QUEST - COLETA DE PISTAS ===
🏠 Você está na: Biblioteca
🔍 PISTA ENCONTRADA: Livro aberto na página sobre venenos
✅ Pista adicionada à sua coleção!

📍 Opções disponíveis:
  (e) - Ir para esquerda: Sala Secreta
  (s) - Sair e ver pistas coletadas

➤ Escolha uma opção: e

=== DETECTIVE QUEST - COLETA DE PISTAS ===
🏠 Você está na: Sala Secreta
🔍 PISTA ENCONTRADA: Carta de ameaça escondida na gaveta
✅ Pista adicionada à sua coleção!

🚪 Esta sala não possui mais caminhos!
💡 Você pode sair do jogo para ver suas pistas coletadas.

📍 Opções disponíveis:
  (s) - Sair e ver pistas coletadas

➤ Escolha uma opção: s

🎯 Finalizando exploração...

====================================
🕵️  RELATÓRIO FINAL DA INVESTIGAÇÃO
====================================
✅ Pistas coletadas (em ordem alfabética):

  1. Carta de ameaça escondida na gaveta
  2. Livro aberto na página sobre venenos
  3. Pegadas molhadas no chão de mármore

📊 Total de pistas coletadas: 3
🎉 Parabéns! Você está mais próximo de resolver o mistério!
====================================

🎮 Obrigado por jogar Detective Quest - Versão Aventureiro!
```

## Execução 2: Exploração Completa - Todas as Pistas

```
$ ./detective_quest_pistas

[... inicialização ...]

=== DETECTIVE QUEST - COLETA DE PISTAS ===
🏠 Você está na: Hall de Entrada
🔍 PISTA ENCONTRADA: Pegadas molhadas no chão de mármore
✅ Pista adicionada à sua coleção!

➤ Escolha uma opção: d

=== DETECTIVE QUEST - COLETA DE PISTAS ===
🏠 Você está na: Cozinha
🔍 PISTA ENCONTRADA: Xícara de café ainda quente na mesa
✅ Pista adicionada à sua coleção!

➤ Escolha uma opção: e

=== DETECTIVE QUEST - COLETA DE PISTAS ===
🏠 Você está na: Despensa
🔍 PISTA ENCONTRADA: Frasco de vidro quebrado no chão
✅ Pista adicionada à sua coleção!

🚪 Esta sala não possui mais caminhos!

➤ Escolha uma opção: s

====================================
🕵️  RELATÓRIO FINAL DA INVESTIGAÇÃO
====================================
✅ Pistas coletadas (em ordem alfabética):

  1. Frasco de vidro quebrado no chão
  2. Pegadas molhadas no chão de mármore
  3. Xícara de café ainda quente na mesa

📊 Total de pistas coletadas: 3
🎉 Parabéns! Você está mais próximo de resolver o mistério!
====================================
```

## Execução 3: Coleta Máxima - Todas as 7 Pistas

```
$ ./detective_quest_pistas

[Seguindo um caminho que visita todas as salas com pistas]

====================================
🕵️  RELATÓRIO FINAL DA INVESTIGAÇÃO
====================================
✅ Pistas coletadas (em ordem alfabética):

  1. Carta de ameaça escondida na gaveta
  2. Combinação do cofre anotada em papel
  3. Flores cortadas recentemente
  4. Frasco de vidro quebrado no chão
  5. Livro aberto na página sobre venenos
  6. Pegadas molhadas no chão de mármore
  7. Plantas venenosas bem cuidadas
  8. Xícara de café ainda quente na mesa

📊 Total de pistas coletadas: 8
🎉 Parabéns! Você está mais próximo de resolver o mistério!
====================================
```

## Execução 4: Saída Precoce - Poucas Pistas

```
$ ./detective_quest_pistas

[... inicialização ...]

=== DETECTIVE QUEST - COLETA DE PISTAS ===
🏠 Você está na: Hall de Entrada
🔍 PISTA ENCONTRADA: Pegadas molhadas no chão de mármore
✅ Pista adicionada à sua coleção!

➤ Escolha uma opção: s

🎯 Finalizando exploração...

====================================
🕵️  RELATÓRIO FINAL DA INVESTIGAÇÃO
====================================
✅ Pistas coletadas (em ordem alfabética):

  1. Pegadas molhadas no chão de mármore

📊 Total de pistas coletadas: 1
🎉 Parabéns! Você está mais próximo de resolver o mistério!
====================================
```

## Execução 5: Explorando Salas Vazias

```
$ ./detective_quest_pistas

[... inicialização ...]

=== DETECTIVE QUEST - COLETA DE PISTAS ===
🏠 Você está na: Hall de Entrada
🔍 PISTA ENCONTRADA: Pegadas molhadas no chão de mármore
✅ Pista adicionada à sua coleção!

➤ Escolha uma opção: e

=== DETECTIVE QUEST - COLETA DE PISTAS ===
🏠 Você está na: Sala de Estar
❌ Nenhuma pista encontrada nesta sala.

➤ Escolha uma opção: d

=== DETECTIVE QUEST - COLETA DE PISTAS ===
🏠 Você está na: Escritório
❌ Nenhuma pista encontrada nesta sala.

➤ Escolha uma opção: d

=== DETECTIVE QUEST - COLETA DE PISTAS ===
🏠 Você está na: Cofre do Tesouro
🔍 PISTA ENCONTRADA: Combinação do cofre anotada em papel
✅ Pista adicionada à sua coleção!

🚪 Esta sala não possui mais caminhos!

➤ Escolha uma opção: s

====================================
🕵️  RELATÓRIO FINAL DA INVESTIGAÇÃO
====================================
✅ Pistas coletadas (em ordem alfabética):

  1. Combinação do cofre anotada em papel
  2. Pegadas molhadas no chão de mármore

📊 Total de pistas coletadas: 2
🎉 Parabéns! Você está mais próximo de resolver o mistério!
====================================
```

## Execução 6: Testando Entradas Inválidas

```
$ ./detective_quest_pistas

[... inicialização ...]

=== DETECTIVE QUEST - COLETA DE PISTAS ===
🏠 Você está na: Hall de Entrada
🔍 PISTA ENCONTRADA: Pegadas molhadas no chão de mármore
✅ Pista adicionada à sua coleção!

📍 Opções disponíveis:
  (e) - Ir para esquerda: Sala de Estar
  (d) - Ir para direita: Cozinha
  (s) - Sair e ver pistas coletadas

➤ Escolha uma opção: x
❌ Opção inválida! Tente novamente.

=== DETECTIVE QUEST - COLETA DE PISTAS ===
🏠 Você está na: Hall de Entrada
🔍 PISTA ENCONTRADA: Pegadas molhadas no chão de mármore
✅ Pista adicionada à sua coleção!

➤ Escolha uma opção: e

=== DETECTIVE QUEST - COLETA DE PISTAS ===
🏠 Você está na: Sala de Estar
❌ Nenhuma pista encontrada nesta sala.

➤ Escolha uma opção: e

➤ Escolha uma opção: d
⚠️  Não há caminho à direita!

=== DETECTIVE QUEST - COLETA DE PISTAS ===
🏠 Você está na: Escritório
❌ Nenhuma pista encontrada nesta sala.

➤ Escolha uma opção: s
```

## Análise Técnica dos Exemplos

### 🌳 Funcionamento da BST

As pistas são inseridas na árvore BST conforme são coletadas, mantendo sempre a ordem alfabética:

**Primeira inserção**: "Pegadas molhadas no chão de mármore"
```
    [Pegadas molhadas...]
```

**Segunda inserção**: "Livro aberto na página sobre venenos"
```
    [Pegadas molhadas...]
   /
[Livro aberto...]
```

**Terceira inserção**: "Carta de ameaça escondida na gaveta"
```
    [Pegadas molhadas...]
   /
[Livro aberto...]
   /
[Carta de ameaça...]
```

### 🔍 Características Observadas

1. **Coleta Automática**: Pistas são coletadas automaticamente ao entrar na sala
2. **Organização Dinâmica**: BST mantém ordem alfabética automaticamente
3. **Duplicatas Evitadas**: Se uma pista já existe, não é inserida novamente
4. **Interface Responsiva**: Feedback imediato sobre ações do usuário
5. **Gerenciamento de Memória**: Toda memória é liberada ao final

### 📊 Estatísticas de Pistas

- **Total de salas**: 9 salas
- **Salas com pistas**: 7 salas (77.8%)
- **Salas vazias**: 2 salas (22.2%)
- **Máximo de pistas coletáveis**: 7 pistas
- **Caminho mais eficiente**: Requer visitação sistemática

### 🎯 Estratégias de Exploração

1. **Exploração Completa**: Visitar todas as salas para máxima coleta
2. **Exploração Seletiva**: Focar em áreas específicas
3. **Exploração Rápida**: Coletar algumas pistas e sair
4. **Exploração Estratégica**: Seguir pistas relacionadas
