#include <iostream>
#include <unordered_map>


class Solution {
public:
    bool isAnagram(string s, string t) {
        
        std::unordered_map<char, int> hashmap_s;
        int s_size = s.size();
        int t_size = t.size();


        for (int i = 0 ; i < s_size ; i++) {
            char c = s[i];
            hashmap_s.insert({c,0});
        }
        
        for (int i = 0 ; i < s_size ; i++){
            hashmap_s[s[i]]++;
        }


        std::unordered_map<char,int> hashmap_t;
        for (int i = 0 ; i < t_size ; i++){
            char c = t[i];
            hashmap_t[c] = 0;
        }

        for (int i = 0 ; i < t_size ; i++){
            hashmap_t[t[i]]++;
        }

        // Compare hashmap_s , hashmap_t
        // if 1 key is missing in hashmap_s or 1 value is different in hashmap_s from the matched value in hashmap_t return false
        for (const auto& [key_t,value_t] : hashmap_t){
            auto it = hashmap_s.find(key_t);
            if (it == hashmap_s.end() || it->second != value_t)
                return false;
        }

        for (const auto& [key_s,value_s] : hashmap_s){
            auto it = hashmap_t.find(key_s);
            if (it == hashmap_t.end() || it->second != value_s)
                return false;
        }

        return true;
    }
};
