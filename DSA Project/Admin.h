//
// Created by Yahya on 12/11/2022.
//

#ifndef DSA_PROJECT_ADMIN_H
#define DSA_PROJECT_ADMIN_H

#include "User.h"
#include "Inventory.h"
#include "DataLayer.h"
#include "TransactionHistory.h"


class Admin : public User{
public:
    Admin(std::string user, std::string pass);

    const std::string getClassId() const override;

    void addToInventory(Inventory * inventory, int itemID, std::string productName, int quantity, float price);

    /**
     * This one I've left for you, will require a menu, i recommend adding the menu for this functionality in the function,
     * instead of in main function. glhf.
     * @param inventory
     * @param itemID
     */
    void editInventory(Inventory * inventory, int itemID);

    void deleteItemFromInventory(Inventory * inventory, int itemID);

    void displayTransactionHistory(Inventory * inventory, TransactionHistory * transactionHistory);

    static bool signUp(std::string username, std::string password);
};


#endif //DSA_PROJECT_ADMIN_H
