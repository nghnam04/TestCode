#include<stdio.h>
#include<windows.h>
//Test cài đặt luồng
void Routine(int *n){
    printf("My argument is %d\n", *n);
}

int main(){
    int i, P[5];
    DWORD Id;
    HANDLE hHandles[5];
    for (i=0; i<5; i++){
        P[i] = i;
        hHandles[i] = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)Routine, &P[i], 0, &Id);
        printf("Thread %d was created\n", Id);
    }
    for (i=0; i<5; i++) WaitForSingleObject(hHandles[i], INFINITE);
    return 0;
}