#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    int length;

    cout << "Enter password length: ";
    cin >> length;

    string chars = "abckefghijklmnopqrstuvwxyz"
                    "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
                    "0123456789"
                    "!@#$%^&*()";
    
    int charSize = chars.size();

    srand(time(0));

    string password = "";

    for(int i=0; i<length; i++) {
        int index = rand() % charSize;
        password += chars[index];
    }

    cout << "Generated Password: " << password << endl;
    
    return 0;
}