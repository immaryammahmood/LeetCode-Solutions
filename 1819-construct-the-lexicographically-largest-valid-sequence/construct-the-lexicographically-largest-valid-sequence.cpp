class Solution {
public:
    vector<int> res;
    bool backtrack(int i, int n, vector<bool>& used) {
        if (i == res.size()) return true;  
        if (res[i] != 0) return backtrack(i + 1, n, used); 
        for (int num = n; num >= 1; num--) {           
            if (used[num]) continue;
            int j = (num == 1) ? i : i + num;  
            if (j < res.size() && res[j] == 0) { 
                res[i] = res[j] = num;
                used[num] = true;
                if (backtrack(i + 1, n, used)) return true;
                res[i] = res[j] = 0;
                used[num] = false;
            }
        }
        return false;
    }

    vector<int> constructDistancedSequence(int n) {
        res.assign(2 * n - 1, 0);
        vector<bool> used(n + 1, false);
        backtrack(0, n, used);
        return res;
    }
};
