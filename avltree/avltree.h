#ifndef AVL_HEAD_H_2023_03_30
#define AVL_HEAD_H_2023_03_30

#include "src/mm.h"

namespace lab618
{

    template <class T, int(*Compare)(const T *pElement, const T* pElement2) >
    class CAVLTree
    {
    private:
        struct leaf
        {
            T* pData;
            leaf *pLeft;
            leaf *pRight;
            int balanceFactor;
        };

    public:
        class CException
        {
        public:
            CException()
            {
            }
        };

    public:
        CAVLTree(int defaultBlockSize)
        {
        }

        virtual ~CAVLTree()
        {
        }

        bool add(T* pElement)
        {
        }

        bool update(T* pElement)
        {
        }
      
        T* find(const T& pElement)
        {
        }

        bool remove(const T& element)
        {
        }

        void clear()
        {
        }

    private:
        leaf* m_pRoot;
        CMemoryManager<leaf> m_Memory;
    };

}; // namespace templates

#endif // #define AVL_HEAD_H_2023_03_30
