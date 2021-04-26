/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        Employee* val;
        for(int i=0;i<employees.size();i++){
            Employee* temp = employees[i];
            if(temp->id ==id){
                val = employees[i];
                break;
            }
        }
        int sum = 0;
        queue<Employee*>q;
        q.push(val);
        while(!q.empty()){
            Employee* u = q.front();
            q.pop();
            sum+=u->importance;
            for(int i=0;i<u->subordinates.size();i++){
                int val = u->subordinates[i];
                for(int j=0;j<employees.size();j++){
                    Employee* temp = employees[j];
                    if(temp->id==val){
                        q.push(temp);
                        break;
                    }
                }
            }
        }
        return sum;
    }
};