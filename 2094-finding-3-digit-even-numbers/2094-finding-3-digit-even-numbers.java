class Solution {
    public int[] findEvenNumbers(int[] digits) {
        Set<Integer> temp = new TreeSet<Integer>();


        for(int i = 0; i<digits.length; i++){
            if(digits[i] == 0){
                continue;
            }
            for(int j = 0; j<digits.length; j++){   
                if(i == j){
                    continue;
                }
                for(int k = 0; k<digits.length; k++){
                    if(i == k || j == k){
                        continue;
                    }
                    int num = digits[i]*10+digits[j];
                    int num2 = num*10 + digits[k];
                    if(num2 %2  == 0){
                        temp.add(num2);
                    }
                }
            }
        }
        
        int size = temp.size();
        int[] ans = new int[size];
        int i = 0;
        for(Integer num: temp){
            ans[i] = num;
            i++;
        }
        return ans;
    }
}