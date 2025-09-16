# DEEPSEEK. Código fonte: algoritmo para compilação e execução. Versão do modelo: DeepSeek-V3. Disponível em: https://chat.deepseek.com/ 

CC = gcc
CFLAGS = -Iinclude -Wall -c
SRC = main.c $(wildcard modulos/*.c)
OBJ = $(SRC:.c=.o)
OUT = programa.exe

all: $(OBJ)
	$(CC) $(OBJ) -o $(OUT)

%.o: %.c
	$(CC) $(CFLAGS) $< -o $@

run: all
	./$(OUT)

clean:
	rm -f $(OBJ) $(OUT)