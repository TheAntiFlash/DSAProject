//
// Created by Yahya on 12/16/2022.
//
#include "Item.h"
Item::Item(int itemId, std::string productName, int quantity, float price) {
    itemID = itemId;
    this->productName = productName;
    this->quantity = quantity;
    this->price = price;
}

int Item::getItemID() {
    return itemID;
}

Item::Item() {

}

const std::string &Item::getProductName() const {
    return productName;
}

int Item::getQuantity() const {
    return quantity;
}

float Item::getPrice() const {
    return price;
}
