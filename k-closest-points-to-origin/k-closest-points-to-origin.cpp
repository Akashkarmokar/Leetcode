class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,int>> maxPQ;
        for(int i=0;i<(int)points.size();i++){
            pair<int,int> entry = {squareDistance(points[i]),i};
            if(maxPQ.size()<k){
                maxPQ.push(entry);
            }else if(entry.first < maxPQ.top().first){
                maxPQ.pop();
                maxPQ.push(entry);
            }
        }
        vector<vector<int>> ans;
        while(!maxPQ.empty()){
            int idx = maxPQ.top().second;
            maxPQ.pop();
            ans.push_back(points[idx]);
        }
        return ans;
    }
    
    
private:
    int squareDistance(vector<int>& point){
        return point[0]*point[0] + point[1]*point[1];
    }
};