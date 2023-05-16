#include "std_lib_facilities.h"

bool check_name(string name, vector<string> names) {
    for (string n : names) {
        if (name == n) return true;
    }
    return false;
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
    cout << "Pairs entered:\n";
    for (auto i = 0; i < names.size(); ++i)
        cout << '(' << names[i] << ',' << scores[i] << ")\n";
}
