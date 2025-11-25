/* $Id: def21060.h,v 1.1.1.1 2013/02/14 17:05:50 bh Exp $ */

/* -----------------------------------------------------------------------------
def21060.h - SYSTEM AND IOP REGISTER BIT AND ADDRESS DEFINITIONS FOR ADSP-2106x
	
Last Modification on: Feb-15-95

This include file contains a list of macro defines to enable the programmer to
use symbolic names for all of the system register bits for the ADSP-2106x.
It also contains macros for the IOP register addresses and some bit fields.
Here are some example uses:

	bit set mode1 BR0|IRPTEN|ALUSTAT;

	ustat1=BSO|HPM01|HMSWF;
	dm(SYSCON)=ustat1;
----------------------------------------------------------------------------- */
 
/* MODE1 register */
#define BR8     0x00000001 /* Bit  0: Bit-reverse for I8                      */
#define BR0     0x00000002 /* Bit  1: Bit-reverse for I0 (uses DMS0- only )   */
#define SRCU    0x00000004 /* Bit  2: Alt. register select for comp. units    */
#define SRD1H   0x00000008 /* Bit  3: DAG1 alt. register select (7-4)         */
#define SRD1L   0x00000010 /* Bit  4: DAG1 alt. register select (3-0)         */
#define SRD2H   0x00000020 /* Bit  5: DAG2 alt. register select (15-12)       */
#define SRD2L   0x00000040 /* Bit  6: DAG2 alt. register select (11-8)        */
#define SRRFH   0x00000080 /* Bit  7: Register file alt. select for R(15-8)   */
#define SRRFL   0x00000400 /* Bit 10: Register file alt. select for R(7-0)    */
#define NESTM   0x00000800 /* Bit 11: Interrupt nesting enable                */
#define IRPTEN  0x00001000 /* Bit 12: Global interrupt enable                 */
#define ALUSAT  0x00002000 /* Bit 13: Enable ALU fixed-pt. saturation         */
#define SSE     0x00004000 /* Bit 14: Enable short word sign extension        */
#define TRUNCATE 0x00008000 /* Bit 15: 1=fltg-pt. truncation 0=Rnd to nearest */
#define RND32   0x00010000 /* Bit 16: 1=32-bit fltg-pt.rounding 0=40-bit rnd  */
#define CSEL	0x00060000 /* Bit 17-18: CSelect: Bus Mastership	      */

/* MODE2 register */
#define IRQ0E   0x00000001 /* Bit  0: IRQ0- 1=edge sens. 0=level sens.        */
#define IRQ1E   0x00000002 /* Bit  1: IRQ1- 1=edge sens. 0=level sens.        */
#define IRQ2E   0x00000004 /* Bit  2: IRQ2- 1=edge sens. 0=level sens.        */
#define CADIS   0x00000010 /* Bit  4: Cache disable                           */
#define TIMEN   0x00000020 /* Bit  5: Timer enable                            */
#define BUSLK   0x00000040 /* Bit  6: External bus lock                       */
#define FLG0O   0x00008000 /* Bit 15: FLAG0 1=output 0=input                  */                 
#define FLG1O   0x00010000 /* Bit 16: FLAG1 1=output 0=input                  */
#define FLG2O   0x00020000 /* Bit 17: FLAG2 1=output 0=input                  */
#define FLG3O   0x00040000 /* Bit 18: FLAG3 1=output 0=input                  */
#define CAFRZ   0x00080000 /* Bit 19: Cache freeze                            */


