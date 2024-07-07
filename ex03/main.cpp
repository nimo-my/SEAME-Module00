#include <QCoreApplication>
#include <QLocale>
#include <QTranslator>
#include <qlist.h>
#include <qstring.h>
#include "PhoneBook.h"
#include "Contact.h"

int main(int argc, char *argv[]){

    QCoreApplication a(argc, argv);

    std::string input = "";
    PhoneBook page;


    std::cout << ENTER_COMMANDS << std::endl;
    while(!std::cin.eof()){

        std::cout << PRINT_OPTIONS << std::endl;
        std::cout << "> ";
        std::getline(std::cin, input);

        if (input.compare("ADD") == 0){
            page.addUsers();
        }
        else if (input.compare("SEARCH") == 0){
            page.searchPages(); // search perticular pages
        }
        else if (input.compare("REMOVE") == 0){
            page.removePages(); // remove perticular pages
        }
        else if (input.compare("BOOKMARK") == 0){
            page.bookmarkPages(); // bookmark perticular index of the pages
        }
        else if (input.compare("EXIT") == 0){
            // std::cout << "* PhoneBook Closed! *" << std::endl;
            exit(0);
        }
    }
    return (0);
}

