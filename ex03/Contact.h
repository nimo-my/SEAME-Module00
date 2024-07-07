#ifndef CONTACT_H
#define CONTACT_H

#include <iostream>
#include <string>
#include <sstream>

class Contact
{
private:
    std::string index;
    std::string name;
    std::string nickName;
    std::string phoneNumber;

public:
    Contact();
    ~Contact();

    std::string getIndex(void) const;
    std::string getName(void) const;
    std::string getNickName(void) const;
    std::string getPhoneNumber(void) const;

    void setIndex(std::string input);
    void setName(std::string input);
    void setNickName(std::string input);
    void setPhoneNumber(std::string input);


    void removeData();
};

#endif
