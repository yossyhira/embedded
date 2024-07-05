# 組込みシステム実装論

実行方法

```bash
$ cd embedded
$ gcc typing.c -o typing -lpthread
$ ./typing
```

embedded wifiにつなぐこと！！！！！
```bash
$ cd embedded
$ gcc -o sock_chat  sock_chat.c -lpthread
$ ./sock_chat 8000 8001 192.168.1.3
```