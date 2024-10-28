class Solution {
    public int longestSquareStreak(int[] nums) {
        int ans = -1; 

        Set<Integer> st = new HashSet<>();
        List<Integer> list = new ArrayList<>();

        for(int num : nums){
            st.add(num);
            list.add(num);
        }

        Collections.sort(list);

        for(int i = 0; i<list.size(); i++){
            int curr = list.get(i);
            int count = 0;

            while(st.contains(curr)){
                st.remove(curr);
                curr = curr*curr;
                count++;
            }

            ans = Math.max(ans, count);
        }

        if(ans < 2){
            return -1;
        }

        return ans;
    }
}