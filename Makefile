objects = lexi.o sentence_t.o
OUTPUT = lexi
COMPILER = clang

all: lex run

lex: $(objects)
	$(COMPILER) $(objects) -o $(OUTPUT)
lexi.o: lexi.c
	$(COMPILER) -c lexi.c
sentence_t.o: src/sentence_t.c includes/sentence_t.h
	$(COMPILER) -c src/sentence_t.c
run:
	./$(OUTPUT)
clean: clean_objects
	rm $(OUTPUT)
clean_objects:
	rm $(objects)