/* ASTAT register */
#define AZ      0x00000001 /* Bit  0: ALU result zero or fltg-pt. underflow   */
#define AV      0x00000002 /* Bit  1: ALU overflow                            */
#define AN      0x00000004 /* Bit  2: ALU result negative                     */
#define AC      0x00000008 /* Bit  3: ALU fixed-pt. carry                     */
#define AS      0x00000010 /* Bit  4: ALU X input sign (ABS and MANT ops)     */
#define AI      0x00000020 /* Bit  5: ALU fltg-pt. invalid operation          */
#define MN      0x00000040 /* Bit  6: Multiplier result negative              */
#define MV      0x00000080 /* Bit  7: Multiplier overflow                     */
#define MU      0x00000100 /* Bit  8: Multiplier fltg-pt. underflow           */
#define MI      0x00000200 /* Bit  9: Multiplier fltg-pt. invalid operation   */
#define AF      0x00000400 /* Bit 10: ALU fltg-pt. operation                  */
#define SV      0x00000800 /* Bit 11: Shifter overflow                        */
#define SZ      0x00001000 /* Bit 12: Shifter result zero                     */
#define SS      0x00002000 /* Bit 13: Shifter input sign                      */
#define BTF     0x00040000 /* Bit 18: Bit test flag for system registers      */
#define FLG0    0x00080000 /* Bit 19: FLAG0 value                             */
#define FLG1    0x00100000 /* Bit 20: FLAG1 value                             */
#define FLG2    0x00200000 /* Bit 21: FLAG2 value                             */
#define FLG3    0x00400000 /* Bit 22: FLAG3 value                             */
#define CACC0   0x01000000 /* Bit 24: Compare Accumulation Bit 0              */
#define CACC1   0x02000000 /* Bit 25: Compare Accumulation Bit 1              */
#define CACC2   0x04000000 /* Bit 26: Compare Accumulation Bit 2              */
#define CACC3   0x08000000 /* Bit 27: Compare Accumulation Bit 3              */
#define CACC4   0x10000000 /* Bit 28: Compare Accumulation Bit 4              */
#define CACC5   0x20000000 /* Bit 29: Compare Accumulation Bit 5              */
#define CACC6   0x40000000 /* Bit 30: Compare Accumulation Bit 6              */
#define CACC7   0x80000000 /* Bit 31: Compare Accumulation Bit 7              */

/* STKY register */
#define AUS     0x00000001 /* Bit  0: ALU fltg-pt. underflow                  */
#define AVS     0x00000002 /* Bit  1: ALU fltg-pt. overflow                   */
#define AOS     0x00000004 /* Bit  2: ALU fixed-pt. overflow                  */ 
#define AIS     0x00000020 /* Bit  5: ALU fltg-pt. invalid operation          */
#define MOS     0x00000040 /* Bit  6: Multiplier fixed-pt. overflow           */
#define MVS     0x00000080 /* Bit  7: Multiplier fltg-pt. overflow            */
#define MUS     0x00000100 /* Bit  8: Multiplier fltg-pt. underflow           */
#define MIS     0x00000200 /* Bit  9: Multiplier fltg-pt. invalid operation   */
#define CB7S    0x00020000 /* Bit 17: DAG1 circular buffer 7 overflow         */
#define CB15S   0x00040000 /* Bit 18: DAG2 circular buffer 15 overflow        */
#define PCFL    0x00200000 /* Bit 21: PC stack full                           */
#define PCEM    0x00400000 /* Bit 22: PC stack empty                          */
#define SSOV    0x00800000 /* Bit 23: Status stack overflow (MODE1 and ASTAT) */
#define SSEM    0x01000000 /* Bit 24: Status stack empty                      */
#define LSOV    0x02000000 /* Bit 25: Loop stack overflow                     */
#define LSEM    0x04000000 /* Bit 26: Loop stack empty                        */

