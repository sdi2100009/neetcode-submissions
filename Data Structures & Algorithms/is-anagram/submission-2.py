class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
  
        s_length = len(s)
        t_length = len(t)

        if (s_length != t_length):
            return False

        # Hash Maps  : [ key , value ]
        # S Hash Map : [ char , count_in_s ]

        s_hash_map = {}
        t_hash_map = {} 
        for i in range(0,s_length):
            s_hash_map[ s[i] ] = 1 + s_hash_map.get(s[i] , 0)
            t_hash_map[ t[i] ] = 1 + t_hash_map.get(t[i] , 0)
        if s_hash_map != t_hash_map:
            return False 
        return True