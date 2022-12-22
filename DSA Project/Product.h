//
// Created by Yahya on 12/18/2022.
//

#ifndef DSA_PROJECT_PRODUCT_H
#define DSA_PROJECT_PRODUCT_H

#include <iostream>

/**
 * This class is made only to store itemID and quantity PURCHASED BY THE USER.
 */
class Product {
private:
    int itemID;
    int quantity;
    float priceOfItems;
public:
    Product();

    float getPriceOfItems() const;

    Product(int itemId, int quantity, float priceOfItems);

    int getItemId() const;

    int getQuantity() const;

    void toString() const;
};


#endif //DSA_PROJECT_PRODUCT_H
