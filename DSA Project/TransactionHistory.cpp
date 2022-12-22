//
// Created by Yahya on 12/18/2022.
//

#include "TransactionHistory.h"

TransactionHistory::TransactionHistory() {
    head = nullptr;
    size = 0;
}

bool TransactionHistory::insert(int transactionId,std::string clientName, std::vector<Product> products, float totalPrice) {
    bool transactionIdExists = false;
    if(transactionIdAlreadyExists(transactionId)){
        transactionIdExists = true;
        return transactionIdExists;
    }
    else{

        if(head == nullptr){
            head = new Transaction;
            head->transactionId = transactionId;
            head->products = products;
            head->totalPrice = totalPrice;
            head->clientName = clientName;
            head->next = nullptr;
            head->prev = nullptr;

        }
        else{
            Transaction * trav = head;
            while(trav->next != nullptr){
                trav = trav->next;
            }
            trav->next = new Transaction;
            trav->next->prev = trav;
            trav = trav->next;
            trav->transactionId = transactionId;
            trav->products = products;
            trav->totalPrice = totalPrice;
            trav->clientName = clientName;
            trav->next = nullptr;

        }
        size++;
        return false;
    }

}

bool TransactionHistory::transactionIdAlreadyExists(int tID) {
    Transaction * trav = head;
    bool exists = false;
    while(trav != nullptr){
        if(trav->transactionId == tID){
            exists = true;
            break;
        }
        trav = trav->next;
    }
    return exists;
}

void TransactionHistory::displayTransactionHistory(Inventory *inventory) {
        Transaction * trav;
        trav = head;
        std::cout << "\n\n"<< std::setw(54) <<"************TRANSACTION HISTORY************";
        while(trav!= nullptr){

            std::cout << "\n\n"
            << std::setw(33) <<"Transaction ID: " << std::setw(15) << trav->transactionId << std::endl
            <<std::setw(30) << "Client Name: " << std::setw(18) << trav->clientName;

            std::cout << "\n\n"
            << std::setw(20) << "Product"
            << std::setw(15) <<  "Quantity"
            << std::setw(15) << "Price";

            for (const auto &item: trav->products){
                std::cout << std::endl
                << std::setw(20) << inventory->getItemFromId(item.getItemId()).getProductName()
                << std::setw(15) << item.getQuantity()
                << std::setw(15) << std::fixed << std::setprecision(2) << item.getPriceOfItems();
            }

            std::cout << std::endl
            << std::setw(50)<<  "---------" << std::endl
            << std::setw(41)<< "Total: " << std::fixed << std::setprecision(2) << trav->totalPrice;

            std::cout << std::endl << std::setw(51)<< "***************************************";
            trav = trav->next;
        }

    }

Transaction *TransactionHistory::getHeadOfList() {
    return head;
}

int TransactionHistory::generateUniqueTransactionID() {
    int id = (rand() % 10000) + 210000;
    while(transactionIdAlreadyExists(id)){
        id = (rand() % 10000) + 210000;
    }
    return id;
}
