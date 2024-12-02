//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> search(string& pattern, string& text){
        int textLength = text.size();
        int patternLength = pattern.size();
        vector<int> lps(patternLength, 0);  // Longest Prefix Suffix array
        vector<int> matchPositions;       // Stores the starting indices of matches

        // Step 1: Build the LPS array for the pattern
        int prefixLength = 0;
        int i = 1;
        while (i < patternLength) {
            if (pattern[i] == pattern[prefixLength]) {
                prefixLength++;
                lps[i] = prefixLength;
                i++;
            } else {
                if (prefixLength != 0) {
                    prefixLength = lps[prefixLength - 1];
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }   

        // Step 2: Search for the pattern in the text
        int textIndex = 0;   // Index for text
        int patternIndex = 0; // Index for pattern
        while (textIndex < textLength) {
            if (text[textIndex] == pattern[patternIndex]) {
                textIndex++;
                patternIndex++;

                // If the full pattern is matched
                if (patternIndex == patternLength) {
                    matchPositions.push_back(textIndex - patternIndex);
                    patternIndex = lps[patternIndex - 1];
                }
            } else {
                // Mismatch after some matches
                if (patternIndex != 0) {
                    patternIndex = lps[patternIndex - 1];
                } else {
                    textIndex++;
                }
            }
        }

        return matchPositions;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S, pat;
        cin >> S >> pat;
        Solution ob;
        vector<int> res = ob.search(pat, S);
        if (res.size() == 0)
            cout << "[]" << endl;
        else {
            for (int i : res)
                cout << i << " ";
            cout << endl;
        }
    }
    return 0;
}

// } Driver Code Ends
