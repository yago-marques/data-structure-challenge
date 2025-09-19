#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HASH_SIZE 20
#define MAX_SUSPEITOS 5

// Estrutura para suspeitos
typedef struct {
    char nome[50];
    char descricao[100];
} Suspeito;

// Estrutura para nó da tabela hash (pista -> suspeito)
typedef struct HashNode {
    char pista[100];
    char suspeito[50];
    struct HashNode* proximo;
} HashNode;

// Estrutura para nó da árvore BST de pistas
typedef struct PistaNode {
    char pista[100];
    struct PistaNode* esquerda;
    struct PistaNode* direita;
} PistaNode;

// Estrutura que representa uma sala (nó da árvore binária da mansão)
typedef struct Sala {
    char nome[50];
    struct Sala* esquerda;
    struct Sala* direita;
} Sala;

// Tabela hash global para associações pista-suspeito
HashNode* tabelaHash[HASH_SIZE];

// Lista de suspeitos disponíveis
Suspeito suspeitos[MAX_SUSPEITOS] = {
    {"Dr. Marcus", "Médico da família, tem acesso a venenos"},
    {"Sra. Helena", "Governanta, conhece todos os segredos da casa"},
    {"Prof. Viktor", "Professor de química, especialista em substâncias"},
    {"James Butler", "Mordomo, tem acesso a todas as áreas"},
    {"Lady Catherine", "Herdeira, tem motivos financeiros"}
};

/**
 * Função: funcaoHash
 * Descrição: Calcula o índice hash para uma string usando algoritmo djb2
 * Parâmetros: str - string para calcular o hash
 * Retorno: índice da tabela hash
 */
unsigned int funcaoHash(const char* str) {
    unsigned long hash = 5381;
    int c;
    while ((c = *str++)) {
        hash = ((hash << 5) + hash) + c; // hash * 33 + c
    }
    return hash % HASH_SIZE;
}

/**
 * Função: criarSala
 * Descrição: Cria uma nova sala de forma dinâmica
 * Parâmetros: nome - string com o nome da sala
 * Retorno: ponteiro para a sala criada
 */
