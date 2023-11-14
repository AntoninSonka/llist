#include <cstddef>
#include <iostream>

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

    int findLl(Node<T>* head, int val){
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
        return retVal;
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
        return findLl(this->head, val);
    }

    int set_val(unsigned int index, int val){
        return setVal(this->head, index, val);
    }

    int get_val(unsigned int index){
        return getVal(this->head, index);
    }
};

int main () {
    LinkedList<int> list(1);
    list.push_back(2);
    list.print();
    return 0;
}
