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

        if (secondOperand.number.size() < number.size()) {
            int difference = number.size() - secondOperand.number.size();
            secondOperand.number = secondOperand.increaseSize(difference);
        }

        for (int i = 0; i < number.size(); i++) {
            newNumber.number.push_back(number[i] ^ secondOperand.number[i]);
        }

        return newNumber;
    }

    BigNumber OR(BigNumber secondOperand) {
        BigNumber newNumber("");

        if (secondOperand.number.size() < number.size()) {
            int difference = number.size() - secondOperand.number.size();
            secondOperand.number = secondOperand.increaseSize(difference);
        }

        for (int i = 0; i < number.size(); i++) {
            newNumber.number.push_back(number[i] | secondOperand.number[i]);
        }

        return newNumber;
    }

    BigNumber AND(BigNumber secondOperand) {
        BigNumber newNumber("");

        if (secondOperand.number.size() < number.size()) {
            int difference = number.size() - secondOperand.number.size();
            secondOperand.number = secondOperand.increaseSize(difference);
        }

        for (int i = 0; i < number.size(); i++) {
            newNumber.number.push_back(number[i] & secondOperand.number[i]);
        }

        return newNumber;
    }

    BigNumber shiftL(int shiftLength) {
        BigNumber newNumber("");

        for (int i = shiftLength; i < number.size(); i++) {
            newNumber.number.push_back(number[i]);
        }

        for (int i = 0; i < shiftLength; i++) {
            newNumber.number.push_back(0);
        }

        return newNumber;
    }

    BigNumber shiftR(int shiftLength) {
        BigNumber newNumber("");

        for (int i = 0; i < shiftLength; i++) {
            newNumber.number.push_back(0);
        }
        for (int i = 0; i < number.size() - shiftLength; i++) {
            newNumber.number.push_back(number[i]);
        }

        return newNumber;
    }

    BigNumber ADD(BigNumber secondOperand) {
        BigNumber newNumber("");

        if (secondOperand.number.size() < number.size()) {
            int difference = number.size() - secondOperand.number.size();
            secondOperand.number = secondOperand.increaseSize(difference);
        }
        else if (number.size() < secondOperand.number.size())
        {
            int difference = secondOperand.number.size() - number.size();
            number = increaseSize(difference);
        }

        int overflow = 0;
        for (int i = number.size() - 1; i >= 0; i--) {
            if (number[i] + secondOperand.number[i] + overflow >= 16)
            {
                newNumber.number.push_back((number[i] + secondOperand.number[i] + overflow) % 16);
                overflow = 1;
            }
            else
            {
                newNumber.number.push_back(number[i] + secondOperand.number[i] + overflow);
                overflow = 0;
            }
        }

        if (overflow == 1)
            newNumber.number.push_back(1);

        std::reverse(newNumber.number.begin(), newNumber.number.end());

        return newNumber;
    }

    std::vector<unsigned long long> increaseSize(int difference) {
        std::vector<unsigned long long> newSecondNumber;

        for (int i = 0; i < difference; i++)
            newSecondNumber.push_back(0);

        for (int i = 0; i < number.size(); i++)
            newSecondNumber.push_back(number[i]);

        return newSecondNumber;
    }
};