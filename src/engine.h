// engine.h
#include "event.h"
#include "tool_epoll.h"

class Config;
const static int MAX_BUF_LEN = 1024;

class Engine
{
public:
    Engine(const Config &config);
    ~Engine();

    int InitNet();
    int Login();
    int Register(); // create epoll, register event
    int StartLoop();
    int ShowInfo();
    int DestroyResource();

private:
    int init_socket(int &listenfd);
    int bind_socket(const int &listenfd);
    int listen_socket(const int &listenfd);


private:
    // non copy
    Engine(const Engine& );
    Engine &operator=(const Engine& );

    const Config &config_;

    struct sockaddr_in serv_addr;
    int listenfd;
    short listen_port;

    EventLoop *eventloop;
};


