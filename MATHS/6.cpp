class Solution {
public:
    string convert(string s, int numRows) {

             if(numRows==1 || numRows>=s.size()){
                 return s;
             }

             bool down=true;
             int row=0;

             vector<string>store(numRows);

             for(char ch:s){

                  store[row]+=ch;
                 
                   if(row==numRows-1){
                       down=false;
                   }
                   else if(row==0){
                       down=true;
                   }

                   if(down){
                      row++;
                   }
                   else{
                    row--;
                   }
             }

             string answer="";

             for(string x:store){
                  
                  answer+=x;
             }

             return answer;


    }
};