#include<stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>


/*
 * In the included file <sys/un.h> a sockaddr_un is defined as follows
 * struct sockaddr_un {
 *  short   sun_family;
 *  char    sun_path[108];
 * };
 */




//#define NAME "socket"


/*
 * This program creates a UNIX domain datagram socket, binds a name to it,
 * then reads from the socket.
 */
int main(int argc, char* argv[])
{
    int sock, length;
    struct sockaddr_un name;
    char buf[1024];


    /* Create socket from which to read. */
    sock = socket(AF_UNIX, SOCK_DGRAM, 0);
    if (sock < 0) {
        perror("opening datagram socket");
        exit(1);
    }


    /* Create name. */
    name.sun_family = AF_UNIX;
    strcpy(name.sun_path, argv[1]);


    /* Bind the UNIX domain address to the created socket */
    if (bind(sock, (struct sockaddr *) &name, sizeof(struct sockaddr_un))) {
        perror("binding name to datagram socket");
        exit(1);
    }
    printf("socket -->%s\n", argv[1]);


    /* Read from the socket */
    if (read(sock, buf, 1024) < 0)
        perror("receiving datagram packet");
    printf("-->%s\n", buf);
    close(sock);
    unlink(argv[1]);
}


