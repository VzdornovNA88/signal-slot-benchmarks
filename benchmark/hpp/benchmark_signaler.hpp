#pragma once

#include "../lib/signaler/src/signal/signal.hpp"

#include "../../benchmark.hpp"

class Signaler
{
    SlotScope reg;

    NOINLINE(void handler(Rng& rng))
    {
        volatile std::size_t a = rng(); (void)a;
    }

    public:

    using Signal = signaler::signal_t<void(Rng&)>;

    template <typename Subject, typename Foo>
    static void connect_method(Subject& subject, Foo& foo)
    {
        subject.template connect<Foo,&Foo::handler>(&foo);

        // Automatically disconnect when the foo instance is destroyed
        // Benchmarks require connection management
        foo.reg = make_slot_scope([&](void*) { subject.disconnect(); });
    }
    template <typename Subject>
    static void emit_method(Subject& subject, Rng& rng)
    {
        subject(rng);
    }

    // Used for switching policies at runtime
    static void initialize();

    static void validate_assert(std::size_t);
    static double construction(std::size_t, std::size_t);
    static double destruction(std::size_t, std::size_t);
    static double connection(std::size_t, std::size_t);
    static double disconnect(std::size_t, std::size_t);
    static double reconnect(std::size_t, std::size_t);
    static double emission(std::size_t, std::size_t);
    static double combined(std::size_t, std::size_t);

    // NOT IMPLEMENTED FOR THIS LIB
    static double threaded(std::size_t, std::size_t);

    static constexpr const char* C_LIB_NAME = "* VzdornovNA Signaler";
    static constexpr const char* C_LIB_SOURCE_URL = "https://github.com/VzdornovNA88/signaler.git";
    static constexpr const char* C_LIB_FILE = "benchmark_signaler";
    static constexpr const char* C_LIB_IS_HEADER_ONLY = "-";
    static constexpr const char* C_LIB_DATA_STRUCTURE = "std::vector";
    static constexpr const char* C_LIB_IS_THREAD_SAFE = "X";

    static constexpr const std::size_t C_LIB_SIZEOF_SIGNAL = sizeof(Signal);
};
