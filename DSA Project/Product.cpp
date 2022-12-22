//
// Created by Yahya on 12/18/2022.
//

#include "Product.h"

Product::Product(int itemId, int quantity, float priceOfItems) {
    this->itemID = itemId;
    this->quantity = quantity;
    this->priceOfItems = priceOfItems;
}

void Product::toString() const {
    std::cout << "\n" << itemID << "\t" << quantity << "\t" << priceOfItems;
}

int Product::getItemId() const {
    return itemID;
}

int Product::getQuantity() const {
    return quantity;
}

float Product::getPriceOfItems() const {
    return priceOfItems;
}

