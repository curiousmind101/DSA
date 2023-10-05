#include<iostream>
#include<stack>
#include<math.h>
using namespace std;

//MinsSteptoOne
int MinStepsTo1(int n){                //Brute Force Recursion
    //Base Case
    if(n<=1){
        return 0;
    }

    int x = MinStepsTo1(n-1);
    int y = INT32_MAX, z = INT32_MAX;
    if(n%3 == 0){
        y = MinStepsTo1(n/3);
    }
    if(n%2 == 0){
        z = MinStepsTo1(n/2);
    }
    return min(x, min(y, z))+1;
}

int MinStepsto1(int n, int *arr){        //Memorization
    //base case
     if(n<=1){
        arr[n] = 0;
        return 0;
    }

    if(arr[n] != -1){
        return arr[n];
    }


    int x = MinStepsTo1(n-1);
    int y = INT32_MAX, z = INT32_MAX;
    if(n%3 == 0){
        y = MinStepsTo1(n/3);
    }
    if(n%2 == 0){
        z = MinStepsTo1(n/2);
    }
    arr[n] = min(x, min(y, z))+1;
    return arr[n];
}
int MinStepsto1(int n){
    int arr[n+1];
    for(int i=0; i<=n; i++){
        arr[i] = -1;
    }
    return MinStepsto1(n, arr);
}

int MinStepto1(int n){
    int *arr = new int[n+1];
    arr[0] = 0;
    arr[1] = 0;

    for(int i=2; i<=n; i++){
        int x = arr[i-1];

        int y = INT32_MAX;
        int z = INT32_MAX;
        if(n%2 == 0){
            y = arr[i/2];
        }
        if(n%3 == 0){
            z = arr[i/3];
        }

        arr[i] = 1+min(x, min(y, z));
    }
    int ans = arr[n];
    delete [] arr;
    return ans;
}

//Count StairCase
int climbStairs(int n) {
        if(n<=2){
            return n;
        }
        int *arr = new int[n+1];
        arr[0] = 1;
        arr[1] = 1;
        arr[2] = 2;
        for(int i=3; i<=n; i++){
            arr[i] = arr[i-1]+arr[i-2]+arr[i-3];
        }
        int ans = arr[n];
        delete [] arr;
        return ans;
}

//Minimum Count
int MinimumCountB(int n){                      //brute force
    if(n <= 0){     //Base Case;
        return 0;
    }
    int mini = INT32_MAX;
    for(int i=1; (i*i)<=n; i++){
        int sqr = i*i;
        mini = min(mini, MinimumCountB(n-sqr));
    }
    return mini+1;
}

int MinimumCountM(int n, int *arr){                      //Memorization
    if(n <= 0){     //Base Case;
        arr[0] = 0;
        return 0;
    }
    if(arr[n] != -1){
        return arr[n];
    }
    int mini = INT32_MAX;
    for(int i=1; (i*i)<=n; i++){
        int sqr = i*i;
        mini = min(mini, MinimumCountM(n-sqr, arr));
    }
    return mini+1;
}

int MinimumCountM(int n){                                //
    if(n<=0){
        return 0;
    }
    int *arr = new int[n+1];
    for(int i=0; i<=n; i++){
        arr[i] = -1;
    }
    int ans = MinimumCountM(n, arr);
    delete [] arr;
    return ans;
}

int MinimumCountDP(int n){                         //DP
    if(n<=1){
        return n;
    }
    int * arr = new int[n+1];
    arr[0] = 0;
    arr[1] = 1;
    arr[2] = 2;
    for(int i=3; i<=n; i++){
        int mini = INT32_MAX;
        for(int j=1; (j*j)<=n; j++){
            int sqr = (j*j);
            mini = min(mini, arr[i-sqr]);
        }
        arr[i] = 1+mini;
    }
    int ans = arr[n];
    delete [] arr;
    return ans;
}

//No. of Balanced BTs

int Howmanytrees(int h){                      //Constrants ka dikkat
    if(h<=1){
        return 1;
    }
    int mod = (int)(pow(10, 9))+7;
    int x = Howmanytrees(h-1);
    int y = Howmanytrees(h-2);
    int temp1 = (int)(((long)(x)*x)%mod);
    int temp2 = (int)((2*(long)(x)*y)%mod);
    int ans = (temp1 + temp2)%mod;
    return ans;
}

