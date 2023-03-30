#ifndef TEMPLATES_LIST_2023_02_02
#define TEMPLATES_LIST_2023_02_02

namespace lab618 {
template <class T>
class CSingleLinkedList {
 private:
  struct leaf {
    // Данные
    T data;
    // Указатель на следующий лист списка
    leaf *pNext;
    leaf(const T& _data, leaf *_pNext) {
      data = _data;
      pNext = _pNext;
    }
  };

 public:
  class CIterator {
   public:
    CIterator() : m_pCurrent(0), m_pBegin(0) {}

    CIterator(leaf *p) {
      m_pCurrent = p;
      m_pBegin = p;
    }

    CIterator(const CIterator& src) {
      m_pCurrent = src.m_pCurrent;
      m_pBegin = src.m_pBegin;
    }

    ~CIterator() {}

    CIterator& operator=(const CIterator& src) {
      m_pCurrent = src.m_pCurrent;
      m_pBegin = src.m_pBegin;
      return *this;
    }

    bool operator!=(const CIterator& it) const {
      return m_pCurrent == it.m_pCurrent;
    }

    void operator++() {
      if (m_pCurrent != m_pBegin - 1) {
        m_pCurrent = m_pCurrent->pNext;
      } else {
        m_pCurrent = m_pBegin;
      }
    }

    T& getData() { return m_pCurrent->data; }

    T& operator*() { return m_pCurrent->data; }

    leaf *getLeaf() { return m_pCurrent; }

    void setLeaf(leaf *p) { m_pCurrent = p; }

    void setLeafPreBegin(leaf *p) {
      m_pBegin = p;
      m_pCurrent = p - 1;
    }

    bool isValid() { return (m_pBegin != nullptr) && (m_pBegin <= m_pCurrent); }

   private:
    // храним голову списка, если мы находимся перед началом
    leaf *m_pBegin;
    // храним текущее положение
    leaf *m_pCurrent;
  };

 public:
  CSingleLinkedList() {
    m_pBegin = nullptr;
    m_pEnd = nullptr;
  }

  virtual ~CSingleLinkedList() { clear(); }

  void pushBack(const T& data) {
    auto node = new leaf(data, nullptr);
    if (m_pBegin == nullptr) {
      m_pBegin = node;
      m_pEnd = node;
    } else {
      m_pEnd->pNext = node;
      m_pEnd = node;
    }
  }

  void pushFront(const T& data) {
    auto node = new leaf(data, nullptr);
    if (m_pBegin == nullptr) {
      m_pBegin = node;
      m_pEnd = node;
    } else {
      node->pNext = m_pBegin;
      m_pBegin = node;
    }
  }

  T popFront() {
    if (m_pBegin != nullptr) {
      if (m_pBegin == m_pEnd) {
        m_pEnd = nullptr;
      }
      T tmp = m_pBegin->data;
      auto new_begin = m_pBegin->pNext;
      delete m_pBegin;
      m_pBegin = new_begin;
      return tmp;
    }
    return T();
  }

  // изменяет состояние итератора. выставляет предыдущую позицию.
  void erase(CIterator& it) {
    if (it.getLeaf() == m_pBegin) {
      popFront();
      it.setLeafPreBegin(m_pBegin);
      return;
    }
    CIterator tmp = begin();
    while (tmp.getLeaf()->pNext != it.getLeaf()) {
      ++tmp;
    }
    auto leaf = it.getLeaf()->pNext;
    if (it.getLeaf() == m_pEnd) {
      m_pEnd = tmp.getLeaf();
    }
    delete it.getLeaf();
    tmp.getLeaf()->pNext = leaf;
    it = tmp;
  }

  int getSize() {
    int size = 0;
    auto tmp = m_pBegin;
    while (tmp != nullptr) {
      ++size;
      tmp = tmp->pNext;
    }
    return size;
  }

  void clear() {
    while (m_pBegin != m_pEnd) {
      auto curr = m_pBegin;
      m_pBegin = m_pBegin->pNext;
      delete curr;
    }
    delete m_pBegin;
    m_pBegin = nullptr;
    m_pEnd = nullptr;
  }

  CIterator begin() { return CIterator(m_pBegin); }

 private:
  // храним голову и хвост списка
  leaf *m_pBegin, *m_pEnd;
};

template <class T>
class CDualLinkedList {
 private:
  struct leaf {
    // Данные
    T data;
    // Указатель на предыдущий / следующий лист списка
    leaf *pNext, *pPrev;
    leaf(const T& _data, leaf *_pPrev, leaf *_pNext) {
      data = _data;
      pNext = _pNext;
      pPrev = _pPrev;
    }
  };

 public:
  class CIterator {
   public:
    CIterator() {
      m_pBegin = nullptr;
      m_pCurrent = nullptr;
      m_pEnd = nullptr;
    }

    CIterator(leaf *p) {
      m_pCurrent = p;
      m_pBegin = p;
      m_pEnd = p;
      while (m_pBegin->pPrev != nullptr) {
        m_pBegin = m_pBegin->pPrev;
      }
      while (m_pEnd->pNext != nullptr) {
        m_pEnd = m_pEnd->pNext;
      }
    }

    CIterator(const CIterator& src) {
      m_pBegin = src.m_pBegin;
      m_pCurrent = src.m_pCurrent;
      m_pEnd = src.m_pEnd;
    }

    ~CIterator() {}

