#ifndef _BUILDMAP_H
#define _BUILDMAP_H
#include "common.h"
using namespace std;
void labelError(string str,string error,unsigned int line,int pos);
bool lineIsLabel(string& str);
void checkLabelCorrect(string& str,unsigned int lineno);
unsigned int countBytes(vector<string> filevec,unsigned int i);
#endif
