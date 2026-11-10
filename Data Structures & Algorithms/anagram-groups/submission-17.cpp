#include <iostream>
#include <unordered_map>
#include <string>

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::unordered_map<string, vector<string>> hash_map;
        vector<vector<string>> result; 

        for (const auto& str : strs){       
            string key(26,0);
            for(const auto& c : str){
                key[c-'a']++;
            }
            hash_map[key].push_back(str);
        }

        for (const auto& pair : hash_map){
            result.push_back(pair.second);
        }

        return result;
    }
};