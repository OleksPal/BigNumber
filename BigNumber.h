#include <iostream>    
#include <vector>
#include <string>
#include <sstream>

class BigNumber {
public:
    std::vector<unsigned long long> number;

    BigNumber(std::string value);

    void setHex(std::string value);

    std::string getHex();
};