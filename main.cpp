#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <cstring>

int tcp_main();
int udp_main();

int main() {
    return tcp_main();
//    return udp_main();
}

int tcp_main() {
    int sock0;
    struct sockaddr_in addr;
    struct sockaddr_in client;
    int len;
    int sock;

    sock0 = socket(AF_INET, SOCK_STREAM, 0);

    addr.sin_family = AF_INET;
    addr.sin_port = htons(12345);
    addr.sin_addr.s_addr = INADDR_ANY;

    bind(sock0, (struct sockaddr *) &addr, sizeof(addr));

    listen(sock0, 5);

    while (1) {
        len = sizeof(client);
        sock = accept(sock0, (struct sockaddr *) &client, &len);
        write(sock, "HELLO", 5);

        close(sock);
    }

    close(sock0);

    return 0;
}

int udp_main() {
    int sock;
    struct sockaddr_in addr;

    char buf[2048];

    sock = socket(AF_INET, SOCK_DGRAM, 0);

    addr.sin_family = AF_INET;
    addr.sin_port = htons(12345);
    addr.sin_addr.s_addr = INADDR_ANY;

    bind(sock, (struct sockaddr *)&addr, sizeof(addr));

    memset(buf, 0, sizeof(buf));
    recv(sock, buf, sizeof(buf), 0);

    printf("%s\n", buf);

    close(sock);

    return 0;
}