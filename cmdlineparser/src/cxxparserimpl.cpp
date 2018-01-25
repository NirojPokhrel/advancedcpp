#include <cxxopts.hpp>
#include <iostream>

int main(int argc, char** argv) {
    cxxopts::Options options(argv[0], " - start using command line arguments with cxxopts");
    options
      .positional_help("[optional args]")
      .show_positional_help();
    bool apple = false;
    std::string ball { "Niroj" };
    int cat { 10 };
    options.add_options()
      ("a, apple", "an apple", cxxopts::value<bool>(apple))
      ("b, ball", "a ball", cxxopts::value<std::string>(ball))
      ("c, cat", "cat type", cxxopts::value<int>(cat))
      ("h, help", "Print help")
      ;
      
    options.parse_positional({"input", "output", "positional"});
      
    auto result = options.parse(argc, argv);

    if(result.count("help")  && result["help"].as<bool>()) {
        std::cout<<result["help"].as<bool>()<<std::endl;
        std::cout << options.help({"", "Group"}) << "-->" <<result.count("help")<< std::endl;
        exit(0);
    }
    if(result.count("a") && result["a"].as<bool>() ) {
        std::cout<<"Apple is caled." <<std::endl;
    }
    if(result.count("b") ) {
        std::cout<<"Ball value : "<< result["b"].as<std::string>() <<std::endl;
    }

    if(result.count("c")) {
        std::cout<<"Cat value : "<<result["c"].as<int>() <<std::endl;
    }

    return 0;
}