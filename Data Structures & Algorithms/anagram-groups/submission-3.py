class Solution:

    def is_anagram(self,s,t) -> bool:
        s_hash_map = {}
        for c in s:
            s_hash_map[c] = 0 
        for c in s:
            s_hash_map[c] += 1
        
        t_hash_map = {}
        for c in t:
            t_hash_map[c] = 0 
        for c in t:
            t_hash_map[c] += 1

        if s_hash_map == t_hash_map:
            return True
        return False

    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        hash_map = defaultdict(list)
        for string in strs:
            sorted_string = "".join(sorted(string))
            hash_map[sorted_string].append(string)         
        return list(hash_map.values())


