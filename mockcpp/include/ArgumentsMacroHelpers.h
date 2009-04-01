
#ifndef __MOCKCPP_ARGUMENTS_MACRO_HELPERS_H
#define __MOCKCPP_ARGUMENTS_MACRO_HELPERS_H

#include <RepeatMacros.h>

#define __ARG(n) P ## n
#define END_ARGS(n) __ARG(n)
#define ARGS(n) __ARG(n) ,

#define __PARAM(n) p ## n
#define END_PARAMS(n) __PARAM(n)
#define PARAMS(n) __PARAM(n) ,

#define TEMPLATE_ARG(n) typename __ARG(n)
#define TEMPLATE_ARGS(n) , TEMPLATE_ARG(n)
#define VOID_TEMPLATE_ARGS(n) typename __ARG(n),

#define __ARG_DECL(n) __ARG(n) __PARAM(n)
#define ARG_DECL(n) __ARG_DECL(n) ,
#define END_ARG_DECL(n) __ARG_DECL(n)


#define DECL_TEMPLATE_ARGS(n) SIMPLE_REPEAT(n, TEMPLATE_ARGS)
#define DECL_VARDIC_ARGS(n) SIMPLE_REPEAT(n, ARGS)
#define DECL_VARDIC_PARAM_LIST(n) SIMPLE_REPEAT(n, ARG_DECL)
#define DECL_VOID_TEMPLATE_ARGS(n) REPEAT(n, VOID_TEMPLATE_ARGS, TEMPLATE_ARG)
#define DECL_ARGS(n) REPEAT(n, ARGS, END_ARGS)
#define DECL_PARAMS(n) REPEAT(n, PARAMS, END_PARAMS)
#define DECL_PARAMS_LIST(n) REPEAT(n, ARG_DECL, END_ARG_DECL)

#endif
