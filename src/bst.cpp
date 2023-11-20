#include <iostream>

class Node {
public:
    int val;
    Node* lChild;
    Node* rChild;
    Node(){
        this->lChild = NULL;
        this->rChild = NULL;
    }
};

void addEl(Node* parent, int val){

    if(val <= parent->val){
        if(parent->lChild == NULL){
            Node* newNode = new Node;
            newNode->val = val;
            parent->lChild = newNode;
            return;
        }
        addEl(parent->lChild, val);
    }
    else if(val > parent->val){
        if(parent->rChild == NULL){
            Node* newNode = new Node;
            newNode->val = val;
            parent->rChild = newNode;
            return;
        }
        addEl(parent->rChild, val);
    }
}

int* accessVal(Node* parent, int val){
    static int* retVal =  &parent->val;
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

Node* accessNode(Node* parent, int val){
    static Node* retVal = parent;
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

int main () {
    
    Node* parent = new Node;
    parent->val = 5;
    addEl(parent, 2);
    addEl(parent, 7);
    addEl(parent, 3);
    addEl(parent, 1);
    addEl(parent, 6);
    addEl(parent, 8);
    Node* test = accessNode(parent, 2);
    std::cout << test->val << "\n";

    
    return 0;
}
