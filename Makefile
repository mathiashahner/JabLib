PATH_SOURCE  = ./src
PATH_BUILD   = ./build
PATH_OBJECT  = $(PATH_BUILD)/obj
PATH_LIBRARY = $(PATH_BUILD)/MazeBuilder.a

PATH_INCLUDE = -I./include

COMP_CPP  = g++
DEFINES   = 
LIBRARIES = -lSDL2main -lSDL2
FLAGS_CPP = -O3 -Wno-format -Wno-stringop-overflow
FLAGS_LIB = ar -rcs

MAKE_BUILD_PATH = mkdir $(PATH_BUILD) $(PATH_OBJECT)

all: path obj bin

clean:
	rm -rf $(PATH_BUILD)
	$(MAKE_BUILD_PATH)

run:
	$(PATH_BUILD)/MazeBuilder

path:
	if [ ! -d $(PATH_BUILD) ]; then $(MAKE_BUILD_PATH); fi

obj: $(PATH_OBJECT)/main.o \
	$(PATH_OBJECT)/game.o \
	$(PATH_OBJECT)/maze.o \
	$(PATH_OBJECT)/rect.o \
	$(PATH_OBJECT)/line.o
	$(FLAGS_LIB) $(PATH_LIBRARY) $(PATH_OBJECT)/*.o

bin: $(PATH_BUILD)/MazeBuilder

$(PATH_OBJECT)/%.o: $(PATH_SOURCE)/%.cpp
	$(COMP_CPP) $(FLAGS_CPP) -c $< $(DEFINES) $(PATH_INCLUDE) -o $@

$(PATH_BUILD)/%: $(PATH_SOURCE)/main.cpp
	$(COMP_CPP) $(FLAGS_CPP) $< $(DEFINES) $(PATH_LIBRARY) $(PATH_INCLUDE) $(LIBRARIES) -o $@
