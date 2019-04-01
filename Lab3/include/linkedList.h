#pragma once

#include <iostream>
#include <memory>//allows use of smart pointers
#include "node.h"

class LinkedList{

    private:
        int itemCount = 0;
        std::shared_ptr<Node> headPtr;//ptr that points to the first item in the list
        std::shared_ptr<Node> currentPtr;//ptr that allows you to look at the nodes in the list
        std::shared_ptr<Node> tmpPtr;//ptr to temporarily store a nodes info
        void removeNextNode(std::shared_ptr<Node> n);//removes the next node in the list

    public:
        void removeDuplicates();//removes nodes with duplicate information
        void addNode(std::string data);//adds a node to the beginning of the list
        void print();//prints all the items in the list
};
