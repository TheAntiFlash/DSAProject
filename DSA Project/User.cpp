//
// Created by Yahya on 12/16/2022.
//

#include "User.h"
#include "DataLayer.h"

bool User::logIn(std::string user, std::string pass) {
    if((user == this->username) && (pass == this->password)) {
        isLoggedIn = true;
        //std::cout << "this ran";
        return true;
    }
    else {
        return false;
    }
}


const std::string User::getClassId() const {
    return std::string();
}

bool User::isUserLoggedIn() {
    return isLoggedIn;
}

std::string User::getUsername() {
    return username;
}

bool User::signUp(bool clientOrAdmin, std::string user, std::string pass) {
    DataLayer dl;
    if(dl.signUp(clientOrAdmin, user, pass)){
        std::cout << "\n\nUser: " << user << "Successfully signed up!";
        return true;
    }
    return false;}
