objects = lex.o count_words.o
OUTPUT = lex
COMPILER = clang

all: lex run

lex: $(objects)
	$(COMPILER) $(objects) -o $(OUTPUT)
lex.o: lex.c
	$(COMPILER) -c lex.c
count_words.o: src/count_words.c includes/count_words.h
	$(COMPILER) -c src/count_words.c
run:
	./$(OUTPUT)
clean: clean_objects
	rm $(OUTPUT)
clean_objects:
	rm $(objects)
