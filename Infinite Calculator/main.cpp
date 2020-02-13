//
//  main.cpp
//  Infinite Calculator
//
//  Created by Apaulture on 2/12/20.
//  Copyright © 2020 Apaulture. All rights reserved.
//

#include "io.hpp"
#include <iostream>

int main()
{
    bool containOperator{true}; // Condition to loop through program
    
    std::cout << "* | / | + | -\n\n" << "! Exit program by entering anything but operators\n";
    
    do
    {
        int nonOperatorCount{}; // Count number of characters in user input which are operator-exclusive
        
        std::cout << "> Enter operator: ";
        
        std::string userInput{};
        std::cin >> userInput;
        
        // Cycle through user inputted string
        for (int i = 0; i < (int)userInput.length(); i++)
        {
            // String to character conversion
            switch (userInput[i])
            {
                case '*':
                {
                    int output{processInput('*')};
                    std::cout << "! Result: " << output << '\n';
                    break;
                }
                case '/':
                {
                    int output{processInput('/')};
                    std::cout << "! Result: " << output << '\n';
                    break;
                }
                case '+':
                {
                    int output{processInput('+')};
                    std::cout << "! Result: " << output << '\n';
                    break;
                }
                case '-':
                {
                    int output{processInput('-')};
                    std::cout << "! Result: " << output << '\n';
                    break;
                }
                // User input does is operation-exclusive
                default:
                    nonOperatorCount++;
                    break;
            }
        }
        
        // If user input do not contain any operators, end loop and exit program
        if (nonOperatorCount == (int)userInput.length())
        {
            // No operators input
            std::cout << "> Thank you for using Infinite Calculator\n";
            containOperator = false;
        }
    } while (containOperator);
    
    
    return 0;
}
