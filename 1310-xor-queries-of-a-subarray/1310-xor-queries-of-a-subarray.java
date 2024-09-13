class Solution {
    public int[] xorQueries(int[] arr, int[][] queries) {
        int size = queries.length;

        int ans[] = new int[size];
        int k = 0;


        for(int i = 0; i<size; i++){
            int temp = 0;
            for(int j = queries[i][0]; j<=queries[i][1]; j++){
                temp ^= arr[j];
            }
            ans[k++] = temp;
        }
        return ans;
    }
}