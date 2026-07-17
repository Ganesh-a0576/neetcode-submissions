class Solution {
public:
    int reverse(int x) {
       long s=0;
       while(x!=0){
        s=s*10+x%10;
        x/=10;
       } 
       return s>INT_MAX || s<INT_MIN ?0:s;
    }
};
