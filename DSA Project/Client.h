//
// Created by Yahya on 12/16/2022.
//

#ifndef DSA_PROJECT_CLIENT_H
#define DSA_PROJECT_CLIENT_H
#include <iostream>
#include "User.h"
#include "Cart.h"
#include "DataLayer.h"
#include <iomanip>

class Client : public User{
private:
    Cart * cart;
    bool isCartCreated;
public:
    Client(std::string user, std::string pass);
    const std::string getClassId() const override;

    /**
     * This function will initialize the private member "pointer of class Cart" with an
     * object of Cart having size that of total arr currently in inventory
     * @param totalItemsInInventory will get from main using function of Inventory, "getTotalItemsInInventory()"
     */
    void createCart(int totalItemsInInventory);

    void addToCart(int itemID);

    static bool signUp(std::string username, std::string password);

    void checkout(Inventory *inventory, TransactionHistory * transactionHistory);
};


#endif //DSA_PROJECT_CLIENT_H
