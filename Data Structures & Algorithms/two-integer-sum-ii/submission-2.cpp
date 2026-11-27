class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0;
        int right = numbers.size()-1;
        
        while( left < right ){
            int two_sum = numbers[left] + numbers[right];
            if (two_sum > target){
                right--;
            }

            else if (two_sum < target){
                left++;
            }
            else{
                return {left+1,right+1};
            }
        }


         
        return {-1,-1};
    }
};
