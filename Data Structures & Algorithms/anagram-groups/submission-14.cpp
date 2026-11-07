#include <iostream>
#include <unordered_map>
#include <string>

bool isAnagram(std::string s, std::string t) {
    // 1. Αν δεν έχουν το ίδιο μήκος, δεν είναι αναγράμματα
    if (s.length() != t.length()) {
        return false;
    }

    std::unordered_map<char, int> count_map;
    
    // 2. Καταγράφουμε τη συχνότητα των χαρακτήρων του s
    for (char c : s) {
        count_map[c]++;
    }
    
    // 3. Αφαιρούμε τις συχνότητες με βάση το t
    for (char c : t) {
        // Αν ο χαρακτήρας δεν υπάρχει ή το count έχει γίνει ήδη 0, 
        // σημαίνει ότι το t έχει περισσότερες εμφανίσεις αυτού του χαρακτήρα
        if (count_map[c] == 0) {
            return false;
        }
        count_map[c]--;
    }
    
    // Αν περάσουν όλοι οι έλεγχοι, είναι αναγράμματα
    return true;
}

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