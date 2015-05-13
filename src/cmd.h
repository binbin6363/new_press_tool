// cmd.h
#include <string>
#include <map>

using namespace std;


typedef int (*pfun)(void *);
typedef map<string, pfun> NameFuncMap;


class CommandCaller
{
public:
	CommandCaller();
	~CommandCaller();

	pfun GetCmdByName(const char *cmd_str);
	void ResgitCbFunc(pfun f);
	int call();

private:
	NameFuncMap name_func_map_;
};

