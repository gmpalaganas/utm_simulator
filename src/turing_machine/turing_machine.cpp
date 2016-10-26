#include "turing_machine.hpp"

using namespace std;

TuringMachine::TuringMachine(vector<string> states, string alphabet, 
        vector<vector<transition>> state_transition_matrix,
              string start_state, string accept_state, string reject_state,
              string tape, char blank_symbol = '_', 
              int head_pos = 0) :
    states(states),
    alphabet(alphabet),
    state_transition_matrix(state_transition_matrix),
    start_state(start_state),
    accept_state(accept_state),
    reject_state(reject_state),
    tape(tape),
    blank_symbol(blank_symbol),
    head_pos(head_pos){

        set_cur_state(start_state);

}

TuringMachine::TuringMachine(ifstream stream){

    string holder;

    getline(stream, alphabet);
    getline(stream, holder);

    blank_symbol = holder[0];

    getline(stream, holder);
    states = utils::split_string(holder, ' ');

    getline(stream,start_state);
    set_cur_state(start_state);

    getline(stream, accept_state);
    getline(stream, reject_state);

    getline(stream, tape);

    vector<vector<transition>> transition_matrix_temp(states.size(),
                                                      vector<transition>(
                                                          alphabet.size() + 1,
                                                          transition(-1,-1,-1)));

    while(getline(stream, holder)){

       vector<string> tokens = utils::split_string(holder, ' ');
       
       //Convert tokens to entries in state transition matrix
       string input_alphabet = get_input_alphabet();

       int state_index =  find(states.begin(), states.end(), tokens[0]) - states.begin();
       int symbol_index = input_alphabet.find(tokens[1]);

       int new_state_index =  find(states.begin(), states.end(), tokens[3]) - states.begin();
       int new_symbol_index = input_alphabet.find(tokens[4]); 
       int head_mov = 0;

       switch(tokens[5][0]){
           case HEAD_LEFT_MOV_SYM: head_mov = HEAD_LEFT_MOV; break;
           case HEAD_RIGHT_MOV_SYM: head_mov = HEAD_RIGHT_MOV; break;
       }

       transition trans = make_tuple(new_state_index,new_symbol_index,head_mov);

       transition_matrix_temp[state_index][symbol_index] = trans;

    }

    state_transition_matrix = transition_matrix_temp;

    head_pos = 0;

}

TuringMachine::TuringMachine(string filename):
    TuringMachine(ifstream(filename)){}

TuringMachine::~TuringMachine(){
}

string TuringMachine::get_cur_state(){ return states[cur_state_index]; }

void TuringMachine::set_cur_state(string c){

    int index =  find(states.begin(), states.end(), c) - states.begin();
    cur_state_index = index;

}

string TuringMachine::get_input_alphabet(){
    return alphabet + blank_symbol;
}

string TuringMachine::str(){
    stringstream ss;
    
    ss << "States: ";

    for(string state : states)
        ss << state << " ";

    ss << "\nAlphabet: ";

    for(char symbol : alphabet)
        ss << symbol << " ";

    ss << "\nTransition Function:\n";

    for(int i = 0; i < state_transition_matrix.size(); i++){
        if(states[i] != accept_state && states[i] != reject_state ){
            for(int j = 0; j < state_transition_matrix[i].size(); j++){
                ss << "\t" << states[i] << " " << get_input_alphabet()[j] << " = ";

                if(state_transition_matrix[i][j] == transition(-1,-1,-1)){
                    ss << reject_state;
                }else{
                    ss << states[get<0>(state_transition_matrix[i][j])] << " ";
                    ss << get_input_alphabet()[get<1>(state_transition_matrix[i][j])] << " ";

                    switch(get<2>(state_transition_matrix[i][j])){
                        case HEAD_LEFT_MOV: ss << HEAD_RIGHT_MOV_SYM; break;
                        case HEAD_RIGHT_MOV: ss << HEAD_RIGHT_MOV_SYM; break;
                    }
                }

                ss << "\n";
            }
        }
    }

    ss << "Start State: " << start_state << endl;
    ss << "Accept State: " << accept_state << endl;
    ss << "Reject State: " << reject_state << endl;
    ss << "Current Tape: " << get_tape_status();

    return ss.str(); 
}

string TuringMachine::get_tape_status(){

    string holder = tape;

    stringstream ss;
    ss << '[' << holder[head_pos] << ']';

    string head_pos_str = ss.str();

    holder.replace(head_pos,1,head_pos_str);

    
    return holder;

}

int TuringMachine::exec(){
    
    while(get_cur_state() != accept_state && get_cur_state() != reject_state){
        char cur_symbol = tape[head_pos];
        transition trans = state_transition_matrix[cur_state_index][get_input_alphabet().find(cur_symbol)];

        if(trans == transition(-1,-1,-1))
            set_cur_state(reject_state);
        else{
            set_cur_state(states[get<0>(trans)]);
            tape[head_pos] = get_input_alphabet()[get<1>(trans)]; 
            mov_head(get<2>(trans));
        }
    }

    if(get_cur_state() == accept_state)
        return 1;

    return 0;
}

void TuringMachine::mov_head(int mov){
    
    head_pos += mov;

    if(head_pos < 0){
        tape = blank_symbol + tape;
        head_pos = 0;
    }else if(head_pos == tape.size()){
        tape += blank_symbol;
    }

}
