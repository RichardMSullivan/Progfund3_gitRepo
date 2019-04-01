
#define NDEBUG

#include <cassert> //debugging
#include <cstdlib> // exit success

#include <fstream> //input and output form files
#include <iostream> //input and output from termial

#include "linkedList.h" //linked list adt

#define FILENAME "file.txt" //file to be opened

int main(){

    std::string fileLine;//string to hold info from the file

    std::ifstream fin;

    //open file to be read from
    fin.open( FILENAME );
    assert(fin.is_open());
    //create a linked list
    LinkedList list;
    
    //return seperate strings for all the lines in the file
    while(!fin.eof()){
        
        //for every string returned add a node in the linked list that holds the teturned string
        getline(fin,fileLine);
        
        list.addNode(fileLine);
    }
    //close the file
    fin.close();

    //print the linked list
    std::cout<< "\n";
    list.print();

    //remove all the duplicate items in the linked list
    list.removeDuplicates();
    std::cout<< "\n\n";

    //print the linked list
    list.print();
    std::cout << "\n";

    return EXIT_SUCCESS;
}
