#include "node.h"
#include <stdio.h>
#include <algorithm>
#include <deque>
#include <QDebug>

#include "students.h"

const char* nameOfStudent1(){
    return "Mattias Odo";
}




/**************************************************************************
 * Trädklättring.
 *
 *
 **************************************************************************/

Node* testTree1(){

    // TODO Returnera det testträd som finns avbildat i uppdragshäftet.

}


void flashPreOrder(Node *pTree){
    if (pTree == nullptr)
        return;
    pTree->flash();
    flashPreOrder(pTree->m_pLeft);
    flashPreOrder(pTree->m_pRight);

}

void flashInOrder(Node *pTree){
    if (pTree == nullptr)
        return;
    flashInOrder(pTree->m_pLeft);
    pTree->flash();
    flashInOrder(pTree->m_pRight);

}

void flashPostOrder(Node *pTree){
    if (pTree == nullptr)
        return;
    flashPostOrder(pTree->m_pLeft);
    flashPostOrder(pTree->m_pRight);
    pTree->flash();
}


// Nedanstående funktion skall inte vara rekursiv.
// implementera den med hjälp av en FIFO-kö.
// Så här kan du deklarera fifo-kön:
// std::deque<Node*> que;
// så här stoppar du in ett värde i kön
// que.push_back( nodepekare );
// så här läser du det värde som ligger främst
// Node *p = que.front();
// så här avlägsnar du det främsta värdet från kön
// que.pop_front();

void flashNodesAtIncreasingDepth(Node *pTree){
    std::deque<Node*> que;
    que.push_back(pTree);                   // Stoppar in ett värde i kön.
    while(que.size() > 0){
        Node *p = que.front();              // Deklarera en nodpekare på främsta värdet i kön.
        p->flash();
        if (p->m_pLeft != nullptr)
            que.push_back(p->m_pLeft);      // Om värdet på vänster barn är skilt från nullptr så stoppas ett värde in på platsen.
        if (p->m_pRight != nullptr)
            que.push_back(p->m_pRight);     // Om värdet på höger barn är skilt från nullptr så stoppas ett värde in på platsen.
        que.pop_front();                    // Annars avlägsna främsta värdet i kön.
    }

}


// Nedanstående funktioner bör vara rekursiva.
// De kan då implementeras med några få raders kod.

int numberOfNodes(Node *pTree){
    // Funktioner bör implementeras med rekursion.
    // Funktioner bör implementeras med rekursion.
    if (pTree == nullptr)
        return 0;
    pTree->flash();
    int numLeft = numberOfNodes(pTree->m_pLeft);
    int numRight = numberOfNodes(pTree->m_pRight);
    int total = numLeft + numRight + 1;
    return total;
}

int height(Node *pTree){
    // Funktioner bör implementeras med rekursion.
    if (pTree == nullptr)
        return -1;
    pTree->flash();
    int lHeight = height(pTree->m_pLeft);
    int rHeight = height(pTree->m_pRight);
    if (rHeight > lHeight)
        return rHeight+1;
    else return lHeight+1;
}

void testfunktion1(Node *pTree){
    // frivilligt att skriva kod här
    qDebug() << "testfunktion1";
}

