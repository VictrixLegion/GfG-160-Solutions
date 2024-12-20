vector<int> spiralOrder(vector<vector<int>>& mat) {
    vector<int> result;
    if (mat.empty()) return result; // Edge case: Empty matrix

    int top = 0, bottom = mat.size() - 1;
    int left = 0, right = mat[0].size() - 1;

    while (top <= bottom && left <= right) {
        // Traverse from left to right
        for (int i = left; i <= right; i++) {
            result.push_back(mat[top][i]);
        }
        top++;

        // Traverse from top to bottom
        for (int i = top; i <= bottom; i++) {
            result.push_back(mat[i][right]);
        }
        right--;

        // Traverse from right to left (if still within bounds)
        if (top <= bottom) {
            for (int i = right; i >= left; i--) {
                result.push_back(mat[bottom][i]);
            }
            bottom--;
        }

        // Traverse from bottom to top (if still within bounds)
        if (left <= right) {
            for (int i = bottom; i >= top; i--) {
                result.push_back(mat[i][left]);
            }
            left++;
        }
    }

    return result;
}
