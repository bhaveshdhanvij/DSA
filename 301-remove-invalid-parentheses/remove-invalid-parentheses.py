class Solution:
    def removeInvalidParentheses(self, s):
        def is_valid(s):
            balance = 0
            for c in s:
                if c == '(':
                    balance += 1
                elif c == ')':
                    balance -= 1
                    if balance < 0:
                        return False
            return balance == 0

        q = {s}
        while True:
            valid = [x for x in q if is_valid(x)]
            if valid:
                return valid

            next_q = set()
            for x in q:
                for i in range(len(x)):
                    if x[i] in '()':
                        next_q.add(x[:i] + x[i + 1:])
            q = next_q