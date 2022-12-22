//
// Created by Yahya on 12/10/2022.
//

#ifndef DSA_PROJECT_IENTITY_H
#define DSA_PROJECT_IENTITY_H
#include <string>

class IEntity {

public:

    /**
     * virtual function used to determine which derived class is stored in the IEntity*
     * @return string name of the child class whose reference is stored in parent pointer
     */
    virtual const std::string getClassId() const = 0;

};


#endif //DSA_PROJECT_IENTITY_H
