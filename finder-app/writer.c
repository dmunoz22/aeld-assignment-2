#include <syslog.h>
#include <stdio.h>


int main(int argc, char *argv[]) {
    openlog(NULL,0,LOG_USER);
    if (argc != 3) {
        syslog(LOG_ERR, "Use writer <writefile> <writestr>");
        return 1;
    }
    FILE *fptr;
    fptr = fopen(argv[1], "w");

    if (fptr == NULL) {
        syslog(LOG_ERR, "%s could not be opened", argv[1]);
        return 1;
    }

    fputs(argv[2], fptr);
    fputs("\n", fptr);
    fclose(fptr);

    syslog(LOG_DEBUG, "Writing %s to %s", argv[2], argv[1]);
}
