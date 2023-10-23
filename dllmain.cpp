// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"
#include <iostream>    
#include <vector>
#include <string>
#include <sstream>

class BigNumber {
public:
    std::vector<unsigned long long> number;

    BigNumber(std::string value) {
        setHex(value);
    }

    void setHex(std::string value) {
        number.clear();

        int size = value.size() - 2; // (-"0x")
        value.erase(0, 2);

        for (int i = 0; i < size; i++) {
            std::string symbol(1, value[i]);
            number.push_back(std::stoi(symbol, 0, 16));
        }
    }

    std::string getHex() {
        std::string hexNumber = "0x";

        std::ostringstream ss;
        for (unsigned long long i : number)
            ss << std::hex << i;

        hexNumber += ss.str();

        return hexNumber;
    }

    BigNumber INV() {
        BigNumber newNumber("");

        for (int i = 0; i < number.size(); i++) {
            newNumber.number.push_back(~number[i]);
        }

        return newNumber;
    }

    BigNumber XOR(BigNumber secondOperand) {
        BigNumber newNumber("");

        for (int i = 0; i < number.size(); i++) {
            newNumber.number.push_back(number[i] ^ secondOperand.number[i]);
        }

        return newNumber;
    }

    BigNumber OR(BigNumber secondOperand) {
        BigNumber newNumber("");

        for (int i = 0; i < number.size(); i++) {
            newNumber.number.push_back(number[i] | secondOperand.number[i]);
        }

        return newNumber;
    }

    BigNumber AND(BigNumber secondOperand) {
        BigNumber newNumber("");

        for (int i = 0; i < number.size(); i++) {
            newNumber.number.push_back(number[i] & secondOperand.number[i]);
        }

        return newNumber;
    }
};