#include "student3swaps.h"
#include "dalgorandom.h"

#include <iostream>
using namespace std;

const char* nameOfTheStudent3() {
    return "Mattias Odo";  // Byt ut denna sträng mot ditt eget namn!
}


// ################ Implementera swap med pekar- och referensanrop #################



// ANROP:   swap(a,b); eller swap( (&a), (&b) );
// UPPGIFT: Byter värden mellan a och b.
void swap(float* pA, float* pB) {


    float temp;
    temp = *pA;
    *pA = *pB;
    *pB = temp;



}


// ANROP:   swap(a,b); eller swap((a), (b));
// UPPGIFT: Byter värden mellan a och b.
void swap(float& a, float& b) {

    float temp;
    temp = a;
    a = b;
    b = temp;

    // TODO

}


// För att öva på referenser ger jag här en
// lite annorluna implementerting av max.
float& max(float& a, float& b) {
    if (a > b)
        return a;
    return b;
}



void testaMax() {
    float a = 42;
    float b = 108;

    cout << "maximum is " << max(a, b) << endl;

    max(a, b) = 1;

    cout << "a=" << a << " , b=" << b << endl;

    /* OBS! Förklara vad ovanstående max(a,b) = 1 gör, och varför!
     * Först så läser max anropet a och b värdarna och returnerar den högsta vilket är då b eftetsom de har värdet 108 och när de returnera
     * b värdet så blir max(a, b) = b, men så ser vi på rad 63 att max(a, b)= 1 vilket innebär att de största värdet ska bli ett. b var
     * största värdet så de blir b=1 vilket leder till att b har värdet 1 istället för 108.
     */

}

void studentsTest3() {

    // TODO! Skriv din testkod här
    // Testa båda dina swap versioner
}



void mainFunctionInStudent3() {

    cout << "\n\n\n################ testingCode3 #################\n\n";

    studentsTest3();
    testaMax();
}

