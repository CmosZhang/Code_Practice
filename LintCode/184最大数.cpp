#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

static bool cmp(string strnum1, string strnum2) 
{
	string str1 = strnum1 + strnum2; 
	string str2 = strnum2 + strnum1;
	return str1 > str2; 
}

string largestNumber(vector<int> &nums) 
{
	// write your code here
	if (nums.size() <= 0)
	{
		return NULL;
	}
	vector<string> strnums(nums.size());
	for (int i = 0; i<nums.size(); i++) 
	{
		strnums[i] = to_string(nums[i]);
	}
	string str="";
	sort(strnums.begin(), strnums.end(), cmp);
	string res = "";
	for (int i = 0; i<nums.size(); i++)
	{ 
		res = res + strnums[i]; 
	}       
	if (res[0] == '0') 
		return "0";        
	return res;
}

int main()
{
	vector<int> num;
	num.push_back(1);
	num.push_back(20);
	num.push_back(23);
	num.push_back(4);
	num.push_back(8);
	string str;
	str = largestNumber(num);
	for (int i = 0; i < str.size(); i++)
	{
		cout << str[i] << " ";
	}
	cout << endl;
	system("pause");
	return 1;
}