
# C++ compiler
CPP=g++ -w -g -fPIC
SHARED=-shared
PTHREAD=-lpthread

# shell command
COPY=cp
DEL=rm -f

# run path
LIB=.
BIN=.

# make
SRC=$^
TARGET=$@
OUT=-o $(BIN)/$(TARGET)
OUTSO=-o $(LIB)/$(TARGET)


all: stuinfo

stuinfo: stuinfo.cpp
	$(CPP) $(SRC) $(OUT) 

