#include "write.h"
#include <math.h>
string nInstr(string str,unsigned int lineno);
string hInstr(string str,unsigned int lineno);
string aInstr(string str,unsigned int lineno);
string jInstr(string str,unsigned int lineno);
string sInstr(string str,unsigned int lineno);
string cInstr(string str,unsigned int lineno);
string lInstr(string str,unsigned int lineno);
string rInstr(string str,unsigned int lineno);
string oInstr(string str,unsigned int lineno);
string iInstr(string str,unsigned int lineno);
string dInstr(string str,unsigned int lineno);
string bInstr(string str,unsigned int lineno);
string twoRegMap(string reg);
string toHex(string immediate);

string getOutStr(string& str, unsigned int lineno)
{
    string output;
    switch (str[0])
    {
    case 'n':
    {
        output = nInstr(str,lineno);
        break;
    }
    case 'h':
    {
        output = hInstr(str,lineno);
        break;
    }
    case 'a':
    {
        output = aInstr(str,lineno);
        break;
    }
    case 'j':
    {
        output = jInstr(str,lineno);
        break;
    }
    case 's':
    {
        output = sInstr(str,lineno);
        break;
    }
    case 'c':
    {
        output = cInstr(str,lineno);
        break;
    }
    case 'l':
    {
        output = lInstr(str,lineno);
        break;
    }
    case 'r':
    {
        output = rInstr(str,lineno);
        break;
    }
    case 'o':
    {
        output = oInstr(str,lineno);
        break;
    }
    case 'i':
    {
        output = iInstr(str,lineno);
        break;
    }
    case 'd':
    {
        output = dInstr(str,lineno);
        break;
    }
    case 'b':
    {
        output = bInstr(str,lineno);
        break;
    }
    default:
    {
        instrError(str,lineno);
    }
    }
    return output;
}
void instrError(string& str, unsigned int lineno)
{
    cout << "ERROR: error building output for \""
         << str
         <<"\" at line "
         << lineno
         << " of cleaned and de-labelled filevector"
         << endl;
    exit(EXIT_FAILURE);
}
string nInstr(string str,unsigned int lineno)
{
    if (str=="nop")
    {
        return "00 ";
    }
    else if (str.substr(0,3)=="not")
    {
        string lower;
        if(str[3]=='a')
            lower = "0";
        else if (str[3]=='b')
            lower = "4";
        else if (str[3]=='c')
            lower = "8";
        else if (str[3]=='d')
            lower = "c";
        else
            instrError(str,lineno);
        return "b"+lower +" ";
    }
    else
    {
        instrError(str,lineno);
    }
    return "YOU SHOULD NOT REACH THIS";
}
string hInstr(string str,unsigned int lineno)
{
    if (str=="halt")
    {
        return "01 ";
    }
    else
    {
        instrError(str,lineno);
    }
    return "YOU SHOULD NOT REACH THIS";
}
string aInstr(string str,unsigned int lineno)
{
    if (str.substr(0,3)=="add")
    {   //addx,y for whatever reason add is one of the few
		//single byte ttp instructions that does not always end in a space
        string lower = twoRegMap(str.substr(3,3));
        if (lower=="ERROR") instrError(str,lineno);
        return "8"+lower+" ";
    }
    else if (str.substr(0,3)=="and")
    {   //andx,y
        string lower = twoRegMap(str.substr(3,3));
        if (lower=="ERROR") instrError(str,lineno);
        return "c"+lower+" ";
    }
    else if (str.substr(0,4)=="addi")
    {
        cout << "ERROR: addi is not yet implemented" << endl;
        instrError(str,lineno);
    }
    else
    {
        instrError(str,lineno);
    }
    return "YOU SHOULD NOT REACH THIS";
}
string jInstr(string str,unsigned int lineno)
{
    if (str.substr(0,4)=="jmpi")
        return "40 "+toHex(str.substr(4,str.size()));
    else if (str.substr(0,3)=="jci")
        return "44 "+toHex(str.substr(3,str.size()));
    else if (str.substr(0,3)=="jzi")
        return "45 "+toHex(str.substr(3,str.size()));
    else if (str.substr(0,3)=="jsi")
        return "43 "+toHex(str.substr(3,str.size()));
    else if (str.substr(0,3)=="joi")
        return "42 "+toHex(str.substr(3,str.size()));
    else if (str.substr(0,3)=="jli")
        return "41 "+toHex(str.substr(3,str.size()));
    else if (str.substr(0,3)=="jmp")
	{
	    string reg;
        if (str[3]=='a') reg = "1";
        else if (str[3]=='b') reg = "5";
        else if (str[3]=='c') reg = "9";
        else if (str[3]=='d') reg = "d";
        else instrError(str,lineno);
        return "b"+reg+" ";
	}
    else if (str.substr(0,2)=="jc")
    {
        string reg;
        if (str[2]=='a') reg = "2";
        else if (str[2]=='b') reg = "6";
        else if (str[2]=='c') reg = "a";
        else if (str[2]=='d') reg = "e";
        else instrError(str,lineno);
        return "b"+reg+" ";
    }
    else if (str.substr(0,2)=="jz")
    {
        string reg;
        if (str[2]=='a') reg = "3";
        else if (str[2]=='b') reg = "7";
        else if (str[2]=='c') reg = "b";
        else if (str[2]=='d') reg = "f";
        else instrError(str,lineno);
        return "b"+reg+" ";
    }
    else if (str.substr(0,2)=="js")
    {
        string reg;
        if (str[2]=='a') reg = "8";
        else if (str[2]=='b') reg = "9";
        else if (str[2]=='c') reg = "a";
        else if (str[2]=='d') reg = "b";
        else instrError(str,lineno);
        return "6"+reg+" ";
    }
    else if (str.substr(0,2)=="jo")
    {
        string reg;
        if (str[2]=='a') reg = "4";
        else if (str[2]=='b') reg = "5";
        else if (str[2]=='c') reg = "6";
        else if (str[2]=='d') reg = "7";
        else instrError(str,lineno);
        return "6"+reg+" ";
    }
    else if (str.substr(0,2)=="jl")
    {
        string reg;
        if (str[2]=='a') reg = "0";
        else if (str[2]=='b') reg = "1";
        else if (str[2]=='c') reg = "2";
        else if (str[2]=='d') reg = "3";
        else instrError(str,lineno);
        return "6"+reg+" ";
    }
    else
    {
        instrError(str,lineno);
    }
    return "YOU SHOULD NOT REACH THIS";
}
string sInstr(string str,unsigned int lineno)
{
    if(str.substr(0,3)=="sub")
    {
        string lower = twoRegMap(str.substr(3,3));
        if (lower=="ERROR") instrError(str,lineno);
        return "9"+lower+" ";
    }
    else if (str.substr(0,2)=="st")
    {   //st(y),x
        string lower = " , ";
        lower[0] = str[6];
        lower[2] = str[3];
        lower = twoRegMap(lower);
        if (lower=="ERROR") instrError(str,lineno);
        return "f"+lower+" ";
    }
    else if (str.substr(0,3)=="stf")
    {
        cout << "ERROR: stf instruction is not implemented" << endl;
        instrError(str,lineno);
    }
    else
    {
        instrError(str,lineno);
    }
    return "YOU SHOULD NOT REACH THIS";
}
string cInstr(string str,unsigned int lineno)
{
    if(str.substr(0,3)=="cpr")
    {
        string lower = twoRegMap(str.substr(3,3));
        if (lower=="ERROR") instrError(str,lineno);
        return "5"+lower+" ";
    }
    else if(str.substr(0,3)=="cmp")
    {
        string lower = twoRegMap(str.substr(3,3));
        if (lower=="ERROR") instrError(str,lineno);
        return "e"+lower+" ";
    }
    else
    {
        instrError(str,lineno);
    }
    return "YOU SHOULD NOT REACH THIS";
}
string lInstr(string str,unsigned int lineno)
{
    if (str.substr(0,3)=="ldi")
    {
        string reg;
        if (str[3]=='a') reg = 'c';
        else if (str[3]=='b') reg = 'd';
        else if (str[3]=='c') reg = 'e';
        else if (str[3]=='d') reg = 'f';
        else instrError(str,lineno);
        return "6"+reg+" "+toHex(str.substr(5,str.size()));
    }
    else if (str.substr(0,2)=="ld")
    {   //ldx,(y)
        string lower = " , ";
        lower[0] = str[2];
        lower[2] = str[5];
        lower = twoRegMap(lower);
        if (lower=="ERROR") instrError(str,lineno);
        return "7"+lower+" ";
    }
    else
    {
        instrError(str,lineno);
    }
    return "YOU SHOULD NOT REACH THIS";

}
string rInstr(string str,unsigned int lineno)
{
    if (str.substr(0,3)=="rsh")
    {
        string lower = twoRegMap(str.substr(3,3));
        if (lower=="ERROR") instrError(str,lineno);
        return "a"+lower+" ";
    }
    else
    {
        instrError(str,lineno);
    }
    return "YOU SHOULD NOT REACH THIS";

}
string oInstr(string str,unsigned int lineno)
{
    if (str.substr(0,2)=="or")
    {
        string lower = twoRegMap(str.substr(2,3));
        if (lower=="ERROR") instrError(str,lineno);
        return "d"+lower+" ";
    }
    else
    {
        instrError(str,lineno);
    }
    return "YOU SHOULD NOT REACH THIS";

}
string iInstr(string str,unsigned int lineno)
{
    if (str.substr(0,3)=="inc")
    {
        string reg;
        if (str[3]=='a') reg = "0";
        else if (str[3]=='b') reg = "5";
        else if (str[3]=='c') reg = "a";
        else if (str[3]=='d') reg = "f";
        else instrError(str,lineno);
        return "d"+reg+" ";
    }
    else
    {
        instrError(str,lineno);
    }
    return "YOU SHOULD NOT REACH THIS";
}
string dInstr(string str,unsigned int lineno)
{
    if (str.substr(0,3)=="dec")
    {
        string reg;
        if (str[3]=='a') reg = "0";
        else if (str[3]=='b') reg = "5";
        else if (str[3]=='c') reg = "a";
        else if (str[3]=='d') reg = "f";
        else
        {
            instrError(str,lineno);
        }
        return "e"+reg+" ";
    }
    else
    {
        instrError(str,lineno);
    }
    return "YOU SHOULD NOT REACH THIS";
}
string bInstr(string str,unsigned int lineno)
{
    if (str.substr(0,4)=="byte")
    {
        return " "+toHex(str.substr(4,str.size()));
    }
    else
    {
        instrError(str,lineno);
    }
    return "YOU SHOULD NOT REACH THIS";
}

