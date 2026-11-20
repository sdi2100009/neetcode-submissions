class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> result;

        for (int i = 0 ; i < temperatures.size() ; i++)
            result.push_back(0);
        
 
        
        std::stack<std::pair<int,int>>myStack;
        myStack.push({temperatures[0],0});

        

        for(int i = 1 ; i < temperatures.size(); i++){
            while(!myStack.empty()){
                if(temperatures[i] > myStack.top().first ){
                    result[myStack.top().second] = i - myStack.top().second;
                    myStack.pop();
                }
                else{
                    myStack.push( {temperatures[i], i} );
                    break;
                }
            }
            if (myStack.empty())
                myStack.push( {temperatures[i],i} );
        }


        return result;
    }
};
