#include<bits/stdc++.h>
#include<string>
using namespace std;
/*
    L1 read/write - 1ns
    L2 read/write - 20ns
    DRAM read/write - 200ns
*/

int BlockSize,L1Size,L1Assoc,L2Size,L2Assoc; // everything in bytes and powers of 2

int L1[L1Size/(BlockSize*L1Assoc)][L1Assoc][BlockSize],
    L2[L2Size/(BlockSize*L2Assoc)][L2Assoc][BlockSize],
    DRAM[1024*1024*1024];
int L1_read,L1_read_miss,L1_write,L1_write_miss;
int L2_read,L2_read_miss,L2_write,L2_write_miss;


void cache(){
    int time;
    int address;
    string req;
    while(cin>>req>>address){
        time+=1;
        if (req=="rd") L1_read+=1;
        if (req=="wr") L1_write+=1;
        
        if address in L1{
            
            /*
                reorder the L1 cache according to LRU principle
            */
        }else{
            time+=20;
            if (req=="rd"){
                L2_read+=1;
                L1_read_miss+=1
            }
            if (req=="wr") {
                L2_write+=1;
                L1_write_miss+=1;
            }
            if address in L2{
               /*
                    reorder L2 cache according to LRU principle
                    bring the address and its neighbours to the L1 cache ,
                    if full delete addresses according to LRU principle

               */
            }else{
                time+=200;
                if (req=="rd") L2_read_miss+=1;
                if (req=="wr") L2_write_miss+=1;
                /*
                    bring the address and its neighbours to the L2 cache ,
                    if full delete addresses according to LRU principle
                    and then to L1 cache according to LRU principle.
                */
            }
        }

    }
    cout<<"L1 cache read: "<<L1_read<<endl;
    cout<<"L1 cache write: "<<L1_write<<endl;
    
    cout<<"L1 cache read miss: "<<L1_read_miss<<endl;
    cout<<"L1 cache write miss: "<<L1_write_miss<<endl;
    
    cout<<"L1 cache read miss rate: "<<L1_read_miss/L1_read<<endl;
    cout<<"L1 cache write miss rate: "<<L1_write_miss/L1_write<<endl;
    
    cout<<"L2 cache read: "<<L2_read<<endl;
    cout<<"L2 cache write: "<<L2_write<<endl;
    
    cout<<"L2 cache read miss: "<<L2_read_miss<<endl;
    cout<<"L2 cache write miss: "<<L2_write_miss<<endl;
   
    cout<<"L2 cache read miss rate: "<<L2_read_miss/L2_read<<endl;
    cout<<"L2 cache write miss rate: "<<L2_write_miss/L2_write<<endl;
    
    cout<<"Average access time: "<<time<<endl;

    
}
