class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result; 
        std::sort(nums.begin() , nums.end());
        for (int i = 0 ; i < nums.size()-1 ; i++){
            if ( i > 0  && nums [i] == nums[i-1])
                continue;
            
            int L = i+1;
            int R = nums.size()-1;
            
            while ( L < R ){
                int sum = nums[L] + nums[R];
                
                if ( sum == -nums[i] ){
                    result.push_back(  {nums[i],nums[L],nums[R]} );
                    L++;
                    while(L < R && nums[L] == nums [L-1]){
                        L++;
                    }
                    R--;
                }
                
                else if (sum > -nums[i]) {
                    R--;
                }
                
                else if ( sum < -nums[i] ) {
                    L++;
                }
            }
        }

        return result;
    }
};
