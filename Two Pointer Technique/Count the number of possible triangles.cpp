int countTriangles(vector<int> &arr) {
    int res = 0;
    sort(arr.begin(), arr.end());

    // Iterate through the array, fixing the largest side at arr[i]
    for (int i = 2; i < arr.size(); ++i) {
      
          // Initialize pointers for the two smaller sides
        int left = 0, right = i - 1; 

        while (left < right) {
          
            if (arr[left] + arr[right] > arr[i]) {
              
                // arr[left] + arr[right] satisfies the triangle inequality,
                // so all pairs (x, right) with (left <= x < right) are valid
                res += right - left; 
              
                  // Move the right pointer to check smaller pairs
                right--; 
            } 
              else {
              
                  // Move the left pointer to increase the sum
                left++; 
            }
        }
    }

    return res;
}