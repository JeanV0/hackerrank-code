 #include <iostream>
#include <string>
using namespace std;

/**
 * Entrada: 
 * abcd
 * ef
 * 
 * Saida:
 * Comprimento de primeira e segunda linha
 * 4 2
 * abcdef = first.append(second);
 * ebcd af = trocar first[0] = second[0] e vice versa
 *  
*/

int main() {
	
    string first;
    string second;

    getline(cin, first);
    getline(cin, second);

    cout << first.size() << " " << second.size() << endl;
    cout << first << second << endl;

    char temp = second[0];

    second[0] = first[0];
    first[0] = temp;

    cout << first << " " << second << endl;
    
  
    return 0;
}