#include <printf.h>
#include <stack>
#include <string>
#include <iostream>

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

string stringToString(string input) {
    assert(input.length() >= 2);
    string result;
    for (int i = 1; i < input.length() -1; i++) {
        char currentChar = input[i];
        if (input[i] == '\\') {
            char nextChar = input[i+1];
            switch (nextChar) {
                case '\"': result.push_back('\"'); break;
                case '/' : result.push_back('/'); break;
                case '\\': result.push_back('\\'); break;
                case 'b' : result.push_back('\b'); break;
                case 'f' : result.push_back('\f'); break;
                case 'r' : result.push_back('\r'); break;
                case 'n' : result.push_back('\n'); break;
                case 't' : result.push_back('\t'); break;
                default: break;
            }
            i++;
        } else {
            result.push_back(currentChar);
        }
    }
    return result;
}

string boolToString(bool input) {
    return input ? "True" : "False";
}

int main() {
    string line;
    while (getline(cin, line)) {
        string s = stringToString(line);

        bool ret = Solution().isValid(s);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}