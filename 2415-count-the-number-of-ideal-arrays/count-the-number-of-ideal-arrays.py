class Solution(object):
    def idealArrays(self, n, maxi):
        mod = 10**9 + 7
        m = min(n, 14)
        dp = [[0] * (m+1) for _ in range(maxi+1)]
        for i in range(1, maxi+1):
            dp[i][1] = 1
            j = 2
            while i * j <= maxi:
                for k in range(1, m):
                    dp[i*j][k+1] += dp[i][k]
                j += 1
        fact = [1] * n
        for i in range(1, n):
            fact[i] = fact[i-1] * i % mod
        invfact = [1] * n
        invfact[n-1] = pow(fact[n-1], mod-2, mod)
        for i in range(n-1, 0, -1):
            invfact[i-1] = invfact[i] * i % mod
        res = 0
        f_n1 = fact[n-1]
        for i in range(1, maxi+1):
            for k in range(1, m+1):
                res = (res + dp[i][k] * f_n1 % mod * invfact[k-1] % mod * invfact[n-k] % mod) % mod
        return res