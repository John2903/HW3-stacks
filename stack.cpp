//This program will require these data libraries to balance the brackets of a string using a stack - John Le
#include<iostream> 
#include<stack>
#include<string>

// Since std::stack is not being used for a vector/list in this case, then no classes are needed
// This function checks if the expression of brackets/parentheses are balanced and will return true when stack empty. It will return false if not.
bool parenthesesChecker(std::string parentheses_expression) {
    // Creates a stack to push, pop, and see top values of the stack. 
    std::stack<char> stack;

    // uses a standard for loop to iterate through the given string
    for(int i = 0; i < parentheses_expression.size(); i++) {
        // will push the expression if it does not contain balanced parentheses or a string that does not contain any parentheses at all
        if(stack.empty()) {
            stack.push(parentheses_expression[i]);
       }
        // pops when a opening bracket has a pair with a closing bracket when iterating through the string
        else if (stack.top() == '(' && parentheses_expression[i] == ')') {
            stack.pop();
       } else {
        stack.push(parentheses_expression[i]);
       }
    }
    // will return a true if the stack is empty
    if (stack.empty()) {
        return true;
    }
    // if statement is used to stop the program if typed "stop" and returns a false
    else if (parentheses_expression == "stop") {
        return false;
    }
    else {return false; }
}

int main() {
    // while loop is used so that multiple expressions can be entered
    while(true) {
        std::cout << "Enter an expression of parentheses to see if the expression is balanced: ";
        std::string parentheses_expression;
        std::cin >> parentheses_expression;

        // ends the while loop if "stop" is entered
        if (parentheses_expression == "stop") {
            std::cout << "\nParentheses Checker ended";
            return false;
        }
       else if(parenthesesChecker(parentheses_expression)) {
            // if statement checks if the expression is correct or not
            std::cout << "\nThe expression of parentheses is balanced\n\n";
         } else {
            std::cout << "\nThe expression of parentheses is not balanced or the input was incorrect\n\n";
        }
    }
    return 0;
}