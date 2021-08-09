class Solution {
public:
    map<int,int>dp;
    int func(int n){
        if(n==0 || n==1)
            return n;
        if(dp[n]!=0)
            return dp[n];
        return dp[n]=1+min(n%2+func(n/2),n%3+func(n/3));
    }

    int minDays(int n) {
        return func(n);
    }
};
