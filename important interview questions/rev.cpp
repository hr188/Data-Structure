#include <iostream>
using namespace std;

void reverseWord(string& s, int start, int end) {
    while (start < end) {
        swap(s[start], s[end]);
        start++;
        end--;
    }
}

string reverseWords(string s) {
    int n = s.length();
    int start = 0;
    while (start < n) {
        // find the end of the current word
        int end = start;
        while (end < n && s[end] != ' ') {
            end++;
        }
        
        // reverse the current word
        reverseWord(s, start, end - 1);
        
        // move to the next word
        start = end + 1;
    }
    
    return s;
}

int main() {
    string s = "this is my reverse";
    string reversed = reverseWords(s);
    cout << reversed;
    
    return 0;
}
