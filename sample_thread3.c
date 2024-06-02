#include <stdio.h> 
#include <pthread.h> 
void func(int x); 
int count = 0;
int count1 = 0; 
int main(){ 
    pthread_t t1; 
    pthread_t t2; 
    pthread_create( &t1, NULL, (void*)func, (void*)1); 
    pthread_create( &t2, NULL, (void*)func, (void*)2); 
    printf("main()\n"); 
    pthread_join( t1, NULL); 
    pthread_join( t2, NULL); 
    printf("count = %d\n",count); 
    //printf("count1 = %d\n",count1); クリティカルセクション回避 
    return 0; 
} 

 void func(int x){ 
 int i; 
 for(i = 0;i < 10000000;i ++){ // すぐに終了する場合は，この値を大きくする． 
  count ++; /*この書き方だと二つのスレッドが一つの変数にアクセスするのでクリティカルセクションが発生。
  例えば、t1がi=100のときに値を読みiにi++で101を書き出す間にt2もi=100を読んでしまいiに101を書き出す(本来はt2にi=101を読んで102を書き出してほしいのに)*/
 }
 }


/*クリティカルセクション回避
void func(int x){ 
 int i; 
 for(i = 0;i < 1000000000;i ++){ // すぐに終了する場合は，この値を大きくする．
 if(x==1){ 
  count ++;
 }else if (x == 2){
    count1 ++;
 }
 } 
}*/