myList = {
    '2' : 'abc',
    '3' : 'def',
    '4' : 'ghi',
    '5' : 'jkl',
    '6' : 'mno',
    '7' : 'pqrs',
    '8' : 'tuv',
    '9' : 'wxyz'
}

class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        r = []
        t = []
        for c in digits:
            
            if not r:
                for m in myList[c]:
                    r.append(m)
        
            else:
                t = []
                for m in r:
                    for x in myList[c]:
                        t.append(m+x)
                r = t

        return r
