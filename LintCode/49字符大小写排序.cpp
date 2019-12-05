#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#include<string>

using namespace std;

//49�ַ���Сд����
//�����ύ����� 38.60% ���ύ!
void sortLetters(string &chars) 
{
	// write your code here
	int low = 0, high = chars.size() - 1;
	while (low < high) 
	{
		while (chars[low] <= 'z' && chars[low] >= 'a') 
		{
			low++;
		}
		while (chars[high] <= 'Z' && chars[high] >= 'A') 
		{
			high--;
		}
		if (low < high) 
		{
			char temp = chars[low];
			chars[low] = chars[high];
			chars[high] = temp;
			low++;
			high--;
		}
	}
}

int main()
{
	string s;
	getline(cin, s);
	sortLetters(s);
	cout << s << endl;
	system("pause");
	return 1;
}