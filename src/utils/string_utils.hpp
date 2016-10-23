#include <sstream>
#include <string>
#include <vector>

namespace utils{

    //Split a string into a vector
    void split_string(std::string s, char delimeter, std::vector<std::string> &container);
    std::vector<std::string> split_string(std::string s, char delimeter);

};
