class Solution:
    def isPalindrome(self, s: str) -> bool:
        check = "".join(c.lower() for c in s if c.isalnum())
        return check == check[::-1]