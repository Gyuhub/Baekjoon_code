#pragma once
#ifndef _CIRCULAR_QUEUE_H_
#define _CIRCULAR_QUEUE_H_

#include "BinaryNode.h"
#include <stdlib.h>
inline void error(char *str)
{
    fprintf(stderr, "%s\n", str);
    exit(1);
};
#define MAX_QUEUE_SIZE 100

class CircularQueue {
    int front;
    int rear;
    BinaryNode *data[MAX_QUEUE_SIZE];
public:
    CircularQueue() {front = rear = 0;}
    bool isEmpty() {return front == rear;}
    bool isFull() {return (rear+1)%MAX_QUEUE_SIZE == front;}
    void enqueue(BinaryNode *n){
        if(isFull()) error(" Error : Queue is full!!\n");
        else{
            rear = (rear + 1) % MAX_QUEUE_SIZE;
            data[rear] = n;
        }
    }
    BinaryNode *dequeue(){
        if(isEmpty()) error(" Error : Queue i empty!!\n");
        else{
            front = (front + 1) % MAX_QUEUE_SIZE;
            return data[front];
        }
    }
};

#endif