CXX = g++
INCLUDE = include
CXXFLAGS = -Wall -g -I $(INCLUDE)
BIN = bin
BUILD = build
SRC = src

sifo: $(BUILD)/simple_image.o $(BUILD)/main.o | bin
	$(CXX) $(CXXFLAGS) $(BUILD)/simple_image.o $(BUILD)/main.o -o $(BIN)/$@

$(BUILD)/simple_image.o: $(SRC)/simple_image.cpp $(INCLUDE)/sifo/simple_image.h | build
	$(CXX) -c $(SRC)/simple_image.cpp -o $@ -I $(INCLUDE)

$(BUILD)/main.o: $(SRC)/main.cpp | build
	$(CXX) -c $(SRC)/main.cpp -o $@ -I $(INCLUDE)

.PHONY:
	clean

bin:
	mkdir $@

build:
	mkdir $@

clean:
	rm -rf build bin
