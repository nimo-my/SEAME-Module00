#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include "Contact.h"
#include "PhoneBookUtils.h"
#include <list>
#include <vector>
#include <cstddef> // for size_t

class PhoneBook
{
private:
    Contact pages;
    std::vector<Contact*> db;
    std::vector<Contact*> bookmarkList;
    std::size_t index;
    std::size_t bookmarkIndex;

public:
    PhoneBook();
    ~PhoneBook();

    void addUsers();

    void showPages();
    void printAllInfo(size_t index);

    void searchPages();
    void getInfoByIndex(std::string input);

    void removePages();
    void bookmarkPages();

    void printBookmarkAllInfo(size_t index);


};

#endif // PHONEBOOK_H
