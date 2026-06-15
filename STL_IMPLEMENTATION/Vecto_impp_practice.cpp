#include <iostream>
using namespace std;

class vector{

     private:
     int size;
     int cap;
     int* arr;

     void resize(){
         
          cap=cap*2;

          int* newarr=new int[cap];

          for(int i=0;i<size;i++){

            newarr[i]=arr[i];
          }

          delete arr;
          arr=newarr;
     }

     public:

     vector(){
        size=0;
        cap=1;
        arr=new int[cap];
     }

     void push_back(int val){
          
           if(size==cap){
              resize();
           }

           arr[size++]=val;
     }

     void pop_back(){
         
           if(size>0){
            size--;
           }
     }

     int sizee(){
          return size;
     }

     

};