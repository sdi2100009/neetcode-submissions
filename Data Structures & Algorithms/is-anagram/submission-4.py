class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        # anagram = every char appears same num of times
        # hashmap[char] = times_of_appearance 
        s_hashmap = {}
        for char in s:
            s_hashmap[char] = 0

        for char in s:
            s_hashmap[char] += 1 
        print(s_hashmap)


        t_hashmap = {}
        for char in t:
            t_hashmap[char] = 0

        for char in t:
            t_hashmap[char] += 1 
        print(t_hashmap)


        if t_hashmap == s_hashmap:
            return True
        return False