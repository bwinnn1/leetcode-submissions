class Solution:
    def isPalindrome(self, s: str) -> bool:
        checked = "".join(c.lower() for c in s if c.isalnum())
        return checked == checked[::-1]