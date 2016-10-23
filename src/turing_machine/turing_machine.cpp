#include "turing_machine.hpp"

using namespace std;

TuringMachine::TuringMachine(vector<string> states, string input_alphabet, 
        vector<vector<transition>> state_transition_matrix,
              string start_state, vector<string> accept_states, string tape,
              string blank_symbols = "_", 
              int head_pos = 0) :
    states(states),
    input_alphabet(input_alphabet),
    state_transition_matrix(state_transition_matrix),
    accept_states(accept_states),
    tape(tape),
    blank_symbols(blank_symbols),
    head_pos(head_pos){

        set_cur_state(start_state);

}

TuringMachine::TuringMachine(ifstream stream){

    string holder;

    getline(stream, input_alphabet);
    getline(stream, blank_symbols);

    getline(stream, holder);
    states = utils::split_string(holder, ' ');

    getline(stream,holder);

    getline(stream, holder);
    accept_states = utils::split_string(holder, ' ');

    getline(stream, tape);

    vector<vector<transition>> transition_matrix_temp(input_alphabet.size() + 
                                                      blank_symbols.size(),
                                                      vector<transition>(
                                                          states.size(), 
                                                          transition(0,0,0)));
    while(getline(stream, holder)){

       vector<string> tokens = utils::split_string(holder, ' ');
       
       //Convert tokens to entries in state transition matrix
       string alphabet = get_alphabet();

       int state_index =  find(states.begin(), states.end(), tokens[0]) - states.begin();
       int symbol_index = alphabet.find(tokens[1]);

       int new_state_index =  find(states.begin(), states.end(), tokens[3]) - states.begin();
       int new_symbol_index = alphabet.find(tokens[4]); 
       int head_mov = 0;

       switch(tokens[5][0]){
           case HEAD_LEFT_MOV_SYM: head_mov = HEAD_LEFT_MOV; break;
           case HEAD_RIGHT_MOV_SYM: head_mov = HEAD_RIGHT_MOV; break;
           default: head_mov = HEAD_NO_MOV;
       }

       transition trans = make_tuple(new_state_index,new_symbol_index,head_mov);

       transition_matrix_temp[state_index][symbol_index] = trans;

    }

    state_transition_matrix = transition_matrix_temp;

    auto trans = state_transition_matrix[0][0];
}

TuringMachine::TuringMachine(string filename):
    TuringMachine(ifstream(filename)){}

TuringMachine::~TuringMachine(){
}

string TuringMachine::get_cur_state(){ return states[cur_state_index]; }

void TuringMachine::set_cur_state(string c){

    //int index = utils::get_index(states,c);
    int index =  find(states.begin(), states.end(), c) - states.begin();
    cur_state_index = index;

}

string TuringMachine::get_alphabet(){
    return input_alphabet + blank_symbols;
}

string TuringMachine::str(){
    return get_alphabet();
}
