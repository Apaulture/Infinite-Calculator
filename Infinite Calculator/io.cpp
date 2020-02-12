//
//  io.cpp
//  Infinite Calculator
//
//  Created by Apaulture on 2/12/20.
//  Copyright © 2020 Apaulture. All rights reserved.
//

#include "io.hpp"
#include "operation.hpp"
#include <iostream>

void processInput(char operation)
{
    std::cout << "Enter operands: ";
    
    int firstNum{};
    int secondNum{};
    std::cin >> firstNum >> secondNum;
    
    switch (operation)
    {
        case '*':
            std::cout << firstNum << operation << secondNum << " = " << multiply(firstNum, secondNum) << '\n';
            break;
        case '/':
            std::cout << firstNum << operation << secondNum << " = " << divide(firstNum, secondNum) << '\n';
            break;
        case '+':
            std::cout << firstNum << operation << secondNum << " = " << add(firstNum, secondNum) << '\n';
            break;
        case '-':
            std::cout << firstNum << operation << secondNum << " = " << minus(firstNum, secondNum) << '\n';
            break;
    }
}
