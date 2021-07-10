#include <iostream>
class Node{
    public:
        int elem;
        Node* next;
        Node();
        Node(int,Node*);
        //Getters
        int getElem()const;
        Node* getNext()const;
        //Setters
        void setElem(int);
        void setNext(Node*);
};
Node::Node(){
    elem = 0;
    next = NULL;
}
Node::Node(int elem,Node* next){
    this->elem = elem;
    this->next = next;
}
int Node::getElem()const{
    return elem;
}
Node* Node::getNext()const{
    return next;
}
void Node::setElem(int elem){
    this->elem = elem;
}
void Node::setNext(Node* next){
    this->next = next;
}