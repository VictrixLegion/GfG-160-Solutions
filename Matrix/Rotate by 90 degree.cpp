void rotateMatrix(vector<vector<int>>& mat) {
    int n = mat.size();

    // Step 1: Transpose the matrix
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) { // Avoid double-swapping
            swap(mat[i][j], mat[j][i]);
        }
    }

    // Step 2: Reverse each column
    for (int j = 0; j < n; j++) {
        int top = 0, bottom = n - 1;
        while (top < bottom) {
            swap(mat[top][j], mat[bottom][j]);
            top++;
            bottom--;
        }
    }
}
