//client4
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#define SERVER_IP "127.0.0.1"
#define SERVER_PORT 5750
#define CLIENT_IP "127.0.0.1"
#define CLIENT_PORT 5751
int main() {
    struct sockaddr_in client, server; 
    int sd;
    char str[512];

    bzero((char*)&client, sizeof(client));
    client.sin_family = AF_INET;
    client.sin_addr.s_addr = inet_addr(CLIENT_IP);
    client.sin_port = htons(CLIENT_PORT);

    bzero((char*)&server, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = inet_addr(SERVER_IP);
    server.sin_port = htons(SERVER_PORT);

    sd = socket(AF_INET, SOCK_STREAM, 0);
    bind(sd, (struct sockaddr*)&client, sizeof(client));
    connect(sd, (struct sockaddr*)&server, sizeof(server));

    do {
        printf("Enter a message: ");
        scanf("%s", str); // Note: This will only read a single word
        send(sd, str, strlen(str)+1, 0);
    } while (strcmp(str, "stop") != 0); // Corrected comparison function

    close(sd);
    return 0;
}

