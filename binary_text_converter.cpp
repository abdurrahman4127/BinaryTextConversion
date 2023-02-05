#include <bits/stdc++.h>
using namespace std;

// to split the binary string and storing it in a vector
vector<string> split_bins(string &bin_str) {
    vector<string> v;
    string word = "";

    for(auto &i: bin_str) {
        if(i != ' ') {
            word += i;    // add chars to word (append)
        } 
        else if(i == ' ') {
            v.push_back(word);
            word = "";    // reset 'word' so that next fresh word can be stored   
        }
    }

    v.push_back(word);
    return v;
}

int main() {
    cout << "enter a binary string: ";

    string binary_string;
    getline(cin, binary_string);

    vector<string> binary;
    binary = split_bins(binary_string);   // split the input string

    // store the output in an answer vector
    vector<char> answer;

    for(auto &bins: binary) {
        int decimal = 0, power = 0;
        
        // binary to decimal conversion
        for(int i=bins.size()-1; i>=0; i--) {
            if(bins[i] == '1')
                decimal += pow(2, power);
            
            power++;
        }

        // typecast decimal to ascii charecter        
        char ascii = (char) decimal;
        answer.push_back(ascii);
        // answer.push_back((char) decimal);  // alternative
    }

    // print the output 
    for(auto &i: answer){
        cout << i;
    }
    cout << endl;

    return 0;
}