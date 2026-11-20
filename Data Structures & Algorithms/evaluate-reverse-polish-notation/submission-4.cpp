#include <string_view>




class Solution {
    bool isMathOperator(char symbol){
        switch (symbol){
            case '+':
            case '-':
            case '*':
            case '/':
                return true;
        }
        return false;
    }

    int eval_op(char symbol, int a, int b) {
        switch (symbol) {
            case '+': return a + b;
            case '-': return a - b;
            case '*': return a * b;
            case '/': return a / b;
        }
        return 0;
    }
public:
    int evalRPN(vector<string>& tokens) {
       std::string symbols = "+-*/";
       
       std::stack<float> myStack;
       float result = 0.0;
       for (auto& token : tokens){
            // if token = symbol 
                if(token.size() == 1 && isMathOperator(token[0])) {
                    float b = myStack.top();
                    myStack.pop();
                    
                    float a = myStack.top();
                    myStack.pop();
              
                    result = eval_op(token[0],a,b);
                    myStack.push(result);
                    continue;
                }

            // if token is number push it to myStack
            float num = std::stof(token);
            myStack.push(num);

        }
        return int(myStack.top());
    }
};
