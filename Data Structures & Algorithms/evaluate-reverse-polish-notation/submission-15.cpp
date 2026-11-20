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
       std::stack<float> myStack;
       float result = 0.0;
       for (auto& token : tokens){
            // if token = symbol (we know 100% that stack is not empty)
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
            
            // Get the float num 
            // int is_neg = (token[0] == '-');
            // int sign = is_neg*(-2) + 1;
            // char c = token[is_neg];
            // float num = static_cast<float>(c-'0');
            // num *= sign;
            float num = 0.0f;
            std::from_chars(token.data(), token.data() + token.size(), num);
            myStack.push(num);
        }
        return int(myStack.top());
    }
};
