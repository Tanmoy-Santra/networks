//client6
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#define SERVER_PORT 4000
#define SERVER_IP "127.0.0.1"
#define CLIENT_PORT 4001
#define CLIENT_IP "127.0.0.1"
int main(){
    int sd;
    char str[512],str1[512];
    struct sockaddr_in client,server;
    bzero((char*)&client,sizeof(client));
    client.sin_family=AF_INET;
    client.sin_port=htons(CLIENT_PORT);
    client.sin_addr.s_addr=inet_addr(CLIENT_IP);
    bzero((char*)&server,sizeof(server));
    server.sin_family=AF_INET;
    server.sin_port=htons(SERVER_PORT);
    server.sin_addr.s_addr=inet_addr(SERVER_IP);
    sd=socket(AF_INET,SOCK_STREAM,0);
    bind(sd,(struct sockaddr*)&client,sizeof(client));
    connect(sd,(struct sockaddr*)&server,sizeof(server));

    do{
        printf("\nenter the msg : ");
        scanf("%s",str1);
        send(sd,str1,strlen(str1)+1,0);
        memset(str,0x0,512);
        recv(sd,str,512,0);
        printf("\nreceived msg :%s",str);

    }while(strcmp(str1,"stop"));
    close(sd);
}

