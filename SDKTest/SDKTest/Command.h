#ifndef COMMAND_H
#define COMMAND_H
#include <iostream>
#include <vector>
#include <sstream>
using namespace std;
enum Command{
	applyIPCData,
	stopIPCData,
	controlMove,
	heartBeat,
	osdSet,
	applyIPCAudioData
};

int split(const string& str, vector<string>& ret_, string sep = ",")
{
    if (str.empty())
    {
        return 0;
    }

    string tmp;
    string::size_type pos_begin = str.find_first_not_of(sep);
    string::size_type comma_pos = 0;

    while (pos_begin != string::npos)
    {
        comma_pos = str.find(sep, pos_begin);
        if (comma_pos != string::npos)
        {
            tmp = str.substr(pos_begin, comma_pos - pos_begin);
            pos_begin = comma_pos + sep.length();
        }
        else
        {
            tmp = str.substr(pos_begin);
            pos_begin = comma_pos;
        }

        if (!tmp.empty())
        {
            ret_.push_back(tmp);
            tmp.clear();
        }
    }
    return 0;
}

string intToStr(int i)
{
	stringstream ss;
    ss<<i;
    string s=ss.str();
	return s;
}
#endif