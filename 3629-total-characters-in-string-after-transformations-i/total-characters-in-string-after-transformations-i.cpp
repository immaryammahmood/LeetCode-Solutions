// precompute, dp
const int MOD = 1e9 + 7;
const int MAX_T = 1e5;
vector<int> init() {
    vector<int> DP(MAX_T + 26);
    for (int i = 0; i < 26; ++i) {
        DP[i] = 1;
    }
    for (int i = 26; i < size(DP); ++i) {
        DP[i] = (DP[i - 26] + DP[(i - 26) + 1]) % MOD;
    }
    return DP;
}

const auto& DP = init();
class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        int result = 0;
        for (const auto& x : s) {
            result = (result + DP[(x - 'a') + t]) % MOD;
        }
        return result;
    }
};