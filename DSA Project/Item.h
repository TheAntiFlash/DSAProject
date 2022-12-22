//
// Created by Yahya on 12/11/2022.
//

#ifndef DSA_PROJECT_NODE_H
#define DSA_PROJECT_NODE_H
#include <string>
#include "Inventory.h"

class Item{
private:
    int itemID;
    std::string productName;
    int quantity;
    float price;

    friend class Inventory;
public:
    Item* next;
    Item* prev;

    Item();

    Item(int itemId, std::string productName, int quantity, float price);

    int getItemID();

    const std::string &getProductName() const;

    int getQuantity() const;

    float getPrice() const;
};


#endif //DSA_PROJECT_NODE_H
