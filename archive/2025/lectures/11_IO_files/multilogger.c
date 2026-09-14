#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>

void log_everywhere(FILE *loggers[], const char *text) {
    FILE *logger = loggers[0];
    for(int i = 0; 1; i++) {
        if(loggers[i] == NULL) break;
        fprintf(loggers[i], "%s\n", text);
        fflush(loggers[i]);
    }
}

int main() {
    FILE *loggers[100] = {0};
    // Åpne fil
    loggers[0] = fopen("logg.txt", "wc");
    // Legg til standard out (terminalen)
    loggers[1] = stdout;
    // Åpne nettverksforbindelse
    loggers[2] = fdopen(socket(AF_INET, SOCK_STREAM, 0), "w");
    if(loggers[2] != NULL) {
        struct sockaddr_in server = {.sin_family = AF_INET, .sin_port = htons(8000)};
        inet_pton(AF_INET, "127.0.0.1", &server.sin_addr);
        if(connect(fileno(loggers[2]), (struct sockaddr*)&server, sizeof(struct sockaddr_in)) != 0) {
            loggers[2] = NULL;
        }
    }
    


    log_everywhere(loggers, "Hello world!");
    log_everywhere(loggers, "Hello world22222!");
    for(int i = 0; 1; i++) {
        if(loggers[i] == NULL) break;
        fclose(loggers[i]);
    }
}
