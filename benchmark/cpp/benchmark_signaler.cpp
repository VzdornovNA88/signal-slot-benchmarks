#include "../hpp/benchmark_signaler.hpp"

NOINLINE(void Signaler::initialize())
{
    // NOOP
}
NOINLINE(void Signaler::validate_assert(std::size_t N))
{
    return Benchmark<Signal, Signaler>::validation_assert(N);
}    
NOINLINE(double Signaler::construction(std::size_t N, std::size_t limit))
{
    return Benchmark<Signal, Signaler>::construction(N, limit);
}
NOINLINE(double Signaler::destruction(std::size_t N, std::size_t limit))
{
    return Benchmark<Signal, Signaler>::destruction(N, limit);
}
NOINLINE(double Signaler::connection(std::size_t N, std::size_t limit))
{
    return Benchmark<Signal, Signaler>::connection(N, limit);
}
NOINLINE(double Signaler::disconnect(std::size_t N, std::size_t limit))
{
    return Benchmark<Signal, Signaler>::disconnect(N, limit);
}
NOINLINE(double Signaler::reconnect(std::size_t N, std::size_t limit))
{
    return Benchmark<Signal, Signaler>::reconnect(N, limit);
}
NOINLINE(double Signaler::emission(std::size_t N, std::size_t limit))
{
    return Benchmark<Signal, Signaler>::emission(N, limit);
}
NOINLINE(double Signaler::combined(std::size_t N, std::size_t limit))
{
    return Benchmark<Signal, Signaler>::combined(N, limit);
}
NOINLINE(double Signaler::threaded(std::size_t N, std::size_t limit))
{
    // NOT IMPLEMENTED FOR THIS LIB
    return 0.0;
}
