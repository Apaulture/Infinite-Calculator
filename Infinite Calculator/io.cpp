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

float processInput(char operation)
{
    std::string input{getInput("operands")};
    std::string delim{","};
    std::vector<float> operands;
    float operand{}; // extracted operand
    float result{}; // current result
    
    size_t delimPos{0};
    
    while ((delimPos = input.find(delim)) != std::string::npos)
    {
        operand = std::stof(input.substr(0, delimPos)); // extract operand from user input up to delimiter
        operands.push_back(operand); // append operand to operands vector/array
        input.erase(0, delimPos + delim.length());
    }
    
    // number of operands extracted from user input
    size_t numOperands{(operands.size())};
    
    operands.push_back(std::stof(input)); // append final value to operands vector
    result = operands[0]; // result is assigned the first extracted operand
    
    for (int i = 1; i <= (int)numOperands; i++)
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
