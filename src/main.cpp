#include <celero/Celero.h>

#include <iostream>

#include <random>

#ifndef WIN32
#include <cmath>
#include <cstdlib>
#endif

CELERO_MAIN

std::random_device RandomDevice;
std::uniform_int_distribution<int> UniformDistribution(0, 255);

BASELINE(HelloWorld, T1, 200, 100)
{
    auto i = 0;
    celero::DoNotOptimizeAway(i);
}

BENCHMARK(HelloWorld, T2, 200, 100)
{
    auto i = 0;
    celero::DoNotOptimizeAway(i);
}

