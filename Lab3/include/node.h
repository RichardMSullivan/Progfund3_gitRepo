#pragma once

#include <memory>
#include <string>
#include <iostream>

class Node{

    private:

        std::shared_ptr<Node> next;
        std::string data = "";

    public:
        //getters
        std::string getData();
        std::shared_ptr<Node> getNext();
        
        //setters
        void setNext(std::shared_ptr<Node> n);
        void setData(std::string);

        //constructors
        ~Node();

};
