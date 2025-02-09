class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int ROWS = matrix.size(), COLS = matrix[0].size();
        int ans = INT_MIN;
        int tempArr[ROWS];

        for (int left = 0; left < COLS; ++left) {
            memset(tempArr, 0, sizeof(tempArr));
            for (int right = left; right < COLS; ++right) {
                for (int up = 0; up < ROWS; ++up)
                    tempArr[up] += matrix[up][right];
                int sum = 0, g = INT_MIN;
                for (int i = 0; i < ROWS; ++i) {
                    sum = max(sum + tempArr[i], tempArr[i]);
                    g = max(g, sum);
                    if (g == k) {
                        return k;
                    }
                }
                if (g < k) {
                    ans = max(ans, g);
                } else {
                    for (int i = 0; i < ROWS; ++i) {
                        sum = 0;
                        for (int j = i; j < ROWS; ++j) {
                            if ((sum += tempArr[j]) <= k) {
                                ans = max(ans, sum);
                            }
                        }
                        if (ans == k) {
                            return k;
                        }
                    }
                }
            }
        }
        return ans;
    }
};
