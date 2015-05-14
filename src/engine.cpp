#include "engine.h"
#include "cofig.h"

using namespace ep;


Engine::Engine(const Config &config)
    : config_(config)
{
}

Engine::~Engine()
{
    eventloop = new EventLoop;
}

int Engine::InitNet()
{
    int ret = 0;
    // init
    ret = init_socket();

    // bind
    ret |= bind_socket();

    // listen
    ret |= listen_socket();

    // create epoll
    ret |= ApiCreate(eventloop);

    LOG(INFO)("done init network.");
    return ret;
}

int Engine::Login()
{
}


int Engine::Register() // create epoll, register event
{

}

int Engine::StartLoop()
{
}

int Engine::ShowInfo()
{

}

int Engine::DestroyResource()
{

}



// private 
int Engine::init_socket()
{
    listenfd = socket(AF_INET, SOCK_STREAM, 0);
    bzero(&serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    serv_addr.sin_port = htons(listen_port);
    fprintf(stdout, "init socket. create fd:%d\n", listenfd);
    return 0;
}

int Engine::bind_socket()
{
    int ret = bind(listenfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr));
    fprintf(stdout, "bind socket. listen fd:%d, ret:%d\n", listenfd, ret);
    return ret;
}


int Engine::listen_socket()
{
    int ret = listen(listenfd, MAX_HANDLER);
    fprintf(stdout, "listen on port:%d, fd:%d, max fd:%d, ret:%d\n", listen_port, listenfd, MAX_HANDLER, ret);
    return ret;
}


