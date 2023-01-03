//
// Created by Yahya on 12/16/2022.
//

#ifndef DSA_PROJECT_CART_H
#define DSA_PROJECT_CART_H

#include "Item.h"
#include "DataLayer.h"
#include "Product.h"
#include <vector>

/**Cart is a stack Data Structure which will be used to keep track of arr in cart of client */
class Cart{
private:
    /*arr dynamic array will store itemIDs of arr*/
    int * arr;
    /*itemsInCart is total arr in cart*/
    int itemsInCart;

    int head;

    int pop();

    void deleteItem(int itemID, int*);


public:
    Cart(int size);

    /**
     * push function for cart takes obj as input and stores it's id in cart.
     * @param itemID is an id of an object from class Item, it will be used to get the id of item */
    void addToCart(int itemID);


    /**
     * Gets total price and empties the cart
     * @returns total price of all arr in stack  */
    float getTotalPrice(Inventory *inventory);

    std::vector<Product> getProductsInCart( Inventory * inventory);
    void RemoveItem();

};


#endif //DSA_PROJECT_CART_H
