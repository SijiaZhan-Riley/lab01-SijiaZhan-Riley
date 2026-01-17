// intlist.cpp
// Implements class IntList
// YOUR NAME(S), AND DATE

#include "intlist.h"

#include <iostream>
using std::cout;

// copy constructor
IntList::IntList(const IntList& source) {
    head = nullptr;
    tail = nullptr;

    Node* curr = source.head;
    while (curr) {
        push_back(curr->info);
        curr = curr->next;
    }
}


// destructor deletes all nodes
IntList::~IntList() {
    Node* curr=head;
    Node* del=nullptr;
    while(curr){
        del=curr;
        curr=curr->next;
        delete del;
    }
    head=nullptr;
    tail=nullptr;
    //IMPLEMENT THIS
}


// return sum of values in list
int IntList::sum() const {
    int sum=0;
    Node* curr=head;
    while(curr){
        sum+=curr->info;
        curr=curr->next;
    }
    return sum; // REPLACE THIS NON-SOLUTION
}

// returns true if value is in the list; false if not
bool IntList::contains(int value) const {
    Node* curr=head;
    while(curr){
        if(curr->info==value)
            return true;
        curr=curr->next;
    }
    return false; // REPLACE THIS NON-SOLUTION
}

// returns maximum value in list, or 0 if empty list
int IntList::max() const {
    if(head==nullptr)
        return 0;
    int max=head->info;
    Node* curr=head;
    while(curr){
        if(curr->info>=max)
            max=curr->info;
        curr=curr->next;
    }
    return max; // REPLACE THIS NON-SOLUTION
}

// returns average (arithmetic mean) of all values, or
// 0 if list is empty
double IntList::average() const {
    if(head==nullptr)
        return 0.0;
    double num=0.0;
    double sum=0.0;
    Node* curr=head;
    while(curr){
        sum+=curr->info;
        num++;
        curr=curr->next;
    }
    return sum/num; // REPLACE THIS NON-SOLUTION
}

// inserts value as new node at beginning of list
void IntList::push_front(int value) {
    Node* n=new Node{value, head};
    head=n;

    if(tail==nullptr)
        tail=head;
}

// append value at end of list
void IntList::push_back(int value) {
    if(head==nullptr){
        Node* h=new Node{value, nullptr};
        head=tail=h;}
    else{
    Node* n=new Node{value, nullptr};
    tail->next=n;
    tail=n;

}
 
}

// return count of values
int IntList::count() const {
    int n=0;
    Node* curr=head;

    while(curr){
        n++;
        curr=curr->next;
    }
    
   //IMPLEMENT THIS
   return n;
}


//Assignment operator should copy the list from the source
//to this list, deleting/replacing any existing nodes
IntList& IntList::operator=(const IntList& source){
    if (this == &source)
        return *this;

    Node* curr = head;
    while (curr) {
        Node* next = curr->next;
        delete curr;
        curr = next;
    }
    head=nullptr;
    tail=nullptr;

    Node* c=source.head;
    while(c){
        push_back(c->info);
        c=c->next;
    }
    return *this;
}

// constructor sets up empty list
IntList::IntList(){ 
    head=nullptr;
    tail=nullptr;
    //IMPLEMENT THIS 
}


// DO NOT CHANGE ANYTHING BELOW (READ IT THOUGH)

// print values enclose in [], separated by spaces
void IntList::print() const {
    Node *n = head;
    cout << '[';
    while (n) {
        cout << n->info;
        if (n->next)
            cout << " ";
        n = n->next;
    }
    cout << ']';
}

