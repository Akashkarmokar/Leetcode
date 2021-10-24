class Solution {
private:
    void flip(vector<int>& row){
        int n = row.size();
        int i = 0;
        int j = n-1;
        while(i<=j){
            swap(row[i],row[j]);
            i++;
            j--;
        }
    }
    void invert(vector<int>& row){
        int n = row.size();
        for(int i=0;i<n;i++){
            row[i]^=1;
        }
    }
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        int row = image.size();
        int col = image[0].size();
        for(int i=0;i<row;i++){
            flip(image[i]);
            invert(image[i]);
        }
        
        return image;
    }
};