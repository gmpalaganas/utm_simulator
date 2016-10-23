#include "string_utils.hpp"

using namespace std;

void utils::split_string(string str, char delimeter, vector<string> &container){

    stringstream stream;
    stream.str(str);
    string token;

    while(getline(stream, token, delimeter)){
        container.push_back(token);
    }
}


vector<string> utils::split_string(string str, char delimeter){

    vector<string> container;
    utils::split_string(str, delimeter, container);

    return container;

}
