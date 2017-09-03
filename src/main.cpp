/*
 * This is a very ugly implementation of the simulator,
 * because I don't wanna spend too much on this part
 */

#include <iostream>
#include <thread>
using namespace std;

#include <cstring>

#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include "world.h"
#include "utils.h"

#define SERVER_PORT 12345

World *world;
thread *worldThread;

int main(int argc, char *argv[]) {
    if (argc <= 2) {
        cout << "Usage: " << argv[0] << " " 
            << "world_name.so" << " "
            << "entity_name.so..." << endl;
        exit(-1);
    }

    // Initialize world
    world = new World(argv[1]);
    for (int i = 2; i < argc; ++i)
        world->CreateEntity(argv[i]);
    
    // Create a thread for world
    worldThread = new thread([](){while(1) world->Update();});

    // Wait for monitors' connection
    // Well, I just copied the following code from the Internet
    // and made a little modification
    int serverSock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    struct sockaddr_in serverAddr;
    memset(&serverAddr, 0, sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    serverAddr.sin_port = htons(SERVER_PORT);
    bind(serverSock, (struct sockaddr*)&serverAddr, sizeof(serverAddr));
    listen(serverSock, 1);
    struct sockaddr_in monitorAddr;
    socklen_t monitorAddrSize = sizeof(monitorAddr);
    int monitorSock;
    while ((monitorSock = accept(serverSock, (struct sockaddr*)&monitorAddr, &monitorAddrSize))
        != -1) {
        char op;
        while (recv(monitorSock, &op, 1, 0) != -1) {
            switch(op) {
                case 'd': // request data
                    // send data to monitor
                    break;
                default: // do nothing
                    break;
            }
        }
        close(monitorSock);
    }

    return 0;
}
