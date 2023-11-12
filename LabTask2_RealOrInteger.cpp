//Check if the number is real or integer by reading all the numbers from a file.

#include<iostream>
#include<cmath>
#include<fstream>
#include<sstream>
#include<string>

using namespace std;

void check(double x)
{
    double y = floor(x);
    double temp = x-y;
    if(temp==0)
    {
        cout<<x<<" is an Integer number."<<endl;
    }
    else
        {
            cout<<x<<" is a Real number."<<endl;
        }
}

int main()
{
    ifstream inputFile("numberList.txt");

    if(!inputFile.is_open())
    {
        cout<<"File doesn't exist!";
        return 1;
    }
    else
        {
            string line;
    while(getline(inputFile, line))
    {
        double i;
    stringstream ss;
    ss << line;
    ss>>i;
    check(i);
    }
        }
        inputFile.close();


}
