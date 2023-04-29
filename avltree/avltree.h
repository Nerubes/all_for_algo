#ifndef AVL_HEAD_H_2023_03_30
#define AVL_HEAD_H_2023_03_30

<<<<<<< HEAD
#include "src/mm.h"
=======
#include "mm.h"
>>>>>>> origin/master

namespace lab618 {

template<class T, int(*Compare)(const T *pElement, const T *pElement2)>
class CAVLTree {
 private:
  struct leaf {
<<<<<<< HEAD
    T *pData;
    leaf *pLeft;
    leaf *pRight;
    int balanceFactor;
=======
    leaf() = default;
    T *pData = nullptr;
    leaf *pLeft = nullptr;
    leaf *pRight = nullptr;
    int balanceFactor = 0;
>>>>>>> origin/master
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
<<<<<<< HEAD
=======
    m_pRoot = nullptr;
>>>>>>> origin/master
  }

  virtual ~CAVLTree() {
    clear();
  }

  bool add(T *pElement) {
<<<<<<< HEAD
    if (find(pElement)) {
      return false;
    }
    addElem(m_pRoot, pElement);
=======
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
>>>>>>> origin/master
    return true;
  }

  bool update(T *pElement) {
<<<<<<< HEAD
    leaf* tmp = findElem(&pElement);
    if (tmp) {
      tmp->pData = pElement;
      return true;
    }
    add(pElement);
=======
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
>>>>>>> origin/master
    return false;
  }

  T *find(const T& pElement) {
<<<<<<< HEAD
    leaf* tmp = findElem(&pElement);
    if (tmp) {
      return tmp->pData;
=======
    leaf *curr = findLeaf(&pElement);
    if (curr) {
      return curr->pData;
>>>>>>> origin/master
    }
    return nullptr;
  }

  bool remove(const T& element) {
<<<<<<< HEAD
=======

>>>>>>> origin/master
  }

  void clear() {
    m_Memory.clear();
    m_pRoot = nullptr;
  }

 private:
<<<<<<< HEAD
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
=======
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
>>>>>>> origin/master
    }
    return nullptr;
  }

<<<<<<< HEAD
  leaf *m_pRoot;
=======
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
>>>>>>> origin/master
  CMemoryManager<leaf> m_Memory = CMemoryManager<leaf>(1, true);
};

}; // namespace templates

#endif // #define AVL_HEAD_H_2023_03_30
