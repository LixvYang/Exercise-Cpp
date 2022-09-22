#include <assert.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <string.h>
#include <sys/select.h>
#include <stdio.h>
#include <sys/socket.h>
#include <unistd.h>
#include <errno.h>

int main(int argc, char* argv[])
{
  if(argc<=2)
  {
    printf("usage:%s ip_address port_number\n", basename(argv[0]));
    return 1;
  }
  const char*ip=argv[1];
  int port=atoi(argv[2]);
  int ret=0;
  struct sockaddr_in address;
  address.sin_addr.s_addr = htonl(INADDR_ANY);
  address.sin_port = htons(port);
  address.sin_family = AF_INET;
  int listenfd = socket(AF_INET, SOCK_STREAM, 0);
  assert(listenfd>=0);
  ret=bind(listenfd, (struct sockaddr*)&address, sizeof(address));
  assert(ret!=-1);
  ret=listen(listenfd, 5);
  assert(ret!=-1);
  struct sockaddr_in client_address;
  socklen_t client_addrlength = sizeof(client_address);
  int connfd = accept(listenfd, (struct sockaddr*)&client_address, &client_addrlength);
  if (connfd < 0) {
    printf("errno is :%d \n", errno);
    close(listenfd);
  }
  char buf[1024];
  fd_set read_fds;
  fd_set exception_fds;
  FD_ZERO(&read_fds);
  FD_ZERO(&exception_fds);
  while (1) {
    memset(buf, '\0', sizeof(buf));
    FD_SET(connfd,&read_fds);
    FD_SET(connfd,&exception_fds);
    ret = select(connfd+1, &read_fds, NULL, &exception_fds, NULL);
    if(ret<0)
    {
      printf("selection failure\n");
      break;
    }
    /*对于可读事件，采用普通的recv函数读取数据*/
    if(FD_ISSET(connfd,&read_fds))
    {
      ret=recv(connfd,buf,sizeof(buf)-1,0);
      if(ret<=0)
      {
        break;
      }
      printf("get%d bytes of normal data:%s\n",ret,buf);
    }
    /*对于异常事件，采用带MSG_OOB标志的recv函数读取带外数据*/
    else if(FD_ISSET(connfd,&exception_fds))
    {
      ret=recv(connfd,buf,sizeof(buf)-1,MSG_OOB);
      if(ret<=0)
      {
      break;
      }
      printf("get%d bytes of oob data:%s\n",ret,buf);
    }
  }
  close(connfd);
  close(listenfd);
  return 0;
}