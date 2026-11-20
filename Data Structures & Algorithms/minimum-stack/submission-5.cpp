class MinStack {
    std::stack<int>* myStack;
    std::stack<int>* minStack;
public:
    MinStack() {
        myStack = new std::stack<int>; 
        minStack = new std::stack<int>;
    }
    ~MinStack(){
        delete myStack;
        delete minStack;
    }

    void push(int val) {    

        //Base Case: Stack.empty
        if (myStack->empty()){
            myStack->push(val);
            minStack->push(val);
            return;
        }
    
        // Case: val < min -> push it to minStack also.
        if (val <= minStack->top()){
            myStack->push(val);
            minStack->push(val);
            return;
        }
        
        // all other cases -> push it to myStack
        myStack->push(val);
    }
    
    void pop() {
        if (myStack->empty()){
            return;
        }

        if (minStack->empty()){
            myStack->pop();
            return;
        }
        // if minStack is NOT empty and myStack is NOT empty.
        if (myStack->top() == minStack->top())
            minStack->pop();
        myStack->pop();
    }
    
    int top() {
        int top = myStack->top(); 
        return top;    
    }
    
    int getMin() {
        if (myStack->empty() || minStack->empty())
            return -1;

        return minStack->top();
    }
};
