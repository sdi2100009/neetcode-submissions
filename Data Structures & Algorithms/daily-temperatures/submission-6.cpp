class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> result(temperatures.size(), 0);
        
        const int max_size = 100000;
        std::array<  std::pair<int,int> , max_size> myStack;
        int top = -1;

        myStack[++top] = {temperatures[0],0};

        for(int i = 1 ; i < temperatures.size(); i++){
            while(top != -1){
                if(temperatures[i] > myStack[top].first ){
                    result[myStack[top].second] = i - myStack[top].second;
                    --top;
                }
                else{
                    myStack[++top] = {temperatures[i], i} ;
                    break;
                }
            }
            if (top == -1) 
                myStack[++top] = {temperatures[i],i};
        }
        return result;
    }
};
