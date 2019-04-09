#define PORT 6559

#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>

struct sendmsg_t
{
    int size;
    int time; //In ms.
    int points[24];
};

void sendPoints(int* points, char elements, int time)
{
    struct sendmsg_t toSend;
    
    //Zero out toSend
    memset(&toSend, 0, 25);
    toSend.size = (int) elements;
    
    for(int x = 0; x < elements; x++)
    {
        toSend.points[x] = points[x];
    }
    
    toSend.time = time;
    
    //Actually send the stuff
    
    int sockfd;
    struct sockaddr_in servaddr;
    
    // Creating socket file descriptor 
    if ( (sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0 ) { 
        printf("socket creation failed\n"); 
        exit(EXIT_FAILURE); 
    } 
    
    memset(&servaddr, 0, sizeof(servaddr));
      
    // Filling server information 
    servaddr.sin_family = AF_INET; 
    servaddr.sin_port = htons(PORT); 
    servaddr.sin_addr.s_addr = INADDR_ANY;
    
    sendto(sockfd, &toSend, 124, 
        MSG_CONFIRM, (const struct sockaddr *) &servaddr,  sizeof(servaddr));
}
