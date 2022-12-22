//
// Created by Yahya on 12/16/2022.
//

#ifndef DSA_PROJECT_DATALAYER_H
#define DSA_PROJECT_DATALAYER_H
#include <fstream>
#include "Inventory.h"
#include "Admin.h"
#include "User.h"
#include "TransactionHistory.h"
#include <iostream>
#include <sstream>
class Inventory;
class DataLayer {
public:

    /**
     * this funciton takes pointer to inventory as a param and reads from inventory.tsv to add
     * all items to the linked list Inventory inventory
     * @param inventory
     */
    void read(Inventory *inventory);
    /**
     * This function takes pointer to User as a param and checks if the username and password is valid,
     * to log in the user.
     * @param user
     */
    void read(User *user);

    bool signUp(bool clientOrAdmin, std::string username, std::string password);
    /**
     * this funciton takes pointer to TransactionHistory as a param and reads from
     * TransactionHistory.tsv to add all Transactions to the
     * linked list TransactionHistory transactionHistory
     * @param transactionHistory
     */
    void read(TransactionHistory * transactionHistory);

    void update(TransactionHistory * transactionHistory);

    /**
     * This function takes the pointer to inventory as a param and updates the inventory.tsv file
     * by rewriting the file with the contents of the linked list.
     * @param inventory
     */
    void Update(Inventory *inventory);

};


#endif //DSA_PROJECT_DATALAYER_H
