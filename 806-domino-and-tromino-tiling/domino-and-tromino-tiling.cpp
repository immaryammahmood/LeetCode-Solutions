class Solution {
public:
    int numTilings(int n) {
        if(n<=2)return n;
        if(n==3)return 5;
        int MOD=1e9+7;
        long long a1=1,a2=2,a3=5;
        for(int i=4;i<=n;i++){
            long long curr = (2 * a3 + a1) % MOD;
            a1=a2;
            a2=a3;
            a3=curr;
        }
        return (int)a3;
    }
};