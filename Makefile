BUILD   = ./build
INCLUDE = ./include
SRC     = ./src
TEST    = ./test
OBJ     = $(BUILD)/obj
LIB     = $(BUILD)/JabLib.a

FLAGS   = -O3 -Wall

all: obj bin

obj: $(OBJ)/JabStdFunctions.o
	ar -rcs $(LIB) $(OBJ)/*.o

bin: $(BUILD)/JabLibTest

$(OBJ)/%.o: $(SRC)/%.cpp $(INCLUDE)/%.h
	gcc $(FLAGS) -c $< -I $(INCLUDE) -o $@

$(BUILD)/%: $(TEST)/%.cpp
	gcc $(FLAGS) $< $(LIB) -I $(INCLUDE) -o $@

run:
	$(BUILD)/JabLibTest

clean:
	rm -rf $(BUILD)
	mkdir $(BUILD) $(OBJ)