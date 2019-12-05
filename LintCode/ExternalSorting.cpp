#include <assert.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <vector>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fstream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

#define MAX_WAYS 100 //���鲢·��
#define MAX_NUM  100 * 1024 * 1024	//�ڴ����ʹ����
#define BUF_SIZE  110000000   //ÿ�δ��ı���ȡ�����ַ���
#define EACH_DOUBLE_NUM	BUF_SIZE/10	 //ÿ�δ��ı���ȡ���ĸ����� ������ÿ����������СԼ10λ


long long temp_file_num[1000];   //��¼ÿ��ת���ĸ�����
long long buf_size_temp[100] = {0};   //��¼ÿ��ʵ��ȡ�����ַ���
long long sum_size = 0;		//��¼�������ܵ��ļ���С
long long sum = 0;		//��¼�����������ĸ���
int numRuns = 0;		//��¼���ɵ���ʱ�ļ����������ܹ鲢·��
bool readIsOver = false;	//��������ʼ��Ƿ����
int illegal_input_num = 0;	//��¼�Ƿ��������
int iFile = 0;	//������ʱ�ļ��ĸ������ļ���


static int ls[MAX_WAYS];	//������
double power[1000] ={0};	//atoF�����е�ָ��
int sortThread;		//�����������ݵ��߳�����
int itemProduced;   //���������߳���Ŀ
char readInFile[1000] = ".\\Sort.param";	//���ò����ļ�


typedef struct run_t {
	double *buf;	// ���뻺����
	long long length;	// ��������ǰ�ж��ٸ���
	int times;	// ��¼�鲢����ʱÿ����ʱ�ļ���Ҫ���Ĵ���
	int x_times;   //��¼�鲢����ʱÿ����ʱ�ļ��Ѿ����Ĵ���
	long long idx;  // ��������ָ��
} run_t;

struct ItemRepository{
	char str[8][BUF_SIZE+10];	 //����ÿ�ζ������ַ�
	int readPosition;	//������λ��.
	int writePosition;  //д����λ��
	int itemCounter;   //��¼�����ļ�����
	mutex mtx;	//������������������
	mutex itemCounterMtx;   //��������������д�߳�ͬʱ����
	condition_variable repoNotFull;		//����������ָʾ��������Ϊ��
	condition_variable repoNotEmpty;	//����������ָʾ��������Ϊ��
}gItemRepository;


char inputFile[1000]  =  "";	//���������� �����ļ���
char outputFile[1000] = "";    //���������� ����ļ���
ofstream fout;
ifstream fin;

void initItem(ItemRepository *ir);     //��ʼ������
void adjust(run_t **runs, int n, int s);	//����������
void createLoserTree(run_t **runs, int n);	//����������
void mergeSort(int num_of_runs, const char* file_out);	//�鲢����
void radixSort(double input[], long long length);	//��������
double atoF(char s[]);	//���ַ���ת��Ϊ��������������ֵ
void readItem(ItemRepository *ir,int item);	//�ֿ��ȡ�ļ�
void readTask();	//�ֿ���ļ�����
void writeItem(ItemRepository *ir);	//�ֿ鴦���ļ������ַ���ת��Ϊ����������������д���ļ�
void writeTask();	//�ֿ鴦���ļ�����
int ftoA(double dnum, char* str, int len);	//��������ת��Ϊ�ַ����������ַ�������
int findThePoint(int left, int right, double dnum);	  //��������ת��Ϊ�ַ���ʱ�����ֲ��ҷ���С�����λ��


