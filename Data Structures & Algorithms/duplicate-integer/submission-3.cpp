#include <iostream>
#include <set>

class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        int i = 0;
        int nums_length = nums.size();
        printf("nums size is: %d\n", nums_length);
        

        std::set<int> Setnums;
        for(i = 0 ; i < nums_length ; i++){
            Setnums.insert(nums[i]);
        }
        
        for(int x : Setnums){
            printf("%d",x);
        }

        if (nums_length > Setnums.size()){
            return true;
        }

        return false;
    }
};