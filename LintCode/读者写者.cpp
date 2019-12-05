#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h> 

int buffer_has_item = 0;
pthread_mutex_t mutex; 


void* writer_function(void){
	while(1){
		pthread_mutex_lock(&mutex);	
		if(buffer_has_item==0){	
			buffer_has_item=1;	
			printf("Write once! \n");	
		}		
		pthread_mutex_unlock(&mutex);
	}	
	return 0;
}

void* reader_function(void*){
	while(1){
		pthread_mutex_lock(&mutex);	
		if(buffer_has_item==1){	
			buffer_has_item=0;	
			printf("Read once !\n"); 
		}	
		pthread_mutex_unlock(&mutex);
	}	
	return 0;
}


int main(void){	
	pthread_t reader;	
	pthread_mutex_init(&mutex,NULL);	
	pthread_create(&reader,NULL,reader_function,NULL);
	writer_function();	
	return 0;
}
