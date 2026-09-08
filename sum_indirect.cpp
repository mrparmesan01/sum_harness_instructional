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
   std::srand(time(0));
   // printf(" inside sum_indirect problem_setup, N=%lld \n", N);
   for(int64_t i = 0; i < N; i++) {
      A[i] = rand() % N;
   }
}

int64_t
sum(int64_t N, int64_t A[])
{
   // printf(" inside sum_indirect perform_sum, N=%lld \n", N);


   int64_t total = 0;

   int64_t* start = A;
   int64_t* end = A + N;

   while(start < end) {
      total += *start;
      start++;
   }

   return total;
}

