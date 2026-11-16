void removeNonAlphanumeric(std::vector<char>& v) {
    // 1. Σβήνει ό,τι δεν είναι γράμμα ή αριθμός
    v.erase(
        std::remove_if(v.begin(), v.end(), [](unsigned char c) {
            return !std::isalnum(c);
        }),
        v.end()
    );

    // 2. Μετατρέπει όσους χαρακτήρες έμειναν σε πεζά (lowercase)
    std::transform(v.begin(), v.end(), v.begin(), [](unsigned char c) {
        return std::tolower(c);
    });
}

class Solution {
public:
    bool isPalindrome(string s) {
        cout << s.size() << "\n"; 


        vector<char> full_string;
        for (auto &c : s){
            full_string.push_back(c);
        }

        removeNonAlphanumeric(full_string);
        int string_size = full_string.size();
        cout << string_size << "\n";

        vector<char> left_sub_string;
        vector<char> right_sub_string;
        if (string_size % 2){            
            int count = 1;
            for (auto& c : full_string){
                if(count > string_size/2)
                    break;
                left_sub_string.push_back(c);
                cout << c;
                count++;
            }
        
            count = 1;
            for (auto it = full_string.rbegin(); it != full_string.rend(); ++it) {
                if (count > string_size / 2)
                    break;
                right_sub_string.push_back(*it);
                cout << *it;
                count++;
            }
        }

        if (string_size % 2 == 0){
            int count = 0;
            for (auto& c : full_string){
                if(count == string_size/2)
                    break;
                cout << c;
                left_sub_string.push_back(c);
                count++;
            }
            
            count = 0;
            for (auto it = full_string.rbegin(); it != full_string.rend(); ++it) {
                if (count == string_size / 2)
                    break;
                cout << *it;
                right_sub_string.push_back(*it);
                count++;
            }
        }

        if (left_sub_string == right_sub_string){
            return true;
        }

        return false;
    }
};
