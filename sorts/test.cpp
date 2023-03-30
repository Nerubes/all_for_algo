#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "sort.h"
#include "src/doctest.h"

#include <vector>
#include <algorithm>

using namespace templates;

int cmpInt(const int *first, const int *second) {
  return *first - *second;
}

int cmpDouble(const double *first, const double *second) {
  if (*first < *second) {
    return -1;
  } else if (*first == *second) {
    return 0;
  }
  return 1;
}

TEST_CASE("Random 1000 ints, merge sort") {
  int length = 1000;
  std::vector<int> arr(length);
  int **pArr = new int *[length];
  for (int i = 0; i < length; ++i) {
    arr[i] = rand() % 2000 - 2000;
    pArr[i] = arr.data() + i;
  }
  std::vector<int> second_array = arr;
  std::sort(second_array.begin(), second_array.end());
  mergeSort(pArr, length, cmpInt);
  for (int i = 0; i < length; ++i) {
    CHECK(*pArr[i] == second_array[i]);
  }
}

TEST_CASE("Random 1000 ints, heap sort") {
  int length = 1000;
  std::vector<int> arr(length);
  int **pArr = new int *[length];
  for (int i = 0; i < length; ++i) {
    arr[i] = rand() % 2000 - 2000;
    pArr[i] = arr.data() + i;
  }
  std::vector<int> second_array = arr;
  std::sort(second_array.begin(), second_array.end());
  heapSort(pArr, length, cmpInt);
  for (int i = 0; i < length; ++i) {
    CHECK(*pArr[i] == second_array[i]);
  }
}

double Rand(double Min, double Max)
{
  double f = (double)rand() / RAND_MAX;
  return Min + f * (Max - Min);
}

TEST_CASE("Random 1000 doubles, merge sort") {
  int length = 1000;
  std::vector<double> arr(length);
  double **pArr = new double *[length];
  for (int i = 0; i < length; ++i) {
    arr[i] = Rand(-1000, 1000);
    pArr[i] = arr.data() + i;
  }
  std::vector<double> second_array = arr;
  std::sort(second_array.begin(), second_array.end());
  mergeSort(pArr, length, cmpDouble);
  for (int i = 0; i < length; ++i) {
    CHECK(*pArr[i] == second_array[i]);
  }
}

TEST_CASE("Random 1000 doubles, heap sort") {
  int length = 1000;
  std::vector<double> arr(length);
  double **pArr = new double *[length];
  for (int i = 0; i < length; ++i) {
    arr[i] = Rand(-1000, 1000);
    pArr[i] = arr.data() + i;
  }
  std::vector<double> second_array = arr;
  std::sort(second_array.begin(), second_array.end());
  heapSort(pArr, length, cmpDouble);
  for (int i = 0; i < length; ++i) {
    CHECK(*pArr[i] == second_array[i]);
  }
}