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
   printf(" inside sum_vector problem_setup, N=%lld \n", N);
   std::srand(time(0));
   for(int64_t i = 0; i < N-1; i++) {
      A[i] = i;
   }
}

int64_t
sum(int64_t N, int64_t A[])
{
   int64_t s0=0;
   int64_t s1=0;
   int64_t s2=0;
   int64_t s3=0;
   // printf(" inside sum_vector perform_sum, N=%lld \n", N);
   for(int64_t i = 0; i < N; i+=4) {
      s0 += A[i];
      s1 += A[i + 1];
      s2 += A[i + 2];
      s3 += A[i + 3];
   }

   int64_t total = s0 + s1 + s2 + s3;

   return total;
}

