
#include "item.h"

Item::Item(){ // defaults both name and color to empty strings
    itemName = "";
    itemColor = "";
}

Item::Item(std::string itemName, std::string itemColor){
    this->itemName = itemName; // item name = inputted name
    this->itemColor = itemColor; // item color = inputted color
}

Item::~Item(){
    //nothing extra needed to delete the item
}


std::ostream &operator << (std::ostream &stream, Item &item){//allows you to cout an item

    stream<< item.itemName << ", "<< item.itemColor;// creates a stream containing the name and color

    return stream;//returns stream
}


