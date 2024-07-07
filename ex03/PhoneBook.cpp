#include "PhoneBook.h"
#include <algorithm> // std::find_if
#include <iostream>
#include <string>
#include <vector>

PhoneBook::PhoneBook()
{
    this->index = 1;
    this->bookmarkIndex = 1;
    this->bookmarkList.reserve(8);
    // std::cout << "* PhoneBook Created! *" << std::endl;
}

PhoneBook::~PhoneBook()
{
    // TODO : delete all contacts
    for (size_t i = 0; i < this->db.size(); i++)
    {
        delete db.at(i);
    }
}

void PhoneBook::addUsers()
{

    std::string input = "";
    Contact *pages = new Contact(); // dynamic memory allocation

    if (this->index == 0)
        this->index = 1;
    pages->setIndex(std::to_string(this->index));

    std::cout << "* Name : ";
    while (input == "")
    {
        std::getline(std::cin, input);
        if (std::cin.eof())
        {
            input.clear();
            exit(1);
        }
        if (!isFieldEmpty(input) && (input != ""))
            pages->setName(input);
        std::cin.clear();
    }
    std::cin.clear();

    input = "";
    std::cout << "* nickname : ";
    while (input == "")
    {
        std::getline(std::cin, input);
        if (std::cin.eof())
        {
            input.clear();
            exit(1);
        }
        if (!isFieldEmpty(input) && (input != ""))
            pages->setNickName(input);
        std::cin.clear();
    }

    input = "";
    std::cout << "* phone number : ";
    while (input == "")
    {
        std::getline(std::cin, input);
        if (std::cin.eof())
        {
            input.clear();
            exit(1);
        }
        if (!isFieldEmpty(input) && (input != ""))
            pages->setPhoneNumber(input);
        std::cin.clear();
    }

    this->db.push_back(pages);
    this->index++;
}

// show all of the pages that are made.
void PhoneBook::showPages()
{
    if (this->index == 1)
        std::cout << PRINT_ADD_FIRST << std::endl;
    else
    {
        phoneBookHeader();
        for (size_t i = 0; i < this->db.size(); i++)
        {
            printAllInfo(i);
        }
    }
}

// TODO : remove the pages.
void PhoneBook::removePages()
{

    std::string input = "";

    if (this->index == 1)
        std::cout << "There is nothing to remove." << std::endl;
    else
    {
        this->showPages();
        std::cout << "Remove method : press 1 to erase by index / press 2 to erase by phone number ." << std::endl;
        std::getline(std::cin, input);
        if (std::cin.eof())
        {
            input.clear();
            exit(1);
        }
        std::cin.clear();

        std::vector<Contact *>::iterator it;

        if (input == "1")
        {
            // 1 - erase by index
            std::cout << "Please insert the index below : " << std::endl;

            std::getline(std::cin, input);
            if (std::cin.eof())
            {
                input.clear();
                exit(1);
            }
            std::cin.clear();

            if (!isFieldEmpty(input) && (input != ""))
            {
                for (it = this->db.begin(); it != this->db.end();)
                {
                    Contact *contact = *it;
                    if (input == contact->getIndex())
                    {
                        this->db.erase(it);
                        std::cout << "Successfully erased! :D" << std::endl;
                        this->index--;
                    }
                    else
                        ++it;
                }
            }
        }
        else if (input == "2")
        {
            // 2 - erase by phone number
            std::cout << "Please insert the phone number below : " << std::endl;

            std::getline(std::cin, input);
            if (std::cin.eof())
            {
                input.clear();
                exit(1);
            }
            std::cin.clear();

            if (!isFieldEmpty(input) && (input != ""))
            {
                for (it = this->db.begin(); it != this->db.end();)
                {
                    Contact *contact = *it;
                    if (input == contact->getPhoneNumber())
                    {
                        this->db.erase(it);
                        std::cout << "Successfully erased! :D" << std::endl;
                        this->index--;
                    }
                    else
                        ++it;
                }
            }
        }
        else
        {
            std::cout << "Did not erased anything..." << std::endl;
        }
    }

    std::cin.clear();
}

