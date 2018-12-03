lNC_DIR:= ./
SRC_DIR:= ./
SRCS:=$(wildcard *.cc)
OBJS:=$(patsubst %.cc, %.o,$(SRCS))  # %.cc 后面不能有空格

LIBS:= -lpthread

CXX:= g++

CXXFLAGS:= -g -w -std=c++11 $(addprefix -I,$(INC_DIR)) $(LIBS) -Wno-deprecated

EXE:= ./a.outserver.exe

#target:
#	@echo $(OBJS)

$(EXE):$(OBJS)
	$(CXX) -o $(EXE) $(OBJS) $(CXXFLAGS)
clean:
	rm -rf $(EXE)
	rm -rf $(OBJS)
