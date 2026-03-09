class Solution {
public:
    int numberOfSteps(int num) {
           int a=step(num,0);

           return a;
    }

    int step(int number,int count){
        if(number==0){
            return count;
        }
        
        if(number%2==0){
            return step(number/2,count+1);
        }
        else{
            return step(number-1,count+1);
        }
    }
};