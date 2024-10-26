#pragma once

// Types Library Compiled Setting
#define USING_STDLIB 1                  // Disable types that end with _t (Should be disabled by default, if stdlib.c is in use it will give errors, but if needed set the value to 0)
#define DISABLE_BOOL_DECLARATIONS 0     // Disables every boolean declaration (Set to 1 if using C++)
#define USE_ENUM_FOR_BOOLEAN_TYPE 1     // To Check
// Types Library Compiled Setting

#define TYPES_LIB_VERSION_MAJOR 1
#define TYPES_LIB_VERSION_MINOR 0
#define TYPES_LIB_VERSION_PATCH 0

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;
//typedef 
typedef signed char i8;
typedef short i16;
typedef int i32;
typedef long long i64;
typedef float f32;
typedef double f64;
typedef long double f128;

#if !USING_STDLIB
typedef u8  uint8_t;
typedef u16 uint16_t;
typedef u32 uint32_t;
typedef u64 uint64_t;
typedef i8  int8_t;
typedef i16 int16_t;
typedef i32 int32_t;
//typedef i64 int64_t;
#endif

#define ARRAY_SIZE(arr) (sizeof(arr)/sizeof(arr[0]))
//#define ARRAY_POINTER_SIZE(arr) (sizeof(&arr)/sizeof(arr[0]))

#if !DISABLE_BOOL_DECLARATIONS
    #ifndef bool 
        #if !USE_ENUM_FOR_BOOLEAN_TYPE
            typedef u8 bool;
            #ifndef true
                #define true 1
            #endif // true
            #ifndef false
                #define false 0
            #endif // true
        #else
            enum boolean { FALSE, TRUE };
            typedef enum boolean bool;
        #endif // USE_ENUM_FOR_BOOLEAN_TYPE
    #endif // !
#endif