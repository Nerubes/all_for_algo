#include "sort.h"

static void merge(void **ppArray, int length1, int length2, templates::CompareSortType pCompareFunc, void **tmp) {
  int pos1 = 0;
  int pos2 = 0;
  while (pos1 + pos2 < length1 + length2) {
    if (pos2 == length2 || (pos1 < length1 && pCompareFunc(*(ppArray + pos1), *(ppArray + length1 + pos2)) <= 0)) {
      tmp[pos1 + pos2] = *(ppArray + pos1);
      ++pos1;
    } else {
      tmp[pos1 + pos2] = *(ppArray + length1 + pos2);
      ++pos2;
    }
  }
  for (int i = 0; i < length1 + length2; ++i) {
    ppArray[i] = tmp[i];
  }
}

static void mergeSortReal(void **ppArray, int length, templates::CompareSortType *pCompareFunc, void **tmp) {
  if (length == 1) {
    return;
  }
  int mid = length / 2;
  mergeSortReal(ppArray, mid, pCompareFunc, tmp);
  mergeSortReal(ppArray + mid, length - mid, pCompareFunc, tmp);
  merge(ppArray, mid, length - mid, pCompareFunc, tmp);
}

void templates::mergeSort(void **ppArray, int length, templates::CompareSortType *pCompareFunc) {
  void **tmp = new void *[length];
  mergeSortReal(ppArray, length, pCompareFunc, tmp);
  delete[] tmp;
}

static void siftDown(void **ppArray, int length, templates::CompareSortType *pCompareFunc, int i) {
  while (2 * i + 1 < length) {
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int j = left;
    if (right < length && (pCompareFunc(ppArray[right], ppArray[left]) < 0)) {
      j = right;
    }
    if (pCompareFunc(ppArray[i], ppArray[j]) < 0) {
      break;
    }
    void *tmp = ppArray[i];
    ppArray[i] = ppArray[j];
    ppArray[j] = tmp;
    i = j;
  }
}

static void heapify(void **ppArray, int length, templates::CompareSortType *pCompareFunc) {
  for (int i = length / 2; i >= 0; --i) {
    siftDown(ppArray, length, pCompareFunc, i);
  }
}

void *extractMin(void **ppArray, int length, templates::CompareSortType *pCompareFunc) {
  void *min = ppArray[0];
  ppArray[0] = ppArray[length - 1];
  --length;
  siftDown(ppArray, length, pCompareFunc, 0);
  return min;
}

void templates::heapSort(void **ppArray, int length, templates::CompareSortType *pCompareFunc) {
  void **tmp = new void *[length];
  for (int i = 0; i < length; ++i) {
    tmp[i] = ppArray[i];
  }
  heapify(tmp, length, pCompareFunc);
  for (int i = 0; i < length; ++i) {
    ppArray[i] = extractMin(tmp, length - i, pCompareFunc);
  }
}