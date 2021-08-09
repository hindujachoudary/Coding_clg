//main function remains same but in subsets func instead of storing dp[i][su] and retrieving dp[i][su]  use dp[i][su+1000]

class Solution {
public:
    
    //with offset of 1000

    int n, s, cnt=0, dp[21][2001], ans=0;
    vector<int>a;
    int subsets(int i, int su){
        
        if(i==n){
            if(su==s)
                return 1;
            else
                return 0;
        }
        else{
            if(dp[i][su+1000]!=-1)
                return dp[i][su+1000];
            else{
                ans=subsets(i+1,su+a[i])+subsets(i+1,su-a[i]);
                return dp[i][su+1000]=ans;
            }
        }
    }

//without offset TLE

class Solution {
public:
    
    int n, s, cnt=0, ans=0;
    vector<int>a;
    int subsets(int i, int su){
        
        if(i==n){
            if(su==s)
                return 1;
            else
                return 0;
        }
        else{
            ans=subsets(i+1,su+a[i])+subsets(i+1,su-a[i]);
            return ans;
        }
        
    }
    


    int findTargetSumWays(vector<int>& nums, int S) {    
        n=nums.size(), s=S;
        a=nums;
        memset(dp,-1,sizeof(dp));
        return subsets(0,0);
        
    }
};