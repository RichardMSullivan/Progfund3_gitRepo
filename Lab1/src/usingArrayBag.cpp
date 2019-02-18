#include <iostream>
#include <string>
#include "ArrayBag.h"

using namespace std;

/*
Program allows you to:
-----------------------------------------------------------------------------------------.
    add items                                                                             |
        allows you to add up to 20 items                                                  |
                                                                                          |
        does not allow duplicate items                                                    |
                                                                                          |
        items that are added will be inserted in numerical order (least to greatest)      |
            achieved with bubble sort                                                     |
------------------------------------------------------------------------------------------|
    remove items                                                                          |
        allows you to remove an item that is found in the list                            |
------------------------------------------------------------------------------------------|
    search for items                                                                      |
        allows you to search to see if the list contains the searched item                |
            you may chose to search for the item with a recursive or an itterative search |
                                                                                          |
        allows you to search to see what item is at a given index value                   |
------------------------------------------------------------------------------------------|
    display items                                                                         |
        displays each item in the list with its corresponding index value                 |
-----------------------------------------------------------------------------------------"
*/          

void bagSorter(ArrayBag<int>& bag);
bool binarySearchRepetition(vector<int>& bag, int size, int searchValue);
bool binarySearchRecursive(vector<int>& bag, int first, int last, int searchValue);
void displayBag(ArrayBag<int>& bag);
void displayMainMenu();
void displayAddMenu();
void displaySearchMenu();
void displaySearchSubMenu();
void clearScreen();
void displayBagContents(ArrayBag<int> &bag);

int main()
{   
	bool QUIT = false; //flag used to navigate menus and quit the application

    std::string INPUT; //holds user input

    int INT_INPUT; //holds number inputs

    ArrayBag<int> arrayBag;//create an empty bag the user can use

    
    // Main Menu loop //
    while(!QUIT){
        
        clearScreen(); //show menu
        displayMainMenu();
        cin>>INPUT; // take input

        if(INPUT == "quit"){ //if quit (main menu)

            QUIT = true;

        } // end if quit

        else if(INPUT == "1"){ // if option 1 (main menu)
            
            clearScreen();
            
            // Add Menu loop
            while(!QUIT){

                displayAddMenu();//show menu (add menu)
                cin>>INPUT;//take in input
                cin.ignore();
                clearScreen();

                if(INPUT == "back"){ // if quit (add menu)
                    QUIT = true;
                }// end if quit (add menu)

                else if(INPUT == "1"){//add item to bag
                    
                    //if you can add an iitem 
                    if( arrayBag.canAdd()){
                        std::cout<<"enter the number you would like to add: "<<std::endl;//take in input
                        std::cin>>INT_INPUT;
                        clearScreen();
                        if(arrayBag.add(INT_INPUT)){//if not already in the bag
                            std::cout<<INT_INPUT<<" added to the bag."<<std::endl;
                        }
                        else{//if already in the bag
                            std::cout<<INT_INPUT<<" is already in the bag."<<std::endl;
                        }
                    }

                    //if you can not add an item
                    else{
                        std::cout<<"sorry not enough room in the bag"<<std::endl;
                    }

                    std::cout<<"press enter to continue...";

                    cin.ignore();
                    cin.get();

                }// end of add item to bag
                
                else if (INPUT == "2"){//delete item from bag

                    std::cout<<"enter the number you would like to delete..."<<std::endl;
                    std::cin>>INT_INPUT;

                    //if you can remove the item
                    if(arrayBag.remove(INT_INPUT)){
                        clearScreen();
                        std::cout<<"item removed"<<std::endl;
                    }
                    //if you can nat add the item
                    else{
                        clearScreen();
                        std::cout<<"item not found..."<<std::endl;
                    }
                    
                    std::cout<<"press enter to continue..."<<std::endl;
                    std::cin.ignore();
                    std::cin.get();

                }//end delete item from bag

                // if input does not equal 1 or 2
                else{
                //do nothing
                }
                
                clearScreen();

            }// end add menu loop

            bagSorter(arrayBag); // after item added sort bag
            QUIT = false; // after quitting add menu set quit to false to prevent quitting applicaion

        } // end if option 1 (main menu)
        
        else if(INPUT == "2"){ // if option 2 (main menu)

            clearScreen();
            
            // search menu loop
            while(!QUIT){

                displaySearchMenu();//display search menu
                
                cin>>INPUT;//take in input
                cin.ignore();

                clearScreen();
                
                if(INPUT == "back"){ // if back (search  menu)
                    QUIT = true;
                }//end if quit (search menu)

                // if option 1 (search menu)
                else if(INPUT == "1"){

                    clearScreen();
                    
                    displaySearchSubMenu(); //display search submenu

                    std::cin>>INPUT;// take in input
                    
                    // if option 1 (search submenu)
                    if(INPUT == "1"){

                        clearScreen();
                        std::cout<<"enter the item you want to search..."<<std::endl;

                        std::cin>>INT_INPUT;//take in input
                        cin.ignore();

                        vector<int> bagVec = arrayBag.toVector();//create vector of bag to put in search function

                        //if binary search of item in bag is successful
                        if(binarySearchRepetition( bagVec, arrayBag.getCurrentSize(), INT_INPUT)){
                            std::cout<<"item found!"<<std::endl;
                        }
                        // if binary search of item in bag is not successful
                        else{
                            std::cout<<"item not found..."<<std::endl;
                        }

                        cin.get();

                    }// end if option 1 (search submenu)

                    // if option 2 (search submenu)
                    else if(INPUT == "2"){

                        clearScreen();
                        std::cout<<"enter the item you want to search..."<<std::endl;

                        std::cin>>INT_INPUT;// take in input
                        cin.ignore();
                        
                        vector<int> bagVec = arrayBag.toVector();//create vector of bag to put in search function
                        
                        // if recursive search of item is successful
                        if(binarySearchRecursive( bagVec, 0, arrayBag.getCurrentSize() - 1, INT_INPUT)){
                            std::cout<<"item found!"<<std::endl;
                        }
                        // if recursive search of item is not successful
                        else{
                            std::cout<<"item not found..."<<std::endl;
                        }

                        cin.get();

                    }// if option 2 (search submenu)

                }// end if option 1 (search menu)
                else if(INPUT == "2"){// option 2 (search menu)
                    clearScreen();
                    std::cout<<"enter the index number you want to see the contents of..."<<std::endl;

                    std::cin>>INT_INPUT;//take in input
                    std::cin.ignore();
                    
                    if (INT_INPUT >= 0 && INT_INPUT < arrayBag.getCurrentSize()){ //if index is positive and has a value
                        
                        clearScreen();

                        std::cout<<"index: "<<INT_INPUT<<" contains the value "<<arrayBag.getItem(INT_INPUT);// show item at index
                    }
                    else{ // if invalid index
                        clearScreen();
                        std::cout<<"no item at index: "<<INT_INPUT<<std::endl; // show index is invalid
                    }
                    std::cin.get();

                }
                // if input does not match any option (search menu)
                else{
                    // do nothing
                }

                clearScreen();
                
            }// end search menu loop
            QUIT = false;

        }// end if option 2 (main menu)

        else if(INPUT == "3"){// if option 3 (mian menu)

            // display items
            clearScreen();
            displayBagContents(arrayBag);
            std::cin.ignore();
            std::cin.get();

        }//end if option 3 (main menu)

        else{ // default
            clearScreen();
        } //end default

    } //end main menu loop

	
   return 0;
   
}  // end main function


