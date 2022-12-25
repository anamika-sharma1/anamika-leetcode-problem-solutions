class Solution:
    def answerQueries(self, nums: List[int], queries: List[int]) -> List[int]:
        r = []
        nums.sort();
        
        for i in queries:
            sum = i
            count = 0
            for j in nums:
                if j < sum:
                    sum = sum - j
                    count = count + 1
                elif j == sum:
                    count = count + 1
                    break
                else:
                    break 
            r.append(count)
        
        return r
