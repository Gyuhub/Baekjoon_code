#pragma once
#ifndef _BINARY_TREE_H_
#define _BINARY_TREE_H_

#include "BinaryNode.h"
#include "CircularQueue.h"

class BinaryTree
{
    BinaryNode *root;
public:
    BinaryTree() : root(NULL) {}
    void setRoot(BinaryNode *node) {root = node;}
    BinaryNode *getRoot() {return root;}
    bool isEmpty() {return root==NULL;}

    void inorder() {std::cout << "\n  inorder : "; inorder(root);}
    void inorder(BinaryNode *node) {
        if(node != NULL){
            inorder(node->getLeft());
            std::cout << " " << node->getData() << " ";
            inorder(node->getRight());
        }
    }
    
    void preorder() {std::cout << "\n  preorder : "; preorder(root);}
    void preorder(BinaryNode *node) {
        if(node != NULL){
            std::cout << " " << node->getData() << " ";
            preorder(node->getLeft());
            preorder(node->getRight());
        }
    }
    
    void postorder() {std::cout << "\n  postorder : "; postorder(root);}
    void postorder(BinaryNode *node) {
        if(node != NULL){
            postorder(node->getLeft());
            postorder(node->getRight());
            std::cout << " " << node->getData() << " ";
        }
    }
    
    void levelorder() {
        std::cout << "\nlevelorder : ";
        if(!isEmpty()){
            CircularQueue q;
            q.enqueue(root);
            while(!q.isEmpty()){
                BinaryNode *n = q.dequeue();
                if(n!=NULL){
                    std::cout << " " << n->getData() << " ";
                    q.enqueue(n->getLeft());
                    q.enqueue(n->getRight());
                }
            }
        }
        std::cout << std::endl;
    }

    int getCount() {return isEmpty() ? 0: getCount(root);}
    int getCount(BinaryNode *node) {
        if(node == NULL) return 0;
        return 1 + getCount(node->getLeft())
                 + getCount(node->getRight());
    }
    
    
    int getHeight() {return isEmpty() ? 0: getHeight(root);}
    int getHeight(BinaryNode *node) {
        if(node == NULL) return 0;
        int hLeft = getHeight(node->getLeft());
        int hRight = getHeight(node->getRight());
        return (hLeft>hRight) ? hLeft+1 : hRight+1;
    }

    int getLeafCount() {return isEmpty() ? 0: getLeafCount(root);}
    int getLeafCount(BinaryNode *node) {
        if(node == NULL) return 0;
        if(node->isLeaf()) return 1;
        else return getLeafCount(node->getLeft())
                  + getLeafCount(node->getRight());
    }
};

#endif