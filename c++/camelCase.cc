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

int main() {
    string s;
    cout << "Dame tu string: ";
    getline(cin, s);
    cout << camelCase(s) << endl;
    return 0;
}
