#include "std_lib_facilities.h"

bool check_name(string name, vector<string> names) {
    for (string n : names) {
        if (name == n) return true;
    }
    return false;
}

int find_name(string name, vector<string> names) {
    for (auto i = 0; i < names.size(); ++i) {
        if (name == names[i]) return i;
    }
    return -1;
}

int main()
{
    vector<string> names;
    vector<int> scores;
    string name;
    int score;
    while (cin >> name >> score) {
        if (name == "NoName" && score == 0) break;
        if (check_name(name, names)) {
            cout << "Error: Name '" << name << "' is entered twice!\n";
            continue;
        }
        names.push_back(name);
        scores.push_back(score);
    }
    
    cout << "Enter a name to output the corresponding score:\n";
    while (cin >> name) {
        int idx = find_name(name, names);
        if (idx == -1) {
            cout << "name not found\n";
            continue;
        }
        cout << scores[idx] << '\n';
    }
}
