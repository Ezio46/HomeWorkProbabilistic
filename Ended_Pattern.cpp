#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> computePrefixFunctionSlow(const string& pattern) {
    int m = pattern.length();
    vector<int> pi(m);
    pi[0] = 0;

    for (int i = 1; i < m; i++) {
        pi[i] = 0;
        for (int j = 0; j < i; j++) {
            if (pattern.substr(0, j + 1) == pattern.substr(i - j, j + 1)) {
                pi[i] = j + 1;
            }
        }
    }

    return pi;
}


vector<int> computePrefixFunctionFast(const string& pattern) {
    int m = pattern.length();
    vector<int> pi(m);
    int j = 0;
    pi[0] = 0;

    for (int i = 1; i < m; i++) {
        while (j > 0 && pattern[j] != pattern[i]) {
            j = pi[j - 1];
        }
        if (pattern[j] == pattern[i]) {
            j++;
        }
        pi[i] = j;
    }

    return pi;
}


void KMP_Slow(const string& text, const string& pattern) {
    int n = text.length();
    int m = pattern.length();
    vector<int> pi = computePrefixFunctionSlow(pattern);
    int q = 0;

    for (int i = 0; i < n; i++) {
        while (q > 0 && pattern[q] != text[i]) {
            q = pi[q - 1];
        }
        if (pattern[q] == text[i]) {
            q++;
        }
        if (q == m) {
            cout << "Pattern occurs with shift (Slow) - " << i - m + 1 << endl;
            q = pi[q - 1];
        }
    }
}

void KMP_Fast(const string& text, const string& pattern) {
    int n = text.length();
    int m = pattern.length();
    vector<int> pi = computePrefixFunctionFast(pattern);
    int q = 0;

    for (int i = 0; i < n; i++) {
        while (q > 0 && pattern[q] != text[i]) {
            q = pi[q - 1];
        }
        if (pattern[q] == text[i]) {
            q++;
        }
        if (q == m) {
            cout << "Pattern occurs with shift (Fast) - " << i - m + 1 << endl;
            q = pi[q - 1];
        }
    }
}

int main() {
    string text = "abcdefghijklmnopqrstuvwxyz";
    string pattern = "cde";

    KMP_Slow(text, pattern);
    KMP_Fast(text, pattern);

    return 0;
}


