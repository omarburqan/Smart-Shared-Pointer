C++ shared pointer.
A class template named SharedPtr.
The class have the following API:
*	Ctor from a raw-pointer of that type
*	Assignment from a raw-pointer of that type
*	Operator *: Dereference (act like a raw ptr)
*	Operator ->: Member access (act like a raw ptr)
*	Provide a way to get the underlying raw ptr
*	Allow the SharedPtr be tested for null in logical expressions – e.g. if(sp1) 
The class should hold a pointer acquired using new(), and allow sharing it, assuring that once no one uses that ptr any more, the held object will be deleted.

Assuming that Der inherits Base, allow a SharedPtr<Base> to be initialized (or assigned from) a SharedPtr<Der> - like a raw ptr does.
