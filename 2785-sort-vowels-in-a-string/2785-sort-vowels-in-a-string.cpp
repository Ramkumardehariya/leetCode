class Solution {
public:
    string sortVowels(string s) {
        priority_queue<pair<int,char>, vector<pair<int,char>> , greater<pair<int,char>>> pq;
        
        for(int i = 0; i<s.size(); i++){
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U'){
                int ch = s[i]-'a';
                pq.push({ch, s[i]});
            }
        }
        
        for(int i = 0; i<s.size(); i++){
            if((s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U') && !pq.empty()){
                
                auto it = pq.top();
                pq.pop();
                char ch = it.second;
                
                swap(s[i],ch);
            }
        }
        return s;
        
    }
};