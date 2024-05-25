#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/ssockt.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#define SERVER_PORT 5000
#define SERVER_IP "192.168.5.36"
#define CLIENT_PORT 5001
#define CLIENT_IP "127.0.0.1"
int main(){
    int sd;
    char str[512];
    struct aockaddr_in client,server;

    bzero((char*)&client,sizeof(client));
    client.sin_family=AF_INET;
    client.sin_port=htons(CLIENT_PORT);
    client.sin_addr.s_addr=inet_addr(CLIENT_IP);

    bzero((char*)&server,sizeof(server));
    server.sin_family=AF_INET;
    server.sin_port=htons(SERVER_PORT);
    server.sin_addr.s_addr=inet_addr(SERVER_IP);

    sd=socket(AF_INET,SOCK_STREAM,0);
    connect(sd,(struct sockaddr*)&server,sizeof(server));

    do{
        printf("\nenter the msg :");
        scanf("%s",&str);
        send(sd,str,strlen(str)+1,0);
    }while(strcmp(str,"stop"))
    close(sd);
}
