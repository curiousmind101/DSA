#include <string>
using namespace std;

template <typename V>  //for value - jo chaho store karo
class mapNode{
    public:
    string key;  //filhal k liye hum string ka hi banate hain
    V value;
    mapNode* next;   
    mapNode(string key, V value){  //constructor
        this->key = key;
        this->value = value;
        next = NULL;
    }

    ~mapNode(){    //destructor
        delete next;
    }
};

template <typename V>

class newmap{
    int numbuckets;
    int count; //counting size
    mapNode<V>** buckets;

    //
    public:
    newmap(){  //constructor 
        count = 0;
        numbuckets = 5;
        buckets = new mapNode<V>*[numbuckets];
        for(int i=0; i<numbuckets; i++){
            buckets[i] = NULL;
        }
    }

    ~newmap(){  //destructor
        for(int i=0; i<numbuckets; i++){
            buckets[i];
        }

        delete [] buckets;
    }

    //functions
    int getSize(){
        return count;
    }

    double getloadfactor(){
        return (1.0*count)/numbuckets;
    }
    private:  
    int getbucketIndex(string key){  //hashfunctions
        int hashCode = 0;
        //that base value
        int multiplier = 1; //pow(31, 0)
        for(int i = key.length()-1; i>=0; i--){
            hashCode = ((key[i])*multiplier)%numbuckets; 
            //using directly ASCII values
            multiplier = (multiplier*37)%numbuckets;
        }
        return hashCode%numbuckets;
    }

    //rehash
    void rehash(){
        mapNode<V>** temp = buckets;
        buckets = new mapNode<V>*[2*numbuckets];
        for(int i=0; i<2*numbuckets; i++){
            buckets[i] = NULL;
        }
        int oldnumbuckets = numbuckets;
        numbuckets *= 2;
        count = 0;

        for(int i=0; i<oldnumbuckets; i++){
            mapNode<V>* head = temp[i];
            while(head!=NULL){
                string key = head->key;
                V value = head->value;
                insert(key, value);
                head = head->next;
            }
        }

        for(int i=0; i<oldnumbuckets; i++){
            mapNode<V>* head =  temp[i];
            delete head;
        }
        delete [] temp;
    }
    public:
    void insert(string key, V value){
        int bucketIndex = getbucketIndex(key);
        mapNode<V>* head = buckets[bucketIndex];

        while(head != NULL){
            if(head->key == key){
                head->value = value; 
                return;
                //if key already exists change the value and return
            }
            head = head->next;
        }

        head = buckets[bucketIndex];
        mapNode<V>* newnode = new mapNode<V>(key, value);
        newnode->next = head;
        buckets[bucketIndex] = newnode;
        count++;
        
        double loadfactor = (1.0 * count)/numbuckets;
        if(loadfactor>0.7){
            rehash();
        }
    }

    V getValue(string key){  //search
        int bucketIndex = getbucketIndex(key);
        mapNode<V>* head = buckets[bucketIndex];
        
        while(head != NULL){
            if(head->key == key){
                return head->value;
            }
            head = head->next;
        }
        return 0;
    }

    V remove(string key){
        int bucketIndex = getbucketIndex(key);
        mapNode<V>* head = buckets[bucketIndex];
        mapNode<V>* prev = NULL;
        while(head != NULL){
            if(head->key == key){
                if(prev == NULL){ //head ko hi delete karna hai
                    buckets[bucketIndex] = head->next;
                }else{
                    prev->next = head->next;
                }
                V val = head->value;
                head->next = NULL;
                delete head;
                count--;
                return val;
            }
            prev = head;
            head = head->next;
        }
        return 0;
    }
};