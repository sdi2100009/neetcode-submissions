class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        hash_map = defaultdict(list)
        for string in strs:
            
            count =  [0] * 26 
            
            for letter in string:
                count[ ord(letter) - ord('a') ] += 1
            
            hash_map[tuple(count)].append(string)
        
        return hash_map.values()