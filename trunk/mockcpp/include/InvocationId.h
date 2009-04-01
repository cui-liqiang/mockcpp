
#ifndef __MOCKCPP_INVOCATION_ID_H
#define __MOCKCPP_INVOCATION_ID_H

#include <mockcpp.h>
#include <string>

MOCKCPP_NS_START

class InvocationId
{
public:
    InvocationId(const std::string& identity);
    std::string getId(void) const;
    std::string toString(void) const;

private:
    std::string id;
};

MOCKCPP_NS_END

#endif

