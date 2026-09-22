class Solution {
public:
    string addBinary(string a, string b) {
    std::string result = "";
    int i = a.length() - 1;
    int j = b.length() - 1;
    int carry = 0;

    // Loop through both strings from right to left, or while there is a carry
    while (i >= 0 || j >= 0 || carry) {
        int sum = carry;

        if (i >= 0) {
            sum += a[i] - '0'; // Convert character to integer (0 or 1)
            i--;
        }
        if (j >= 0) {
            sum += b[j] - '0'; // Convert character to integer (0 or 1)
            j--;
        }

        // The current bit value is sum % 2 (either 0 or 1)
        result += (sum % 2) + '0';

        // Calculate the new carry (sum / 2 will be 1 if sum was 2 or 3)
        carry = sum / 2;
    }

    // Since digits were added from right to left, reverse the result
    std::reverse(result.begin(), result.end());
    return result;
    }
};