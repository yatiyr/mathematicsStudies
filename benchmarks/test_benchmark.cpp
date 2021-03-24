#include <benchmark.h>
#include <vector>
#include <cstdlib>
#include <numeric>
#include <vector>

static void test_vector_addition(benchmark::State &s)
{
    auto N = 1 << 10;

    std::vector<int> v(N);
    std::generate(begin(v), end(v), [] {return rand() % 100;});

    int result = 0;

    for(auto _ : s)
    {
        benchmark::DoNotOptimize(result = std::accumulate(begin(v), end(v), 0));
    }
}

BENCHMARK(test_vector_addition);

BENCHMARK_MAIN();

