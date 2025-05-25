class Solution {
    public int longestPalindrome(String[] words) {
        int[][] freq = new int[26][26];
        List<String> sameCharWords = new ArrayList<>();
        List<String> diffCharWords = new ArrayList<>();
        
        for (String word : words) {
            int first = word.charAt(0) - 'a';
            int second = word.charAt(1) - 'a';

            if (first == second) {
                if (freq[first][second] == 0) {
                    sameCharWords.add(word);
                }
                freq[first][second]++;
                continue;
            }

            if (freq[second][first] != 0) {
                freq[first][second]++;
                continue;
            }

            if (freq[first][second] == 0) {
                diffCharWords.add(word);
            }
            
            freq[first][second]++;
        }

        int pairCount = 0;
        for (String word : diffCharWords) {
            int first = word.charAt(0) - 'a';
            int second = word.charAt(1) - 'a';
            pairCount += Math.min(freq[first][second], freq[second][first]);
        }

        int repeatCount = 0;
        int oddMax = 0;
        for (String word : sameCharWords) {

            int index = word.charAt(0) - 'a';
            if (freq[index][index] % 2 == 1 && freq[index][index] > oddMax) {
                oddMax = freq[index][index];
            }

            int pairs = freq[index][index] / 2;
            repeatCount += (2 * pairs);
        }

        if (oddMax == 0) return 4 * pairCount + 2 * repeatCount;

        return 4 * pairCount + 2 * repeatCount + 2;
    }
}