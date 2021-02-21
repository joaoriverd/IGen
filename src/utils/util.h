#ifndef ICOMPES_UTIL_H
#define ICOMPES_UTIL_H

#include <string>
#include <vector>

void replaceSubString(std::string& str, const std::string& from, const std::string& to);

template <typename T> T str2num (std::string s);

#endif //ICOMPES_UTIL_H