#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <unistd.h>

#define SOP 0x7E
#define EOP 0x7E
#define ESCAPE 0x7D

int main()
{

    int server;
    int client;
    int portNum = 1500;
    bool isExit = false;
    int bufsize = 1024;
    char buffer[bufsize];

    struct sockaddr_in server_addr;
    socklen_t size;

    server = socket(AF_INET, SOCK_STREAM, 0);
    printf("SERVER\n");

    if (server < 0)
    {
        printf("Error establishing socket...\n");
        exit(1);
    }

    printf("=> Socket server has been created...\n");

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htons(INADDR_ANY);
    server_addr.sin_port = htons(portNum);

    if ((bind(server, (struct sockaddr *)&server_addr, sizeof(server_addr))) < 0)
    {
        printf("=> Error binding connection, the socket has already been established...\n");
        return -1;
    }

    size = sizeof(server_addr);
    printf("=> Looking for clients...\n");

    listen(server, 1);

    int clientCount = 1;
    client = accept(server, (struct sockaddr *)&server_addr, &size);

    if (client < 0)
        printf("=> Error on accepting...");

    while (client > 0)
    {
        printf("=> Connected with the client %d, you are good to go...\n", clientCount);
        printf("\n=> Enter # to end the connection\n");
        strcpy(buffer, "=> Server connected...\n");
        send(client, buffer, bufsize, 0);

        printf("Client: ");
        do
        {
            recv(client, buffer, bufsize, 0);
            // Декодирование байт-стаффинга
            char decoded_buffer[bufsize];
            int j = 0;
            if (buffer[0] != SOP)
            {
                printf("/nError SOP\n");
            }

            for (int i = 1; i < bufsize; i++)
            {
                if (buffer[i] == EOP)
                    break;

                if (buffer[i] == ESCAPE)
                    decoded_buffer[j++] = buffer[++i] ^ 0x20;
                else
                    decoded_buffer[j++] = buffer[i];
                if (i == bufsize - 1)
                    printf("\nError EOP\n");
            }
            printf("%s ", decoded_buffer);
            decoded_buffer[j] = '\0';
            memset(decoded_buffer, 0, bufsize);

        } while (1);

        printf("\n\n=> Connection terminated with IP %s\n", inet_ntoa(server_addr.sin_addr));
        close(client);
        close(server);
        printf("\nGoodbye...");
        isExit = false;
        //~ exit(1);
        return 0;
    }
    return 0;
}