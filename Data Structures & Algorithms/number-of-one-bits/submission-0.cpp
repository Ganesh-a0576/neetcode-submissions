class Solution {
public:
    int hammingWeight(uint32_t n) {
        int c=0;
        while(n>1){
            c+=n&1;
            n>>=1;
        }
        if(n==1) c++;
        return c;
    }
};
