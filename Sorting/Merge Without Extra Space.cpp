void mergeArrays(vector<int>& a, vector<int>& b) {
        int n = a.size(); // Size of array a
        int m = b.size(); // Size of array b
        int i = n - 1;    // Pointer for the last element in a
        int j = 0;        // Pointer for the first element in b

        // Step 1: Compare and swap elements between a and b
        while (i >= 0 && j < m) {
            if (a[i] > b[j]) {
                swap(a[i], b[j]); // Swap elements to maintain the order
            }
            i--;
            j++;
        }

        // Step 2: Sort both arrays
        sort(a.begin(), a.end()); // Sort array a
        sort(b.begin(), b.end()); // Sort array b
    }
