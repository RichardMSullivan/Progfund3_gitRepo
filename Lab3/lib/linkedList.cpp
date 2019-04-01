#include "linkedList.h"

void LinkedList::addNode(std::string data){
    if (headPtr == NULL){
        std::shared_ptr <Node> n = std::make_shared <Node>();
        headPtr = n;
        
        headPtr -> setData(data);
        headPtr -> setNext(NULL);
    }
    else{
        currentPtr = headPtr;

        std::shared_ptr <Node> n = std::make_shared<Node>();
        headPtr = n;

        headPtr -> setData(data);
        headPtr -> setNext(currentPtr);
    }

    itemCount ++;

}

void LinkedList::removeNextNode(std::shared_ptr<Node> n){
    n-> setNext(n->getNext()->getNext());

}

void LinkedList::removeDuplicates(){
    int i = 0;
    while(i < (this->itemCount-1)){
//        std::cout << this->itemCount-2 <<std::endl;
        int count = 0;
       
        currentPtr = headPtr;
        tmpPtr = NULL;

        bool itemDeleted = false;
        while(currentPtr->getNext()){
            //std::cout<<"count: "<<count<<" i: "<<i<<std::endl;
            if(count == i){
                tmpPtr = currentPtr;
            }
            if(tmpPtr){
                if((tmpPtr->getData()) == currentPtr->getNext()->getData()){
                    //std::cout<<"tmp=  "<<tmpPtr->getData()<<" "
                      //       <<"curr= "<<currentPtr->getNext()->getData()
                        //     <<"\n"<<count<<std::endl;
                    
                    currentPtr->setNext(currentPtr->getNext()->getNext());
                    this->itemCount --;

                    itemDeleted = true;

                }
            }
            if(currentPtr->getNext() && (itemDeleted == false)){
                count ++;
                currentPtr = currentPtr->getNext();
            }
            itemDeleted = false;
        }
        i ++;
    }
}

void LinkedList::print(){
    currentPtr = headPtr;
    
    if(headPtr != NULL){
        while(currentPtr){
            std::cout<< currentPtr -> getData() << "\n";
            currentPtr = currentPtr -> getNext();
        }
    }
    else{
        std::cout<<"the list is empty"<<std::endl;
    }

}
