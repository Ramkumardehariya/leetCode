class Pair<K, V> {
    private K key;
    private V value;

    public Pair(K key, V value) {
        this.key = key;
        this.value = value;
    }

    public K getKey() {
        return key;
    }

    public void setKey(K key) {
        this.key = key;
    }

    public V getValue() {
        return value;
    }

    public void setValue(V value) {
        this.value = value;
    }

    @Override
    public String toString() {
        return "(" + key + ", " + value + ")";
    }
}

class Solution {
    public int countPalindromicSubsequence(String s) {
        int ans = 0;
        Map<Character,Pair<Integer,Integer>> map = new HashMap<>();

        for(char c = 'a'; c<='z'; c++){
            map.put(c, new Pair<>(-1,-1));
        }

        for(int i = 0; i<s.length(); i++){
            Pair<Integer,Integer> pair = map.get(s.charAt(i));

            if(pair.getKey() == -1){
                pair.setKey(i);
                map.put(s.charAt(i), pair);
            }
        }

        for(int i = s.length()-1; i>=0; i--){
            Pair<Integer,Integer> pair = map.get(s.charAt(i));

            if(pair.getValue() == -1){
                pair.setValue(i);
                map.put(s.charAt(i), pair);
            }

        }

        for(Map.Entry<Character,Pair<Integer,Integer>> entry: map.entrySet()){
            Pair<Integer,Integer> value = entry.getValue();

            Set<Character> st = new HashSet<>();

            for(int i = value.getKey()+1; i<value.getValue(); i++){
                st.add(s.charAt(i));
            }
            ans += st.size();
        }
        return ans;
    }
}