class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        //TLE 
        // if(left == right){
        //     return left;
        // }
        // for(int i = left; i<right; i++){
        //     left = left & i;
        // }
        // return left&right;

        int count = 0;
        while(left != right){
            left = left>>1;
            right = right>>1;
            count++;
        }

        cout<<left<<" "<<right<<" "<<count;
        left = left<<count;

        return left;
    }
};