#include <map>

using namespace std;

const static int PASSPORT_LENGTH = 16;

typedef std::map<int, int> CmdCnt;

class User
{
public:
	User();
	~User();


private:
	User &operator=(const User &);
	User(const User &);


public:
	// data seg
	int id1;          // id 1
	int id2;          // id 2
	int fd;           // socket file descript
	int seq;          // seq
	int last_time;    // last active time
	int login_flag;   // is login
	int byte_in;      // byte input
	int byte_out;     // byte output
	char key[PASSPORT_LENGTH];// key
	CmdCnt cmdin_cnt; // command input count
	CmdCnt cmdout_cnt;// command output count
	
};



