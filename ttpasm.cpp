//standard c++ headers
#include "common.h"
using namespace std;

//headers for auxiliary functions called by the functions shown below
#include "clean.h"
#include "buildmap.h"
#include "replace.h"
#include "write.h"
void cleanAndPrepFileVec(vector<string>&);
void buildLabelToNumberMap(vector<string>& vec,map<string,unsigned int>& lmap);
void replaceLabelsWithNumbers(vector<string>& vec, map<string,unsigned int>& lmap);
void writeOpcodes(vector<string>& vec,ofstream& fout);

void convertFileToVec(ifstream& file,vector<string>& vec);
void printFileVec(vector<string>& filevec);
void printMap(map<string,unsigned int>);
void checkLabels(vector<string>& vec);
void fileVecToLower(vector<string>& vec);

int main(int argc,char* argv[])
{	
	//label map for mapping labels to actual numbers
	map<string,unsigned int> lmap;
	//a vector containing each line of code
	vector<string> filevec;
	//input and output file streams
	ifstream fin;
	ofstream fout;
	
	//open file and junk
	if (argc != 2) return 1;
	fin.open(string(argv[1]));

	//convert the file to a vector of strings for easy processing
	cout << "Converting File \""  << string(argv[1]) << "\" To Vector: " << endl;
	convertFileToVec(fin,filevec);
	fin.close();
	printFileVec(filevec);

	//prep the file vector
	cout << "Converting File Vector To Lower Case: " << endl;
	fileVecToLower(filevec);
	cout << "Checking Labels: " << endl;
	checkLabels(filevec);
	cout << "Preparing File Vector: " << endl;
	cleanAndPrepFileVec(filevec);
	//cout << endl;
	printFileVec(filevec);
	cout << "Building Label Number Map: " << endl;
	buildLabelToNumberMap(filevec,lmap); //can't count bytes nicely before the filevec is cleaned
	printMap(lmap);
	cout << "Replacing Labels With Numbers in File Vector: " << endl;
	replaceLabelsWithNumbers(filevec,lmap);
	printFileVec(filevec);
	cout << "Removing Label Lines From File Vector: " << endl;
	removeLabelLines(filevec);
	printFileVec(filevec);
		
	fout.open("output.ram");
	//write actual opcodes to the output file
	writeOpcodes(filevec,fout);
	fout.close();
	return 0;
}
void printMap(map<string,unsigned int> lmap)
{
	cout << "Printing label map: " << endl;
	for(auto iter : lmap)
	{
		cout << "\t" << iter.first << " : "<< iter.second << endl; 
	}
}
void printFileVec(vector<string>& filevec)
{
	cout << "Printing file vector: " << endl;
	for (unsigned int i = 0; i < filevec.size(); i++)
		cout << setw(5) 
			<< i  
			<< ":"
			<< filevec[i] 
			<< "\t::line-size: "
			<<filevec[i].size()<< endl;
}
void convertFileToVec(ifstream& file,vector<string>& vec)
{
	string line;
	while(getline(file,line))
	{
		vec.push_back(line);
	}
}
void fileVecToLower(vector<string>& vec)
{
	for(unsigned int i = 0; i < vec.size();i++)
	{
		for (unsigned int j = 0; j < vec[i].size(); j++)
		{
			if (isupper(vec[i][j]))
				vec[i][j] = tolower(vec[i][j]);
		}
	}
}
void cleanAndPrepFileVec(vector<string>& vec)
{
	removeUselessChars(vec);
	removeUselessLines(vec);
}
void checkLabels(vector<string>& vec)
{
	for (unsigned int i = 0; i < vec.size(); i++)
	{
		if (lineIsLabel(vec[i]))
		{
			checkLabelCorrect(vec[i],i);
		}
	}
}
void buildLabelToNumberMap(vector<string>& vec,map<string,unsigned int>& lmap)
{
	for (unsigned int i = 0; i < vec.size(); i++)
	{
		if (lineIsLabel(vec[i]))
		{
			//double checking doesn't hurt much
			checkLabelCorrect(vec[i],i);
			unsigned int bytecount = countBytes(vec,i);
			//insert the whole label string except ':'
			lmap.insert(pair<string,unsigned int>(vec[i].substr(0,vec[i].size()-1),bytecount));
		}
	}
}
//I think this is correct
void replaceLabelsWithNumbers(vector<string>& vec, map<string,unsigned int>& lmap)
{
	string curlabel;
	int mapsize = lmap.size();
	for (int i = 0; i < mapsize; i++)
	{
		//get the biggest label in the map
		curlabel = findBiggestLabel(lmap);
		cout << "replacing label " << curlabel << endl;
		//check ever line to see if it contains that label
		for (unsigned int j = 0; j < vec.size(); j++)
		{
			//if it does get the corresponding number and replace the label
			//with that number
			if (instructionHasLabel(vec[j],curlabel))
			{
				cout << "\toccurence found at line: " << j << endl;
				long int lnum = getLabelNum(vec[j],lmap);
				cout << "\tnumber to replace: " << lnum << endl;
				labelToNum(vec[j],curlabel,lnum);
			}
		}
		//the label is not needed anymore so remove it from the map
		lmap.erase(curlabel);
	}

/*//this method has issues if the labels are substrings of each other
	for (unsigned int i = 0; i < vec.size(); i++)
	{
		if (instructionHasLabel(vec[i],lmap))
		{
			long int lnum = getLabelNum(vec[i],lmap);
			string lname = "DEADBEEF";
			if (lnum != -999)
			{
				for (auto it : lmap)
					if(int(it.second) == lnum)
						lname = it.first;
			}
			else
			{
				labelError(vec[i],"failed to map label name to number",i,-1);	
			}
			
			labelToNum(vec[i],lname,lnum);
		}
	}
*/
}
void writeOpcodes(vector<string>& vec,ofstream& fout)
{
	string outstr;
	fout << "v2.0 raw" << "\r\n";
	for (unsigned int i = 0; i < vec.size(); i++)
	{
		outstr = getOutStr(vec[i],i);
		//fout << outstr << endl;
		fout << outstr << "\r\n";
	}
}
