class Solution {
public:
    vector<double> internalAngles(vector<int>& sides) {

          double a=sides[0],b=sides[1],c=sides[2];

          if(a+b<=c || a+c<=b || b+c<=a) return {};

          double A=acos((b*b+c*c-a*a)/(2*b*c));
          double B=acos((a*a+c*c-b*b)/(2*a*c));
          double C=acos((a*a+b*b-c*c)/(2*a*b));

          A=A*180.0/M_PI;
          B=B*180.0/M_PI;
          C=C*180.0/M_PI;

          vector<double>ans={A,B,C};

          sort(ans.begin(),ans.end());

          return ans;
    }
};