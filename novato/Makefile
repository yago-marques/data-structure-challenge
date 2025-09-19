# Makefile para compilar o jogo Detective Quest
# Compilador
CC = gcc

# Flags de compilação
CFLAGS = -Wall -Wextra -std=c99 -g

# Nome do executável
TARGET = detective_quest

# Arquivo fonte
SOURCES = detective_quest.c

# Regra padrão
all: $(TARGET)

# Regra para criar o executável
$(TARGET): $(SOURCES)
	$(CC) $(CFLAGS) -o $(TARGET) $(SOURCES)

# Regra para executar o programa
run: $(TARGET)
	./$(TARGET)

# Regra para limpar arquivos gerados
clean:
	rm -f $(TARGET)

# Regra para mostrar ajuda
help:
	@echo "Opções disponíveis:"
	@echo "  make        - Compila o programa"
	@echo "  make run    - Compila e executa o programa"
	@echo "  make clean  - Remove arquivos gerados"
	@echo "  make help   - Mostra esta ajuda"

.PHONY: all run clean help
