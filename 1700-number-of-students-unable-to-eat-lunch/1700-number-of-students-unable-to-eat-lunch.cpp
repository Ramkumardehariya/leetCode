class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int n = students.size();

        for(int i = 0; i<n*10+1; i++){
            int num = students[0];
            if(students[0] == sandwiches[0]){
                students.erase(students.begin(),students.begin()+1);
                sandwiches.erase(sandwiches.begin(),sandwiches.begin()+1);
            }
            else{
                students.erase(students.begin(),students.begin()+1);
                // cout<<students.size()<<" ";
                students.push_back(num);
            }

            if(students.size() == 0){
                break;
            }
        }
        return students.size();
    }
};