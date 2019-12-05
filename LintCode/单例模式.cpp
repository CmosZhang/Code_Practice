#include<iostream>
#include<algorithm>
#include<pthread.h>

using namespace std;

//������ʽ:
//���ʵ���ڵ��߳�������ȷ�ģ������ڶ��߳�����£���������߳�
//ͬʱ�״ε���getInstance������ͬʱ��⵽Instance��NULL��������
//�̻߳�ͬʱ����һ��ʵ����Instance�������ͻᷢ������
class Singleton
{
private:
	Singleton() {};//˽�еĹ��캯��
	static Singleton *Instance;
public:
	static Singleton *getInstance()
	{
		if (Instance == NULL)
		{
			Instance = new Singleton();
		}
		return Instance;
	}
};


//�Ľ�������ʽ��˫�ؼ������
//˼·��ֻ���ڵ�һ�δ�����ʱ���������Instance��Ϊ�յ�ʱ��Ͳ���Ҫ����
class Singleton
{
private:
	Singleton() {}
	static Singleton*Instance;
public:
	static Singleton *GetInstance()
	{
		if (Instance == NULL)
		{
			Lock();//��ʾ�����ĺ���
			if (Instance == NULL)
			{
				Instance = new Singleton();
			}
			UnLock();//��ʾ�����ĺ���
		}
		return Instance;
	}
};

//������ʽ��
//����ʽ���ص���һ��ʼ�ͼ��أ���Ϊһ��ʼ�ʹ�����ʵ��������ÿ���õ���֮���ֱ�ӷ��ؾͺ�
//������ʽ���̰߳�ȫ��
class singleton
{
private:
	singleton() {};
public:
	static singleton* getsingleton()
	{
		static singleton instance;
		return &instance;
	}
};


//�����ľ�������ģʽ
class singleton {
private:
	static singleton *p;
protected:
	singleton() {
		pthread_mutex_init(&mutex);
	}
public:
	static pthread_mutex_t mutex;
	static singleton *instance();
};

pthread_mutex_t singleton::mutex;
singleton*singleton::p = NULL;
singleton *singleton::instance() {
	if (p == NULL) {
		pthread_mutex_lock(&mutex);
		if (p == NULL) {
			p = new singleton();
		}
		pthread_mutex_unlock(&mutex);
	}
	return p;
}
