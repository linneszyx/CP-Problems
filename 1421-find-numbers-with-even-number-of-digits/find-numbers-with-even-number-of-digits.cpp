class Solution {
public:
bool f(int n){
	int temp = n;
	int d;
	int c=0;
	while(n!=0){
		d=n%10;
		c++;
		n/=10;
	}
	if(c%2==0){
		return true;
	}
	else {
		return false;
	}
}
    int findNumbers(vector<int>& nums) {
         int  c=0;
	for(int i=0;i<nums.size();i++){
		if(f(nums[i])) c++;
		else continue;
	}
	return c;
    }
};