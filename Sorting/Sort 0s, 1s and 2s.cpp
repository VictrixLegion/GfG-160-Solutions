// Initialize pointers:
    // start: Points to the position where the next 0 should go
    // current: Used to traverse the array
    // end: Points to the position where the next 2 should go
    int start = 0, current = 0, end = arr.size() - 1;

    // Traverse the array until 'current' exceeds 'end'
    while (current <= end) {
        if (arr[current] == 0) {
            // If the current element is 0, swap it with the element at 'start'
            // Increment both 'start' and 'current'
            swap(arr[start], arr[current]);
            start++;
            current++;
        } else if (arr[current] == 1) {
            // If the current element is 1, just move to the next element
            current++;
        } else { // arr[current] == 2
            // If the current element is 2, swap it with the element at 'end'
            // Decrement 'end' (but do not increment 'current' because the swapped
            // element from 'end' needs to be checked)
            swap(arr[current], arr[end]);
            end--;
        }
    }
}
