# Exemplo de Execução - Detective Quest

Este arquivo mostra um exemplo completo de execução do jogo Detective Quest, demonstrando os diferentes caminhos que podem ser explorados na mansão.

## Execução 1: Explorando o lado esquerdo até a Sala Secreta

```
$ ./detective_quest

=== BEM-VINDO AO DETECTIVE QUEST ===
Explore a mansão misteriosa e descubra seus segredos!
Use 'e' para ir à esquerda, 'd' para ir à direita, 's' para sair.

Mapa da mansão criado com sucesso!
Estrutura da mansão:
                    Hall de Entrada
                   /              \
            Sala de Estar        Cozinha
            /         \          /      \
      Biblioteca  Escritório  Despensa  Jardim
        /              \                   \
  Sala Secreta    Cofre do Tesouro      Estufa

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

Escolha uma opção: e

=== DETECTIVE QUEST ===
Você está na: Biblioteca

Opções disponíveis:
(e) - Ir para esquerda: Sala Secreta
(s) - Sair do jogo

Escolha uma opção: e

=== DETECTIVE QUEST ===
Você está na: Sala Secreta
Esta sala não possui mais caminhos!
Fim da exploração. Obrigado por jogar!
```

## Execução 2: Explorando o lado direito até a Despensa

```
$ ./detective_quest

=== BEM-VINDO AO DETECTIVE QUEST ===
Explore a mansão misteriosa e descubra seus segredos!
Use 'e' para ir à esquerda, 'd' para ir à direita, 's' para sair.

Mapa da mansão criado com sucesso!
Estrutura da mansão:
                    Hall de Entrada
                   /              \
            Sala de Estar        Cozinha
            /         \          /      \
      Biblioteca  Escritório  Despensa  Jardim
        /              \                   \
  Sala Secreta    Cofre do Tesouro      Estufa

=== DETECTIVE QUEST ===
Você está na: Hall de Entrada

Opções disponíveis:
(e) - Ir para esquerda: Sala de Estar
(d) - Ir para direita: Cozinha
(s) - Sair do jogo

Escolha uma opção: d

=== DETECTIVE QUEST ===
Você está na: Cozinha

Opções disponíveis:
(e) - Ir para esquerda: Despensa
(d) - Ir para direita: Jardim
(s) - Sair do jogo

Escolha uma opção: e

=== DETECTIVE QUEST ===
Você está na: Despensa
Esta sala não possui mais caminhos!
Fim da exploração. Obrigado por jogar!
```

## Execução 3: Explorando até o Cofre do Tesouro

```
$ ./detective_quest

=== BEM-VINDO AO DETECTIVE QUEST ===
Explore a mansão misteriosa e descubra seus segredos!
Use 'e' para ir à esquerda, 'd' para ir à direita, 's' para sair.

Mapa da mansão criado com sucesso!
Estrutura da mansão:
                    Hall de Entrada
                   /              \
            Sala de Estar        Cozinha
            /         \          /      \
      Biblioteca  Escritório  Despensa  Jardim
        /              \                   \
  Sala Secreta    Cofre do Tesouro      Estufa

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

## Execução 4: Testando entrada inválida e saída antecipada

```
$ ./detective_quest

=== BEM-VINDO AO DETECTIVE QUEST ===
Explore a mansão misteriosa e descubra seus segredos!
Use 'e' para ir à esquerda, 'd' para ir à direita, 's' para sair.

Mapa da mansão criado com sucesso!
Estrutura da mansão:
                    Hall de Entrada
                   /              \
            Sala de Estar        Cozinha
            /         \          /      \
      Biblioteca  Escritório  Despensa  Jardim
        /              \                   \
  Sala Secreta    Cofre do Tesouro      Estufa

=== DETECTIVE QUEST ===
Você está na: Hall de Entrada

Opções disponíveis:
(e) - Ir para esquerda: Sala de Estar
(d) - Ir para direita: Cozinha
(s) - Sair do jogo

Escolha uma opção: x
Opção inválida! Tente novamente.

=== DETECTIVE QUEST ===
Você está na: Hall de Entrada

Opções disponíveis:
(e) - Ir para esquerda: Sala de Estar
(d) - Ir para direita: Cozinha
(s) - Sair do jogo

Escolha uma opção: d

=== DETECTIVE QUEST ===
Você está na: Cozinha

Opções disponíveis:
(e) - Ir para esquerda: Despensa
(d) - Ir para direita: Jardim
(s) - Sair do jogo

Escolha uma opção: s
Saindo do jogo...
```

## Análise dos Caminhos Possíveis

### Nós Folha (Salas sem saídas):
- **Sala Secreta**: Caminho e → e → e
- **Despensa**: Caminho d → e  
- **Cofre do Tesouro**: Caminho e → d → d
- **Estufa**: Caminho d → d → d

### Validações Implementadas:
- ✅ Entrada inválida é tratada com mensagem de erro
- ✅ Tentativa de ir para direção sem caminho é bloqueada
- ✅ Opção de sair antecipadamente funciona
- ✅ Detecção automática de nós folha
- ✅ Liberação de memória ao final do programa

### Características Educativas:
- Interface clara mostrando a posição atual
- Visualização da estrutura da árvore no início
- Feedback imediato para escolhas inválidas
- Exploração livre permitindo diferentes estratégias
