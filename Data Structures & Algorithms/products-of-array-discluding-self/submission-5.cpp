class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {


        vector<int> product_before(nums.size(), 1);
        for (int i = 0 ; i < nums.size() ; i++){
            if (i > 0)
                product_before[i] = product_before[i-1] * nums[i-1];  
        }

        vector<int> product_after(nums.size(),1);
        for (int i = nums.size()-1 ; i != -1; i--){
            if (i < nums.size()-1) 
                product_after[i] = product_after[i+1] * nums[i+1];
        }

        vector<int> output(nums.size());
        for (int i = 0 ; i < nums.size() ; i++)
            output[i] = product_before[i] * product_after[i];

        return output; 

    }
};