/* IRPTL and IMASK and IMASKP registers */
#define RSTI    0x00000002 /* Bit  1: Offset: 04: Reset                       */
#define SOVFI   0x00000008 /* Bit  3: Offset: 0c: Stack overflow              */
#define TMZHI   0x00000010 /* Bit  4: Offset: 10: Timer = 0 (high priority)   */
#define VIRPTI  0x00000020 /* Bit  5: Offset: 14: Vector interrupt            */
#define IRQ2I   0x00000040 /* Bit  6: Offset: 18: IRQ2- asserted              */
#define IRQ1I   0x00000080 /* Bit  7: Offset: 1c: IRQ1- asserted              */
#define IRQ0I   0x00000100 /* Bit  8: Offset: 20: IRQ0- asserted              */
#define SPR0I	0x00000400 /* Bit 10: Offset: 28: SPORT0 receive DMA channel  */
#define SPR1I	0x00000800 /* Bit 11: Offset: 2c: SPORT1 receive (or LBUF0)   */
#define SPT0I	0x00001000 /* Bit 12: Offset: 30: SPORT0 transmit DMA channel */
#define SPT1I	0x00002000 /* Bit 13: Offset: 34: SPORT1 transmit (or LBUF0)  */
#define LP2I	0x00004000 /* Bit 14: Offset: 38: Link buffer 2 DMA channel   */
#define LP3I	0x00008000 /* Bit 15: Offset: 3c: Link buffer 3 DMA channel   */
#define EP0I	0x00010000 /* Bit 16: Offset: 40: External port channel 0 DMA */
#define EP1I	0x00020000 /* Bit 17: Offset: 44: External port channel 1 DMA */
#define EP2I	0x00040000 /* Bit 18: Offset: 48: External port channel 2 DMA */
#define EP3I	0x00080000 /* Bit 19: Offset: 4c: External port channel 3 DMA */
#define LSRQI	0x00100000 /* Bit 20: Offset: 50: Link service request	      */
#define CB7I    0x00200000 /* Bit 21: Offset: 54: Circ. buffer 7 overflow     */
#define CB15I   0x00400000 /* Bit 22: Offset: 58: Circ. buffer 15 overflow    */
#define TMZLI   0x00800000 /* Bit 23: Offset: 5c: Timer = 0 (low priority)    */
#define FIXI    0x01000000 /* Bit 24: Offset: 60: Fixed-pt. overflow          */
#define FLTOI   0x02000000 /* Bit 25: Offset: 64: fltg-pt. overflow           */
#define FLTUI   0x04000000 /* Bit 26: Offset: 68: fltg-pt. underflow          */
#define FLTII   0x08000000 /* Bit 27: Offset: 6c: fltg-pt. invalid            */
#define SFT0I   0x10000000 /* Bit 28: Offset: 70: user software int 0         */
#define SFT1I   0x20000000 /* Bit 29: Offset: 74: user software int 1         */
#define SFT2I   0x40000000 /* Bit 30: Offset: 78: user software int 2         */
#define SFT3I   0x80000000 /* Bit 31: Offset: 7c: user software int 3         */

/* I/O Processor Registers */
#define SYSCON 0x00	   /* System configuration register		      */
#define VIRPT  0x01	   /* Vector interrupt register			      */
#define WAIT   0x02	   /* Wait state configuration for external memory    */
#define SYSTAT 0x03	   /* System status register			      */
#define EPB0   0x04	   /* External port DMA buffer 0		      */
#define EPB1   0x05	   /* External port DMA buffer 1		      */
#define EPB2   0x06	   /* External port DMA buffer 3		      */
#define EPB3   0x07	   /* External port DMA buffer 4 		      */
#define MSGR0  0x08	   /* Message register 0			      */
#define MSGR1  0x09	   /* Message register 1			      */
#define MSGR2  0x0a	   /* Message register 2			      */
#define MSGR3  0x0b	   /* Message register 3			      */
#define MSGR4  0x0c	   /* Message register 4			      */
#define MSGR5  0x0d	   /* Message register 5			      */
#define MSGR6  0x0e	   /* Message register 6			      */
#define MSGR7  0x0f	   /* Message register 7			      */
#define BMAX   0x18	   /* Bus time-out maximum			      */
#define BCNT   0x19	   /* Bus time-out counter			      */
#define ELAST  0x1b	   /* Address of last external access for page detect */
#define DMAC6  0x1c	   /* EP DMA6 control register			      */
#define DMAC7  0x1d	   /* EP DMA7 control register			      */
#define DMAC8  0x1e	   /* EP DMA8 control register			      */
#define DMAC9  0x1f	   /* EP DMA9 control register			      */

