#include "std_lib_facilities.h"

pair<pair<string, string>, pair<string, int>> find_minmaxmode(vector<string> strings) {
    unordered_map<string, int> hash;
    int n = strings.size();
    for (int i = 0; i < n; i++)
        hash[strings[i]]++;

    pair<string, string> minmax;
    pair<string, int> mode;
    minmax.first = strings[0]; // min
    minmax.second = strings[0]; // max
    mode.first = "";
    mode.second = 0; // most frequent
    for (auto i : hash) {
        if (mode.second < i.second) {
            mode.first = i.first;
            mode.second = i.second;
        }
        
        if (i.first < minmax.first)
            minmax.first = i.first;

        if (i.first > minmax.second)
            minmax.second = i.first;
    }

    pair<pair<string, string>, pair<string, int>> res;
    res.first = minmax;
    res.second = mode;
    return res;
}

int main()
{
    vector<string> strings;
    string s;
    cout << "Insert a series of strings:\n";
    while (cin >> s)
        strings.push_back(s);
    
    if (strings.size() == 0) {
        cout << "No data inserted\n";
        return 1;
    }

    pair<pair<string, string>, pair<string, int>> res = find_minmaxmode(strings);
    pair<string, string> minmax = res.first;
    pair<string, int> mode = res.second;

    cout << "The minimum of the sequence of strings is " << minmax.first
         << "\nThe maximum of the sequence of strings is " << minmax.second
         << "\nThe mode of the sequence of strings is " << mode.first
         << " with " << mode.second << " appearances.\n";
}
