CC = gcc
LEX = lex
RM = rm -f

TARGET_LEX = A3_group.l
LEX_C = lex.yy.c
MAIN = A3_group.c

EXEC = a.out
TEST = A3_group.nc
OUTPUT = output.txt

$(EXEC): $(LEX_C)
	$(CC) $(LEX_C) $(MAIN)

$(LEX_C): $(TARGET_LEX)
	$(LEX) $(TARGET_LEX)

clean:
	$(RM) $(LEX_C) $(EXEC) $(OUTPUT)

run: $(EXEC)
	./$(EXEC) $(TEST) && ./$(EXEC) $(TEST) > $(OUTPUT)