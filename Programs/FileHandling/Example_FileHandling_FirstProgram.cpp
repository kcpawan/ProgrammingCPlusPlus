#include <iostream>
#include <fstream>
using namespace std;
 
int main() {
    ofstream fout("./FilesFromFileHandling/marks.txt");         // 8.2.1 open via constructor
    if (!fout) {
        cout << "Could not open file for writing." << endl;
        return 1;
    }
    fout << "Aakriti 78" << endl;
    fout << "Bishal 85" << endl;
    fout.close();
 
    ifstream fin;
    fin.open("./FilesFromFileHandling/marks.txt", ios::in);       // 8.2.2 open via open() with a mode
    string name;
    int score;
    while (fin >> name >> score) {
        cout << name << " scored " << score << endl;
    }
    fin.close();
    return 0;
}
