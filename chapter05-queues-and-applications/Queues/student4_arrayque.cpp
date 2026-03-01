#include "student4_arrayque.h"
#include "assert.h"

const char* nameOfStudentAQue(){
    return "Mattias Odo";
}



AQue::AQue()
{
    m_capacity = 10;
    m_pArr = new float[m_capacity];
    m_indexOfFront = 0;
    m_size = 0;

}

AQue::~AQue()
{
    delete [] m_pArr;
    m_pArr = nullptr;

}


void AQue::pushBack(float value)
{
    assert(m_size < m_capacity);

    m_pArr[(m_indexOfFront+m_size) % m_capacity] = value;
    m_size++;

}

float &AQue::back()
{
    assert(m_size > 0);
    return m_pArr[(m_indexOfFront+m_size-1) % m_capacity];


}

void AQue::popFront()
{
    assert(m_size > 0);
    m_indexOfFront = (m_indexOfFront +1) % m_capacity;
    m_size --;

}

float &AQue::front()
{
    assert(m_size > 0);
    return m_pArr[m_indexOfFront];

}


int AQue::size() const
{
    return m_size;

}
