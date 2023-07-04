#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
    int sfd, new_sfd, port_no, sock;
    char string_recv[100];

    struct sockaddr_in server, client;

    sfd = socket(AF_INET, SOCK_STREAM, 0);

    server.sin_family = AF_INET;
    server.sin_port = 2000;
    server.sin_addr.s_addr = INADDR_ANY;

    bind(sfd, (struct sockaddr *)&server, sizeof(server));
    listen(sfd, 1);

    int n = sizeof client;

    sock = accept(sfd, (struct sockaddr *)&client, &n);

    recv(sock, string_recv, 100, 0);
    printf("Received string from Client : %s\n", string_recv);
    int vowels = 0, count = 0;
    char c;
    while (string_recv[count] != '\0')
    {
        c = string_recv[count];
        if (c == 'a' || c == 'A' || c == 'e' || c == 'E' || c == 'i' || c == 'I' || c == 'o' || c == 'O' || c == 'u' || c == 'U')
        {
            vowels++;
        }
        count++;
    }

    send(sock, &vowels, sizeof(int), 0);
    printf("Total Vowles : %d\n", vowels);

    close(sock);
    close(sfd);

    return 0;
}