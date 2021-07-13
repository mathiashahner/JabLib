PATH_BUILD   = ./build
PATH_INCLUDE = ./include
PATH_SOURCE  = ./src
PATH_TEST    = ./test
PATH_OBJECT  = $(PATH_BUILD)/obj
PATH_LIBRARY = $(PATH_BUILD)/JabLib.a

MAKE_BUILD_PATH = mkdir $(PATH_BUILD) $(PATH_OBJECT)
FLAGS = -O3 -Wall

all: path obj bin

clean:
	rm -rf $(PATH_BUILD)
	$(MAKE_BUILD_PATH)

run:
	$(PATH_BUILD)/JabLibTest

path:
	if [ ! -d $(PATH_BUILD) ]; then $(MAKE_BUILD_PATH); fi

obj: $(PATH_OBJECT)/JabStdFunctions.o \
	$(PATH_OBJECT)/JabMath.o
	ar -rcs $(PATH_LIBRARY) $(PATH_OBJECT)/*.o

bin: $(PATH_BUILD)/JabLibTest

$(PATH_OBJECT)/%.o: $(PATH_SOURCE)/%.cpp $(PATH_INCLUDE)/%.h
	gcc $(FLAGS) -c $< -I $(PATH_INCLUDE) -o $@

$(PATH_BUILD)/%: $(PATH_TEST)/%.cpp
	gcc $(FLAGS) $< $(PATH_LIBRARY) -I $(PATH_INCLUDE) -o $@