int main()
{
	//��ʼ������
	cout<<"��ȡ���ò���,��ʼ�����ݡ�����"<<endl;
	initItem(&gItemRepository);
	cout<<"1�����߳�"<<endl;
	cout<<sortThread - 1<<"��д�߳�"<<endl;

	clock_t s, e;
	s = clock();
	clock_t s1, e1;
	s1 = clock();

	fin.open(inputFile, ios::binary);
	if (!fin.is_open())
	{
		cout<<"can't open file "<<inputFile<<endl;
		exit(0);
	}

	//����1�����̣߳�sortThread-1��д�߳�
	thread readT(readTask);
	thread writeT[100];
	for (int i = 0; i < sortThread - 1; i++)
	{
		writeT[i] = thread(writeTask);
	}
	readT.join();
	for (int i = 0; i < sortThread - 1; i++)
	{
		writeT[i].join();
	}

	fin.close();
	e1 = clock();
	cout<<"��������ʱ��"<<(double)(e1 - s1) / CLOCKS_PER_SEC<<endl;
	cout<<"�鲢�εĸ���Ϊ��"<<numRuns<<endl;
	cout<<"�ļ��ܴ�СΪ��"<<sum_size<<endl;
	cout<<"�ܵĸ�����Ϊ��"<<sum<<endl;
	cout<<"�Ƿ�����ĸ���Ϊ��"<<illegal_input_num<<endl;

	//�鲢����
	clock_t s2, e2;
	s2 = clock();
	mergeSort(numRuns, outputFile);
	e2 = clock();
	cout<<"�鲢����ʱ��"<<(double)(e2 - s2) / CLOCKS_PER_SEC<<endl;
	e = clock();
	cout<<"������ʱ��"<<(double)(e - s) / CLOCKS_PER_SEC<<endl;

	//ɾ���ļ�
	for (int i =0; i < numRuns; i++)
	{
		remove("i+100");
	}

	return 0;
}



//���ܣ��������ò�������ʼ������
//������ItemRepository�ṹ��
//����ֵ����
void initItem(ItemRepository *ir)
{
	//��ʼ����дλ��
	ir->writePosition = 0;
	ir->readPosition = 0;
	ir->itemCounter = 0;

	//��ʼ��power���� 1e-308��1e+308
	power[0] = 1e-308;
	for (int i = 1; i < 617; i++)
	{
		power[i] = power[i-1] * 10.0;
	}

	char line[10][1000];
	char strtemp[1000];
	ifstream readin;
	readin.open(readInFile);

	//�����һ�У�ȷ�������ļ���
	readin.getline(line[0], sizeof(line[0]));
	sscanf(line[0], "%*100[^=]%100[^;]", strtemp);
	int k = 0;
	for (int j = 1; j < strlen(strtemp); j++)
	{
		if (strtemp[j] =='\\')
		{
			inputFile[k++] = '\\';
			inputFile[k++] = '\\';
		}
		else
		{
			inputFile[k++] = strtemp[j];
		}
	}
	inputFile[k] = '\0';

	//����ڶ��У�ȷ������ļ���
	readin.getline(line[1], sizeof(line[1]));
	sscanf(line[1], "%*100[^=]%100[^;]", strtemp);
	k = 0;
	for (int j = 1; j < strlen(strtemp); j++)
	{
		if (strtemp[j] =='\\')
		{
			outputFile[k++] = '\\';
			outputFile[k++] = '\\';
		}
		else
		{
			outputFile[k++] = strtemp[j];
		}
	}
	outputFile[k] = '\0';

	//��������У�ȷ��д�߳���Ŀ
	readin.getline(line[2], sizeof(line[2]));
	sscanf(line[2], "%*100[^=]=%d[^;]", &sortThread);
	itemProduced = sortThread;
	readin.close();
}

//���ܣ����̶߳�ȡ�ļ�
//������ItemRepository�ṹ�壬�����ļ����
//����ֵ����
void readItem(ItemRepository *ir,int item)
{
	//���ļ��̣߳������ߣ��ȴ�����������Ϊ������һ��������
	unique_lock<mutex> lock(ir->mtx);
	while (((ir->writePosition + 1) % itemProduced)== ir->readPosition)
	{
		(ir->repoNotFull).wait(lock);
	}

	//�ֿ��ȡ�ļ�
	fin.read((ir->str)[item], BUF_SIZE * sizeof(char));
	ir->writePosition ++;
	//buf_size_temp[item] = fin.gcount();
	buf_size_temp[item] = BUF_SIZE;

	//�ҵ����һ�������ĸ�������λ�ã����ļ�ָ�뵹�˵���λ��
	int offset = 0;
	for (long long tp = buf_size_temp[item] - 1; tp >= 0; tp --)
	{
		if ((ir->str)[item][tp] == '\n')
		{
			buf_size_temp[item]  = tp + 1;
			(ir->str)[item][buf_size_temp[item]] = '\0';
			break;
		}
		offset--;
	}
	streampos sp = fin.tellg();
	fin.seekg(offset, ios::cur);

	sum_size = sum_size + buf_size_temp[item];

	//д��λ�������ڶ����������������Ϊ��ʼλ��
	if (ir->writePosition == itemProduced)
		ir->writePosition = 0;

	//֪ͨ���̣߳������ߣ���Ʒ�ⲻΪ��
	(ir->repoNotEmpty).notify_all();
	lock.unlock();
}