// Sorts bag in ascending order
void bagSorter(ArrayBag<int>& bag)
{
    if(bag.getCurrentSize() > 1){//if the bag is larger than 1

        for(int i = bag.getCurrentSize(); i>0; i--){//for every item in the bag
                for(int j=0; j<i-1 ;j++ ){//go through each item until index of the last item - number of times process is performed
                   
                   //if left item is larger than right item
                   if(bag.getItem(j)>bag.getItem(j+1)){

                        bag.swap(j,j+1);//swap the items

                    }//end if

                }//end for loop j
            }//end for loop i

    }//end if bag is larger than 1

} // end bagSorter


// Searches for a value in the ArrayBag
// @ returns true if the item is found and false if not
bool binarySearchRepetition(vector<int>& bag, int size, int searchValue)
{
    bool found = false;
    int start = 0;
    int end = size -1;
    int middle = (start + end)/2;

    while(start <= end && found != true){//binary search loop
        if(bag[middle] == searchValue){//if the item between start and end is the item
            found = true;
        }
        if(bag[middle] < searchValue){//if the item between start and end is less than the searched item
            start = middle +1;//the middle becomed the new starting point
            middle = (start + end)/2;//recalculate the middle
        }
        if(bag[middle] > searchValue){//if the item between the start and end is more than the searched item
            end = middle -1;//the middle becomes the new end point
            middle = (start+end)/2;//recalculate the middle
        }

    }//end binary search loop

    return found;
} // end binarySearchRepetition

