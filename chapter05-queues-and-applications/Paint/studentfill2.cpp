// OBS OBS OBS OBS OBS OBS
// Denna fil tillhör INTE rekursionslabbarna, utan en senare laboration!!!!





#include "studentfill2.h"
#include <QDebug>
#include <deque>   // double-ended-que, har du tillåtelse att använda här!

using namespace std;


const char* nameOfStudent2(){
    return "Mattias Odo";
}

// Nedanstående struct kan användas för att lagra koordinater
struct RK {
    RK(int r, int k): _r(r),_k(k) {}
    int _r;
    int _k;
};


// Denna metod visar bara hur man använder en sk deque
void exempelkodDemonstrerarDeque(){

    deque<RK> minQueue;


    qDebug() <<"Demo: vi använder minQueue som en STACK";
    qDebug() <<"      med push_back back och pop_back";

    minQueue.push_back( RK(0,0) );
    minQueue.push_back( RK(1,10) );
    minQueue.push_back( RK(2,20) );

    while (!minQueue.empty()) {
       RK rk = minQueue.back();
       minQueue.pop_back();
       qDebug() << "vi poppar: (" << rk._r << ", " << rk._k << ")";
    }

    qDebug() <<"Demo: vi använder nu minQueue som en FIFO";
    qDebug() <<"      med push_back front och pop_front";

    minQueue.push_back( RK(0,0) );
    minQueue.push_back( RK(1,10) );
    minQueue.push_back( RK(2,20) );

    while (!minQueue.empty()) {
       RK rk = minQueue.front();
       minQueue.pop_front();
       qDebug() << "vi pop_frontar: (" << rk._r << ", " << rk._k << ")";
    }

}



void nonRecursiveFillStack(int r, int k, IDrawingParent *im, QColor colorOld, QColor colorNew){

    if(colorOld==colorNew)
            return;

        deque<RK> todo;
        todo.push_back(RK(r,k));
        while(todo.size()>0){
            RK rk = todo.back(); // front
            todo.pop_back(); // back

            int r = rk._r;
            int k = rk._k;

            if((*im).isInside(r, k) && (*im).pixel(r, k) == colorOld){
                (*im).setPixel(r, k, colorNew);

                todo.push_back(RK(r, k+1)); // skickar in grannar
                todo.push_back(RK(r+1, k));
                todo.push_back(RK(r, k-1));
                todo.push_back(RK(r-1, k));
            }
        }

}


void nonRecursiveFillFifo(int r, int k, IDrawingParent *im, QColor colorOld, QColor colorNew){

    if(colorOld==colorNew)
            return;

        deque<RK> todo;
        todo.push_back(RK(r,k));
        while(todo.size()>0){
            RK rk = todo.front();
            todo.pop_front();

            int r = rk._r;
            int k = rk._k;

            if((*im).isInside(r, k) && (*im).pixel(r, k) == colorOld){
                (*im).setPixel(r, k, colorNew);

                todo.push_back(RK(r, k+1));
                todo.push_back(RK(r+1, k));
                todo.push_back(RK(r, k-1));
                todo.push_back(RK(r-1, k));
            }


    }
}
