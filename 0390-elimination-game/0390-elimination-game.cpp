class Solution {
public:
    int lastRemaining(int n) {

        int remain = n;
        bool flag = true;
        int head = 1;
        int step = 1;

        while(remain > 1){
            if(flag || remain % 2 == 1){
                head += step;
            }

            remain /= 2;
            step *= 2;
            flag = !flag;
        }
        return head;

    }
};