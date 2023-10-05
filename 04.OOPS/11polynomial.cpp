#include<bits/stdc++.h>
using namespace std;

class Polynomial{
    int *degree_coff;
    int capacity;
    public:
    Polynomial(){
        degree_coff = new int[1]{0};   //imp - you can initialize dynamic array with some value
        capacity = 1;
    }

    void add(int ind, int coff){
        if(ind>=capacity){
            int count = 0;

            // multiple of 2 
            // count = 2*((ind/2)+1);
            // ncapacity = count;

            //power of 2
            int temp = ind;
            while(temp>0){
                temp /= 2;
                count++;
            }
            int ncapacity = pow(2, count);
            int *n_degree_coff = new int[ncapacity]{0};
            for(int i=0; i<capacity; i++){
                n_degree_coff[i] = degree_coff[i];
            }
            
            n_degree_coff[ind] = coff;
            delete [] degree_coff;
            degree_coff = n_degree_coff;
            capacity = ncapacity;
        }
        else{
            degree_coff[ind] = coff;
        }
        
    }

    void printfun(){
        for(int i = 0; i<capacity; i++){
            if(degree_coff[i] != 0)
            {
                if(degree_coff[i]>=0 && i!= 0){
                cout<<"+";
                }
                cout<<degree_coff[i]<<"x"<<i;
            }
        }
        cout<<endl;
    }

    int get_coff(int i){
        return degree_coff[i];
    }

    void add2c(int i, int n){
        if(i<capacity){
            degree_coff[i] += n;
        }else{
            add(i, n);
        } 
    }

    Polynomial operator+(Polynomial const &p2){
        Polynomial p3;
        int i=0;
        for(; i<this->capacity && i<p2.capacity; i++){
            p3.add(i, (this-> degree_coff[i] + p2.degree_coff[i]));  
        }
        while(i<this->capacity){
            p3.add(i, this-> degree_coff[i]);
        }
        while(i<p2.capacity){
            p3.add(i, p2.degree_coff[i]);
        }
        return p3;
    }
    


    Polynomial operator-(Polynomial const &p2){
        Polynomial p3;
        int i=0;
        for(; i<this->capacity && i<p2.capacity; i++){
            p3.add(i, (this-> degree_coff[i] - p2.degree_coff[i]));  
        }
        while(i<this->capacity){
            p3.add(i, this-> degree_coff[i]);
        }
        while(i<p2.capacity){
            p3.add(i, -(p2.degree_coff[i]));
        }
        return p3;
    }

    Polynomial operator*(Polynomial const &p2){
        Polynomial p4;
        for(int i=0; i<this->capacity; i++){
            for(int j=0; j<p2.capacity; j++){
            int index= (i+j);
            int feeder = ((this->degree_coff[i])*(p2.degree_coff[j]));
            if(feeder != 0){
                p4.add2c(index,feeder);
            }
            }
        }
        return p4;
    }

    void operator*=(Polynomial const &p2){
        Polynomial p4;
        for(int i=0; i<this->capacity; i++){
            for(int j=0; j<p2.capacity; j++){
            int index= (i+j);
            int feeder = ((this->degree_coff[i])*(p2.degree_coff[j]));
            if(feeder != 0){
                p4.add2c(index,feeder);
            }
            }
        }
        delete [] this;
        *this = p4;
    }

    int getcapacity(){
        return capacity;
    }

    void operator+=(Polynomial const &p2){
        int i=0;
        for(; i<this->capacity && i<p2.capacity; i++){
            add(i, (this-> degree_coff[i] + p2.degree_coff[i]));  
        }
        while(i<this->capacity){
            add(i, this-> degree_coff[i]);
        }
        while(i<p2.capacity){
            add(i, p2.degree_coff[i]);
        }
    }
};

// += remaining
// -= remaining