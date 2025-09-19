# Makefile para compilar o jogo Detective Quest - Nível Mestre
# Compilador
CC = gcc

# Flags de compilação
CFLAGS = -Wall -Wextra -std=c99 -g

# Nome do executável
TARGET = detective_quest_mestre

# Arquivo fonte
SOURCES = detective_quest_mestre.c

# Regra padrão
all: $(TARGET)

# Regra para criar o executável
$(TARGET): $(SOURCES)
	$(CC) $(CFLAGS) -o $(TARGET) $(SOURCES)

# Regra para executar o programa
run: $(TARGET)
	./$(TARGET)

# Regra para compilar e executar com informações
test: $(TARGET)
	@echo "================================================="
	@echo "🎮 Detective Quest - Nível Mestre"
	@echo "================================================="
	@echo "✅ Compilação concluída com sucesso!"
	@echo ""
	@echo "🎯 Funcionalidades implementadas:"
	@echo "   • Árvore Binária para navegação"
	@echo "   • BST para organização de pistas"
	@echo "   • Tabela Hash para suspeitos"
	@echo "   • Sistema de julgamento inteligente"
	@echo ""
	@echo "⚖️  Iniciando investigação..."
	@echo "================================================="
	@echo ""
	./$(TARGET)

# Regra para demonstração rápida
demo: $(TARGET)
	@echo "🕵️  DEMONSTRAÇÃO - DETECTIVE QUEST MESTRE"
	@echo "=========================================="
	@echo "Este é o nível mais avançado do Detective Quest!"
	@echo ""
	@echo "📊 Estruturas de dados utilizadas:"
	@echo "   1. Árvore Binária - Mapa da mansão"
	@echo "   2. BST - Organização de pistas"
	@echo "   3. Tabela Hash - Associação pista-suspeito"
	@echo ""
	@echo "🎯 Objetivo: Coletar evidências e resolver o caso!"
	@echo "=========================================="

# Regra para verificar estruturas de dados
check-structures:
	@echo "🔍 VERIFICAÇÃO DAS ESTRUTURAS DE DADOS"
	@echo "======================================"
	@echo ""
	@echo "1. 🌳 ÁRVORE BINÁRIA (Mapa da Mansão):"
	@echo "   • Navegação hierarchical"
	@echo "   • Cada nó = sala da mansão"
	@echo "   • Exploração por escolhas esquerda/direita"
	@echo ""
	@echo "2. 🔄 BST (Pistas Coletadas):"
	@echo "   • Ordenação automática alfabética"
	@echo "   • Inserção O(log n) no melhor caso"
	@echo "   • Percurso in-order para exibição"
	@echo ""
	@echo "3. #️⃣ TABELA HASH (Pista → Suspeito):"
	@echo "   • Associação eficiente O(1)"
	@echo "   • Hash function: djb2 algorithm"
	@echo "   • Resolução de colisões por encadeamento"
	@echo ""
	@echo "4. ⚖️  ALGORITMO DE JULGAMENTO:"
	@echo "   • Contagem recursiva de evidências"
	@echo "   • Verificação de threshold (≥2 pistas)"
	@echo "   • Decisão automática baseada em dados"

# Regra para limpar arquivos gerados
clean:
	rm -f $(TARGET)

# Regra para mostrar ajuda completa
help:
	@echo "🎮 Detective Quest - Nível Mestre"
	@echo "================================="
	@echo ""
	@echo "📋 Comandos disponíveis:"
	@echo "  make              - Compila o programa"
	@echo "  make run          - Compila e executa"
	@echo "  make test         - Executa com informações detalhadas"
	@echo "  make demo         - Mostra demonstração das funcionalidades"
	@echo "  make check-structures - Explica as estruturas de dados"
	@echo "  make clean        - Remove arquivos gerados"
	@echo "  make help         - Mostra esta ajuda"
	@echo ""
	@echo "🎯 Características do Nível Mestre:"
	@echo "  • Combina 3 estruturas de dados principais"
	@echo "  • Sistema de investigação completo"
	@echo "  • Algoritmo de julgamento inteligente"
	@echo "  • Interface avançada com feedback detalhado"
	@echo ""
	@echo "📚 Conceitos educacionais:"
	@echo "  • Árvores Binárias e BST"
	@echo "  • Tabelas Hash com função de hash"
	@echo "  • Algoritmos de busca e contagem"
	@echo "  • Gerenciamento de memória complexo"
	@echo "  • Modularização avançada"

.PHONY: all run test demo check-structures clean help
