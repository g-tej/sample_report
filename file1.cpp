#include<iostream>
#include<fstream>
using namespace std;
int main()
{
   ofstream ofs("demofile.txt",ios::trunc);
    ofs<<"teja"<<endl;
    ofs<<23<<endl;
    ofs<<"ECE"<<endl;
    ofs.close();
}

