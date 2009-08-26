/***
    mockcpp is a generic C/C++ mock framework.
    Copyright (C) <2009>  <Darwin Yuan: darwin.yuan@gmail.com>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
***/

#ifndef __MOCKCPP_MOCK_OBJECT_H
#define __MOCKCPP_MOCK_OBJECT_H

#include <algorithm>

#include <mockcpp/mockcpp.h>
#include <mockcpp/TypeString.h>
#include <mockcpp/MockObjectBase.h>
#include <mockcpp/DelegatedMethodGetter.h>
#include <mockcpp/InterfaceInfo.h>
#include <mockcpp/DestructorChecker.h>
#include <mockcpp/OutputStringStream.h>
#include <mockcpp/Asserter.h>

MOCKCPP_NS_START

////////////////////////////////////////////////////////////////
template <typename Interface>
struct MockObject : public MockObjectBase
{
   /////////////////////////////////////////////////////////////
	MockObject()
		: MockObjectBase(TypeString<Interface>::value()
      , getNumberOfVtbls<Interface>()
      , typeid(Interface))
	{
      identifyDestructor<Interface, Interface>();
   }

   /////////////////////////////////////////////////////////////
   ~MockObject()
   {
   }

   /////////////////////////////////////////////////////////////
   operator Interface* ()
   {
      return (Interface*)toPointerToInterface();
   }

   /////////////////////////////////////////////////////////////
   Interface* operator->()
   {
      return (Interface*)toPointerToInterface();
   }

   /////////////////////////////////////////////////////////////
   template <typename TargetInterface>
   void mightBeUsedAs()
   {
      TargetInterface* target = \
         dynamic_cast<TargetInterface*>
             ((Interface*)toPointerToInterface());
      if(target == 0)
      {
         oss_t oss;
         oss << TypeString<Interface>::value()
             << " can not be used as "
             << TypeString<TargetInterface>::value()
             << ".";

         MOCKCPP_FAIL(oss.str());
      }

      identifyDestructor<TargetInterface, Interface>();
   }

   /////////////////////////////////////////////////////////////
   void willBeDeleted()
   {
      expectsBeingDeleted();
   }

   /////////////////////////////////////////////////////////////
   void willKeepAlive()
   {
      expectsKeepAlive();
   }

   void reset()
   {
      MockObjectBase::reset();
      identifyDestructor<Interface, Interface>();
   }
   /////////////////////////////////////////////////////////////
	template <typename Method>
   InvocationMockBuilderGetter method(Method m, const char* name = 0)
   {
     std::string methodName(name == 0 ? \
         TypeString<Method>::value():name);

     unsigned int vptrIndex = getVptrIndex(m);
     unsigned int vtblIndex = getVtblIndex(m);

     void * addr = getDelegatedFunction<Interface, Method>( \
         vptrIndex, vtblIndex, m);

     return createInvocationMockerBuilderGetter(
               methodName, addr, vptrIndex, vtblIndex);
	}

////////////////////////////////////////////////////////////////
// Template methods: it's ugly, but we have to make them visible.
private:

   template <typename T, typename Original>
   void identifyDestructor()
   {
      std::pair<unsigned int, unsigned int> indices = \
         getIndexOfDestructor<T, Original>();

      setDestructor(indices.first, indices.second);
   }

   template <typename Method>
   void* getAddrOfDelegatedMethod(Method m)
   { return getAddrOfMethod(m); }

   template <typename Method>
   unsigned int getVptrIndex(Method m)
   { return getDeltaOfMethod<Interface, Method>(m); }

   template <typename Method>
   unsigned int getVtblIndex(Method m)
   { return getIndexOfMethod<Interface, Method>(m); }

};

MOCKCPP_NS_END

#endif
