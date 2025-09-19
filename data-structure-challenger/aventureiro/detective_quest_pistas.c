#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura para nó da árvore BST de pistas
typedef struct PistaNode {
    char pista[100];                // Conteúdo da pista
    struct PistaNode* esquerda;     // Subárvore esquerda
    struct PistaNode* direita;      // Subárvore direita
} PistaNode;

// Estrutura que representa uma sala (nó da árvore binária da mansão)
typedef struct Sala {
    char nome[50];          // Nome da sala
    char pista[100];        // Pista encontrada na sala (pode estar vazia)
    struct Sala* esquerda;  // Ponteiro para sala à esquerda
    struct Sala* direita;   // Ponteiro para sala à direita
} Sala;

/**
 * Função: criarSala
 * Descrição: Cria uma nova sala de forma dinâmica com nome e pista opcional
 * Parâmetros: nome - string com o nome da sala
 *             pista - string com a pista (pode ser "" se não houver pista)
 * Retorno: ponteiro para a sala criada
 */
Sala* criarSala(char* nome, char* pista) {
    // Aloca memória dinamicamente para uma nova sala
    Sala* novaSala = (Sala*)malloc(sizeof(Sala));
    
    if (novaSala == NULL) {
        printf("Erro: Não foi possível alocar memória para a sala.\n");
        exit(1);
    }
    
    // Copia o nome e a pista da sala
    strcpy(novaSala->nome, nome);
    strcpy(novaSala->pista, pista);
    
    // Inicializa os ponteiros como NULL
    novaSala->esquerda = NULL;
    novaSala->direita = NULL;
    
    return novaSala;
}

/**
 * Função: criarPistaNode
 * Descrição: Cria um novo nó para a árvore BST de pistas
 * Parâmetros: pista - string com o conteúdo da pista
 * Retorno: ponteiro para o nó criado
 */
PistaNode* criarPistaNode(char* pista) {
    PistaNode* novoNode = (PistaNode*)malloc(sizeof(PistaNode));
    
    if (novoNode == NULL) {
        printf("Erro: Não foi possível alocar memória para a pista.\n");
        exit(1);
    }
    
    strcpy(novoNode->pista, pista);
    novoNode->esquerda = NULL;
    novoNode->direita = NULL;
    
    return novoNode;
}

/**
 * Função: inserirPista
 * Descrição: Insere uma nova pista na árvore BST mantendo ordem alfabética
 * Parâmetros: raiz - ponteiro para ponteiro da raiz da árvore BST
 *             pista - string com a pista a ser inserida
 * Retorno: ponteiro para a raiz atualizada
 */
PistaNode* inserirPista(PistaNode* raiz, char* pista) {
    // Caso base: árvore vazia ou chegou ao local de inserção
    if (raiz == NULL) {
        return criarPistaNode(pista);
    }
    
    // Compara a pista com o nó atual para decidir o lado da inserção
    int comparacao = strcmp(pista, raiz->pista);
    
    if (comparacao < 0) {
        // Pista é menor lexicograficamente, insere à esquerda
        raiz->esquerda = inserirPista(raiz->esquerda, pista);
    } else if (comparacao > 0) {
        // Pista é maior lexicograficamente, insere à direita
        raiz->direita = inserirPista(raiz->direita, pista);
    }
    // Se comparacao == 0, a pista já existe, não insere duplicata
    
    return raiz;
}

/**
 * Função: exibirPistas
 * Descrição: Exibe todas as pistas em ordem alfabética (percurso in-order)
 * Parâmetros: raiz - ponteiro para a raiz da árvore BST
 *             contador - ponteiro para contador de pistas
 * Retorno: void
 */
void exibirPistas(PistaNode* raiz, int* contador) {
    if (raiz != NULL) {
        // Percorre subárvore esquerda
        exibirPistas(raiz->esquerda, contador);
        
        // Processa nó atual
        (*contador)++;
        printf("  %d. %s\n", *contador, raiz->pista);
        
        // Percorre subárvore direita
        exibirPistas(raiz->direita, contador);
    }
}

