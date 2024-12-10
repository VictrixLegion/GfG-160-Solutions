int minRemoval(vector<vector<int>> &intervals) {
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });
        int removeCount = 0; 
        int lastEnd = INT_MIN; 
        for (const auto& interval : intervals) {
            if (interval[0] >= lastEnd) {lastEnd = interval[1];} 
            else {removeCount++;}
        }
        return removeCount;
    }
