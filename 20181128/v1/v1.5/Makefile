INC_DIR:= ./
SRC_DIR:= ./
SRCS:=$(wildcard *.cc)
OBJS:=$(patsubst %.cc ,%.o ,$(SRCS))
LIBS:= -llog4cpp -lpthread

CXX:= g++

CXXFLAGS:= -w -g -std=c++11 $(addprefix -I, $(INC_DIR)) $(LIBS)

EXE:=./test.exe

$(EXE):$(OBJS)
	$(CXX) -o $(EXE) $(OBJS) $(CXXFLAGS)
	rm -rf $(OBJS)
clean;
	rm -rf $(EXE)

