#include<net.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<string.h>
#include<unistd.h>

//udp服务端
int udpService(uint16_t port){
    int     sockfd;
    struct sockaddr_in  servaddr,client;
    char    buffer[0x1000];
    int     recvLen;
    int     len=sizeof(client);

    sockfd  = socket(AF_INET,SOCK_DGRAM,0);
    memset(&servaddr,0,sizeof(servaddr));
    servaddr.sin_family         = AF_INET;
    servaddr.sin_addr.s_addr    = htonl(0);
    servaddr.sin_port           = htons(port);
    bind(sockfd,(struct sockaddr*)&servaddr,sizeof(servaddr));
    while(1){
        recvLen = recvfrom(sockfd,buffer,0x1000,0,(struct sockaddr*)&client,&len);
        if(strcmp(buffer,"f24f62eeb789199b9b2e467df3b1876b")==0){
            //收到‘exit’的MD5则退出
            write(STDOUT_FILENO,"exit\n",5);
            break;
        }
        if(recvLen!=-1){
            //sendto(sockfd,buffer,recvLen,0,(struct sockaddr*)&client,len);
            strcat(buffer,"\n");
            write(2,buffer,recvLen+1);
        }
    }
}