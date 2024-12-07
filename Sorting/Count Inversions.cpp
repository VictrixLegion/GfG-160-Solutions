class Solution {
  public:
    // Function to count inversions in the array.
    int inversionCount(vector<int> &arr) {
        return mergeSortAndCount(arr, 0, arr.size() - 1);
    }

private:
    // Function to merge two halves and count inversions
    long long mergeAndCount(vector<int>& arr, int left, int mid, int right) {
        int n1 = mid - left + 1;
        int n2 = right - mid;

        // Create temporary arrays
        vector<int> leftArr(n1), rightArr(n2);

        for (int i = 0; i < n1; i++)
            leftArr[i] = arr[left + i];
        for (int i = 0; i < n2; i++)
            rightArr[i] = arr[mid + 1 + i];

        int i = 0, j = 0, k = left;
        long long invCount = 0;

        // Merge the two halves and count inversions
        while (i < n1 && j < n2) {
            if (leftArr[i] <= rightArr[j]) {
                arr[k] = leftArr[i];
                i++;
            } else {
                arr[k] = rightArr[j];
                invCount += (n1 - i);  // All remaining elements in leftArr are greater than rightArr[j]
                j++;
            }
            k++;
        }

        // Copy remaining elements of leftArr, if any
        while (i < n1) {
            arr[k] = leftArr[i];
            i++;
            k++;
        }

        // Copy remaining elements of rightArr, if any
        while (j < n2) {
            arr[k] = rightArr[j];
            j++;
            k++;
        }

        return invCount;
    }

    // Function to sort the array and count inversions using merge sort
    long long mergeSortAndCount(vector<int>& arr, int left, int right) {
        long long invCount = 0;
        if (left < right) {
            int mid = left + (right - left) / 2;

            invCount += mergeSortAndCount(arr, left, mid);  // Left half
            invCount += mergeSortAndCount(arr, mid + 1, right);  // Right half

            invCount += mergeAndCount(arr, left, mid, right);  // Merge and count
        }
        return invCount;
    }
};
