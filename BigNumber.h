#include <iostream>    
#include <vector>
#include <string>
#include <sstream>

class BigNumber {
public:
    std::vector<unsigned long long> number;

    BigNumber(std::string);

    void setHex(std::string);
    std::string getHex();
    BigNumber INV();
    BigNumber XOR(BigNumber);
    BigNumber OR(BigNumber);
    BigNumber AND(BigNumber);
    BigNumber shiftL(int);
    BigNumber shiftR(int);
};