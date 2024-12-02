class Solution {
    public int isPrefixOfWord(String sentence, String searchWord) {

        int arr[] = new int[26];
        int count = 1;
        int temp[] = new int[26];

        for(int i = 0; i<searchWord.length(); i++){
            arr[searchWord.charAt(i)-'a']++;
        }

        for(int i = 0; i<sentence.length(); i++){
            if(Arrays.equals(arr,temp)){
                return count;
            }
            else if(sentence.charAt(i) == ' '){
                count++;
                Arrays.fill(temp, 0);
            }
            else{
                temp[sentence.charAt(i)-'a']++;
            }
        }

        if(Arrays.equals(arr,temp)){
            return count;
        }

        return -1;
    }
}