#define II4    0x30	   /* Internal DMA4 memory address		      */
#define IM4    0x31	   /* Internal DMA4 memory access modifier	      */
#define C4     0x32	   /* Contains number of DMA4 transfers remainnig     */
#define CP4    0x33	   /* Points to next DMA4 parameters		      */
#define GP4    0x34	   /* DMA4 General purpose / 2-D DMA		      */
#define DB4    0x35	   /* DMA4 General purpose / 2-D DMA		      */
#define DA4    0x36	   /* DMA4 General purpose / 2-D DMA		      */

#define DMASTAT 0x37	   /* DMA channel status register		      */

#define II5    0x38	   /* Internal DMA5 memory address		      */
#define IM5    0x39	   /* Internal DMA5 memory access modifier	      */
#define C5     0x3a	   /* Contains number of DMA5 transfers remainnig     */
#define CP5    0x3b	   /* Points to next DMA5 parameters		      */
#define GP5    0x3c	   /* DMA5 General purpose / 2-D DMA		      */
#define DB5    0x3d	   /* DMA5 General purpose / 2-D DMA		      */
#define DA5    0x3e	   /* DMA5 General purpose / 2-D DMA		      */

#define II6    0x40	   /* Internal DMA6 memory address		      */
#define IM6    0x41	   /* Internal DMA6 memory access modifier	      */
#define C6     0x42	   /* Contains number of DMA6 transfers remainnig     */
#define CP6    0x43	   /* Points to next DMA6 parameters		      */
#define GP6    0x44	   /* DMA6 General purpose			      */
#define EI6    0x45	   /* External DMA6 address			      */
#define EM6    0x46	   /* External DMA6 address modifier		      */
#define EC6    0x47	   /* External DMA6 counter			      */

#define II7    0x48	   /* Internal DMA7 memory address		      */
#define IM7    0x49	   /* Internal DMA7 memory access modifier	      */
#define C7     0x4a	   /* Contains number of DMA7 transfers remainnig     */
#define CP7    0x4b	   /* Points to next DMA7 parameters		      */
#define GP7    0x4c	   /* DMA7 General purpose			      */
#define EI7    0x4d	   /* External DMA7 address			      */
#define EM7    0x4e	   /* External DMA7 address modifier		      */
#define EC7    0x4f	   /* External DMA7 counter			      */

#define II8    0x50	   /* Internal DMA8 memory address		      */
#define IM8    0x51	   /* Internal DMA8 memory access modifier	      */
#define C8     0x52	   /* Contains number of DMA8 transfers remainnig     */
#define CP8    0x53	   /* Points to next DMA8 parameters		      */
#define GP8    0x54	   /* DMA8 General purpose			      */
#define EI8    0x55	   /* External DMA8 address			      */
#define EM8    0x56	   /* External DMA8 address modifier		      */
#define EC8    0x57	   /* External DMA8 counter			      */

#define II9    0x58	   /* Internal DMA9 memory address		      */
#define IM9    0x59	   /* Internal DMA9 memory access modifier	      */
#define C9     0x5a	   /* Contains number of DMA9 transfers remainnig     */
#define CP9    0x5b	   /* Points to next DMA9 parameters		      */
#define GP9    0x5c	   /* DMA9 General purpose			      */
#define EI9    0x5d	   /* External DMA9 address			      */
#define EM9    0x5e	   /* External DMA9 address modifier		      */
#define EC9    0x5f	   /* External DMA9 counter			      */

