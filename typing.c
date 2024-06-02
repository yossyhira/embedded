#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <string.h> 
#include <pthread.h> 
 
void func(int x); 
char s[100] = ""; 
 
int main(){ 
 int count = 10; 
 char sa[100] = "start"; 
 pthread_t t1; 
 pthread_create( &t1, NULL, (void*)func, (void*)1); 
 while(1){ 
  printf("\033[2J\033[%d;%dH%s\n", 0, count --, sa); 
  usleep(500000); 
  if (!strcmp(s,sa)){ 
   for(int i = 0; i < 5; i ++) sa[i] = 0x61 + rand() % 26; 
   count = 10; 
  } 
 } 
 return 0; 
}


void func(int x){ 
    while(1){
    fgets(s, sizeof(s), stdin);
    s[strcspn(s, "\n")] = '\0';
    }  
}