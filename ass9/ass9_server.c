//server9
//server9
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>
#define SERVER_PORT 4000
#define SERVER_IP "127.0.0.1"
int main(){
    struct sockaddr_in client,server;
    int pid,sd,nsd,clen=sizeof(client);
    char str[512],str1[512];
    bzero((char*)&server,sizeof(server));
    server.sin_family=AF_INET;
    server.sin_port=htons(SERVER_PORT);
    server.sin_addr.s_addr=inet_addr(SERVER_IP);
    sd=socket(AF_INET,SOCK_STREAM,0);
    bind(sd,(struct sockaddr*)&server,sizeof(server));
    listen(sd,5);
    while(1){
         nsd = accept(sd, (struct sockaddr*)&client, &clen);
            pid=fork();
            if(pid==0){
                    do{
                            memset(str,0x0,512);
                            recv(nsd,str,512,0);
                            printf("msg from client : %s\n(ip : %s & port : %u)\n",str,inet_ntoa(client.sin_addr),ntohs(client.sin_port));
                    }while(strcmp(str,"stop"));
            }
            else if(pid>0){
                    close(nsd);
            }
    }
}