#include <algorithm>
#include <fstream>
#include <iostream>
#include <tuple>
#include <string>
#include <vector>

#include <string_utils.hpp>

#define HEAD_LEFT_MOV -1
#define HEAD_NO_MOV 0
#define HEAD_RIGHT_MOV 1

#define HEAD_LEFT_MOV_SYM '<'
#define HEAD_NO_MOV_SYM '.'
#define HEAD_RIGHT_MOV_SYM '>'

typedef std::tuple<int,int,int> transition;

class TuringMachine{
    public:

        std::string input_alphabet;
        std::string tape;

        std::string blank_symbols;

        std::vector<std::string> states;
        std::vector<std::string> accept_states;

        std::vector<std::vector<transition>> state_transition_matrix;
        
        int head_pos;
        int cur_state_index;

        TuringMachine(std::vector<std::string> states, std::string input_alphabet,
                      std::vector<std::vector<transition>> state_transition_matrix,
                      std::string start_state, std::vector<std::string> accept_states,
                      std::string tape, std::string blank_symbols,
                      int head_pos);
        //Load from file
        TuringMachine(std::ifstream stream);
        TuringMachine(std::string filename);
        ~TuringMachine();

        std::string get_cur_state();
        void set_cur_state(std::string s);

        std::string get_alphabet();
        
        std::string str();
};
