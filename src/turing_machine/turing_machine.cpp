#include "turing_machine.hpp"

using namespace std;
using namespace TuringMachine;

TuringMachine(vector<string> states, string input_alphabet, vector<vector<pair<int,int>>> state_transition_matrix,
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

    vector<vector<pair<int,int>>> transition_matrix_temp(input_alphabet.size() + blank_symbols.size(),
                                               vector<pair<int,int>>(states.size(), pair<int,int>(0,0)));
    while(getline(stream, holder)){

       vector tokens = utils::split_string(holder, ' ');
       
       //Convert tokens to entries in state transition matrix
       string alphabet = get_alphabet();

       int state_index = find(states.begin(), states.end(), tokens[0]);
       int symbol_index = find(alphabet.begin(), alphabet.end(), tokens[1]);

       int new_state_index = find(states.begin(), states.end(), tokens[3]);
       int new_symbol_index = find(alphabet.begin(), alphabet.end(), tokens[4]);
       pair<int,int> transition(new_state_index,new_symbol_index);
       
       transition_matrix_temp[state_index][symbol_index] = transition;

    }

    state_transition_matrix = transition_matrix_temp;

}

TuringMachine(string filename):
    TuringMachine(ifstream(filename)){}

~TuringMachine(){
}

string get_cur_state(){ return states[cur_state]; }

void set_cur_state(string c){

    int index = find(states.begin(), states.end(), c);
    cur_state_index = index;

}

string get_alphabet(){
    return input_alphabet + blank_symbols;
}
