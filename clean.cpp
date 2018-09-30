#include "common.h"
#include "clean.h"
#include "stdlib.h"
static bool isZeroSize(string& str) {return str.size()==0;}
void removeUselessLines(vector<string>& vec)
{
	vec.erase(remove_if(vec.begin(),vec.end(),isZeroSize), vec.end());
}

static bool isLabelLine(string& str) {return str.find(':')!=string::npos;}
void removeLabelLines(vector<string>& vec)
{
	vec.erase(remove_if(vec.begin(),vec.end(),isLabelLine), vec.end());
}

void removeUselessChars(vector<string>& vec)
{
	string curstr;
	//remove all whitespace characters
	for (unsigned int i = 0; i < vec.size(); i++)
	{
		curstr = vec[i];
		curstr.erase( remove_if( curstr.begin(), curstr.end(), ::isspace ), curstr.end() );
		vec[i] = curstr;
	}
	//remove all comments
	for (unsigned int i = 0; i < vec.size(); i++)
	{
		curstr = vec[i];
		curstr = curstr.substr(0, curstr.find("/", 0));
		vec[i] = curstr;
	}
}
