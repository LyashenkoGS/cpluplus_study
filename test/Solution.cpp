#include <printf.h>
#include <stack>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution {

public:

    void processParenthesis(std::stack<char> &stack1, char &item, char openSign, char closingSign) {
       // printf("process: %c\n", openSign);
        //printf("item: %c\n", item);
        if (item == openSign) {
            stack1.push(item);
        } else if (item == closingSign) {
            if (stack1.empty()) {
                throw "The stack is empty!!";
            }
            char top = stack1.top();
            //printf("Top: %c\n", item);
            if (top == openSign) {
                stack1.pop();
            } else{
                throw "The stack is empty!!";
            }
        }
    }

    bool isValid(string s) {
        //printf("input: %s\n", input.c_str());
        if(s.empty()){
            return true;
        }
        std::vector<char> data(s.begin(), s.end());
        if (data.size() < 2) {
            return false;
        }
        std::stack<char> stack;
        for (auto &item : data) {
            try {
               // printf("item: %c\n", item);
//                for (std::stack<char> dump = stack; !dump.empty(); dump.pop())
//                    std::cout << dump.top() << '\n';
                processParenthesis(stack, item, '(', ')');
                processParenthesis(stack, item, '[', ']');
                processParenthesis(stack, item, '{', '}');

            }
            catch (const char* msg) {
            //cout << msg << endl;
                return false;
         }
        }
        return stack.empty();
    }

};