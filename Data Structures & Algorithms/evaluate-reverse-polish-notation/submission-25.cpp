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
       std::stack<int> myStack;
       for (const auto& token : tokens){
            // if token = symbol (we know 100% that stack is not empty)
            if(token.size() == 1 && isMathOperator(token[0])) {
                    int b = myStack.top();
                    myStack.pop();
                    
                    int a = myStack.top();
                    myStack.pop();
              
                    const int result = eval_op(token[0],a,b);
                    myStack.push(result);
                    continue;
            }

            // if token is number push it to myStack
            int num;
            std::from_chars(token.data(), token.data() + token.size(), num);
            myStack.push(num);
        }
        return myStack.top();
    }
};
