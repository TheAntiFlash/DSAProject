//
// Created by Yahya on 12/16/2022.
//

#include "Client.h"

Client::Client(std::string user, std::string pass) {
    isLoggedIn = false;
    isCartCreated = false;
    username = user;
    password = pass;
    DataLayer dl;
    dl.read(this);
}

const std::string Client::getClassId() const {
    std::string name = "Client";
    return name;
}

void Client::createCart(int totalItemsInInventory) {
    if(isLoggedIn){
        cart = new Cart(totalItemsInInventory);
        isCartCreated = true;
    }
    else{
        std::cout <<"\n\t*******ERROR*******"
                    "\n\t***First Log In***\n";
    }
}

void Client::addToCart(int itemID) {
    if(isLoggedIn && isCartCreated){
        cart->addToCart(itemID);
    }
    else if(isLoggedIn){
        std::cout <<"\n\t*******ERROR*******"
                    "\n\t*First Create Cart*\n";
    }
    else{
        std::cout <<"\n\t*******ERROR*******"
                    "\n\t***First Log In***\n";
    }
    //std::cout << item.getItemID();

}

void Client::checkout(Inventory *inventory, TransactionHistory * transactionHistory) {
    if(isLoggedIn && isCartCreated){

        std::vector<Product> products = cart->getProductsInCart(inventory);

        float tPrice = cart->getTotalPrice(inventory);
        int uniqueTransactionID = transactionHistory->generateUniqueTransactionID();
        transactionHistory->insert(uniqueTransactionID,this->getUsername(), products, tPrice);
        DataLayer dl;
        dl.update(transactionHistory);
        inventory->decrementItemQuantityAfterCheckout(products);
        dl.update(inventory);

        std::cout << std::endl << std::setw(51)<< "***************************************";
        std::cout << "\n"
                  << std::setw(29) <<"Transaction ID: " << std::setw(21) << uniqueTransactionID << std::endl
                  <<std::setw(26) << "Client Name: " << std::setw(24) << this->getUsername();

        std::cout << "\n\n"
                  << std::setw(20) << "Product"
                  << std::setw(15) <<  "Quantity"
                  << std::setw(15) << "Price";

        for (const auto &item: products){
            std::cout << std::endl
                      << std::setw(20) << inventory->getItemFromId(item.getItemId()).getProductName()
                      << std::setw(15) << item.getQuantity()
                      << std::setw(15) << std::fixed << std::setprecision(2) << item.getPriceOfItems();
        }

        std::cout << std::endl
                  << std::setw(50)<<  "---------" << std::endl
                  << std::setw(41)<< "Total: " << std::fixed << std::setprecision(2) << tPrice;

        std::cout << std::endl << std::setw(51)<< "***************************************";

    }
    else if(isLoggedIn){
        std::cout <<"\n\t*******ERROR*******"
                    "\n\t*First Create Cart*\n";
    }
    else{
        std::cout <<"\n\t*******ERROR*******"
                    "\n\t***First Log In***\n";
    }

}

bool Client::signUp(std::string username, std::string password) {
    return User::signUp(false, username, password);

}
