CXXFLAGS = -std=c++2b -O2 -Wall
GXX = g++

%: %.cc
	@${GXX} $^ ${CXXFLAGS} -o ./$@
	@find . -name "*$@*"