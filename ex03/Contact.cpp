#include "Contact.h"

Contact::Contact()
{
}

Contact::~Contact()
{
}

std::string Contact::getIndex(void) const
{
    return (this->index);
}

std::string Contact::getName(void) const
{
    return (this->name);
}

std::string Contact::getNickName(void) const
{
    return (this->nickName);
}

std::string Contact::getPhoneNumber(void) const
{
    return (this->phoneNumber);
}

void Contact::setIndex(std::string input)
{
    this->index = input;
}

void Contact::setName(std::string input)
{
    this->name = input;
}

void Contact::setNickName(std::string input)
{
    this->nickName = input;
}

void Contact::setPhoneNumber(std::string input)
{
    this->phoneNumber = input;
}

void Contact::removeData()
{
    this->index = "";
    this->name = "";
    this->nickName = "";
    this->phoneNumber = "";
}
