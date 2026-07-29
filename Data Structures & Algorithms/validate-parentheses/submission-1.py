class Solution:
    def isValid(self, s: str) -> bool:
        stack = []
        closingBracket = {")" : "(", "]" : "[", "}" : "{"}

        for c in s:
            if c not in closingBracket:
                stack.append(c)
            else:
                if stack and stack[-1] == closingBracket[c]:
                    stack.pop()

                else:
                    return False
        
        if stack:
            return False
        return True