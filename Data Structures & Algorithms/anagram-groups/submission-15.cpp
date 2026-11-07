#include <iostream>
#include <unordered_map>
#include <string>

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::unordered_map<string, vector<string>> hash_map;


        for (const auto& string : strs){
            std::string key(26,0);
            for (const auto& c : string){
                key[c-'a']++;
            }             
            hash_map[key].push_back(string);
        } 

        vector<vector<string>> result;
        for ( const auto& pair : hash_map ){
           
            vector<string> anagrams;
            for ( const auto& value : pair.second ){
                anagrams.push_back(value);
            }
            result.push_back(anagrams);
        }

        return result;
    }
};