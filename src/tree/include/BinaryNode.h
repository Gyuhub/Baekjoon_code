#pragma once
#ifndef _BINARY_NODE_H_
#define _BINART_NODE_H_

#include <iostream>

class BinaryNode
{
protected:
    char data;
    BinaryNode *left;
    BinaryNode *right;
public:
    BinaryNode(char val=0, BinaryNode *l=NULL, BinaryNode *r=NULL) : data(val), left(l), right(r) {}
    void setData(char val) {data = val;}
    void setLeft(BinaryNode *l) {left = l;}
    void setRight(BinaryNode *r) {right = r;}
    char getData() {return data;}
    BinaryNode *getLeft() {return left;}
    BinaryNode *getRight() {return right;}
    bool isLeaf() {return left==NULL && right==NULL;}
};

#endif