    CIterator& operator=(const CIterator& src) {
      m_pBegin = src.m_pBegin;
      m_pCurrent = src.m_pCurrent;
      m_pEnd = src.m_pEnd;
      return *this;
    }

    bool operator!=(const CIterator& it) const {
      return (m_pCurrent != it.m_pCurrent) || (m_pBegin != it.m_pBegin) ||
          (m_pEnd != it.m_pEnd);
    }

    void operator++() {
      if (m_pCurrent != m_pBegin - 1) {
        m_pCurrent = m_pCurrent->pNext;
      } else {
        m_pCurrent = m_pBegin;
      }
    }

    void operator--() {
      if (m_pCurrent != m_pEnd + 1) {
        m_pCurrent = m_pCurrent->pPrev;
      } else {
        m_pCurrent = m_pEnd;
      }
    }

    T& getData() { return m_pCurrent->data; }

    T& operator*() { return m_pCurrent->data; }

    leaf *getLeaf() { return m_pCurrent; }

    // применяется в erase и eraseAndNext
    void setLeaf(leaf *p) { m_pCurrent = p; }

    // применяется в erase и eraseAndNext
    void setLeafPreBegin(leaf *p) {
      m_pBegin = p;
      m_pCurrent = m_pBegin - 1;
    }

    // применяется в erase и eraseAndNext
    void setLeafPostEnd(leaf *p) {
      m_pEnd = p;
      m_pCurrent = m_pEnd + 1;
    }

    bool isValid() {
      return (m_pCurrent != nullptr) && (m_pCurrent >= m_pBegin) &&
          (m_pCurrent <= m_pEnd);
    }

   private:
    // храним голову списка, если мы находимся перед началом
    leaf *m_pBegin;
    // храним текущее положение
    leaf *m_pCurrent;
    // храним конец списка, если мы находимся после конца
    leaf *m_pEnd;
  };

 public:
  CDualLinkedList() {
    m_pBegin = nullptr;
    m_pEnd = nullptr;
  };

  virtual ~CDualLinkedList() { clear(); };

  void pushBack(const T& data) {
    leaf *node = new leaf(data, m_pEnd, nullptr);
    if (m_pEnd == nullptr) {
      m_pBegin = node;
    } else {
      m_pEnd->pNext = node;
    }
    m_pEnd = node;
  }

  T popBack() {
    if (m_pEnd != nullptr) {
      if (m_pBegin == m_pEnd) {
        m_pBegin = nullptr;
      }
      T tmp = m_pEnd->data;
      auto new_end = m_pEnd->pPrev;
      delete m_pEnd;
      m_pEnd = new_end;
      if (m_pEnd) {
        m_pEnd->pNext = nullptr;
      }
      return tmp;
    }
    return T();
  }

  void pushFront(const T& data) {
    leaf *node = new leaf(data, nullptr, m_pBegin);
    if (m_pBegin == nullptr) {
      m_pEnd = node;
    } else {
      m_pBegin->pPrev = node;
    }
    m_pBegin = node;
  }

  T popFront() {
    if (m_pBegin != nullptr) {
      if (m_pBegin == m_pEnd) {
        m_pEnd = nullptr;
      }
      T tmp = m_pBegin->data;
      auto new_begin = m_pBegin->pNext;
      delete m_pBegin;
      m_pBegin = new_begin;
      if (m_pBegin) {
        m_pBegin->pPrev = nullptr;
      }
      return tmp;
    }
    return T();
  }

  // изменяет состояние итератора. выставляет предыдущую позицию.
  void erase(CIterator& it) {
    if (it.getLeaf() == m_pBegin) {
      popFront();
      it.setLeafPreBegin(m_pBegin);
    } else {
      auto tmp = it.getLeaf();
      if (tmp->pNext != nullptr) {
        tmp->pPrev->pNext = tmp->pNext;
        tmp->pNext->pPrev = tmp->pPrev;
      } else {
        m_pEnd = tmp->pPrev;
        m_pEnd->pNext = nullptr;
        it = CIterator(m_pEnd);
      }
      it.setLeaf(tmp->pPrev);
      delete tmp;
    }
  }

  // изменяет состояние итератора. выставляет следующую позицию.
  void eraseAndNext(CIterator& it) {
    if (it.getLeaf() == m_pEnd) {
      popBack();
      it.setLeafPostEnd(m_pEnd);
    } else {
      auto tmp = it.getLeaf();
      if (tmp->pPrev != nullptr) {
        tmp->pPrev->pNext = tmp->pNext;
        tmp->pNext->pPrev = tmp->pPrev;
      } else {
        m_pBegin = tmp->pNext;
        m_pBegin->pPrev = nullptr;
        it = CIterator(m_pBegin);
      }
      it.setLeaf(tmp->pNext);
      delete tmp;
    }
  }

  int getSize() {
    int size = 0;
    auto tmp = m_pBegin;
    while (tmp != nullptr) {
      ++size;
      tmp = tmp->pNext;
    }
    return size;
  }

  void clear() {
    while (m_pBegin != m_pEnd) {
      auto curr = m_pBegin;
      m_pBegin = m_pBegin->pNext;
      delete curr;
    }
    delete m_pBegin;
    m_pBegin = nullptr;
    m_pEnd = nullptr;
  }

  CIterator begin() { return CIterator(m_pBegin); }

  CIterator end() { return CIterator(m_pEnd); }

 private:
  // храним голову и хвост списка
  leaf *m_pBegin, *m_pEnd;
};
};      // namespace lab618
#endif  // #ifndef TEMPLATES_LIST_2022_02_03