int HowManyTrees(int h, int *arr){                  //Memorization
    if(h<=1){ 
        arr[h] = 1;               //base case
        return 1;
    }

    if(arr[h] != -1){
        return arr[h];
    }

    int mod = (int)(pow(10, 9))+7;
    int x = HowManyTrees(h-1, arr);
    int y = HowManyTrees(h-2, arr);
    int temp1 = (int)(((long)(x)*(long)(x))%mod);
    int temp2 = (int)((2*(long)(x)*(long)(y))%mod);
    arr[h] = (temp1 + temp2)%mod;
    return arr[h];
}

int HowManyTrees(int h){
    int *arr = new int[h+1];
    for(int i=0; i<=h; i++){
        arr[i] = -1;
    }
    int ans = HowManyTrees(h, arr);
    delete [] arr;
    return ans;
}

long HowmanyTrees(long h){            //DP
    long *arr = new long[h+1];
    arr[0] = 1;
    arr[1] = 1;
    for(int i=2; i<=h; i++){
        long x = arr[i-1];
        long y = arr[i-2];
        arr[i] = ((long)(x)*x) + (2*(long)(x)*y);
    }
    int ans = arr[h];
    delete [] arr;
    return ans;
}

int MinCPath(int x, int y, int **arr){                     //Incomplete
    int **memory = new int*[x];
    for(int i=0; i<x; i++){
        memory[i] = new int[y];
    }
    memory[x-1][y-1]= arr[x-1][y-1];
    for(int i=x-1; i>=0; i--){
        for(int j = y-1; j>=0; j--){
            int mini = INT32_MAX;
            int a=INT32_MAX, b=INT32_MAX, c=INT32_MAX;
            if(i+1 < x){
                a = memory[i+1][j];
            }
            if(j+1 < y){
                b = memory[i][j+1];
            }
            if(i+1 < x && j+1 < y){
                c = memory[i+1][j+1];
            }
            mini = min(a, min(b,c));
            memory[i][j] = arr[i][j]+mini;
        }
    }
}

int MinCPath(int x, int y, int i, int j, int **arr, int **memory){  //Memorization
    if(i == x-1 && j==y-1){
        memory[i][j] = arr[i][j];
        return arr[i][j];
    }
    if(i >= x || j >= y){
        return INT32_MAX;
    }
    if(memory[i][j] != -1){
        return memory[i][j];
    }
    int a = MinCPath(x, y, i+1, j,arr, memory);
    int b = MinCPath(x, y, i, j+1,arr, memory);
    int c = MinCPath(x, y, i+1, j+1,arr, memory);
    memory[i][j] = min(a, min(b,c))+arr[i][j];
    return memory[i][j];
}

int MinCostPath(int x, int y, int i, int j,int **arr){   //Recursion
    if(i == x-1 && j==y-1){
        return arr[i][j];
    }
    if(i >= x || j >= y){
        return INT32_MAX;
    }
    int a = MinCostPath(x, y, i+1, j,arr);
    int b = MinCostPath(x, y, i, j+1,arr);
    int c = MinCostPath(x, y, i+1, j+1,arr);
    int ans = min(a, min(b,c))+arr[i][j];
    return ans;
}

int MinCostPath(){                          //Initiator
    int M, N;
    cin>>M>>N;
    int **arr = new int*[M];

    for(int i=0; i<M; i++){
        arr[i] = new int[N];
        for(int j=0; j<N; j++){
            cin>>arr[i][j];
        }
    }
    int **memory = new int*[M];
    for(int i=0; i<M; i++){
        memory[i] = new int[N];
        for(int j=0; j<N; j++){
            memory[i][j] = -1;
        }
    }
    //int ans = MinCostPath(M, N,0, 0, arr);
    //return ans;

    //int ans =  MinCPath(M, N, 0, 0, arr, memory);
    //return ans;
    
    int ans =  MinCPath(M, N, arr);
    for(int i=0; i<N; i++){
        delete arr[i];
    }
    delete [] arr;
    for(int i=0; i<N; i++){
        delete memory[i];
    }
    delete [] memory;
    return ans;
}

