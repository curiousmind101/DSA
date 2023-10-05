#include<bits/stdc++.h>

using namespace std;

template<typename V>
class mapnode{
    public:
    string key;
    V value;
    mapnode *next;
    mapnode(string key, V value){
        this->key = key;
        this->value = value;
        next = NULL;
    }
    ~mapnode(){
        delete next;
    }
};
template<typename V>
class mymap{
    mapnode<V>** buckets;
    int size;
    int numBuckets;
    int count;
    
    public:
    mymap(){
        count = 0;
        size = 0;
        numBuckets = 5;
        buckets = new mapnode<V>*[numBuckets];
        for(int i=0; i<numBuckets; i++){
            buckets[i] = NULL;
        }
    }
    ~mymap(){
        for(int i=0; i<numBuckets; i++){
            delete buckets[i];
        }

        delete [] buckets;
    }  
    
    int getSize(){
        return count;
    }

    V getvalue(string key){
        int bucketIndex = getBucketindex(key);
        mapnode<V>* head = buckets[bucketIndex];
        while(head != NULL){
            if(head->key == key){
                return head->value;
            }
            head = head->next;
        }
        return 0;
    }

    private:
    int getBucketindex(string key){
        int hashcode;
        int currentCoeff = 1;
        for(int i=key.length()-1; i>= 0; i--){
            hashcode += key[i] * currentCoeff;
            hashcode = hashcode % numBuckets;
            currentCoeff *= 37;
            currentCoeff = currentCoeff % numBuckets;
        }
        return hashcode % numBuckets;
    }

    public:
    void insert(string key, V value){
        int bucketindex = getBucketindex(key);
        mapnode<V>* head = buckets[bucketindex];
        while(head != NULL){
            if(head->key == key){
                head->value = value;
                return;
            }
            head = head->next;
        }
        head = buckets[bucketindex];
        mapnode<V>* newnode = new mapnode<V>(key, value);
        newnode->next = head;
        head = newnode;
        buckets[bucketindex] = newnode;
        count++;
    }

    V remove(string key){
        int index = getBucketindex(key);
        mapnode<V>* head = buckets[index];
        mapnode<V>* prev = NULL;
        while(head != NULL){
            if(head->key == key){
                if(prev == NULL){
                    buckets[index] = head->next;
                }else{
                    prev->next = head->next;
                }
                V removed = head->value;
                head->next = NULL;
                count--;
                delete head;
                return removed;
            }
            prev = head;
            head = head->next;
        }
        return 0;
    }

    double getloadfactor(){
        return (1.0*count)/numBuckets;
    }
};