//���ܣ�����readItem�����ֿ��ȡ�ļ�
//��������
//����ֵ����
void readTask()
{
	//�ֿ��ȡ��ѭ������itemProduced���ļ�
	int item = 0;
	while (fin.peek() != EOF)
	{
		readItem(&gItemRepository, item);
		item ++;
		if (item == itemProduced)
		{
			item = 0;
		}
		numRuns ++;
	}
	readIsOver = true;
}

//���ܣ�����ֿ��ļ���������д��
//������ItemRepository�ṹ��
//����ֵ����
void writeItem(ItemRepository *ir)
{
	run_t *runs = (run_t *)malloc(sizeof(run_t) * 100);
	runs->buf = (double *)calloc(EACH_DOUBLE_NUM, sizeof(double));
	int item = 0;
	std::unique_lock<std::mutex> lock(ir->mtx);

	//д�ļ��̣߳������ߣ��ȴ�����������Ϊ�ա���һ��������
	while(ir->writePosition == ir->readPosition)
	{
		(ir->repoNotEmpty).wait(lock);
	}
	item = ir->readPosition;
	(ir->readPosition)++;


	long long jp = 0, ip = 0, kp = 0;
	long long pre = 0;	//��¼�����ַ�����λ��
	bool flag = false;	//����Ƿ�Ϊ��һ�������Ƿ��ַ�
	char illegal_input[100]; //����Ƿ������ַ�


	//���ַ���ת��Ϊ������
	for (ip = 0; ip < buf_size_temp[item]; ip++)
	{
		int tmp = 0;

		//�жϷǷ�����
		if ((((ir->str)[item][ip] < '0') || ((ir->str)[item][ip] > '9'))
			&& ((ir->str)[item][ip] != '-')&& ((ir->str)[item][ip] != '+')
			&& ((ir->str)[item][ip] != '\r') && ((ir->str)[item][ip] != 'e')
			&& ((ir->str)[item][ip] != 'E') && ((ir->str)[item][ip] != '.')
			&& ((ir->str)[item][ip] != '\n')){
			if (!flag)
			{
				//������һ���Ƿ��ַ������ҵ��÷Ƿ��ַ�������������ƶ�ipλ��
				flag = true;
				for (long long mp = pre; mp < buf_size_temp[item]; mp++)
				{
					illegal_input[mp - pre] = (ir->str)[item][mp];
					if ((ir->str)[item][mp] == '\n')
					{
						illegal_input[mp - pre] = '\0';
						illegal_input_num ++;
						cout<<"�Ƿ����룺"<<illegal_input<<endl;
						ip =  mp;
						break;
					}
				}
			}
		}

		//��������\n��,���ʾ����һ���������ַ�����ת��Ϊ������
		if ((ir->str)[item][ip] == '\n')
		{
			if (flag)
				pre = ip + 1;
			else
			{
				(ir->str)[item][ip] ='\0';
				runs->buf[jp] = atoF((ir->str)[item]+pre);
				pre = ip+1;
				jp++;
			}
			flag = false;

		}
		else if ((ir->str)[item][ip] == '\r')
		{
			(ir->str)[item][ip] = '\0';
		}
	}
	//��¼ÿ��С�ļ��и������ĸ���
	runs->length = jp;
	temp_file_num[iFile] = jp;

	//��ÿ��С�ļ����л�������
	radixSort(runs->buf, runs->length);

	//����������д��ÿ��С�ļ���
	ofstream out_temp;
	char out_temp_file[10];  //С�ļ���ʱ�ļ���
	sprintf(out_temp_file, "%d", iFile+100);
	out_temp.open(out_temp_file, ios::binary);
	if (!out_temp.is_open())
	{
		printf("FILE OPEN ERROR!\n");
		exit(0);

	}
	out_temp.write((char*)runs->buf, runs->length * sizeof(double));
	out_temp.close();

	sum = sum + temp_file_num[iFile]; //��¼���븡�����ܵĸ���
	free(runs->buf);
	free(runs);
	iFile ++; //�ļ�����1

	//����λ�������ڶ����������������Ϊ��ʼλ��
	if (ir->readPosition >= itemProduced)
		ir->readPosition = 0;
	(ir->repoNotFull).notify_all();
	lock.unlock();
}

