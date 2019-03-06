
/*application creates a stack which you can populate with items
  an item holds two strings: name and color
  
  to use the application you enter the option you want to perform by typing the option number and pressing enter
  then follow the prompts to complete the aciton
  
  push item to stack - allows you to input an item name and color and then adds that item to the stack
  peek at top item - allows you to see the topmost item in the stack
  is empty - allows you to check if the stack is empty
  pop item - allows you to remove the topmost item in the stack
  */

#include "item.h"
#include "stack.h"
#include <iostream>

void displayMainMenu();

template<typename T>
void push(Stack<T> &stack);

template<typename T>
void peek(Stack<T> &stack);

template<typename T>
void empty(Stack<T> &stack);

template<typename T>
void pop(Stack<T> &stack);

void clearScreen();

//start main function
int main(int argc, char** argv){
    Stack<Item> stack;
    Stack<Item>* stackPtr = &stack;

    std::string input;
    bool quit = false;
    while(!quit){//start application

        clearScreen();
        displayMainMenu();//dislay menu

        std::cin>>input;//take in input

        clearScreen();
        if(input == "1"){//if input is to push

            push(stack);//push to the stack

            std::cin.ignore();
            std::cin.get();
        }
        else if(input == "2"){//if input is to peek

            peek(stack);//peek the first item in the stack

            std::cin.ignore();
            std::cin.get();
        }
        else if(input == "3"){//if input is to check if stack is empty

            empty(stack);//ceck if stack is empty

            std::cin.ignore();
            std::cin.get();
        }
        else if(input == "4"){//if input is to pop

            pop(stack);//pop an item form the stack

            std::cin.ignore();
            std::cin.get();
        }
        else if(input == "5"){
            quit = true;
        }
        else{//if the input is invalid
            std::cout<<"invalid input. to select an option, press the corresponding option number.\
                        \n press enter to continue..."<<std::endl;//let the user know

            std::cin.ignore();
            std::cin.get();
        }

    }//end application
    
    return 0;

}//end main function


void displayMainMenu(){
    std::cout<<" .-----------------------. "<<std::endl;
    std::cout<<"|        MAIN MENU        |"<<std::endl;
    std::cout<<" :-----------------------: "<<std::endl;
    std::cout<<"| 1. PUSH ITEM TO STACK   |"<<std::endl;
    std::cout<<"| 2. PEEK AT TOP ITEM     |"<<std::endl;
    std::cout<<"| 3. CHECK IF  EMPTY      |"<<std::endl;
    std::cout<<"| 4. POP ITEM             |"<<std::endl;
    std::cout<<"| 5. QUIT                 |"<<std::endl;
    std::cout<<" '-----------------------' "<<std::endl;
}

template<typename T>
void push(Stack<T> &stack){
    
    std::string name;//name to hold item name
    std::string color;//color to hold item color
    std::cout<<"what is the name of your item?"<<std::endl;
    std::cin>>name;//set item name
    std::cout<<"what is the color of your item?"<<std::endl;
    std::cin>>color;//set item color

    Item item(name, color);//create item

    if(stack.push(item)){;//push item to stack

        std::cout<<"your item has been pushed to the stack.";
    }
    else{
        std::cout<<"the stack is full.";
    }
    std::cout<<"\n\npress enter to continue...";
}
template<typename T>
void peek(Stack<T> &stack){
    
    if(stack.peek()){//if you can peek
        std::cout<<"is the top item in the stack.";//tell what they see
    }
    else{//if not
        std::cout<<"the stack is empty.";//they see nothing
    }

    std::cout<<"\n\npress enter to continue...";
}
template<typename T>
void empty(Stack<T> &stack){
    
    if(stack.isEmpty()){//if the stack is empty
        std::cout<<"the stack is empty";//tell the stack is empty
    }
    else{//if stack not empty
        std::cout<<"the stack is not empty";//tell the stack is not empty
    }

    std::cout<<"\n\npress enter to continue...";

}
template<typename T>
void pop(Stack<T> &stack){
    
    if(!stack.isEmpty()){//if the stack is not empty
        Item item = stack.pop();//remove item from stack
        std::cout<<item<<" has been removed from the stack.";//tell what item was removed
    }
    else{
        stack.pop();// if nothing in the stack the pop function prints  "stack empty"
    }
    
    std::cout<<"\n\npress enter to continue...";
}

void clearScreen(){
    for (int i=0; i<10; i++){//lots of newlines
        std::cout<<"\n\n\n\n\n\n\n\n\n\n";
    }
}



