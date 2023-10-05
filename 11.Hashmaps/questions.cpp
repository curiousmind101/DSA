#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>

using namespace std;

int countmax(int* arr, int n){
    int max = 0;
    int maxvalue = 0;
    unordered_map<int, int> newmap;
    for(int i=0; i<n; i++){
        newmap[arr[i]]++;
    }
    for(int i=0; i<n; i++){
        if(newmap[arr[i]] > maxvalue){
            maxvalue = newmap[arr[i]];
            max = arr[i];
        }
    }
    return max;
}

//question2
vector<int> common(int * arr1, int* arr2, int s1, int s2){
    vector<int> ans;
    unordered_map<int, int> m;
    for(int i=0; i<s1; i++){
        m[arr1[i]]++;
    }
    for(int i=0; i<s2; i++){
        if(m[arr2[i]] > 0){
            ans.push_back(arr2[i]);
            m[arr2[i]]--;
        }
    }
    return ans;
}

// Question 3
string removedup(string s){
    unordered_map<char, char> mymap;
    string n;
    for(int i=0; i<s.size(); i++){
        if(mymap.count(s[i]) == 0){
            mymap[s[i]] = s[i];
            n = n+s[i];
        }
    }
    return n;
}

//Question 4
vector<int> longestsubse(vector<int> v){
    unordered_map<int,int> mymap;
    for(int i=0; i<v.size(); i++){
        mymap[v[i]]++;
    }
    int l = 0;
    int maxlength = 0;
    int length = 0;
    int current;
    for (int i = 0; i < v.size(); i++)
    {
       current = v[i];
       if(mymap[current] == 0){
        continue;
       }
       length = 1;
       while(mymap[current]!= 0){
        mymap[current]--;
        current++;
        length++;
       }
       current = v[i];
       while(mymap[current] != 0){
        mymap[current]--;
        current--;
        length++;
       }
       if(length > maxlength){
        maxlength = length;
        l = current+1;
       }
       length = 0;
    }
    v.push_back(l);
    v.push_back(l+maxlength-1);
    
}

int factorial(int n){
    if(n == 0){
        return 1;
    }
    return n*factorial(n-1);
}

int combination(int n, int r){
    int num, den;
    num = factorial(n);
    den = factorial(n-r)*factorial(r);
    return (num/den);
}

// Question 5
int pairdk(vector<int> v, int d){
    int count = 0;
    unordered_map<int, int> mymap;
    for(int i=0; i<v.size(); i++){
        mymap[v[i]]++;
    }
    if(d==0){
        for(int i=0; i<v.size(); i++){
            if(mymap[v[i]]>1){
                count+=combination(mymap[v[i]], 2);
            }
            mymap[v[i]] = 0;
        }
        return count;
    }
    for(int i=0; i<v.size(); i++){
        if(mymap.count(v[i]+d) > 0){
            count += mymap[v[i]]*mymap[v[i]+d];
        }
        if(mymap.count(v[i]-d) > 0){
            count += mymap[v[i]]*mymap[v[i]-d];
        }
        mymap[v[i]] = 0;
    }
    return count;
}

//Question 6

vector<int> longestsubarr(vector<int> v){
    unordered_map<int, int> mymap;
    int sum = 0;
    int l = 0;
    int j = 0;
    int maxi = 0;
    if(v[0] == 0){
        l = 0;
        j = 1;
    }
    vector<int> s;
    for(int i=0; i<v.size(); i++){
        sum += v[i];
        if(mymap.count(sum) > 0){
            if(maxi < i-mymap[sum]){
                l = mymap[sum]+1;
                j = i;
                maxi = i-mymap[sum];
            }
        }
        mymap[sum] = i;
    }
    for(int i=l; i<=j; i++){
        s.push_back(v[i]);
    }
    return s;
}

int main(){
    
    //basic inbuilt unordered_map

    unordered_map<string, int> mp;

    //differeent functions 
    
    //1 insert()

    pair<string, int> p("abc", 1);

    //we will keep track the map
    mp.insert(p);
    cout<<mp.size()<<endl;  //output  - 1

    mp.insert({"Kira", 12});
    cout<<mp.size()<<endl;  //output  - 2

    //[] can be used to insert
    mp["dub"] = 3;
    cout<<mp.size()<<endl;   //output  - 3
    
    cout<<mp.at("Kira")<<endl;  //output - 12

    //cout<<mp.at("def")<<endl; //trying to print which is not present int the map
                              //** it will through an error
    
    cout<<mp["dub"]<<endl;   //output - 3
    cout<<mp["def"]<<endl;   //output - 0
    //[] behaves different from at() function it actually inserts the 
    //new element with defualt value which is 0

    //to play safe
    if(mp.count("def")>0){
        //the count function checks the presence
        //it doesn't matter what is its value 0 or any thing else
        cout<<mp.at("def")<<endl;
    }

    //erase(key) - this function completely erases the element from the map
    mp.erase("def");  

    //Itrators -------------------------------------------

    /*unordered_map<string, int> mymap;
    mymap["n1"] = 1;
    mymap["n2"] = 2;
    mymap["n3"] = 3;
    mymap["n4"] = 4;
    mymap["n5"] = 5;
    mymap["n6"] = 6;

    unordered_map<string, int>::iterator it = mymap.begin();
    while(it != mymap.end()){
        cout<<" Key: "<<it->first<<" Value: "<<it->second<<endl;
        it++;
    }

    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    v.push_back(6);
    vector<int>::iterator it1 = v.begin();
    while(it1 != v.end()){
        cout<< *it1<<endl;
        it1++;
    }*/

    /* //Que1 
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    cout<<countmax(arr, n);*/

    //Que2
    /*int t, s1, s2;
    cin>>t;
    for(int j=0; j<t; j++){
        cin>>s1;
        int arr1[s1];
        for(int i=0; i<s1; i++){
            cin>>arr1[i];
        }
        cin>>s2;
        int arr2[s2];
        for(int i=0; i<s2; i++){
            cin>>arr2[i];
        }
        vector<int> output = common(arr1, arr2, s1, s2);
        for(int i=0; i< output.size(); i++){
            cout<<output[i]<<" ";
        }
        cout<<"\n";
    }*/

    //Question 3
    /*string s;
    cin>>s;
    string k = removedup(s);
    cout<<k<<endl;*/

    //Question 4
    /*vector<int> v;
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        v.push_back(x);
    }
    vector<int> s = longestsubse(v);
    for(int i=0; i<s.size(); i++){
        cout<<s[i]<<" ";
    }*/

    //Question 5
    /*vector<int> v;
    int n, d;
    cin>>n;

    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        v.push_back(x);
    }
    cin>>d;
    cout<<pairdk(v, d)<<endl;*/

    //Question 6
    // vector<int> v;
    // int n;
    // cin>>n;
    // for(int i=0; i<n; i++){
    //     int x;
    //     cin>>x;
    //     v.push_back(x);
    // }
    // vector<int> s = longestsubarr(v);
    // for(int i=0; i<s.size(); i++){
    //     cout<<s[i]<<" ";
    // }

    return 0;
}