/**
 * Função: explorarSalasComPistas
 * Descrição: Permite navegação pela mansão coletando pistas automaticamente
 * Parâmetros: salaAtual - ponteiro para a sala onde o jogador está
 *             pistasColetadas - ponteiro para ponteiro da árvore BST de pistas
 * Retorno: void
 */
void explorarSalasComPistas(Sala* salaAtual, PistaNode** pistasColetadas) {
    char escolha;
    
    while (salaAtual != NULL) {
        printf("\n=== DETECTIVE QUEST - COLETA DE PISTAS ===\n");
        printf("🏠 Você está na: %s\n", salaAtual->nome);
        
        // Verifica se há pista na sala atual
        if (strlen(salaAtual->pista) > 0) {
            printf("🔍 PISTA ENCONTRADA: %s\n", salaAtual->pista);
            *pistasColetadas = inserirPista(*pistasColetadas, salaAtual->pista);
            printf("✅ Pista adicionada à sua coleção!\n");
        } else {
            printf("❌ Nenhuma pista encontrada nesta sala.\n");
        }
        
        // Verifica se é uma sala sem saídas (nó folha)
        if (salaAtual->esquerda == NULL && salaAtual->direita == NULL) {
            printf("\n🚪 Esta sala não possui mais caminhos!\n");
            printf("💡 Você pode sair do jogo para ver suas pistas coletadas.\n");
        }
        
        // Mostra as opções disponíveis
        printf("\n📍 Opções disponíveis:\n");
        if (salaAtual->esquerda != NULL) {
            printf("  (e) - Ir para esquerda: %s\n", salaAtual->esquerda->nome);
        }
        if (salaAtual->direita != NULL) {
            printf("  (d) - Ir para direita: %s\n", salaAtual->direita->nome);
        }
        printf("  (s) - Sair e ver pistas coletadas\n");
        
        printf("\n➤ Escolha uma opção: ");
        scanf(" %c", &escolha);
        
        // Processa a escolha do jogador
        switch (escolha) {
            case 'e':
            case 'E':
                if (salaAtual->esquerda != NULL) {
                    salaAtual = salaAtual->esquerda;
                } else {
                    printf("⚠️  Não há caminho à esquerda!\n");
                }
                break;
                
            case 'd':
            case 'D':
                if (salaAtual->direita != NULL) {
                    salaAtual = salaAtual->direita;
                } else {
                    printf("⚠️  Não há caminho à direita!\n");
                }
                break;
                
            case 's':
            case 'S':
                printf("\n🎯 Finalizando exploração...\n");
                return;
                
            default:
                printf("❌ Opção inválida! Tente novamente.\n");
                break;
        }
    }
}

/**
 * Função: liberarMemoriaSalas
 * Descrição: Libera a memória alocada para toda a árvore de salas
 * Parâmetros: raiz - ponteiro para a raiz da árvore de salas
 * Retorno: void
 */
void liberarMemoriaSalas(Sala* raiz) {
    if (raiz != NULL) {
        liberarMemoriaSalas(raiz->esquerda);
        liberarMemoriaSalas(raiz->direita);
        free(raiz);
    }
}

/**
 * Função: liberarMemoriaPistas
 * Descrição: Libera a memória alocada para toda a árvore BST de pistas
 * Parâmetros: raiz - ponteiro para a raiz da árvore BST
 * Retorno: void
 */
void liberarMemoriaPistas(PistaNode* raiz) {
    if (raiz != NULL) {
        liberarMemoriaPistas(raiz->esquerda);
        liberarMemoriaPistas(raiz->direita);
        free(raiz);
    }
}

/**
 * Função: exibirRelatorioFinal
 * Descrição: Mostra o relatório final com todas as pistas coletadas
 * Parâmetros: pistasColetadas - ponteiro para a raiz da árvore BST de pistas
 * Retorno: void
 */
