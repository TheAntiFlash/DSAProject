//
// Created by Yahya on 12/18/2022.
//

#ifndef DSA_PROJECT_TRANSACTIONHISTORY_H
#define DSA_PROJECT_TRANSACTIONHISTORY_H

#include "Product.h"
#include "Inventory.h"
#include <vector>

struct Transaction{
    int transactionId;
    std::string clientName;
    std::vector<Product> products;
    float totalPrice;
    Transaction * next;
    Transaction * prev;
};
class TransactionHistory {
private:
    Transaction * head;
    int size;

    void displayTransactionHistory(Inventory *inventory);
    friend class Admin;
public:

    TransactionHistory();

    bool insert(int transactionId,std::string clientName ,  std::vector<Product> products, float totalPrice);


    Transaction* getHeadOfList();

    int generateUniqueTransactionID();

    bool transactionIdAlreadyExists(int tID);
};


#endif //DSA_PROJECT_TRANSACTIONHISTORY_H
