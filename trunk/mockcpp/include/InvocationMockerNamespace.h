
#ifndef __MOCKCPP_INVOCATION_MOCKER_NAMESPACE_H
#define __MOCKCPP_INVOCATION_MOCKER_NAMESPACE_H

#include <mockcpp.h>

#include <string>

MOCKCPP_NS_START

struct InvocationMocker;

struct InvocationMockerNamespace
{
   virtual InvocationMocker* getInvocationMocker(const std::string& id) const = 0;
   virtual std::string& getName(void) const = 0;

   virtual ~InvocationMockerNamespace() {}
};

MOCKCPP_NS_END

#endif

