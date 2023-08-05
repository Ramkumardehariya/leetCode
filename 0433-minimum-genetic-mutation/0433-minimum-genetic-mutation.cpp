class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
         queue<string> pq;
         unordered_set<string> vis;
         vis.insert(startGene);
         pq.push(startGene);
         int count = 0;

         while(!pq.empty()){
             int n = pq.size();

             for(int i = 0; i<n; i++){
                 string node = pq.front();
                 pq.pop();

                 if(node == endGene){
                     return count;
                 }

                 for(auto ch : "ACGT"){
                     for(int j = 0; j<node.size(); j++){
                         string adjNode =node;
                         adjNode[j] = ch;

                         if(!vis.count(adjNode) && find(bank.begin(),bank.end(), adjNode) != bank.end()){
                             pq.push(adjNode);
                             vis.insert(adjNode);
                         }
                     }
                 }
             }
             count++;
         }
         return -1;
    }
};