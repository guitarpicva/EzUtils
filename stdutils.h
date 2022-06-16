#include <string>
#include <vector>

// We all need to split a string on a delimiter!
// This could be extended to split on another std::string
// or to optionally drop the empty tokens.  Lots of choices in std::string

// This version splits on a single char and keeps all empty tokens, so:
// split on "a,b,c,,,f,g,h" with ',' as the delimiter returns a vector 
// with size of 8 with two empty strings in indexes 3 and 4.
static void split(std::string str, std::vector<std::string> &token_v, const char delim){
    size_t start = str.find_first_not_of(delim), end=start;
    while (start != std::string::npos){
        // Find next occurence of delimiter
        end = str.find(delim, start);
        // Push back the token found into vector
        // back to back tokens leave an empty string in the vector
        token_v.push_back(str.substr(start, end-start));
        // slide up one to get to the next starting point
        start = end + 1;
    }
}