#ifndef TESTC_H
#define TESTC_H

void __test_fail(const char* expression,
                 const char* file,
                 const char* function,
                 int line);

#define test_assert(expression) \
  ((void)((expression)          \
              ? ((void)0)       \
              : __test_fail(#expression, __FILE__, __FUNCTION__, __LINE__)))

void test(void (*test)(void));

void test_results(void);

#endif  // TESTC_H
