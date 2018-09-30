#include "replace.h"
string findBiggestLabel(map<string,unsigned int>&lmap)
{
	string ret;
	//maps are sorted so the end is the last thingg
	auto iter = lmap.begin();
	while(iter!=lmap.end())
	{
		if (iter->first.size()>ret.size())
			ret = iter->first;
		iter++;
	}
	return ret;
}
bool instructionHasLabel(string& str, map<string,unsigned int>& lmap)
{
	bool ret = false;
	for (auto it : lmap)
		if(str.find(it.first)!=string::npos)
			ret = true;
	return ret;
}
bool instructionHasLabel(string& str, string label)
{
	return (str.find(label)!=string::npos);
}
int getLabelNum(string& str, map<string, unsigned int>& lmap)
{
	int ret = -999;
	unsigned int matchsize = 0;
	//for every label in the map
	for (auto it : lmap)
	{
		//check if the instruction passed in contains that label
		if(str.find(it.first)!=string::npos)
		{
			//the label is the correct match if it is the largest
			//still in the map
			if (it.first.size()>matchsize)
			{
				ret = it.second;
				matchsize = it.first.size();
			}
		}
	}
	return ret;
}
//from stack overflow
string do_replace( string const & in, string const & from, string const & to )
{
  return regex_replace( in, regex(from), to );
}
void labelToNum(string& str,string from,unsigned int num)
{
	//only perform replacements on instructions that use immediate operands
	//make sure to do so only on the correct portion of the string
	string prefix;
	string postfix;
	if (str.substr(0,4)=="jmpi") 
	{
		postfix = str.substr(4,str.size());
		prefix = str.substr(0,4);
		str = prefix + do_replace(postfix,from,to_string(num));
	}
	else if (str.substr(0,4)=="byte") 
	{
		postfix = str.substr(4,str.size());
		prefix = str.substr(0,4);
		str = prefix + do_replace(postfix,from,to_string(num));
	}
	else if (str.substr(0,3)=="jci")
	{
		postfix = str.substr(3,str.size());
		prefix = str.substr(0,3);
		str = prefix + do_replace(postfix,from,to_string(num));
	}
	else if (str.substr(0,3)=="jzi")	
	{
		postfix = str.substr(3,str.size());
		prefix = str.substr(0,3);
		str = prefix + do_replace(postfix,from,to_string(num));
	}
	else if (str.substr(0,3)=="jsi")	
	{
		postfix = str.substr(3,str.size());
		prefix = str.substr(0,3);
		str = prefix + do_replace(postfix,from,to_string(num));
	}
	else if (str.substr(0,3)=="joi")	
	{
		postfix = str.substr(3,str.size());
		prefix = str.substr(0,3);
		str = prefix + do_replace(postfix,from,to_string(num));
	}
	else if (str.substr(0,3)=="jli")	
	{
		postfix = str.substr(3,str.size());
		prefix = str.substr(0,3);
		str = prefix + do_replace(postfix,from,to_string(num));
	}
	else if (str.substr(0,3)=="ldi")	
	{//ldix,immediate
		postfix = str.substr(5,str.size());
		prefix = str.substr(0,5);
		str = prefix + do_replace(postfix,from,to_string(num));
	}
	else 
	{
		str=str;
	}
	//str = do_replace(str,from,to_string(num));
}
