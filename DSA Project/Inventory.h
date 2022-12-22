//
// Created by Yahya on 12/16/2022.
//

#ifndef DSA_PROJECT_INVENTORY_H
#define DSA_PROJECT_INVENTORY_H
#include "IEntity.h"
#include "Item.h"
#include <iostream>
#include <iomanip>
class Item;
class Inventory : public IEntity {
private:
    Item * head;
    int size;
public:
    Inventory();

    /**
     * will insert to the linked list that is Inventory. Function should in theory only be called from class DataLayer or from Admin.
     * @param itemID
     * @param productName
     * @param quantity
     * @param price
     */
    void insert(int itemID, std::string productName,int quantity,float price);

    /**
     * Deletes the item from list with the same itemID as the parameter
     * @param itemID
     */
    void deleteItem(int itemID);

    /**
     * Function takes itemID as input and returns the Item obj which includes, itemID, productName, Quantity (in inventory) and price
     * @param itemID private member of obj item
     * @return obj of class Item
     */
    Item getItemFromId(int itemID);

    /**
     * displays all arr in linkedList Inventory
     */
    void displayInventory();

    bool doesItemExistInInventory(int itemID);

    Item * getHeadOfList();

    const std::string getClassId() const;

    int getTotalItemsInInventory() const;
};


#endif //DSA_PROJECT_INVENTORY_H
