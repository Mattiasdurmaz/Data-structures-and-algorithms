#include "student1cstackl.h"
#include <assert.h>
#include <iostream>

using namespace std;

const char* nameOfStudent1(){
    return "Mattias Odo";
}

CStackL  CStackLConstruct(){
   // Jag lämnar kvar denna implementering
    CStackL theStack;
    theStack.m_pTop = nullptr;
    theStack.m_size = 0;
    return theStack;
}




CStackL  CStackLConstruct(const CStackL &other){
// TODO
    CStackL theStack;
    theStack.m_size = other.m_size;
    theStack.m_pTop = nullptr;

    Link *pPreviousLink = nullptr;

    for (const Link *pOthLnk=other.m_pTop; pOthLnk!=nullptr; pOthLnk=(*pOthLnk).m_pNext){
        Link *pCopy = new Link;
        (*pCopy).m_data = (*pOthLnk).m_data;
        (*pCopy).m_pNext = nullptr;
        if (pPreviousLink==nullptr)
            theStack.m_pTop = pCopy;
        else (*pPreviousLink).m_pNext = pCopy;
        pPreviousLink = pCopy;
    }
    return theStack;
}



void   CStackLDestruct(CStackL *pDettaObjekt){
// TODO
    while (CStackLSize(pDettaObjekt) > 0)
        CStackLPop(pDettaObjekt);
    assert( (*pDettaObjekt).m_pTop == nullptr );
    assert( (*pDettaObjekt).m_size == 0 );
}

void   CStackLPush(CStackL *pDettaObjekt, float data){
// TODO
    
    Link *pNewTop = new Link;
    (*pNewTop).m_data=data;
    (*pNewTop).m_pNext=(*pDettaObjekt).m_pTop;
    (*pDettaObjekt).m_pTop=pNewTop;
    (*pDettaObjekt).m_size += 1;
}


float  CStackLTop(CStackL *pDettaObjekt){
    assert( pDettaObjekt->m_size > 0 );
    return (*(*pDettaObjekt).m_pTop).m_data;
}


void CStackLPop(CStackL *pDettaObjekt){
// TODO
    Link *pOldTop = (*pDettaObjekt).m_pTop;
    (*pDettaObjekt).m_pTop = (*pOldTop).m_pNext;
    (*pDettaObjekt).m_size -= 1;
    delete pOldTop;

}

int  CStackLSize(CStackL *pDettaObjekt){
    return (*pDettaObjekt).m_size;
}

// ----- Din testkod

void studentTest1(){

     cout << endl << endl << "studentTest1..." << endl ;
    // Skriv din egen testkod här
}

