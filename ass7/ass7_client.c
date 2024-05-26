//client7
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#define SERVER_PORT 5500
#define SERVER_IP "192.168.5.17"
#define CLIENT_PORT 5501
#define CLIENT_IP "127.0.0.1"
int main(){
         struct sockaddr_in client,server;
        char str1[512],str[512];
        int sd,slen=sizeof(server);
        bzero((char*)&client,sizeof(client));
        client.sin_family=AF_INET;
        client.sin_port=htons(CLIENT_PORT);
        client.sin_addr.s_addr=inet_addr(CLIENT_IP);
        bzero((char*)&server,sizeof(server));
        server.sin_family=AF_INET;
        server.sin_port=htons(SERVER_PORT);
        server.sin_addr.s_addr=inet_addr(SERVER_IP);

        sd=socket(AF_INET,SOCK_DGRAM,0);
        bind(sd,(struct sockaddr*)&client,sizeof(client));

        do{
                printf("\nenter  the msg :");
                scanf("%s",str);
                sendto(sd,str,strlen(str)+1,0,(struct sockaddr*)&server,sizeof(server));
                memset(str1,0x0,512);
                recvfrom(sd,str1,512,0,(struct sockaddr*)&server,&slen);
                printf("msg received from server : %s",str1);
        }while(strcmp(str,"stop"));
        close(sd);

}
