//
// Created by Yahya on 12/16/2022.
//

#include "Cart.h"

Cart::Cart(int size) {
    this->head = -1;
    this->arr = new int[size];
    itemsInCart = 0;
}

void Cart::addToCart(int itemID) {
    head++;
    arr[head] = itemID;
    itemsInCart++;
}

float Cart::getTotalPrice(Inventory * inventory) {
    float totalPrice;
    //std::cout << "\n\n\tProduct\t\tPrice";
    while(head != -1){
        int itemId = pop();

        /*std::cout << "\n\t"
                  << inventory->getItemFromId(itemId).getProductName() <<"\t\t"
                  << inventory->getItemFromId(itemId).getPrice();*/

        /*inventory->getItemFromID returns an Item object,
         so we can use the Item Obj's .getPrice() method directly*/
        totalPrice += inventory->getItemFromId(itemId).getPrice();
    }

    return totalPrice;
}

int Cart::pop() {
    int removedItemId = arr[head];
    arr[head] = -1;
    head--;
    itemsInCart--;
    return removedItemId;
}

std::vector<Product> Cart::getProductsInCart(Inventory * inventory){
    std::vector<Product> products;

    int tempArr[itemsInCart];

    for(int i = 0; i < itemsInCart; i ++){
        tempArr[i] = arr[i];
    }


    for(int i = 0; i < itemsInCart; i ++){
        int quantity = 1;
        //std::cout << "itemsInCart: " << itemsInCart << std::endl;
        for(int j = i + 1; j < itemsInCart; j++){
            if(tempArr[i] == tempArr[j]){
                quantity++;
            }
        }
        products.push_back(*(new Product(tempArr[i], quantity, inventory->getItemFromId(tempArr[i]).getPrice() * quantity )));
        deleteItem(tempArr[i], tempArr);
        i+= quantity-1;
    }
    
    /*for (const auto &item: products){
        item.toString();
    }*/
return products;
}

void Cart::deleteItem(int itemID, int* arr) {
    int swap = 0;
    for(int i = 0; i < itemsInCart; i ++){
        if(arr[i] == itemID){
            arr[i] = -1;
            int temp = arr[swap];
            arr[swap] = arr[i];
            arr[i] = arr[swap];
            swap++;
        }
    }

}

void Cart::RemoveItem() {
    pop();
    std::cout<<"Item Removed...."<<std::endl;
}

