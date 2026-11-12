int numbers_that_next_number_exists(int start, const std::unordered_map<int,int>& hash_map){
    // Base Case 
    if (hash_map.count(start+1) == 0)
        return 1;
    return numbers_that_next_number_exists(start+1, hash_map)+1;
}


class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        std::unordered_map<int,int> hash_map;

        // Init hashmap
        for (const auto& num : nums ){
            hash_map[num] = 1;
        }

        // For every number check if its Start of a sequence and save the starts of sequences.
        int max = 0;
        for (const auto& [num, _] : hash_map){
            // For every start of sequence count how many +1 consecutive numbers we can find. 
            if (hash_map.count(num-1) == 0){
                int length_of_consecutive_numbers =  numbers_that_next_number_exists(num, hash_map);
                if (length_of_consecutive_numbers > max)
                    max = length_of_consecutive_numbers;
            }
        }

        return max;
    }
};
