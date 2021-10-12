#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

void vockeigra(int novci,int ulog)
{


    srand (time(NULL));
    int broj1 = rand() % 10;
    int broj2 = rand() % 10;
    int broj3 = rand() % 10;
    cout << " _____  " << "  _____  "<< "  _____  "<< endl;
    cout << "|     |  "<< "|     |  "<<"|     |  "<< endl;
    cout << "|  " <<broj1<<"  |  "<< "|  " <<broj2<<"  |  "<< "|  " <<broj3<<"  |  "<< endl;
    cout << "|_____|  "<< "|_____|  "<< "|_____|  " << endl;
    if(broj1==broj2==broj3){
        ulog=ulog*2;
        novci=novci+ulog;
        cout << "Bravo, tvoj ulog se poduplao." << endl;
    }
    else{
            cout << "Nista" << endl;
            if(novci==0){cout << "Nemas vise novaca :( " << endl;
            //goto start;
            }

        }
}

int main()
{
    int ulog;
    int novci = 10;
    string vockenaredba;
    string start = "start";
    cout << "Vockice" << endl;
    cout << "Za jednu igru upisite start" << endl;
    cout << "Za izlaz upisite izlaz" << endl;
    cout << "Za provjeru novca upisite novac" << endl;
    cout << "Dobitak je ostvaren samo u slucaju da sva tri broja budu jednaka" << endl;
    cout << "U slucaju dobitka, ulozeni novac se poduplava" << endl;
    cout << "Novci: "<<novci << endl;
    cout << "" << endl;
    pocetakvocke:
    cout << "Upisi naredbu: " << endl;
    cin >> vockenaredba;
    if(vockenaredba=="start"){
    ulog:
    cout << "Ulog: " << endl;
    cin >> ulog;
    if(ulog>novci){
    cout << "Ponovi..." << endl;
    goto ulog;
    }
    novci = novci-ulog;
    vockeigra(novci,ulog);
    goto pocetakvocke;
    }
    else if(vockenaredba=="novac"){
        cout << "Ostalo vam je "<< novci <<" novca" << endl;
        goto pocetakvocke;
    }
    //else if(vockenaredba=="izlaz"){
    //goto start;
    else{cout << "Ne razumijem. Ponovi..." << endl;
    goto pocetakvocke;
    }
    return 0;
}