Sala* criarSala(char* nome) {
    Sala* novaSala = (Sala*)malloc(sizeof(Sala));
    
    if (novaSala == NULL) {
        printf("❌ Erro: Não foi possível alocar memória para a sala.\n");
        exit(1);
    }
    
    strcpy(novaSala->nome, nome);
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
        printf("❌ Erro: Não foi possível alocar memória para a pista.\n");
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
 * Parâmetros: raiz - ponteiro para a raiz da árvore BST
 *             pista - string com a pista a ser inserida
 * Retorno: ponteiro para a raiz atualizada
 */
PistaNode* inserirPista(PistaNode* raiz, char* pista) {
    if (raiz == NULL) {
        return criarPistaNode(pista);
    }
    
    int comparacao = strcmp(pista, raiz->pista);
    
    if (comparacao < 0) {
        raiz->esquerda = inserirPista(raiz->esquerda, pista);
    } else if (comparacao > 0) {
        raiz->direita = inserirPista(raiz->direita, pista);
    }
    // Se igual, não insere duplicata
    
    return raiz;
}

/**
 * Função: inserirNaHash
 * Descrição: Insere associação pista/suspeito na tabela hash
 * Parâmetros: pista - string com a pista
 *             suspeito - string com o nome do suspeito
 * Retorno: void
 */
void inserirNaHash(char* pista, char* suspeito) {
    unsigned int indice = funcaoHash(pista);
    
    HashNode* novoNode = (HashNode*)malloc(sizeof(HashNode));
    if (novoNode == NULL) {
        printf("❌ Erro: Não foi possível alocar memória para hash.\n");
        exit(1);
    }
    
    strcpy(novoNode->pista, pista);
    strcpy(novoNode->suspeito, suspeito);
    novoNode->proximo = tabelaHash[indice];
    tabelaHash[indice] = novoNode;
}

/**
 * Função: encontrarSuspeito
 * Descrição: Consulta o suspeito correspondente a uma pista na tabela hash
 * Parâmetros: pista - string com a pista para buscar
 * Retorno: ponteiro para o nome do suspeito ou NULL se não encontrado
 */
char* encontrarSuspeito(char* pista) {
    unsigned int indice = funcaoHash(pista);
    HashNode* atual = tabelaHash[indice];
    
    while (atual != NULL) {
        if (strcmp(atual->pista, pista) == 0) {
            return atual->suspeito;
        }
        atual = atual->proximo;
    }
    
    return NULL; // Pista não encontrada
}

/**
 * Função: obterPistaPorSala
 * Descrição: Retorna a pista específica associada a uma sala
 * Parâmetros: nomeSala - nome da sala para obter a pista
 * Retorno: ponteiro para a string da pista ou NULL se não houver
 */
char* obterPistaPorSala(char* nomeSala) {
    // Definição estática das pistas por sala
    if (strcmp(nomeSala, "Hall de Entrada") == 0) {
        return "Pegadas molhadas de sapatos caros";
    } else if (strcmp(nomeSala, "Biblioteca") == 0) {
        return "Livro de toxicologia com páginas marcadas";
    } else if (strcmp(nomeSala, "Laboratório") == 0) {
        return "Frasco de cianeto parcialmente vazio";
    } else if (strcmp(nomeSala, "Escritório") == 0) {
        return "Testamento alterado recentemente";
    } else if (strcmp(nomeSala, "Cozinha") == 0) {
        return "Restos de plantas venenosas no liquidificador";
    } else if (strcmp(nomeSala, "Quarto Principal") == 0) {
        return "Carta de chantagem escondida na gaveta";
    } else if (strcmp(nomeSala, "Jardim") == 0) {
        return "Ferramentas de jardinagem com traces suspeitos";
    } else if (strcmp(nomeSala, "Adega") == 0) {
        return "Garrafa de vinho adulterada";
    } else if (strcmp(nomeSala, "Cofre Secreto") == 0) {
        return "Documentos comprometedores sobre heranças";
    }
    
    return NULL; // Sala sem pista
}

/**
 * Função: exibirPistas
 * Descrição: Exibe todas as pistas coletadas em ordem alfabética
 * Parâmetros: raiz - ponteiro para a raiz da árvore BST
 *             contador - ponteiro para contador de pistas
 * Retorno: void
 */
void exibirPistas(PistaNode* raiz, int* contador) {
    if (raiz != NULL) {
        exibirPistas(raiz->esquerda, contador);
        (*contador)++;
        char* suspeito = encontrarSuspeito(raiz->pista);
        printf("  %d. %s\n", *contador, raiz->pista);
        printf("     👤 Aponta para: %s\n", suspeito ? suspeito : "Suspeito desconhecido");
        exibirPistas(raiz->direita, contador);
    }
}

/**
 * Função: contarPistasPorSuspeito
 * Descrição: Conta quantas pistas apontam para um suspeito específico
 * Parâmetros: raiz - ponteiro para a raiz da árvore BST
 *             suspeitoAlvo - nome do suspeito para contar
 * Retorno: número de pistas que apontam para o suspeito
 */
int contarPistasPorSuspeito(PistaNode* raiz, char* suspeitoAlvo) {
    if (raiz == NULL) {
        return 0;
    }
    
    int count = 0;
    char* suspeito = encontrarSuspeito(raiz->pista);
    
    if (suspeito && strcmp(suspeito, suspeitoAlvo) == 0) {
        count = 1;
    }
    
    return count + 
           contarPistasPorSuspeito(raiz->esquerda, suspeitoAlvo) +
           contarPistasPorSuspeito(raiz->direita, suspeitoAlvo);
}

/**
 * Função: explorarSalas
 * Descrição: Permite navegação pela mansão ativando o sistema de pistas
 * Parâmetros: salaAtual - ponteiro para a sala onde o jogador está
 *             pistasColetadas - ponteiro para ponteiro da árvore BST de pistas
 * Retorno: void
 */
void explorarSalas(Sala* salaAtual, PistaNode** pistasColetadas) {
    char escolha;
    
    while (salaAtual != NULL) {
        printf("\n🏰 === DETECTIVE QUEST - INVESTIGAÇÃO MESTRE ===\n");
        printf("📍 Você está na: %s\n", salaAtual->nome);
        
        // Verifica se há pista na sala atual
        char* pista = obterPistaPorSala(salaAtual->nome);
        if (pista != NULL) {
            printf("🔍 PISTA DESCOBERTA: %s\n", pista);
            *pistasColetadas = inserirPista(*pistasColetadas, pista);
            
            char* suspeito = encontrarSuspeito(pista);
            if (suspeito) {
                printf("🎯 Esta pista aponta para: %s\n", suspeito);
            }
            printf("✅ Pista adicionada ao seu dossiê!\n");
        } else {
            printf("❌ Nenhuma pista encontrada nesta sala.\n");
        }
        
        // Verifica se é uma sala sem saídas
        if (salaAtual->esquerda == NULL && salaAtual->direita == NULL) {
            printf("\n🚪 Esta sala não possui mais caminhos!\n");
            printf("💡 Você pode sair para começar a fase de julgamento.\n");
        }
        
        // Mostra as opções disponíveis
        printf("\n📋 Opções disponíveis:\n");
        if (salaAtual->esquerda != NULL) {
            printf("  (e) - Ir para esquerda: %s\n", salaAtual->esquerda->nome);
        }
        if (salaAtual->direita != NULL) {
            printf("  (d) - Ir para direita: %s\n", salaAtual->direita->nome);
        }
        printf("  (s) - Sair e iniciar julgamento\n");
        
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
                printf("\n⚖️  Iniciando fase de julgamento...\n");
                return;
                
            default:
                printf("❌ Opção inválida! Tente novamente.\n");
                break;
        }
    }
}

