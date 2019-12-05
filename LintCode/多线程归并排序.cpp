#include <pthread.h>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <thread>
#include <string.h>
//#include <unistd.h>
//#include <mysql/mysql.h>

using namespace std; 

struct node
{    
	int l,r; 
	int id;
}; 

const int Maxn = 100;
int a[Maxn];

pthread_mutex_t mut = PTHREAD_MUTEX_INITIALIZER; 

void merge(int left1,int right1,int left2,int right2)
{  
	int n = right2 - left1 + 1;
	int *data = new int[n];
	for(int i=0;i<n;i++) 
		data[i] = 0; 
	int l1 = left1,l2 = left2,i = 0;  
	while(l1 <= right1 && l2 <= right2)  
	{      
		if(a[l1] < a[l2])   
			data[i++] = a[l1++];  
		else           
			data[i++] = a[l2++]; 
	}    
	while(l1 <= right1)
		data[i++] = a[l1++]; 
	while(l2 <= right2) 
		data[i++] = a[l2++];  
	int id = 0;   
	for(int i = left1;i<=right2;i++)  
		a[i] = data[id++];    
	delete[] data;
} 


void sort(int left,int right)
{   
	if(left >= right) 
		return;     
	int l = left,r = right; 
	while(l < r)  
	{       
		while(l < r && a[l] <= a[r])
			l++;        
		if(l != r) 
			swap(a[l],a[r]); 
		while(l < r && a[l] <= a[r])
			r--;       
		if(l != r) 
			swap(a[l],a[r]); 
	}      
	sort(left,l-1); 
	sort(l+1,right); 
	return;
} 

void* __sort(void* segment)
{    
	struct node * Segment; 
	Segment = (struct node*) segment;
	cout << "Thread " << Segment->id << ":Sort begin!" << endl;
	sort(Segment->l, Segment->r);
	cout << "Thread " << Segment->id << ":Sort End!" << endl;
} 

int main()
{    
	srand((unsigned)time(NULL)); 
	for(int i=0;i<100;i++)      
		a[i] = rand()%1000; 
	for(int i=0;i<100;i++)   
		cout << a[i] << " ";  
	cout << endl;    
	struct node s[10]; 
	for(int i=0;i<10;i++)  
	{        
		s[i].id = i;   
		s[i].l = i*10;  
		s[i].r = i*10+9;  
	}    
	pthread_t t[10];  
	for(int i=0;i<10;i++)   
		pthread_create(&t[i],NULL,__sort,(void *)&s[i]);  
	for(int i=0;i<10;i++)        
		pthread_join(t[i],NULL);  
	int left = 0,right = 9;  
	for(int i=1;i<10;i++)  
	{       
		merge(left,right,s[i].l,s[i].r);    
		right += 10; 
	}    
	for(int i=0;i<100;i++)    
		cout << a[i] << " "; 
	cout << endl;  
	system("pause");
	return 0;
}
