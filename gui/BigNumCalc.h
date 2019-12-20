#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <string>
// Main Calculator class
class calculator{
private:
    std::string x, y;
public:
    void get_mode();
    std::string addition(std::string a, std::string b);
    std::string subtraction(std::string a, std::string b);
    std::string multiplication(std::string a, std::string b);
    std::string check_division(std::string a, std::string b);
};

#endif // BIGNUMCALC_H_INCLUDED
