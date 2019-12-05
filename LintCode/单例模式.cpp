#include<iostream>
#include<algorithm>
#include<pthread.h>

using namespace std;

//懒汉方式:
//这个实现在单线程下是正确的，但是在多线程情况下，如果两个线程
//同时首次调用getInstance方法且同时检测到Instance是NULL，则两个
//线程会同时构造一个实例给Instance，这样就会发生错误。
class Singleton
{
private:
	Singleton() {};//私有的构造函数
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


//改进的懒汉式（双重检查锁）
//思路：只有在第一次创建的时候加锁，当Instance不为空的时候就不需要加锁
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
			Lock();//表示上锁的函数
			if (Instance == NULL)
			{
				Instance = new Singleton();
			}
			UnLock();//表示解锁的函数
		}
		return Instance;
	}
};

//饿汉方式：
//饿汉式的特点是一开始就加载，因为一开始就创建了实例，所以每次用到的之后就直接返回就好
//饿汉方式是线程安全的
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


//加锁的经典懒汉模式
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
