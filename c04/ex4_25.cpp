#include <iostream>

using namespace std;
int main() {
    
    char q = 113; // 01110001
        
    cout << (~q) << endl;
    
    auto not_q = (~q);
    
    cout << (not_q << 6) << endl;

    return 0;
}