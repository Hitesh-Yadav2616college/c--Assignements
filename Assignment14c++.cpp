/*Create a class having a string pointer as an member and then store a string into it during the object creation.
 Thereafter you need to design a member function which can calculate total words present into the string.*/

 #include <iostream>
#include <string>

using namespace std;

class StringProcessor {
private:
    string* strPtr;

public:
    StringProcessor(string str) {
        strPtr = new string(str);
    }

    int getTotalWords() {
        if (strPtr == nullptr) {
            return 0;
        }

        int wordCount = 0;
        bool inWord = false;

        for (char c : *strPtr) {
            if (isspace(c)) {
                if (inWord) inWord = false;
            } else {
                if (!inWord) {
                    wordCount++;
                    inWord = true;
                }
            }
        }

        return wordCount;
    }
};

int main() {
    string inputString = "This is a sample string.";

    StringProcessor processor(inputString);

    cout << "Total words in the string: " << processor.getTotalWords() << endl;

    return 0;
}