PATH_BUILD   = ./build
PATH_SOURCE  = ./source
PATH_TEST    = ./test
PATH_OBJECT  = $(PATH_BUILD)/obj
PATH_LIBRARY = $(PATH_BUILD)/JabLib.a

COMP_C    = gcc
COMP_CC   = g++

FLAGS_C   = -O3 -Wall
FLAGS_CC  = -O3 -Wall
FLAGS_LIB = ar -rcs

COMP_DEFINES    = 
MAKE_BUILD_PATH = mkdir $(PATH_BUILD) $(PATH_OBJECT)

PATH_INCLUDE  = -I./include
PATH_INCLUDE += -I$(PATH_TEST)

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
	$(FLAGS_LIB) $(PATH_LIBRARY) $(PATH_OBJECT)/*.o

bin: $(PATH_BUILD)/JabLibTest

$(PATH_OBJECT)/%.o: $(PATH_SOURCE)/%.cpp
	$(COMP_CC) $(FLAGS_CC) -c $< $(COMP_DEFINES) $(PATH_INCLUDE) -o $@

$(PATH_BUILD)/%: $(PATH_TEST)/%.cpp
	$(COMP_CC) $(FLAGS_CC) $< $(COMP_DEFINES) $(PATH_LIBRARY) $(PATH_INCLUDE) -o $@