#include "util.h"

using namespace std;

void replaceSubString(string& str, const string& from, const string& to) {
    if(from.empty()) {
        return;
    }
    size_t start_pos = 0;
    while((start_pos = str.find(from, start_pos)) != string::npos) {
        str.replace(start_pos, from.length(), to);
        start_pos += to.length(); // In case 'to' contains 'from', like replacing 'x' with 'yx'
    }
}

template <>
float str2num<float>(string s) {
    return stof(s);
}

template <>
double str2num<double>(string s) {
    return stod(s);
}

template <>
int str2num<int>(string s) {
    return stoi(s);
}