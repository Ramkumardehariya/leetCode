class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        sort(prices.begin(), prices.end());
        int temp = 0;

        if(prices[0]+prices[1] > money){
            return money;
        }
        else{
            return money-(prices[0]+prices[1]);
        } 
    }
};