
#ifndef __MOCKCPP_CHAINING_MOCK_HELPER_H
#define __MOCKCPP_CHAINING_MOCK_HELPER_H

#include <mockcpp.h>
#include <IsEqual.h>
#include <IsNotEqual.h>
#include <IsMirror.h>
#include <OutBound.h>
#include <OutBoundPointer.h>
#include <Any.h>

MOCKCPP_NS_START

class Matcher;
class Stub;

Matcher* once();
Matcher* never();
Matcher* atLeast(unsigned int times);
Matcher* atMost(unsigned int times);
Matcher* exactly(unsigned int times);

template <typename T>
Constraint* eq(const T& val)
{
	return new IsEqual<T>(val);
}

template <typename T>
Constraint* neq(const T& val)
{
	return new IsNotEqual<T>(val);
}

////////////////////////////////////////////////////////////////
#if 0
static inline Constraint* eq(const char* s)
{
   return new IsEqual<const char*>(s);
}
#endif

////////////////////////////////////////////////////////////////
template <typename T>
Constraint* outBound(const T& val, Constraint* constraint = 0)
{
   return new OutBound<T>(val, constraint);
}

////////////////////////////////////////////////////////////////
// outBoundP
////////////////////////////////////////////////////////////////
template <typename T>
Constraint* outBoundP(T* p, size_t size, Constraint* constraint = 0)
{
   return new OutBoundPointer<T*>(p, size, constraint);
}

////////////////////////////////////////////////////////////////
Constraint* outBoundP(void* p, size_t size, Constraint* constraint = 0);

////////////////////////////////////////////////////////////////
template <typename T>
Constraint* outBoundP(T* p, Constraint* constraint = 0)
{
   return new OutBoundPointer<T*>(p, sizeof(T), constraint);
}

///////////////////////////////////////////////////////////////////
// mirror
///////////////////////////////////////////////////////////////////
#if defined(__GNUC__) && (__GNUC__ > 3)
template <typename T>
Constraint* mirror(const T& obj)
{
   return new IsMirror<T>(obj);
}
#endif

///////////////////////////////////////////////////////////////////
template <typename T>
Constraint* mirror(T* p, size_t size = 0)
{
   return new IsMirror<T*>(p, size);
}

///////////////////////////////////////////////////////////////////
Constraint* mirror(void* p, size_t size);


///////////////////////////////////////////////////////////////////
// smirror
///////////////////////////////////////////////////////////////////
Constraint* smirror(char* s);
Constraint* smirror(const char* s);
///////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////
Stub* returnValue(const Any& val);

Stub* ignoreReturnValue();

Stub* returnObjectList( const Any& o01
                      , const Any& o02 = Any()
                      , const Any& o03 = Any()
                      , const Any& o04 = Any()
                      , const Any& o05 = Any()
                      , const Any& o06 = Any()
                      , const Any& o07 = Any()
                      , const Any& o08 = Any()
                      , const Any& o09 = Any()
                      , const Any& o10 = Any()
                      , const Any& o11 = Any()
                      , const Any& o12 = Any());



MOCKCPP_NS_END

#endif
