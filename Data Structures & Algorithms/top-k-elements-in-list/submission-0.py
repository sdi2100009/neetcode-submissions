class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        hash_map = {}

        for num in nums:
            hash_map[num] = 0
        for num in nums:
            hash_map[num] += 1
        
        sorted_hash_map = dict(sorted(hash_map.items(), key=lambda item: item[1] , reverse=True))
        
        i = 0
        result_list = []
        for key,value in sorted_hash_map.items():
            result_list.append(key)              
            i += 1
            if i == k:
                break        
        return result_list