int LCS(string s, string t){
    if(s.size() == 0 || t.size() == 0){
        return 0;
    }
    if(s[0] == t[0]){
        return 1+LCS(s.substr(1), t.substr(1));
    }
    int a = LCS(s.substr(1), t);
    int b = LCS(s, t.substr(1));
    //int c = LCS(s.substr(1), t.substr(1));             Optional
    //return max(a, max(b,c));
    return max(a, b);
}

int LCS_mem(string s, string t, int **memory){      //Memorization
    int n = s.size();
    int m = t.size();
    if(n == 0 || n == 0){
        return 0;
    }
    if(memory[n][m] != -1){
        return memory[n][m];
    }
    if(s[0] == t[0]){
        memory[n][m] = 1+LCS(s.substr(1), t.substr(1));
        return memory[n][m];
    }
    int a = LCS(s.substr(1), t);
    int b = LCS(s, t.substr(1));
    //int c = LCS(s.substr(1), t.substr(1));             Optional
    //return max(a, max(b,c));
    memory[n][m] = max(a, b);
    return memory[n][m];
}


int LCS_DP(string s, string t){
    int m = s.size()+1;
    int n = t.size()+1;
    int **memory = new int*[m];
    for(int i=0; i<m; i++){
        memory[i] = new int[n];
        for(int j=0; j<n; j++){
            if(i==0 || j==0){
                memory[i][j] = 0;
            }else{
                memory[i][j] = -1;
            } 
        }
    }
    for(int i=1; i<m; i++){
        for(int j=1; j<n; j++){
            if(s[i] == t[j]){
                memory[i][j] = 1+memory[i-1][j-1];
            }else{
                int a = memory[i][j-1];
                int b = memory[i-1][j];
                int c = memory[i-1][j-1];
                memory[i][j] = max(a, max(b,c));
            }
        }
    }
    int ans = memory[m-1][n-1];
    for(int i=0; i<m; i++){
        delete memory[i];
    }
    delete [] memory;
    return ans;
}

int LCS_start(){
    string s, t;
    cin>>s>>t;
    int **memory = new int*[s.size()+1];
    for(int i=0; i<=s.size(); i++){
        memory[i] = new int[t.size()+1];
        for(int j=0; j<=t.size(); j++){
            memory[i][j] = -1;
        }
    }
    //return LCS(s, t); 
    //return LCS_mem(s, t, memory);
    int ans = LCS_DP(s, t);
    for(int i=0; i<=t.length(); i++){
        delete memory[i];
    }
    delete [] memory;
    return ans;
}

//Edit Distance 
int EditDistance(string s, string t){
    if(s.size() == 0 || t.size() == 0){
        int m = s.size(), n = t.size();
        return max(m, n);
    }
    if(s[0] == t[0]){
        return EditDistance(s.substr(1), t.substr(1));
    }
    int x = EditDistance(s.substr(1), t)+1;
    int y = EditDistance(s, t.substr(1))+1;
    int z = EditDistance(s.substr(1), t.substr(1))+1;
    return min(x, min(y,z));
}

//Memoization
int EditDistance_mem(string s, string t, int **memory){
    int m = s.size();
    int n = t.size();
    if(m == 0 || n == 0){
        return max(m, n);
    }
    if(memory[m][n] != -1){
        return memory[m][n];
    }
    int ans;
    if(s[0] == t[0]){
        ans = EditDistance_mem(s.substr(1), t.substr(1), memory);
    }else{
        //Insert
        int x = EditDistance_mem(s.substr(1), t, memory)+1;
        //delete
        int y = EditDistance_mem(s, t.substr(1), memory)+1;
        //Replace 
        int z = EditDistance_mem(s.substr(1), t.substr(1), memory)+1;
        ans = min(x, min(y, z));
    } 
    memory[m][n] = ans;
    return ans;
}

//DP Solution
int EditDistance_DP(string s, string t){
    int m = s.size();
    int n = t.size();
    int**dp = new int*[m+1];
    for(int i=0; i<=m; i++){
        dp[i] = new int[n+1];
    }
    for(int i=0; i<=n; i++){
        dp[0][i] = i;
    }
    for(int i=1; i<=m; i++){
        dp[i][0] = i;
    }
    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){
            if(s[i] == t[j]){
                dp[i][j] = dp[i-1][j-1];
            }else{
                int x = dp[i-1][j]+1;
                int y = dp[i][j-1]+1;
                int z = dp[i-1][j-1]+1;
                dp[i][j] = min(x, min(y,z));
            }
        }
    }
    int ans = dp[m][n];
    for(int i=0; i<=m; i++){
        delete dp[i];
    }
    delete [] dp;
    return ans;
}


