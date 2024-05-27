//server6
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<time.h>
#define SERVER_PORT 4000
#define SERVER_IP "127.0.0.1"
int main(){
    struct sockaddr_in client,server;
    int sd,nsd,clen=sizeof(client);
    char str[512],str1[512]="invalid request";
    char *ptr;
    time_t ti;
    bzero((char*)&server,sizeof(server));
    server.sin_family=AF_INET;
    server.sin_port=htons(SERVER_PORT);
    server.sin_addr.s_addr=inet_addr(SERVER_IP);
    sd=socket(AF_INET,SOCK_STREAM,0);
    bind(sd,(struct sockaddr*)&server,sizeof(server));
    listen(sd,5);
    while(1){
         nsd = accept(sd, (struct sockaddr*)&client, &clen);
    do{
        memset(str,0x0,512);
        recv(nsd,str,512,0);
        if(strcmp(str,"time")==0){
            ti=time(NULL);
            ptr=ctime(&ti);
            send(nsd,ptr,strlen(ptr)+1,0);
        }
        else{
             send(nsd,str1,strlen(str1)+1,0);        }

    }while(strcmp(str,"stop"));
    close(nsd);}}