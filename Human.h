//
// Created by User on 04.10.2023.
//

#ifndef LAB1ALGOR_HUMAN_H
#define LAB1ALGOR_HUMAN_H

#include <string>

class Human {
public:
    std::wstring secondName;
    std::wstring firstName;
    std::wstring middleName;

    Human() :
            secondName(L""),
            firstName(L""),
            middleName(L"") {}


    Human(std::wstring &secondName_, std::wstring &firstName_, std::wstring &middleName_) :
            secondName(secondName_),
            firstName(firstName_),
            middleName(middleName_) {}

    bool operator<(const Human &other) const {
        if (secondName != other.secondName) return secondName < other.secondName;
        if (firstName != other.firstName) return firstName < other.firstName;
        return middleName < other.middleName;
    }
};


#endif //LAB1ALGOR_HUMAN_H
