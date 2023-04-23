#include <iostream>
#include <cctype>
using namespace std;

string camelCase(const string s) {
    string resul = "";
    if (!s.empty()) {
        resul += toupper(s[0]);
        for (int i = 1; i < s.size(); i++) {
            if (isspace(s[i])) {
                resul += toupper(s[i+1]);
                i++;
            }
            else if (isupper(s[i])) {
                resul += tolower(s[i]);
            }
            else if (islower(s[i])) {
                resul += s[i];
            }
            else if (isalnum(s[i])) {
                resul += s[i];
            }
        }
    }
    return resul;
}

int main(int argc, char* argv[]) {
    string s;
    for (int i = 1; i < argc; i++) {
        s += argv[i];
        s += " ";
    }
    cout << camelCase(s) << endl;
    return 0;
}
