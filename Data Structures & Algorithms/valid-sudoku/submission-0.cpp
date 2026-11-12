
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        // Rows
        for (int i = 0; i < 9; i++) {
            set<char> set_rows;

            for (int j = 0; j < 9; j++) {
                char value = board[i][j];

                if (value == '.')
                    continue;

                if (!set_rows.insert(value).second)
                    return false;
            }
        }

        // Columns
        for (int i = 0; i < 9; i++) {
            set<char> set_columns;

            for (int j = 0; j < 9; j++) {
                char value = board[j][i];

                if (value == '.')
                    continue;

                if (!set_columns.insert(value).second)
                    return false;
            }
        }

        // Subarrays (3x3)
        for (int row_start = 0; row_start < 9; row_start += 3) {
            for (int col_start = 0; col_start < 9; col_start += 3) {

                set<char> set_sub_array;

                for (int i = row_start; i < row_start + 3; i++) {
                    for (int j = col_start; j < col_start + 3; j++) {

                        char value = board[i][j];

                        if (value == '.')
                            continue;

                        if (!set_sub_array.insert(value).second)
                            return false;
                    }
                }
            }
        }

        return true;
    }
};
