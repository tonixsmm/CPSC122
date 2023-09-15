#include <iostream>
#include <fstream>

using namespace std;

int main(){
    // ifstream to input file
    // ofstream to output file
    // fstream to open files in more modes
        // ios::in to open file for input
        // ios::out to open file for output
        // ios::app to open file for appending
        // ios::ate to open file for appending at the end of file
        // ios::binary
    
    string line;

    // open a file for writing
    fstream file;
    file.open("words.txt", ios::out);
    file << "hello" << endl;

    // Wrote 6 bytes to words.txt
    // tellp is for putting (outfiles, write position)
    // tellg is for getting (infiles, read position)
    long position = file.tellp();
    cout << "Position: " << position << endl;

    file.close();

    file.open("words.txt", ios::in | ios::out); // both reading and writing
    while (!file.eof()){
        getline(file, line);
        if (file.good()){
            cout << "Read: " << line << endl;
        }
    }
    // Move the cursor to the beginning of the file (without closing it)
    // Overwrite the hello with good bye
    file.clear(); // clear the state of the stream (EOF bit), not the file
    file.seekp(0, ios::beg);
    // ios::beg is the beginning of the file
    // ios::cur is the current position of the cursor
    // ios::end is the end of the file
    file << "good bye" << endl;
    cout << file.tellp() << endl;
    cout << file.tellg() << endl;
    
    file.close();

    return 0;
}