#define II0    0x60	   /* Internal DMA0 memory address		      */
#define IM0    0x61	   /* Internal DMA0 memory access modifier	      */
#define C0     0x62	   /* Contains number of DMA0 transfers remainnig     */
#define CP0    0x63	   /* Points to next DMA0 parameters		      */
#define GP0    0x64	   /* DMA0 General purpose / 2-D DMA		      */
#define DB0    0x65	   /* DMA0 General purpose / 2-D DMA		      */
#define DA0    0x66	   /* DMA0 General purpose / 2-D DMA		      */

#define II1    0x68	   /* Internal DMA1 memory address		      */
#define IM1    0x69	   /* Internal DMA1 memory access modifier	      */
#define C1     0x6a	   /* Contains number of DMA1 transfers remainnig     */
#define CP1    0x6b	   /* Points to next DMA1 parameters		      */
#define GP1    0x6c	   /* DMA1 General purpose / 2-D DMA		      */
#define DB1    0x6d	   /* DMA1 General purpose / 2-D DMA		      */
#define DA1    0x6e	   /* DMA1 General purpose / 2-D DMA		      */

#define II2    0x70	   /* Internal DMA2 memory address		      */
#define IM2    0x71	   /* Internal DMA2 memory access modifier	      */
#define C2     0x72	   /* Contains number of DMA2 transfers remainnig     */
#define CP2    0x73	   /* Points to next DMA2 parameters		      */
#define GP2    0x74	   /* DMA2 General purpose / 2-D DMA		      */
#define DB2    0x75	   /* DMA2 General purpose / 2-D DMA		      */
#define DA2    0x76	   /* DMA2 General purpose / 2-D DMA		      */

#define II3    0x78	   /* Internal DMA3 memory address		      */
#define IM3    0x79	   /* Internal DMA3 memory access modifier	      */
#define C3     0x7a	   /* Contains number of DMA3 transfers remainnig     */
#define CP3    0x7b	   /* Points to next DMA3 parameters		      */
#define GP3    0x7c	   /* DMA3 General purpose / 2-D DMA		      */
#define DB3    0x7d	   /* DMA3 General purpose / 2-D DMA		      */
#define DA3    0x7e	   /* DMA3 General purpose / 2-D DMA		      */

#define LBUF0  0xc0	   /* Link buffer 0				      */
#define LBUF1  0xc1	   /* Link buffer 1				      */
#define LBUF2  0xc2	   /* Link buffer 2				      */
#define LBUF3  0xc3	   /* Link buffer 3				      */
#define LBUF4  0xc4	   /* Link buffer 4				      */
#define LBUF5  0xc5	   /* Link buffer 5				      */
#define LCTL   0xc6	   /* Link buffer control			      */
#define LCOM   0xc7	   /* Link common control			      */
#define LAR    0xc8	   /* Link assignment register			      */
#define LSRQ   0xc9	   /* Link service request and mask register	      */
#define LPATH1 0xca	   /* Link path register 1			      */
#define LPATH2 0xcb	   /* Link path register 2			      */
#define LPATH3 0xcc	   /* Link path register 3			      */
#define LPCNT  0xcd	   /* Link path counter				      */
#define CNST1  0xce	   /* Link port constant 1 register		      */
#define CNST2  0xcf	   /* Link port constant 2 register		      */

#define STCTL0	0xe0 /*Serial Port 0 Transmit Control Register          */ 
#define SRCTL0	0xe1 /*Serial Port 0 Receive  Control Register          */ 
#define TX0   	0xe2 /*Serial Port 0 Transmit Data Buffer               */ 
#define RX0   	0xe3 /*Serial Port 0 Receive Data Buffer                */ 
#define TDIV0 	0xe4 /*Serial Port 0 Transmit Divisor                   */ 
#define TCNT0 	0xe5 /*Serial Port 0 Transmit Count Reg                 */ 
#define RDIV0 	0xe6 /*Serial Port 0 Receive Divisor                    */ 
#define RCNT0 	0xe7 /*Serial Port 0 Receive Count Reg                  */ 
#define MTCS0 	0xe8 /*Serial Port 0 Mulitchannel Transmit Selector     */ 
#define MRCS0 	0xe9 /*Serial Port 0 Mulitchannel Receive Selector      */ 
#define MTCCS0	0xea /*Serial Port 0 Mulitchannel Transmit Selector     */ 
#define MRCCS0	0xeb /*Serial Port 0 Mulitchannel Receive Selector      */ 
#define SPATH0	0xee /*Serial Port 0 Path Length (Mesh Multiprocessing) */
#define SPCNT0	0xef /*Serial Port 0 Path Counter (Mesh Multiprocessing)*/

