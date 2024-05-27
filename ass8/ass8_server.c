//server8

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#define SERVER_PORT 5000
#define SERVER_IP "127.0.0.1"
#define CLIENT_PORT 5001
#define CLIENT_IP "127.0.0.1"
#include<time.h>
int main(){
        struct sockaddr_in client,server;
        char str[512],str1[512]="bad request";
        int sd,clen=sizeof(client);
        char *ptr;
        time_t ti;
        bzero((char*)&server,sizeof(server));
        server.sin_family=AF_INET;
        server.sin_port=htons(SERVER_PORT);
        server.sin_addr.s_addr=inet_addr(SERVER_IP);
        sd=socket(AF_INET,SOCK_DGRAM,0);
        bind(sd,(struct sockaddr*)&server,sizeof(server));

        while(1){
                do{     memset(str,0x0,512);
                        recvfrom(sd,str,512,0,(struct sockaddr*)&client,&clen);
                        if(strcmp(str,"time")==0){
                                ti=time(NULL);
                                ptr=ctime(&ti);
                                sendto(sd,ptr,strlen(ptr)+1,0,(struct sockaddr*)&client,sizeof(client));
                        }
                        else{sendto(sd,str1,strlen(str1)+1,0,(struct sockaddr*)&client,sizeof(client));}
                }while(strcmp(str,"stop"));
                close(sd);      }}