#pragma once
#include <iostream>
#include <string>

/*Item type holds a name and a color, both are of the type string*/
class Item{

    private:
        std::string itemName;
        std::string itemColor;

    public:
        //constructors
        Item();
        Item(std::string itemName, std::string itemColor);
        
        //deconstructor
        ~Item();

        //<< operator prints the name and the color
        friend std::ostream &operator << (std::ostream &stream, Item &item);
};


