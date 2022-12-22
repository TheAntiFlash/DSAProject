#include <iostream>
#include "Inventory.h"
#include "DataLayer.h"
#include "Admin.h"
#include "Client.h"
#include <ctime>
void function(){
    std::cout << "This function does nothing";
}
int main() {
    srand(time(0));
    function();
    /*
    Checking if inventory is reading correctly
    Inventory inventory;

    DataLayer dl;
    dl.read(&inventory);

    inventory.displayInventory();

     checking if log in system is working correctly

    std::string user = "hashaam";
    std::string pass = "qwe321";
    Admin admin(user, pass);
    std::cout << std::boolalpha << admin.isUserLoggedIn();
    */

    Inventory inventory;
    DataLayer dL;
    dL.read(&inventory);

    TransactionHistory transactionHistory;
    DataLayer dl;
    dl.read(&transactionHistory);

    //Client::signUp("danish", "flashy123");
    //Admin::signUp("ahmed","lkj123");


    /*
    std::string user = "faizan";
    std::string pass = "qwe321";
    Client client(user, pass);
    //std::cout << std::boolalpha << client.isUserLoggedIn();
    //std::cout << inventory.getTotalItemsInInventory();
    client.createCart(inventory.getTotalItemsInInventory());
     //made this comment
    client.addToCart(1);
    client.addToCart(1);
    client.addToCart(2);
    client.addToCart(2);
    client.addToCart(2);
    client.checkout(&inventory, &transactionHistory);

    //transactionHistory.displayTransactionHistory(&inventory);

    Inventory inventory;
    inventory.displayInventory();
    DataLayer dL;
    dL.read(&inventory);
    std::string user = "yahya";
    std::string pass = "abc123";

    Admin admin(user, pass);

    admin.deleteItemFromInventory(&inventory,4);*/
    //system("pause");



    return 0;
}
