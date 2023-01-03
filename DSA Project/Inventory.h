//
// Created by Yahya on 12/16/2022.
//

#ifndef DSA_PROJECT_INVENTORY_H
#define DSA_PROJECT_INVENTORY_H
#include "IEntity.h"
#include "Item.h"
#include "Product.h"
#include <iostream>
#include <iomanip>
#include <vector>
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
    void updateItemName(int itemID,std::string productName);
    void updateItemQuantity(int itemID,int quantity);


    bool doesItemExistInInventory(int itemID);

    Item * getHeadOfList();

    int getTotalQuantityOfItemsInInventory();


    void decrementItemQuantityAfterCheckout(const std::vector<Product>& products);

    const std::string getClassId() const;

    int getTotalItemsInInventory() const;

    void updateItemPrice(int itemID, float price);
};


#endif //DSA_PROJECT_INVENTORY_H
