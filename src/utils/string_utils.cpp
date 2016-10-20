#include "string_utils.hpp"

using namespace std;
using namespace utils;

void split_string(string str, char delimeter, vector<string> &container){

    stringstream stream;
    stream.str(str);
    string token;

    while(getline(stream, token, delimeter)){
        container.push_back(item);
    }
}


vector split_string(string str, char delimeter){

    vector<string> container;
    split_string(str, delimeter, container);

    return conainer;

}
