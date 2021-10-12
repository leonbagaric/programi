#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <dos.h>
#include <windows.h>
using namespace std;

int main()
{
    int b = 0;
    cout << "----" << endl;
    cout << "|   |---|" << endl;
    cout << "O        O" << endl;
    cout << "------------------------" << endl;
    cout << "--  --  --  --  --  --  " << endl;
    cout << "------------------------" << endl;
    pocetak:
    Sleep(1);
    system("CLS");
    b++;
            if(b%4==0){
    cout << "----" << endl;
    cout << "|   |---|" << endl;
    cout << "O        O" << endl;
                cout << "------------------------" << endl;
                cout << "--  --  --  --  --  --  " << endl;
                cout << "------------------------" << endl;
            }
            if(b%4==1){
                cout << "----" << endl;
                cout << "|   |---|" << endl;
                cout << "O        O" << endl;
                cout << "------------------------" << endl;
                cout << "-  --  --  --  --  --  -" << endl;
                cout << "------------------------" << endl;
            }
            if(b%4==2){
    cout << "----" << endl;
    cout << "|   |---|" << endl;
    cout << "O        O" << endl;
                cout << "------------------------" << endl;
                cout << "  --  --  --  --  --  --" << endl;
                cout << "------------------------" << endl;
            }
            if(b%4==3){
    cout << "----" << endl;
    cout << "|   |---|" << endl;
    cout << "O        O" << endl;
                cout << "------------------------" << endl;
                cout << " --  --  --  --  --  -- " << endl;
                cout << "------------------------" << endl;
            };
        goto pocetak;
}
