#include <stdio.h>

#include <unistd.h>

#include <stdlib.h>

#include <string.h>

#include <sys/socket.h>

#include <arpa/inet.h>

#include <sys/fcntl.h>

int initserver(int port);


int main(int argc,char *argv[])

{

  if (argc != 2)

  {

    printf("usage: ./tcpselect port\n"); return -1;

  }


  // 初始化服务端用于监听的socket。

  int listensock = initserver(atoi(argv[1]));

  printf("listensock=%d\n",listensock);


  if (listensock < 0)

  {

    printf("initserver() failed.\n"); return -1;

  }


  fd_set readfdset;  // 读事件的集合，包括监听socket和客户端连接上来的socket。

  int maxfd;  // readfdset中socket的最大值。


  // 初始化结构体，把listensock添加到集合中。

  FD_ZERO(&readfdset);


  FD_SET(listensock,&readfdset);

  maxfd = listensock;


  while (1)

  {

    // 调用select函数时，会改变socket集合的内容，所以要把socket集合保存下来，传一个临时的给select。

    fd_set tmpfdset = readfdset;


    int infds = select(maxfd+1,&tmpfdset,NULL,NULL,NULL);

    // printf("select infds=%d\n",infds);


    // 返回失败。

    if (infds < 0)

    {

      printf("select() failed.\n"); perror("select()"); break;

    }


    // 超时，在本程序中，select函数最后一个参数为空，不存在超时的情况，但以下代码还是留着。

    if (infds == 0)

    {

      printf("select() timeout.\n"); continue;

    }


    // 检查有事情发生的socket，包括监听和客户端连接的socket。

    // 这里是客户端的socket事件，每次都要遍历整个集合，因为可能有多个socket有事件。

    for (int eventfd=0; eventfd <= maxfd; eventfd++)

    {

      if (FD_ISSET(eventfd,&tmpfdset)<=0) continue;


      if (eventfd==listensock)

      { 

        // 如果发生事件的是listensock，表示有新的客户端连上来。

        struct sockaddr_in client;

        socklen_t len = sizeof(client);

        int clientsock = accept(listensock,(struct sockaddr*)&client,&len);

        if (clientsock < 0)

        {

          printf("accept() failed.\n"); continue;

        }


        printf ("client(socket=%d) connected ok.\n",clientsock);


        // 把新的客户端socket加入集合。

        FD_SET(clientsock,&readfdset);


        if (maxfd < clientsock) maxfd = clientsock;


        continue;

      }

      else

      {

        // 客户端有数据过来或客户端的socket连接被断开。

        char buffer[1024];

        memset(buffer,0,sizeof(buffer));


        // 读取客户端的数据。

        ssize_t isize=read(eventfd,buffer,sizeof(buffer));


        // 发生了错误或socket被对方关闭。

        if (isize <=0)

        {

          printf("client(eventfd=%d) disconnected.\n",eventfd);


          close(eventfd);  // 关闭客户端的socket。


          FD_CLR(eventfd,&readfdset);  // 从集合中移去客户端的socket。


          // 重新计算maxfd的值，注意，只有当eventfd==maxfd时才需要计算。

          if (eventfd == maxfd)

          {

            for (int ii=maxfd;ii>0;ii--)

            {

              if (FD_ISSET(ii,&readfdset))

              {

                maxfd = ii; break;

              }

            }


            printf("maxfd=%d\n",maxfd);

          }


          continue;

        }


        printf("recv(eventfd=%d,size=%d):%s\n",eventfd,isize,buffer);


        // 把收到的报文发回给客户端。

        write(eventfd,buffer,strlen(buffer));

      }

    }

  }


  return 0;

}


// 初始化服务端的监听端口。

int initserver(int port)

{

  int sock = socket(AF_INET,SOCK_STREAM,0);

  if (sock < 0)

  {

    printf("socket() failed.\n"); return -1;

  } 

  // Linux如下

  int opt = 1; unsigned int len = sizeof(opt);

  setsockopt(sock,SOL_SOCKET,SO_REUSEADDR,&opt,len);

  setsockopt(sock,SOL_SOCKET,SO_KEEPALIVE,&opt,len);


  struct sockaddr_in servaddr;

  servaddr.sin_family = AF_INET;

  servaddr.sin_addr.s_addr = htonl(INADDR_ANY);

  servaddr.sin_port = htons(port);


  if (bind(sock,(struct sockaddr *)&servaddr,sizeof(servaddr)) < 0 )

  {

    printf("bind() failed.\n"); close(sock); return -1;

  }


  if (listen(sock,5) != 0 )

  {

    printf("listen() failed.\n"); close(sock); return -1;

  }


  return sock;

} 

#include <stdio.h>

#include <stdlib.h>

#include <unistd.h>

#include <errno.h>

#include <string.h>

#include <netinet/in.h>

#include <sys/socket.h>

#include <arpa/inet.h>


int main(int argc, char *argv[])

{

  if (argc != 3)

  {

    printf("usage:./tcpclient ip port\n"); return -1;

  }


  int sockfd;

  struct sockaddr_in servaddr;

  char buf[1024];

 

  if ((sockfd=socket(AF_INET,SOCK_STREAM,0))<0) { printf("socket() failed.\n"); return -1; }

  memset(&servaddr,0,sizeof(servaddr));

  servaddr.sin_family=AF_INET;

  servaddr.sin_port=htons(atoi(argv[2]));

  servaddr.sin_addr.s_addr=inet_addr(argv[1]);


  if (connect(sockfd, (struct sockaddr *)&servaddr,sizeof(servaddr)) != 0)

  {

    printf("connect(%s:%s) failed.\n",argv[1],argv[2]); close(sockfd);  return -1;

  }


  printf("connect ok.\n");


  for (int ii=0;ii<10000;ii++)

  {

    // 从命令行输入内容。

    memset(buf,0,sizeof(buf));

    printf("please input:"); scanf("%s",buf);

    // sprintf(buf,"1111111111111111111111ii=%08d",ii);


    if (write(sockfd,buf,strlen(buf)) <=0)

    { 

      printf("write() failed.\n");  close(sockfd);  return -1;

    }

    memset(buf,0,sizeof(buf));

    if (read(sockfd,buf,sizeof(buf)) <=0) 

    { 

      printf("read() failed.\n");  close(sockfd);  return -1;

    }


    printf("recv:%s\n",buf);


    // close(sockfd); break;

  }

}  