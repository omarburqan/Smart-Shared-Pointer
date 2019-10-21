#ifndef __SHARED_POINTER_H__
#define __SHARED_POINTER_H__

#include <iostream>

template<typename T>
class SharedPtr {

	public:
		explicit SharedPtr(T *ptr);

		~SharedPtr();
		
		SharedPtr(SharedPtr<T> const &); // copy constructor

		SharedPtr &operator=(SharedPtr<T> const &); // copy assignment

		T *operator->() const;

		T &operator*() const;

		operator bool() const; // logical expressions	
		
		T *get() const;

	private:
		T *m_ptr;
		
		size_t *m_counter;

};

#endif /* __SHARED_POINTER_H__ */
