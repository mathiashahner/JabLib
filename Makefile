BUILD   = ./build
INCLUDE = ./include
SRC     = ./src
TEST    = ./test
OBJ     = $(BUILD)/obj
LIB     = $(BUILD)/JabLib.a

FLAGS = -O3 -Wall
MAKE_BUILD_PATH = mkdir $(BUILD) $(OBJ)

all: path obj bin

clean:
	rm -rf $(BUILD)
	$(MAKE_BUILD_PATH)

run:
	$(BUILD)/JabLibTest

path:
	if [ ! -d $(BUILD) ]; then $(MAKE_BUILD_PATH); fi

obj: $(OBJ)/JabStdFunctions.o
	ar -rcs $(LIB) $(OBJ)/*.o

bin: $(BUILD)/JabLibTest

$(OBJ)/%.o: $(SRC)/%.cpp $(INCLUDE)/%.h
	gcc $(FLAGS) -c $< -I $(INCLUDE) -o $@

$(BUILD)/%: $(TEST)/%.cpp
	gcc $(FLAGS) $< $(LIB) -I $(INCLUDE) -o $@