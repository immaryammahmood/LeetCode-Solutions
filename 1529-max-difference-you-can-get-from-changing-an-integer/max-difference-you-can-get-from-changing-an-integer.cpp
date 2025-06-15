class Solution {
public:
    int n;
    static consteval array<int, 10> pow10(){
        array<int, 10> ans={1};
        for (int i=1; i<10; i++)
            ans[i]=ans[i-1]*10;
        return ans;
    }   

    int maxDiff(int num) {
        constexpr array<int, 10> tens=pow10();
        int T=*upper_bound(tens.begin(), tens.end(), num)/10;;
        int a=-1, b=-1, x=0, y=0;
        int c=num/T==1?0:1;// convert b=c look first digit==1 or not
        for( int t=T; t>=1; num%=t, t/=10){
            const int d=num/t;
            if ( a==-1&& d!=9){// for max
                a=d;
                x+=9*t;
            }
            else if (d==a) x+=9*t;
            else x+=d*t;

            if (b==-1 && d!=0 && d!=1){// for min
                b=d;
                y+=c*t;
            }
            else if (d==b) y+=c*t;
            else y+=d*t;
        }
        return x-y;
    }
};