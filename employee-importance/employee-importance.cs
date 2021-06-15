/*
// Definition for Employee.
class Employee {
    public int id;
    public int importance;
    public IList<int> subordinates;
}
*/

class Solution {
    public int GetImportance(IList<Employee> employees, int id) {
        Employee s = null;
        
        for(int i=0;i<employees.Count;i++)
        {
            Employee temp = employees[i];
            if(temp.id==id){
                s = employees[i];
                break;
            }
        }
        
        
        int sum = 0;
        
        Queue<Employee> q = new Queue<Employee>();
        q.Enqueue(s);
        
        while(q.Count!=0)
        {
            Employee u = q.Peek();
            q.Dequeue();
            sum+=u.importance;
            
            for(int i=0;i<u.subordinates.Count;i++)
            {
                int valu = u.subordinates[i];
                for(int j=0;j<employees.Count;j++)
                {
                    Employee obj =employees[j];
                    if(obj.id==valu)
                    {
                        q.Enqueue(obj);
                        break;
                    }
                }
            }
        }
        
        return sum;
    }
}