class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> result(temperatures.size(), 0);
        
        int myStack[100000];
        int top = -1;
        myStack[++top] = 0;

        for(int i = 1 ; i < temperatures.size(); i++){
            int temp_i = temperatures[i];
            while(top != -1){
                if(temp_i > temperatures[ myStack[top] ] ){
                    result[myStack[top]] = i - myStack[top];
                    --top;
                }
                else{
                    myStack[++top] = i ;
                    break;
                }
            }
            if (top == -1) 
                myStack[++top] = i;
        }
        return result;
    }
};
