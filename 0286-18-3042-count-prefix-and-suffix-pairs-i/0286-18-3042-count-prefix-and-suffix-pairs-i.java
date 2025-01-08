class Solution {
    public int countPrefixSuffixPairs(String[] words) {
        int ans =0;

        for(int i = 0; i < words.length; i++){
            for(int j = i+1; j < words.length; j++){
                boolean flag1 = true;
                boolean flag2 = true;
                if(words[i].length() > words[j].length()){
                    continue;
                }
                int n = words[i].length()-1;
                int m = words[j].length()-1;
                int k = 0;
                int s = 0;

                while(k <= n && s <= m){
                    if(words[i].charAt(k) == words[j].charAt(s)){
                        flag1 = true;
                    }
                    else{
                        flag1 = false;
                        break;
                    }
                    k++;
                    s++;
                }
                k = n;
                s = m;

                while(k >=0 && s >= 0){
                    if(words[i].charAt(k) == words[j].charAt(s)){
                        flag2 = true;
                    }
                    else{
                        flag2 = false;
                        break;
                    }
                    k--;
                    s--;
                }
                if(flag1 && flag2){
                    ans++;
                }
                
            }
        }

        return ans;

    }
}