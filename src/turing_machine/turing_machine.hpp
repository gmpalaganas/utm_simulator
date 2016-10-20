#include <algorithm>
#include <fstream>
#include <string>
#include <vector>

#include "string_utils.hpp"

class TuringMachine{
    public:

        std::string str();

        std::string input_alphabet;
        std::string tape;

        stdL::string blank_symbols;

        std::vector<std::string> states;
        std::vector<std::string> accept_states;

        std::vector<std::vector<int>> state_transition_matrix;
        
        int head_pos;
        int cur_state_index;

        TuringMachine(std::vector<std::string> states, std::string input_alphabet,
                      std::vector<std::vector<int>> state_transition_matrix,
                      std::string start_state, std::vector<std::string> accept_states,
                      std::string tape, std::string blank_symbols,
                      int head_pos);
        //Load from file
        TuringMachine(std::ifstream stream);
        TuringMachine(std::string filename);
        ~TuringMachine();

        std::string cur_state();
        void set_cur_state(std::string s);

        void str();
};
