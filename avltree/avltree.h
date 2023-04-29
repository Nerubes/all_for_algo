#ifndef AVL_HEAD_H_2023_03_30
#define AVL_HEAD_H_2023_03_30

#include "src/mm.h"

namespace lab618 {

template<class T, int(*Compare)(const T *pElement, const T *pElement2)>
class CAVLTree {
 private:
  struct leaf {
    T *pData;
    leaf *pLeft;
    leaf *pRight;
    int balanceFactor;
  };

 public:
  class CException {
   public:
    CException() {
    }
  };

 public:
  CAVLTree(int defaultBlockSize) {
    m_Memory = CMemoryManager<leaf>(defaultBlockSize, true);
  }

  virtual ~CAVLTree() {
    clear();
  }

  bool add(T *pElement) {
    if (find(pElement)) {
      return false;
    }
    addElem(m_pRoot, pElement);
    return true;
  }

  bool update(T *pElement) {
    leaf* tmp = findElem(&pElement);
    if (tmp) {
      tmp->pData = pElement;
      return true;
    }
    add(pElement);
    return false;
  }

  T *find(const T& pElement) {
    leaf* tmp = findElem(&pElement);
    if (tmp) {
      return tmp->pData;
    }
    return nullptr;
  }

  bool remove(const T& element) {
  }

  void clear() {
    m_Memory.clear();
    m_pRoot = nullptr;
  }

 private:
  void addElem(leaf* root, const T* elem) {
    if (root == nullptr) {
      return;
    }
    int cmp = Compare(elem, root->pData);
    leaf* next = nullptr;
    int balance = 0;
    if (cmp < 0) {
      next = root->pLeft;
      if (next == nullptr) {
        root->pLeft = m_Memory.newObject();
        root->pLeft->pData = elem;
      }
      balance = -1;
    } else {
      next = root->pRight;
      if (next == nullptr) {
        root->pLeft = m_Memory.newObject();
        root->pLeft->pData = elem;
      }
      balance = 1;
    }
    addElem(next, elem);
    root->balanceFactor += balance;
  }

  leaf* findElem(const T* elem) {
    leaf* curr = m_pRoot;
    while (curr) {
      int cmp = Compare(elem, curr->pData);
      if (cmp < 0) {
        curr = curr->pLeft;
        continue;
      }
      if (cmp > 0) {
        curr = curr->pRight;
        continue;
      }
      return curr;
    }
    return nullptr;
  }

  leaf *m_pRoot;
  CMemoryManager<leaf> m_Memory = CMemoryManager<leaf>(1, true);
};

}; // namespace templates

#endif // #define AVL_HEAD_H_2023_03_30
