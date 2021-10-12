#include <iostream>
#include <ctime>
#include <cstdlib>
#include <ratio>
#include <chrono>
#include <Windows.h>
#include <ctime>
#include <cmath>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <conio.h>
#include <fstream>


using namespace std;

    string a;
    string b="Nista";
    string c="odabirigre";
    string vrijeme= "vrijeme";
    string pomoc= "pomoc";
    string zbroj= "zbrajanje";
    string razl= "oduzimanje";
    string mno= "mnozenje";
    string kol= "djeljenje";
    string razgovor= "razgovor";
    string ime= "netko";
    string mood= "nikako";
    string dobro= "dobro";
    string lose= "lose";
    string kraj= "kraj";
    string igra= "igre";
    string psk= "psk";
    string dgs= "dgs";
    string pska= "pska";
    string papir="papir";
    string skare="skare";
    string kamen="kamen";
    string odabirpsk="Nezz";
    string izlaz="izlaz";
    string musketiri="musketiri";
    string da="da";
    string ne = "ne";
    string autor="autor";
    string verzije="verzije";
    string deset="deset";
    string sinus="sinus";
    string kosinus="kosinus";
    string tangens="tangens";
    string kotangens="kotangens";
    string matematika="matematika";
    string potenc="potenciranje";
    string korijen="korijen";
    string ide="ide";
    string super="super";
    string ono ="ono";
    string odl="odl";
    string kul="kul";
    string sou="sou";
    string pogodi="pogadanje";
    string dobrosam="dobro sam";
    string supersam="super sam";
    string nepitaj="ne pitaj";
    string mat;
    string dostdobro="dost dobro";
    string dostadobro="dosta dobro";
    string aono="a ono";
    string stoperica="stoperica";
    string nisam="nisam";
    string ucenje="ucenje";
    string zmija="zmija";
    string danezm="neznam";
    string kk="kk";
    string reg="log";
    string user,pass;
    string pluss="pluss";
    string army="army";
    string cheatsmusk;
    string nista="nista";
    string logoff="logoff";
    string adminn="admin";
    string ad,lg,ps;
    string registrira="registracija";
    string usernames,passwords;
    string login="login";
    string name;
    bool admin=false;
    bool userr=false;



    int randpsk;
    int loginuspjeh=0;




// Zmija
bool Kraj;
bool print;
const int width=20;
const int height=20;
int x,y,vX,vY,bodovi;
int rX[100], rY[100];
int nr;
enum eDirection{STOP=0,LEFT,RIGHT,UP,DOWN};
eDirection dir;




void Setup()
{
    Kraj = 0;
    dir = STOP;
    x = width/2;
    y = height/2;
    vX = rand() % width;
    vY = rand() % height;
    bodovi = 0;
}
void Draw()
{

    system("cls");
    for(int i = 0;i < width+2;i++)
        cout<<"#";
    cout<<endl;

    for(int i = 0;i < height; i++)
    {
        for(int j = 0;j<width; j++)
        {
            if (j==0)
                cout <<"#";
            if (i==y && j ==x)
                cout << "0";
            else if(i== vY && j ==vX)
                cout << "f";
            else
            {
                bool print = false;
                for(int k=0;k<nr;k++)
                {
                    if(rX[k]== j&&rY[k]== i)
                    {
                        cout <<"o";
                        print = true;
                    }
                }
                    if (!print)
                        cout<<" ";

            }

            if(j==width-1)
                cout<<"#";
        }
        cout <<endl;
    }

    for(int i = 0;i < width+2;i++)
        cout<<"#";
        cout <<""<<endl;
        cout <<""<<endl;
        cout << "Bodovi:"<< bodovi<<endl;
        cout <<""<<endl;
}
void Input()
{
    if (_kbhit())
    {
        switch (_getch())
        {
        case 'a':
            dir = LEFT;
            break;
        case 's':
            dir = DOWN;
            break;
        case 'd':
            dir = RIGHT;
            break;
        case 'w':
            dir = UP;
            break;
        }
    }
}
void Logic()
{
    int prevX = rX[0];
    int prevY = rY[0];
    int prev2X, prev2Y;
    rX[0]=x;
    rY[0]=y;
    for(int i=1;i<nr;i++)
    {
        prev2X = rX[i];
        prev2Y = rY[i];
        rX[i]= prevX;
        rY[i]=prevY;
        prevX = prev2X;
        prevY=prev2Y;
    }

        switch(dir)
        {
        case LEFT:
            x--;
            break;
        case RIGHT:
            x++;
            break;
        case UP:
            y--;
            break;
        case DOWN:
            y++;
            break;
        default:
            break;
        }
        if (x >= width || x<0 || y > height || y < 0)
            Kraj = 1;
        for (int i = 0;i <nr; i++)
            if(rX[i] == x && rY[i] ==y)
            Kraj = 1;
        if (x == vX && y == vY)
        {
            bodovi = bodovi + 1;

    vX = rand() % width;
    vY = rand() % height;
    nr++;
        }
}



