class Solution {
public:
    bool isValidSerialization(string preorder) {

        int vac = 1;
        int i;
        int n = preorder.size();
        if(n == 0){
            return true;
        }
        if(n != 1 && preorder[i] == '#'){
            return false;
        }


        for(i= 0; i<n; i++){
            vac--;
            if(vac < 0){
                return false;
            }
            if(preorder[i] != '#'){
                vac = vac +2;
            }
            i++;
            while(i<n && preorder[i] != ','){
                i++;
            }
        }

        return vac == 0;
    }
};