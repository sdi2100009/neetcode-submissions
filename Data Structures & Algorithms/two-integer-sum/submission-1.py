class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        # Hash Map : value , index 

        hash_map = {}
        for i in range (0,len(nums)):
            difference = target - nums[i]
            if difference in hash_map:
                return [hash_map[difference] , i] 
            hash_map[nums[i]] = i
        return {}