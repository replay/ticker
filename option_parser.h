#ifndef OPTION_PARSER_H_
#define OPTION_PARSER_H_

#include <iostream>
#include <string>
#include <boost/program_options/options_description.hpp>
#include <boost/program_options.hpp>

using namespace std;

namespace po = boost::program_options;

class OptionParser {
	private:
		int _argc;
		char** _argv;
		po::variables_map _vm;
	public:
		OptionParser(int, char**);
		vector<string> data_providers();
};

#endif // OPTION_PARSER_H_
