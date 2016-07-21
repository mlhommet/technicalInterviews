//
// Created by Margaux Lhommet on 7/9/16.
//

#ifndef REVISIONS_XORLIST_H
#define REVISIONS_XORLIST_H

#include <iostream>
using namespace std;

struct node{
    int value;
    node * p;
};

node * XOR(const node* a, const node * b){
    return (node*) ((unsigned long) a ^ (unsigned long) b);
}

void printList(node * head){
    if (head == nullptr) return;
    cout<<head->value<<' ';
    node * next = XOR(head, head->p);
    printList(next);
}

node*  insertFront(node * head, int val){
    node * newNode = new node();
    newNode->value = val;
    newNode->p = XOR(head, nullptr);
    if (head != nullptr) {
        head->p = XOR(head->p, newNode);
    }
    return newNode;
}

void testXORList(){
    cout<<"Test XOR List"<<endl;
    node * a = insertFront(nullptr, 45);
    printList(a);
}

#endif //REVISIONS_XORLIST_H
