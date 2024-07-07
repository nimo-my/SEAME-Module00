#ifndef PHONEBOOKUTILS_H
#define PHONEBOOKUTILS_H

#include <iomanip>
#include <iostream>
#include <string>

#define PRINT_LINE " ==============================================================="
#define PRINT_OPTIONS "* USAGE : Please type one keywords between [ADD, SEARCH, REMOVE, BOOKMARK, EXIT]. *"
#define ENTER_COMMANDS "============= Welcome! this is a PHONEBOOK program! ============="
#define EMPTY_VALUE "* PHONEBOOK : Empty value can't be stored. please write more!"
#define PRINT_ADD_FIRST "* PHONEBOOK : There is no data! [ADD] first!"
#define PRINT_SEARCH "What pages are you looking for? Input the number of index : "
#define PRINT_INVALID_INPUT "* PHONEBOOK : Invalid input! Useage : put one number between 1 ~ 8."

void printLine();
void phoneBookHeader();

void checkFieldEmpty(std::string input);
int isFieldEmpty(std::string field);
int checkValidNumber(std::string str);
std::string checkLength(std::string input);
int checkValidNumber(std::string str, int dbSize);

#endif // PHONEBOOKUTILS_H
