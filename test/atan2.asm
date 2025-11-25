/* atan2.asm - atan2 function */

/* $Id: atan2.asm,v 1.1.1.1 2013/02/14 17:05:50 bh Exp $ */

/*
	This C language subroutine computes that arctangent
	of its floating point input.

	The Run Time Library for the C Language.

	Gordon A. Sterling	(617) 461 - 3076
	DSP Development Tools Engineering

	Created on 6/8/90
	Updated on 5/94 by AS
	Changed on 8/04 by BH for MY-14

	#include <math.h>		<Header>
	float atanf(float x);		<Prototype>
	float atan2f(float x, float y);	<Prototype>
*/

/* dm(atan2_v) = atan2(dm(atan2_y),dm(atan2_x)) */

/* CHANGES: Uses memory for parameters and result.
   The routine must NOT be interrupted. */

#include "def21060.h" /* Use symbolic register names */ 

.segment/dm     seg_dmda;
.var    atan2_y, atan2_x, atan2_v;
.global atan2_y, atan2_x, atan2_v;
.endseg;

.segment/  pm   seg_pmco ;

.global         atan2;

atan2:          bit set mode1 SRRFL|SRRFH|SRD1L|SRD1H|SRD2L|SRD2H;
                nop;
                f4 = dm(atan2_y);
                r8 = dm(atan2_x);
                m13 = 0;

                r0 = pass r4;
                r3 = pass r8;              

do_divide:      if ne jump (pc, overflow_tst);  
                r4 = pass r4;              
                if ne jump (pc, overflow);  

input_error:    jump (pc, restore_state) (db);
                f12 = 0.0;
                dm(atan2_v) = f12;

overflow_tst:   r1 = logb f4;              
                r0 = logb f8;              
                r1 = r1-r0;                
                r0 = 124;                  
                comp(r1,r0);
                if ge jump (pc, overflow);       
                r0 = -r0;
                comp(r1,r0);
                if le jump (pc, underflow);      

do_division:    call (pc, float_divide) (db);
                f11 = 2.0;                 
                f12 = pass f8, f7 = f4;      

                f0 = pass f7;

                f11 = 2.0;                 
                f0 = abs f0, r1 = m13 ;      
                f12 = 1.0;                
                comp(f0,f12);
                if le jump (pc, tst_f); 

                call (pc, float_divide) (db);
                f12 = pass f0, f7 = f12;     
                r1 = 2;                    

                f0 = pass f7;              

tst_f:          f12 = 0.26794919243112270647 ;
                comp(f0,f12);
                if le jump (pc, tst_for_eps);   
                r1 = r1+1;                 
                f8 = 0.73205080756887729353 ;
                f7 = f8*f0;                
                f8 = 0.5;
                f7 = f7-f8;                
                f7 = f7-f8;                
                f7 = f7+f0;                
                call (pc, float_divide) (db);
                f8 = 1.73205080756887729353 ;
                f12 = f8+f0;               
                
                f0 = pass f7;

tst_for_eps:    f8 = abs f0;               
                f12 = 0.000244140625 ;
                comp(f8,f12);
                if le jump (pc, tst_n);
                f8 = f0*f0;                
                f2 = -0.720026848898e+0 ;
                f7 = f8*f2;                
                f2 = -0.144008344874e+1 ;
                f7 = f7+f2;                
                f7 = f7*f8;                
                f12 =  0.475222584599e+1 ;                    
                f12 = f8+f12;              
                f12 = f12*f8, f8 = f0;       
                call (pc, float_divide) (db);  
                f2 =  0.432025038919e+1 ;                 
                f12 = f12+f2;              

                f7 = f7*f8;                
                f0 = f7+f8;                

tst_n:          r8 = 1;
                comp(r1,r8);
                if gt f0 = -f0;            
                r1 = pass r1;
                if eq jump (pc, adjust_by_an) (db);
                f12 = 0;
                r1 = r1-1;
                if eq jump (pc, adjust_by_an) (db);
                f12 = 0.52359877559829887308 ;
                r1 = r1-1;
                if eq jump (pc, adjust_by_an) (db);
                f12 = 1.57079632679489661923 ;
                r1 = r1-1;

                f12 = 1.04719755119659774615 ;
adjust_by_an:   f12 = f0+f12;
tst_sign_y:     f0 = 3.14159265358979323846 ;
                f3 = pass f3;              
                if lt f12 = f0-f12;        
tst_sign_x:     f4 = pass f4;
                if lt f12 = -f12;

                dm(atan2_v) = f12;
                                
restore_state:  bit clr mode1 SRRFL|SRRFH|SRD1L|SRD1H|SRD2L|SRD2H;
                nop;
                rts;

overflow:       jump (pc, tst_sign_x) (db);
                nop;
                f12 = 1.57079632679489661923 ;
                
underflow:      jump (pc, tst_sign_y) (db);
                nop;
                f12 = 0;


float_divide:   f0 = recips f12;               
                f12 = f0*f12;                  
                f7 = f0*f7, f0 = f11-f12;        
                f12 = f0*f12;                  
                f7 = f0*f7, f0 = f11-f12;        
                rts (db), f12 = f0*f12;        
                f7 = f0*f7, f0 = f11-f12;        
                f7 = f0*f7;                    

.endseg;
