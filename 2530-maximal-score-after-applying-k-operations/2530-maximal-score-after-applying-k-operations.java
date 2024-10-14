class Solution {
    public long maxKelements(int[] nums, int k) {
        long ans = 0;
        PriorityQueue<Integer> pq = new PriorityQueue<>(Collections.reverseOrder());

        for(int i = 0; i<nums.length; i++){
            pq.add(nums[i]);
        }

        for(int i = 0; i<k; i++){
            int maxi = pq.poll();
            int num = (int)Math.ceil((double)maxi/3);
            pq.add(num);
            ans += maxi;
        }
        return ans;
    }
}