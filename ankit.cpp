#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int kthLargest(vector<int>& nums, int k){

	priority_queue<int, vector<int>, greater<int>>pq;

	for(int i=0;i<nums.size();i++)
{
		pq.push(nums[i]);
		if(pq.size()>k)
		{
			pq.pop();
		}

    }
	return pq.top();


}


int main(){
	int n;
	cin>>n;
	vector<int>nums(n);
	for(int i=0;i<n;i++)
	{
		cin>>nums[i];
	}

	int k;
	cin>>k;
	
	cout<<kthLargest(nums,k);

}