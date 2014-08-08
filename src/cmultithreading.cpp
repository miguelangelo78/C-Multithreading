#include <stdio.h>
#include <windows.h>
#include <process.h>

void foo(void* id){
    printf("THREAD ID: %d\n",(*(int*)id));
	 _endthread();
}

int main(){
	const int MAX_THREADS=10;
	int process[MAX_THREADS];
	HANDLE thread[MAX_THREADS]; //CREATE THREADS
	for(int i=0;i<MAX_THREADS;i++)
		thread[i]=(HANDLE)_beginthread(foo,0,(void*)&(process[i]=i)); //START THREADS
	for(int i=0;i<MAX_THREADS;i++)
		WaitForSingleObject(thread[i],INFINITE); //JOIN THREADS
	return 0;
}
