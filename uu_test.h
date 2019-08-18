#pragma once

#include "stdio.h"

typedef bool TestResult;

#define SUCCESS true
#define FAIL    false

extern int passed;
extern int failed;


#define ASSERT(cond) \
    if(!(cond)) \
    { \
        printf("    Assertion is failed: "#cond"\n");\
        res = FAIL; \
        return; \
    }

#define EXPECT(cond) \
    if(!(cond)) \
    { \
        printf("    Expectation is failed: "#cond"\n");\
        res = FAIL; \
    }

#define TEST(test_case, test_name) \
    class test_name \
    { \
        TestResult res; \
    public: \
        test_name(); \
        void func(); \
    }; \
    test_name test_name; \
    test_name::test_name() \
    { \
        printf(#test_case"."#test_name" - run\n");\
        res = SUCCESS; \
        func(); \
        printf(#test_case"."#test_name);\
        if(res == FAIL) \
        { \
            failed++; \
            printf(" - failed\n"); \
        } \
        else \
        { \
            passed++; \
            printf(" - passed\n"); \
        } \
    }; \
    void test_name::func()


#define DEFINE_TEST_RESULTS \
    int passed = 0; \
    int failed = 0;


#define TEST_RESULTS \
    printf("%d test(s) - failed\n", failed); \
    printf("%d test(s) - passed\n", passed); \
    if(failed) \
    { \
        printf("Some tests failed\n"); \
    } \
    else \
    { \
        printf("All tests passed\n"); \
    }