void exibirRelatorioFinal(PistaNode* pistasColetadas) {
    printf("\n" "====================================\n");
    printf("🕵️  RELATÓRIO FINAL DA INVESTIGAÇÃO\n");
    printf("====================================\n");
    
    if (pistasColetadas == NULL) {
        printf("❌ Nenhuma pista foi coletada durante a exploração.\n");
        printf("💡 Tente explorar mais salas na próxima vez!\n");
    } else {
        printf("✅ Pistas coletadas (em ordem alfabética):\n\n");
        int contador = 0;
        exibirPistas(pistasColetadas, &contador);
        printf("\n📊 Total de pistas coletadas: %d\n", contador);
        printf("🎉 Parabéns! Você está mais próximo de resolver o mistério!\n");
    }
    
    printf("====================================\n");
}

/**
 * Função: main
 * Descrição: Monta o mapa da mansão com pistas e inicia a exploração
 * Retorno: 0 se executado com sucesso
 */
int main() {
    printf("🎮 === BEM-VINDO AO DETECTIVE QUEST - VERSÃO AVENTUREIRO ===\n");
    printf("🔍 Explore a mansão, colete pistas e resolva o mistério!\n");
    printf("📖 Use 'e' para esquerda, 'd' para direita, 's' para sair.\n");
    printf("💡 As pistas serão organizadas automaticamente em ordem alfabética!\n");
    
    // Inicializa a árvore BST de pistas (vazia no início)
    PistaNode* pistasColetadas = NULL;
    
    // Criação do mapa da mansão com pistas distribuídas
    Sala* hall = criarSala("Hall de Entrada", "Pegadas molhadas no chão de mármore");
    
    // Segundo nível
    Sala* salaEstar = criarSala("Sala de Estar", "");  // Sem pista
    Sala* cozinha = criarSala("Cozinha", "Xícara de café ainda quente na mesa");
    
    // Terceiro nível - lado esquerdo
    Sala* biblioteca = criarSala("Biblioteca", "Livro aberto na página sobre venenos");
    Sala* escritorio = criarSala("Escritório", "");  // Sem pista
    
    // Terceiro nível - lado direito  
    Sala* despensa = criarSala("Despensa", "Frasco de vidro quebrado no chão");
    Sala* jardim = criarSala("Jardim", "Flores cortadas recentemente");
    
    // Quarto nível - folhas da árvore
    Sala* salaSecreta = criarSala("Sala Secreta", "Carta de ameaça escondida na gaveta");
    Sala* cofre = criarSala("Cofre do Tesouro", "Combinação do cofre anotada em papel");
    Sala* greenhouse = criarSala("Estufa", "Plantas venenosas bem cuidadas");
    
    // Montagem da estrutura da árvore
    // Hall (raiz)
    hall->esquerda = salaEstar;
    hall->direita = cozinha;
    
    // Segundo nível
    salaEstar->esquerda = biblioteca;
    salaEstar->direita = escritorio;
    cozinha->esquerda = despensa;
    cozinha->direita = jardim;
    
    // Terceiro nível
    biblioteca->esquerda = salaSecreta;
    escritorio->direita = cofre;
    jardim->direita = greenhouse;
    // despensa não tem filhos (nó folha)
    
    printf("\n🏰 Mapa da mansão criado com sucesso!\n");
    printf("🗺️  Estrutura da mansão:\n");
    printf("                    Hall de Entrada\n");
    printf("                   /              \\\n");
    printf("            Sala de Estar        Cozinha\n");
    printf("            /         \\          /      \\\n");
    printf("      Biblioteca  Escritório  Despensa  Jardim\n");
    printf("        /              \\                   \\\n");
    printf("  Sala Secreta    Cofre do Tesouro      Estufa\n");
    
    printf("\n🔍 Pistas estão espalhadas pela mansão. Explore para encontrá-las!\n");
    
    // Inicia a exploração com coleta de pistas
    explorarSalasComPistas(hall, &pistasColetadas);
    
    // Exibe o relatório final com todas as pistas coletadas
    exibirRelatorioFinal(pistasColetadas);
    
    // Libera toda a memória alocada
    liberarMemoriaSalas(hall);
    liberarMemoriaPistas(pistasColetadas);
    
    printf("\n🎮 Obrigado por jogar Detective Quest - Versão Aventureiro!\n");
    
    return 0;
}
