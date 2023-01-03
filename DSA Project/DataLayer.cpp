//
// Created by Yahya on 12/16/2022.
//


#include "DataLayer.h"



void DataLayer::read(Inventory * inventory) {
    std::ifstream file("Inventory.tsv");
    std::string line;
    while(std::getline(file, line)){
        //std::cout << line << std::endl;
        std::istringstream iss(line);
        int itemID;
        std::string productName;
        int quantity;
        float price;

        if(iss >> itemID >> productName >> quantity >> price) {
             //std::cout << itemID << "\t" << productName << "\t" << quantity << "\t" << price;
            inventory->insert(itemID, productName, quantity, price);
        }
    }
    file.close();
}

void DataLayer::read(User *user) {
    std::ifstream file;
    bool loggedIn = false;
    if(user->getClassId() == "Admin"){
        file.open("Admin.tsv");
    }
    else if(user->getClassId() == "Client"){
        file.open("Client.tsv");
    }
    std::string line;
    while(std::getline(file, line)){
        std::istringstream iss(line);
        std::string username;
        std::string password;

        if(iss >> username >> password) {
            loggedIn = user->logIn(username, password);
            if(loggedIn){
                break;
            }
        }
    }
    if(loggedIn){
        std::cout << "Account " << user->getUsername() << " Successfully logged in!";
    }
    else{
        std::cout << "Invalid Username OR Password";
    }
    file.close();
}

void DataLayer::update(Inventory *inventory) {
    std::ofstream file;
    file.open("Inventory.tsv");
    Item * trav = inventory->getHeadOfList();
    while(trav != nullptr){
        file << trav->getItemID() << "\t" << trav->getProductName() << "\t" << trav->getQuantity() << "\t" << std::setprecision(7) << trav->getPrice() << "\n";
        trav = trav->next;
    }
    file.close();
}

void DataLayer::read(TransactionHistory *transactionHistory) {
    std::ifstream file("TransactionHistory.tsv");
    std::string line;
    while(std::getline(file, line)){
        //std::cout << line << std::endl;
        std::istringstream iss(line);
        int transactionID;
        std::string clientName;
        std::vector<Product> products;
        int itemId;
        int quantity;
        float priceOfItem;
        float totalPrice;

        if(iss >> transactionID >> clientName >> totalPrice) {
            while(iss >> itemId >> quantity >> priceOfItem){
                products.push_back(*(new Product(itemId, quantity, priceOfItem)));
            }

            /*std::cout << "\n" << transactionID << "\t" << totalPrice << std::endl;
            for (const auto &item: products){
                item.toString();
            }*/

            transactionHistory->insert(transactionID, clientName, products, totalPrice);
        }
    }
    file.close();
}

void DataLayer::update(TransactionHistory *transactionHistory) {
    std::ofstream file;
    file.open("TransactionHistory.tsv");
    Transaction* trav = transactionHistory->getHeadOfList();

    while(trav!= nullptr){
        file << trav->transactionId << "\t" << trav->clientName << "\t" << std::setprecision(7) << trav->totalPrice;
        for (const auto &item: trav->products){
            file << "\t" << item.getItemId() << "\t" << item.getQuantity() << "\t" << std::setprecision(7) << item.getPriceOfItems();
        }
        file << "\n";
        trav = trav->next;
    }
    file.close();
}

bool DataLayer::signUp(bool clientOrAdmin, std::string username, std::string password) {
    std::ifstream file;
    if(!clientOrAdmin) {
         file.open("Client.tsv");
    }
    else{
        file.open("Admin.tsv");

    }

    std::string line;
    bool userAlreadyExists = false;
    while(std::getline(file, line)){
        std::istringstream iss(line);
        std::string user;
        std::string pass;



        if(iss >> user >> pass) {
            if(username == user){
                userAlreadyExists = true;
                break;
            }
        }
    }
    file.close();

    if(userAlreadyExists){
        std::cout << "\n\nUsername is taken!\nTry Again!";
        return false;
    }

    std::ofstream read;

    if(!clientOrAdmin) {
        read.open("Client.tsv", std::ios::out | std::ios::app);
    }
    else{
        read.open("Admin.tsv", std::ios::out | std::ios::app);
    }

    read << "\n" << username << "\t" << password;
    return true;
}
