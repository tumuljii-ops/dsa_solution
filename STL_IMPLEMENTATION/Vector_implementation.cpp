#include <iostream>
using namespace std;

class Vector{
     
     private:
       int* arr;
       int size;
       int cap;

     void resize(){
          cap=cap*2;
          
          int* newarr=new int[cap];

          for(int i=0;i<size;i++){
             newarr[i]=arr[i];
          }

          delete[] arr;
          arr=newarr;

     }

     public: 
       Vector(){
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

       int capacity() {
        return cap;
       }

        int operator[](int idx) {
        return arr[idx];
       }

        void print() {
        for(int i=0;i<size;i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
        }

        ~Vector(){
            delete[] arr;
        }

     
};

int main() {

    Vector v;

    v.push_back(10);
    v.push_back(20);
    v.push_back(30);

    v.print();

    cout << v[1] << endl;

    cout << v.sizee() << endl;

    return 0;
}