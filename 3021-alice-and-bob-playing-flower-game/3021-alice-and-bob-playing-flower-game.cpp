class Solution {
public:
    long long flowerGame(int n, int m) {
        long long count = 0;

        //n is odd and m = is even
        int odd = (n+1)/2;
        int even = m/2;
        count += (1LL * odd*even);

        //m is odd and n is even
         odd = (m+1)/2;
         even = n/2;
        count += (1LL * odd*even);

        return count;
    }
};