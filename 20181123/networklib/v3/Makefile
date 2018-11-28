lNC_DIR:= ./
SRC_DIR:= ./
SRCS:=$(wildcard *.cc)
OBJS:=$(patsubst %.cc ,%.o, $(SRCS))

LIBS:= -lpthread

CXX:= g++

CXXFLAGS:= -g -w -std=c++11 $(addprefix -I,$(INC_DIR)) $(LIBS) -Wno-deprecated

EXE:= ./server.exe

$(EXE):$(OBJS)
	$(CXX) -o $(EXE) $(OBJS) $(CXXFLAGS)
	rm -rf $(OBJS)
clean:
	rm -rf $(EXE)
