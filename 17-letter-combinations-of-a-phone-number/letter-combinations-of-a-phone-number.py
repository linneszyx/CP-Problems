class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        if not digits:
            return []
        digi = {
            '2':'abc',
            '3':'def',
            '4':'ghi',
            '5':'jkl',
            '6':'mno',
            '7':'pqrs',
            '8':'tuv',
            '9':'wxyz',
        }
        def backtract(idx,comb):
            if idx == len(digits):
                res.append(comb[:])
                return
            for letter in digi[digits[idx]]:
                backtract(idx+1,comb+letter)
        res = []
        backtract(0,"")
        return res