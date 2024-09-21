class Solution {
    public List<Integer> lexicalOrder(int n) {
        List<Integer> ans = new ArrayList<Integer>();
        String []arr = new String[n];

        int j = 0;

        for(int i = 1; i<=n; i++){
            arr[j] = Integer.toString(i);
            j++;
        }


        Arrays.sort(arr);

        for(int i = 0; i<arr.length; i++){
            ans.add(Integer.parseInt(arr[i]));
        }

        return ans;
    }
}