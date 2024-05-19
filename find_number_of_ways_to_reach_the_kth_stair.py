class Solution:
    def waysToReachStair(self, k: int) -> int:
        J, location, res = 64, 1, 0
        for j in range(J):
            if location >= k:
                extra = location - k
                res += math.comb(j + 1, extra)
            location += 1 << j
        return res

# class Solution:
#     def waysToReachStair(self, k: int) -> int:
#         @cache
#         def dfs(i, j, b):
#             if i > k and (i>k+1 or not b):
#                 return 0
#             res = i == k
#             res += dfs(i+(1<<j), j+1, 1)
#             if b:
#                 res+=dfs(i-1, j, 0)
#             return res
#         return dfs(1, 0, 1)