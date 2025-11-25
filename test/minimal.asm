/* minimal.asm - smallest SHARC assembly test */

.segment/pm seg_pmco;

.global test;

test:
    nop;
    rts;

.endseg;
