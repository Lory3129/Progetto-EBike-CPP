#include<iostream>
#include<cmath>
#include <algorithm>
#include <ctime>
#include <random>
using namespace std;

int CordX;
int CordY; 

//INIZIALIZZAZIONE DELLA STRUCT:
struct Bici{
    double X;
    double Y;
    int Id;
    double Autonomia;
    bool Disponibile;
};

//ASSEGNAZIONE DEI VALORI DELLA STRUCT:
Bici BiciDisponibili[5]{
    {1, 2, 4632, 40.0, true},
    {1, 1.5, 4637, 12, false},
    {1, 1.25, 4377, 60, true},
    {2, 1, 3322, 22, false},
    {1, 1.9, 4454, 21, true}
    
};

//CALCOLO DELLA DISTANZA DALLA BICI DALL'UTENTE
int  distanza(Bici bici){
    return sqrt(pow(bici.X-CordX, 2)+pow(bici.Y-CordY, 2));
}

//
bool confronta(Bici Bici1, Bici Bici2){
    return distanza(Bici1) < distanza(Bici2);
}

int main()
{
    double Dist;
    double AutonomiaU;
    int IDx;
    double tempo;
    int velocit;
    int num_randomico=rand()%15 + 1;
    double prezzo;
    int AutonomiaR;
    velocit=20;
    cout<<"Inserisci la coordinata X di dove di trovi --> ";
    cin>>CordX;
    cout<<"Inserisci la coordinata Y di dove di trovi --> ";
    cin>>CordY;
    cout<<"Quanti chilometri vorresti percorrere? --> ";
    cin>>AutonomiaU;
    
    //ALGORITMO DI ORDINAMENTO:
    sort(BiciDisponibili, BiciDisponibili + 5, confronta );
    
    //MENU':
    cout<<"################################################################"<<endl;
    cout<<"| Bici № | Id Ebike | Autonomia (km) | Disponibile? | Distanza |"<<endl;
    for(int i=0; i<5; i++){
        if (BiciDisponibili[i].Disponibile==true){
            cout<<"|   "<<i+1
                <<"    |   "
                <<BiciDisponibili[i].Id
                <<"   |       "
                <<BiciDisponibili[i].Autonomia
                <<"       |      "
                <<BiciDisponibili[i].Disponibile
                <<"       |     " 
                <<distanza(BiciDisponibili[i]) 
                << "    |"<<endl;        }
    }
    cout<<"################################################################";
    
    //SCELTA DELLA BICI:
    cout<<"\nScegli la bici: ";
    cin>>IDx;
    
    //VERIFICA DELLE CONDIZIONI NECESSARIE PER LA SELEZIONE DELLA BICI:
    if(IDx>=1
        && IDx<=5
        && BiciDisponibili[IDx-1].Disponibile==true
        && BiciDisponibili[IDx-1].Autonomia>AutonomiaU){
        cout<<endl;
        cout << "Prenotata! ID:" << BiciDisponibili[IDx].Id << " (Distanza: " << distanza(BiciDisponibili[IDx]) << ")" << endl;
    }else{
        cout<<"Hai inserito un numero di una bici non valido !!! "<<endl;
    }
    
    //CALCOLO DEL TEMPO:
    tempo=((AutonomiaU/velocit)*60)+num_randomico;
    cout<<endl;
    
    //STATISTICHE AGGIORNATE DOPOO LA FINE DEL NOLEGGIO:
    cout<<"Il noleggio è terminato!"<<endl;
    AutonomiaR=(BiciDisponibili[IDx-1].Autonomia)-AutonomiaU;
    cout<<"L'autonomia residua della bicicletta è: "<<AutonomiaR<<endl;
    prezzo=0.20 * tempo;
    cout<<"Hai pedalato per "<<tempo<<" minuti"<<endl;
    cout<<"L'importo da pagare è: "<<prezzo<<"€";
    
}






