// list up the bookmark page.
void PhoneBook::bookmarkPages()
{
    if (this->index == 0)
        std::cout << PRINT_ADD_FIRST << std::endl;
    else
    {
        phoneBookHeader();
        if (bookmarkList.size())
        {
            for (std::size_t i = 0; i < this->bookmarkIndex - 1; i++)
            {
                printBookmarkAllInfo(i);
            }
        }
    }
}

void PhoneBook::printBookmarkAllInfo(std::size_t index)
{

    std::cout << std::setw(10) << checkLength(this->bookmarkList[index]->getIndex()) << "|";
    std::cout << std::setw(10) << checkLength(this->bookmarkList[index]->getName()) << "|";
    std::cout << std::setw(10) << checkLength(this->bookmarkList[index]->getNickName()) << "|";
    std::cout << std::setw(10) << checkLength(this->bookmarkList[index]->getPhoneNumber()) << "|";

    std::cout << std::endl;
}

void PhoneBook::printAllInfo(std::size_t index)
{
    std::cout << std::setw(10) << checkLength(this->db[index]->getIndex()) << "|";
    std::cout << std::setw(10) << checkLength(this->db[index]->getName()) << "|";
    std::cout << std::setw(10) << checkLength(this->db[index]->getNickName()) << "|";
    std::cout << std::setw(10) << checkLength(this->db[index]->getPhoneNumber()) << "|";

    std::cout << std::endl;
}

void PhoneBook::searchPages()
{
    if (this->index == 1)
        std::cout << PRINT_ADD_FIRST << std::endl;
    else
    {
        std::string input = "";
        std::string bookmarkInput = "";
        while (input == "")
        {
            showPages();
            std::cout << std::endl << PRINT_SEARCH;
            std::getline(std::cin, input);
            if (std::cin.eof())
            {
                input.clear();
                exit(1);
            }

            if (checkValidNumber(input, this->db.size()))
                std::cout << PRINT_INVALID_INPUT << std::endl;
            else
            {
                getInfoByIndex(input);
                std::cout << "Do you want to bookmark this information? (press Y for yes)" << std::endl;
                std::getline(std::cin, bookmarkInput);

                if (bookmarkInput == "Y")
                {
                    std::cout << "If you want to confirm, press ENTER." << std::endl;
                    std::stringstream stream(input);
                    std::size_t convertedInput;
                    stream >> convertedInput;

                    // insert data inside the bookmarkList
                    bookmarkList.push_back(db.at(convertedInput - 1));
                    this->bookmarkIndex++; // total bookmark's size
                }
                else
                    std::cout << ".. maybe we can bookmark next time... ;) (Press ENTER)" << std::endl;
            }

            std::getline(std::cin, input);

            break;
        }
    }
}

void PhoneBook::getInfoByIndex(std::string index)
{

    std::stringstream stream(index);
    size_t resultIdx;
    stream >> resultIdx;

    if (!isFieldEmpty(index) && (index != ""))
    {
        // check index
        for (size_t i = 0; i < db.size(); i++)
        {
            if (this->db[i]->getIndex() == index)
            {
                // show pages if there's a data
                std::cout << "=============== showing pages ==================" << std::endl;
                std::cout << "* name : " << this->db[resultIdx - 1]->getName() << std::endl;
                std::cout << "* nick name : " << this->db[resultIdx - 1]->getNickName() << std::endl;
                std::cout << "* phone number : " << this->db[resultIdx - 1]->getPhoneNumber() << std::endl;
                std::cout << "================================================" << std::endl << std::endl;
            }
        }
    }
    else
        std::cout << PRINT_INVALID_INPUT << std::endl;
}
