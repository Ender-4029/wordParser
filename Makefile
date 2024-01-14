CC = gcc
CXX = g++
CFLAGS = -o3
CXXFLAGS = --std=c++20 -o3
CSRC = $(wildcard src/*.c)
CPPSRC = $(wildcard src/*.cpp)

runTests: buildc buildcpp
	@echo "Running analyzeWordsC..."
	@bash -c 'time ./bin/analyzeWordsC'
	@echo "Running analyzeWordsCPP..."
	@bash -c 'time ./bin/analyzeWordsCPP'

buildc: 
	$(CC) $(CFLAGS) -o bin/analyzeWordsC $(CSRC)
buildcpp: 
	$(CXX) $(CXXFLAGS) -o bin/analyzeWordsCPP $(CPPSRC)