#include <iostream>
#include <fstream>
using namespace std;

int main() {
        fstream file;

        //open file sample_TP.txt in and Write mode
        file.open("sample_TP.txt",ios::out);

        if(!file){
            cout<<"Error in creating file!!!";
            return 0;
        }

        //write A to Z
        file<<"ABCDEFGHIJKLMNOPQRSTUVWXYZ";
            
        //print the position
        cout<<"Current position is: "<<file.tellp()<<endl;
        file.close();

        //Again open file in read mode
        file.open("sample_TP.txt",ios::in);
        if(!file){
            cout<<"Error in opening file!!!";
            return 0;
        }
        cout<<"After opening file position is: "<<file.tellg()<<endl;
            
        //read characters untill end of file is not found
        char ch;
        while(!file.eof()){
            cout<<"At position : "<<file.tellg();   //current position
            file>>ch;   //read character from file
            cout<<" Character \""<<ch<<"\""<<endl;
        }

        //close the file
        file.close();
        return 0;
}
