//------------------------------------------------------------------
//
//  FILE      : StdLithDefs.h
//
//  PURPOSE   : Defines types and stuff for StdLith files.
//
//  CREATED   : September 7 1996
//
//  COPYRIGHT : Microsoft 1996 All Rights Reserved
//
//------------------------------------------------------------------


#ifndef __STDLITHDEFS_H__
#define __STDLITHDEFS_H__


// Includes....
#ifndef __STDIO_H__
#include <stdio.h>
#define __STDIO_H__
#endif

#ifndef __STRING_H__
#include <string.h>
#define __STRING_H__
#endif

#ifndef __ASSERT_H__
#include <assert.h>
#define __ASSERT_H__
#endif

// C++11 addons since this is just freaking sad
#include <cstdint>
// These are also in sdk/incs/ltbasetypes.h, however, since the stuff in lithshared 
// should compile with out the engine, they are duplicated here
// BEGIN LTBASETYPES.H

typedef int8_t				int8;
typedef int16_t				int16;
typedef int32_t				int32;

typedef int64_t 			int64;

typedef uint8_t				uint8;
typedef uint16_t			uint16;
typedef uint32_t			uint32;
typedef uint64_t 			uint64;

typedef uint32 LTBOOL;
typedef float LTFLOAT;
typedef uint32 LTRESULT;

typedef uintptr_t PointerType;

// END LTBASETYPES.H

#ifndef ASSERT
    #define ASSERT assert
#endif

#ifndef TRUE
constexpr int TRUE = 1;
#endif

#ifndef FALSE
constexpr int FALSE = 0;
#endif

constexpr uint32 BAD_INDEX = static_cast<uint32>(-1);

#endif  // __STDLITH_DEFS_H__



