//
// Created by Margaux Lhommet on 6/29/16.
//

#include "LinkedList.h"

void LinkedList::MergeSort(node** A){
    node * head = *A;
    if ((head == NULL) || (head->next == NULL))
        return;
    // Split the list in two
    node * first, * second;
    FrontBackSplit(head, &first, &second);
    MergeSort(&first);
    MergeSort(&second);
    *A = Merge(first, second);
}

void LinkedList::FrontBackSplit(node *head, node **first, node **second){
    if ((head==NULL) || (head->next == NULL)){
        *first = head;
        *second = NULL;
    }
    else{
        // use fast pointer to find the end
        // use slow pointer to find the split point (halfway)
        node * fast = head->next;
        node * slow = head;
        while (fast != NULL){
            fast = fast->next;
            if (fast != NULL){
                fast = fast->next;
                slow = slow->next;
            }
        }
        *second = slow->next;
        slow->next = NULL;
        *first = head;
    }
}

LinkedList::node * LinkedList::Merge(node *a, node *b){
    if (a==NULL) return b;
    if (b==NULL) return a;
    node * res = NULL;
    if (a->data <= b->data){
        res = a;
        res->next = Merge(a->next, b);
    }
    else{
        res = b;
        res->next = Merge(a,b->next);
    }
    return res;
}