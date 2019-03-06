
#pragma once

template<typename T>
class Stack{
    
    private:
        static const int MAX_ITEMS = 100;//maximum number of items that can be stored in the stack

        T stack[MAX_ITEMS];// stack can hold 100 items
        int items;// the number of item in the stack;

    public:
        Stack();// stack constructor
        Stack(int maxItems);//stack constructor
        ~Stack();// stack deconstructor

        /* inserts an item to the top of the stack
         @ returns true if item is added to the stack, false if the stack is full */
        bool push(T &item);

        /* removes an item from the top of the stack
         @ returns the removed item */
        T pop();

        /* couts the item that is on the top of the stack
         @ returns true if there are items in the stack */
        bool peek();

        bool isEmpty(){
            return items == 0;
        }

};

template<typename T>//sets item number to 0
Stack<T>::Stack(){
    this->items = 0;
}

template<typename T>
Stack<T>::~Stack(){

}

template<typename T>
bool Stack<T>::push(T &item){

    bool added = false;//flag added (default is false)

    if (this->items != MAX_ITEMS){//if the number of items in the stack is not the maximum allowed
       
       this->stack[this->items] = item;//add an item to the end of the array
       this->items ++;//increase the number of items by 1
       
       added = true;//added is set to true
    }

    return added;//return if an item was added or not
}

template<typename T>
T Stack<T>::pop(){

    T item;//create a blank item

    if(this->items == 0){//if no items
        
        std::cout<<"stack empty"<<std::endl;//tell user stack is empty
    }
    else{
        
        item = this->stack[(this->items) -1];//create an item and set it to the item to be popped
        
        this->items --;//number of items --
    }

    return item;//return the copy of the popped item
}

template<typename T>
bool Stack<T>::peek(){
    
    int canPeek = false;//flag can peek (default is false)
    
    if(this->items > 0){//if there are items in the stack
        
        std::cout<< this->stack[this->items -1]<< std::endl;//cout item information
        
        canPeek = true;//can peek is true
    }
    
    return canPeek;// return can peek
}


