#ifndef PORZADKOWE_HH
#define PORZADKOWE_HH

#include <vector>
#include <iostream>
#include <fstream>
#include <math.h>
#include <memory>
#include <ctime>
#include <string>
#include <cstring>

using namespace std;

void raport_do_pliku(int time[4][5],int VERCISE,string sciezka)
{
    ofstream zapis(sciezka);
    zapis << "raport dla " << VERCISE << " wierzcholkow"<< endl;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cout << time[i][j] << endl;
        } 
    }
    zapis.close();
    cout << "poprawnie zostało zapisane" << endl;
}










    // if (a == 1)
    // {
    //     zapis << "raport po sortowaniu tablic nie posortowanych:" << endl;
    //     // zapis << "dla " << k << " tablic o dlugosci " << zmienna << " elementow:" << endl;
    //     zapis << "shella \t"
    //           << "scalanie \t"
    //           << "quicksort \t" << endl;
    //     for (int i = 0; i < 6; i++)
    //     {
    //         zapis << czas_sh[i] << "\t" << czas_s[i] << "\t" << czas_q[i] << "\t" << endl;
    //     }
    // }
    // if (a == 2)
    // {
    //     zapis << "raport po sortowaniu tablic w " << procent * 100 << "% posortowanych" << endl;
    //     // zapis << "dla " << k << " tablic o dlugosci " << zmienna << " elementow:" << endl;
    //     zapis << "shella \t"
    //           << "scalanie \t"
    //           << "quicksort \t" << endl;
    //     for (int i = 0; i < 5; i++)
    //     {
    //         zapis << czas_sh[i] << "\t" << czas_s[i] << "\t" << czas_q[i] << "\t" << endl;
    //     }
    // }
    // if (a == 3)
    // {
    //     zapis << "raport po sortowaniu tablic posortowanych od tyłu:" << endl;
    //     // zapis << "dla " << k << " tablic o dlugosci " << zmienna << " elementow:" << endl;
    //     zapis << "shella \t"
    //           << "scalanie \t"
    //           << "quicksort \t" << endl;
    //     for (int i = 0; i < 5; i++)
    //     {
    //         zapis << czas_sh[i] << "\t" << czas_s[i] << "\t" << czas_q[i] << "\t" << endl;
    //     }
    // }
//     zapis.close();
// }
// string stworz_nazwe(int a){
//     string lp = to_string(a);        
//     string napis = "txt/posortowane";  
//     napis = napis+lp;
//     napis = napis+".txt";
//     return napis;
// }
#endif
