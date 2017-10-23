// TMIPS assembler, disassembler, debugger and simulator
// dgideas@outlook.com
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <stack>
#include <sstream>
#include <cmath>
#include <ctime>
#include <cstdlib>

#include "interface.hpp"

using namespace std;

#define DEBUG
// #undef DEBUG

void errorExit(const string& _errorMsg = "")
{
	return;
}

string strToLower(const string& _raw)
{
	string res = "";
	for (const auto& letter: _raw)
	{
		res += tolower(letter);
	}
	return res;
}

string hexToBin(string _hex, const int& _length)
{
	string res = "";
	map<char, string> binTransfer = {
		{'0', "0000"}, {'1', "0001"},
		{'2', "0010"}, {'3', "0011"},
		{'4', "0100"}, {'5', "0101"},
		{'6', "0110"}, {'7', "0111"},
		{'8', "1000"}, {'9', "1001"},
		{'a', "1010"}, {'b', "1011"},
		{'c', "1100"}, {'d', "1101"},
		{'e', "1110"}, {'f', "1111"}
	};
	int bitCount = _length/4 + (_length%4 ? 1 : 0);
	int count = 0;
	if (_hex.substr(0, 2) == "0x")
	{
		_hex = _hex.substr(2);
	}
	else if (_hex.substr(0,1) == "x")
	{
		_hex = _hex.substr(1);
	}
	
	for (string::const_reverse_iterator i = _hex.crbegin();
		i != _hex.crend();
		i++)
	{
		if (count++ == bitCount)
		{
			break;
		}
		res = binTransfer[*i] + res;
	}
	return res;
}

char segToBin(const string& _seg)
{
	char ch = 0;
	int weight = _seg.size()-1;
	for (const auto& bit: _seg)
	{
		if (bit == '1')
		{
			ch += 1<<weight;
		}
		weight--;
	}
	return ch;
}

string toBin(const string& _bin)
{
	string res = "";
	bool bigEnd = false;
	char highByte = segToBin(_bin.substr(0, 8));
	char lowByte = segToBin(_bin.substr(8));
	if (bigEnd)
	{
		res += highByte;
		res += lowByte;
	}
	else
	{
		res += lowByte;
		res += highByte;
	}
	return res;
}

class TmipsConfig
{
	// TmipsConfig class used for intermpt command line arguments
	public:
		static TmipsConfig& init();
		void parseArgs(const vector<string>&);
		bool printVersion; // = false
	private:
		TmipsConfig();
};

TmipsConfig& TmipsConfig::init()
{
	static TmipsConfig instance;
	instance.printVersion = false;
	return instance;
}

void TmipsConfig::parseArgs(const vector<string>& _args)
{
	// Using autometa to parse the command line args
	enum parseMode
	{
		normal, argParseLevel1, argParseLevel2,
	};
	parseMode mode;
	for (size_t argsIndex=1; argsIndex!=_args.size(); argsIndex++)
	{
		mode = normal;
		for (const auto& letter: _args[argsIndex])
		{
			if (letter == '-')
			{
				if (mode == normal)
				{
					mode = argParseLevel1;
				}
				else if (mode == argParseLevel1)
				{
					mode = argParseLevel2;
				}
				else if (mode == argParseLevel2)
				{
					exit(0);
				}
			}
		}
	}
	return;
}

TmipsConfig::TmipsConfig()
{
	return;
}

void startupScreen()
{
	const string tmipsVersion = "0.1 alpha";
	cout<<"TMIPS "<<tmipsVersion<<" (";
	#ifdef DEBUG
		cout<<"debug";
	#else
		cout<<"default";
	#endif
	cout<<", "<<__DATE__<<", "<<__TIME__<<")"<<endl<<"[";
	#ifdef _MSC_VER
		cout<<"cl.exe "<<_MSC_VER;
	#elif __GNUC__
		cout<<"GCC "<<__GNUC__<<"."<<__GNUC_MINOR__<<
			"."<<__GNUC_PATCHLEVEL__;
	#else
		cout<<"DGideas";
	#endif
	cout<<" "<<__cplusplus<<"] "<<INTERFACE_WORD_RUN_ON<<
		" "<<int(sizeof(int*)*8)<<INTERFACE_WORD_BIT<<endl;
	cout<<INTERFACE_HINT<<endl;
}

int main(int argc, char* argv[])
{
	startupScreen();
	if (argc <= 1)
	{
		cout<<">>> ";
		int a;
		cin>>a;
		cout<<endl;
		return EXIT_FAILURE;
	}
	TmipsConfig tmipsConfig = TmipsConfig::init();
	{
		vector<string> args;
		for (size_t argCount=0; argCount!=argc; argCount++)
		{
			args.push_back(argv[argCount]);
		}
		tmipsConfig.parseArgs(args);
	}
	return EXIT_SUCCESS;
}