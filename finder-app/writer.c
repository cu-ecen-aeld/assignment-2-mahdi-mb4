#include <stdio.h>
#include <syslog.h>
#include <errno.h>
#include <string.h>

int main(int argc, char* argv[]) {
    if (argc < 3) {
        openlog(NULL, 0, LOG_USER);
        syslog(LOG_USER, "Invalid Number of arguments: %d\n", argc);
        printf("Invalid Number of arguments: %d\n", argc);
        return 1;
    }

    const char* writefile = argv[1];
    const char* writestr = argv[2];
    FILE* file = fopen(writefile, "w");
    if (file == NULL) {
        openlog(NULL, 0, LOG_USER);
        syslog(LOG_USER, "The file %s could not be created\n", writefile);
        printf("The file %s could not be created\n", writefile);
        return 1;
    }

    fwrite(writestr, 1, strlen(writestr), file);
    openlog(NULL, 0, LOG_DEBUG);
    syslog(LOG_DEBUG, "Writing %s to %s\n", writestr, writefile);
    printf("Writing %s to %s\n", writestr, writefile);
    fclose(file);
    if (errno != 0) {
        openlog(NULL, 0, LOG_ERR);
        syslog(LOG_ERR, "%s\n", strerror(errno));
        printf("%s\n", strerror(errno));
        return 1;
    }

    return 0;
}

