#include "student1.h"
#include <cassert>
#include "ragnarstest1.h"
#include "dalgorandom.h"

#include <iostream>
using namespace std;


// Läs Detta!

// Pekaruppdragen går ut på att implementera nedastående funktioner
// Många funktioner skall implementeras på två olika sätt (I och P):
// Version I: Räkna ut size och använd arraynotation med hakparanteser och heltalsindex.
// Version P: Använd istället pekarnotation, dvs  *p,  p+=1,  etc.




// ************************************************************
// ANROP:   char* namn = nameOfStudent1();
// UPPGIFT: Returnerar ditt namn!
// ************************************************************
const char* nameOfTheStudent1(){
    return "Mattias Odo";  // Byt ut denna sträng mot ditt eget namn!
}




// ################ version I, löses med [ ]  och indexnotation #############



// ************************************************************
// ANROP:   float value = minimumI(&arr[0], &arr[size]);
// UPPGIFT: Returnerar arrayens minsta värde
// ************************************************************
float minimumI(const float *pBegin, const float *pEnd){

    // Jag låter min egen lösnin ligga kvar.
    // Förstå denna! Lös de andra uppgifterna själv.

    assert( pBegin < pEnd );

    int size = pEnd - pBegin;
    float extreme = pBegin[0];
    for (int i=0; i<size ; i+=1)
        if (pBegin[i]<extreme)
            extreme = pBegin[i];
    return extreme;
}


// ************************************************************
// ANROP:   float value = maximumI( &arr[0], &arr[size] );
// UPPGIFT: Returnerar arrayens största värde
// ************************************************************
float maximumI(const float *pBegin, const float *pEnd){

    assert(pBegin < pEnd);
    int i;
    int size = pEnd - pBegin;
    float max = pBegin[0];

    for (i = 1; i < size;i++)
        if (pBegin[i] > max)
            max = pBegin[i];
    cout << "Största värdet i arrayI är: " << max << "\n" << endl;
    return max;

}


// ************************************************************
// ANROP:   float value = sumI( &arr[0], &arr[size] );
// UPPGIFT: Returnerar summan av alla element.
// ************************************************************
float sumI(const float *pBegin, const float *pEnd){

    assert(pBegin < pEnd);
    int size = pEnd - pBegin;
    int i;
    float sum = 0;

    for (i = 0; i < size; i++)
    {
        sum = sum + pBegin[i];
    }

    cout << "Total summan i arrayI är: " << sum << "\n" << endl;
    return sum;

}


// ************************************************************
// ANROP:   fillRandomI( &arr[0], &arr[size] );
// UPPGIFT: Fyller arrayen med oberoende slumpdata
// ************************************************************
void fillRandomI(float *pBegin, float *pEnd){
    assert(pBegin < pEnd);
    int size = pEnd - pBegin;
    int i;

    for (i = 0; i < size; i++)
    {
        pBegin[i] = rand() % 1000;
    }

    for (int i = 0; i < size; i++)
        cout << "Random nummer i array " << i + 1 << ":" << pBegin[i] << endl;


}

// ************************************************************
// ANROP:   fillSortedRandomI( &arr[0], &arr[size] );
// UPPGIFT: Fyller arrayen med sorterat slumpdata. Minst först
// ************************************************************
void fillSortedRandomI(float *pBegin, float *pEnd){
    int size = pEnd - pBegin;
    int i;
    pBegin[0] = rand() % 1000;
    for (i = 0; i < size; i++) {
        pBegin[i] = pBegin[i - 1] + rand() % 1000;
    }
    for (int i = 0; i < size; i++)
        cout << "Random nummer i array " << i + 1 << ":" << pBegin[i] << endl;
}



// ************************************************************
// ANROP:   bool contains = hasValueInRangeI(min, max, &arr[0], &arr[size] );
// UPPGIFT: Returnerar true om arrayen ett värde i det halvt öppna intervallet min <= x < max.
// ************************************************************
bool  hasValueInRangeI(float min, float max, const float *pBegin, const float *pEnd){

}

