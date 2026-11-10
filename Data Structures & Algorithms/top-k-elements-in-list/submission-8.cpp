class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::unordered_map <int,int> hash_map;
        std::vector<int> result;

        // Init HashMap
        for (const auto& num : nums){
            hash_map[num]++;
        }


        // We will insert: pair[frequency, num] in Max Heap   
        std::priority_queue <std::pair<int,int>> max_heap; 
        for (const auto& pair : hash_map){
            max_heap.push({pair.second,pair.first});
        }


        // We remove everything from max_heap
        while(!max_heap.empty() and k != 0){
            auto pair = max_heap.top(); 
            cout << "(" << pair.first << ", " << pair.second << ")" << "\n";
            max_heap.pop();
            result.push_back(pair.second);
            k--; 
        }

        



        return result;

    }
};
