class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int largestRectangle = 0;

        ////
        std::tuple<int,int,int> myStack[200000] = {{0,0,0}};
        
        int areas_right[100000];
        int top = -1;
        for(int i = 0 ; i < heights.size() ; i++){
            if (top == -1){
                top++;
                myStack[top] = {heights[i], 1, i};
                continue;
            }

            if (heights[i] >= std::get<0>(myStack[top]) ){
                top++;
                myStack[top] = {heights[i], 1, i};
                continue;
            }

            while (heights[i] < std::get<0>(myStack[top])){
                if (top == -1) break;
                int height = std::get<0>(myStack[top]);
                int width = std::get<1>(myStack[top]);
                int index = std::get<2>(myStack[top]);

                areas_right[index] = height*width;
                top--;
                if (top == -1) break;
                std::get<1>(myStack[top]) += width;
            }
            // if the stack is empty push it or heights[i] >= stack[top]_current
            top++;
            myStack[top] = { heights[i] , 1, i }; 
        }

        while(top != -1){
            if (top == -1) break;
            int height = std::get<0>(myStack[top]);
            int width = std::get<1>(myStack[top]);
            int index = std::get<2>(myStack[top]);

            areas_right[index] = height*width;
            top--;
            if (top == -1) break;
            std::get<1>(myStack[top]) += width;
        }




        int areas_left[100000];
        top = -1;
        for(int i = heights.size()-1 ; i > -1 ; --i){
            if (top == -1){
                top++;
                myStack[top] = {heights[i], 0, i};
                continue;
            }

            if (heights[i] >= std::get<0>(myStack[top]) ){
                top++;
                myStack[top] = {heights[i], 0, i};
                continue;
            }

            while (heights[i] < std::get<0>(myStack[top])){
                if (top == -1) break;
                int height = std::get<0>(myStack[top]);
                int width = std::get<1>(myStack[top]);
                int index = std::get<2>(myStack[top]);

                areas_right[index] += height*width;
                top--;
                if (top == -1) break;
                std::get<1>(myStack[top]) += width + 1;
            }
            
            // if the stack is empty push it or heights[i] >= stack[top]_current
            top++;
            myStack[top] = { heights[i] , 0, i }; 
        }

        while(top != -1){
            if (top == -1) break;
            int height = std::get<0>(myStack[top]);
            int width = std::get<1>(myStack[top]);
            int index = std::get<2>(myStack[top]);

            areas_right[index] += height*width;
            top--;
            if (top == -1) break;
            std::get<1>(myStack[top]) += width+1;
        }

      

        int max = -1; 
        for (int i = 0 ; i < heights.size() ; i++){
            if (areas_right[i] > max) {
                max = areas_right[i];
            }
        }
        return max;
    }
};
