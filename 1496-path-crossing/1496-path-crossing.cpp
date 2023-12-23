class Solution {
public:
    bool isPathCrossing(string path) {
        set<pair<int,int>> temp;

        temp.insert({0,0});
        int prevX = 0;
        int prevY = 0;

        for(int i = 0; i<path.size(); i++){
            int size = temp.size();

            if(path[i] == 'W'){
                prevX -= 1;
                temp.insert({prevX,prevY});
            }
            else if(path[i] == 'N'){
                prevY += 1;
                temp.insert({prevX,prevY});
            }
            else if(path[i] == 'E'){
                prevX += 1;
                temp.insert({prevX, prevY});
            }
            else{
                prevY -= 1;
                temp.insert({prevX, prevY});
            }

            if(size == temp.size()){
                return true;
            }
        }

        return false;
    }
};