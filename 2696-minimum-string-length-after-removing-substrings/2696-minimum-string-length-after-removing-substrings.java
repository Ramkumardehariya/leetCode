class Solution {
    public int minLength(String s) {

        StringBuilder sb = new StringBuilder(s);

        String ab = "AB";
        String cd = "CD";

        while(sb.indexOf(ab) != -1 || sb.indexOf(cd) != -1){
            if(sb.indexOf(ab) != -1){
                sb.delete(sb.indexOf(ab), sb.indexOf(ab)+2);
            }
            else{
                sb.delete(sb.indexOf(cd), sb.indexOf(cd)+2);
            }
        }
        return sb.length();
    }
}