/**
 * Função: verificarSuspeitoFinal
 * Descrição: Conduz à fase de julgamento final verificando a acusação
 * Parâmetros: pistasColetadas - ponteiro para a raiz da árvore BST de pistas
 * Retorno: void
 */
void verificarSuspeitoFinal(PistaNode* pistasColetadas) {
    printf("\n" "==========================================\n");
    printf("⚖️  FASE DE JULGAMENTO - DETECTIVE QUEST\n");
    printf("==========================================\n");
    
    if (pistasColetadas == NULL) {
        printf("❌ Você não coletou nenhuma pista!\n");
        printf("💡 Sem evidências, é impossível fazer uma acusação.\n");
        printf("🔄 Tente explorar mais a mansão na próxima vez.\n");
        return;
    }
    
    printf("📋 DOSSIÊ COMPLETO - Pistas coletadas:\n\n");
    int contador = 0;
    exibirPistas(pistasColetadas, &contador);
    printf("\n📊 Total de pistas coletadas: %d\n", contador);
    
    printf("\n👥 SUSPEITOS DISPONÍVEIS:\n");
    for (int i = 0; i < MAX_SUSPEITOS; i++) {
        printf("  %d. %s - %s\n", i + 1, suspeitos[i].nome, suspeitos[i].descricao);
    }
    
    printf("\n🎯 Baseado nas evidências, quem você acusa?\n");
    printf("Digite o número do suspeito (1-%d): ", MAX_SUSPEITOS);
    
    int escolha;
    scanf("%d", &escolha);
    
    if (escolha < 1 || escolha > MAX_SUSPEITOS) {
        printf("❌ Número inválido! Julgamento cancelado.\n");
        return;
    }
    
    char* suspeitoAcusado = suspeitos[escolha - 1].nome;
    printf("\n⚖️  ACUSAÇÃO FORMAL: %s\n", suspeitoAcusado);
    
    // Conta pistas que apontam para o suspeito acusado
    int pistasQueApontam = contarPistasPorSuspeito(pistasColetadas, suspeitoAcusado);
    
    printf("\n📈 ANÁLISE DAS EVIDÊNCIAS:\n");
    printf("   Pistas que apontam para %s: %d\n", suspeitoAcusado, pistasQueApontam);
    printf("   Evidências necessárias para condenação: 2\n");
    
    printf("\n" "==========================================\n");
    
    if (pistasQueApontam >= 2) {
        printf("✅ VEREDICTO: CULPADO!\n");
        printf("🎉 Parabéns, Detective! Você reuniu evidências suficientes!\n");
        printf("⚖️  %s foi considerado culpado com base em %d pistas sólidas.\n", 
               suspeitoAcusado, pistasQueApontam);
        printf("🏆 Caso resolvido com sucesso!\n");
    } else {
        printf("❌ VEREDICTO: EVIDÊNCIAS INSUFICIENTES\n");
        printf("😞 Infelizmente, você não reuniu evidências suficientes.\n");
        printf("💡 São necessárias pelo menos 2 pistas para uma condenação.\n");
        printf("🔄 O suspeito foi liberado. Tente novamente!\n");
    }
    
    printf("==========================================\n");
}

/**
 * Função: inicializarTabelaHash
 * Descrição: Inicializa a tabela hash e preenche com associações pista-suspeito
 * Retorno: void
 */
