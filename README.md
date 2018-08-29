program: unix domain stream socket creation. 

This program creates a socket in the UNIX domain and binds a name to it. After printing the socket's name it begins a loop. Each time through the loop it accepts a connection and prints out messages from it. When the connection breaks, or a termination message comes through, the program accepts a new connection


**********Theory************


A Unix domain socket or IPC socket (inter-process communication socket) is a data communications endpoint for exchanging data between processes executing on the same host operating system. Like named pipes, Unix domain sockets support transmission of a reliable stream of bytes (SOCK_STREAM, compare to TCP). In addition, they support ordered and reliable transmission of datagrams (SOCK_SEQPACKET, compare to SCTP), or unordered and unreliable transmission of datagrams (SOCK_DGRAM, compare to UDP). The Unix domain socket facility is a standard component of POSIX operating systems.

The API for Unix domain sockets is similar to that of an Internet socket, but rather than using an underlying network protocol, all communication occurs entirely within the operating system kernel. Unix domain sockets use the file system as their address name space. Processes reference Unix domain sockets as file system inodes, so two processes can communicate by opening the same socket.

In addition to sending data, processes may send file descriptors across a Unix domain socket connection using the sendmsg() and recvmsg() system calls. This allows the sending processes to grant the receiving process access to a file descriptor for which the receiving process otherwise does not have access.[1] This can be used to implement a rudimentary form of capability-based security.[2] For example, this allows the Clam AntiVirus scanner to run as an unprivileged daemon on Linux and BSD, yet still read any file sent to the daemon's Unix domain socket


**********How to run*********

1.Run server program first and while running pass command line argument as any file system path.

2.then open new terminal and run client program and pass command line argument same file system path.

example:
#server side
gcc unix_st-ser.c -o ser
./ser /home/vaibhav/v

#client side
gcc unix_st-cli.c -o cli
./cli /home/vaibhav/v


