

#include "node.h"
#include <stdio.h>
#include <algorithm>
#include <deque>
#include <QDebug>
#include "students.h"


const char* nameOfStudent2(){
    return "Mattias Odo";
}

/**************************************************************************
 * Sökträd.
 *
 *
 **************************************************************************/

void insertKeyToSearchtree(Node*& pTree, int key){
    pTree->flash();
    if (pTree == nullptr)
        pTree = new Node(key, nullptr, nullptr);        // Om värdet *pTree pekar på är nullptr, skapa en ny nod med key som värde och inga barn.
    else if (key < pTree->m_key)
        insertKeyToSearchtree((pTree->m_pLeft), key);   // Annars om key är mindre än värdet som pTree pekar på, rekursera ett steg till vänster barn.
    else if (key > pTree->m_key)
        insertKeyToSearchtree((pTree->m_pRight), key);  // Annars om key är större än värdet som pTree pekar på, rekursera ett steg till höger barn.
}

bool contains(Node *pTree, int key){
    if (pTree == nullptr)
        return false;
    pTree->flash();
    if (key > pTree->m_key)
        return contains(pTree->m_pRight, key);      // Om key > värdet som pTree pekar på, rekursera ett steg åt höger.
    if (key < pTree->m_key)
        return contains(pTree->m_pLeft, key);       // Om key < värdet som pTree pekar på, rekursera ett steg åt vänster.
    return true;}


Node* nodeWithMinimumKey(Node *pTree){

    // Enligt anvisning bör du ej göra den rekursiv
    // (så att ni inte skriver av min god på alla uppgifter)

    if (pTree == nullptr)
        return nullptr;
    while (pTree != nullptr) {
        if (pTree->m_pLeft == nullptr)
            return pTree;
        pTree = pTree->m_pLeft;
    }
    return 0;
}

void removeKeyFromSearchtree(Node* &pTree, int key){
    if (pTree == nullptr)
        return;
    else if (key < pTree->m_key)
        removeKeyFromSearchtree((pTree->m_pLeft), key);                         // Om key < värdet som pTree pekar på, rekursera åt vänster.
    else if (key > pTree->m_key)
        removeKeyFromSearchtree((pTree->m_pRight), key);                        // Om key > värdet som pTree pekar på, rekursera åt höger.
    else if (pTree->m_pLeft == nullptr || pTree->m_pRight == nullptr){
        Node *pOldNode = pTree;                                                 // Om något av barnen är nullptr, deklarera en ny nodpekare,
        pTree = (pTree->m_pLeft != nullptr? pTree->m_pLeft: pTree->m_pRight);   // och ge pTree flyttas ner till ett av barnen.
        delete pOldNode;                                                        // Ta bort pekaren.
    }
    else {
        pTree->m_key = nodeWithMinimumKey(pTree->m_pRight)->m_key;              // Annars får det som pTree pekar på värdet av nodeWithMinimumKey,
        removeKeyFromSearchtree((pTree->m_pRight), pTree->m_key);               // och rekursera ett steg åt höger
    }
}

/*** redogörelse för experiment ***************************************

  Hur stort blir trädets höjd respektive genomsnittliga
   djup om man stoppar in 255 element (gör flera experiment om det går)?


  TODO...

  höjden är = .. 17, 13, 14, 14

  de medelvärde djup = ... 8.93, 7.91, 7.98, 7.75

  (gör flera experiment)

   OBS på Windowsmaskiner kan det vara svårt att utföra flera olika experiment.


  varför är det genomsnittliga djupet intressant? ...

  Det genomsnittliga djupet är intressant eftersom att det berättar hur lång tid det tar att söka igenom trädet.

  Om trädet skulle varit så jämnt som möjligt då hade djupet varit O(ln(n)) där n är antal noder i trädet.


 ******************************************************************************/



void testfunktion2(Node *pTree){
    qDebug() << "testfunktion2";

    // frivilligt att skriva kod här
}
