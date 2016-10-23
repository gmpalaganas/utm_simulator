#include "main.hpp"

using namespace std;

int main(){
    TuringMachine tm = TuringMachine("samples/sample1.txt");     

    cout << tm.str() << endl;

    return 0;
}
