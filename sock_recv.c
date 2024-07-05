#include <stdio.h>
#include <arpa/inet.h>
#include <unistd.h>//ソケット間通信に必要なヘッダ
int main()
{
int sock; //ソケットの番号
struct sockaddr_in addr;//ソケット通信用のデータ構造体
char buf [2048] ;

sock = socket(AF_INET, SOCK_DGRAM, 0);//ソケットの生成
addr.sin_family = AF_INET;//通信プロトコルの指定
addr.sin_port = htons(8000);//ポートの指定
addr.sin_addr.s_addr = INADDR_ANY;;//IPアドレス
bind(sock, (struct sockaddr *)&addr, sizeof(addr));// ソケットにアドレスを割り当てる
recv(sock, buf, sizeof(buf), 0);//受信する
printf("%s\n", buf);
close(sock);//ノンケットを解放
return 0;
}