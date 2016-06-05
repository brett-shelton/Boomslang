#------------------------------------------------------------------------------#
# This makefile was generated by 'cbp2make' tool rev.147                       #
#------------------------------------------------------------------------------#


WORKDIR = %cd%

CC = gcc.exe
CXX = g++.exe
AR = ar.exe
LD = g++.exe
WINDRES = windres.exe

INC = 
CFLAGS = -std=c++11 -Wall -fexceptions
RESINC = 
LIBDIR = 
LIB = 
LDFLAGS = 

INC_DEBUG = $(INC)
CFLAGS_DEBUG = $(CFLAGS) -g
RESINC_DEBUG = $(RESINC)
RCFLAGS_DEBUG = $(RCFLAGS)
LIBDIR_DEBUG = $(LIBDIR)
LIB_DEBUG = $(LIB)
LDFLAGS_DEBUG = $(LDFLAGS)
OBJDIR_DEBUG = obj\\Debug
DEP_DEBUG = 
OUT_DEBUG = bin\\Debug\\BoomslangCompiler.exe

INC_RELEASE = $(INC)
CFLAGS_RELEASE = $(CFLAGS) -O3
RESINC_RELEASE = $(RESINC)
RCFLAGS_RELEASE = $(RCFLAGS)
LIBDIR_RELEASE = $(LIBDIR)
LIB_RELEASE = $(LIB)
LDFLAGS_RELEASE = $(LDFLAGS) -s
OBJDIR_RELEASE = obj\\Release
DEP_RELEASE = 
OUT_RELEASE = bin\\Release\\BoomslangCompiler.exe

OBJ_DEBUG = $(OBJDIR_DEBUG)\\source\\token.o $(OBJDIR_DEBUG)\\source\\scope.o $(OBJDIR_DEBUG)\\source\\run.o $(OBJDIR_DEBUG)\\source\\options.o $(OBJDIR_DEBUG)\\source\\management.o $(OBJDIR_DEBUG)\\source\\main.o $(OBJDIR_DEBUG)\\source\\log.o $(OBJDIR_DEBUG)\\source\\locate.o $(OBJDIR_DEBUG)\\source\\lexer.o $(OBJDIR_DEBUG)\\source\\file.o $(OBJDIR_DEBUG)\\source\\errors.o $(OBJDIR_DEBUG)\\source\\enforcer.o $(OBJDIR_DEBUG)\\source\\die.o $(OBJDIR_DEBUG)\\source\\core.o $(OBJDIR_DEBUG)\\source\\context.o $(OBJDIR_DEBUG)\\source\\assembler.o

OBJ_RELEASE = $(OBJDIR_RELEASE)\\source\\token.o $(OBJDIR_RELEASE)\\source\\scope.o $(OBJDIR_RELEASE)\\source\\run.o $(OBJDIR_RELEASE)\\source\\options.o $(OBJDIR_RELEASE)\\source\\management.o $(OBJDIR_RELEASE)\\source\\main.o $(OBJDIR_RELEASE)\\source\\log.o $(OBJDIR_RELEASE)\\source\\locate.o $(OBJDIR_RELEASE)\\source\\lexer.o $(OBJDIR_RELEASE)\\source\\file.o $(OBJDIR_RELEASE)\\source\\errors.o $(OBJDIR_RELEASE)\\source\\enforcer.o $(OBJDIR_RELEASE)\\source\\die.o $(OBJDIR_RELEASE)\\source\\core.o $(OBJDIR_RELEASE)\\source\\context.o $(OBJDIR_RELEASE)\\source\\assembler.o

all: debug release

clean: clean_debug clean_release

before_debug: 
	cmd /c if not exist bin\\Debug md bin\\Debug
	cmd /c if not exist $(OBJDIR_DEBUG)\\source md $(OBJDIR_DEBUG)\\source

after_debug: 

debug: before_debug out_debug after_debug

out_debug: before_debug $(OBJ_DEBUG) $(DEP_DEBUG)
	$(LD) $(LIBDIR_DEBUG) -o $(OUT_DEBUG) $(OBJ_DEBUG)  $(LDFLAGS_DEBUG) $(LIB_DEBUG)

$(OBJDIR_DEBUG)\\source\\token.o: source\\token.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c source\\token.cpp -o $(OBJDIR_DEBUG)\\source\\token.o

$(OBJDIR_DEBUG)\\source\\scope.o: source\\scope.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c source\\scope.cpp -o $(OBJDIR_DEBUG)\\source\\scope.o

$(OBJDIR_DEBUG)\\source\\run.o: source\\run.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c source\\run.cpp -o $(OBJDIR_DEBUG)\\source\\run.o

$(OBJDIR_DEBUG)\\source\\options.o: source\\options.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c source\\options.cpp -o $(OBJDIR_DEBUG)\\source\\options.o

$(OBJDIR_DEBUG)\\source\\management.o: source\\management.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c source\\management.cpp -o $(OBJDIR_DEBUG)\\source\\management.o

$(OBJDIR_DEBUG)\\source\\main.o: source\\main.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c source\\main.cpp -o $(OBJDIR_DEBUG)\\source\\main.o

$(OBJDIR_DEBUG)\\source\\log.o: source\\log.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c source\\log.cpp -o $(OBJDIR_DEBUG)\\source\\log.o

