#include "student2_arrstack.h"
#include <assert.h>

const char* nameOfStudentAStack(){
    return "MAttias Odo";
}



AStack::AStack()
{
    m_capacity = 10;
    m_size = 0;
    m_pArr = new float[m_capacity];
}

AStack::~AStack()
{
    delete [] m_pArr;
}

void AStack::pushBack(float value)
{
    if (m_size == m_capacity){
        m_capacity = m_size*2;
        float *pCopy = new float[m_capacity];
        for (int i=0; i<m_size; i+=1)
        {
            pCopy[i] = m_pArr[i];
        }
        delete [] m_pArr;
        m_pArr = pCopy;
    }
    m_pArr[m_size] = value;
    m_size += 1;
}


float &AStack::back()
{
    return m_pArr[m_size-1];
}

void AStack::popBack()
{
    m_size -= 1;
}

int AStack::size() const
{
    return m_size;
}




void studentTest2(){
    AStack stack1;

    stack1.pushBack(3);
    stack1.pushBack(9);
    stack1.pushBack(2);
    stack1.pushBack(5.5);

    stack1.popBack();



}

/******** kommentar som efterfrågades i "öka istället linjärt"

  blev det någon skillnad när du ökade arraystorleken med 10 istället för med dubbleing?

  Stacken blir lågnsam



 ***********************************************************************/
