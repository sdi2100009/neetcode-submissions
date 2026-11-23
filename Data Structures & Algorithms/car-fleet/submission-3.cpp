double stepsToTarget(int target, int position, int speed) {
    return static_cast<double>(target - position) / speed;
}

void sortCarsByPosition(vector<int>& position, vector<int>& speed) {
    int n = position.size();
    vector<pair<int, int>> cars(n);

    // 1. Ένωση σε ζεύγη {position, speed}
    for (int i = 0; i < n; ++i) {
        cars[i] = {position[i], speed[i]};
    }

    // 2. Ταξινόμηση σε αύξουσα σειρά (η std::sort ταξινομεί αυτόματα με βάση το .first)
    sort(cars.begin(), cars.end());

    // 3. Ενημέρωση των αρχικών vectors (προαιρετικό, αν τα χρειάζεσαι ξεχωριστά μετά)
    for (int i = 0; i < n; ++i) {
        position[i] = cars[i].first;
        speed[i] = cars[i].second;
    }
}

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int carFleets = 1;

        sortCarsByPosition(position, speed);

        int myStack[100000];
        int top = -1;

        for (int i = position.size() -1 ; i >= 0 ; --i){
            if(top == -1){
                top++;
                myStack[top] = i;
                continue;
            }

            if (stepsToTarget(target, position[i], speed[i]) <= stepsToTarget(target, position[myStack[top]], speed[myStack[top]])){
                continue;
            }
            
            // Get the Stack Empty
            top = 0;
            myStack[top] = i;            
            carFleets++;

        }


        return carFleets;
    }
};
