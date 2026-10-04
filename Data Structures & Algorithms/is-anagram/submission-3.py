class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        s_length,t_length = (len(s)),(len(t))
        if (s_length != t_length):
            return False
        hash_map = {} 
        for i in range(0,s_length):
            hash_map[s[i]] = s.count(s[i])
        for i in range(0,t_length):
            if t[i] not in hash_map:
                return False
            if t.count(t[i]) != hash_map[t[i]]:
                    return False
        return True