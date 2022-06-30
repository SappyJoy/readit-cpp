#pragma once

#include <iomanip>
#include <sstream>
#include <string>
#include <vector>

template <typename T>
std::ostream & operator<<(std::ostream & os, const std::vector<T> & v);

/** Template function that generates a comma separated string from the contents
 * of a vector. Elements are separated by a comma and a space for readability.
 */
template <typename T>
std::string vec2csv(const std::vector<T> & vec) {
    std::string s;
    for (typename std::vector<T>::const_iterator it = vec.begin(); it != vec.end(); ++it) {

        // Simpler, but requires boost and offers minimal formatting control
        // s += boost::lexical_cast<std::string>(*it);

        // Doesn't require boost, offers more formatting control
        std::ostringstream ss;
        ss << std::fixed << std::setprecision(2);
        ss << *it;
        s += ss.str();
        s += ", ";
    }
    if (s.size() >= 2) { // clear the trailing comma, space
        s.erase(s.size() - 2);
    }
    return s;
}

template <typename T>
std::ostream & operator<<(std::ostream & os, const std::vector<T> & v) {
    os << "[";
    os << vec2csv(v);
    os << "]";
    return os;
}