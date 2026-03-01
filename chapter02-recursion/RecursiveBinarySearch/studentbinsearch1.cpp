#include "studentbinsearch1.h"

#include "ragnarstest.h"
#include <cassert>

#include <iostream>
using namespace std;


const char* nameOfStudent1(){
    return "Mattias Odo";
}


/****************************************************************
ANROP:    bool exist = containedInSortedarray(x, pBegin, pEnd);
VERSION:  ...
UPPGIFT:  Returnerar true omm *p==x för något p i
          intervallet [pBegin, pEnd), dvs pBegin <= p < pEnd
          (observera att pEnd skall peka på första elementet efter arrayen)
OBS:      Alla tal mellan pBegin och pEnd måste vara sorterade i
          stigande ordning
*****************************************************************/
bool containedInSortedarray(int x, const int* pBegin, const int* pEnd)
{
    if((pBegin>=pEnd)){
        return false;
    }
    int size = pEnd - pBegin;
    const int *pMid =pBegin+size/2;
    if(size==1)
    {
        if(x==*pBegin){
            return true;
        }
        else
            return false;
    }
    else if(*pMid==x){
        return true;
    }
    else if(*pMid < x){
        return containedInSortedarray(x,pMid,pEnd);
    }
    else
        return containedInSortedarray(x,pBegin,pMid);


}// contains




void studentsTest1(){

    cout << "Har borde studentens testresultat synas" << endl << endl;

   // TODO din egen testkod som anropar contains här
}
