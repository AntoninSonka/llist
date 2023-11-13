#include <iostream>

namespace ll {

class Node {
public:
    int val;
    Node* next;
};

void push_back(Node* head, int val){
    if(head->next == NULL){
        head->next = new Node;
        head->next->val = val;
        return;
    }
    push_back(head->next, val);
}

void pop_back(Node* head){
    if(head->next->next == NULL){
        delete head->next;
        head->next = NULL;
        return;
    }
    pop_back(head->next);
}

void print_llist(Node* head){
    std::cout << head->val << "\n";
    if(head->next == NULL){
        return;
    }
    print_llist(head->next);
}

void delete_llist(Node* head){
    if(head->next == NULL){
        delete head;
        return;
    }
    delete_llist(head->next);
    delete head;
}

int find(Node* head, int val){
    static int index = 0;
    if(head->val == val){
        return index;
    }
    else if(head->next == NULL){
        return -1;
    }
    index++;
    find(head->next, val);
    return index;
}
};

int main () {
    ll::Node* head = new ll::Node;
    head->next = NULL;
    head->val = 10;
    ll::push_back(head, -10);
    ll::push_back(head, 0);
    ll::print_llist(head);
    std::cout << "\n";
    ll::pop_back(head);
    ll::push_back(head, -20);
    ll::push_back(head, -100);
    ll::print_llist(head);
    std::cout << "\n";
    std::cout << ll::find(head, -100) << "\n";
    ll::delete_llist(head);
    return 0;
}
