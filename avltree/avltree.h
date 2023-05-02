#ifndef AVL_HEAD_H_2023_03_30
#define AVL_HEAD_H_2023_03_30

#include "src/mm.h"

namespace lab618 {

template <class T>
static T max(const T& a, const T& b) {
  if (a < b) {
    return b;
  }
  return a;
}

template <class T, int (*Compare)(const T* pElement, const T* pElement2)>
class CAVLTree {
 private:
  struct leaf {
    T* pData;
    leaf* pLeft;
    leaf* pRight;
    int balanceFactor;
    leaf& operator=(const leaf& other) {
      if (this == &other) {
        return *this;
      }
      pData = other.pData;
      pLeft = other.pLeft;
      pRight = other.pRight;
      return *this;
    }
  };

 public:
  class CException {
   public:
    CException() {}
  };

 public:
  CAVLTree(int defaultBlockSize) {
    m_Memory = CMemoryManager<leaf>(defaultBlockSize, true);
    m_pRoot = nullptr;
  }

  virtual ~CAVLTree() { clear(); }

  bool add(T* pElement) {
    if (findLeaf(*pElement)) {
      return false;
    }
    m_pRoot = insert(m_pRoot, pElement);
    return true;
  }

  bool update(T* pElement) {
    leaf* curr = findLeaf(*pElement);
    if (curr) {
      curr->pData = pElement;
      return true;
    }
    add(pElement);
    return false;
  }

  T* find(const T& pElement) {
    leaf* curr = findLeaf(pElement);
    if (curr) {
      return curr->pData;
    }
    return nullptr;
  }

  bool remove(const T& element) {
    leaf* curr = findLeaf(element);
    if (curr) {
      m_pRoot = remove(m_pRoot, &element);
      return true;
    }
    return false;
  }

  void clear() {
    m_Memory.clear();
    m_pRoot = nullptr;
  }

 private:
  leaf* leftRotation(leaf* node) {
    leaf* right = node->pRight;
    leaf* subtree = right->pLeft;
    right->pLeft = node;
    node->pRight = subtree;
    calculateBalance(node);
    calculateBalance(right);
    return right;
  }

  leaf* rightRotation(leaf* node) {
    leaf* left = node->pLeft;
    leaf* subtree = left->pRight;
    left->pRight = node;
    node->pLeft = subtree;
    calculateBalance(node);
    calculateBalance(left);
    return left;
  }

  void calculateBalance(leaf* root) {
    root->balanceFactor =
        max(balanceFactor(root->pLeft), balanceFactor(root->pRight)) + 1;
  }

  int balanceFactor(leaf* node) {
    if (node) {
      return node->balanceFactor;
    }
    return 0;
  }

  leaf* balance(leaf* root) {
    calculateBalance(root);
    if (Difference(root) == 2) {
      if (Difference(root->pRight) < 0) {
        root->pRight = rightRotation(root->pRight);
      }
      return leftRotation(root);
    }
    if (Difference(root) == -2) {
      if (Difference(root->pLeft) > 0) {
        root->pLeft = leftRotation(root->pLeft);
      }
      return rightRotation(root);
    }
    return root;
  }

  int Difference(leaf* node) {
    return balanceFactor(node->pRight) - balanceFactor(node->pLeft);
  }

  leaf* insert(leaf* root, T* pElement) {
    if (root == nullptr) {
      leaf* new_leaf = m_Memory.newObject();
      new_leaf->balanceFactor = 0;
      new_leaf->pData = pElement;
      new_leaf->pLeft = nullptr;
      new_leaf->pRight = nullptr;
      return new_leaf;
    }
    int cmp = Compare(root->pData, pElement);
    if (cmp < 0) {
      root->pLeft = insert(root->pLeft, pElement);
    } else {
      root->pRight = insert(root->pRight, pElement);
    }
    return balance(root);
  }

  leaf* minLeaf(leaf* root) {
    leaf* curr = root;
    while (curr->pLeft) {
      curr = curr->pLeft;
    }
    return curr;
  }

  leaf* remove(leaf* root, const T* pElement) {
    int cmp = Compare(root->pData, pElement);
    if (!root) {
      return nullptr;
    }
    if (cmp < 0) {
      root->pLeft = remove(root->pLeft, pElement);
    } else if (cmp > 0) {
      root->pRight = remove(root->pRight, pElement);
    } else if (root->pLeft == nullptr || root->pRight == nullptr) {
      leaf* tmp = root->pLeft ? root->pLeft : root->pRight;
      if (tmp == nullptr) {
        tmp = root;
        root = nullptr;
      } else {
        *root = *tmp;
      }
      m_Memory.deleteObject(tmp);
    } else {
      leaf* tmp = minLeaf(root->pRight);
      root->pData = tmp->pData;
      root->pRight = remove(root->pRight, tmp->pData);
    }
    if (root) {
      return balance(root);
    }
    return nullptr;
  }

  leaf* findLeaf(const T& pElement) {
    leaf* curr = m_pRoot;
    while (curr) {
      int cmp = Compare(curr->pData, &pElement);
      if (cmp > 0) {
        curr = curr->pRight;
        continue;
      }
      if (cmp < 0) {
        curr = curr->pLeft;
        continue;
      }
      return curr;
    }
    return nullptr;
  }

  leaf* m_pRoot = nullptr;
  CMemoryManager<leaf> m_Memory = CMemoryManager<leaf>(1, true);
};

};  // namespace lab618

#endif  // #define AVL_HEAD_H_2023_03_30
