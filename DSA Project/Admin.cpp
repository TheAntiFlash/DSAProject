//
// Created by Yahya on 12/11/2022.
//

#include "Admin.h"
Admin::Admin()
{
    //empty constructor
}

void Admin::displayList()
{
    std::cout<<"\n\t\tWelcome to Admin Portal.";
    std::cout<<"\n\n\tSelect from Options given below: ";
    std::cout<<"\n\n1)Add to Inventory.";
    std::cout<<"\n\n2)Delete From Inventory.";
    std::cout<<"\n\n3)Display Transaction History.";
    std::cout<<"\n\n4)Display Inventory";
    std::cout<<"\n\n5)Edit inventory.";
    std::cout<<"\n\n6)Exit Portal";
    std::cout<<"\n\nEnter your Choice -> ";
}
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
            dl.update(inventory);
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
    if(isLoggedIn) {
        if (inventory->doesItemExistInInventory(itemID)) {
           std::cout<<"Select option to edit "<<std::endl
                <<"1-Product name "<<std::endl
                <<"2-Price "<<std::endl
                <<"3-Quantity "<<std::endl;
           int choice;
           std::cout<<"choice: ";
           std::cin>>choice;
           while(choice>3 || choice<1){
               std::cout<<"Enter a number between 1-3: ";
               std::cin>>choice;
           }
           if(choice==1){
               std::string Pname;
               std::cout<<"Enter new Product Name: ";
               std::cin>>Pname;
               inventory->updateItemName(itemID,Pname);
           }
           else if(choice==2){
               float Price;
               std::cout<<"Enter new Product Price: ";
               std::cin>>Price;
               inventory->updateItemPrice(itemID,Price);
           }else{
               int Quantity;
               std::cout<<"Enter new Product Quantity : ";
               std::cin>>Quantity;
               inventory->updateItemQuantity(itemID,Quantity);
           }
            DataLayer dl;
            dl.update(inventory);

        }
        else{
            std::cout << "\n\t*********ERROR**********"
                         "\n\tItem ID DOES NOT Exist";
        }
    }



}

void Admin::deleteItemFromInventory(Inventory * inventory, int itemID) {
    if(isLoggedIn) {
        if (inventory->doesItemExistInInventory(itemID)) {
            inventory->deleteItem(itemID);
            DataLayer dl;
            dl.update(inventory);
        }
        else{
            std::cout << "\n\t*********ERROR**********"
                         "\n\tItem ID DOES NOT Exist";
        }
    }
}

void Admin::displayTransactionHistory(Inventory * inventory, TransactionHistory *transactionHistory) {
    transactionHistory->displayTransactionHistory(inventory);
}

bool Admin::signUp(std::string username, std::string password) {
    return User::signUp(true, username, password);

}




