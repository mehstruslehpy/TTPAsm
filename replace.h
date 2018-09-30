#ifndef _REPLACE_H
#define _REPLACE_H
#include "common.h"
using namespace std;
string findBiggestLabel(map<string,unsigned int>&lmap);
bool instructionHasLabel(string& str, map<string, unsigned int>& lmap);
bool instructionHasLabel(string& str, string label);
int getLabelNum(string& str, map<string, unsigned int>& lmap);
void labelToNum(string&,string,unsigned int num);
#endif
