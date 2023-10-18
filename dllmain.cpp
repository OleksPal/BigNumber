// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <string.h>
#include <sstream>

class BigNumber {
public:
    unsigned long long* number;

    BigNumber(std::string value) {
        setHex(value);
    }

    void setHex(std::string value) {
        int size = value.size() - 2; // (-"0x")
        value.erase(0, 2);

        number = new unsigned long long[size];

        for (int i = size - 1; i >= 0; i--) {
            std::string symbol(1, value[i]);
            number[i] = std::stoi(symbol, 0, 16);
        }
    }

    std::string getHex() {
        int size = sizeof(number) - 2;
        std::string hexNumber = "0x";

        std::ostringstream ss;
        for (int i = 0; i < size; i++) {
            ss << std::hex << number[i];
            hexNumber += ss.str();
        }

        return hexNumber;
    }
};