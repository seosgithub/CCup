#include "CCNetwork.h"

static sockaddr_in addr;
static int sock;
void CCNetworkBegin() {
  //Try to create a socket
  sock = socket(AF_INET, SOCK_DGRAM, 0);
  if (sock < 0) {
    perror("CCup: Could not create socket");
    exit(EXIT_FAILURE);
  }

  //Setup addressing
  memset(&addr, 0, sizeof(sockaddr_in));
  addr.sin_family = AF_INET;
  addr.sin_addr.s_addr = inet_addr(CCUP_IP);
  addr.sin_port = htons(CCUP_PORT);
}

void CCNetSend(std::string name, unsigned char *message, int len) {
  struct {
    char name[100];
    unsigned char len;
    unsigned char message[200];
  } buffer;

  strcpy(buffer.name, name.c_str());
  memcpy(buffer.message, message, len);
  buffer.len = len;

  int res = sendto(sock, &buffer, sizeof(buffer), 0, (sockaddr *)&addr, sizeof(sockaddr_in));
  if (res < 0) {
    perror("CCup: Could not send network data");
    exit(EXIT_FAILURE);
  }
}
