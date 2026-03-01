
#include "studentArrayrekursioner.h"
#include <cassert>
#include <iostream>
#include <random>

using namespace std;


std::string nameOfStudent(){
    return "Homer ";  // TODO andra till ditt namn!
}



float sum(const float *pBegin, const float *pEnd){
    if(pBegin >=pEnd)
        return 0;
    return *pBegin + sum(pBegin+1,pEnd);


}


void fillValue(float value,  float *pBegin,  float *pEnd){
       if(!(pBegin>=pEnd)){
           *pBegin =value;
           fillValue(value,pBegin+1,pEnd);
       }
       // TODO

}
bool hasValueInRange(float min, float max, const float *pBegin, const float *pEnd){
 if((pBegin>=pEnd)){
     return false;
 }

else if(*pBegin < max && min <= *pBegin){
     return true;
 }

else
    return hasValueInRange(min,max,pBegin+1,pEnd);

}

int numberOfValuesInRange(float min, float max, const float *pBegin, const float *pEnd){
    if((pBegin>=pEnd)){
        return 0;
    }
    if(*pBegin < max && min <= *pBegin){
         return 1+numberOfValuesInRange(min,max,pBegin+1,pEnd);
     }
    else
        return numberOfValuesInRange(min,max,pBegin+1,pEnd);
}



void studentTest(){

}


// ------------


