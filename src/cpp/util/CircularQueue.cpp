/*
 * Copyright (C) 2002 Juan José Aguililla Martínez. Todos los derechos reservados.
 */

// P R E P R O C E S S O R //////////////////////////////////////////////////////////////
#ifndef __CIRCULAR_QUEUE_CPP
#    define __CIRCULAR_QUEUE_CPP

// I N C L U D E S //////////////////////////////////////////////////////////////////////
#include "CircularQueue.hpp"

// U S I N G ////////////////////////////////////////////////////////////////////////////
using namespace util;

// I M P L E M E N T A T I O N //////////////////////////////////////////////////////////
template < class T1 >
inline CircularQueue < T1 >::CircularQueue (int queueCapacity)
{
    capacity = queueCapacity;
    size = headIndex = tailIndex = 0;
    elements = new T1[capacity];
    orderedElements = new T1[capacity];
}

template < class T1 >
inline CircularQueue < T1 >::~CircularQueue ()
{
    delete[]elements;
    delete[]orderedElements;
}

template < class T1 >
inline void CircularQueue < T1 >::addElement (T1 element)
{
    elements[headIndex] = element;
    headIndex = ++headIndex % capacity;
    // Si despues de haber desplazado "headIndex" la cabeza y la cola son
    // iguales es que la lista está llena (el número de elementos no se altera)
    if (headIndex == tailIndex) {
        tailIndex = ++tailIndex % capacity;
    }
    else {
        size++;
    }
}

template < class T1 >
inline T1 CircularQueue < T1 >::removeElement ()
{
    if (size == 0) {
        return 0;
    }
    T1 tailValue = elements[tailIndex];

    tailIndex = ++tailIndex % capacity;
    size--;
    return tailValue;
}

template < class T1 >
inline T1 * CircularQueue < T1 >::getElements ()
{
    if (size == 0) {
        return NULL;
    }
    if (tailIndex < headIndex) {
        memcpy (orderedElements, &elements[tailIndex], size);
    }
    else if (tailIndex > headIndex) {
        int mid = capacity - tailIndex;

        memcpy (orderedElements, &elements[tailIndex], mid);
        memcpy (&orderedElements[mid], elements, headIndex);
    }
    return orderedElements;
}

template < class T1 >
inline void CircularQueue < T1 >::clear ()
{
    if (size != 0)              // Puede que no sea necesario
    {
        size = headIndex = tailIndex = 0;
    }
}

template < class T1 >
inline string CircularQueue < T1 >::toString ()
{
}

#endif
// EOF //////////////////////////////////////////////////////////////////////////////////

