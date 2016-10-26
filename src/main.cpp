#include "main.hpp"

using namespace std;

int main(){
    TuringMachine tm = TuringMachine("samples/sample1.txt");     

    cout << tm.str() << endl;

    string accept = tm.exec()?"ACCEPT":"REJECT";

    cout << "After Execution: " << endl;

    cout << "TM state: " << accept << endl;
    cout << "TM tape: " << tm.get_tape_status() << endl;

    return 0;
}
