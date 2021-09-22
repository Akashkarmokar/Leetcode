class NumArray {
private:
    vector<int> tree;
    int n;
    
    void build(vector<int>& nums,int node,int b,int e){
        if(b==e){
            tree[node] = nums[b];
            return;
        }
        int mid = (b+e)/2;
        int left = node*2+1;
        int right = left+1;
        build(nums,left,b,mid);
        build(nums,right,mid+1,e);
        tree[node] = tree[left] + tree[right];
    }
    
    void updatePos(int node,int b,int e,int index,int val){
        if(e<index || index<b )
            return;
        if(b>=index && e<=index){
            tree[node] = val;
            return;
        }
        int left = node*2+1;
        int right = left+1;
        int mid = (b+e)/2;
        updatePos(left,b,mid,index,val);
        updatePos(right,mid+1,e,index,val);
        tree[node] = tree[left] + tree[right];
    }
    
    int query(int node,int b,int e,int i,int j){
        if(j<b || e<i){
            return 0;
        }
        if(b>=i && e<=j){
            return tree[node];
        }
        int left = node*2+1;
        int right = left+1;
        int mid = (b+e)/2;
        int p1 = query(left,b,mid,i,j);
        int p2 = query(right,mid+1,e,i,j);
        return p1+p2;
    }
public:
    NumArray(vector<int>& nums) {
        if(nums.size()>0){
            n = nums.size();
            tree.resize(4*n,0);
            build(nums,0,0,n-1);
        }    
    }
    
    void update(int index, int val) {
        if(n==0){
            return;
        }
        updatePos(0,0,n-1,index,val);
    }
    
    int sumRange(int left, int right) {
        if(n==0){
            return 0;
        }
        return query(0,0,n-1,left,right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */