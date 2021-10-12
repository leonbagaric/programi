#include <stdio.h>
#include <iostream>

using namespace std;

int main()
{
        int slbr,pogbr;
        std::string i1,i2;
        int trenutniigrac = 1;
        std::cout<<"Upisi ime prvog igraca: "<<std::endl;
        std::cin>>i1;
        std::cout<<"Upisi ime drugog igraca: "<<std::endl;
        std::cin>>i2;


        slbr = rand() % 100;
        std::cout << "Slucajni broj je odabran: "<<std::endl;
        pogodibr:
        if(trenutniigrac == 1){
            std::cout << "Upisi broj "<<i1<<std::endl;
        }
        else if(trenutniigrac == 2){
            std::cout << "Upisi broj "<<i2<<std::endl;
        }

        std::cin >> pogbr;

        if (pogbr < slbr){
            std::cout << "Trazeni broj je veci od tvog broja"<<std::endl;
            if(trenutniigrac==1){
                trenutniigrac=2;
            }
            else if(trenutniigrac==2){
                trenutniigrac=1;
            }
            goto pogodibr;
        }
        else if (pogbr > slbr){
            std::cout << "Trazeni broj je manji od tvog broja"<<std::endl;
            if(trenutniigrac==1){
                trenutniigrac=2;
            }
            else if(trenutniigrac==2){
                trenutniigrac=1;
            }
            goto pogodibr;
        }
        else if(pogbr==slbr){
            if(trenutniigrac == 1){
                std::cout <<i1<<" pobjeduje!"<<std::endl;
        }
            if(trenutniigrac == 2){
                std::cout <<i2<<" pobjeduje!"<<std::endl;
            }
        }

    return 0;
}
