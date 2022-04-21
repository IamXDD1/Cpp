#pragma once
#include <iostream>
#include <string>

namespace
{
    std::string password;
    bool isValid() {
        if (password.length() < 8) return false;
        for (int i = 0; i < password.length(); i++) {
            if (isdigit(password[i])) return true;
        }
        return false;
    }
}

namespace Authenticate
{
    void inputPassword()
    {
        do
        {
            std::cout << "Enter your password (at least 8 characters " <<
                "and at least one non-letter)" << std::endl;
            std::cin >> password;
        } while (!isValid());
    }

    std::string getPassword()
    {
        return password;
    }
}
