#ifndef ERROR_H
#define ERROR_H

/** **********************************************************************
** Module:  Error \file error.h
** Description: This module implements the ERROR abstraction.
************************************************************************/

/*
 * This work was supported by the United States Government, and is
 * not subject to copyright.
 *
 * $Log: error.h,v $
 * Revision 1.8  1997/01/21 19:16:55  dar
 * made C++ compatible
 * ,.
 *
 * Revision 1.7  1993/10/15  18:49:23  libes
 * CADDETC certified
 *
 * Revision 1.5  1993/02/22  21:44:34  libes
 * ANSI compat fixes
 *
 * Revision 1.4  1992/08/18  17:15:40  libes
 * rm'd extraneous error messages
 *
 * Revision 1.3  1992/06/08  18:07:35  libes
 * prettied up interface to print_objects_when_running
 */

#include <sc_export.h>
#include "basic.h"  /* get basic definitions */
#include <setjmp.h>

/*************/
/* constants */
/*************/

#define ERROR_none      (Error)NULL
#define ERROR_MAX       100

/*****************/
/* packages used */
/*****************/

#include "alloc.h"
#include "symbol.h"

/************/
/* typedefs */
/************/

typedef enum {
    SEVERITY_WARNING    = 0,
    SEVERITY_ERROR  = 1,
    SEVERITY_EXIT   = 2,
    SEVERITY_DUMP   = 3,
    SEVERITY_MAX    = 4
} Severity;

/***************************/
/* hidden type definitions */
/***************************/

typedef struct Error_ {
    bool enabled;
    Severity    severity;
    char  * message;
    int serial; /* used to give each type of error a unique identifier */
} * Error;

typedef struct Error_Warning_ {
    char  * name;
    struct Linked_List_ * errors;
} * Error_Warning;

/****************/
/* modules used */
/****************/

/********************/
/* global variables */
/********************/

extern SC_EXPRESS_EXPORT bool __ERROR_buffer_errors;
extern SC_EXPRESS_EXPORT const char * current_filename;

/* flag to remember whether non-warning errors have occurred */
extern SC_EXPRESS_EXPORT bool ERRORoccurred;


extern SC_EXPRESS_EXPORT Error experrc;
extern SC_EXPRESS_EXPORT Error ERROR_subordinate_failed;
extern SC_EXPRESS_EXPORT Error ERROR_syntax_expecting;

/* all of these are 1 if true, 0 if false switches */
/* for debugging fedex */
extern SC_EXPRESS_EXPORT int ERRORdebugging;
/* for debugging malloc during resolution */
extern SC_EXPRESS_EXPORT int malloc_debug_resolve;
/* for debugging yacc/lex */
extern SC_EXPRESS_EXPORT int debug;

extern SC_EXPRESS_EXPORT struct Linked_List_ * ERRORwarnings;
extern SC_EXPRESS_EXPORT struct freelist_head ERROR_OPT_fl;

extern SC_EXPRESS_EXPORT void ( *ERRORusage_function )( void );

/******************************/
/* macro function definitions */
/******************************/

#define ERROR_OPT_new() (struct Error_Warning_ *)ALLOC_new(&ERROR_OPT_fl)
#define ERROR_OPT_destroy(x)    ALLOC_destroy(&ERROR_OPT_fl,(Freelist *)x)

/***********************/
/* function prototypes */
/***********************/

extern SC_EXPRESS_EXPORT void ERROR_start_message_buffer( void );
extern SC_EXPRESS_EXPORT void ERROR_flush_message_buffer( void );

/********************/
/* Inline functions */
/********************/

static inline void ERRORdisable( Error error ) {
    if( error != ERROR_none ) {
        error->enabled = false;
    }
}

static inline void ERRORenable( Error error ) {
    if( error != ERROR_none ) {
        error->enabled = true;
    }
}

static inline bool ERRORis_enabled( Error error ) {
    return error->enabled;
}

static inline void ERRORbuffer_messages( bool flag ) {
    __ERROR_buffer_errors = flag;
    if( __ERROR_buffer_errors ) {
        ERROR_start_message_buffer();
    } else {
        ERROR_flush_message_buffer();
    }
}

static inline void ERRORflush_messages( void ) {
    if( __ERROR_buffer_errors ) {
        ERROR_flush_message_buffer();
        ERROR_start_message_buffer();
    }
}


/***********************/
/* function prototypes */
/***********************/

extern SC_EXPRESS_EXPORT void ERRORinitialize( void );
extern SC_EXPRESS_EXPORT void ERRORinitialize_after_LIST( void );
extern SC_EXPRESS_EXPORT void ERRORcleanup( void );
extern SC_EXPRESS_EXPORT void ERRORnospace( void );
extern SC_EXPRESS_EXPORT void ERRORabort( int );
extern SC_EXPRESS_EXPORT Error    ERRORcreate( char *, Severity );
extern SC_EXPRESS_EXPORT void ERRORreport( Error, ... );
extern SC_EXPRESS_EXPORT void ERRORdestroy( Error );

struct Symbol_; /* mention Symbol to avoid warning on following line */
extern SC_EXPRESS_EXPORT void ERRORreport_with_symbol( Error, struct Symbol_ *, ... );
extern SC_EXPRESS_EXPORT void ERRORreport_with_line( Error, int, ... );

extern SC_EXPRESS_EXPORT void ERRORcreate_warning( char *, Error );
extern SC_EXPRESS_EXPORT void ERRORset_warning( char *, int );
extern SC_EXPRESS_EXPORT void ERRORset_all_warnings( int );
extern SC_EXPRESS_EXPORT void ERRORsafe( jmp_buf env );
extern SC_EXPRESS_EXPORT void ERRORunsafe( void );

#endif /* ERROR_H */