int main(int argc, char *argv[])
{




    time_t now;
    time(&now);
    srand((unsigned int)now);



    cout << "Bot v1.21 --- By L. ---" << endl;
    cout << "Sve sto pises pisi malim slovima!" << endl;
    cout<<"########################################################################"<<endl;
	cout<<"#                                                                      #"<<endl;
	cout<<"#                                                                      #"<<endl;
	cout<<"#    ###           #########     #############     #####        ###    #"<<endl;
	cout<<"#    ###           #########     #############     ######       ###    #"<<endl;
	cout<<"#    ###           ###           ###       ###     ### ###      ###    #"<<endl;
	cout<<"#    ###           ###           ###       ###     ###  ###     ###    #"<<endl;
	cout<<"#    ###           #########     ###       ###     ###   ###    ###    #"<<endl;
	cout<<"#    ###           #########     ###       ###     ###    ###   ###    #"<<endl;
	cout<<"#    ###           ###           ###       ###     ###     ###  ###    #"<<endl;
	cout<<"#    ###           ###           ###       ###     ###      ### ###    #"<<endl;
	cout<<"#    #########     #########     #############     ###       ######    #"<<endl;
	cout<<"#    #########     #########     #############     ###        #####    #"<<endl;
	cout<<"#                                                                      #"<<endl;
	cout<<"#                                                                      #"<<endl;
	cout<<"########################################################################"<<endl;
    start:
    system("COLOR 07");
    if (admin==true){cout<<"Welcome Admin"<<endl;}
    if (userr==true){cout<<"Welcome "<<name<<endl;}
    cout << "Upisi pomoc za neke od komandi" << endl;
    cout << "Cekam" << endl;
    cin >>a;
    system("cls");




    if(a==login){
      cout<<"username:"<<endl;
      cin>>lg;
      if(lg!="leonbagaric"){
      cout<<"Nije pronaden identitet"<<endl;
      goto start;
      }
      else if(lg=="leonbagaric"){
        cout<<"Pronaden identitet"<<endl;Sleep(3000);
        goto dada;
      }

       dada:
        cout<<"password:"<<endl;
        cin>>ps;
        if (ps!="admin"){
        cout<<"Neuspjesno"<<endl;Sleep(3000);
        goto start;
       }

        else if(ps=="admin"){
        cout<<"Uspijeh"<<endl;Sleep(3000);
        system("cls");
        admin=true;
        userr=false;
        loginuspjeh=1;
        goto ovo;

      }

goto start;
}
    if(admin==true){
    if(a==adminn){
        //KAD SMISLIS STAVLJAJ
        admstart:
        cin>>ad;
        if(ad==izlaz){ goto start;}
        else{cout<<"Ne razumijem"<<endl;goto admstart;}
    }}
    if(a==logoff){
            admin=false;
            goto start;}
ovo:
    if(loginuspjeh==1){
        loginuspjeh = 0;
        system("cls");
        cout<<"V"<<endl;Sleep(300);system("cls");
        cout<<"VE"<<endl;Sleep(300);system("cls");
        cout<<"VER"<<endl;Sleep(300);system("cls");
        cout<<"VERI"<<endl;Sleep(300);system("cls");
        cout<<"VERIF"<<endl;Sleep(300);system("cls");
        cout<<"VERIFI"<<endl;Sleep(300);system("cls");
        cout<<"VERIFIE"<<endl;Sleep(300);system("cls");
        cout<<"VERIFIED"<<endl;Sleep(300);system("cls");
        cout<<""<<endl;Sleep(600);system("cls");
        cout<<"VERIFIED"<<endl;Sleep(3000);
        cout<<"Welcome Admin"<<endl;Sleep(4000);
        admin=true;
        system("cls");
        goto start;
        }
    if(a==ucenje){
            uc:
    int ucenjec;
    cout << "Za izlaz upisi 0" << endl;
    cout << "Ucenje C++" << endl;
    cout << "" << endl;
    cout << "Lekcije: " << endl;
    cout << "1.  Uvod" << endl;
    cout << "2.  Vrste podataka" << endl;
    cout << "3.  Vrste operatora" << endl;
    cout << "4.  Osnovne naredbe" << endl;
    cout << "5.  Slozenije naredbe" << endl;
    cout << "" << endl;
    cout << "Za nastavak upisi broj lekcije." << endl;
    cout << "Za zavrsetak lekcije pritisni enter" << endl;
    cout << "" << endl;
    cin >> ucenjec;
    system("cls");
    if (ucenjec==1){
        cout << "1.  Uvod" << endl;
        cout << "" << endl;
        cout << "C++ je programski jezik opce namjene i srednje razine s podrskom za objektno orijentirano programiranje." << endl;
        cout << "Jedan je od najvaznijih i najcesce koristenih programskih jezika na svijetu" << endl;
        cout << "Primjer C++ koda:                           " << endl;
        cout << "" << endl;
        cout << "#include <iostream>" << endl;
        cout << "" << endl;
        cout << "using namespace std;" << endl;
        cout << "" << endl;
        cout << "int main(){" << endl;
        cout << "     cout<<'Hello world'<<endl;" << endl;
        cout << "     Return 0;" << endl;
        cout << "}" << endl;
        cout << "" << endl;
        cout << "Svaki C++ program mora imati int main(){} koji sluzi kao glavni dio koda koji se izvrsava." << endl;
        cout << "Sav kod pise se unutar {} zagrada." << endl;

        cin.ignore();
        cin.ignore();
        system("cls");
        goto uc;
    }
    else if(ucenjec==2){

        cout << "2.  Vrste podataka" << endl;
        cout << "" << endl;
        cout << "U C++ postoje razlicite vrste podataka." << endl;
        cout << "Postoje:" << endl;
        cout << "int - Cjelobrojni tip podatka (Primjer: 12)" << endl;
        cout << "float, double - Realni tipovi podataka (Primjer: 1.234)" << endl;
        cout << "char - Znakovni tip podatka (Jedno slovo) (Primjer: H)" << endl;
        cout << "string - Znakovni tip podatka (Rijec) (Primjer: Vozilo)" << endl;
        cout << "bool - Logicki tip podatka (1 ili 0) (Primjer: 0)" << endl;
        cout << "const - Konstanta - Broj koji se ne mjenja (Primjer: Pi(3.1415926535))" << endl;
        cout << "Sve vrste podataka moraju se odrediti na pocetku koda" << endl;
        cout << "Primjer koda:                           " << endl;
        cout << "" << endl;
        cout << "#include <iostream>" << endl;
        cout << "#include <cstdlib>" << endl;
        cout << "" << endl;
        cout << "using namespace std;" << endl;
        cout << "" << endl;
        cout << "int main(){" << endl;
        cout << "     int a=6;" << endl;
        cout << "" << endl;
        cout << "     cout<< a <<endl;" << endl;
        cout << "     Return 0;" << endl;
        cout << "}" << endl;
        cout << "" << endl;

        cin.ignore();
        cin.ignore();
        system("cls");
        goto uc;

        }
    else if(ucenjec==3){

        cout << "3.  Vrste operatora"<<endl;
        cout << "" << endl;
        cout << "Osnovni operatori koji se koriste u C++ su: " << endl;
        cout << "" << endl;
        cout << "Aritmeticki operatori" << endl;
        cout << "+ : zbrajanje" << endl;
        cout << "- : oduzimanje" << endl;
        cout << "/ : djeljenje" << endl;
        cout << "* : mnozenje" << endl;
        cout << "" << endl;
        cout << "Logicki operatori" << endl;
        cout << "! : NE (Suprotnost)" << endl;
        cout << "&& : I (Oba uvjeta moraju biti ispunjena)" << endl;
        cout << "|| : ILI (Barem jedan od uvjeta mora biti ispunjen)" << endl;
        cout << "" << endl;
        cout << "Operatori usporedivanja:" << endl;
        cout << "< : manje" << endl;
        cout << "<= : manje ili jednako" << endl;
        cout << "== : jednako" << endl;
        cout << ">= : vece ili jednako" << endl;
        cout << "> : vece" << endl;
        cout << "!= : nije jednako" << endl;
        cout << "" << endl;
        cout << "I ostali operatori" << endl;

        cin.ignore();
        cin.ignore();
        system("cls");
        goto uc;
}
    else if(ucenjec==4){
        cout << "4. Osnovne naredbe" << endl;
        cout << "" << endl;
        cout << "Svaki programski jezik funkcionira pomocu naredbi" << endl;
        cout << "U C++ naredbe koje program treba ciniti nalaze se u int main(){ <naredbe> }" << endl;
        cout << "Sve naredbe zavrsavaju sa ;" << endl;
        cout << "" << endl;
        cout << "Naredbe: " << endl;
        cout << "cout<< 'Tekst' << varijabla <<endl;   : naredba za ispis teksta (pod navodnicima) i zadanih varijabli (bez navodnika) " << endl;
        cout << "cin>> varijabla;   : naredba za unos teksta, slova ili broja. Tip varijable se odreduje na pocetku (int, float, char ...)" << endl;
        cout << "" << endl;
        cout << "if(uvjet){}    : naredba koja u slucaju zadanog uvjeta izvrsava radnju zadanu u bloku naredbi ( if(uvjet){ Blok naredbi } )" << endl;
        cout << "Ako uvjet nije ispunjen, blok naredbi se preskace." << endl;
        cout << "Ako zelimo imati vise uvjeta, poslije bloka naredbi stavljamo: if else(uvjet){} ,koji u slucaju ne ispunjenog if uvjeta provjerava ovaj if else uvjet" << endl;
        cout << "Mozemo imati neogranicen broj if else naredbi" << endl;
        cout << "Ako zelimo naredbu koja se ispunjava u slucaju ne ispunjenog niti jednog if else i if bloka, upisujemo else naredbu" << endl;
        cout << "else{blok naredbi} se stavlja na kraju, te se ispunjava ako nijedan if blok uvjet nije ispunjen" << endl;
        cout << "" << endl;
        cout << "for(pocetno stanje; uvjet; prirast){ blok naredbi} se koristi da se blok ispunjava zadani broj puta." << endl;
        cout << "Primjer : for(int var=0; var < 10; var=var+1) : na pocetku varijabla je jednaka nuli. Kada se blok naredbi izvrsi varijabla ce porasti za 1. Izvrsava se dok varijabla ne bude jednaka 10." << endl;
        cout << "" << endl;
        cout << "while(uvjet){blok naredbi} se koristi da se blok ispunjava dok je uvjet ispunjen." << endl;
        cout << "while(var <= 10){ var = var + 1 }" << endl;
        cin.ignore();
        cin.ignore();
        system("cls");
        goto uc;
    }
    else if(ucenjec==0){

        cin.ignore();
        system("cls");
        goto start;
    }
    else if(ucenjec==5){
        cout << "5. Slozenije naredbe" << endl;
        cout << "" << endl;
        cout << "C++ vecinu funkcija dobiva iz biblioteka. One se upisuju na samom pocetku koda. Primjer biblioteke je <windows.h>." << endl;
        cout << "" << endl;
        cout << "Naredbe:" << endl;
        cout << "var++ :  Jednaka je kao var = var + 1;" << endl;
        cout << "var-- :  Jednaka je kao var = var - 1;" << endl;
        cout << "Naredba Sleep( milisekunde ) je naredba iz biblioteke <windows.h>. Ona odreduje kolika pauza ce biti izmedu dvije naredbe. Odreduje se u milisekundama " << endl;
        cout << "goto pocetak; nastavlja izvrsavanje koda od mjesta gdje je upisan kod:    pocetak: " << endl;
        cout << "system('cls'); naredba koja brise sve sto se trenutno nalazi u konzoli. Nalazi se u <cstdlib> biblioteci." << endl;
        cout << "var = rand() % 100; Bira nasumican broj od 0 do 99. Ako je upisano var = rand() % 100 + 1; , +1 na kraju upucuje da se pocinje od 1, pa odabire broj izmedu 1 i 100" << endl;
        cin.ignore();
        cin.ignore();
        system("cls");
        goto uc;
    }
    else{cout<<"Ne razumijem"<<endl;
        goto uc;}
    }
    if(a==stoperica){

        cin.ignore();
        cout << "Pritisni enter za pocetak";
        cin.ignore();
        system("cls");
        unsigned int start = clock();
        cout << "Pritisni enter za kraj";
        cin.ignore();
        system("cls");
        cout << "Proslo je " << (clock()-start)/1000 <<" sekundi ("<<clock()-start<<" milisekundi)"<<endl;
        cout << "Pritisni enter za zavrsetak";
        cin.ignore();
        system("cls");
        goto start;
    }
    if(a==matematika){
    cout << "Matematicke operacije:"<<endl;
    cout << "zbrajanje - Kalkulator zbrajanja"<<endl;
    cout << "oduzimanje - Kalkulator oduzimanja "<<endl;
    cout << "mnozenje - Kalkulator djeljenja"<<endl;
    cout << "djeljenje - Kalkulator mnozenja"<<endl;
    cout << "sinus - Racunanje sinusa"<<endl;
    cout << "kosinus - Racunanje kosinusa "<<endl;
    cout << "tangens -  Racunanje tangensa"<<endl;
    cout << "kotangens -  Racunanje kotangensa"<<endl;
    cout << "korijen - Korjenovanje zadanog broja"<<endl;
    cout << "potenciranje -  Racunanje s potencijama"<<endl;



    cin >> mat;

    system("cls");
    if(mat==izlaz){

    system("cls");
    goto start;
    }
    if(mat==korijen){

        float kor;
        cout << "Korjenovanje"<<endl;
        cout << "Upisi broj"<<endl;
        cin >> kor;
        cout << "Korijen zadanog broja je "<< sqrt(kor)<<endl;
        goto start;
    }
    if(mat==potenc){

    float pot,bazapot,ekspot;
    cout << "Potenciranje"<<endl;
    cout << "Upisi bazu "<<endl;
    cin >> bazapot;
    cout << "Upisi eksponent "<<endl;
    cin>>ekspot;
    cout << "Rezultat potenciranja je "<< pow(bazapot , ekspot)<<endl;
goto start;

    }
    if(mat==kotangens){
    float ctg,resctg;

    cout << "Racunanje kotangensa"<<endl;
    cout << "Upisi kut za izracunavanje kotangensa "<<endl;
    cin >> ctg;
    resctg=1/(tan(ctg*3.14159265/180));
    cout << "Kotangens broja "<<ctg<< " je "<< resctg <<endl;
    goto start;
}
    if(mat==tangens){
    float tg,rtg;

    cout << "Racunanje tangensa"<<endl;
    cout << "Upisi kut za izracunavanje tangensa "<<endl;
    cin >> tg;
    rtg=tan(tg*3.14159265/180);
    cout << "Tangens broja "<<tg<< " je "<< rtg <<endl;
    goto start;
}
    if(mat==kosinus){
    float cosinbr,rcs;

    cout << "Racunanje kosinusa"<<endl;
    cout << "Upisi kut za izracunavanje kosinusa "<<endl;
    cin >> cosinbr;
    rcs=cos(cosinbr*3.14159265/180);
    cout << "Kosinus broja "<<cosinbr<< " je "<< rcs <<endl;
    goto start;
}
    if(mat==sinus){
    float sinbr,rsn;

    cout << "Racunanje sinusa"<<endl;
    cout << "Upisi kut za izracunavanje sinusa "<<endl;
    cin >> sinbr;
    rsn=sin(sinbr*3.14159265/180);
    cout << "Sinus broja "<<sinbr<< " je "<< rsn <<endl;
    goto start;
}
    if(mat==zbroj){
        double prvizbr;
        double drugizbr;
        double trecizbr;
        cout << "Kalkulator zbrajanja" << endl;
        cout << "Upisi prvi broj: " << endl;
        cin >> prvizbr;
        cout << "Upisi drugi broj: " << endl;
        cin >> drugizbr;
        trecizbr=prvizbr+drugizbr;
        cout << "Rezultat zbrajanja je "<<trecizbr << endl;



        goto start;
    }
    if(mat==razl){
        double prviraz;
        double drugiraz;
        double treciraz;
        cout << "Kalkulator oduzimanja" << endl;
        cout << "Upisi prvi broj: " << endl;
        cin >> prviraz;
        cout << "Upisi drugi broj: " << endl;
        cin >> drugiraz;

        treciraz=prviraz-drugiraz;
        cout << "Rezultat oduzimanja je "<<treciraz << endl;



        goto start;
    }
    if(mat==kol){
        float prvi;
        float drugi;
        float treci;

        cout << "Kalkulator djeljenja" << endl;
        cout << "Upisi prvi broj: " << endl;
        cin >> prvi;
        cout << "Upisi drugi broj: " << endl;
        cin >> drugi;
        treci=prvi/drugi;
        cout << "Rezultat djeljenja je "<<treci << endl;



        goto start;
    }
    if(mat==mno){
        double prvimno;
        double drugimno;
        double trecimno;
        cout << "Kalkulator mnozenja" << endl;
        cout << "Upisi prvi broj: " << endl;
        cin >> prvimno;
        cout << "Upisi drugi broj: " << endl;
        cin >> drugimno;
        trecimno=prvimno*drugimno;
        cout << "Rezultat mnozenja je "<<prvimno*drugimno << endl;



        goto start;
    }
}
    if(a==vrijeme){
             using namespace std::chrono;

             duration<int,std::ratio<60*60*24> > one_day (1);

             system_clock::time_point today = system_clock::now();

             time_t tt;

             tt = system_clock::to_time_t ( today );
             std::cout << ctime(&tt) <<endl;

             a=b;
             goto start;
    }
    if(a==pomoc){
        cout << "matematika - Matematicke operacije"<<endl;
        cout << "vrijeme - Ispisuje trenutno vrijeme" << endl;
        cout << "stoperica - Stoperica " << endl;
        cout << "razgovor - Razgovor" << endl;
        cout << "kraj - Zavrsetak programa" << endl;
        cout << "igre - Odabir igara" << endl;
        cout << "autor - O autoru" << endl;
        cout << "verzije - Dosadasnje verzije programa " << endl;
        cout << "ucenje - Lekcije za ucenje C++ " << endl;






        a=b;
        goto start;
    }
    if(a==autor){
        cout << "O autoru " << endl;Sleep(1000);
        cout << " " << endl;
        cout << "Made by Leon Bagaric " << endl;Sleep(1000);
        cout << "March 2018. " << endl;Sleep(1000);
        cout << "Current version - v1.21" << endl;Sleep(1000);
        goto start;
    }
    if(a==verzije){
        cout << "V1.0 - >>Pocetna verzija<<." << endl;Sleep(1000);
        cout << " " << endl;
        cout << "Osnovne funkcije. " << endl;Sleep(1000);
        cout << " " << endl;
        cout << "V1.1 " << endl;Sleep(1000);
        cout << " " << endl;
        cout << "Dodano: verzije - Sve dosadasnje vezije programa. " << endl;Sleep(1000);
        cout << "Dodano: autor - Osnovno o autoru i programu. " << endl;Sleep(1000);
        cout << "Dodano: igre > musketiri - Mala igrica u obliku price u kojoj igrac kontrolira musketire. " << endl;Sleep(1000);
        cout << "Popravljene manje greske." << endl;Sleep(1000);
        cout << " " << endl;
        cout << "V1.11 " << endl;Sleep(1000);
        cout << " " << endl;
        cout << "Dodano: matematika - Matematicke funkcije " << endl;Sleep(1000);
        cout << "Dodano: Vise matematickih funkcija pod matematika"<<endl;Sleep(1000);
        cout << "Preimenovano: upoznavanje -> razgovor" << endl;Sleep(1000);
        cout << "Nadogradeno: razgovor" << endl;Sleep(1000);
        cout << "Popravljene manje greske." << endl;Sleep(1000);
        cout << " " << endl;
        cout << "V1.12" << endl;Sleep(1000);
        cout << " " << endl;
        cout << "Dodano: igre > pogadanje - Igra pogadanja slucajnog broja." << endl;Sleep(1000);
        cout << "Popravljene manje greske" << endl;Sleep(1000);
        cout << " " << endl;
        cout << "V1.2" << endl;Sleep(1000);
        cout << " " << endl;
        cout << "Razgovor > moguc odgovor sa vise od jedne rijeci" << endl;Sleep(1000);
        cout << "Nadogradeno: razgovor" << endl;Sleep(1000);
        cout << "Dodano: stoperica - Stoperica" << endl;Sleep(1000);
        cout << "Dodano: ucenje - Lekcije za ucenje C++" << endl;Sleep(1000);
        cout << "Dodano: igre - zmija - Igra u kojoj zmija mora pojesti sto vise voca." << endl;Sleep(1000);
        cout << "Dodano: Razlicita boja teksta za svaku igru" << endl;
        cout << "Popravljene manje greske" << endl;Sleep(1000);
        cout << "V1.21" << endl;Sleep(1000);
        cout << " " << endl;
        cout << "Dodano: igre - kk - Krizic Kruzic u dvoje" << endl;Sleep(1000);

        cout << " " << endl;
        cout << "Trenutna verzija:  V1.21" << endl;Sleep(1000);
        goto start;
    }
    if(a==razgovor){




        char kaksi[30];
        cout << "Kako se zoves? "<< endl;
        cin>> ime;
        cout << "Bok "<<ime<<"!"<<endl;
        cout << "Kako si? "<<endl;
        cin.ignore();
        cin.getline(kaksi,30);
        if(kaksi == dobro){
            cout << "Super, i ja! "<<endl;
        }

        else if(kaksi == lose){
            cout << "Ajoj. "<<endl;
        }

        else if(kaksi == ide){
                cout << "I kod mene. "<<endl;
        }

        else if(kaksi == super){
                cout << "I ja. "<<endl;
        }

        else if(kaksi == ono){
                cout << "Bit ce bolje, aj... "<<endl;
        }

        else if(kaksi == odl){
                cout << "Odl onda. "<<endl;
        }

        else if(kaksi == kul){
                cout << "Kul kul. "<<endl;
        }


        else if(kaksi == dobrosam){
            cout << "Odlicno, i ja sam dobro. "<<endl;
        }

        else if(kaksi == aono){
            cout << "Ma dobro ce bit. "<<endl;
        }

        else if(kaksi == supersam){
            cout << "Evo i ja sam. "<<endl;
        }

        else if(kaksi == nepitaj){
            cout << "Ma znam. "<<endl;
        }

        else if(kaksi == dostdobro || kaksi == dostadobro){
            cout << "Dost dobro. "<<endl;
        }

        else if(kaksi == nisam){
            cout << "Nisam ni ja. "<<endl;
        }
        else if(kaksi == sou){
            cout << "Skrr." << endl;
        }
        else if(kaksi == izlaz){
                system("CLS");
            goto start;
        }




        else {
            cout << "Ja sam dobro. "<<endl;
        }


        goto start;
    }
    if(a==kraj){
    return 0;
    }
    if(a==igra){
        igragoto:
        cout << "Odaberi igru: "<<endl;
        cout << "psk - Papir, skare, kamen  "<<endl;
        cout << "dgs - Drzava, grad, selo  "<<endl;
        cout << "musketiri - Mala igrica u obliku price u kojoj igrac kontrolira musketire.  "<<endl;
        cout << "pogadanje - Igra pogadanja slucajnog broja.  "<<endl;
        cout << "zmija - Igra u kojoj zmija mora pojesti sto vise voca. Ne smije se zabiti u zid ni u svoje tijelo!"<<endl;
        cout << "kk - Krizic Kruzic - u dvoje"<<endl;
        igrica:
        cin>>c;
        system("cls");
        if(c==kk){
  string v1="1";
  string v2="2";
  string v3="3";
  string v4="4";
  string v5="5";
  string v6="6";
  string v7="7";
  string v8="8";
  string v9="9";
  int a,b,c,d,e,f,g,h,i;
  string x="X";
  string o="O";




 cout<<" K R I Z I C  K R U Z I C"<< endl;
 cout<<""<<endl;
 cout<<v1<<"     "<<v2<<"     "<<v3<<endl;
  cout<<""<< endl;

 cout<<v4<<"     "<<v5<<"     "<<v6<<endl;
  cout<<""<< endl;

 cout<<v7<<"     "<<v8<<"     "<<v9<<endl;



if(((v1==x&&v2==x&&v3==x)||(v4==x&&v5==x&&v6==x)||(v7==x&&v8==x&&v9==x)||(v1==x&&v4==x&&v7==x)||(v2==x&&v5==x&&v8==x)||(v3==x&&v6==x&&v9==x)||(v1==x&&v5==x&&v9==x)||(v7==x&&v5==x&&v3==x)))
{
    cout<<"Pobjednik je prvi igrac"<<endl;Sleep(3000);system("cls");
goto start;
}


if(((v1==o&&v2==o&&v3==o)||(v4==o&&v5==o&&v6==o)||(v7==o&&v8==o&&v9==o)||(v1==o&&v4==o&&v7==o)||(v2==o&&v5==o&&v8==o)||(v3==o&&v6==o&&v9==o)||(v1==o&&v5==o&&v9==o)||(v7==o&&v5==o&&v3==o)))
{
    cout<<"Pobjednik je drugi igrac"<<endl;Sleep(3000);system("cls");
goto start;
}

igr1:
cout<<" Igrac broj 1"<<endl;
cin>>a;
system("cls");
if(a==1)
{
        v1=x;
}
else if (a==1&&v1==o)
    {
        cout<<"Ponovi"<<endl;
        goto igr1;
 }

else if(a==2)
{
        v2=x;
}
else if (f==2&&v2==x)
    {
        cout<<"Ponovi"<<endl;
        goto igr6;
 }
else if (a==2&&v2==o)
    {
        cout<<"Ponovi"<<endl;
        goto igr1;
 }


else if(a==3)
{
        v3=x;
}
else if (a==3&&v3==o)
    {
        cout<<"Ponovi"<<endl;
        goto igr1;
 }

else if(a==4)
{
        v4=x;
}
else if (a==4&&v4==o)
    {
        cout<<"Ponovi"<<endl;
        goto igr1;
 }

else if(a==5)
{
        v5=x;
}

else if (a==5&&v5==o)
    {
        cout<<"Ponovi"<<endl;
        goto igr1;
 }

else if(a==6)
{
        v6=x;
}
else if (a==6&&v6==o)
    {
        cout<<"Ponovi"<<endl;
        goto igr1;
 }

else if(a==7)
{
        v7=x;
}
else if (a==7&&v7==o)
    {
        cout<<"Ponovi"<<endl;
        goto igr1;
 }

else if(a==8)
{
        v8=x;
}
else if (a==8&&v8==o)
    {
        cout<<"Ponovi"<<endl;
        goto igr1;
 }

else if(a==9)
{
        v9=x;
}
else if (a==9&&v9==o)
    {
        cout<<"Ponovi"<<endl;
        goto igr1;
 }

else
{
    cout<<"Ponovi"<<endl;
    goto igr1;
}

 cout<<""<<endl;
 cout<<v1<<"     "<<v2<<"     "<<v3<<endl;
  cout<<""<< endl;

 cout<<v4<<"     "<<v5<<"     "<<v6<<endl;
  cout<<""<< endl;

 cout<<v7<<"     "<<v8<<"     "<<v9<<endl;


if(((v1==x&&v2==x&&v3==x)||(v4==x&&v5==x&&v6==x)||(v7==x&&v8==x&&v9==x)||(v1==x&&v4==x&&v7==x)||(v2==x&&v5==x&&v8==x)||(v3==x&&v6==x&&v9==x)||(v1==x&&v5==x&&v9==x)||(v7==x&&v5==x&&v3==x)))
{
    cout<<"Pobjednik je prvi igrac"<<endl;Sleep(3000);system("cls");
goto start;
}


if(((v1==o&&v2==o&&v3==o)||(v4==o&&v5==o&&v6==o)||(v7==o&&v8==o&&v9==o)||(v1==o&&v4==o&&v7==o)||(v2==o&&v5==o&&v8==o)||(v3==o&&v6==o&&v9==o)||(v1==o&&v5==o&&v9==o)||(v7==o&&v5==o&&v3==o)))
{
    cout<<"Pobjednik je drugi igrac"<<endl;Sleep(3000);system("cls");
goto start;
}
 igr2:
cout<<"Igrac broj 2"<<endl;
cin>>b;system("cls");
if(b==1)
{
        v1=o;
}
else if (b==1&&v1==x)
    {
        cout<<"Ponovi"<<endl;
        goto igr2;
 }

else if(b==2)
{
        v2=o;
}
else if (b==2&&v2==x)
    {
        cout<<"Ponovi"<<endl;
        goto igr2;
 }
else if(b==3)
{
        v3=o;
}
else if (b==3&&v3==x)
    {
        cout<<"Ponovi"<<endl;
        goto igr2;
 }
else if(b==4)
{
        v4=o;
}
else if (b==4&&v4==x)
    {
        cout<<"Ponovi"<<endl;
        goto igr2;
 }
else if(b==5)
{
        v5=o;
}

else if (b==5&&v5==x)
    {
        cout<<"Ponovi"<<endl;
        goto igr2;
 }
else if(b==6)
{
        v6=o;
}
else if (b==6&&v6==x)
    {
        cout<<"Ponovi"<<endl;
        goto igr2;
 }
else if(b==7)
{
        v7=o;
}
else if (b==7&&v7==x)
    {
        cout<<"Ponovi"<<endl;
        goto igr2;
 }
else if(b==8)
{
        v8=o;
}
else if (b==8&&v8==x)
    {
        cout<<"Ponovi"<<endl;
        goto igr2;
 }
else if(b==9)
{
        v9=o;
}
else if (b==9&&v9==x)
    {
        cout<<"Ponovi"<<endl;
        goto igr2;
 }
else
{
    cout<<"Ponovi"<<endl;
    goto igr2;
}

 cout<<""<<endl;
 cout<<v1<<"     "<<v2<<"     "<<v3<<endl;
  cout<<""<< endl;

 cout<<v4<<"     "<<v5<<"     "<<v6<<endl;
  cout<<""<< endl;

 cout<<v7<<"     "<<v8<<"     "<<v9<<endl;

if(((v1==x&&v2==x&&v3==x)||(v4==x&&v5==x&&v6==x)||(v7==x&&v8==x&&v9==x)||(v1==x&&v4==x&&v7==x)||(v2==x&&v5==x&&v8==x)||(v3==x&&v6==x&&v9==x)||(v1==x&&v5==x&&v9==x)||(v7==x&&v5==x&&v3==x)))
{
    cout<<"Pobjednik je prvi igrac"<<endl;Sleep(3000);system("cls");
goto start;
}


if(((v1==o&&v2==o&&v3==o)||(v4==o&&v5==o&&v6==o)||(v7==o&&v8==o&&v9==o)||(v1==o&&v4==o&&v7==o)||(v2==o&&v5==o&&v8==o)||(v3==o&&v6==o&&v9==o)||(v1==o&&v5==o&&v9==o)||(v7==o&&v5==o&&v3==o)))
{
    cout<<"Pobjednik je drugi igrac"<<endl;Sleep(3000);system("cls");
goto start;
}
 igr3:
cout<<" Igrac broj 1"<<endl;
cin>>c;system("cls");
if(c==1)
{
        v1=x;
}
else if (c==1&&v1==o)
    {
        cout<<"Ponovi"<<endl;
        goto igr3;
 }
else if(c==2)
{
        v2=x;
}
else if (c==2&&v2==o)
    {
        cout<<"Ponovi"<<endl;
        goto igr3;
 }
else if(c==3)
{
        v3=x;
}
else if (c==3&&v3==o)
    {
        cout<<"Ponovi"<<endl;
        goto igr3;
 }
else if(c==4)
{
        v4=x;
}
else if (c==4&&v4==o)
    {
        cout<<"Ponovi"<<endl;
        goto igr3;
 }
else if(c==5)
{
        v5=x;
}

else if (c==5&&v5==o)
    {
        cout<<"Ponovi"<<endl;
        goto igr3;
 }
else if(c==6)
{
        v6=x;
}
else if (c==6&&v6==o)
    {
        cout<<"Ponovi"<<endl;
        goto igr3;
 }
else if(c==7)
{
        v7=x;
}
else if (c==7&&v7==o)
    {
        cout<<"Ponovi"<<endl;
        goto igr3;
 }
else if(c==8)
{
        v8=x;
}
else if (c==8&&v8==o)
    {
        cout<<"Ponovi"<<endl;
        goto igr3;
 }
else if(c==9)
{
        v9=x;
}
else if (c==9&&v9==o)
    {
        cout<<"Ponovi"<<endl;
        goto igr3;
 }
else
{
    cout<<"Ponovi"<<endl;
    goto igr3;
}





 cout<<""<<endl;
 cout<<v1<<"     "<<v2<<"     "<<v3<<endl;
  cout<<""<< endl;

 cout<<v4<<"     "<<v5<<"     "<<v6<<endl;
  cout<<""<< endl;

 cout<<v7<<"     "<<v8<<"     "<<v9<<endl;
if(((v1==x&&v2==x&&v3==x)||(v4==x&&v5==x&&v6==x)||(v7==x&&v8==x&&v9==x)||(v1==x&&v4==x&&v7==x)||(v2==x&&v5==x&&v8==x)||(v3==x&&v6==x&&v9==x)||(v1==x&&v5==x&&v9==x)||(v7==x&&v5==x&&v3==x)))
{
    cout<<"Pobjednik je prvi igrac"<<endl;Sleep(3000);system("cls");
goto start;
}


if(((v1==o&&v2==o&&v3==o)||(v4==o&&v5==o&&v6==o)||(v7==o&&v8==o&&v9==o)||(v1==o&&v4==o&&v7==o)||(v2==o&&v5==o&&v8==o)||(v3==o&&v6==o&&v9==o)||(v1==o&&v5==o&&v9==o)||(v7==o&&v5==o&&v3==o)))
{
    cout<<"Pobjednik je drugi igrac"<<endl;Sleep(3000);system("cls");
goto start;
}
 igr4:
cout<<" Igrac broj 2"<<endl;
cin>>d;system("cls");
if(d==1)
{
        v1=o;
}
else if (d==1&&v1==x)
    {
        cout<<"Ponovi"<<endl;
        goto igr4;
 }
else if(d==2)
{
        v2=o;
}
else if (d==2&&v2==x)
    {
        cout<<"Ponovi"<<endl;
        goto igr4;
 }
else if(d==3)
{
        v3=o;
}
else if (d==3&&v3==x)
    {
        cout<<"Ponovi"<<endl;
        goto igr4;
 }
else if(d==4)
{
        v4=o;
}
else if (d==4&&v4==x)
    {
        cout<<"Ponovi"<<endl;
        goto igr4;
 }
else if(d==5)
{
        v5=o;
}

else if (d==5&&v5==x)
    {
        cout<<"Ponovi"<<endl;
        goto igr4;
 }
else if(d==6)
{
        v6=o;
}
else if (d==6&&v6==x)
    {
        cout<<"Ponovi"<<endl;
        goto igr4;
 }
else if(d==7)
{
        v7=o;
}
else if (d==7&&v7==x)
    {
        cout<<"Ponovi"<<endl;
        goto igr4;
 }
else if(d==8)
{
        v8=o;
}
else if (d==8&&v8==x)
    {
        cout<<"Ponovi"<<endl;
        goto igr4;
 }
else if(d==9)
{
        v9=o;
}
else if (d==9&&v9==x)
    {
        cout<<"Ponovi"<<endl;
        goto igr4;
 }
else
{
    cout<<"Ponovi"<<endl;
    goto igr4;
}

 cout<<""<<endl;
 cout<<v1<<"     "<<v2<<"     "<<v3<<endl;
  cout<<""<< endl;

 cout<<v4<<"     "<<v5<<"     "<<v6<<endl;
  cout<<""<< endl;

 cout<<v7<<"     "<<v8<<"     "<<v9<<endl;
if(((v1==x&&v2==x&&v3==x)||(v4==x&&v5==x&&v6==x)||(v7==x&&v8==x&&v9==x)||(v1==x&&v4==x&&v7==x)||(v2==x&&v5==x&&v8==x)||(v3==x&&v6==x&&v9==x)||(v1==x&&v5==x&&v9==x)||(v7==x&&v5==x&&v3==x)))
{
    cout<<"Pobjednik je prvi igrac"<<endl;Sleep(3000);system("cls");
goto start;
}


if(((v1==o&&v2==o&&v3==o)||(v4==o&&v5==o&&v6==o)||(v7==o&&v8==o&&v9==o)||(v1==o&&v4==o&&v7==o)||(v2==o&&v5==o&&v8==o)||(v3==o&&v6==o&&v9==o)||(v1==o&&v5==o&&v9==o)||(v7==o&&v5==o&&v3==o)))
{
    cout<<"Pobjednik je drugi igrac"<<endl;Sleep(3000);system("cls");
goto start;
}
 igr5:
cout<<" Igrac broj 1"<<endl;
cin>>e;system("cls");
if(e==1)
{
        v1=x;
}
else if (e==1&&v1==o)
    {
        cout<<"Ponovi"<<endl;
        goto igr5;
 }
else if(e==2)
{
        v2=x;
}
else if (e==2&&v2==o)
    {
        cout<<"Ponovi"<<endl;
        goto igr5;
 }
else if(e==3)
{
        v3=x;
}
else if (e==3&&v3==o)
    {
        cout<<"Ponovi"<<endl;
        goto igr5;
 }
else if(e==4)
{
        v4=x;
}
else if (e==4&&v4==o)
    {
        cout<<"Ponovi"<<endl;
        goto igr5;
 }
else if(e==5)
{
        v5=x;
}

else if (e==5&&v5==o)
    {
        cout<<"Ponovi"<<endl;
        goto igr5;
 }
else if(e==6)
{
        v6=x;
}
else if (e==6&&v6==o)
    {
        cout<<"Ponovi"<<endl;
        goto igr5;
 }
else if(e==7)
{
        v7=x;
}
else if (e==7&&v7==o)
    {
        cout<<"Ponovi"<<endl;
        goto igr5;
 }
else if(e==8)
{
        v8=x;
}
else if (e==8&&v8==o)
    {
        cout<<"Ponovi"<<endl;
        goto igr5;
 }
else if(e==9)
{
        v9=x;
}
else if (e==9&&v9==o)
    {
        cout<<"Ponovi"<<endl;
        goto igr5;
 }
else
{
    cout<<"Ponovi"<<endl;
    goto igr5;
}

 cout<<""<<endl;
 cout<<v1<<"     "<<v2<<"     "<<v3<<endl;
  cout<<""<< endl;

 cout<<v4<<"     "<<v5<<"     "<<v6<<endl;
  cout<<""<< endl;

 cout<<v7<<"     "<<v8<<"     "<<v9<<endl;
if(((v1==x&&v2==x&&v3==x)||(v4==x&&v5==x&&v6==x)||(v7==x&&v8==x&&v9==x)||(v1==x&&v4==x&&v7==x)||(v2==x&&v5==x&&v8==x)||(v3==x&&v6==x&&v9==x)||(v1==x&&v5==x&&v9==x)||(v7==x&&v5==x&&v3==x)))
{
    cout<<"Pobjednik je prvi igrac"<<endl;Sleep(3000);system("cls");
goto start;
}


if(((v1==o&&v2==o&&v3==o)||(v4==o&&v5==o&&v6==o)||(v7==o&&v8==o&&v9==o)||(v1==o&&v4==o&&v7==o)||(v2==o&&v5==o&&v8==o)||(v3==o&&v6==o&&v9==o)||(v1==o&&v5==o&&v9==o)||(v7==o&&v5==o&&v3==o)))
{
    cout<<"Pobjednik je drugi igrac"<<endl;Sleep(3000);system("cls");
goto start;
}
 igr6:
cout<<" Igrac broj 2"<<endl;
cin>>f;system("cls");
if(f==1)
{
        v1=o;
}
else if (f==1&&v1==x)
    {
        cout<<"Ponovi"<<endl;
        goto igr6;
 }
else if(f==2)
{
        v2=o;
}
else if (f==2&&v2==x)
    {
        cout<<"Ponovi"<<endl;
        goto igr6;
 }
else if(f==3)
{
        v3=o;
}
else if (f==3&&v3==x)
    {
        cout<<"Ponovi"<<endl;
        goto igr6;
 }
else if(f==4)
{
        v4=o;
}
else if (f==4&&v4==x)
    {
        cout<<"Ponovi"<<endl;
        goto igr6;
 }
else if(f==5)
{
        v5=o;
}

else if (f==5&&v5==x)
    {
        cout<<"Ponovi"<<endl;
        goto igr6;
 }
else if(f==6)
{
        v6=o;
}
else if (f==6&&v6==x)
    {
        cout<<"Ponovi"<<endl;
        goto igr6;
 }
else if(f==7)
{
        v7=o;
}
else if (f==7&&v7==x)
    {
        cout<<"Ponovi"<<endl;
        goto igr6;
 }
else if(f==8)
{
        v8=o;
}
else if (f==8&&v8==x)
    {
        cout<<"Ponovi"<<endl;
        goto igr6;
 }
else if(f==9)
{
        v9=o;
}
else if (f==9&&v9==x)
    {
        cout<<"Ponovi"<<endl;
        goto igr6;
 }
else
{
    cout<<"Ponovi"<<endl;
    goto igr6;
}

 cout<<""<<endl;
 cout<<v1<<"     "<<v2<<"     "<<v3<<endl;
  cout<<""<< endl;

 cout<<v4<<"     "<<v5<<"     "<<v6<<endl;
  cout<<""<< endl;

 cout<<v7<<"     "<<v8<<"     "<<v9<<endl;
if(((v1==x&&v2==x&&v3==x)||(v4==x&&v5==x&&v6==x)||(v7==x&&v8==x&&v9==x)||(v1==x&&v4==x&&v7==x)||(v2==x&&v5==x&&v8==x)||(v3==x&&v6==x&&v9==x)||(v1==x&&v5==x&&v9==x)||(v7==x&&v5==x&&v3==x)))
{
    cout<<"Pobjednik je prvi igrac"<<endl;Sleep(3000);system("cls");
goto start;
}


if(((v1==o&&v2==o&&v3==o)||(v4==o&&v5==o&&v6==o)||(v7==o&&v8==o&&v9==o)||(v1==o&&v4==o&&v7==o)||(v2==o&&v5==o&&v8==o)||(v3==o&&v6==o&&v9==o)||(v1==o&&v5==o&&v9==o)||(v7==o&&v5==o&&v3==o)))
{
    cout<<"Pobjednik je drugi igrac"<<endl;Sleep(3000);system("cls");
goto start;
}
 igr7:
cout<<" Igrac broj 1"<<endl;
cin>>g;system("cls");
if(g==1)
{
        v1=x;
}
else if (g==1&&v1==o)
    {
        cout<<"Ponovi"<<endl;
        goto igr7;
 }
else if(g==2)
{
        v2=x;
}
else if (g==2&&v2==o)
    {
        cout<<"Ponovi"<<endl;
        goto igr7;
 }
else if(g==3)
{
        v3=x;
}
else if (g==3&&v3==o)
    {
        cout<<"Ponovi"<<endl;
        goto igr7;
 }
else if(g==4)
{
        v4=x;
}
else if (g==4&&v4==o)
    {
        cout<<"Ponovi"<<endl;
        goto igr7;
 }
else if(g==5)
{
        v5=x;
}

else if (g==5&&v5==o)
    {
        cout<<"Ponovi"<<endl;
        goto igr7;
 }
else if(g==6)
{
        v6=x;
}
else if (g==6&&v6==o)
    {
        cout<<"Ponovi"<<endl;
        goto igr7;
 }
else if(g==7)
{
        v7=x;
}
else if (g==7&&v7==o)
    {
        cout<<"Ponovi"<<endl;
        goto igr7;
 }
else if(g==8)
{
        v8=x;
}
else if (g==8&&v8==o)
    {
        cout<<"Ponovi"<<endl;
        goto igr7;
 }
else if(g==9)
{
        v9=x;
}
else if (g==9&&v9==o)
    {
        cout<<"Ponovi"<<endl;
        goto igr7;
 }
else
{
    cout<<"Ponovi"<<endl;
    goto igr7;
}

 cout<<""<<endl;
 cout<<v1<<"     "<<v2<<"     "<<v3<<endl;
  cout<<""<< endl;

 cout<<v4<<"     "<<v5<<"     "<<v6<<endl;
  cout<<""<< endl;

 cout<<v7<<"     "<<v8<<"     "<<v9<<endl;
if(((v1==x&&v2==x&&v3==x)||(v4==x&&v5==x&&v6==x)||(v7==x&&v8==x&&v9==x)||(v1==x&&v4==x&&v7==x)||(v2==x&&v5==x&&v8==x)||(v3==x&&v6==x&&v9==x)||(v1==x&&v5==x&&v9==x)||(v7==x&&v5==x&&v3==x)))
{
    cout<<"Pobjednik je prvi igrac"<<endl;Sleep(3000);system("cls");
goto start;
}


if(((v1==o&&v2==o&&v3==o)||(v4==o&&v5==o&&v6==o)||(v7==o&&v8==o&&v9==o)||(v1==o&&v4==o&&v7==o)||(v2==o&&v5==o&&v8==o)||(v3==o&&v6==o&&v9==o)||(v1==o&&v5==o&&v9==o)||(v7==o&&v5==o&&v3==o)))
{
    cout<<"Pobjednik je drugi igrac"<<endl;Sleep(3000);system("cls");
goto start;
}
 igr8:
cout<<"Igrac broj 2"<<endl;
cin>>h;system("cls");
if(h==1)
{
        v1=o;
}
else if (h==1&&v1==x)
    {
        cout<<"Ponovi"<<endl;
        goto igr8;
 }
else if(h==2)
{
        v2=o;
}
else if (h==2&&v2==x)
    {
        cout<<"Ponovi"<<endl;
        goto igr8;
 }
else if(h==3)
{
        v3=o;
}
else if (h==3&&v3==x)
    {
        cout<<"Ponovi"<<endl;
        goto igr8;
 }
else if(h==4)
{
        v4=o;
}
else if (h==4&&v4==x)
    {
        cout<<"Ponovi"<<endl;
        goto igr8;
 }
else if(h==5)
{
        v5=o;
}

else if (h==5&&v5==x)
    {
        cout<<"Ponovi"<<endl;
        goto igr8;
 }
else if(h==6)
{
        v6=o;
}
else if (h==6&&v6==x)
    {
        cout<<"Ponovi"<<endl;
        goto igr8;
 }
else if(h==7)
{
        v7=o;
}
else if (h==7&&v7==x)
    {
        cout<<"Ponovi"<<endl;
        goto igr8;
 }
else if(h==8)
{
        v8=o;
}
else if (h==8&&v8==x)
    {
        cout<<"Ponovi"<<endl;
        goto igr8;
 }
else if(h==9)
{
        v9=o;
}

else if (h==9&&v9==x)
    {
        cout<<"Ponovi"<<endl;
        goto igr8;
 }else
{
    cout<<"Ponovi"<<endl;
    goto igr8;
}

 cout<<""<<endl;
 cout<<v1<<"     "<<v2<<"     "<<v3<<endl;
  cout<<""<< endl;

 cout<<v4<<"     "<<v5<<"     "<<v6<<endl;
  cout<<""<< endl;

 cout<<v7<<"     "<<v8<<"     "<<v9<<endl;

if(((v1==x&&v2==x&&v3==x)||(v4==x&&v5==x&&v6==x)||(v7==x&&v8==x&&v9==x)||(v1==x&&v4==x&&v7==x)||(v2==x&&v5==x&&v8==x)||(v3==x&&v6==x&&v9==x)||(v1==x&&v5==x&&v9==x)||(v7==x&&v5==x&&v3==x)))
{
    cout<<"Pobjednik je prvi igrac"<<endl;Sleep(3000);system("cls");
  goto start;

}


if(((v1==o&&v2==o&&v3==o)||(v4==o&&v5==o&&v6==o)||(v7==o&&v8==o&&v9==o)||(v1==o&&v4==o&&v7==o)||(v2==o&&v5==o&&v8==o)||(v3==o&&v6==o&&v9==o)||(v1==o&&v5==o&&v9==o)||(v7==o&&v5==o&&v3==o)))
{
    cout<<"Pobjednik je drugi igrac"<<endl;Sleep(3000);system("cls");
   goto start;

}



 igr9:
cout<<" igrac broj 1"<<endl;
cin>>i;system("cls");
if(i==1)
{
        v1=x;
}
else if (i==1&&v1==o)
    {
        cout<<"Ponovi"<<endl;
        goto igr9;
 }
else if(i==2)
{
        v2=x;
}
else if (i==2&&v2==o)
    {
        cout<<"Ponovi"<<endl;
        goto igr9;
 }
else if(i==3)
{
        v3=x;
}
else if (i==3&&v3==o)
    {
        cout<<"Ponovi"<<endl;
        goto igr9;
 }
else if(i==4)
{
        v4=x;
}
else if (i==4&&v4==o)
    {
        cout<<"Ponovi"<<endl;
        goto igr9;
 }
else if(i==5)
{
        v5=x;
}

else if (i==5&&v5==o)
    {
        cout<<"Ponovi"<<endl;
        goto igr9;
 }
else if(i==6)
{
        v6=x;
}
else if (i==6&&v6==o)
    {
        cout<<"Ponovi"<<endl;
        goto igr9;
 }
else if(i==7)
{
        v7=x;
}
else if (i==7&&v7==o)
    {
        cout<<"Ponovi"<<endl;
        goto igr9;
 }
else if(i==8)
{
        v8=x;
}
else if (i==8&&v8==o)
    {
        cout<<"Ponovi"<<endl;
        goto igr9;
 }
else if(i==9)
{
        v9=x;
}
else if (i==9&&v9==o)
    {
        cout<<"Ponovi"<<endl;
        goto igr9;
 }
else
{
    cout<<"Ponovi"<<endl;
    goto igr9;
}



 cout<<""<<endl;
 cout<<v1<<"     "<<v2<<"     "<<v3<<endl;
  cout<<""<< endl;

 cout<<v4<<"     "<<v5<<"     "<<v6<<endl;
  cout<<""<< endl;

 cout<<v7<<"     "<<v8<<"     "<<v9<<endl;



 if(((v1==x&&v2==x&&v3==x)||(v4==x&&v5==x&&v6==x)||(v7==x&&v8==x&&v9==x)||(v1==x&&v4==x&&v7==x)||(v2==x&&v5==x&&v8==x)||(v3==x&&v6==x&&v9==x)||(v1==x&&v5==x&&v9==x)||(v7==x&&v5==x&&v3==x)))
{
    cout<<"Pobjednik je prvi igrac"<<endl;Sleep(3000);system("cls");
    goto start;

}


if(((v1==o&&v2==o&&v3==o)||(v4==o&&v5==o&&v6==o)||(v7==o&&v8==o&&v9==o)||(v1==o&&v4==o&&v7==o)||(v2==o&&v5==o&&v8==o)||(v3==o&&v6==o&&v9==o)||(v1==o&&v5==o&&v9==o)||(v7==o&&v5==o&&v3==o)))
{
    cout<<"Pobjednik je drugi igrac"<<endl;Sleep(3000);system("cls");
    goto start;

}
else{
    cout<<"Nema pobjednika"<<endl;Sleep(3000);system("cls");
}









}
        if(c==zmija){
        system("COLOR 0C");
        cout << "Zmija"<<endl;
        cout << ""<<endl;
        cout << "W = gore"<<endl;
        cout << "A = lijevo"<<endl;
        cout << "S = dolje"<<endl;
        cout << "D = desno"<<endl;
        cout << ""<<endl;
        cout << "Cilj igre je pojesti sto vise voca."<<endl;
        cout << "Zmija se ne smije zabiti u zid niti u sebe!"<<endl;

        Sleep(3000);
        system("cls");



            Setup();

        while (!Kraj)
        {
            Draw();
            Input();
            Logic();
            Sleep(40);

        }
        cout<<"Kraj!"<<endl;
        Sleep(2000);
        system("cls");
        goto start;
        }
        if(c==pogodi){
        int pogbr,slbr;

        string daneslbr;




        system("COLOR 0A");
        cout << "Pogadanje broja "<<endl;
        cout << "U svakoj rundi odabran je nasumican broj od 0 do 1000 "<<endl;
        cout << "Cilj igre je upisivati brojeve dok ne pronadete zadani broj "<<endl;
        cout << "Ako je broj veci ili manji od trazenog dobit cete poruku"<<endl;
        cout << "kako bi znali trazi li se veci ili manji broj."<<endl;
        cout << ""<<endl;
        slbrstart:
        int pokusajislbr=0;
        slbr = rand() % 1000;
        cout << "Upisi 1001 za izlaz"<<endl;
        cout << "Slucajni broj je odabran: "<<endl;
        pogodibr:
        cout << "Upisi broj."<<endl;
        cin >> pogbr;
        if (pogbr == 1001){
            system("cls");
            goto start;
        }

        else if (pogbr < slbr){
            cout << "Trazeni broj je veci od tvog broja"<<endl;
            pokusajislbr++;
            goto pogodibr;
        }
        else if (pogbr > slbr){
            cout << "Trazeni broj je manji od tvog broja"<<endl;
            pokusajislbr++;
            goto pogodibr;
        }
        else if (pogbr == slbr){
            cout << "Pogodio/la si slucajni broj!"<<endl;
            cout << "Trebalo ti je "<< pokusajislbr<<" pokusaja." <<endl;
            pocetakslbr:
            cout << "Kreni iz pocetka? (da/ne)" <<endl;
            cin >> daneslbr;
            if (daneslbr == da){
                    system("cls");
                goto slbrstart;
            }
            else if (daneslbr == ne){
                system("cls");
                goto start;
            }
            else {
                cout << "Ne razumijem"<<endl;
            system("cls");
                goto pocetakslbr;
            }
        }


        }
        if(c==musketiri){

            int musk = 0;
            int lop1= 0;
            int lop2= 0;
            int lop3= 0;
            int lop4= 0;
            int lop5= 0;
            int lop6= 0;
            int novac = 0;
            int smrt1= 0;
            int smrt2= 0;
            int smrt3= 0;
            int smrt4= 0;
            int smrt5= 0;
            int smrt6= 0;
            int musks = musk+5;

             if (admin==true){
            cout<<"Cheats:"<<endl;
            cout<<"pluss: + 300 novca"<<endl;
            cout<<"army: + 100 ljudi"<<endl;
            cout<<"nista: ....."<<endl;
            admmuskch:
            cin>>cheatsmusk;
            if(cheatsmusk==pluss){novac=novac+300;system("cls");goto admmuskch;}
            if(cheatsmusk==army){musk=musk + 100;system("cls");goto admmuskch;}
            if(cheatsmusk==nista){system("cls");goto stmusk;}

             }
             stmusk:
            system("COLOR 0B");
            cout << "Musketiri "<<endl;
            cout << "Igra u obliku price"<<endl;
            cout << " "<<endl;
            cout << "Francuska, 1624. godina "<<endl;Sleep(1000);
            cout << "Grupa musketira sastaje se na glavnom trgu. "<<endl;Sleep(1000);
            musk1:
            cout << "Koliko musketira se nalazi ondje? (upisi broj izmedu 10 i 20) "<<endl;Sleep(1000);
            cin >> musk;

            if (musk<10 || musk >20){
                cout << "Molim te ponovi... "<<endl;Sleep(1000);
                goto musk1;
            }
            else if (musk>9 || musk <21){goto musk2;}
            else{cout << "Molim te ponovi... "<<endl;Sleep(1000);
                goto musk1;}
            musk2:
            int novci1;
            lop1 = rand() % 9;
            string odabir1;
            string borba="borba";
            string bijeg="bijeg";
            cout << musk << " musketira se nalazi na trgu."<<endl;Sleep(1000);
            cout << "Musketiri razgovaraju, kada dolazi "<<lop1+1<< " zlocinaca"<<endl;Sleep(1000);
            cout <<"Sto da musketiri ucine? (upisi borba ili bijeg)"<<endl;Sleep(1000);
            ne1:
            cin>>odabir1;

            if (odabir1==izlaz){
            system("cls");
            goto start;
            }
            if (odabir1==deset){
            novac=novac+10;
            goto ne1;
            }
            if(odabir1==bijeg){
            if (novac>10){
            novac = novac/6;
            cout <<"Bijeg je bio uspjesan"<<endl;Sleep(1000);
            }
            else {cout <<"Ne mozes pobjeci"<<endl;Sleep(1000);
            goto ne1;}
            }
            else if(odabir1 == borba)
            {
                smrt1 = rand() % musks;
                novci1 = rand() % 4;
                musk = musk - smrt1;
                if(musk>0){
                novac = novac+novci1;
                cout<<"Pobjeda! Ostalo je jos "<<musk<< " musketira"<<endl;Sleep(1000);
                cout<<"Imas jos "<<novac<<" novca"<<endl;Sleep(1000);
                goto musk3;
                }
                else{
                    cout<<"Kraj. Svi musketiri su mrtvi. Nastavljas od posljednjeg vaznijeg dogadaja."<<endl;Sleep(1000);
                    goto musk2;
                }
            }
            else{cout<<"Ne razumijem"<<endl;Sleep(1000);
            goto musk2;}
            musk3:

            int novci2;
            cout<<"Musketiri nastavljaju sa razgovorom"<<endl;Sleep(1000);
            cout<<"Nekoliko minuta kasnije..."<<endl;Sleep(1000);
            cout<<"Blizu musketira zacuje se vrisak"<<endl;Sleep(1000);
            cout<<"Musketiri dotrce i vide jos neprijatelja"<<endl;Sleep(1000);
            lop2 = rand() % 9;
            cout<<"Ondje je "<<lop2<<" neprijatelja"<<endl;Sleep(1000);
            string odabir2;
            cout <<"Sto da musketiri ucine? (upisi borba ili bijeg)"<<endl;Sleep(1000);
            ne2:
            cin>>odabir2;
            if (odabir2==deset){
            novac=novac+10;
            goto ne2;
            }
            if (odabir2==izlaz){
        system("cls");
        goto start;
        }
            if(odabir2==bijeg){
            if (novac>10){
            novac = novac/6;
            cout <<"Bijeg je bio uspjesan"<<endl;Sleep(1000);
            }
            else {cout <<"Ne mozes pobjeci"<<endl;Sleep(1000);
            goto ne2;}
            }
            else if(odabir2 == borba)
            {
                smrt2 = rand() % musks;
                novci2 = rand() % 4;
                musk = musk - smrt2;
                if(musk>0){
                novac = novac+novci2;
                cout<<"Pobjeda! Ostalo je jos "<<musk<< " musketira"<<endl;Sleep(1000);
                cout<<"Imas jos "<<novac<<" novca"<<endl;Sleep(1000);
                goto musk4;
                }
                else{
                    cout<<"Kraj. Svi musketiri su mrtvi. Nastavljas od posljednjeg vaznijeg dogadaja."<<endl;Sleep(1000);
                    goto musk3;
                }
            }
            else{cout<<"Ne razumijem"<<endl;Sleep(1000);
            goto musk2;}
            musk4:
            string dane1;
            int kupi1;
            cout<<"Grupa tvojih musketira nastavlja sa razgovorom."<<endl;Sleep(1000);
            cout<<"Jednog trenutka zacuje se galopiranje."<<endl;Sleep(1000);
            cout<<"Svi gledaju prema konjima."<<endl;Sleep(1000);
            cout<<"To je trgovac!"<<endl;Sleep(1000);
            cout<<"Grupa tvojih musketira odlazi prema trgovcu."<<endl;Sleep(1000);
            kup1:
            cout<<"Sto zelis kupiti?"<<endl;Sleep(1000);
            cout<<"1 musketir - 1 novcica"<<endl;Sleep(1000);
            cout<<"5 musketira - 5 novcica"<<endl;Sleep(1000);
            cout<<"10 musketira - 10 novcica"<<endl;Sleep(1000);
            cout<<"Ti imas "<<novac<<" novca"<<endl;Sleep(1000);
            cout<<"Upisi 1,5 ili 10 da kupis toliko musketira."<<endl;Sleep(1000);
            cin>>kupi1;

            if(kupi1 == 1){
                if(novac>=1){
                musk = musk+1;
                novac = novac-1;
                goto kupi1a;}
                else{
                cout<<"Nemas dovoljno novca"<<endl;Sleep(1000);
                goto kup1;}
            }
            else if(kupi1 == 5){
                if(novac>=5){
                musk = musk+5;
                novac = novac - 5;
                goto kupi1a;}
                else{
                cout<<"Nemas dovoljno novca"<<endl;Sleep(1000);
                goto kup1;}
            }
            else if(kupi1 == 10){
                if(novac>=10){
                musk=musk+10;
                novac=novac-10;
                goto kupi1a;}
                else{
                cout<<"Nemas dovoljno novca"<<endl;Sleep(1000);
                goto kup1;
                }
            }
            else{cout<<"Ponovi"<<endl;Sleep(1000);}
            kupi1a:
            cout<<"Jos nesto? (da / ne)"<<endl;Sleep(1000);
            cin>>dane1;
            if (dane1==da){goto kup1;}
            else if(dane1==ne){goto musk5;}
        musk5:
            int novci4;
        cout<<"Musketiri odlaze prema brodskoj luci"<<endl;Sleep(1000);
        cout<<"Zacuje se glasan smijeh i razbijanje"<<endl;Sleep(1000);
        cout<<"Musketiri dotrce i vide jos neprijatelja"<<endl;Sleep(1000);
        lop4 = rand() % 9;
        cout<<"Ondje je "<<lop4<<" neprijatelja"<<endl;Sleep(1000);
        string odabir4;
        cout <<"Sto da musketiri ucine? (upisi borba ili bijeg)"<<endl;Sleep(1000);
        ne4:
        cin>>odabir4;
        if (odabir4==deset){
            novac=novac+10;
            goto ne4;
            }
        if (odabir4==izlaz){
        system("cls");
        goto start;
        }
        if(odabir4==bijeg){
        if(novac>10){
        novac = novac/6;
        cout <<"Bijeg je bio uspjesan"<<endl;Sleep(1000);
        }
        else {cout <<"Ne mozes pobjeci"<<endl;Sleep(1000);
        goto ne4;}
        }
        else if(odabir4 == borba)
        {
            smrt4 = rand() % musks;
            novci4 = rand() % 4;
            musk = musk - smrt4;
            if(musk>0){
            novac = novac+novci4;
            cout<<"Pobjeda! Ostalo je jos "<<musk<< " musketira"<<endl;Sleep(1000);
            cout<<"Imas jos "<<novac<<" novca"<<endl;Sleep(1000);
            goto musk6;
            }
            else{
                cout<<"Kraj. Svi musketiri su mrtvi. Nastavljas od posljednjeg vaznijeg dogadaja."<<endl;Sleep(1000);
                goto musk5;
            }
        }
        else{cout<<"Ne razumijem"<<endl;Sleep(1000);
        goto ne4;}
        musk6:
        cout<<"Preostali musketiri zadovoljni njihovim uspjesima, nastavljaju svoj dan."<<endl;Sleep(1000);
        cout<<"Kraj."<<endl;Sleep(1000);
        cout<<"Na kraju imas "<<musk<< " musketira"<<endl;Sleep(1000);
        cout<<"Imas "<<novac<<" novca"<<endl;Sleep(1000);
        Sleep(3000);
        system("cls");
        goto start;
}
        if(c==psk){
        int ja=0;
        int pc=0;
        system("COLOR 0D");
    cout << "Papir, skare, kamen "<<endl;
    cout << "Za izlazak upisi izlaz "<<endl;
    cout << "Upute - Igra se do 5 bodova. Igrac upisuje - papir , skare ili kamen."<<endl;
    cout << "Nakon igraca , bot nasumicno odabire svoj potez, te pobjednik osvaja bod."<<endl;
    cout<< "Upisi papir , skare ili kamen: ";
psks:

     cout<< "Ti: "<<ja<< " Bot: "<<pc<<endl;

    cin >> odabirpsk;
    if (odabirpsk==izlaz){
        system("cls");
        goto start;
        }
    randpsk = rand() % 2;
    if (randpsk == 0){
            cout<< "Papir! "<<endl;
        if (odabirpsk ==papir){
            cout<< "Jednako. "<<endl;
        }
        else if(odabirpsk ==skare){
            cout<< "Ti dobivas bod. "<<endl;
            ja=ja+1;
        }
        else if(odabirpsk ==kamen){
            cout<< "Bot dobiva bod. "<<endl;
            pc=pc+1;
        }
    }
    if (randpsk == 1){
            cout<< "Skare! "<<endl;
        if (odabirpsk ==papir){
            cout<< "Bot dobiva bod. "<<endl;
            pc=pc+1;
        }
        else if(odabirpsk ==skare){
        cout<< "Jednako. "<<endl;
        }
        else if(odabirpsk ==kamen){
            cout<< "Ti dobivas bod. "<<endl;
            ja=ja+1;
        }
    }
    if (randpsk == 2){
            cout<< "Kamen! "<<endl;
        if (odabirpsk ==papir){
            cout<< "Ti dobivas bod."<<endl;
            ja=ja+1;
        }
        else if(odabirpsk ==skare){
            cout<< "Bod dobiva bod. "<<endl;
            pc=pc+1;
        }
        else if(odabirpsk ==kamen){
            cout<< "Jednako. "<<endl;
        }
    }
    if(ja==5){
        cout<< "Pobjeda! "<<endl;Sleep(3000);
        system("cls");
        goto start;
    }
    else if(pc==5){
        cout<< "Gubitak."<<endl;Sleep(3000);
        system("cls");
        goto start;
    }
    else{
    goto psks;
}


}
        if(c==dgs){
        int p1=0;
        int p2=0;
        string drzava1="asd";
        string drzava2="asd";
        string grad1="asd";
        string grad2="asd";
        string selo1="asd";
        string selo2="asd";
        string ime1="asd";
        string ime2="asd";
        string zivotinja1="asd";
        string zivotinja2="asd";
        string stvar1="asd";
        string stvar2="asd";
        string slovo="a";
        system("COLOR 0E");
        cout<<"Drzava, grad , selo"<<endl;
        cout<<"Upute - igraci upiuju slovo koje odrede. Nakon toga dobiju grupu (na primjer - drzava)"<<endl;
        cout<<"i upisuju rijec koja pocinje zadanim slovom i koja pripada u tu grupu"<<endl;
        cout<<"Bodovi: Igrac 1: "<<p1<<" Igrac 2: "<<p2<<endl;
        cout<<"Slovo: ";
        cin>> slovo;
        if (slovo == izlaz){
                system("cls");
                goto start;}
        cout<<"Drzava "<<endl;
        cout<<"Igrac 1: "<<endl;
        cin>> drzava1;
        if (drzava1 == izlaz){
            system("cls");
            goto start;}
        cout<<"Igrac 2: "<<endl;
        cin>> drzava2;
        if (drzava2 == izlaz){
            system("cls");
            goto start;}


        if (drzava1.find(slovo) == 0 && drzava2.find(slovo) == 0 )
        {
            p1=p1+10;
            p2=p2+10;
            goto gra;
        }
        else if (drzava1.find(slovo) == 0 && drzava2.find(slovo) != 0 )
        {
            p1=p1+20;
            goto gra;
        }
        else if (drzava2.find(slovo) == 0 && drzava1.find(slovo) != 0 )
        {
            p2=p2+20;
            goto gra;
        }
        else if (drzava2.find(slovo) != 0 && drzava1.find(slovo) != 0 )
        {
            goto gra;
        }
gra:
    cout<<"Bodovi: Igrac 1: "<<p1<<" Igrac 2: "<<p2<<endl;
            cout<<"Grad "<<endl;
        cout<<"Igrac 1: "<<endl;
        cin>> grad1;
        if (grad1 == izlaz){
                system("cls");
                goto start;}
        cout<<"Igrac 2: "<<endl;
        cin>> grad2;
        if (grad2 == izlaz){
            system("cls");
            goto start;}


        if (grad1.find(slovo) == 0 && grad2.find(slovo) == 0 )
        {
            p1=p1+10;
            p2=p2+10;
            goto sel;
        }
        else if (grad1.find(slovo) == 0 && grad2.find(slovo) != 0 )
        {
            p1=p1+20;
            goto sel;
        }
        else if (grad2.find(slovo) == 0 && grad1.find(slovo) != 0 )
        {
            p2=p2+20;
            goto sel;
        }
        else if (grad2.find(slovo) != 0 && grad1.find(slovo) != 0 )
        {
            goto sel;
        }
sel:
    cout<<"Bodovi: Igrac 1: "<<p1<<" Igrac 2: "<<p2<<endl;
            cout<<"Selo "<<endl;
        cout<<"Igrac 1: "<<endl;
        cin>> selo1;
        if (selo1 == izlaz){
                system("cls");
                goto start;}
        cout<<"Igrac 2: "<<endl;
        cin>> selo2;
        if (selo1 == izlaz){
            system("cls");
            goto start;}


        if (selo1.find(slovo) == 0 && selo2.find(slovo) == 0 )
        {
            p1=p1+10;
            p2=p2+10;
            goto ime;
        }
        else if (selo1.find(slovo) == 0 && selo2.find(slovo) != 0 )
        {
            p1=p1+20;
            goto ime;
        }
        else if (selo2.find(slovo) == 0 && selo1.find(slovo) != 0 )
        {
            p2=p2+20;
            goto ime;
        }
        else if (selo2.find(slovo) != 0 && selo1.find(slovo) != 0 )
        {
            goto ime;
        }
ime:
    cout<<"Bodovi: Igrac 1: "<<p1<<" Igrac 2: "<<p2<<endl;
            cout<<"Ime "<<endl;
        cout<<"Igrac 1: "<<endl;
        cin>> ime1;
        if (ime1 == izlaz){
                system("cls");
                goto start;}
        cout<<"Igrac 2: "<<endl;
        cin>> ime2;
        if (ime2 == izlaz){
                system("cls");
                goto start;}


        if (ime1.find(slovo) == 0 && ime2.find(slovo) == 0 )
        {
            p1=p1+10;
            p2=p2+10;
            goto ziv;
        }
        else if (ime1.find(slovo) == 0 && ime2.find(slovo) != 0 )
        {
            p1=p1+20;
            goto ziv;
        }
        else if (ime2.find(slovo) == 0 && ime1.find(slovo) != 0 )
        {
            p2=p2+20;
            goto ziv;
        }
        else if (ime2.find(slovo) != 0 && ime1.find(slovo) != 0 )
        {
            goto ziv;
        }
ziv:
    cout<<"Bodovi: Igrac 1: "<<p1<<" Igrac 2: "<<p2<<endl;
            cout<<"Zivotinja "<<endl;
        cout<<"Igrac 1: "<<endl;
        cin>> zivotinja1;
        if (zivotinja1 == izlaz){
                system("cls");
                goto start;}
        cout<<"Igrac 2: "<<endl;
        cin>> zivotinja2;
        if (zivotinja2 == izlaz){
            system("cls");
            goto start;}


        if (zivotinja1.find(slovo) == 0 && zivotinja2.find(slovo) == 0 )
        {
            p1=p1+10;
            p2=p2+10;
            goto stv;
        }
        else if (zivotinja1.find(slovo) == 0 && zivotinja2.find(slovo) != 0 )
        {
            p1=p1+20;
            goto stv;
        }
        else if (zivotinja2.find(slovo) == 0 && zivotinja1.find(slovo) != 0 )
        {
            p2=p2+20;
            goto stv;
        }
        else if (zivotinja2.find(slovo) != 0 && zivotinja1.find(slovo) != 0 )
        {
            goto stv;
        }
stv:
    cout<<"Bodovi: Igrac 1: "<<p1<<" Igrac 2: "<<p2<<endl;
            cout<<"Stvar "<<endl;
        cout<<"Igrac 1: "<<endl;
        cin>> stvar1;
        if (stvar1 == izlaz){
                system("cls");
                goto start;}
        cout<<"Igrac 2: "<<endl;
        cin>> stvar2;
        if (stvar2 == izlaz){
            system("cls");
            goto start;}


        if (stvar1.find(slovo) == 0 && stvar2.find(slovo) == 0 )
        {
            p1=p1+10;
            p2=p2+10;
            goto dgsk;
        }
        else if (stvar1.find(slovo) == 0 && stvar2.find(slovo) != 0 )
        {
            p1=p1+20;
            goto dgsk;
        }
        else if (stvar2.find(slovo) == 0 && stvar1.find(slovo) != 0 )
        {
            p2=p2+20;
            goto dgsk;
        }
        else if (stvar2.find(slovo) != 0 && stvar1.find(slovo) != 0 )
        {
            goto dgsk;
        }
dgsk:
    cout<<"Kraj."<<endl;
    if(p1 > p2){
        cout<<"Pobjednik je prvi igrac."<<endl;
    }
    else if(p1<p2){
    cout<<"Pobjednik je drugi igrac."<<endl;
    }
    else{
        cout<<"Izjednaceno."<<endl;
    }
    Sleep(5000);
    system("cls");
    goto start;
}
        if(c==izlaz){
                goto start;}
    else{
    cout<<"Ne razumijem"<<endl;
    goto igragoto;
}
}
else{
        cout<<"Ne razumijem"<<endl;
    goto start;}
}

