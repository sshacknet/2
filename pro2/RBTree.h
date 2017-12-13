#pragma once

#include <memory>

typedef enum { RED, BLACK } Color;

template <class KeyType>
class RBTreeNode
{
public:
    std::shared_ptr<RBTreeNode<KeyType>> right, left;//子节点
    std::shared_ptr<RBTreeNode<KeyType>> p;//父节点
    Color color;
    KeyType key;

    RBTreeNode(KeyType key): right(nullptr), left(nullptr), color(BLACK), key(key) { }
};

template <class KeyType>
class RBTree
{
public:
    std::shared_ptr<RBTreeNode<KeyType>> root;
    std::shared_ptr<RBTreeNode<KeyType>> nil;
    RBTree() : root(nullptr), nil(std::make_shared<RBTreeNode<KeyType>>(NULL)) { }

    void insert(KeyType key);
    bool serach(KeyType key);
private:
    void adjust(std::shared_ptr<RBTreeNode<KeyType>> z);
    void left_rotate(std::shared_ptr<RBTreeNode<KeyType>> x);
    void right_rotate(std::shared_ptr<RBTreeNode<KeyType>> x);
};

template <class KeyType>
void RBTree<KeyType>::insert(KeyType key)
{
    auto z = std::make_shared<RBTreeNode<KeyType>>(key);
    auto y = nil;
    auto x = root;
    while (x != nil)
    {
        y = x;
        if (z->key < x.key)
            x = x->left;
        else
            x = x->right;
    }
    z->p = y;
    if (y == nullptr) { root = z; }
    else if (z->key < y->key)
    {
        y->left = z;
    }
    else
    {
        y->right = z;
    }

    z.color = RED;
    adjust(z);
}

template <class KeyType>
void RBTree<KeyType>::adjust(std::shared_ptr<RBTreeNode<KeyType>> z)
{
    std::shared_ptr<RBTreeNode<KeyType>> y;
    while (z->p->color = RED)
    {
        if (z->p == z->p->p->left)
        {
            y = z->p->p->right;
            if (y->color == RED)
            {
                z->p->color = BLACK;
                y->color = BLACK;
                z->p->p->color = RED;
                z = z->p->p;
            }
            else if (z == z->p->right)
            {
                z = z->p;
                left_rotate(z);
            }
            z->p->color = BLACK;
            z->p->p->color = RED;
            right_rotate(z->p->p);
        }
        else
        {
            ;
        }
    }
}

template <class KeyType>
void RBTree<KeyType>::left_rotate(std::shared_ptr<RBTreeNode<KeyType>> x)
{
    auto y = x->right;
    x->right = y->left;
    if (y->left != nil)
    {
        y->left->p = x;
    }
    y->p = x->p;
    if (x->p == nil)
    {
        root = y;
    }
    else if (x == x->p->left)
    {
        x->p->left = y;
    }
    else
    {
        x->p->right = y;
    }
    y->left = x;
    x->p = y;
}

template <class KeyType>
void RBTree<KeyType>::right_rotate(std::shared_ptr<RBTreeNode<KeyType>> x)
{
    //
}
