#include <QCoreApplication>
#include <iostream>
#include <cctype>
#include <string>

void changeAlphabet(std::string response, int flag)
{
    if (flag == 0) // convert alphabet to UPPER CASE
    {
        for (size_t j = 0; j < response.length(); j++)
        {
            std::cout << static_cast<char>(std::toupper(response[j]));
        }
        std::cout << " ";
    }
    else if (flag == 1) // convert alphabet to LOWER CASE
    {
        for (size_t j = 0; j < response.length(); j++)
        {
            std::cout << static_cast<char>(std::tolower(response[j]));
        }
        std::cout << " ";
    }
}



int main(int argc, char *argv[])
{

    QCoreApplication a(argc, argv);

    int flag = -1;
    std::string up = "up";
    std::string down = "down";

    if (argc != 1)
    {
        // set a flag
        if (argv[1] == up)
            flag = 0;
        else if (argv[1] == down)
            flag = 1;

        if (flag == 0 || flag == 1)
        {
            for (int i = 2; i < argc; i++)
            {
                std::string response(argv[i]);
                changeAlphabet(response, flag);
            }
            std::cout << std::endl;
        }
        else
        {
            for (int i = 1; i < argc; i++)
            {
                std::string response(argv[i]);

                for (size_t j = 0; j < response.length(); j++)
                {
                    std::cout << response[j];
                }
                std::cout << " ";
            }
            std::cout << std::endl;
        }
    }
    // std::cout << "program finished" << std::endl;
    return 0;
}