//���ܣ�����writeItem�������ֿ��ȡ�����ݴ��������д��С�ļ���
//��������
//����ֵ����
void writeTask()
{
	bool readyToExit = false;
	while(1)
	{
		unique_lock<mutex> lock(gItemRepository.itemCounterMtx);
		//�жϴ�����ļ����Ƿ�ﵽ���ֵ��ļ������������ļ��Ƿ񶼴������
		if ((!readIsOver) || (gItemRepository.itemCounter < numRuns))
		{
			 writeItem(&gItemRepository);
			 (gItemRepository.itemCounter) ++;
		}
		else
		{
			readyToExit = true;
		}
		lock.unlock();
		if(readyToExit)
		{
			break;
		}
	}

}


//���ܣ����ַ���ת��Ϊ������
//��������ת�����ַ���
//����ֵ��ת����ĸ�����
double atoF(char s[])
{
	int i, cnt = 0;
	int sign_1;		//��Ǹ�������������-1��ʾ����1��ʾ��
	bool find_frist_non_zero = false;	//�ҵ���һ����Ч���֣�����0����
	bool sign_2 = true;  //���e������Ƿ�Ϊ����
	double rate = 1.0;
	bool bDot = false;	//����Ƿ����С����
	bool bE = false;	//��ʾ�Ƿ���ֿ�ѧ��������ʾ�ĸ����������Ƿ���e
	double ret = 0.0;	//���渡����
	int exp = 0;

	//��������ǰ�Ŀո�
	for(i = 0; isspace(s[i]); i++);

	//��ô˸�����������
	sign_1 = s[i] == '-' ? -1 : 1;
	if(s[i] == '-' || s[i] == '+')
		i++;
	for(ret = 0.0; s[i] != '\0'; i++)
	{
		if(s[i] == '.')
		{
			bDot = true;
			i++;
		}
		//���˸�����ʹ�ÿ�ѧ��������ʾ������bE��sign_2
		if((s[i] == 'e') || (s[i] == 'E'))
		{
			bE = true;
			i++;
			if((s[i] == '-') || (s[i] == '+'))
			{
				sign_2 = s[i]== '-' ? false : true;
				i++;
			}
		}
		if(!bE)
		{
			//�ҵ���һ����0����
			if (((s[i]-'0') != 0) && (!find_frist_non_zero))
			{
				find_frist_non_zero = true;
			}
			if (find_frist_non_zero && (cnt < 12)) //ֻ������11���ַ�
			{
				cnt ++;
			}
			//���������⣬������11λ���ڵ���5����ǰһλֱ�Ӽ�1����ǰΪ����
			if(!bDot)
			{
				if (cnt == 11)
				{
					if ((s[i]-'0') >= 5)
					{
						ret = (ret + (double)1.0) * 10.0;
						continue;
					}

				}
				ret = (ret * 10.0) + (s[i] - '0'); //��ֻ�ǳ���10�����о�����ʧ
			}
			else
			{
				if (cnt == 11)
				{
					if ((s[i]-'0') >= 5)
					{
						ret = ret + ((double)1.0) / rate;
						rate = rate * 10.0;
						continue;
					}

				}
				rate = rate * 10.0;
				ret = ret + ((double) (s[i] - '0')) / rate; //����ǿ��ת����double������ʧ����
			}
		}
		//�����ֿ�ѧ��������ʾ�ĸ�����������exp����ָ��
		else
		{
			exp = 10 * exp + (s[i] - '0');
		}
	}
	if(sign_2)
		ret = ret * power[308 + exp];
	else
		ret = ret * power[308 - exp];

	return sign_1 * ret;
}

