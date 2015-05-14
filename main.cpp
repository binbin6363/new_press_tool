/**
 * press tool, mutilp user cmd test tool
 *
 * auth: bbwang
 * time: 2015/05/13
*/
#include <stdlib.h>
#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <fcntl.h>
#include <sys/epoll.h>
#include "log.h"
#include "utils.h"

using namespace utils;


void ShowHelp();
int CheckArgs(int argc, char *argv[]);
int LoadConfig(const char *cfg_path);


int main(int argc, char *argv[])
{
	int ret = 0;

    // 0. check argv
    if (0 != CheckArgs(argc, argv))
    {
        ShowHelp();
        return 0;
    }

    const char *cfg_path = argv[1];
    Config config;
	// 1. load config, eg: user info, ip, port, loop num, cmd
	if (0 != LoadConfig(cfg_path))
    {
        fprintf(stderr, "load config failed.");
        return 0;
    }   

	// 2. init connect, connect to server
	Engine *engine = new Engine(config);
    ret = engine->InitNet();
    if (0 != ret)
    {
        LOG(ERROR)("init network failed.");
        return 0;
    }

	// 3. make user login
    ret = engine->Login();
    if (0 != ret)
    {
        LOG(ERROR)("engine login failed.");
        return 0;
    }

	// 4. register logined user fd to epoll
    ret = engine->Register();
    if (0 != ret)
    {
        LOG(ERROR)("register event failed.");
        return 0;
    }

	// 5. start test engine, loop
	LOG(INFO)("start test engine, loop...");
    ret = engine->StartLoop();
    if (0 != ret)
    {
        LOG(ERROR)("engine start loop failed.");
        return 0;
    }

	// 6. done, show test result info
    ret = engine->ShowInfo();
    if (0 != ret)
    {
        LOG(ERROR)("engine show info failed.");
        return 0;
    }

	// 7. clean data.
    ret = engine->DestroyResource();
    if (0 != ret)
    {
        LOG(ERROR)("destroy resource failed.");
        return 0;
    }

	LOG(INFO)("done test tool!");
	return ret;
}


int CheckArgs(int argc, char *argv[])
{
    int ret = 0;
    if (argc != 2)
    {
        fprintf(stderr, "input args num is error.");
        ret = -1;
        return ret;
    }
    else if (!IsFileExist(argv[1]))
    {
        fprintf(stderr, "input config file is not exist. path:%s\n", argv[1]);
        ret = -2;
        return ret;
    }
    return ret;
}


