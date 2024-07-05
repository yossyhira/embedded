#include <arpa/inet.h>
#include <unistd.h>//ソケット間通信に必要なヘッダ
int main()
{
int sock; //ソケットの番号
struct sockaddr_in addr;//ソケット通信用のデータ構造体
char msg[] = "Hello World\n" ;

sock = socket(AF_INET, SOCK_DGRAM, 0);//ソケットの生成
addr.sin_family = AF_INET;//通信プロトコルの指定
addr.sin_port = htons(8000);//ポートの指定
addr.sin_addr.s_addr = inet_addr("192.168.1.3");//IPアドレス
sendto(sock, msg, sizeof(msg), 0, (struct sockaddr *)&addr, sizeof(addr)); //データを送信
close(sock);//ノンケットを解放
return 0;
}