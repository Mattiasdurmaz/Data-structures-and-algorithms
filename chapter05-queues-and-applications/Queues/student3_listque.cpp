#include "student3_listque.h"
#include "assert.h"


const char* nameOfStudentLQue(){
    return "Homer Simpson";
}



LQue::LQue()
{
// TODO

}

LQue::~LQue()
{

}

void LQue::pushBack(float value)
{


}

float &LQue::back()
{
    assert( m_size>0 );
    return m_pBack->m_value;

}

void LQue::popFront()
{
  assert( m_size>0 );


}

float &LQue::front()
{
    assert( m_size> 0);
    return m_pFront->m_value;
}

int LQue::size() const
{
    return m_size;
}
