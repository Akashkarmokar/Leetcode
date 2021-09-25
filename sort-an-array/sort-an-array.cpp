class Solution {
private:
    void merge(vector<int>&a ,int start,int mid,int end){
	vector<int> tmp(end-start+1);
	int k = 0;
	int i=start,j=mid+1;
	while(i<=mid or j<=end){
		if(j==end+1 || (i<=mid && a[i]<a[j])){
			tmp[k++] = a[i++];
		}else{
			tmp[k++] = a[j++];
		}
	}
	for(int p=0;p<k;p++){
		a[start++] = tmp[p];
	}
}

void mergeSort(vector<int>& a,int start,int end){
	if(start==end){
		return ;
	}
	int mid = (start+end)/2;
	mergeSort(a,start,mid);
	mergeSort(a,mid+1,end);

	// merge the both part
	merge(a,start,mid,end);
}
public:
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums,0,nums.size()-1);
        return nums;
    }
};