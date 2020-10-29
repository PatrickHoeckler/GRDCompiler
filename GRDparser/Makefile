###This make file was intended for use with nmake

#compiler
CC = cl

#executable name
EXE = GRDparser

#include directory
SRC_DIR = src
OBJ_DIR = obj
INCLUDE_DIR = include

#source files
SRC = $(SRC_DIR)/*.c \
	$(SRC_DIR)/GRDlexer/*.c \
	$(SRC_DIR)/GRDparser/*.c \

#flags
CFLAGS = /W4 /D_CRT_SECURE_NO_WARNINGS /nologo 
LFLAGS = /nologo

.PHONY: all

all: $(EXE)

$(EXE): $(OBJ_DIR)/*.obj
	$(CC) $(LFLAGS) $? /Fe: $@.exe

$(OBJ_DIR)/*.obj:
	$(CC) $(CFLAGS) /I$(INCLUDE_DIR) /c $(SRC) /Fo: $(OBJ_DIR)/

clean:
	del $(OBJ_DIR)\*.obj $(EXE).exe