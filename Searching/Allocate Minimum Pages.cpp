// Helper function to check if a given maximum number of pages is feasible
bool isFeasible(vector<int>& arr, int n, int k, int max_pages) {
    int students = 1; // Start with one student
    int pages_sum = 0; // Tracks the total pages assigned to the current student

    for (int i = 0; i < n; i++) {
        // If a single book has more pages than max_pages, allocation is not possible
        if (arr[i] > max_pages) {
            return false;
        }

        // If adding the current book exceeds max_pages, allocate to a new student
        if (pages_sum + arr[i] > max_pages) {
            students++; // Allocate to the next student
            pages_sum = arr[i]; // Start the new student's page count with the current book
            
            // If the number of students exceeds k, allocation is not feasible
            if (students > k) {
                return false;
            }
        } else {
            // Add the current book's pages to the current student's total
            pages_sum += arr[i];
        }
    }

    // If we were able to allocate books within the constraints, return true
    return true;
}

// Main function to find the minimum possible value of the maximum pages
int findPages(vector<int>& arr, int k) {
    int n = arr.size(); // Number of books
    
    // If the number of students is greater than the number of books, allocation is impossible
    if (k > n) return -1;

    // Minimum value for binary search is the maximum single book's pages
    int low = *max_element(arr.begin(), arr.end());
    // Maximum value for binary search is the sum of all pages (assign all books to one student)
    int high = accumulate(arr.begin(), arr.end(), 0);
    
    int result = -1; // To store the final result

    // Binary search to find the optimal solution
    while (low <= high) {
        int mid = low + (high - low) / 2; // Calculate the middle value

        // Check if it is feasible to allocate books with mid as the maximum pages
        if (isFeasible(arr, n, k, mid)) {
            result = mid; // Update the result
            high = mid - 1; // Try for a smaller maximum value
        } else {
            low = mid + 1; // Try for a larger maximum value
        }
    }

    return result; // Return the minimum possible value of the maximum pages
}
