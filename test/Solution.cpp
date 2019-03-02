#include <printf.h>
#include <stack>
#include <string>

using namespace std;
class Solution {

public:

void processParenthesis(std::stack<char> &stack1, char &item, char openSign, char closingSign) {
   // printf("%c\n", item);
    if (item == openSign) {
        stack1.push(item);
    } else if (item == closingSign) {
        char top = stack1.top();
        //printf("Top: %c\n", item);
        if (top == openSign) {
            stack1.pop();
        }
    }
}

bool isValid(string s){
    //printf("input: %s\n", input.c_str());
    char arr[s.size()];
    strcpy(arr, s.c_str());
    std::stack<char> stack;
    for (auto &item : arr) {
        processParenthesis(stack,item,'(',')');
        processParenthesis(stack,item,'[',']');
        processParenthesis(stack,item,'{','}');
    }
    return stack.empty();
}

};