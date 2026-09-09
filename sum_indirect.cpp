#include <algorithm>
#include <chrono>
#include <iomanip>
#include <iostream>
#include <random>
#include <vector>
#include <string.h>

#include "sums.h"

void 
setup(int64_t N, int64_t A[])
{
   printf("inside sum_indirect problem_setup, N=%lld \n", N);
   for(int64_t i = 0; i < N-1; i++) {
      A[i] = lrand48() % N;
   }
}

int64_t
sum(int64_t N, int64_t A[])
{
   printf(" inside sum_indirect perform_sum, N=%lld \n", N);

   int64_t total = 0;
   int64_t index = 0;

   for(int64_t i = 0; i < N; i++) {
      index = A[index];
      total += A[index];
   }

   return total;
}

