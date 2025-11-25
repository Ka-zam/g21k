#ifndef _AOUTHDR_H
#define _AOUTHDR_H

typedef struct aouthdr
{
    short   magic;	    /* magic number */
    short   vstamp;	    /* version stamp */
    int    tsize;	    /* text size in bytes (COFF: 32-bit) */
    int    dsize;	    /* initialized data size (COFF: 32-bit) */
    int    bsize;	    /* uninitialized data size (COFF: 32-bit) */
    int    entry;	    /* entry point (COFF: 32-bit) */
    int    text_start;	    /* base of text used for this file (COFF: 32-bit) */
    int    data_start;	    /* base of data used for this file (COFF: 32-bit) */
} AOUTHDR;


#define AOUTSZ sizeof(AOUTHDR)

#endif

