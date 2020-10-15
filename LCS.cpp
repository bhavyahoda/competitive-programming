string s,t;
    cin>>s>>t;
    int n = s.length()+1;
    int m = t.length()+1;

    int dp[n][m]={0};
    for(int i=0;i<n;i++){
        dp[i][0]=0;
    }
    for(int i=0;i<m;i++){
        dp[0][i] = 0;
    }
    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            if(t[j-1]==s[i-1]){
                dp[i][j] = 1+dp[i-1][j-1];
            }else{
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }