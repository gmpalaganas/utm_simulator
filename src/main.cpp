/*
 * A Universal Turing Machine Simulator based on
 * the formal definition of a Turing Machine.
 *
 * See Chapter 3 of Introduction to the Theory of Computation 3rd Ed by Michael J. Sipser
 */

#include "main.hpp"

using namespace std;

int main(int argc, char *argv[]){
    
    if(argc != 2){
        cout << "usage: " << argv[0] << " <filename>\n";
        return 1;
    }

    TuringMachine tm = TuringMachine(argv[1]);     

    cout << tm.str() << endl;

    string accept = tm.exec()?"ACCEPT":"REJECT";

    cout << "After Execution: " << endl;

    cout << "TM state: " << accept << endl;
    cout << "TM tape: " << tm.get_tape_status() << endl;

    return 0;
}
