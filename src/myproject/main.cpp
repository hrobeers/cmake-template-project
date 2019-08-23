#include <cstdlib>
#include <string>
#include <iostream>
#include <boost/program_options.hpp>
namespace po = boost::program_options;

#include "../version_autogen.hpp"
#include "mylib/myfunc.hpp"


inline void showHelp(const po::options_description &cmdline_options, std::ostream &stream = std::cout)
{
    stream << cmdline_options << "\n";
}

int main(int argc, char *argv[])
{
  try
  {
    //
    // Positional options
    //
    po::positional_options_description positional_options;
    positional_options.add("input-file", -1);

    po::options_description positional_params;
    positional_params.add_options()
      ("input-file", po::value<std::string>(), "Optional input file (can also be provided through stdin)");


    //
    // Generic options
    //
    po::options_description generic_params("Generic options");
    generic_params.add_options()
      ("version,v", "Print version string")
      ("about,a", "About this application")
      ("help,h", "Print help");

    //
    // Process the actual command line arguments given by the user
    //
    po::options_description cmdline_options;
    cmdline_options.add(positional_params).add(generic_params);

    po::variables_map vm;
    po::store(po::command_line_parser(argc, argv).options(cmdline_options).positional(positional_options).run(), vm);
    po::notify(vm);

    // Process the generic options
    bool do_exit = false;
    if (vm.count("version")) {
      std::cout << MAJOR_VERSION << '.'
                << MINOR_VERSION << '.'
                << REVISION << '.'
                << BUILD_NUMBER << '\n'
                << COMMIT_HASH << '\n';
      do_exit = true;
    }
    if (vm.count("help")) {
      showHelp(cmdline_options);
      do_exit = true;
    }
    if (do_exit) exit(EXIT_SUCCESS);


    //
    // Run the application
    //

    if (true)
    {
      std::cout << "hello from " << mylib::my_name() << std::endl;
    }
    else
    {
      showHelp(cmdline_options, std::cerr);
    }

    exit(EXIT_SUCCESS);
  }
  catch (std::exception &ex)
  {
    std::cerr << ex.what() << std::endl;
    exit(EXIT_FAILURE);
  }
}
