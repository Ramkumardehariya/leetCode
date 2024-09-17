class Solution {
    public int[] getSneakyNumbers(int[] nums) {
        TreeMap<Integer,Integer> mp = new TreeMap<>();

        for(int i: nums){
            mp.put(i,mp.getOrDefault(i, 0)+1);
        }
        List<Integer> arr = new ArrayList<>();

        mp.forEach((key, value) -> {
            if(value > 1){
                arr.add(key);
            }
        });

        int ans[] = new int[arr.size()];

        for(int i = 0; i<arr.size(); i++){
            ans[i] = arr.get(i);
        }

        return ans;
    }
}