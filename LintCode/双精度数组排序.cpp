//double���͵���������
//Ҫ���Ӷ�ΪO(n)

#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

//ʹ�û�������ķ�ʽ
void radixSort(double input[], long long length)
{
	double *tmp_12 = (double *)malloc((length + 10) * sizeof(double));//�����ռ�
	long long negCnt = 0; //��¼�����ĸ���
	int bucket[65536];

	//��64λ���ֳ�4���ֽڣ�1������1���ֽ�
	for (int i = 0; i < 4; i++)
	{
		//����������
		for (int j = 0; j < 65536; j++)
			bucket[j] = 0;
		//ͳ�Ƽ���
		int digit = i * 16;
		for (long long j = 0; j < length; j++)
			bucket[reinterpret_cast<unsigned long long&>(input[j]) >> digit & 0xffff]++;
		//������ε���ʼλ��
		for (int j = 1; j < 65536; j++)
			bucket[j] = bucket[j - 1] + bucket[j];
		//���Ƶ���ʱ���飬����¼�����ĸ���
		for (long long j = length - 1; j >= 0; j--)
		{
			int temp = --bucket[reinterpret_cast<unsigned long long&>(input[j]) >> digit & 0xffff];
			tmp_12[temp] = input[j];
			if ((i == 0) && input[j] < 0)
			{
				negCnt++;
			}
		}
		//����ʱ�����е������Ƶ�ԭ����
		//�����һ������ʱ�õ���˳��������С���󣬸����Ӵ�С
		//�������ǽ���������λ�÷�ת����С�������е���ȷλ��
		for (long long j = 0; j < length; j++)
		{
			if (i == 3)
			{
				if (tmp_12[j] < 0.0)
					input[length - 1 - j] = tmp_12[j];
				else
					input[negCnt + j] = tmp_12[j];
			}
			else
				input[j] = tmp_12[j];
		}
	}
	free(tmp_12);
}

int main()
{
	double input[] = { 3.23,6.854,12.8,79.5,1.0,0.23,-0.9 };
	radixSort(input, 7);
	for (int i = 0; i < 7; i++)
	{
		cout << input[i] << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}