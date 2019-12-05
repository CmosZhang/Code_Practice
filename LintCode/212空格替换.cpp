#include<iostream>
#include<string>

using namespace std;

int replaceBlank(char string[], int length)
{
	// write your code here
	if (length <= 0)
		return 0;
	int space = 0;
	int origlen = 0;
	for (int i = 0; i<length; i++)
	{
		if (string[i] == ' ')
		{
			space++;
		}
		origlen++;
	}
	int len = space * 2 + origlen;
	int newlength = len;
	while (origlen < len)
	{
		if (string[origlen] != ' ')//ÒÀ´Î¸´ÖÆ×Ö·û´®ÄÚÈÝ		
		{
			string[len] = string[origlen];
			len--;
			origlen--;
		}
		else//¿Õ¸ñÌæ»»		
		{
			origlen--;
			string[len] = '0';
			len--;
			string[len] = '2';
			len--;
			string[len] = '%';
			len--;
		}
	}
	return newlength;
}

int main()
{
	char str[30] = "We Are Happy.";
	int k = 0;
	k = replaceBlank(str, 13);
	cout << str << endl;
	cout << k << endl;
	system("pause");
	return 0;
}