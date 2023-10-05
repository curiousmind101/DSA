#include<iostream>
#include<string>
#include<cmath>
using namespace std;


// Question 1
int LootHouses(int n, int *arr){
    if(n <= 0){                                      //Base Case
        return 0;
    }

    int first = LootHouses(n-2, arr+2)+arr[0];
    int sec = LootHouses(n-1, arr+1);

    return max(first, sec);
}

int LootHouses_mem(int n, int *arr, int *output){              //
    if(n<=0){
        return 0;
    }
    if(output[n] != -1){
        return output[n];
    }
    int x = LootHouses_mem(n-2, arr+2, output)+arr[0];
    int y = LootHouses_mem(n-1, arr+1, output);
    output[n] = max(x, y);
    return output[n];
}

int LootHouses_DP(int n, int *arr){
    int *ans = new int[n+1];
    ans[0]= 0;
    ans[1] = arr[0];
    for(int i=2; i<=n; i++){
        int x = ans[i-2]+arr[i-1];
        int y = ans[i-1];
        ans[i] = max(x, y);
    }
    return ans[n];
}

void LootHouses_Start(){
    int n;
    cin>>n;
    int *arr = new int[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    int *output = new int[n+1];
    for(int i=0; i<=n; i++){
        output[i] = -1;
    }
    cout<<LootHouses(n, arr)<<"\n";
    cout<<LootHouses_mem(n, arr, output)<<"\n";
    cout<<LootHouses_DP(n, arr)<<"\n";
    delete [] output;
}

//Question 2

int LIS(int n, int *arr){
    int *output = new int[n];
    output[0] = 1;
    for(int i=1; i<n; i++){
        output[i] = 1;
        for(int j=i-1; j>=0; j--){
            if(arr[j] >= arr[i]){
                continue;
            }
            int possibleans = output[j]+1;
            if(possibleans > output[i]){
                output[i] = possibleans;
            }
        }
    }
    int best = 0;
    for(int i=0; i<n; i++){
        if(best < output[i]){
            best = output[i];
        }
    }
    delete [] output;
    return best;
}
void LIS_start(){
    int n;
    cin>>n;
    int * arr = new int[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    int ans = LIS(n, arr);
    delete [] arr;
    cout<< ans;
}


//Helper function
int getAllWaysHelper(int remainingSum, int power, int base){              // Copied from GFG!!  //Working on Online Compiler
	//calculate power
	int result = pow(base, power);
	
	if(remainingSum == result){
        cout<<base<<endl;
        return 1;
    }
		
	if(remainingSum < result){
        return 0;
    }
	//Two recursive calls one to include current base's power in sum another to exclude
	int x = getAllWaysHelper(remainingSum - result, power, base + 1);
	int y = getAllWaysHelper(remainingSum, power, base+1);
	return (x + y);
}

int getAllWays(int sum, int power) {
	return getAllWaysHelper(sum, power, 1);
}

void Allpossibleways_start(){
    int a, b;
    cin>>a>>b;
    cout<<getAllWays(a,b);
}

int WaystoMakeCoinChange(int n, int *arr, int m){
    if(m == 0){
        return 1;
    }
    if(n<=0){
        return 0;
    }
    if(arr[n-1]<=m){
        return WaystoMakeCoinChange(n, arr, m-arr[n-1])+WaystoMakeCoinChange(n-1, arr, m);
    }
    return WaystoMakeCoinChange(n-1, arr, m);
}

int WaystoMakeCoinChangeDP(int n, int *arr, int m){
    int **dp = new int*[n+1];
    for(int i=0; i<=n; i++){
        dp[i] = new int[m+1];
    }
    for(int i=0; i<=m; i++){
        dp[0][i]= 0; 
    }
    for(int i=0; i<=n; i++){
        dp[i][0]= 1; 
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(arr[i-1]<=j){
                dp[i][j] = dp[i][j-arr[i-1]] + dp[i-1][j];
            }else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    int ans =  dp[n][m];
    for(int i=0; i<=n; i++){
        delete dp[i];
    }
    delete [] dp;
    return ans;
}
void WaystoMakeCoinChange(){
    int n;
    cin>>n;
    int *arr = new int[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    int m;
    cin>>m;
    cout<<WaystoMakeCoinChangeDP(n, arr, m);
    delete [] arr;
}

//Matrix Chain Multiplication
int MCM_rec(int s, int e, int *arr){
    if(s>=e-1){
        return 0;
    }
    int mini = INT32_MAX;
    for(int i=s+1; i<e; i++){
        int sambhavna = (MCM_rec(s, i, arr)+MCM_rec(i, e, arr)+(arr[s]*arr[i]*arr[e]));
        if(sambhavna<mini){
            mini = sambhavna;
        }
    }
    return mini;
}
int MCM_mem(int s, int e, int *arr, int **memo){
    if(s>=e-1){
        return 0;
    }
    if(memo[s][e] != -1){
        return memo[s][e];
    }
    int mini = INT32_MAX;
    for(int i=s+1; i<e; i++){
        int sambhavna = (MCM_mem(s, i, arr, memo)+MCM_mem(i, e, arr, memo)+(arr[s]*arr[i]*arr[e]));
        if(sambhavna<mini){
            mini = sambhavna;
        }
    }
    memo[s][e] = mini;
    return mini;
}

int MCM_DP(int n, int *arr){                          //Not Completed Yet
}


int MCM(int n, int *arr){
    int **memo = new int*[n+1];
    for(int i=0; i<=n; i++){
        memo[i] = new int[n+1];
        for(int j=0; j<=n; j++){
            memo[i][j] = -1;
        }
    }
    //return MCM_rec(0, n, arr);    //Recursion
    //int ans = MCM_mem(0, n, arr, memo);
    int ans = MCM_DP(n, arr);
    for(int i=0; i<=n; i++){
        delete memo[i];
    }
    delete memo;
    return ans;
}

int MCM_start(){
    int n;
    cin>>n;
    int *arr = new int[n+1];
    for(int i=0; i<=n; i++){
        cin>>arr[i];
    }
    cout<<MCM(n, arr);
    delete [] arr;
}

//Coin Tower

bool CoinTower(int n, int x, int y){                   //Solve after Reading XOR
    if(n==0){
        return true;
    }
    bool ans = CoinTower(n-1, x, y);
    if(n-x >= 1){
        ans^CoinTower(n-x, x, y);
    }
    if(n-y >= 1){
        ans^CoinTower(n-y, x, y);
    }
    return ans;
}
void CoinTowerStart(){
    int n, x, y;
    cin>>n>>x>>y;
    return;
}


//Question 6
int MaxSquareMatrix(int m, int n, int **arr){
    int **dp = new int*[m];
    for(int i=0; i<m; i++){
        dp[i] = new int[n];
    }
    int maxi = 0;
    for(int i=0; i<m; i++){
        if(arr[i][0] == 0){
            dp[i][0] = 1;
            maxi = 1;
        }else{
            dp[i][0] = 0;
        }
    }
    for(int j=1; j<n; j++){
        if(arr[0][j] == 0){
            dp[0][j] = 1;
            maxi = 1;
        }else{
            dp[0][j] = 0;
        }
    }
    for(int i=1; i<m; i++){
        for(int j=1; j<n; j++){
            if(arr[i][j] == 1){
                dp[i][j] = 0;
            }else{
                dp[i][j] = min(dp[i-1][j], min(dp[i-1][j-1], dp[i][j-1]))+1;
            }
            if(dp[i][j] > maxi){
                maxi = dp[i][j];
            }
        }
    }
    for(int i=0; i<m; i++){
        delete dp[i];
    }
    delete [] dp;
    return maxi;
}
void MaxSquareMatrix(){
    int m, n;
    cin>>m>>n;
    int **arr = new int*[m];
    for(int i=0; i<m; i++){
        arr[i] = new int[n];
        for(int j=0; j<n; j++){
            cin>>arr[i][j];
        }
    }
    cout<<MaxSquareMatrix(m, n, arr);
    for(int i=0; i<m; i++){
        delete arr[i];
    }
    delete [] arr;
    return;
}


//Question7

int ShortestSubsequence(string s, string t){  //Recursion
    //Base Case
    if(s.size() == 0){
        return INT32_MAX-1000;
    }

    if(t.size() <= 0){             //if t is empty 
        return 1;                  // As per Question the We need find Shortest SubSe - That could be 1;
    }

    //Search First Character
    int i;
    for(i=0; i<t.size(); i++){
        if(s[0] == t[i]){
            break;
        }
    }
    if(i == t.size()){             //Character not found - Means that is uncommon
        return 1;
    }

    return min(ShortestSubsequence(s.substr(1), t), 1+ShortestSubsequence(s.substr(1), t.substr(i+1)));
    //https://www.geeksforgeeks.org/shortest-uncommon-subsequence/
}
int ShortestSubsequence_mem(string s, string t, int** memo){
    int m = s.length();
    int n = t.length();
    if(m == 0){
        return INT32_MAX-1000;
    }

    if(n <= 0){                    //if t is empty 
        return 1;                  // As per Question the We need find Shortest SubSe - That could be 1;
    }

    if(memo[m][n] != -1){
        return memo[m][n];
    }
    //Search First Character
    int i;
    for(i=0; i<n; i++){
        if(s[0] == t[i]){
            break;
        }
    }
    if(i == n){             //Character not found - Means that is uncommon
        memo[m][n] = 1;
        return 1;
    }

    memo[m][n] = min(ShortestSubsequence(s.substr(1), t), 1+ShortestSubsequence(s.substr(1), t.substr(i+1)));
    return memo[m][n];
}
int ShortestSubSequenceDP(string s, string t){
    int m = s.length();
    int n = t.length();
    int **dp = new int*[m+1];
    for(int i=0; i<=m; i++){
        dp[i] = new int[n+1];
    }
    for(int j=0; j<=n; j++){
        dp[0][j] = INT32_MAX-1000;
    }
    for(int i=1; i<=m; i++){
        dp[i][0] = 1;
    }

    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){
            char ch = s[i-1];
            int k;
            for(k=j-1; k>=0; k--){
                if(ch == t[k]){
                    break;
                }
            }
            if(k == -1){             //Character not found - Means that is uncommon
               dp[i][j] = 1;
            }

            dp[i][j] = min(dp[i-1][j], 1+dp[i-1][k]);
        }
    }
    int ans = dp[m][n];
    for(int i=0; i<=m; i++){
        delete dp[i];
    }
    delete [] dp;
    return ans;
}
void ShortestSubsequence_start(){       //Runnig Fine on GFG 
    string s, t;
    cin>>s>>t;

    int **memo = new int*[s.size()+1];
    for(int i=0; i<=s.size(); i++){
        memo[i] = new int[t.size()+1];
        for(int j=0; j<=t.size(); j++){
            memo[i][j] = -1;
        }
    }

    int ans = ShortestSubSequenceDP(s, t);
    if(ans >= INT32_MAX-1000){
        ans = -1;
    }
    cout<<ans;
    for(int i=0; i<=s.size(); i++){
        delete memo[i];
    }
    delete memo;
    return;
}


int main(){
    //LootHouses_Start();
    //LIS_start();
    //Allpossibleways_start();
    //WaystoMakeCoinChange();
    //MCM_start();
    //CoinTower();    Yet to Complete
    MaxSquareMatrix();
    //ShortestSubsequence_start();
    return 0;
}