//
// Created by Yahya on 12/11/2022.
//

#include "Admin.h"
Admin::Admin(std::string user, std::string pass) {
    isLoggedIn = false;
    username = user;
    password = pass;
    DataLayer dl;
    dl.read(this);
}

const std::string Admin::getClassId() const {
    std::string name = "Admin";
    return name;
}

void Admin::addToInventory(Inventory *inventory, int itemID, std::string productName, int quantity, float price) {
    if(isLoggedIn) {
        if (inventory->doesItemExistInInventory(itemID)) {
            std::cout << "\n\t*********ERROR**********"
                         "\n\tItem ID already Exists"
                         "\n\tItem ID must be unique";
        }
        else {
            inventory->insert(itemID, productName, quantity, price);
            DataLayer dl;
            dl.Update(inventory);
        }
    }
    else{
        std::cout <<"\n\t*******ERROR*******"
                    "\n\t***First Log In***\n";
    }
}

void Admin::editInventory(Inventory *inventory, int itemID) {
    /* You can choose to add the menu here or write the code for functionality. directly edit the inventory linked list and then
     * call the DataLayer function update(inventory).
     * DataLayer dl;
     * dl.update(*inventory);
     */
}

void Admin::deleteItemFromInventory(Inventory * inventory, int itemID) {
    if(isLoggedIn) {
        if (inventory->doesItemExistInInventory(itemID)) {
            inventory->deleteItem(itemID);
            DataLayer dl;
            dl.Update(inventory);
        }
    }
}

void Admin::displayTransactionHistory(Inventory * inventory, TransactionHistory *transactionHistory) {
    transactionHistory->displayTransactionHistory(inventory);
}

bool Admin::signUp(std::string username, std::string password) {
    return User::signUp(true, username, password);

}