$(OBJDIR_DEBUG)\\source\\locate.o: source\\locate.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c source\\locate.cpp -o $(OBJDIR_DEBUG)\\source\\locate.o

$(OBJDIR_DEBUG)\\source\\lexer.o: source\\lexer.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c source\\lexer.cpp -o $(OBJDIR_DEBUG)\\source\\lexer.o

$(OBJDIR_DEBUG)\\source\\file.o: source\\file.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c source\\file.cpp -o $(OBJDIR_DEBUG)\\source\\file.o

$(OBJDIR_DEBUG)\\source\\errors.o: source\\errors.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c source\\errors.cpp -o $(OBJDIR_DEBUG)\\source\\errors.o

$(OBJDIR_DEBUG)\\source\\enforcer.o: source\\enforcer.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c source\\enforcer.cpp -o $(OBJDIR_DEBUG)\\source\\enforcer.o

$(OBJDIR_DEBUG)\\source\\die.o: source\\die.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c source\\die.cpp -o $(OBJDIR_DEBUG)\\source\\die.o

$(OBJDIR_DEBUG)\\source\\core.o: source\\core.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c source\\core.cpp -o $(OBJDIR_DEBUG)\\source\\core.o

$(OBJDIR_DEBUG)\\source\\context.o: source\\context.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c source\\context.cpp -o $(OBJDIR_DEBUG)\\source\\context.o

$(OBJDIR_DEBUG)\\source\\assembler.o: source\\assembler.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c source\\assembler.cpp -o $(OBJDIR_DEBUG)\\source\\assembler.o

clean_debug: 
	cmd /c del /f $(OBJ_DEBUG) $(OUT_DEBUG)
	cmd /c rd bin\\Debug
	cmd /c rd $(OBJDIR_DEBUG)\\source

before_release: 
	cmd /c if not exist bin\\Release md bin\\Release
	cmd /c if not exist $(OBJDIR_RELEASE)\\source md $(OBJDIR_RELEASE)\\source

after_release: 

release: before_release out_release after_release

out_release: before_release $(OBJ_RELEASE) $(DEP_RELEASE)
	$(LD) $(LIBDIR_RELEASE) -o $(OUT_RELEASE) $(OBJ_RELEASE)  $(LDFLAGS_RELEASE) $(LIB_RELEASE)

$(OBJDIR_RELEASE)\\source\\token.o: source\\token.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c source\\token.cpp -o $(OBJDIR_RELEASE)\\source\\token.o

$(OBJDIR_RELEASE)\\source\\scope.o: source\\scope.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c source\\scope.cpp -o $(OBJDIR_RELEASE)\\source\\scope.o

$(OBJDIR_RELEASE)\\source\\run.o: source\\run.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c source\\run.cpp -o $(OBJDIR_RELEASE)\\source\\run.o

$(OBJDIR_RELEASE)\\source\\options.o: source\\options.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c source\\options.cpp -o $(OBJDIR_RELEASE)\\source\\options.o

$(OBJDIR_RELEASE)\\source\\management.o: source\\management.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c source\\management.cpp -o $(OBJDIR_RELEASE)\\source\\management.o

$(OBJDIR_RELEASE)\\source\\main.o: source\\main.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c source\\main.cpp -o $(OBJDIR_RELEASE)\\source\\main.o

$(OBJDIR_RELEASE)\\source\\log.o: source\\log.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c source\\log.cpp -o $(OBJDIR_RELEASE)\\source\\log.o

$(OBJDIR_RELEASE)\\source\\locate.o: source\\locate.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c source\\locate.cpp -o $(OBJDIR_RELEASE)\\source\\locate.o

$(OBJDIR_RELEASE)\\source\\lexer.o: source\\lexer.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c source\\lexer.cpp -o $(OBJDIR_RELEASE)\\source\\lexer.o

$(OBJDIR_RELEASE)\\source\\file.o: source\\file.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c source\\file.cpp -o $(OBJDIR_RELEASE)\\source\\file.o

$(OBJDIR_RELEASE)\\source\\errors.o: source\\errors.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c source\\errors.cpp -o $(OBJDIR_RELEASE)\\source\\errors.o

$(OBJDIR_RELEASE)\\source\\enforcer.o: source\\enforcer.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c source\\enforcer.cpp -o $(OBJDIR_RELEASE)\\source\\enforcer.o

$(OBJDIR_RELEASE)\\source\\die.o: source\\die.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c source\\die.cpp -o $(OBJDIR_RELEASE)\\source\\die.o

$(OBJDIR_RELEASE)\\source\\core.o: source\\core.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c source\\core.cpp -o $(OBJDIR_RELEASE)\\source\\core.o

$(OBJDIR_RELEASE)\\source\\context.o: source\\context.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c source\\context.cpp -o $(OBJDIR_RELEASE)\\source\\context.o

$(OBJDIR_RELEASE)\\source\\assembler.o: source\\assembler.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c source\\assembler.cpp -o $(OBJDIR_RELEASE)\\source\\assembler.o

clean_release: 
	cmd /c del /f $(OBJ_RELEASE) $(OUT_RELEASE)
	cmd /c rd bin\\Release
	cmd /c rd $(OBJDIR_RELEASE)\\source

.PHONY: before_debug after_debug clean_debug before_release after_release clean_release

