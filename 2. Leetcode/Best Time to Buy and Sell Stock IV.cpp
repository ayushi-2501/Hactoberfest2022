class Solution {
public:
    int dp[2][101][1001];
    
    int solve(int own,int cnt,int i,int k,vector<int> &a){
        int x=0,y=0;
        int n=a.size();
        if(i>=n)
            return 0;

        if(dp[own][cnt][i]!=-1){
            return dp[own][cnt][i];
        }

        if(i==n-1){
            if(own==1){
                // dp[own][cnt][i]
                return dp[own][cnt][i] = a[i];
            }
            
            // return 0;
            return dp[own][cnt][i] = 0;
        }
        if(own==1){
            x=a[i]+solve(0,cnt+1,i+1,k,a);
            y=solve(1,cnt,i+1,k,a);
        }
        else{
            if(cnt<k){
                x=-a[i]+solve(1,cnt,i+1,k,a);
                y=solve(0,cnt,i+1,k,a);
            }
            
        }
        return dp[own][cnt][i] = max(x,y);
        
    }

    
    int maxProfit(int k, vector<int>& prices) {
        memset(dp,-1,sizeof dp);
        return solve(0,0,0,k,prices);
    }
};