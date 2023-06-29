# Configurações do Makefile
CC := gcc
CFLAGS := -std=c99
TARGET := main

# Comando padrão ao executar make
all: $(TARGET)

# Regra para compilar o programa
$(TARGET): main.c
	$(CC) $(CFLAGS) -o $@ $<

# Regra para executar o programa
run: $(TARGET)
	./$(TARGET)

# Regra para limpar os arquivos gerados
clean:
	rm -f $(TARGET)

# Regra para compactar os arquivos em um zip
zip:
	zip marketsystem.zip main.c Makefile

# Define as regras que não são arquivos
.PHONY: all run clean zip
