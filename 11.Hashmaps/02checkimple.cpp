#include <iostream>
#include "newmap.cpp"

int main(){
    newmap<int> map;

    for(int i=0; i<10; i++){
        char c = '0' + i;
        string key = "abc";
        key = key + c;
        int value = i+1;
        map.insert(key, value);
        cout<<map.getloadfactor()<<endl;
    }
    cout<<map.getSize()<<endl;
    return 0;
}

