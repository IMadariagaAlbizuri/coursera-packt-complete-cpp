#include "integer.h"

/*Note: We need to define a Destructor. As some resources are being
used, to free them, we need the destructor.*/

Integer::Integer(){
    m_pInt = new int(0);
}

Integer::Integer(int value){
    m_pInt = new int(value);
}

int Integer::GetValue() const{
    return *m_pInt;
}

void Integer::SetValue(int value){
    *m_pInt=value;
}

Integer::~Integer(){
    delete m_pInt;
}

//This is DEEP COPY
Integer::Integer(Integer &obj){
    m_pInt= new int(*obj.m_pInt);
}