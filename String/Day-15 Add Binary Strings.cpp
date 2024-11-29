string addBinary(string& s1, string& s2) {
    int s1_lastchar_index = s1.size() - 1;
    int s2_lastchar_index = s2.size() - 1;
    int carry = 0;
    string result = "";

    // Perform binary addition
    while (s1_lastchar_index >= 0 || s2_lastchar_index >= 0 || carry) {
        int bit1 = (s1_lastchar_index >= 0) ? s1[s1_lastchar_index] - '0' : 0;  // Convert char to int (0 or 1)
        int bit2 = (s2_lastchar_index >= 0) ? s2[s2_lastchar_index] - '0' : 0;
        int sum = bit1 + bit2 + carry;

        result += (sum % 2) + '0';  // Append the result bit (0 or 1)
        carry = sum / 2;  // Calculate carry for next step

        s1_lastchar_index--;
        s2_lastchar_index--;
    }

    // Reverse the result string since we've been adding from the rightmost bit
    reverse(result.begin(), result.end());

    // Remove leading zeros (if any)
    while (result.size() > 1 && result[0] == '0') {
        result.erase(result.begin());
    }

    return result;
    }
