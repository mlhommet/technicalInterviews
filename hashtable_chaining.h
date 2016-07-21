//
// Created by Margaux Lhommet on 7/3/16.
//

#ifndef REVISIONS_HASHTABLE_CHAINING_H
#define REVISIONS_HASHTABLE_CHAINING_H

#include <vector>
#include <iostream>
using namespace std;

class hashtable_chaining {
private:
    struct node{
        int id;
        string value;
        node * next;
        node(int id, const string & value, node*next):id(id),value(value), next(next){};
    };

    vector<node*> array;
    int buckets;

private:
    int hash(int id) const{
        return id%buckets;
    }

    node* insert_addBucket(node * n, int id, const string & s){
        if (n==NULL){
            n = new node(id, s, NULL);
            return n;
        }
        if (n->id == id)
            n->value = s;
        else
            n->next = insert_addBucket(n->next, id, s);
        return n;
    }

    node * removeBucket(node *n, int id){
        if (n==NULL)
            return NULL;
        if (n->id == id)
            return n->next;
        else {
            n->next = removeBucket(n->next, id);
            return n;
        }
    }

public:
    hashtable_chaining(int buckets=7):buckets(buckets),array(vector<node*>(buckets)){};

    string getValue(int id) const{
        int bucket = hash(id);
        node * n = array[bucket];
        while (n != NULL){
            if (n->id == id) return n->value;
            else n = n->next;
        }
        return "not found";
    }

    void addItem(int id, const string & s){
        cout<<"Add to bucket " <<hash(id)<<endl;
        array[hash(id)] = insert_addBucket(array[hash(id)], id, s);
    }

    void modifyItem(int id, const string & s){
        array[hash(id)] = insert_addBucket(array[hash(id)], id, s);
    }

    void deleteItem(int id){
        array[hash(id)] = removeBucket(array[hash(id)], id);

    }

    void print(){
        for (int i=0; i<buckets; ++i){
            cout<<i<<": ";
            for (node* n = array[hash(i)]; n!= NULL; n = n->next){
                cout<<" ["<<n->id<<" "<<n->value<<"] ,";
            }
            cout<<endl;
        }
    }

    static void test(){
        hashtable_chaining a (5);
        a.addItem(24,"Margot");
        a.addItem(65,"Emilie");
        a.addItem(29,"Margot2");
        a.print();
        a.deleteItem(24);
        a.deleteItem(24);
        a.deleteItem(29);
        a.print();


    }
};


#endif //REVISIONS_HASHTABLE_CHAINING_H
