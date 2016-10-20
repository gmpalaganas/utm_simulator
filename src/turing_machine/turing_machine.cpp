#include "turing_machine.hpp"

using namespace std;
using namespace TuringMachine;

TuringMachine(vector<string> states, string input_alphabet, vector<vector<int>> state_transition_matrix,
              string start_state, vector<string> accept_states, string tape, string blank_symbols = "_" 
              int head_pos = 0) :
    states(states),
    input_alphabet(input_alphabet),
    state_transition_matrix(state_transition_matrix),
    accept_states(accept_states),
    tape(tape),
    blank_symbols(blank_symbols),
    head_pos(head_pos){

        set_cur_state(start_state)

}

TuringMachine(ifstream stream){

    string holder;

    getline(stream, input_alphabet);

    getline(stream, holder);
    states = utils::split_string(holder, ' ');

    getline(stream,holder);
    set_cur_state(holder);

    getline(stream, holder);
    accept_states = utils::split_string(holder, ' ');

    getline(stream, tape);

    vector<vector<int>> transition_matrix_temp(input_alphabet.size() + blank_symbols.size(),
                                               vector<int>(states.size(), 0));
    while(getline(stream, holder)){

       vector tokens = utils::split_string(holder, ' ');

       //Convert tokens to entries in state transition matrix

    }

}

TuringMachine(string filename){
    ifstream stream {filename};
}

~TuringMachine(){
}

string cur_state{ return states[cur_state]; }

void set_cur_state(string c){

    int index = find(states.begin(), states.end(), c);
    cur_state_index = index;

}
