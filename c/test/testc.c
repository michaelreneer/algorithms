#include "testc.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

static unsigned long test_fail = 0;
static unsigned long test_failed = 0;
static unsigned long test_passed = 0;
static struct timespec test_time = {0, 0};

#define NANOSECONDS_PER_SECOND 1000000000
#define NANOSECONDS_PER_MILISECOND 1000000

void __test_fail(const char* expression,
                 const char* file,
                 const char* function,
                 int line) {
  ++test_fail;
  printf(
      "============================================================\n"
      "FAIL: %s\n"
      "------------------------------------------------------------\n"
      "Assertion failed: (%s) in %s:%d\n"
      "\n",
      function, expression, file, line);
}

static struct timespec time_diff(struct timespec start, struct timespec stop) {
  struct timespec time = {0, 0};
  if ((stop.tv_nsec - start.tv_nsec) < 0) {
    time.tv_sec = stop.tv_sec - start.tv_sec - 1;
    time.tv_nsec = NANOSECONDS_PER_SECOND + stop.tv_nsec - start.tv_nsec;
  } else {
    time.tv_sec = stop.tv_sec - start.tv_sec;
    time.tv_nsec = stop.tv_nsec - start.tv_nsec;
  }
  return time;
}

static struct timespec time_add(struct timespec time1, struct timespec time2) {
  struct timespec time = {0, 0};
  if ((time1.tv_nsec + time2.tv_nsec) >= NANOSECONDS_PER_SECOND) {
    time.tv_sec = time1.tv_sec + time2.tv_sec + 1;
    time.tv_nsec = time1.tv_nsec + time2.tv_nsec - NANOSECONDS_PER_SECOND;
  } else {
    time.tv_sec = time1.tv_sec + time2.tv_sec;
    time.tv_nsec = time1.tv_nsec + time2.tv_nsec;
  }
  return time;
}

void test(void (*test)(void)) {
  test_fail = 0;

  struct timespec start = {0, 0};
  clock_gettime(CLOCK_MONOTONIC, &start);
  test();
  struct timespec stop = {0, 0};
  clock_gettime(CLOCK_MONOTONIC, &stop);

  struct timespec diff = time_diff(start, stop);
  test_time = time_add(test_time, diff);

  if (test_fail == 0) {
    ++test_passed;
  } else {
    ++test_failed;
  }
}

void test_results(void) {
  printf(
      "------------------------------------------------------------\n"
      "Ran %lu tests in %ld.%.3lds\n"
      "\n",
      test_passed + test_failed, test_time.tv_sec,
      test_time.tv_nsec / NANOSECONDS_PER_MILISECOND);

  if (test_failed == 0) {
    printf("PASSED\n");
  } else {
    printf("FAILED (%lu failures)\n", test_failed);
    exit(1);
  }
}
