
#ifndef __MOCKPP_REF_ANY_H
#define __MOCKPP_REF_ANY_H

#include <mockcpp.h>

#include <AnyBase.h>
#include <RefHolder.h>

MOCKCPP_NS_START

struct RefAny : public AnyBase
{
public: 

   RefAny() {}

   template <typename ValueType>
   RefAny(const ValueType& value)
      : AnyBase(new RefHolder<ValueType>(value))
   {}

   RefAny(const char* value)
      : AnyBase(new RefHolder<const char*>(value))
   {}

   RefAny(const RefAny & other)
      : AnyBase(other.getContent() ? other.getContent()->clone() : 0)
   {}

public:

   template<typename ValueType>
   RefAny& operator=(const ValueType & rhs)
   {
      RefAny(rhs).swap(*this);
      return *this;
   }

   RefAny& operator=(const RefAny & rhs)
   {
      RefAny(rhs).swap(*this);
      return *this;
   }

	template <typename ValueType>
   bool changeValue(const ValueType& val)
   {
      RefHolder<ValueType>* p = dynamic_cast<RefHolder<ValueType>*>(getContent());
      if (p == 0)
      {
			return false;
		}

      p->changeValue(val);

      return true;
   }
};

/////////////////////////////////////////////////////
/////////////////////////////////////////////////////
const RefAny EmptyRefAny;

inline RefAny& getEmptyRefAny()
{
    return const_cast<RefAny&>(EmptyRefAny);
}
/////////////////////////////////////////////////////

MOCKCPP_NS_END


#endif // __MOCKPP_REF_ANY_H

