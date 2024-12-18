class Solution {
    public int[] finalPrices(int[] prices) {
        int n = prices.length;

        int ans[] = new int[n];

        for(int i = 0; i<n; i++){
            int num = prices[i];
            boolean flag = false;
            for(int j = i+1; j<n; j++){
                if(prices[j] <= prices[i]){
                    num = prices[j];
                    flag = true;
                    break;
                }
            }
            if(flag){
                num = prices[i]-num;
            }

            ans[i] = num;
        }

        return ans;
    }
}