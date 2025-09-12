CC = gcc
CFLAGS = -Iinclude -Wall -c

# Arquivos do projeto
SRC = main.c $(wildcard Modulos/*.c)
OBJ = $(SRC:.c=.o)
OUT = programa.exe

# Regra padrão
all: $(OBJ)
	$(CC) $(OBJ) -o $(OUT)

# Regra genérica para compilar .c para .o
%.o: %.c
	$(CC) $(CFLAGS) $< -o $@

# Atalho para compilar e rodar
run: all
	./$(OUT)

# Limpa os objetos e executável
clean:
	rm -f $(OBJ) $(OUT)