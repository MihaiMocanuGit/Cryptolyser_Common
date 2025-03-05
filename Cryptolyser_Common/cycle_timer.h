#ifndef CRYPTOLYSER_COMMON_CYCLE_TIMER_H
#define CRYPTOLYSER_COMMON_CYCLE_TIMER_H

#include <stdint.h>

struct cycle_timer_t
{
    uint64_t t1;
    uint64_t t2;
};

#if defined __x86_64__

inline __attribute__((always_inline)) struct cycle_timer_t time_start(void)
{
    uint32_t a, d;
    __asm__ volatile("cpuid" ::: "%rax", "%rbx", "%rcx", "%rdx");
    __asm__ volatile("rdtsc" : "=a"(a), "=d"(d));
    struct cycle_timer_t time = {.t1 = 0, .t2 = ((uint64_t)a) | (((uint64_t)d) << 32)};
    return time;
}

inline __attribute__((always_inline)) struct cycle_timer_t time_end(void)
{
    uint32_t a, d;
    __asm__ volatile("rdtscp" : "=a"(a), "=d"(d));
    __asm__ volatile("cpuid" ::: "%rax", "%rbx", "%rcx", "%rdx");
    struct cycle_timer_t time = {.t1 = 0, .t2 = ((uint64_t)a) | (((uint64_t)d) << 32)};
    return time;
}

#else

inline __attribute__((always_inline)) struct Timer time_start(void)
{
    struct timespec t;
    clock_gettime(CLOCK_THREAD_CPUTIME_ID, (struct timespec *)&t);
    struct Timer time = {.t1 = t.tv_sec, .t2 = t.tv_nsec);
    return time;
}

inline __attribute__((always_inline)) struct Timer time_end(void) { return time_start(t1, t2); }

#endif
#endif // CRYPTOLYSER_COMMON_CYCLE_TIMER_H
