#include <syslog.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

#include <stdio.h>

int main(int argc, char* argv[]) {
    if(argc < 3) {
        syslog(LOG_ERR, "Invalid number of arguments! Please provide: filename and string");
        return 1;
    }
    else if(argc > 4){
        syslog(LOG_WARNING, "Invalid number of arguments! Provide only filename and string. Ignoring all other arguments");
    }
    
    int fd = open(argv[1], O_RDWR | O_CREAT, S_IRUSR | S_IRGRP | S_IROTH);

    write(fd, argv[2], strlen(argv[2]));
    close(fd);

    return 0;
}