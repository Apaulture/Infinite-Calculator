//
//  io.cpp
//  Infinite Calculator
//
//  Created by Apaulture on 2/12/20.
//  Copyright © 2020 Apaulture. All rights reserved.
//

#include "io.hpp"
#include <iostream>
#include <vector>

std::string getInput(std::string input)
{
    if (input == "operator")
    {
        std::cout << "> Enter operator: ";
    }
    else if (input == "operands")
    {
        std::cout << "> Enter operands separated by comma: ";
    }
    
    std::string userInput{};
    std::cin >> userInput;
    
    return userInput;
}

int processInput(char operation)
{
    std::string input{getInput("operands")};
    size_t delimPos = 0;
    std::string delim{","};
    
    int result{};
    int operand{};
    std::vector<int> operands;
    
    while ((delimPos = input.find(delim)) != std::string::npos)
    {
        operand = std::stoi(input.substr(0, delimPos)); // extract operand from user input
        operands.push_back(operand); // append operand to operands vector/array
        input.erase(0, delimPos + delim.length());
    }
    
    // perform operation here
    size_t numOperands{operands.size()};
    
    operands.push_back(std::stoi(input)); // append final value to operands vector
    result = operands[0];
    
    for (int i = 1; i <= numOperands; i++)
    {
        switch (operation)
        {
            case '*':
                result *= operands[i];
                break;
            case '/':
                result /= operands[i];
                break;
            case '+':
                result += operands[i];
                break;
            case '-':
                result -= operands[i];
                break;
        }
    }
    
    
    
    return result;
}
