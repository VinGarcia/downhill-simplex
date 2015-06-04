
MAIN=demo

all: build

build: $(MAIN).cpp
	g++ -Wall $(MAIN).cpp -o $(MAIN)

run: build
	./$(MAIN)

clean:
	rm $(MAIN)
