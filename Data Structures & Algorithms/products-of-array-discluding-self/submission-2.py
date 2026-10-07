class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:        
        output = [1]*len(nums)
        for j in range(0,len(nums)):
            output[0] = output[0] * nums[j]
        for i in range(0,len(nums)):
            output[i] = output[0]

        for i in range(0,len(nums)):
            if nums[i] != 0:
                output[i] = int(output[i]/nums[i])
            if nums[i] == 0:
                output[i] = 1  
                for j in range(0,len(nums)):
                    if i == j:
                        continue        
                    output[i] = output[i] * nums[j]
        return output