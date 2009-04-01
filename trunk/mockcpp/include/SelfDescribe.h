
#ifndef __MOCKCPP_SELF_DESCRIBE_H
#define __MOCKCPP_SELF_DESCRIBE_H

#include <mockcpp.h>
#include <string>

MOCKCPP_NS_START

class SelfDescribe
{
public:
    virtual ~SelfDescribe() {}
    virtual std::string toString() const = 0;
};

MOCKCPP_NS_END

#endif
