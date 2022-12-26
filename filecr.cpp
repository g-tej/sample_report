#include<iostream>
#include<fstream>
using namespace std;
int main()
{

   int roll;
   string name,branch;
   ofstream ofs("demofile.txt",ios::trunc);
    ofs<<"teja"<<endl;
    ofs<<23<<endl;
    ofs<<"ECE"<<endl;
    if(ofs.is_open())
        cout<<"opened"<<endl;
    ofs.close();
    ifstream infile;
    infile.open("demofile.txt");
    infile>>name>>roll>>branch;
    infile.close();
    cout<<name<<endl;
    cout<<roll<<endl;
    cout<<branch<<endl;

}
