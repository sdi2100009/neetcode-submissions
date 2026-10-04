class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        # We create a Hash Map = {}
        # Hash Map[ nums[i] ]  = i
        # We find the difference = target - nums[i]
        # Search for the difference in the Hash Map. 
        # if difference in Hash Map:
        #       return [ i  ,  Hash Map[ difference ] ]
        hash_map = {}
        length_of_nums = len(nums)
        for i in range (0,length_of_nums):
            difference = target - nums[i]
            if difference in hash_map:
                return [ hash_map[difference] , i ]
            hash_map[nums[i]] = i
        return {}