// ************************************************************
// ANROP:   int number = numberOfValuesInRange(min, max,  &arr[0], &arr[size] );
// UPPGIFT: Returnerar antalet värden som ligger i det halvt öppna intervallet  min <= x < max.
// ************************************************************
int numberOfValuesInRangeI(float min, float max, const float *pBegin, const float *pEnd){

}



// ################ version P, samma uppgifter löses nu med pekarnotation  ###############






float minimumP(const float *pBegin, const float *pEnd){
    // Jag låter min egen lösnin ligga kvar.
    // Förstå denna! Lös de andra uppgifterna själv.

    assert( pBegin < pEnd );
    float extreme = *pBegin;
    for (const float *p=pBegin ; p<pEnd; p+=1)
        if (*p<extreme)
            extreme = *p;
    return extreme;
}


float maximumP(const float *pBegin, const float *pEnd){
    assert(pBegin < pEnd);
    float max = *pBegin;

    for (const float* p = pBegin; p < pEnd; p += 1)
        if (*p > max)
            max = *p;

    cout << "Största värdet i arrayP är: " << max << "\n" << endl;
    return max;

}

float sumP(const float *pBegin, const float *pEnd){
    assert(pBegin < pEnd);
      float sum = 0;

      for (const float* p = pBegin; p < pEnd; p += 1)
      {
          sum += *pBegin;
      }

      cout << "Total summan i arrayP är: " << sum << "\n" << endl;
      return sum;

}

void fillRandomP(float *pBegin, float *pEnd){
    assert(pBegin < pEnd);
       int size = pEnd - pBegin;


       for (const float* p = pBegin; p < pEnd; p += 1)
       {
           *pBegin = rand() % 1000;
       }

       for (int i = 0; i < size; i++)
           cout << "Random nummer i array " << i + 1 << ":" << pBegin[i] << endl;

}



void fillSortedRandomP(float *pBegin, float *pEnd){
    int size = pEnd - pBegin;

    pBegin[0] = rand() % 1000;
    for (const float* p = pBegin; p < pEnd; p += 1) {
        *pBegin = *pBegin - 1 + rand() % 1000;
    }
    for (int i = 0; i < size; i++)
        cout << "Random nummer i array " << i + 1 << ":" << pBegin[i] << endl;
}


bool hasValueInRangeP(float min, float max, const float *pBegin, const float *pEnd){
    // TODO

}


int  numberOfValuesInRangeP(float min, float max, const float *pBegin, const float *pEnd){
    // TODO


}


// ################ Skriv din egen testkod här! #################


void studentsTest1(){

    // Testa själv dina funktioner här!
    // Det är OBLIGATRORISKT att anropa varje funktion som du själv
    // implementeratrat,  så att labansvarig kan se att du förstått hur funktionerna skall
    // anropas!

    // Helst bör du också skriva kod som verifierar att dina funktioner
    // returnerar korrekta resultat för vissa exempeel på indata.
    // Istället för att skriva ut ett felmedelande på skärmen bör du se
    // till så att programmet kraschar om det innehåller ett fel!
    // Man kan göra detta genom att anropa:
    //   assert( false );
    // Men istället för att skriva:
    // if (!isOk) // om inte okay..
    //    assert( false );  // ..krascha programmet!
    // Bör man skriva:
    //   assert( isOk );
    // Ännu bättre... Istället för att skriva isOK kan man skriva ett uttryck som
    // blir true eller false, exempelvis (förutsatt att arr[0]==1 och arr[1]==2)
    //   assert( averageElementP(&arr[0],  &arr[2]) == 1.5 );



    cout << "(dina egna tester borde komma har!)\n";
    nameOfTheStudent1();

}




void mainFunctionInStudent1(){

    cout << "\n\n\n################ testingCode1 ################# \n\n";

    studentsTest1();


}


