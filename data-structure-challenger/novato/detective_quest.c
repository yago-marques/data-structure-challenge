#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura que representa uma sala (nó da árvore binária)
typedef struct Sala {
    char nome[50];          // Nome da sala
    struct Sala* esquerda;  // Ponteiro para sala à esquerda
    struct Sala* direita;   // Ponteiro para sala à direita
} Sala;

/**
 * Função: criarSala
 * Descrição: Cria uma nova sala de forma dinâmica e inicializa seus campos
 * Parâmetros: nome - string com o nome da sala
 * Retorno: ponteiro para a sala criada
 */
Sala* criarSala(char* nome) {
    // Aloca memória dinamicamente para uma nova sala
    Sala* novaSala = (Sala*)malloc(sizeof(Sala));
    
    if (novaSala == NULL) {
        printf("Erro: Não foi possível alocar memória para a sala.\n");
        exit(1);
    }
    
    // Copia o nome da sala
    strcpy(novaSala->nome, nome);
    
    // Inicializa os ponteiros como NULL (sem caminhos inicialmente)
    novaSala->esquerda = NULL;
    novaSala->direita = NULL;
    
    return novaSala;
}

/**
 * Função: explorarSalas
 * Descrição: Permite a navegação do jogador pela árvore binária
 * Parâmetros: salaAtual - ponteiro para a sala onde o jogador está
 * Retorno: void
 */
void explorarSalas(Sala* salaAtual) {
    char escolha;
    
    // Continua a exploração enquanto não chegar a uma folha
    while (salaAtual != NULL) {
        printf("\n=== DETECTIVE QUEST ===\n");
        printf("Você está na: %s\n", salaAtual->nome);
        
        // Verifica se é uma sala sem saídas (nó folha)
        if (salaAtual->esquerda == NULL && salaAtual->direita == NULL) {
            printf("Esta sala não possui mais caminhos!\n");
            printf("Fim da exploração. Obrigado por jogar!\n");
            break;
        }
        
        // Mostra as opções disponíveis
        printf("\nOpções disponíveis:\n");
        if (salaAtual->esquerda != NULL) {
            printf("(e) - Ir para esquerda: %s\n", salaAtual->esquerda->nome);
        }
        if (salaAtual->direita != NULL) {
            printf("(d) - Ir para direita: %s\n", salaAtual->direita->nome);
        }
        printf("(s) - Sair do jogo\n");
        
        printf("\nEscolha uma opção: ");
        scanf(" %c", &escolha);
        
        // Processa a escolha do jogador
        switch (escolha) {
            case 'e':
            case 'E':
                if (salaAtual->esquerda != NULL) {
                    salaAtual = salaAtual->esquerda;
                } else {
                    printf("Não há caminho à esquerda!\n");
                }
                break;
                
            case 'd':
            case 'D':
                if (salaAtual->direita != NULL) {
                    salaAtual = salaAtual->direita;
                } else {
                    printf("Não há caminho à direita!\n");
                }
                break;
                
            case 's':
            case 'S':
                printf("Saindo do jogo...\n");
                return;
                
            default:
                printf("Opção inválida! Tente novamente.\n");
                break;
        }
    }
}

/**
 * Função: liberarMemoria
 * Descrição: Libera a memória alocada para toda a árvore
 * Parâmetros: raiz - ponteiro para a raiz da árvore
 * Retorno: void
 */
void liberarMemoria(Sala* raiz) {
    if (raiz != NULL) {
        liberarMemoria(raiz->esquerda);
        liberarMemoria(raiz->direita);
        free(raiz);
    }
}

/**
 * Função: main
 * Descrição: Monta o mapa inicial da mansão e inicia a exploração
 * Retorno: 0 se executado com sucesso
 */
int main() {
    printf("=== BEM-VINDO AO DETECTIVE QUEST ===\n");
    printf("Explore a mansão misteriosa e descubra seus segredos!\n");
    printf("Use 'e' para ir à esquerda, 'd' para ir à direita, 's' para sair.\n");
    
    // Criação manual do mapa da mansão (árvore binária)
    Sala* hall = criarSala("Hall de Entrada");
    
    // Segundo nível
    Sala* salaEstar = criarSala("Sala de Estar");
    Sala* cozinha = criarSala("Cozinha");
    
    // Terceiro nível - lado esquerdo
    Sala* biblioteca = criarSala("Biblioteca");
    Sala* escritorio = criarSala("Escritório");
    
    // Terceiro nível - lado direito  
    Sala* despensa = criarSala("Despensa");
    Sala* jardim = criarSala("Jardim");
    
    // Quarto nível - folhas da árvore
    Sala* salaSecreta = criarSala("Sala Secreta");
    Sala* cofre = criarSala("Cofre do Tesouro");
    Sala* greenhouse = criarSala("Estufa");
    
    // Montagem da estrutura da árvore
    // Hall (raiz)
    hall->esquerda = salaEstar;
    hall->direita = cozinha;
    
    // Segundo nível
    salaEstar->esquerda = biblioteca;
    salaEstar->direita = escritorio;
    cozinha->esquerda = despensa;
    cozinha->direita = jardim;
    
    // Terceiro nível (alguns nós folha, outros com filhos)
    biblioteca->esquerda = salaSecreta;
    escritorio->direita = cofre;
    jardim->direita = greenhouse;
    // despensa não tem filhos (nó folha)
    
    printf("\nMapa da mansão criado com sucesso!\n");
    printf("Estrutura da mansão:\n");
    printf("                    Hall de Entrada\n");
    printf("                   /              \\\n");
    printf("            Sala de Estar        Cozinha\n");
    printf("            /         \\          /      \\\n");
    printf("      Biblioteca  Escritório  Despensa  Jardim\n");
    printf("        /              \\                   \\\n");
    printf("  Sala Secreta    Cofre do Tesouro      Estufa\n");
    
    // Inicia a exploração a partir do Hall
    explorarSalas(hall);
    
    // Libera a memória alocada
    liberarMemoria(hall);
    
    return 0;
}
