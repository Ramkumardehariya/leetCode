class Solution {
    public int[] vowelStrings(String[] words, int[][] queries) {
        int n = queries.length;
        int m = words.length;
        int prefixSum[] = new int[m+1];
        int ans[] = new int[n];
        int index = 0;
        int ansIndex = 0;

        for(int i = 0; i<m; i++){
            int size = words[i].length();
            if((words[i].charAt(0) == 'a' || words[i].charAt(0) == 'e' || words[i].charAt(0) == 'i' || words[i].charAt(0) == 'o' || words[i].charAt(0) == 'u') && (words[i].charAt(size-1) == 'a' || words[i].charAt(size-1) == 'e' || words[i].charAt(size-1) == 'i' || words[i].charAt(size-1) == 'o' || words[i].charAt(size-1) == 'u')){
                prefixSum[index+1] = prefixSum[index]+1;
            }
            else{
                prefixSum[index+1] = prefixSum[index];
            }
            index++;
        }

        for(int i = 0; i<n; i++){
            ans[ansIndex] = prefixSum[queries[i][1]+1]-prefixSum[queries[i][0]];
            ansIndex++;
        }

        return ans;
    }
}