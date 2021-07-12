#include <iostream>
#include <fstream>
#include <iterator>
#include <string>
#include <algorithm>
using namespace std;
 
int main() {
    ifstream file1("1.txt", ios::in);
    string first{istreambuf_iterator<char>(file1), istreambuf_iterator<char>()};
    
    ifstream file2("2.txt", ios::in);
    string second{istreambuf_iterator<char>(file2), istreambuf_iterator<char>()};
    
    ofstream output;
    output.open("output.txt", ios::out | ios::app);
    
    for (int i = 0; i < min(first.length(), second.length()); i++)
        if (first[i] != second[i])
            output << i << ": " << first[i] << " != " << second[i] << endl;
    
    int diff = first.length() - second.length();
    if (diff == 0)
        return 0;
    else if (diff < 0)
        diff = -diff;
    
    output << "length diff is " << diff << endl;
    return 0;
}
