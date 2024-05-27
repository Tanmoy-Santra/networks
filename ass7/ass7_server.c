///server7

include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#define SERVER_PORT 5000
#define SERVER_IP "127.0.0.1"

int main(){
         struct sockaddr_in client,server;
        char str1[512],str[512];
        int sd,clen=sizeof(client),nsd;

        bzero((char*)&server,sizeof(server));
        server.sin_family=AF_INET;
        server.sin_port=htons(SERVER_PORT);
        server.sin_addr.s_addr=inet_addr(SERVER_IP);

        sd=socket(AF_INET,SOCK_DGRAM,0);
        bind(sd,(struct sockaddr*)&server,sizeof(server));
        while(1){
        do{
                memset(str,0x0,512);
                recvfrom(sd,str,512,0,(struct sockaddr*)&client,&clen);
                sendto(sd,str,strlen(str)+1,0,(struct sockaddr*)&client,sizeof(client));

        }while(strcmp(str,"stop"));
        }
        close(sd);

}