class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::unordered_map <int,int> hash_map;
        std::vector<int> result;


        for(const auto& num : nums){
            hash_map[num]++;
        }

        priority_queue<pair<int, int>> maxHeap;
        for (const auto& pair : hash_map){
            maxHeap.push({pair.second,pair.first});
        }

        
        while (!maxHeap.empty() and k != 0) {
            // Παίρνουμε το ζευγάρι από την κορυφή
            pair<int, int> p = maxHeap.top(); 
            
            // Τυπώνουμε ξεχωριστά το πρώτο και το δεύτερο στοιχείο
            cout << "(" << p.first << ", " << p.second << ") "; 
            result.push_back(p.second);
            maxHeap.pop();                
            k--;
        }
        cout << endl;


        return result;

    }
};
