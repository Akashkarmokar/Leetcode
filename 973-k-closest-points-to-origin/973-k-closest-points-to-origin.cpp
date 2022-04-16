/**
            Time Complexity: O(nlogk + k)
*/

class Solution {
private:
    int distance(vector<int>& points){
        return points[0]*points[0] + points[1] * points[1];
    }
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        auto comp = [](pair<int,int>& a, pair<int,int>& b){
            if(a.first != b.first){
                return a.first < b.first ;
            }
            return a.first < b.first;
        };
        priority_queue<pair<int,int> , vector<pair<int,int>>, decltype(comp)> maxHeap(comp);
        /**
            Time Complexity: O(nlogk)
        */
        for(int i=0;i< points.size();i++){
            pair<int,int> tempMaxHeapValue = {distance(points[i]),i};
            if(maxHeap.size() < k){
                maxHeap.push(tempMaxHeapValue);
            }else if(maxHeap.top().first > tempMaxHeapValue.first){
                maxHeap.pop();
                maxHeap.push(tempMaxHeapValue);
            }
        }
        
        vector<vector<int>> ans;
        while(!maxHeap.empty()){
            ans.push_back(points[maxHeap.top().second]);
            maxHeap.pop();
        }
        
        return ans;
        
    }
};