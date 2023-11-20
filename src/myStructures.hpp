#pragma once

#include <cstddef>
#include <iostream>
#include <type_traits>


namespace ms {

namespace ll {

template <typename T>
class Node {
public:
    T val;
    Node* next;
};

template <typename T>
class LinkedList {

private:

    bool hasBeenDeleted = false;

    void pushBack(Node<T>* head, T val){
        if(head->next == NULL){
            head->next = new Node<T>;
            head->next->val = val;
            return;
        }
        pushBack(head->next, val);
    }

    void popBack(Node<T>* head){
        if(head->next->next == NULL){
            delete head->next;
            head->next = NULL;
            return;
        }
        popBack(head->next);
    }

    void printLl(Node<T>* head){
        std::cout << head->val;
        if(head->next == NULL){
            std::cout << "\n";
            return;
        }
        else {
            std::cout << ", ";
        }
        printLl(head->next);
    }

    void deleteLl(Node<T>* head){
        this->hasBeenDeleted = true;
        if(head->next == NULL){
            delete head;
            return;
        }
        deleteLl(head->next);
        delete head;
    }

    int findLl(Node<T>* head, int val, int& index){
        if(head->val == val){
            return index;
        }
        else if(head->next == NULL){
            index = 0;
            return -1;
        }
        index++;
        findLl(head->next, val, index);
        return index;
    }

    int setVal(Node<T>* head, unsigned int index, int val){
        static int retVal = 0;
        static int count = 0;

        if(count == index){
            head->val = val;
            return retVal;
        }

        if(head->next == NULL){
            retVal = 1;
            return retVal;
        }
        count++;
        setVal(head->next, index, val);
        count = 0;
        return retVal;
    }

    int getVal(Node<T>* head, unsigned int index){
        static int retVal = 0;
        static int count = 0;
        if(count == index){
            retVal = head->val;
            return retVal;
        }
        if(head->next == NULL){
            retVal = -1;
            return retVal;
        }
        count++;
        getVal(head->next, index);
        count = 0;
        return retVal;
    }

    void insertOn(Node<T>* head, int index, T val){
        static int count = -1;
        if(index == -2){
            Node<T>* insertedNode = new Node<T>;
            insertedNode->val = val;
            insertedNode->next = head;
            this->head = insertedNode;
            return;
        }
        if(count == index){
            Node<T>* insertedNode = new Node<T>;
            insertedNode->val = val;
            insertedNode->next = head->next;
            head->next = insertedNode;
            return;
        }
        if(head->next == NULL){
            return;
        }
        count++;
        insertOn(head->next, index, val);
        count = -1;
    }

    void removeOn(Node<T>* head, int index){
        static int count = 0;
        if(index == 0){
            this->head->val = this->head->next->val;
            Node<T>* tempNode = head->next->next;
            delete head->next;
            head->next = tempNode;
            return;
        }
        if(count == (index - 1)){
            Node<T>* tempNode = head->next->next;
            delete head->next;
            head->next = tempNode;
            return;
        }

        if(head->next == NULL){
            return;
        }
        count++;
        removeOn(head->next, index);
        count = 0;
    }

public:

    Node<T>* head;
    
    //constructor

    LinkedList(T val){
        head = new Node<T>;
        head->val = val;
    }

    //destructor

    ~LinkedList(){
        if(!hasBeenDeleted){
            deleteLl(this->head);
        }
    }

    //methods
    
    void insert(T val, int index){
        index -= 2;
        insertOn(this->head, index, val);
    }

    void remove(T index){
        removeOn(this->head, index);
    }

    void push_back(T val){
        pushBack(this->head, val);
    }

    void pop_back(){
        popBack(this->head);
    }

    void print(){
        printLl(this->head);
    }

    void delete_llist(){
        deleteLl(this->head);
    }

    int find(int val){
        int index = 0;
        return findLl(this->head, val, index);
    }

    int set_val(unsigned int index, int val){
        return setVal(this->head, index, val);
    }

    int get_val(unsigned int index){
        return getVal(this->head, index);
    }
};

}

namespace bst {

template <typename T>
class Node {
public:
    T val;
    Node* lChild;
    Node* rChild;
    Node(){
        this->lChild = NULL;
        this->rChild = NULL;
    }
};

template <typename T>
class BST {

private:

    Node<T>* parent;

    void addEl(Node<T>* parent, T val){

        if(val <= parent->val){
            if(parent->lChild == NULL){
                Node<T>* newNode = new Node<T>;
                newNode->val = val;
                parent->lChild = newNode;
                return;
            }
            addEl(parent->lChild, val);
        }
        else if(val > parent->val){
            if(parent->rChild == NULL){
                Node<T>* newNode = new Node<T>;
                newNode->val = val;
                parent->rChild = newNode;
                return;
            }
            addEl(parent->rChild, val);
        }
    }

    T* accessVal(Node<T>* parent, T val){
        static T* retVal =  &parent->val;
        if(parent->val == val){
            retVal = &parent->val;
        }
        if(parent->lChild == NULL){
            return nullptr;
        }
        else if(val < parent->val){
            accessVal(parent->lChild, val);
        }
        if(parent->rChild == NULL){
            return nullptr;
        }
        else if(val > parent->val){
            accessVal(parent->rChild, val);
        }

        return retVal;
    }

    Node<T>* accessNode(Node<T>* parent, T val){
        static Node<T>* retVal = parent;
        if(parent->val == val){
            retVal = parent;
        }
        if(parent->lChild == NULL){
            return nullptr;
        }
        else if(val < parent->val){
            accessNode(parent->lChild, val);
        }
        if(parent->rChild == NULL){
            return nullptr;
        }
        else if(val > parent->val){
            accessNode(parent->rChild, val);
        }
        return retVal;
    }

public:

    void add_el(T val){
        addEl(this->parent, val);
    }

    T* access_val(T val){
        return accessVal(this->parent, val);
    }

    Node<T>* access_node(T val){
        return accessNode(this->parent, val);
    }

};

}

}
