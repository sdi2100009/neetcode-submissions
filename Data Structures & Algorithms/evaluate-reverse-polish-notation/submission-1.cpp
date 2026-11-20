#include <string_view>




class Solution {
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
            if (!myStack.empty())
                if(token.size() == 1 && symbols.find(token) != std::string_view::npos) {
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
