int findKthPositive(vector<int>& arr, int k) {
    int low = 0, high = arr.size() - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        int missing_count = arr[mid] - (mid + 1);

        if (missing_count < k) {
            low = mid + 1; // Look for the kth missing in the right half
        } else {
            high = mid - 1; // Look for the kth missing in the left half
        }
    }

    return k + low; // Adjust the missing count based on the current index
}
