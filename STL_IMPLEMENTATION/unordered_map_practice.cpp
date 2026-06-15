#include <vector>
#include <iostream>
#include <list>

using namespace std;

class unorderedMap{
     
      private:
      int bucketsize;
      vector<list<pair<int,int>>>buckets;

      int hash_function(int key){
        return key%bucketsize;
      }

      public:

      unorderedMap(){

          bucketsize=10;
          buckets.resize(10);

      }

      void put(int key,int value){
            
            int ind=hash_function(key);

            for(auto &p:buckets[ind]){
                 if(p.first==ind){
                    p.second=value;
                    return ;
                 }
                  
            }

            buckets[ind].push_back({key,value});

      }

      int get(int key){
         
          int ind=hash_function(key);

          for(auto it:buckets[ind]){
                if(it.first==key){
                    return it.second;
                }
          }

          return -1;
      }

      




};