//searches for a value in the ArrayBag
// @ returns true if the item is found and false if not
bool binarySearchRecursive(vector<int>& bag, int first, int last, int searchValue)
{
    int middle = (first + last)/2;//calculate middle value

    if(first > last){//if the first index looked at is not less than or equal to the end
        return false; // item not found
    }
    else if(bag[middle]==searchValue){//if the middle is equal to the search value
        return true; // item found
    }
    else if(bag [middle] < searchValue){//if the middle is less than the search value
        return binarySearchRecursive(bag,middle+1,last,searchValue); //start becomes new middle
    }
    else if(bag [middle] > searchValue){//if the middle is more than the search value
        return binarySearchRecursive(bag,first,middle-1,searchValue); // end becomes new middle
    }
    else{//default
        return false;
    }
} // end binarySearchRecursive
			
//shows the items in the ArrayBag on the screen
void displayBagContents(ArrayBag<int>& bag)
{  
    vector<int> bagVec = bag.toVector();// get items in a vector
        std::cout<<"-----------------------------------"<< std::endl;
    for(int i=0 ; i < bagVec.size() ; i++){ // for each item in the vector cout the index and then item number
        std::cout<<"item index : " << i << std::endl;
        std::cout<<"item number: " << bagVec[i] << std::endl;
        std::cout<<"-----------------------------------"<< std::endl;
    }
        std::cout<<"\npress enter to go exit.";
}  // end displayBag

//displays the main menu
void displayMainMenu(){
    std::cout<<".--------------------------------------."<<std::endl;
    std::cout<<":                MAIN MENU             :"<<std::endl;
    std::cout<<":--------------------------------------:"<<std::endl;
    std::cout<<": 1: ADD / DELETE                      :"<<std::endl;
    std::cout<<":--------------------------------------:"<<std::endl;
    std::cout<<": 2: SEARCH                            :"<<std::endl;
    std::cout<<":--------------------------------------:"<<std::endl;
    std::cout<<": 3: DISPLAY BAG CONTENTS              :"<<std::endl;
    std::cout<<":--------------------------------------:"<<std::endl;
    std::cout<<":'quit': QUIT APPLICATIN               :"<<std::endl;
    std::cout<<"'--------------------------------------'"<<std::endl;
}
// displays the menu that allows you to add items to the ArrayBag
void displayAddMenu(){
    std::cout<<".--------------------------------------."<<std::endl;
    std::cout<<":                ADD MENU              :"<<std::endl;
    std::cout<<":--------------------------------------:"<<std::endl;
    std::cout<<": 1: ADD ITEM TO BAG                   :"<<std::endl;
    std::cout<<":--------------------------------------:"<<std::endl;
    std::cout<<": 2: DELETE ITEM FROM BAG              :"<<std::endl;
    std::cout<<":--------------------------------------:"<<std::endl;
    std::cout<<":'back': GO BACK TO MAIN MENU          :"<<std::endl;
    std::cout<<"'--------------------------------------'"<<std::endl;

} // end displayAddMenu

// displays the menu that allows you to search for items in the ArrayBag
void displaySearchMenu(){
    std::cout<<".--------------------------------------."<<std::endl;
    std::cout<<":              SEARCH  MENU            :"<<std::endl;
    std::cout<<":--------------------------------------:"<<std::endl;
    std::cout<<": 1: DOES BAG CONTAIN ITEM             :"<<std::endl;
    std::cout<<":--------------------------------------:"<<std::endl;
    std::cout<<": 2: ITEM AT INDEX VALUE               :"<<std::endl;
    std::cout<<":--------------------------------------:"<<std::endl;
    std::cout<<":'back': GO BACK TO MAIN MENU          :"<<std::endl;
    std::cout<<"'--------------------------------------'"<<std::endl;

} // end displaySearchMenu

// displays options for how you want to search for an item
void displaySearchSubMenu(){

    std::cout<<".--------------------------------------."<<std::endl;
    std::cout<<":              SEARCH  TYPE            :"<<std::endl;
    std::cout<<":--------------------------------------:"<<std::endl;
    std::cout<<": 1: ITTERATIVE                        :"<<std::endl;
    std::cout<<":--------------------------------------:"<<std::endl;
    std::cout<<": 2: RECURSIVE                         :"<<std::endl;
    std::cout<<":--------------------------------------:"<<std::endl;
    std::cout<<":'back': GO BACK TO SEARCH MENU        :"<<std::endl;
    std::cout<<"'--------------------------------------'"<<std::endl;
 }// end displaySortSubMenu


// clears the screen
void clearScreen(){
    //lots of newlines to "clear the screen"
    for(int i=0; i<10; i++){
        std::cout<<"\n\n\n\n\n\n\n\n\n\n";
    } // end for()

} // end clearScreen()



