class Solution {
    public String[] uncommonFromSentences(String s1, String s2) {
        String []word1 = s1.split(" ");
        String []word2 = s2.split(" ");

        Map<String,Integer> wordCount = new HashMap<>();

        for(String word : word1){
            wordCount.put(word,wordCount.getOrDefault(word, 0)+1);
        }

        for(String word : word2){
            wordCount.put(word,wordCount.getOrDefault(word, 0)+1);
        }

        List<String> result = new ArrayList<String>();

        for(String word: wordCount.keySet()){
            if(wordCount.get(word) == 1){
                result.add(word);
            }
        }

        return result.toArray(new String[0]);
    }
}