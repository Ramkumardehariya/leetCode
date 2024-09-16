class Solution {
    public int findMinDifference(List<String> timePoints) {
        ArrayList<Integer> minutes = new ArrayList<>();

        for(int i = 0; i<timePoints.size(); i++){
            int hour = Integer.parseInt(timePoints.get(i).substring(0,2));
            int minute = Integer.parseInt(timePoints.get(i).substring(3));
            int total = hour*60 + minute;
            minutes.add(total);
        }

        Collections.sort(minutes);
        int mini = Integer.MAX_VALUE;

        for(int i = 0; i<minutes.size()-1; i++){
            if(mini > (minutes.get(i+1) - minutes.get(i))){
                mini = (minutes.get(i+1) - minutes.get(i));
            }
        }

        if(mini > (minutes.get(0)+1440 - minutes.get(minutes.size()-1))){
            mini = (minutes.get(0)+1440 - minutes.get(minutes.size()-1));
        }
        
        return mini;
    }
}