//Edit Distance starter
int EditDistance_st(){
    string s, t;
    cin>>s>>t;
    int m = s.size();
    int n = t.size();
    int **memory = new int*[m+1];
    for(int i=0; i<=m; i++){
        memory[i] = new int[n+1];
        for(int j=0; j<=n; j++){
            memory[i][j] = -1; 
        }
    }
    //return EditDistance(s, t);
    //int ans =  EditDistance_mem(s, t, memory);
    for(int i=0; i<=t.size(); i++){
        delete memory[i];
    }
    delete [] memory;
    //return ans;
    return EditDistance_DP(s, t);
}

int Knapsack(int n, int *w, int *v, int W){                   //n - number of variables , w - weight of elements, v- values,
    //Base Case                                                //W - maxWeight
    if(n == 0 || W <= 0){
        return 0;
    }
    if(w[0] > W){
        return Knapsack(n-1, w+1, v+1, W);
    }

    int smallcase1 = Knapsack(n-1, w+1, v+1, W-w[0])+v[0];
    int smallcase2 = Knapsack(n-1, w+1, v+1, W);

    return max(smallcase1, smallcase2);
}


int Knapsack_start(){
    int n;
    cin>>n;
    int w[n];
    for(int i=0; i<n; i++){
        cin>>w[i];
    }
    int v[n];
    for(int i=0; i<n; i++){
        cin>>v[i];
    }
    int maxWeight;
    cin>>maxWeight;
    return Knapsack(n, w, v, maxWeight);
}

int main(){
    //int n;
    //cin>>n;
    //cout<<MinStepsto1(n);
    //cout<<climbStairs(n);
    //cout<<MinimumCountB(n)<<endl;
    //cout<<MinimumCountM(n)<<endl;
    //cout<<MinimumCountDP(n)<<endl;
    //cout<<HowmanyTrees(n);
    //cout<<MinCostPath();
    //cout<<LCS_start();
    //cout<<EditDistance_st();
    cout<<Knapsack_start()<<endl;
    return 0;
}

/*int MinStepto1(int n){             //Brute Force
    if(n == 1){
        return 0;
    }
    if(n==3 || n==2){
        return 1;
    }

    if(n%3 == 1){
        return MinStepto1(n-1)+1;
    }
    if(n%3 == 0){
        return MinStepto1(n/3)+1;
    }
    if(n%2 == 0){
        return MinStepto1(n/2)+1;
    }
    return MinStepto1(n-1)+1;
}

int MinStepto1(int n, int *arr){             //Memorization
    if(n == 1){
        return 0;
    }
    if(n==3 || n==2){
        return 1;
    }

    if(arr[n] != -1){
        return 1;
    }

    if(n%3 == 1){
        arr[n] = MinStepto1(n-1)+1;
        return arr[n];
    }
    if(n%3 == 0){
        arr[n] =  MinStepto1(n/3)+1;
        return arr[n];
    }
    if(n%2 == 0){
        arr[n] = MinStepto1(n/2)+1;
        return arr[n];
    }
    arr[n] = MinStepto1(n-1)+1;
    return arr[n];
}
int MinStepto1t(int n){
    int arr[n+1];
    for(int i=0; i<=n; i++){
        arr[i] = -1;
    }
    return MinStepto1(n, arr);
}

int MinSteptoone(int n, int *arr){             //DP
    arr[1] = 0;

    for(int i=2; i<=n; i++){
        int x = arr[i-1];

        int y = INT32_MAX;
        int z = INT32_MAX;
        if(n%2 == 0){
            y = arr[i/2];
        }
        if(n%3 == 0){
            z = arr[i/3];
        }

        arr[i] = 1+min(x, min(y, z));
    }
    
}


int MinStepto1t(int n){
    int arr[n+1];
    for(int i=0; i<=n; i++){
        arr[i] = -1;
    }
    return MinSteptoone(n, arr);
}*/