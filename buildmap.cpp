#include "buildmap.h"
void labelError(string str,string error,unsigned int line,int pos)
{
    string posstring = (pos!=-1)?to_string(pos):"";
    cout << "ERROR: "
         << error
         << " in "
         << str
         << " at line "
         << " at position "
         << posstring
         << endl;
    exit(EXIT_FAILURE);
}
bool lineIsLabel(string& str)
{
    return str.find(':') != string::npos;
}
void checkLabelCorrect(string& str,unsigned int lineno)
{
    //disallow spaces in the middle of a label
    for(unsigned int i = 0; str[i]!=':' ; i++)
        if (isspace(str[i])&&str[0]!='/')
            labelError(str,"illegal space in labelname",lineno,i);
}
static unsigned int bytesOnLine(string str)
{
    //if (str.find("addi")!=string::npos)
    //	return 2;
    if (str[str.size()-1]==':')
        return 0;
    if (str.find("jmpi")!=string::npos && str.size() > 4)
        return 2;
    else if (str.find("jci")!=string::npos && str.size() > 3)
        return 2;
    else if (str.find("jzi")!=string::npos && str.size() > 3)
        return 2;
    else if (str.find("jsi")!=string::npos && str.size() > 3)
        return 2;
    else if (str.find("joi")!=string::npos && str.size() > 3)
        return 2;
    else if (str.find("jli")!=string::npos && str.size() > 3)
        return 2;
    else if (str.find("ldi")!=string::npos && str.size() > 3)
        return 2;
    else if (str.find("jmp")!=string::npos && str.size() ==4 && str[3] != 'i')	//jmp has 3 chars for "jmp" + a reg and no i at char 4
        return 1;
    else if (str.find("jc")!=string::npos && str.size() == 3 && str[2] != 'i')
        return 1;
    else if (str.find("jz")!=string::npos && str.size() == 3 && str[2] != 'i')
        return 1;
    else if (str.find("js")!=string::npos && str.size() == 3 && str[2] != 'i')
        return 1;
    else if (str.find("jo")!=string::npos && str.size() == 3 && str[2] != 'i')
        return 1;
    else if (str.find("jl")!=string::npos && str.size() == 3 && str[2] != 'i')
        return 1;
    else if (str.find("nop")!=string::npos)
        return 1;
    else if (str.find("halt")!=string::npos)
        return 1;
    //else if (str.find("stf")!=string::npos)
    //	return 1;
    else if (str.find("cpr")!=string::npos)
        return 1;
    else if (str.find("ld")!=string::npos && str.size()==7 && str[2]!='i')//ldx,(y)
        return 1;
    else if (str.find("add")!=string::npos)
        return 1;
    else if (str.find("sub")!=string::npos)
        return 1;
    else if (str.find("rsh")!=string::npos)
        return 1;
    else if (str.find("not")!=string::npos)
        return 1;
    else if (str.find("sub")!=string::npos)
        return 1;
    else if (str.find("and")!=string::npos)
        return 1;
    else if (str.find("or")!=string::npos)
        return 1;
    else if (str.find("cmp")!=string::npos)
        return 1;
    else if (str.find("st")!=string::npos)
        return 1;
    else if (str.find("inc")!=string::npos)
        return 1;
    else if (str.find("dec")!=string::npos)
        return 1;
    else if (str.find("byte")!=string::npos)
        return 1;
    else
        return 0;
}
unsigned int countBytes(vector<string> filevec,unsigned int countto)
{
    unsigned int countbytes = 0;
    //cout << "#####################################################"<<endl;
    for (unsigned int i = 0; i < countto; i++)
    {
        //cout << "DEBUG: " << countbytes << endl;
        //int temp = bytesOnLine(filevec[i]);
        countbytes += bytesOnLine(filevec[i]);
        //cout << "\tDEBUG:index="<<i<<": string="<<filevec[i]<<": bytecount="<<countbytes<<": bytesadded="<<temp<< endl;
    }
    //cout << "#####################################################"<<endl;
    //countbytes++; //increment to one after the current count
    return countbytes;
}