//���ܣ��Էֿ�����ĸ��������л�������
//���������������飬���鳤��
//����ֵ����
void radixSort(double input[], long long length)
{
	double *tmp_12 = (double *)malloc((length+10) * sizeof(double));
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
			bucket[reinterpret_cast<unsigned long long&>(input[j])>>digit & 0xffff]++;
		//������ε���ʼλ��
		for (int j = 1; j < 65536; j++)
			bucket[j] = bucket[j-1] + bucket[j];
		//���Ƶ���ʱ���飬����¼�����ĸ���
		for (long long j= length - 1; j >= 0; j--)
		{
			int temp = --bucket[reinterpret_cast<unsigned long long&>(input[j])>>digit & 0xffff];
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

//���ܣ�������˳�����й鲢�����γ����յ������ļ�
//�������鲢·�����ָ��С�ļ���������������ļ���
//����ֵ����
void mergeSort(int num_of_runs, const char* file_out)
{
	//����ÿ��ȡ���������ĸ���������������һ���ļ��ĸ�������Ŀ���������һ���ļ�Ϊ��׼ȡ��
	long long length_per_run = (MAX_NUM/20) / num_of_runs;
	if (length_per_run > temp_file_num[num_of_runs - 1] )
	{
		length_per_run = temp_file_num[num_of_runs - 1];
	}
	cout<<"ÿ��ȡ���ַ�����"<<length_per_run<<endl;

	//��ʼ���ṹ��run_t��������ÿ���ļ���Ҫ��ȡ�Ĵ���
	run_t **runs = (run_t **)malloc(sizeof(run_t *)*(num_of_runs+1));
	for (int i = 0; i < num_of_runs; i++)
	{
		runs[i] = (run_t *)malloc(sizeof(run_t));
		runs[i]->buf = (double *)calloc((length_per_run +100),  sizeof(double));
		runs[i]->x_times = 0;
		runs[i]->times =(int) (temp_file_num[i] / length_per_run);
		int temp = (int)(temp_file_num[i] % length_per_run);
		if (temp != 0)
		{
			runs[i]->times ++;
		}
	}

	// ��ÿ��˳���ļ���length_per_run���ݶ�����������
	ifstream in[100];
	char file_name[20];
	for (int i = 0; i < num_of_runs; i++)
	{
		sprintf(file_name, "%d", i+100);
		in[i].open(file_name, ios::binary);
		in[i].read((char *)runs[i]->buf, length_per_run * sizeof(double));
		runs[i]->x_times ++;
		runs[i]->length = length_per_run;
		runs[i]->idx = 0;
	}

	//������������������
	createLoserTree(runs, num_of_runs);

	cout<<"����д�������ļ��С�����"<<endl;

	ofstream final;
	final.open(file_out, ios::binary);
	int live_runs = num_of_runs;
	int pbuf_len = 0;
	char *pbuf = (char *)malloc((MAX_NUM + 1000) * sizeof(char));

	while (live_runs > 0)
	{
		//����д�������ļ��У����������е��ַ�������MAX_NUMʱд��
		pbuf_len += ftoA(runs[ls[0]]->buf[runs[ls[0]]->idx++], &(*(pbuf+ pbuf_len)), 9);
		if (pbuf_len >= MAX_NUM)
		{
			final.write(pbuf, pbuf_len);
			pbuf_len = 0;
		}
		//���ĳһ˳���ļ������ݶ������������ls[0]��Ϊ���ֵ
		if ((runs[ls[0]]->x_times  == runs[ls[0]]->times) && (runs[ls[0]]->idx == runs[ls[0]]->length))
		{
			runs[ls[0]]->buf[runs[ls[0]]->idx] = DBL_MAX;
			live_runs--;
		}
		//�����ǰ˳���ж�ȡ�����ݴ����꣬�������ȡ
		else if (runs[ls[0]]->idx == runs[ls[0]]->length)
		{
			long long ac_length_per_run = length_per_run;
			//��Ϊ���һ�ζ�ȡ��ǰ�ļ�����ȡ��ʣ��ĸ�����
			if (runs[ls[0]]->x_times  == (runs[ls[0]]->times - 1))
			{
				ac_length_per_run = temp_file_num[ls[0]] - length_per_run * runs[ls[0]]->x_times;
			}
			in[ls[0]].read((char *)runs[ls[0]]->buf, ac_length_per_run * sizeof(double));
			runs[ls[0]]->x_times ++;
			runs[ls[0]]->length = ac_length_per_run;
			runs[ls[0]]->idx = 0;
		}
		//����������
		adjust(runs, num_of_runs, ls[0]);
	}
	final.write(pbuf, pbuf_len);
	free(pbuf);

	//�ر��ļ����ͷ��ڴ�ռ�
	for (int i = 0; i < num_of_runs; i++)
	{
		in[i].close();
		free(runs[i]->buf);
		free(runs[i]);
	}
	free(runs);
	final.close();
}

//���ܣ�����������
//������run_t�ṹ�壬 �����ļ��ĸ���
//����ֵ����
void createLoserTree(run_t **runs, int n)
{
	for (int i = 0; i < n; i++)
	{
		ls[i] = -1;
	}
	for (int i = n-1; i >= 0; i--)
	{
		adjust(runs, n, i);
	}
}

//���ܣ�������������ÿ�ζ�����ֵ����������
//����:run_t�ṹ�壬�����ļ���������ǰ�ļ��±�
//����ֵ����
void adjust(run_t **runs, int n, int s)
{
	int t = (s + n) / 2;
	int tmp;

	while (t != 0)
	{
		if (s == -1)
			break;
		if (ls[t] == -1 || runs[s]->buf[runs[s]->idx] >
			runs[ls[t]]->buf[runs[ls[t]]->idx])
		{
			tmp = s;
			s = ls[t];
			ls[t] = tmp;
		}
		t /= 2;
	}
	ls[0] = s;
}

//���ܣ���������ת�����ַ�������ʽ����ѧ��������ʾ��������9λС��
//��������ת����С�����洢С�����ַ�����,��ѧ����������С����λ��
//����ֵ��ת������ַ����ĳ���
int ftoA(double dnum, char* str, int len)
{
	int arrayNum[100]; //��¼ÿ��ȡ�����������������֣����100λ
	int pointPos=0;//С�����λ��
	bool sign_1 = false; //��¼����or����
	bool sign_2 = false; //��¼����1orС��1 ����ѧ������e�������Ϊ��or��
	double lastDigit = 5.0;
	len = len + 2;
	//���Ϊ��������ת��Ϊ����
	if(dnum < 0)
	{
		dnum = -dnum;
		sign_1 = true;
	}
	if (dnum == 0.0 || (dnum >= 1.0 && dnum < 10.0))
	{
		sign_2 = true;
	}
	//���ֲ���С�����λ��
	if (dnum >= 10.0)
	{
		int temp = findThePoint(0, 308, dnum);
		dnum = dnum * power[temp];
		pointPos = 308 - temp;
		sign_2 = true;
	}
	if ((dnum < 1.0) && (dnum != 0.0))
	{
		int temp = findThePoint(308, 616, dnum);
		dnum = dnum * power[temp];
		pointPos = temp - 308;
	}
	//len+1 λ����5
	lastDigit = lastDigit * power[308 - len - 1];

	//ÿ��ȡ����ǰ���������������ֲ���¼��������
	for(int i = 0; i < len; i++)
	{
		if (i == 1)
		{
			arrayNum[i] = -2;   //��ǰλΪС����
			continue;
		}
		int num = (int)dnum;
		arrayNum[i] = num;
		dnum = dnum - (int)dnum;
		dnum = (dnum + lastDigit) * 10.0;
	}

	//����������ת��Ϊ�ַ���
	int k = 0;
	if (sign_1) //�ж��Ƿ�Ϊ����
	{
		str[k] = '-';
		k++;
	}
	for(int i = 0;i < len; i++)
	{
		if(i == 1)
		{
			str[k++] = '.';
			continue;
		}
		str[k++] = arrayNum[i]+'0';
	}
	str[k++] = 'E';

	//�ж�ָ�����ֵ�����
	if (sign_2)
		str[k++] = '+';
	else
		str[k++] = '-';

	//��ָ������ת��Ϊ�ַ��� ��Χ0-308
	if (pointPos < 10)
	{
		str[k++] = '0';
		str[k++] = '0';
		str[k++] =  pointPos + '0';
	}
	else if(pointPos < 100)
	{
		str[k++] = '0';
		str[k++] = pointPos / 10 + '0';
		str[k++] = pointPos % 10 + '0';
	}
	else if(pointPos < 1000)
	{
		str[k++] = pointPos / 100 % 10 + '0';
		str[k++] = pointPos / 10 % 10 + '0';
		str[k++] = pointPos % 10 + '0';
	}
	str[k++]='\n';
	str[k]='\0';
	return strlen(str);
}

//���ܣ����ֲ���С�����λ��
//���������ҵ���ʼλ�ã���ֹλ�ã������ҵ���
//����ֵ�����ص�ǰ��ָ���Ĵ�С��С�����λ�ã�
int findThePoint(int left, int right, double dnum)
{
	int mid = (left + right) / 2;;
	double tmp = 0.0;
	while (left <= right)
	{
		mid = (left + right) / 2;
		tmp = dnum * power[mid];
		if (tmp >= 1.0 && tmp < 10.0)
			break;
		if (tmp >= 10.0)
		{
			right = mid - 1;
		}
		else if (tmp < 1.0)
		{
			left = mid + 1;
		}
	}
	return mid;
}

