#include "node.h"

Node::~Node(){
//    std::cout<<this->data<<" destroyed..."<<std::endl;
}

std::string Node::getData(){
    return this->data;
}

std::shared_ptr <Node> Node::getNext(){
    return this->next;
}

void Node::setNext(std::shared_ptr <Node> n){
    this->next = n;

}

void Node::setData(std::string data){
    this->data = data;

}
