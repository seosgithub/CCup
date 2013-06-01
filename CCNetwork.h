#ifndef CC_NETWORK_H_
#define CC_NETWORK_H_

#define CCUP_PORT 3334
#define CCUP_IP "224.4.5.6"

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

//Setup UDP multicast
void CCNetworkBegin();

//Start sending UDP packets out
void CCNetSend(std::string name, unsigned char *message, int len);

#endif
