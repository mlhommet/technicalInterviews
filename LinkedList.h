//
// Created by Margaux Lhommet on 6/29/16.
//

#ifndef REVISIONS_MERGESORTLIST_H
#define REVISIONS_MERGESORTLIST_H

#include <iostream>
using namespace std;

class LinkedList {

    /* Link list node */
public:
    struct node {
        int data;
        struct node *next;
    };

protected:
    /* Function to print nodes in a given linked list */
    static void printList(struct node *node) {
        while (node != NULL) {
            cout<< node->data;
            if (node->next != nullptr) cout<<"->";
            node = node->next;
        }
        cout<<endl;
    }

    /* Function to insert a node at the beginging of the linked list */
    static void push(struct node **head_ref, int new_data) {
        /* allocate node */
        struct node *new_node = (struct node *) malloc(sizeof(struct node));
        /* put in the data  */
        new_node->data = new_data;
        /* link the old list off the new node */
        new_node->next = (*head_ref);
        /* move the head to point to the new node */
        (*head_ref) = new_node;
    }

    virtual void MergeSort (node ** A);
    virtual void FrontBackSplit(node * head, node ** first, node **second);
    virtual node * Merge(node* a, node * b);

    static node* getKthRight(node *A, int B){
        int count = 0;
        node* n = A;
        while (count<B){
            count++;
            if (n->next == nullptr) {
                B = B%count; // we know the length of the list so we can reduce the # of iterations
                if (B==0) return A;
                else n=A; //get back to the start
            }
            else n = n->next;
        }
        node *res = A;
        // move to the end
        while (n->next != nullptr){
            n=n->next;
            res = res->next;
        }
        return res;
    }

    static node* rotateRight(node* A, int B) {
        //extreme cases
        if ((A == nullptr) || A->next == nullptr || B==0) return A;

        //reach element at location B
        node * n = getKthRight(A, B+1);
        // if we are back to the start, return the initial list
        if (n->next == nullptr) return A;

        // mark Kth element as the new head (this is what we return)
        node * head = n->next;
        // disconnect the Kth-1 element from element
        n->next = nullptr;

        // move n to the last element and connect to A
        n = head;
        while (n->next != nullptr){
            n=n->next;
        }
        n->next = A;
        return head;
    }

    static node * reverseList(node* n){
        node* prev = nullptr;
        node* current = n;
        node* next;
        while (current != nullptr){
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        return prev;
    }


    static node * reverseRec(node * head){
        if (head == nullptr || head->next == nullptr)
            return head;
        node * res = reverseRec(head->next);
        head->next->next = head;
        head->next = nullptr;
        return res;
    }


public:
    static void testLinkedList(){
        /* Start with the empty list */
        struct node* res = NULL;
        struct node* a = NULL;

        /* Let us create a unsorted linked lists to test the functions
         Created lists shall be a: 2->3->20->5->10->15 */
        push(&a, 1);
        push(&a, 2);
        push(&a, 3);
        push(&a, 4);
        push(&a, 5);
        push(&a, 6);
        push(&a, 7);


        //MergeSort(&a);
        cout<<"List init: ";
        printList(a);
//        cout<<endl<<"Test Rotate right"<<endl;
//        node * b = rotateRight(a, 89);
//        printList(b);
//        cout<<endl<<"Test reverse list"<<endl;
        //reverseList2(a, a->next->next);
        node * rec = reverseRec(a);
        cout<< "List revert: ";
        printList(rec);
//
//        /* Sort the above created Linked List */
//
//
//        printf("\n Sorted Linked List is: \n");
//        printList(a);
//
//        getchar();
    }

};


#endif //REVISIONS_MERGESORTLIST_H
