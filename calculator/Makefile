.PHONY: all debug release clean

RELEASE_FLAGS = -O2 -Wall -DNDEBUG
DEBUG_FLAGS = -g -O0 -Wall
RELEASE_EXEC = pract_2
DEBUG_EXEC = pract_2-dbg
SOURCE = pract_2.cpp

all: debug release

debug: $(DEBUG_EXEC)

$(DEBUG_EXEC): pract_2.cpp
    g++ $(DEBUG_FLAGS) pract_2.cpp -o $(DEBUG_EXEC)

release: $(RELEASE_EXEC)

$(RELEASE_EXEC): pract_2.cpp
    g++ $(RELEASE_FLAGS) pract_2.cpp -o $(RELEASE_EXEC)

clean:
    rm -f $(RELEASE_EXEC) $(DEBUG_EXEC)