void inicializarTabelaHash() {
    // Inicializa todos os ponteiros como NULL
    for (int i = 0; i < HASH_SIZE; i++) {
        tabelaHash[i] = NULL;
    }
    
    // Preenche associações pista -> suspeito
    inserirNaHash("Pegadas molhadas de sapatos caros", "Dr. Marcus");
    inserirNaHash("Livro de toxicologia com páginas marcadas", "Prof. Viktor");
    inserirNaHash("Frasco de cianeto parcialmente vazio", "Prof. Viktor");
    inserirNaHash("Testamento alterado recentemente", "Lady Catherine");
    inserirNaHash("Restos de plantas venenosas no liquidificador", "Sra. Helena");
    inserirNaHash("Carta de chantagem escondida na gaveta", "James Butler");
    inserirNaHash("Ferramentas de jardinagem com traces suspeitos", "Sra. Helena");
    inserirNaHash("Garrafa de vinho adulterada", "Dr. Marcus");
    inserirNaHash("Documentos comprometedores sobre heranças", "Lady Catherine");
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
 * Função: liberarMemoriaHash
 * Descrição: Libera a memória alocada para a tabela hash
 * Retorno: void
 */
void liberarMemoriaHash() {
    for (int i = 0; i < HASH_SIZE; i++) {
        HashNode* atual = tabelaHash[i];
        while (atual != NULL) {
            HashNode* temp = atual;
            atual = atual->proximo;
            free(temp);
        }
    }
}

/**
 * Função: main
 * Descrição: Programa principal que monta a mansão e coordena toda a investigação
 * Retorno: 0 se executado com sucesso
 */
int main() {
    printf("🎮 === DETECTIVE QUEST - NÍVEL MESTRE ===\n");
    printf("🕵️  Bem-vindo à investigação mais complexa!\n");
    printf("🎯 Objetivo: Colete pistas, analise suspeitos e resolva o caso!\n");
    printf("⚖️  Você precisará de pelo menos 2 pistas para condenar um suspeito.\n\n");
    
    // Inicializa as estruturas de dados
    inicializarTabelaHash();
    PistaNode* pistasColetadas = NULL;
    
    // Criação do mapa da mansão - estrutura mais complexa
    Sala* hall = criarSala("Hall de Entrada");
    
    // Segundo nível
    Sala* biblioteca = criarSala("Biblioteca");
    Sala* cozinha = criarSala("Cozinha");
    
    // Terceiro nível - lado esquerdo
    Sala* laboratorio = criarSala("Laboratório");
    Sala* escritorio = criarSala("Escritório");
    
    // Terceiro nível - lado direito
    Sala* quartoMain = criarSala("Quarto Principal");
    Sala* jardim = criarSala("Jardim");
    
    // Quarto nível - salas finais
    Sala* adega = criarSala("Adega");
    Sala* cofreSecreto = criarSala("Cofre Secreto");
    
    // Montagem da estrutura da árvore
    hall->esquerda = biblioteca;
    hall->direita = cozinha;
    
    biblioteca->esquerda = laboratorio;
    biblioteca->direita = escritorio;
    
    cozinha->esquerda = quartoMain;
    cozinha->direita = jardim;
    
    escritorio->direita = adega;
    jardim->direita = cofreSecreto;
    
    printf("🏰 Mansão do mistério criada com sucesso!\n");
    printf("🗺️  Estrutura da mansão:\n");
    printf("                    Hall de Entrada\n");
    printf("                   /              \\\n");
    printf("              Biblioteca        Cozinha\n");
    printf("              /       \\        /      \\\n");
    printf("       Laboratório  Escritório Quarto  Jardim\n");
    printf("                        \\      Principal   \\\n");
    printf("                       Adega            Cofre Secreto\n");
    
    printf("\n🔍 A mansão está cheia de pistas. Explore com cuidado!\n");
    printf("🎯 Lembre-se: você precisa de evidências sólidas para o julgamento.\n");
    
    // Inicia a exploração
    explorarSalas(hall, &pistasColetadas);
    
    // Fase de julgamento
    verificarSuspeitoFinal(pistasColetadas);
    
    // Libera toda a memória alocada
    liberarMemoriaSalas(hall);
    liberarMemoriaPistas(pistasColetadas);
    liberarMemoriaHash();
    
    printf("\n🎮 Obrigado por jogar Detective Quest - Nível Mestre!\n");
    printf("🎓 Você dominou: Árvores Binárias, BST e Tabelas Hash!\n");
    
    return 0;
}
