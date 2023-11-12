//check and find the tokens line by line

#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <algorithm>

using namespace std;

bool isdigit(char c) {
    return (c >= '0' && c <= '9');
}

bool isNumeric(const string& str) {
    for (int i = 0; i < str.length(); i++) {
        char c = str[i];
        if (!isdigit(c) && c != '.') {
            return false;
        }
    }
    return true;
}

bool isValidIdentifier(const string& str) {
    if (str.empty()) {
        return false;
    }

    char firstChar = str[0];
    if (!(isalpha(firstChar) || firstChar == '_')) {
        return false;
    }

    if (str.size() == 1 && (str[0] == '+' || str[0] == '-' || str[0] == '*' || str[0] == '/' || str[0] == '%' || str[0] == '$')) {
        return false;
    }
    for (int i = 0; i < str.length(); i++) {
        char c = str[i];
        if (!(isalnum(c) || c == '_')) {
            return false;
        }
    }

    return true;
}

bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '%';
}

int main() {
    ifstream inputFile("expression.txt");
    if (!inputFile) {
        cout << "Error: Cannot open input file." << endl;
        return 1;
    }
    string line;
 const string commonKeywords[] = {"if", "else", "while", "for", "int", "float", "double", "return", "break", "continue", "cin", "cout"};
    while (getline(inputFile, line)) {
        cout << "Original Line: " << line << endl;

        string currentWord;
        bool insideWord = false;

        for (int i = 0; i < line.length(); i++) {
            char c = line[i];
            if (isalnum(c) || c == '_' || c == '!') {
                currentWord += c;
                insideWord = true;
            } else if (isOperator(c)) {
                if (insideWord) {
                    if (isNumeric(currentWord) && !isValidIdentifier(currentWord)) {
                        cout << "Constant: " << currentWord << endl;
                    } else if (isValidIdentifier(currentWord)) {
                        cout << "Valid Identifier: " << currentWord << endl;
                    } else {
                        cout << "Invalid Identifier: " << currentWord << endl;
                    }
                    currentWord.clear();
                    insideWord = false;
                }
                cout << "Operator: " << c << endl;
            } else if (ispunct(c)) {
                if (insideWord) {
                    if (isNumeric(currentWord) && !isValidIdentifier(currentWord)) {
                        cout << "Constant: " << currentWord << endl;
                    } else if (isValidIdentifier(currentWord)) {
                        if (find(begin(commonKeywords), end(commonKeywords), currentWord) != end(commonKeywords)) {
                            cout << "Keyword: " << currentWord << endl;
                        } else {
                            cout << "Valid Identifier: " << currentWord << endl;
                        }
                    } else {
                        cout << "Invalid Identifier: " << currentWord << endl;
                    }
                    currentWord.clear();
                    insideWord = false;
                }
                cout << "Punctuation: " << c << endl;
            } else {
                if (insideWord) {
                    if (isNumeric(currentWord) && !isValidIdentifier(currentWord)) {
                        cout << "Constant: " << currentWord << endl;
                    } else if (isValidIdentifier(currentWord)) {
                        if (find(begin(commonKeywords), end(commonKeywords), currentWord) != end(commonKeywords)) {
                            cout << "Keyword: " << currentWord << endl;
                        } else {
                            cout << "Valid Identifier: " << currentWord << endl;
                        }
                    } else {
                        cout << "Invalid Identifier: " << currentWord << endl;
                    }
                    currentWord.clear();
                }
                insideWord = false;
            }
        }

        if (insideWord) {
            if (isNumeric(currentWord) && !isValidIdentifier(currentWord)) {
                cout << "Constant: " << currentWord << endl;
            } else if (isValidIdentifier(currentWord)) {
                if (find(begin(commonKeywords), end(commonKeywords), currentWord) != end(commonKeywords)) {
                    cout << "Keyword: " << currentWord << endl;
                } else {
                    cout << "Valid Identifier: " << currentWord << endl;
                }
            } else {
                cout << "Invalid Identifier: " << currentWord << endl;
            }
        }

        cout << endl;
        }

    inputFile.close();
    return 0;
}
