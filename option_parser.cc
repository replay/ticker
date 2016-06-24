#include <option_parser.h>


OptionParser::OptionParser(int argc, char** argv)
{
	this->_argc = argc;
	this->_argv = argv;

	po::options_description desc("Allowed options");
	desc.add_options()
		("data-providers", po::value< vector<string> >()->composing(), "providers of data")
	;
	po::positional_options_description p;
	p.add("data-providers", -1);

	po::store(po::command_line_parser(argc, argv).
		  options(desc).positional(p).run(), this->_vm);
	po::notify(this->_vm);

}

vector<string> OptionParser::data_providers()
{
	vector<string> data_providers;

	if (this->_vm.count("data-providers") > 0)
		data_providers = this->_vm["data-providers"].as< vector<string> >();

	return data_providers;
}
