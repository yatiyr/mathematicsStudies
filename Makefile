CXX = g++
INCLUDE = -I./thirdparty/googleBenchmark/include
LIB  = -L./thirdparty/googleBenchmark/libs
FLAGS = -std=c++11 -lbenchmark -lpthread -O3 -o build/benchmark
SOURCE = ./src/benchmarks/test_benchmark.cpp

all:
	$(CXX) $(SOURCE) $(FLAGS) $(INCLUDE) $(LIB)