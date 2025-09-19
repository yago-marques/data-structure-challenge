# Makefile para compilar o jogo Detective Quest - Versão Aventureiro
# Compilador
CC = gcc

# Flags de compilação
CFLAGS = -Wall -Wextra -std=c99 -g

# Nome do executável
TARGET = detective_quest_pistas

# Arquivo fonte
SOURCES = detective_quest_pistas.c

# Regra padrão
all: $(TARGET)

# Regra para criar o executável
$(TARGET): $(SOURCES)
	$(CC) $(CFLAGS) -o $(TARGET) $(SOURCES)

# Regra para executar o programa
run: $(TARGET)
	./$(TARGET)

# Regra para compilar e executar
test: $(TARGET)
	@echo "=== Compilação concluída com sucesso! ==="
	@echo "=== Executando Detective Quest - Versão Aventureiro ==="
	@echo ""
	./$(TARGET)

# Regra para limpar arquivos gerados
clean:
	rm -f $(TARGET)

# Regra para mostrar ajuda
help:
	@echo "Detective Quest - Versão Aventureiro"
	@echo "===================================="
	@echo "Opções disponíveis:"
	@echo "  make        - Compila o programa"
	@echo "  make run    - Compila e executa o programa"
	@echo "  make test   - Compila, executa e mostra informações"
	@echo "  make clean  - Remove arquivos gerados"
	@echo "  make help   - Mostra esta ajuda"
	@echo ""
	@echo "Características do nível aventureiro:"
	@echo "  • Árvore binária para mapa da mansão"
	@echo "  • Árvore BST para organizar pistas"
	@echo "  • Coleta automática de pistas"
	@echo "  • Exibição ordenada alfabeticamente"

.PHONY: all run test clean help
