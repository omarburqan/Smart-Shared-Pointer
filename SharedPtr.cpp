#include "SharedPtr.h"
#include "gtest/gtest.h"


template<typename T>
SharedPtr<T>::SharedPtr(T *ptr): m_ptr(ptr) {
    m_ptr = ptr; 
    m_counter = new unsigned int(); 
    if (ptr) { 
    	++(*m_counter); 
    } 
}

template<typename T>
SharedPtr<T>::~SharedPtr() {
    --(*m_counter); 
    if (*m_counter == 0) { 
        delete m_counter; 
        delete m_ptr; 
    }
}

template<typename T>
SharedPtr<T>::SharedPtr(SharedPtr<T> const &other) {
    m_counter = other.m_counter;
    m_ptr = other.m_ptr;
    ++(*m_counter);
}

template<typename T>
SharedPtr<T> &SharedPtr<T>::operator=(SharedPtr<T> const &other) {
    if (!*m_counter) { // delete checks if null before delete so it safe not to use this condition
        delete m_ptr;
        delete m_counter;
    }
    m_counter = other.m_counter;
    m_ptr = other.m_ptr;
    return *this;
}

template<typename T>
T *SharedPtr<T>::operator->() const {
    return m_ptr;
}

template<typename T>
T &SharedPtr<T>::operator*() const {
    return *m_ptr;
}

template<typename T>
SharedPtr<T>::operator bool() const {
    return m_ptr != NULL;
}

template<typename T>
SharedPtr<T> &SharedPtr<T>::operator=(T *ptr) {
    if (m_ptr != ptr) {
        if (!*m_counter) {
            delete m_ptr;
            delete m_counter;
        }
        m_counter = new unsigned int();
        m_ptr = ptr;
    }
    return *this;
}

template<typename T>
T *SharedPtr<T>::get() const {
    return m_ptr;
}


















