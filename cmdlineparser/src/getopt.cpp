#include <iostream>
#include <getopt.h>


int main(int argc, char *argv[]) {
    int c;
    const char * short_opt = "a::b:c:h";
    struct option long_opt[] = {
        {"apple", no_argument, NULL, 'a'},
        {"ball", required_argument, NULL, 'b'},
        {"cat", required_argument, NULL, 'c'},
        {"help", no_argument, NULL, 'h'},
        {0, 0, 0, 0}
    };
    while((c=getopt_long(argc, argv, short_opt, long_opt, NULL)) != -1 ) {
        switch(c) {
            case -1:
            case 0: {
                break;
            }
            case 'a': {
                std::cout<<"Apple found"<<std::endl;
                break;
            }
            case 'b': {
                std::cout<<"Ball found"<<std::endl;
                std::cout<<"Optional Args:" <<optarg<<std::endl;
                break;
            }
            case 'c' : {
                std::cout<<"Cat found"<<std::endl;
                std::cout<<"Optional Args:" <<optarg<<std::endl;
                break;
            }
            case 'h' : {
                std::cout<<"-a apple"<<std::endl;
                std::cout<<"-b ball"<<std::endl;
                std::cout<<"-c cat"<<std::endl;
                break;
            }
            case ':': 
            case '?': {
                std::cout<<"Try %s --help for more information"<<std::endl;
                return -2;
            }
            default: {
                std::cout<<"Invalid option: "<<argv[0] << " "<<c<<std::endl;
                return -2;
            }
        }
    }

    return 0;
}