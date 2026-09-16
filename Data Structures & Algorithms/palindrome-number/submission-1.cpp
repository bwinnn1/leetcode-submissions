class Solution {
public:
    bool isPalindrome(int x) {
        // go from the middle to outward
        // we have odd length number and even length number
        // we check fail once return false immediately

        string value = std::to_string(x);

        string rev = value;

        reverse(rev.begin(), rev.end());
        return value == rev;
    }
};