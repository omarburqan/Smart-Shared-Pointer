#ifndef __SHARED_POINTER_H__
#define __SHARED_POINTER_H__

#include <iostream>

template<typename T>
class SharedPtr {

	public:
		//Ctor from a raw-pointer of that type
		explicit SharedPtr(T* ptr = NULL);
		
		//Dtor
		~SharedPtr();
		
		// copy constructor
		SharedPtr(SharedPtr<T> const &);

		// copy constructor
		SharedPtr &operator=(SharedPtr<T> const &);


		//Operator ->: Member access (act like a raw ptr)
		T *operator->() const;

		//Operator *: Dereference (act like a raw ptr)
		T &operator*() const;
		
		//Allow the SharedPtr be tested for null in logical expressions
		operator bool() const; 	
		
		// Assignment from a raw-pointer of that type (type >> T)
		SharedPtr<T> &operator=(T *t);
		
		//Provide a way to get the underlying raw ptr
		T *get() const;

	private:
		T *m_ptr;
		
		unsigned int *m_counter;

};

#endif /* __SHARED_POINTER_H__ */
