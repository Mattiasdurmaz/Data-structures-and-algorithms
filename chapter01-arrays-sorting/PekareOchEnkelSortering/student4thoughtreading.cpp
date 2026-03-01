#include "student4thoughtreading.h"
#include <iostream>
using namespace std;




// ################ MAGI! Förklara hur tankeläsningen fungerar! #################

void tankPaEttTal() {
    int x = 108;
    cout << "Denna funktion tanker pa ett hemligt tal" << endl;

}

void tankelasning() {
    int  hemligheten;
    cout << "Denna funktion tror att den andra funktionens hemlighet ar " << hemligheten << endl;
}

void experimentMedTankeoverforing() {
    cout << "Experiment med tankeoverforing!\n";
    cout << "(studera utskrifterna sa att du kan forklara dem i kommentaren)\n\n";
    tankPaEttTal();
    tankelasning();


    /* TODO
       Förklaring:

       I det här fallet kommer datorn att tilldela lite oanvänt minne till hemligheten.
       Det kommer sedan att skicka värdet som finns på den minnesplatsen till cout<<"denna.... , som kommer att skriva ut värdet (tolkat som ett heltal).
       Men vilket värde kommer den att skriva ut? Svaret är "vem vet!", och svaret kan eller kanske inte ändras varje gång du kör programmet.
       När man kör det här programmet i Visual Studio så skrevs  värdet 7177728 en gång och 5277592 nästa.

     */
}




void mainFunctionInStudent4() {

    cout << "\n\n\n################ testingCode4 #################\n\n";

    experimentMedTankeoverforing();

}
