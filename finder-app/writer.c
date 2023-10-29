#include <syslog.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main(int argc, char* argv[]) {
    if(argc < 3) {
        syslog(LOG_ERR, "Invalid number of arguments! Please provide: filename and string");
        return 1;
    }
    else if(argc > 4){
        syslog(LOG_WARNING, "Invalid number of arguments! Provide only filename and string. Ignoring all other arguments");
    }
    
    int fd = open(argv[1], O_RDWR|O_CREAT, 0666);
    if(fd == -1) {
        syslog(LOG_ERR, "Could not open file: %s", argv[1]);
        return 1;
    }

    syslog(LOG_DEBUG, "Writing %s to %s", argv[2], argv[1]);

    write(fd, argv[2], strlen(argv[2]));
    close(fd);

    return 0;
}