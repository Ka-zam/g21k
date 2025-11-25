
struct lineno
{
    union                       /* if l_lnno == 0... */
    {
	int    l_symndx;       /* then use l_symndx (COFF: 32-bit) */
	int    l_paddr;        /* else use l_paddr (COFF: 32-bit) */
    } l_addr;
    unsigned short  l_lnno;     /* line number */
} PACKED;

#define     LINENO  struct lineno
#define     LINESZ  sizeof(LINENO)

