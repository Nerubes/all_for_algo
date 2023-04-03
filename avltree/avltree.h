#ifndef AVL_HEAD_H_2023_03_30
#define AVL_HEAD_H_2023_03_30

#include "mm.h"

namespace lab618 {

template<class T, int(*Compare)(const T *pElement, const T *pElement2)>
class CAVLTree {
 private:
  struct leaf {
    leaf() = default;
    T *pData = nullptr;
    leaf *pLeft = nullptr;
    leaf *pRight = nullptr;
    int balanceFactor = 0;
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
    m_pRoot = nullptr;
  }

  virtual ~CAVLTree() {
    clear();
  }

  bool add(T *pElement) {
    leaf *prev = nullptr;
    leaf *curr = findLeaf(pElement, prev);
    if (curr) {
      return false;
    }
    leaf *newLeaf = m_Memory.newObject();
    newLeaf->pData = pElement;
    if (!prev) {
      m_pRoot = newLeaf;
      return true;
    }
    if (Compare(pElement, prev->pData) < 0) {
      prev->pLeft = newLeaf;
    }
    if (Compare(pElement, prev->pData) > 0) {
      prev->pRight = newLeaf;
    }
    balance(newLeaf);
    return true;
  }

  bool update(T *pElement) {
    leaf *prev = nullptr;
    leaf *curr = findLeaf(pElement, prev);
    if (curr) {
      *(curr->pData) = *pElement;
      return true;
    }
    leaf *newLeaf = m_Memory.newObject();
    newLeaf->pData = pElement;
    if (!prev) {
      m_pRoot = newLeaf;
      return false;
    }
    if (Compare(pElement, prev->pData) < 0) {
      prev->pLeft = newLeaf;
    }
    if (Compare(pElement, prev->pData) > 0) {
      prev->pRight = newLeaf;
    }
    balance(newLeaf);
    return false;
  }

  T *find(const T& pElement) {
    leaf *curr = findLeaf(&pElement);
    if (curr) {
      return curr->pData;
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
  leaf* findLeaf(T* pElement, leaf* prev = nullptr) {
    prev = nullptr;
    leaf *curr = m_pRoot;
    while (curr) {
      prev = curr;
      int compare = Compare(&pElement, curr->pData);
      if (compare < 0) {
        curr = curr->pLeft;
        continue;
      }
      if (compare > 0) {
        curr = curr->pRight;
        continue;
      }
      if (compare == 0) {
        return curr->pData;
      }
    }
    return nullptr;
  }

  void balance(leaf* outOfOrderList) {

  }

  void correctBalance(leaf* curr) {
    curr->balanceFactor = 
  }

  int balanceFactor(leaf* curr) {
    if (curr) {
      return curr->balanceFactor;
    }
    return 0;
  }

  leaf *m_pRoot = nullptr;
  CMemoryManager<leaf> m_Memory = CMemoryManager<leaf>(1, true);
};

}; // namespace templates

#endif // #define AVL_HEAD_H_2023_03_30
