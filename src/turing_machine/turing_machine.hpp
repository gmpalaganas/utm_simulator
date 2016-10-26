#include <algorithm>
#include <fstream>
#include <iostream>
#include <tuple>
#include <sstream>
#include <string>
#include <vector>

#include <string_utils.hpp>

#define HEAD_LEFT_MOV -1
#define HEAD_RIGHT_MOV 1

#define HEAD_LEFT_MOV_SYM '<'
#define HEAD_RIGHT_MOV_SYM '>'

typedef std::tuple<int,int,int> transition;

class TuringMachine{
    public:

        std::string alphabet;
        std::string tape;

        char blank_symbol;

        std::vector<std::string> states;
        std::string start_state;
        std::string accept_state;
        std::string reject_state;

        std::vector<std::vector<transition>> state_transition_matrix;
        
        int head_pos;
        int cur_state_index;

        TuringMachine(std::vector<std::string> states, std::string alphabet,
                      std::vector<std::vector<transition>> state_transition_matrix,
                      std::string start_state, std::string accept_state, std::string reject_state,
                      std::string tape, char blank_symbol,
                      int head_pos);
        //Load from file
        TuringMachine(std::ifstream stream);
        TuringMachine(std::string filename);
        ~TuringMachine();

        std::string get_cur_state();
        void set_cur_state(std::string s);

        std::string get_input_alphabet();
        
        std::string str();
        std::string get_tape_status();
        
        int exec();

    private:

        void mov_head(int mov);
};
