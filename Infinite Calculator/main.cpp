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
    // Condition to loop through program
    bool containOperator{true};
    
    std::cout << "         *  |  /  |  +  |  -\n\n" << "! To exit, enter anything but operators\n";
    
    // Loop through program here
    do
    {
        int nonOperatorCount{}; // Count number of characters in user input which are operator-exclusive
        std::string userInput{getInput("operator")};
        int inputLength{(int)userInput.length()}; // char length of user input
        
        // Cycle through user inputted string
        for (int i = 1; i <= inputLength; i++)
        {
            // String to character conversion
            switch (userInput[i - 1]) // check at index 0 by subtracting 1
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
            
            // Condition becomes true when char in string is an operator
            if (i != nonOperatorCount)
            {
                i = inputLength; // End loop by setting i to the input length
            }
        }
        
        // If user input do not contain any operators, end loop and exit program
        if (nonOperatorCount == inputLength)
        {
            // No operators input
            std::cout << "> Thank you for using Infinite Calculator\n";
            containOperator = false;
        }
    } while (containOperator);
    
    
    return 0;
}
