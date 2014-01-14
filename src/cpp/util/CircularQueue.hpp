/*
 * Copyright (C) 2002 Juan José Aguililla Martínez. Todos los derechos reservados.
 */

// P R E P R O C E S S O R //////////////////////////////////////////////////////////////
#ifndef __CIRCULAR_QUEUE_HPP
#    define __CIRCULAR_QUEUE_HPP

// I N C L U D E S //////////////////////////////////////////////////////////////////////
#include <string>

// N A M E S P A C E ////////////////////////////////////////////////////////////////////
namespace util {

// U S I N G ///////////////////////////////////////////////////////////////////////////////////////
using namespace std;

// C L A S S E S //////////////////////////////////////////////////////////////////////////
/**
 * Cola circular implementada en un array.
 * @todo Crear una versión para longs
 * @author Juan Jose Aguililla Martinez
 */
template < class T1 > class CircularQueue {
    protected:
    /** Capacidad de la cola (numero de elementos del array). */
    int capacity;
    /** Número de elementos almacenados en la cola. */
    int size;
    /** Datos almacenados en la cola. */
    T1 elements[];
    /** Datos almacenados en la cola. */
    T1 orderedElements[];
    /** Indice del principio de la cola. */
    int headIndex;
    /** Indice del final de la cola. */
    int tailIndex;

    public:
    /**
     * Constructor.
     */
    CircularQueue (int queueCapacity = 32);

    /**
     * Destructor.
     */
    ~CircularQueue ();

    /**
     * .
     */
    void addElement (T1 element);

    /**
     * No deberia ser una referencia, al sobreescribirse el valor en la cola, cambiará
     * también en la referencia guardada.
     */
    T1 removeElement ();

    /**
     * .
     */
    T1 head () {
        return elements[headIndex - 1];
    }

    /**
     * .
     */
    T1 tail () {
        return elements[tailIndex];
    }

    /**
     * .
     */
    int getSize () {
        return size;
    }

    /**
     * .
     */
    T1 *getElements ();

    /**
     * .
     */
    void clear ();

    /**
     * .
     */
    string toString ();
};

};

#endif
// EOF //////////////////////////////////////////////////////////////////////////////////
