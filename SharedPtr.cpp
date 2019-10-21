#include "SharedPtr.h"
#include "gtest/gtest.h"


template<typename T>
SharedPtr<T>::SharedPtr(T *ptr): m_ptr(ptr) {
    m_counter = new size_t;
    *m_counter = 1;
}

template<typename T>
SharedPtr<T>::~SharedPtr() {
    --(*m_counter);
    if (!*m_counter) {
        delete m_ptr;
        delete m_counter;
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
   //--(*m_counter);
    if (!*m_counter) {
        delete m_ptr;
        delete m_counter;
    }
    m_counter = other.m_counter;
    m_ptr = other.m_ptr;
   //++(*m_counter);
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
    return bool(m_ptr);
}

template<typename T>
T *SharedPtr<T>::get() const {
    return m_ptr;
}





















