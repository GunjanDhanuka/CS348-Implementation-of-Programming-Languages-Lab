CC = gcc
LEX = lex
RM = rm -f
TARGET_LEX = lexical.l
LEX_C = lex.yy.c
MAIN = main.c

EXEC = a.out

$(EXEC): $(LEX_C)
	$(CC) $(LEX_C) $(MAIN)

$(LEX_C): $(TARGET_LEX)
	$(LEX) $(TARGET_LEX)

clean:
	$(RM) $(LEX_C) $(EXEC)

run: $(EXEC)
	./$(EXEC) && ./$(EXEC) > output.txt