#define STCTL1	0xf0 /*Serial Port 1 Transmit Control Register          */
#define SRCTL1	0xf1 /*Serial Port 1 Receive  Control Register          */
#define TX1   	0xf2 /*Serial Port 1 Transmit Data Buffer               */
#define RX1   	0xf3 /*Serial Port 1 Receive Data Buffer                */
#define TDIV1 	0xf4 /*Serial Port 1 Transmit Divisor                   */
#define TCNT1 	0xf5 /*Serial Port 1 Transmit Count Reg                 */
#define RDIV1 	0xf6 /*Serial Port 1 Receive Divisor                    */
#define RCNT1 	0xf7 /*Serial Port 1 Receive Count Reg                  */
#define MTCS1 	0xf8 /*Serial Port 1 Mulitchannel Transmit Selector     */
#define MRCS1 	0xf9 /*Serial Port 1 Mulitchannel Receive Selector      */
#define MTCCS1	0xfa /*Serial Port 1 Mulitchannel Transmit Selector     */
#define MRCCS1	0xfb /*Serial Port 1 Mulitchannel Receive Selector      */
#define SPATH1	0xfe /*Serial Port 1 Path Length (Mesh Multiprocessing) */
#define SPCNT1	0xff /*Serial Port 1 Path Counter (Mesh Multiprocessing)*/


/* SYSCON Register */
#define SYSCON 0x00	   /* Memory mapped System Configuration Register     */
#define SRST   0x00000001  /* Soft Reset				      */
#define BSO    0x00000002  /* Boot Select Override			      */
#define IIVT   0x00000004  /* Internal Interrupt Vector Table		      */
#define IWT    0x00000008  /* Instruction word transfer (0 = data, 1 = inst)  */
#define HPM00  0x00000000  /* Host packing mode: None			      */
#define HPM01  0x00000010  /* Host packing mode: 16/32			      */
#define HPM10  0x00000020  /* Host packing mode: 16/48			      */
#define HPM11  0x00000030  /* Host packing mode: 32/48			      */
#define HMSWF  0x00000040  /* Host packing order (0 = LSW first, 1 = MSW)     */
#define HPFLSH 0x00000080  /* Host pack flush				      */
#define IMDW0X 0x00000100  /* Internal memory block 0, extended data (40 bit) */
#define IMDW1X 0x00000200  /* Internal memory block 1, extended data (40 bit) */

#define EBPR00 0x00000000  /* External bus priority: Even		      */
#define EBPR01 0x00010000  /* External bus priority: Core has priority	      */
#define EBPR10 0x00020000  /* External bus priority: IO has priority	      */

#define DCPR   0x00040000  /* Select rotating access priority on DMA6 - DMA9  */

#define IMGR   0x10000000  /* Internal memory block grouping (for the MSP)    */

/* SYSTAT Register */
#define SYSTAT 0x03	   /* Memory mapped System Status Register	      */
#define HSTM   0x00000001  /* Host is the Bus Master			      */
#define BSYN   0x00000002  /* Bus arbitration logic is synchronized	      */
#define CRBM   0x00000070  /* Current ADSP2106x Bus Master		      */
#define IDC    0x00000700  /* ADSP2106x ID Code				      */
#define DWPD   0x00001000  /* Direct write pending (0 = none, 1 = pending)    */
#define VIPD   0x00002000  /* Vector interrupt pending (1 = pending)	      */
#define HPS    0x0000c000  /* Host pack status				      */








