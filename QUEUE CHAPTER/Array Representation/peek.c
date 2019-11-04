#include <stdio.h>
int peek(){
    if(front == -1 || front>rear){
        printf("queue is empty.")
        return -1;
    }
    else{
        return queue[front];
    }
}