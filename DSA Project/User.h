//
// Created by Yahya on 12/16/2022.
//

#ifndef DSA_PROJECT_USER_H
#define DSA_PROJECT_USER_H


#include "IEntity.h"
#include <iostream>
class User : public IEntity{
protected:
    std::string username;
    std::string password;
    bool isLoggedIn;

    static bool signUp(bool clientOrAdmin, std::string user, std::string pass);

public:
    bool logIn(std::string username, std::string password) ;
    bool isUserLoggedIn();
    const std::string getClassId() const override;


    std::string getUsername();
};


#endif //DSA_PROJECT_USER_H
