#include <iostream>
#include "Inventory.h"
#include "DataLayer.h"
#include "Admin.h"
#include "Client.h"
#include <ctime>

int main() {
    srand(time(0));
    //class instances //variable declaration
    std::cout<<std::endl<<"-------------------------------------"<<std::endl;
    std::cout<<"Created by:"<<std::endl;
    std::cout<<std::endl<<"-------------------------------------"<<std::endl;
    std::cout<<"Hamza Afzal - 210948"<<std::endl<<std::endl;
    std::cout<<"Yahya Bin Naveed - 210999"<<std::endl<<std::endl;
    std::cout<<"Areesh Ali Abdullah - 210894"<<std::endl<<std::endl;
    std::cout<<"M Hashaam Awan - 210981"<<std::endl<<std::endl;
    std::cout<<std::endl<<"-------------------------------------"<<std::endl<<std::endl;
    Inventory inventory;//instance of class Inventory in mian.cpp
    TransactionHistory transactionHistory; //
    DataLayer dl;
    bool cartCreated=false; //checks whether cart is created or not
    dl.read(&inventory);
    dl.read(&transactionHistory);

    int adminOrClientMenuChoice;
    bool quit = false;
    bool sub_quit=false;
    std::cout << "\n****************************** "
                 "Welcome to xyz Online Store"
                 " *********************************\n";
    // system("pause");
    while (quit == false) {
        //system("cls");
        std::cout << "\n\t\t\t-> LOG IN AS <-\n";
        std::cout << "1)As Admin\n2)As User\n";
        std::cout << "Enter Choice: " << std::endl;
        std::cin >> adminOrClientMenuChoice;


        /**
         * ADMIN MENU
         */
        if (adminOrClientMenuChoice == 1) {
            std::string name, password;
            system("CLS");
            std::cout << "\t\tADMIN LOG IN PANEL";
            std::cout << "\nEnter Username :   ";
            std::cin >> name;
            std::cout << "\nEnter Password :   ";
            std::cin >> password;
            //admin.logIn(name,password);
            Admin admin(name,password);
            if(admin.isUserLoggedIn())
            {
                std::cout<<"\nAdmin: "<<name<<"  LogIn Successfull";
                while (quit!=true)
                {
                    int subchoice=0;

                    admin.displayList();
                    std::cin>>subchoice;

                    /**
                     * ADD ITEM TO INVENTORY
                     */
                    if (subchoice == 1)
                    {
                        system("cls");
                        std:: string name;
                        int itemid;
                        int quantity;
                        float price;
                        std::cout<<"\n\t\tAdd Item to Inventory.";
                        std::cout<<"\nEnter Name of NEW Product: ";
                        std::cin>>name;
                        std::cout<<"\nEnter Item ID of the Product: ";
                        std::cin>>itemid;

                        if(!inventory.doesItemExistInInventory(itemid)){
                            std::cout<<"\nEnter Quantity of the Product: ";
                            std::cin>>quantity;
                            std::cout<<"\nEnter Price of the Product: ";
                            std::cin>>price;
                            admin.addToInventory(&inventory,itemid,name,quantity,price);
                            std::cout<<"\nItem Inserted Successfully...................";
                        }
                        else{
                            std::cout << "\n\t*********ERROR**********"
                                         "\n\tItem ID already Exists"
                                         "\n\tItem ID must be unique";
                        }
                    }

                    /**
                     * DELETE ITEM FROM INVENTORY
                     */
                    else if(subchoice==2)
                    {
                        system("cls");
                        int itemid;
                        std::cout<<std::endl<<std::setw(15)
                                 <<"->Delete Item from Inventory<-\n\n";
                        std::cout<<"Enter Item ID to delete : ";
                        std::cin >> itemid;
                        admin.deleteItemFromInventory(&inventory,itemid);
                    }

                    /**
                     * DISPLAY TRANSACTION HISTORY
                     */
                    else if(subchoice==3)
                    {
                        system("cls");
                        std::cout<<std::setw(15)<<"Displaying Transaction History.\n";
                        admin.displayTransactionHistory(&inventory,&transactionHistory);
                        std::cout<<std::endl;
                        system("pause");
                    }

                    /**
                     * DISPLAY INVENTORY
                     */
                    else if(subchoice==4)
                    {
                        system("cls");
                        std::cout<<"\n\t\t->Displaying Inventory<-\n\n";
                        inventory.displayInventory();
                        system("pause");
                        std::cout<<std::endl;
                    }

                    /**
                     * EDIT INVENTORY
                     */
                    else if(subchoice==5){
                        system("cls");
                        int itemid;
                        std::cout<<std::endl<<std::setw(15)
                                 <<"->Edit Item from Inventory<-\n\n";
                        std::cout<<"Enter Item ID to edit : ";
                        std::cin >> itemid;
                        admin.editInventory(&inventory,itemid);
                    }

                    /**
                     * EXIT
                     */
                    else if(subchoice==6){
                        system("cls");
                        char ext;
                        std::cout<<"\n\t\tEXIT PORTAL";
                        std::cout<<"\nDo you Really want to exit? (y/n)\n->";
                        std::cin>>ext;
                        if (ext=='Y' || ext== 'y')
                        {
                            std::cout<<"\n\tLeaving Portal......\n";
                            system("pause");
                            quit=true;
                            exit(0);
                        }
                        else
                        {
                            std::cout<<"\n\tInvalid Choice"
                                       "\nRedirecting.............\n";
                            system("pause");
                        }
                    }
                }
            }

            /**
             * SIGN UP AS ADMIN
             */
            else {
                std::string name, password;
                char tempCh;
                std::cout << "\n->SignUp as Admin??? (y/n): ";
                std::cin >> tempCh;
                if (tempCh == 'Y' || tempCh == 'y') {
                    std::cout << "\nNEW ACCOUNT Name: ";
                    std::cin >> name;
                    std::cout << "\nPassword: ";
                    std::cin >> password;
                    Admin::signUp(name, password);

                } else {
                    std::cout << "\nReturning back to Menu......";
                }

            }
        }

        /**
         * CLIENT MENU
         */
        else if (adminOrClientMenuChoice == 2)
        {
            std::string name, password;
            system("CLS");
            std::cout << "\t\tUser LOG IN PANEL";
            std::cout << "\nEnter Username:  ";
            std::cin >> name;
            std::cout << "\nEnter Password: ";
            std::cin >> password;

            Client client(name,password);
            if (client.isUserLoggedIn())
            {

                std::cout << "\n\nUser:  " << name << " Logged In SUCCESSFULL!!!!";
                std::cout<<"\n\n\t\tWELCOME TO USER PORTAL";
                std::cout<<"\n\n\n\t\t Hello "<<name<<std::endl;
                while (!sub_quit)
                {
                    int choice=0;

                    client.ClDisplayList();
                    std::cin>>choice;
                    /**
                     * DISPLAY INVENTORY
                     */
                    if (choice==1)
                    {
                        system("cls");
                        std::cout<<"\n**************** Displaying Inventory *****************\n\n";
                        inventory.displayInventory();
                        system("pause");
                    }
                    /**
                     * CREATE CART
                     */
                    else if(choice == 2 )
                    {
                        system("cls");
                        char ch;
                        std::cout<<"\nDo you want to create Create Cart? (y/n)\n->";
                        std::cin>>ch;
                        if (ch=='Y' || ch=='y')
                        {
                            client.createCart(inventory.getTotalQuantityOfItemsInInventory());
                            cartCreated=true;

                        } else
                        {
                            std::cout<<"\n!!!!!!!! Invalid Input !!!!!!!!!";
                        }
                        system("pause");
                    }
                    /**
                     * ADD TO CART
                     */
                    else if(choice == 3 && cartCreated)
                    {
                        system("cls");
                        int itemid;
                        char ext;
                        std::cout<<"\n********** Displaying Inventory ****************\n";
                        inventory.displayInventory();
                        std::cout<<"\nEnter Item ID of Product to add in your cart: ";
                        std::cout<<"\nMax Item that can be pushed in Cart "<<inventory.getTotalQuantityOfItemsInInventory();
                        for (int i = 0; i < inventory.getTotalQuantityOfItemsInInventory(); ++i)
                        {
                            std::cout<<"\nItem # "  <<i+1<<": ";
                            std::cin>>itemid;
                            if(inventory.doesItemExistInInventory(itemid)){
                                client.addToCart(itemid);
                            }
                            else{
                                std::cout<<"\n!!!!!!!! Invalid Input !!!!!!!!!";
                                std::cout<<"\n!!!!!!!! ENTER VALID ITEM ID !!!!!!!!!";
                                i--;
                                continue;
                            }
                            std::cout<<"\n*Press Y to Exit, Else it will Keep going on*\n";
                            std::cin>>ext;
                            if(ext == 'y' || ext == 'Y')
                            {
                                i=inventory.getTotalQuantityOfItemsInInventory();
                            }
                        }

                    }
                    /**
                     * REMOVE FROM CART
                     */
                    else if (choice == 4 && cartCreated)
                    {
                        system("cls");
                        client.removeCartItem(&inventory);
                        system("pause");

                    }
                    /**
                     * DISPLAY CART
                     */
                    else if (choice == 5 && cartCreated)
                    {
                        system("cls");
                        std::cout<<"Displaying items in Cart : "<<std::endl;
                        client.showCart(&inventory);
                        system("pause");
                    }

                    /**
                     * GET CART PRICE
                     */
                    else if (choice == 6 && cartCreated)
                    {
                        system("cls");
                        std::cout<<"Displaying Total Price of Cart : "<<std::endl;
                        client.showCartPrice(&inventory);
                        system("pause");

                    }
                    /**
                     * CHECKOUT
                     */
                    else if (choice == 7 && cartCreated)
                    {
                        system("cls");
                        std::cout<<"\n\t************** CHECKOUT *************************";
                        std::cout<<"\tName: "<<client.getUsername();
                        client.checkout(&inventory,&transactionHistory);
                        std::cout<<std::endl<<std::endl;
                        system("pause");

                    }
                    /**
                     * EXIT
                     */
                    else if (choice == 8 )
                    {
                        system("cls");
                        char ext;
                        std::cout<<"\n\t\tEXIT PORTAL";
                        std::cout<<"\nDo you Really want to exit? (y/n)\n->";
                        std::cin>>ext;
                        if (ext=='Y' || ext== 'y')
                        {
                            std::cout<<"\n\tLeaving Portal......\n";
                            std::cout<<"THank You For using this program, Have a nice day.."<<std::endl;
                            std::cout<<std::endl<<"-------------------------------------"<<std::endl;
                            std::cout<<"Created by:"<<std::endl;
                            std::cout<<std::endl<<"-------------------------------------"<<std::endl;
                            std::cout<<"Hamza Afzal - 210948"<<std::endl<<std::endl;
                            std::cout<<"Yahya Bin Naveed - 210999"<<std::endl<<std::endl;
                            std::cout<<"Areesh Ali Abdullah - 210894"<<std::endl<<std::endl;
                            std::cout<<"M Hashaam Awan - 210981"<<std::endl<<std::endl;
                            std::cout<<std::endl<<"-------------------------------------"<<std::endl<<std::endl;
                            system("pause");
                            quit=true;
                            exit(0);
                        }
                        else
                        {
                            std::cout<<"\n\tInvalid Choice"
                                       "\nRedirecting.............\n";
                            system("pause");
                        }
                    }
                    /**
                     * INVALID CHOICE
                     */
                    else
                    {
                        std::cout<<"\n\t!!!!-Invalid Choice-!!!!!!!\n";
                        std::cout<<"\n\tRedirecting........";
                        system("pause");
                    }

                }
            }
            /**
             * SIGN UP AS USER
             */
            else
            {
                std::string signUp_Username, signUp_Password;
                char tempCh;
                std::cout << "\n->SignUp as User??? (y/n): ";
                std::cin >> tempCh;
                if (tempCh == 'Y' || tempCh == 'y') {
                    std::cout << "\nNEW ACCOUNT Name: ";
                    std::cin >> signUp_Username;
                    std::cout << "\nPassword: ";
                    std::cin >> signUp_Password;
                    Client::signUp(signUp_Username,signUp_Password);
                    system("pause");

                }
                else
                {
                    std::cout << "\nReturning back to Menu......";
                }

            }
        }
        else
        {
            std::cout<<"\n\t!!!!!! Invalid Choice !!!!!!!!\n";
            std::cout<<"\tREDIRECTING >>>.................\n\n";

            continue;
        }
    }


}