string twoRegMap(string reg)
{
    if (reg=="a,a") return "0";
    if (reg=="a,b") return "1";
    if (reg=="a,c") return "2";
    if (reg=="a,d") return "3";
    if (reg=="b,a") return "4";
    if (reg=="b,b") return "5";
    if (reg=="b,c") return "6";
    if (reg=="b,d") return "7";
    if (reg=="c,a") return "8";
    if (reg=="c,b") return "9";
    if (reg=="c,c") return "a";
    if (reg=="c,d") return "b";
    if (reg=="d,a") return "c";
    if (reg=="d,b") return "d";
    if (reg=="d,c") return "e";
    if (reg=="d,d") return "f";
    else
        return "ERROR";
}

string toHex(string instr)
{
    /*
    	stringstream str;
    	str << immediate;
    	string output;
    	str >> hex >> output;
    */
	//adapted from my base conversion program
	stringstream sstr;
    int value = atoi(instr.c_str());
	int digit = 0;
    int y = 0;
    for (int i = 3; i >= 0 ; --i)
    {
        y = (int)floor( value / pow(16,i));
        digit = y % 16;
        sstr << hex << digit;
    }
	string output = sstr.str().substr(2,2);
    if (output[0]=='0') output = output.substr(1,1);
	//cout << "DEBUG: "
	cout << instr
         << " converted to "
         << output
         << " in hex"
         << endl;
    return output;
}
