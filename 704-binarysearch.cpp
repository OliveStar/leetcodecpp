#include <iostream>
#include <vector>

using namespace std;

// solution
int search(vector<int>& nums, int target){
    int left = 0,right = nums.size() - 1;
    while(left <= right){
        int mid = left + (right - left) / 2;
        if(nums[mid] < target){
            left = mid + 1;
        }else if(nums[mid] > target){
            right = mid - 1;
        }else if(nums[mid] == target){
            return mid;
        }
    }
    return -1;
}

int main() {
    int n;
    int target;
	vector<int> nums;
	cin >> target;
	while(cin >> n){
	    nums.push_back(n);
	    cin.get();//读取单个字符,过滤掉逗号/空格/分号等英文分隔符
	}
	int res=search(nums,target);
	cout  << res << endl;
	return 0;
}