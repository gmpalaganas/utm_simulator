CC = g++
INCLUDES = -Isrc/turing_machine -Isrc/utils
CFLAGS = -std=c++14
RM = rm -r
MKDIR = mkdir -p

VPATH = src/utils src/turing_machine
BUILDDIR = build/utils build/turing_machine
OBJS = build/main.o \
	   build/utils/string_utils.o \
	   build/turing_machine/turing_machine.o 

all: directories bin/tm_sim samples
	@echo Done

bin/tm_sim: $(OBJS)
	@echo Building $@
	@$(CC) $(CFLAGS) $(INCLUDES) $^ -o $@

build/main.o: src/main.cpp
	@echo Building $@
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@ 

build/turing_machine/turing_machine.o: src/turing_machine/turing_machine.cpp
	@echo Building $@
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@ 

build/utils/string_utils.o: src/utils/string_utils.cpp
	@echo Building $@
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@ 

directories:
	@echo Making build directories
	@$(MKDIR) $(BUILDDIR)

samples:
	@echo Copying sample files
	@cp src/samples/ bin/ -r

clean:
	@echo Cleaning up
	@$(RM) build/*.o build/**/*.o
	@$(RM) bin/* bin/**/*
