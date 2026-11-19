char close_for(char c) {
    switch (c) {
        case '(': return ')';
        case '[': return ']';
        case '{': return '}';
        default:  return 0;
    }
}

class Solution {
public:
    bool isValid(string s) {
        std::stack<char> myStack; 
        
        for (auto& c : s){
            
            // if c is an open_symbol {[( then add it to the stack
            if(close_for(c) != 0){
                myStack.push(c);
                continue;
            }

            // if c is a closed_symbol )]} then remove it to the stack (if stack is empty)
            if(myStack.empty() ){
                return false;
            }

            if (close_for(myStack.top()) != c)
                return false;
            
            myStack.pop();
        }

        if (myStack.empty()){
            return true;
        } 
        return false;
    }
};
