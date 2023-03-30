#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "list.hpp"
#include "src/doctest.h"

#include <iostream>

using namespace lab618;

TEST_CASE("Push/Pop Single linked list") {
  CSingleLinkedList<int> a;
  for (int i = 0; i < 1000; ++i) {
    a.pushBack(i);
    CHECK(a.popFront() == i);
    CHECK(a.getSize() == 0);
  }
  for (int i = 0; i < 1000; ++i) {
    a.pushFront(i);
    CHECK(a.getSize() == i + 1);
  }
  for (int i = 999; i >= 0; --i) {
    CHECK(a.popFront() == i);
    CHECK(a.getSize() == i);
  }
}

TEST_CASE("Erase Single linked list") {
  CSingleLinkedList<int> a;
  for (int i = 0; i < 100; ++i) {
    a.pushBack(i);
  }
  auto iter = a.begin();
  for (int i = 0; i < 50; ++i) {
    a.erase(iter);
    CHECK(a.getSize() == 99 - i);
    ++iter;
    CHECK(iter.getData() == i + 1);
  }
  iter = a.begin();
  while (iter.getLeaf()->pNext != nullptr) {
    ++iter;
  }
  int i = 0;
  while (a.getSize() > 0) {
    CHECK(*a.begin() == 50);
    CHECK(*iter == 99 - i);
    a.erase(iter);
    ++i;
  }
  CHECK(a.getSize() == 0);
}

TEST_CASE("Clear Single linked list") {
  CSingleLinkedList<int> a;
  for (int i = 0; i < 100; ++i) {
    a.pushBack(i);
  }
  a.clear();
  CHECK(a.getSize() == 0);
}

TEST_CASE("Push/Pop Dual linked list") {
  CDualLinkedList<int> a;
  for (int i = 0; i < 1000; ++i) {
    a.pushBack(i);
  }
  CHECK(a.getSize() == 1000);
  for (int i = 0; i < 1000; ++i) {
    CHECK(a.popFront() == i);
  }
  CHECK(a.getSize() == 0);
  for (int i = 0; i < 1000; ++i) {
    a.pushFront(i);
  }
  CHECK(a.getSize() == 1000);
  for (int i = 0; i < 1000; ++i) {
    CHECK(a.popBack() == i);
  }
  CHECK(a.getSize() == 0);
}
TEST_CASE("Push/Pop Dual linked list") {
  CDualLinkedList<int> a;
  for (int i = 0; i < 100; ++i) {
    a.pushBack(i);
  }
  CHECK(a.getSize() == 100);
  for (int i = 0; i < 100; ++i) {
    CHECK(a.popFront() == i);
  }
  CHECK(a.getSize() == 0);
  for (int i = 0; i < 100; ++i) {
    a.pushFront(i);
  }
  CHECK(a.getSize() == 100);
  for (int i = 0; i < 100; ++i) {
    CHECK(a.popBack() == i);
  }
  CHECK(a.getSize() == 0);
}

TEST_CASE("Erase Dual linked list") {
  CDualLinkedList<int> a;
  for (int i = 0; i < 100; ++i) {
    a.pushBack(i);
  }
  auto iter = a.begin();
  for (int i = 0; i < 50; ++i) {
    a.erase(iter);
    CHECK(a.getSize() == 99 - i);
    ++iter;
    CHECK(iter.getData() == i + 1);
  }
  iter = a.end();
  int i = 0;
  while (a.getSize() > 0) {
    CHECK(*a.begin() == 50);
    CHECK(*iter == 99 - i);
    a.erase(iter);
    ++i;
  }
  CHECK(a.getSize() == 0);
}

TEST_CASE("EraseAndNext Dual linked list") {
  CDualLinkedList<int> a;
  for (int i = 0; i < 100; ++i) {
    a.pushBack(i);
  }
  auto iter = a.begin();
  for (int i = 0; i < 50; ++i) {
    a.eraseAndNext(iter);
    CHECK(a.getSize() == 99 - i);
    CHECK(iter.getData() == i + 1);
  }
  iter = a.end();
  int i = 0;
  while (a.getSize() > 0) {
    CHECK(*a.begin() == 50);
    CHECK(*iter == 99 - i);
    a.eraseAndNext(iter);
    --iter;
    ++i;
  }
  CHECK(a.getSize() == 0);
}

TEST_CASE("Clear Dual linked list") {
  CDualLinkedList<int> a;
  for (int i = 0; i < 100; ++i) {
    a.pushBack(i);
  }
  CHECK(a.getSize() == 100);
  a.clear();
  CHECK(a.getSize() == 0);
}