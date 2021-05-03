bool cmp(const vector<int> &a, const vector<int> &b){
    return a[1]<b[1];
}
class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(),courses.end(),cmp);
        priority_queue<int> pq;
        int total = 0;
        for(int i=0;i<courses.size();i++){
            int dur = courses[i][0];
            int end = courses[i][1];
            if(dur+total<=end){
                total+=dur;
                pq.push(dur);
            }else if(pq.size() && pq.top()>dur){
                total+=dur-pq.top();
                pq.pop();
                pq.push(dur);
            }
        }
        return pq.size();
    }
};