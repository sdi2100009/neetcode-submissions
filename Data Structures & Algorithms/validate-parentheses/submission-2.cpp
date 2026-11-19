class Solution {
public:
    bool isValid(string s) {
        std::stack<char> myStack; 
        std::unordered_map<char,char> hash_map;

        // Hash_map[open] = closed
        hash_map['{'] = '}';
        hash_map['['] = ']';
        hash_map['('] = ')';
        
        for (auto& c : s){
            
            // if c is an open_symbol {[( then add it to the stack
            if(hash_map.count(c) > 0){
                myStack.push(c);
                continue;
            }

            // if c is a closed_symbol )]} then remove it to the stack (if stack is empty)
            if(myStack.empty() ){
                return false;
            }

            if (hash_map[myStack.top()] != c){
                return false;
            }            
        
            if (hash_map[myStack.top()] == c){
                myStack.pop();
            }

        }

        if (myStack.empty()){
            return true;
        } 
        return false;
    }
};
