#include <bits/stdc++.h>
using namespace std;

class Stack{

      private:
      int *arr;
      int capacity;
      int topindex;


      public:

      Stack(int size){
          capacity=size;
          arr=new int[capacity];
          topindex=-1;
      }

      ~Stack(){
        delete[] arr;
      }


      int push(int num){
         
           if(topindex==capacity-1){
                cout<<"stack overflow"<<'\n';
                return -1;
           }

           topindex++;
           arr[topindex]=num;
      }

      void pop(){
          
         if(topindex=-1){
            cout<<"stack is empty"<<"\n";
            return ;
         }

         topindex--;
      }

      int top(){
         
           if(topindex==-1){
            cout<<"stack is empty\n";
             return -1;
           }

           return arr[topindex];
      }

      int size(){
        return topindex+1;
      }

      bool empty(){
          return topindex==-1;
      }

      void display(){
          
           if(empty()){
               cout<<"stack is empty\n";
               return ;
           }

           cout<<"stack is:\n";

           for(int i=topindex;i>=0;i--){
                 cout<<arr[i]<<" ";

           }

           cout<<endl;
      }

};

int main(){
      
    Stack st(5);

    st.push(10);
    st.push(20);
    st.push(30);
    st.push(49);


    st.display();

    cout<<"Top element is:"<< st.top()<<endl;

    st.pop();

    st.display();

    cout<<"Stack size is:"<<st.size()<<endl;

    return 0;


}