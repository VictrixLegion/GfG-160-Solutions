    bool matSearch(vector<vector<int>> &mat, int x) {
    int n = mat.size();       // Number of rows
    if (n == 0) return false; // Handle empty matrix
    int m = mat[0].size();    // Number of columns

    int i = 0, j = m - 1; // Start at the top-right corner

    while (i < n && j >= 0) {
        if (mat[i][j] == x) {
            return true; // Element found
        } else if (mat[i][j] > x) {
            j--; // Move left
        } else {
            i++; // Move down 
            }
    }
    return false; // Element not found
    }
