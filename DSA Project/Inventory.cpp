//
// Created by Yahya on 12/16/2022.
//

#include "Inventory.h"

Inventory::Inventory() {
    head = nullptr;
    size = 0;

}

void Inventory::insert(int itemID, std::string productName, int quantity, float price) {

    if(head == nullptr){
        head = new Item;
        head->itemID = itemID;
        head->price = price;
        head->quantity = quantity;
        head->productName = productName;
        head->next = nullptr;
        head->prev = nullptr;

    }
    else{
        Item * trav = head;
        while(trav->next != nullptr){
            trav = trav->next;
        }
        trav->next = new Item();
        trav->next->prev = trav;
        trav = trav->next;
        trav->price = price;
        trav->quantity = quantity;
        trav->productName = productName;
        trav->itemID = itemID;
        trav->next = nullptr;

    }
    size++;
}

void Inventory::displayInventory() {
    Item * trav;
    trav = head;

    while(trav!= nullptr){
        std::cout << "ID: " << trav->itemID << "\tProduct Name: " << trav->productName
                  << "\tQuantity: " << trav->quantity << "\tPrice: " << std::setprecision(7) <<trav->price;
        std::cout << std::endl;
        trav = trav->next;
    }

}

const std::string Inventory::getClassId() const {
    const std::string name = "Inventory";
    return name;
}

int Inventory::getTotalItemsInInventory() const {
    return size;
}

Item Inventory::getItemFromId(int itemID) {
    Item * trav = head;
    while(trav != nullptr){
        if(trav->itemID == itemID){
            //std::cout << trav->itemID << trav->productName << trav->price;
            return *trav;
        }
        trav = trav->next;
    }
    std::cout << "Invalid item ID";
    return *(new Item());
}

Item *Inventory::getHeadOfList() {
    return head;
}

void Inventory::deleteItem(int itemID) {
    Item * trav = head;

    while(trav != nullptr){
        if(trav->itemID == itemID){
            break;
            std::cout << "this ran";
        }
        trav = trav->next;
    }
    if(trav->prev != nullptr){
        trav->prev->next = trav->next;
    }
    else{
        head = head->next;
    }
    if(trav->next != nullptr){
        trav->next->prev = trav->prev;
    }
    else{
        trav = nullptr;
    }
    free(trav);
}

bool Inventory::doesItemExistInInventory(int itemID) {
    Item *trav = head;
    bool itemIdExists = false;

    while(trav != nullptr){
        if(itemID == trav->getItemID()){
            itemIdExists = true;
        }
        trav = trav->next;
    }
    return itemIdExists;
}
