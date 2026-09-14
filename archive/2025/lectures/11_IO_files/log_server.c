#include <sys/socket.h>
#include <stdio.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <string.h>

int main() {
    int f = socket(AF_INET, SOCK_STREAM, 0);
    int options = 1;
    setsockopt(f, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &options, sizeof(int));
    struct sockaddr_in addr = {.sin_family = AF_INET, .sin_addr.s_addr = INADDR_ANY, .sin_port = htons(8000)};
    bind(f, (struct sockaddr*)&addr, sizeof(addr));
    listen(f, 1);
    socklen_t len = sizeof(addr);
    int conn = accept(f, (struct sockaddr*)&addr, &len);
    char buffer[1000] = {0};
    while(1) {
        ssize_t num = read(conn, buffer, 999);
        if(num > 0) {
            printf("Got data: %s\n", buffer);
            memset(buffer, 0, 1000);
        }
    }
}
