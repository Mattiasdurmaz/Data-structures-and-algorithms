#include "student2stackl.h"
#include <assert.h>
#include <iostream>

using namespace std;

const char* nameOfStudent2(){
    return "Mattias Odo";
}

StackL::StackL(){
// TODO
    m_pTop = nullptr;
    m_size=0;
}


StackL::StackL(const StackL& theOther){
// TODO
    m_size = theOther.m_size;
    m_pTop = nullptr;
    
    Link *pPreviousLink = nullptr;
    
    for(Link *pOtherLink = theOther.m_pTop; pOtherLink != nullptr;
        pOtherLink = (*pOtherLink).m_pNext){
        Link *pCopy = new Link;
        
        pCopy->m_data = pOtherLink->m_data;
        pCopy->m_pNext = nullptr;
        if(pPreviousLink == nullptr)
            m_pTop = pCopy;
        else pPreviousLink->m_pNext = pCopy;
        pPreviousLink=pCopy;
    }
    
}

StackL::~StackL(){
// TODO
    while ( m_size > 0 )
        pop();
    assert( m_pTop == nullptr );
    assert( m_size == 0 );
}

void StackL::push(float value){
// TODO
    Link *pNewTop = new Link;
    (*pNewTop).m_data = value;
    (*pNewTop).m_pNext = m_pTop;
    m_pTop = pNewTop;
    m_size += 1;
}

void StackL::pop(){
// TODO
    
    Link *pOldTop = m_pTop;
    m_pTop = (*pOldTop).m_pNext;
    m_size -= 1;
    delete pOldTop;
}


float StackL::top() const {
// TODO
    assert( m_size > 0 );
    return (*m_pTop).m_data;

}
int StackL::size() const {
// TODO
    return m_size;
}


void studentTest2(){

     cout << endl << endl <<  "studentTest2..." << endl;

    // Skriv din egen testkod här
}

