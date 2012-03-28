;************************************************************************************
;*                                                                                  *
;*  file name   : definition of M16C/10s SFR                                      *
;*                                                                                  *
;*  Copyright   : MITSUBISHI ELECTRIC CORPORATION                                   *
;*                                                                                  *
;*  Version     : 1.00 (2001-4-10)						*
;*		  1.01 (2001- 6-20) modified cm20/cm21/cm22/cm23			*
;*        1.02 (2001-12-26) modified tys/tzs/tysc/typr/tzsc/tzpr/txs/u0c0/u1c0/ad/da*
;*                                   p2_2~7/pd2_2~7/pu05                            *
;************************************************************************************
;
;  note:
;   This data is a freeware that SFR for M16C/10 groups is described.
;   Mitsubishi Electric Corporation assumes no responsibility for any damage
;   that occurred by this data.
;
;-------------------------------------------------------
;   Processor mode register 0
;-------------------------------------------------------
pm0         .equ        0004h
;
pm03        .btequ      3,pm0       ; Software reset bit
;
;-------------------------------------------------------
;   Processor mode register 1
;-------------------------------------------------------
pm1         .equ        0005h
;
pm12        .btequ      2,pm1       ; WDT interrupt/reset select bit
;
;-------------------------------------------------------
;   System clock control register 0
;-------------------------------------------------------
cm0         .equ        0006h
;
cm02        .btequ      2,cm0       ; WAIT peripheral function clock stop bit
cm03        .btequ      3,cm0       ; Xcin-Xcout drive capacity select bit
cm04        .btequ      4,cm0       ; Port Xc select bit
cm05        .btequ      5,cm0       ; Main clock stop bit
cm06        .btequ      6,cm0       ; Main clock division select bit 0
cm07        .btequ      7,cm0       ; System clock select bit
;
;-------------------------------------------------------
;   System clock control register 1
;-------------------------------------------------------
cm1         .equ        0007h
;
cm10        .btequ      0,cm1       ; All clock stop control bit
cm13        .btequ      3,cm1       ; Xin RC select bit
cm14        .btequ      4,cm1       ; Ring clock stop bit
cm15        .btequ      5,cm1       ; Xin-Xout drive capacity select bit
cm16        .btequ      6,cm1       ; Main clock division select bit 1
cm17        .btequ      7,cm1       ; Main clock division select bit 1
;
;-------------------------------------------------------
;   Address match interrupt enable register
;-------------------------------------------------------
aier        .equ        0009h
;
aier0       .btequ      0,aier      ; Address match interrupt 0 enable bit
aier1       .btequ      1,aier      ; Address match interrupt 1 enable bit
;
;-------------------------------------------------------
;   Protect register
;-------------------------------------------------------
prcr        .equ        000ah
;
prc0        .btequ      0,prcr      ; Enable writting to cm0 and cm1 and cm2 
prc1        .btequ      1,prcr      ; Enable writting to pm0 and pm1
prc2        .btequ      2,prcr      ; Enable writting to port P0 direction register
;
;-------------------------------------------------------
;   Xin detect register
;-------------------------------------------------------
cm2         .equ        000ch
;
cm20        .btequ      0,cm2       ; Xin detect bit
cm21        .btequ      1,cm2       ; Xin detect interrupt enable bit
cm22        .btequ      2,cm2       ; Main clock Xin/Ring select bit
cm23        .btequ      3,cm2       ; Xin-Xout clock monitor bit
;
;-------------------------------------------------------
;   Watchdog timer
;-------------------------------------------------------
wdts        .equ        000eh       ; Watchdog timer start register
;
wdc         .equ        000fh       ; Watchdog timer control register
;
wdc7        .btequ      7,wdc       ; Prescaler select bit
;
;-------------------------------------------------------
;   Address match interrupt register 0
;-------------------------------------------------------
rmad0       .equ        0010h
rmad0l      .equ        rmad0       ; Address match interrupt register 0L
rmad0m      .equ        rmad0+1     ; Address match interrupt register 0M
rmad0h      .equ        rmad0+2     ; Address match interrupt register 0H
;
;-------------------------------------------------------
;   Address match interrupt register 1
;-------------------------------------------------------
rmad1       .equ        0014h
rmad1l      .equ        rmad1       ; Address match interrupt register 1L
rmad1m      .equ        rmad1+1     ; Address match interrupt register 1M
rmad1h      .equ        rmad1+2     ; Address match interrupt register 1H
;
;-------------------------------------------------------
;   INT0 input filter select register
;-------------------------------------------------------
int0f       .equ        001eh
int0f0		.btequ		0,int0f		; int0 input filter select bit 0
int0f1		.btequ		1,int0f		; int0 input filter select bit 1
int0f2		.btequ		2,int0f		; uart1 receive h/w interrupt enable bit
;
;-------------------------------------------------------
;   Interrupt control registers
;-------------------------------------------------------
kupic           .equ    004dh       ; Key input interrupt control register
ilvl0_kupic     .btequ  0,kupic     ; Interrupt priority level select bit
ilvl1_kupic     .btequ  1,kupic     ;
ilvl2_kupic     .btequ  2,kupic     ;
ir_kupic        .btequ  3,kupic     ; Interrupt request bit
;
adic            .equ    004eh       ; A-D interrupt control register
ilvl0_adic      .btequ  0,adic      ; Interrupt priority level select bit
ilvl1_adic      .btequ  1,adic      ;
ilvl2_adic      .btequ  2,adic      ;
ir_adic         .btequ  3,adic      ; Interrupt request bit
;
s0tic           .equ    0051h       ; UART0 transmit interrupt control register
ilvl0_s0tic     .btequ  0,s0tic     ; Interrupt priority level select bit
ilvl1_s0tic     .btequ  1,s0tic     ;
ilvl2_s0tic     .btequ  2,s0tic     ;
ir_s0tic        .btequ  3,s0tic     ; Interrupt request bit
;
s0ric           .equ    0052h       ; UART0 receive interrupt control register
ilvl0_s0ric     .btequ  0,s0ric     ; Interrupt priority level select bit
ilvl1_s0ric     .btequ  1,s0ric     ;
ilvl2_s0ric     .btequ  2,s0ric     ;
ir_s0ric        .btequ  3,s0ric     ; Interrupt request bit
;
s1tic           .equ    0053h       ; UART1 transmit interrupt control register
ilvl0_s1tic     .btequ  0,s1tic     ; Interrupt priority level select bit
ilvl1_s1tic     .btequ  1,s1tic     ;
ilvl2_s1tic     .btequ  2,s1tic     ;
ir_s1tic        .btequ  3,s1tic     ; Interrupt request bit
;
s1ric           .equ    0054h       ; UART1 receive interrupt control register
ilvl0_s1ric     .btequ  0,s1ric     ; Interrupt priority level select bit
ilvl1_s1ric     .btequ  1,s1ric     ;
ilvl2_s1ric     .btequ  2,s1ric     ;
ir_s1ric        .btequ  3,s1ric     ; Interrupt request bit
;
t1ic           	.equ    0055h       ; Timer 1
ilvl0_t1ic 	    .btequ  0,t1ic     ; Interrupt priority level select bit
ilvl1_t1ic  	.btequ  1,t1ic     ;
ilvl2_t1ic     	.btequ  2,t1ic     ;
ir_t1ic        	.btequ  3,t1ic     ; Interrupt request bit
;
txic           	.equ    0056h       ; Timer X
ilvl0_txic     	.btequ  0,txic   	; Interrupt priority level select bit
ilvl1_txic     	.btequ  1,txic     	;
ilvl2_txic     	.btequ  2,txic     	;
ir_txic        	.btequ  3,txic     	; Interrupt request bit
;
tyic           	.equ    0057h       ; Timer Y
ilvl0_tyic     	.btequ  0,tyic     	; Interrupt priority level select bit
ilvl1_tyic     	.btequ  1,tyic     	;
ilvl2_tyic     	.btequ  2,tyic     	;
ir_tyic        	.btequ  3,tyic     	; Interrupt request bit
;
tzic           	.equ    0058h       ; Timer Z
ilvl0_tzic     	.btequ  0,tzic     	; Interrupt priority level select bit
ilvl1_tzic     	.btequ  1,tzic     	;
ilvl2_tzic     	.btequ  2,tzic     	;
ir_tzic        	.btequ  3,tzic     	; Interrupt request bit
;
cntr0ic         .equ    0059h       ; CNTR0 Timer
ilvl0_cntr0ic   .btequ  0,cntr0ic  	; Interrupt priority level select bit
ilvl1_cntr0ic   .btequ  1,cntr0ic   ;
ilvl2_cntr0ic   .btequ  2,cntr0ic   ;
ir_cntr0ic      .btequ  3,cntr0ic   ; Interrupt request bit
;
tcinic           .equ    005ah      ; Timer Cin
ilvl0_tcinic     .btequ  0,tcinic	; Interrupt priority level select bit
ilvl1_tcinic     .btequ  1,tcinic   ;
ilvl2_tcinic     .btequ  2,tcinic   ;
ir_tcinic        .btequ  3,tcinic   ; Interrupt request bit
;
tcic           	.equ    005bh       ; Timer C
ilvl0_tcic     	.btequ  0,tcic     	; Interrupt priority level select bit
ilvl1_tcic     	.btequ  1,tcic     	;
ilvl2_tcic     	.btequ  2,tcic     	;
ir_tcic        	.btequ  3,tcic     	; Interrupt request bit
;
int3ic          .equ    005ch       ; INT3
ilvl0_int3ic    .btequ  0,int3ic    ; Interrupt priority level select bit
ilvl1_int3ic    .btequ  1,int3ic    ;
ilvl2_int3ic    .btequ  2,int3ic    ;
ir_int3ic       .btequ  3,int3ic    ; Interrupt request bit
;
int0ic          .equ    005dh       ; INT0
ilvl0_int0ic    .btequ  0,int0ic    ; Interrupt priority level select bit
ilvl1_int0ic    .btequ  1,int0ic    ;
ilvl2_int0ic    .btequ  2,int0ic    ;
ir_int0ic       .btequ  3,int0ic    ; Interrupt request bit
pol_int0ic      .btequ  4,int0ic    ; Polarity select bit
;
int1ic          .equ    005eh       ; INT1
ilvl0_int1ic    .btequ  0,int1ic    ; Interrupt priority level select bit
ilvl1_int1ic    .btequ  1,int1ic    ;
ilvl2_int1ic    .btequ  2,int1ic    ;
ir_int1ic       .btequ  3,int1ic    ; Interrupt request bit
pol_int1ic      .btequ  4,int1ic    ; Polarity select bit
;
int2ic          .equ    005fh       ; INT2
ilvl0_int2ic    .btequ  0,int2ic    ; Interrupt priority level select bit
ilvl1_int2ic    .btequ  1,int2ic    ;
ilvl2_int2ic    .btequ  2,int2ic    ;
ir_int2ic       .btequ  3,int2ic    ; Interrupt request bit
pol_int2ic      .btequ  4,int2ic    ; Polarity select bit
;
;-------------------------------------------------------
;   Timer Y,Z mode register
;-------------------------------------------------------
tyzmr       .equ        0080h
tymod0 		.btequ      0,tyzmr     ; TY Operation mode select bit
tywc   		.btequ      2,tyzmr     ; TY write control bit
tys 	  	.btequ      3,tyzmr     ; TY count start bit
tzmod0 		.btequ      4,tyzmr     ; TZ Operation mode select bit
tzmod1 		.btequ      5,tyzmr     ; TZ Operation mode select bit
tzwc   		.btequ      6,tyzmr     ; TZ write control bit
tzs 	  	.btequ      7,tyzmr     ; TZ count start bit
;
;-------------------------------------------------------
;   Timer Y registers
;-------------------------------------------------------
prey		.equ		0081h		; TY prescaler
;
tysc		.equ		0082h		; TY secondary
;
typr			.equ		0083h		; TY primary
;
;-------------------------------------------------------
;   Timer YZ wave-form output control register
;-------------------------------------------------------
pum			.equ        0084h
typum0 		.btequ      0,pum	    ; TY primary wave-form expand control bit
typum1 		.btequ      1,pum	    ; TY secondary wave-form expand control bit
tzpum0 		.btequ      2,pum	    ; TZ primary wave-form expand control bit
tzpum1 		.btequ      3,pum	    ; TZ secondary wave-form expand control bit
tyopl   	.btequ      4,pum     	; TY output level latch
tzopl   	.btequ      5,pum     	; TZ output level latch
intstg   	.btequ      6,pum     	; INT0 one-shot trigger control bit
intseg   	.btequ      7,pum     	; INT0 one-shot trigger polarity select bit
;
;-------------------------------------------------------
;   Timer Z registers
;-------------------------------------------------------
prez		.equ		0085h		; TZ prescaler
;
tzsc		.equ		0086h		; TZ secondary
;
tzpr		.equ		0087h		; TZ primary
;
;-------------------------------------------------------
;   Timer 1 registers
;-------------------------------------------------------
pre1		.equ		0088h		; T1 prescaler
;
t1			.equ		0089h		; T1 timer
;
;-------------------------------------------------------
;   Timer YZ output control register
;-------------------------------------------------------
tyzoc		.equ        008ah
tzos 		.btequ      0,tyzoc	    ; TZ one-shot start bit
tyocnt 		.btequ      1,tyzoc	    ; TY programable outpur select bit
tzocnt 		.btequ      2,tyzoc	    ; TZ programable outpur select bit
;
;-------------------------------------------------------
;   Timer X mode register
;-------------------------------------------------------
txmr       .equ        008bh
txmod0 		.btequ      0,txmr     	; TX Operation mode select bit0
txmod1 		.btequ      1,txmr     	; TX Operation mode select bit1
r0edg  		.btequ      2,txmr     	; CNTR0 polarity select bit
txs 	  	.btequ      3,txmr     	; TX count start bit
txocnt 	  	.btequ      4,txmr     	; output enable bit
txmod2 		.btequ      5,txmr     	; TX Operation mode select bit2
;
;-------------------------------------------------------
;   Timer X registers
;-------------------------------------------------------
prex		.equ		008ch		; TX prescaler
;
tx			.equ		008dh		; TX
;
;-------------------------------------------------------
;   Timer count source select register
;-------------------------------------------------------
tcss		.equ        008eh
txck0 		.btequ      0,tcss     	; TX count spurce select bit0
txck1 		.btequ      1,tcss     	; TX count source select bit1
tyck0 		.btequ      2,tcss     	; TY count spurce select bit0
tyck1 		.btequ      3,tcss     	; TY count source select bit1
tzck0 		.btequ      4,tcss     	; TZ count spurce select bit0
tzck1 		.btequ      5,tcss     	; TZ count source select bit1
t1ck0 		.btequ      6,tcss     	; T1 count spurce select bit0
t1ck1 		.btequ      7,tcss     	; T1 count source select bit1
;
;-------------------------------------------------------
;   Clock prescaler reset flag
;-------------------------------------------------------
cpsrf       .equ        008fh
;
cpsr        .btequ      7,cpsrf     ; Clock prescaler reset flag
;
;-------------------------------------------------------
;   Timer C registers
;-------------------------------------------------------
tc			.equ		0090h		; TC
tcl		.equ		tc			;
tch		.equ		tc+1		; 
;
;-------------------------------------------------------
;   External interrupt enable register
;-------------------------------------------------------
inten		.equ		0096h
int0en		.btequ		0,inten		; INT0 interrupt enable bit
int0pl		.btequ		1,inten		; INT0 polarity select bit
int1en		.btequ		2,inten		; INT1 interrupt enable bit
int1pl		.btequ		3,inten		; INT1 polarity select bit
int2en		.btequ		4,inten		; INT2 interrupt enable bit
int2pl		.btequ		5,inten		; INT2 polarity select bit
int3en		.btequ		6,inten		; INT3 interrupt enable bit
int3pl		.btequ		7,inten		; INT3 polarity select bit
;
;-------------------------------------------------------
;   Key interrupt enable register
;-------------------------------------------------------
kien		.equ		0098h
ki0en		.btequ		0,kien		; KI0 interrupt enable bit
ki0pl		.btequ		1,kien		; KI0 polarity select bit
ki1en		.btequ		2,kien		; KI1 interrupt enable bit
ki1pl		.btequ		3,kien		; KI1 polarity select bit
ki2en		.btequ		4,kien		; KI2 interrupt enable bit
ki2pl		.btequ		5,kien		; KI2 polarity select bit
ki3en		.btequ		6,kien		; KI3 interrupt enable bit
ki3pl		.btequ		7,kien		; KI3 polarity select bit
;
;-------------------------------------------------------
;   Timer C control register0
;-------------------------------------------------------
tcc0		.equ		009ah
tcc00		.btequ		0,tcc0		; input capture control bit
tcc01		.btequ		1,tcc0		; Timer C clock select bit
tcc02		.btequ		2,tcc0		; Timer C clock select bit
tcc03		.btequ		3,tcc0		; Timer C trgger edge select bit
tcc04		.btequ		4,tcc0		; Timer C trgger edge select bit
tcc07		.btequ		7,tcc0		; Timer C count source select bit
;
;-------------------------------------------------------
;   Timer C control register1
;-------------------------------------------------------
tcc1		.equ		009bh
tcc10		.btequ		0,tcc1		; degital filter select bit
tcc11		.btequ		1,tcc1		; degital filter select bit
;
;-------------------------------------------------------
;   Time Mesurement register
;-------------------------------------------------------
tm			.equ		009ch		; Time mesurement reg.
tml		.equ		tm			;
tmh		.equ		tm+1		; 
;
;-------------------------------------------------------
;   UART0
;-------------------------------------------------------
u0mr        .equ        00a0h       ; UART0 transmit/receive mode register
smd0_u0mr   .btequ      0,u0mr      ; Serial I/O mode select bit
smd1_u0mr   .btequ      1,u0mr      ;
smd2_u0mr   .btequ      2,u0mr      ;
ckdir_u0mr  .btequ      3,u0mr      ; Internal/external clock select bit
stps_u0mr   .btequ      4,u0mr      ; Stop bit length select bit
pry_u0mr    .btequ      5,u0mr      ; Odd/even parity select bit
prye_u0mr   .btequ      6,u0mr      ; Parity enable bit
slep_u0mr   .btequ      7,u0mr      ; Sleep  select bit
;
u0brg       .equ        00a1h       ; UART0 bit rate generator ; Use "MOV" instruction when writing to this register.
;
u0tb        .equ        00a2h       ; UART0 transmit buffer register ; Use "MOV" instruction when writing to this register.
u0tbl       .equ        u0tb        ;       Low
u0tbh       .equ        u0tb+1      ;       High
;
u0c0        .equ        00a4h       ; UART0 transmit/receive control register 0
clk0_u0c0   .btequ      0,u0c0      ; BRG count source select bit
clk1_u0c0   .btequ      1,u0c0      ; 
txept_u0c0  .btequ      3,u0c0      ; Transmit register empty flag
nch_u0c0    .btequ      5,u0c0      ; Data output select bit
ckpol_u0c0  .btequ      6,u0c0      ; CLK polarity select bit
uform_u0c0  .btequ      7,u0c0      ; Transfer format select bit
;
u0c1        .equ        00a5h       ; UART0 transmit/receive control register 1
te_u0c1     .btequ      0,u0c1      ; Transmit enable bit
ti_u0c1     .btequ      1,u0c1      ; Transmit buffer empty flag
re_u0c1     .btequ      2,u0c1      ; Receive enable bit
ri_u0c1     .btequ      3,u0c1      ; Receive complete flag
;
u0rb        .equ        00a6h       ; UART0 receive buffer register
u0rbl       .equ        u0rb        ;       Low
u0rbh       .equ        u0rb+1      ;       High
oer_u0rb    .btequ      4,u0rbh     ; Overrun error flag
fer_u0rb    .btequ      5,u0rbh     ; Framing error flag
per_u0rb    .btequ      6,u0rbh     ; Parity error flag
sum_u0rb    .btequ      7,u0rbh     ; Error sum flag
;
;-------------------------------------------------------
;   UART1
;-------------------------------------------------------
u1mr        .equ        00a8h       ; UART1 transmit/receive mode register
smd0_u1mr   .btequ      0,u1mr      ; Serial I/O mode select bit
smd1_u1mr   .btequ      1,u1mr      ;
smd2_u1mr   .btequ      2,u1mr      ;
ckdir_u1mr  .btequ      3,u1mr      ; Internal/external clock select bit
stps_u1mr   .btequ      4,u1mr      ; Stop bit length select bit
pry_u1mr    .btequ      5,u1mr      ; Odd/even parity select bit
prye_u1mr   .btequ      6,u1mr      ; Parity enable bit
slep_u1mr   .btequ      7,u1mr      ; Sleep select bit
;
u1brg       .equ        00a9h       ; UART1 bit rate generator ; Use "MOV" instruction when writing to this register.
;
u1tb        .equ        00aah       ; UART1 transmit buffer register ; Use "MOV" instruction when writing to this register.
u1tbl       .equ        u1tb        ;       Low
u1tbh       .equ        u1tb+1      ;       High
;
u1c0        .equ        00ach       ; UART1 transmit/receive control register 0
clk0_u1c0   .btequ      0,u1c0      ; BRG count source select bit
clk1_u1c0   .btequ      1,u1c0      ; 
txept_u1c0  .btequ      3,u1c0      ; Transmit register empty flag
nch_u1c0    .btequ      5,u1c0      ; Data output select bit
ckpol_u1c0  .btequ      6,u1c0      ; CLK polarity select bit
uform_u1c0  .btequ      7,u1c0      ; Transfer format select bit
;
u1c1        .equ        00adh       ; UART1 transmit/receive control register 1
te_u1c1     .btequ      0,u1c1      ; Transmit enable bit
ti_u1c1     .btequ      1,u1c1      ; Transmit buffer empty flag
re_u1c1     .btequ      2,u1c1      ; Receive enable bit
ri_u1c1     .btequ      3,u1c1      ; Receive complete flag
;
u1rb        .equ        00aeh       ; UART1 receive register
u1rbl       .equ        u1rb        ;       Low
u1rbh       .equ        u1rb+1      ;       High
oer_u1rb    .btequ      4,u1rbh     ; Overrun error flag
fer_u1rb    .btequ      5,u1rbh     ; Framing error flag
per_u1rb    .btequ      6,u1rbh     ; Parity error flag
sum_u1rb    .btequ      7,u1rbh     ; Error sum flag
;
ucon        .equ        00b0h       ; UART transmit/receive control register 2
u0irs       .btequ      0,ucon      ; UART0 transmit interrupt cause select bit
u1irs       .btequ      1,ucon      ; UART1 transmit interrupt cause select bit
u0rrm       .btequ      2,ucon      ; UART0 continuous receive mode enable bit
u1rrm       .btequ      3,ucon      ; UART1 continuous receive mode enable bit
clkmd0      .btequ      4,ucon      ; CLK/CLKS select bit 0
clkmd1      .btequ      5,ucon      ; CLK/CLKS select bit 1
rxd1en      .btequ      6,ucon      ; RxD1 input-pin select bit
;
;-------------------------------------------------------
;   A-D registers ADi
;-------------------------------------------------------
ad          .equ        00c0h       ; A-D register 0
adl         .equ        ad          ;       Low
adh         .equ        ad+1        ;       High
;
;-------------------------------------------------------
;   A-D control register 2
;-------------------------------------------------------
adcon2      .equ        00d4h       ; A-D control register 2
smp         .btequ      0,adcon2    ; A-D conversion method select bit
;
;-------------------------------------------------------
;   A-D control register 0
;-------------------------------------------------------
adcon0      .equ        00d6h       ; A-D control register 0
ch0         .btequ      0,adcon0    ; Analog input pin select bit
ch1         .btequ      1,adcon0    ;
ch2         .btequ      2,adcon0    ;
md          .btequ      3,adcon0    ; A-D operation mode select bit 0
adgsel0     .btequ      4,adcon0    ; A-D input group select bit
adst        .btequ      6,adcon0    ; A-D conversion start flag
cks0        .btequ      7,adcon0    ; Frequency select bit 0
;
;-------------------------------------------------------
;   A-D control register 1
;-------------------------------------------------------
adcon1      .equ        00d7h       ; A-D control register 1
bits        .btequ      3,adcon1    ; 8/10-bit mode select bit
cks1        .btequ      4,adcon1    ; Frequency select bit 1
vcut        .btequ      5,adcon1    ; Vref connect bit
opa0        .btequ      6,adcon1    ; External op-amp connection mode bit
opa1        .btequ      7,adcon1    ;
;
;-------------------------------------------------------
;   D-A
;-------------------------------------------------------
;
da          .equ        00d8h       ; D-A register
;
dacon       .equ        00dch       ; D-A control register
dae          .btequ      0,dacon     ; D-A output enable bit
;
;-------------------------------------------------------
;   Port
;-------------------------------------------------------
p0          .equ        00e0h       ; Port P0 register
p0_0        .btequ      0,p0
p0_1        .btequ      1,p0
p0_2        .btequ      2,p0
p0_3        .btequ      3,p0
p0_4        .btequ      4,p0
p0_5        .btequ      5,p0
p0_6        .btequ      6,p0
p0_7        .btequ      7,p0
;
p1          .equ        00e1h       ; Port P1 register
p1_0        .btequ      0,p1
p1_1        .btequ      1,p1
p1_2        .btequ      2,p1
p1_3        .btequ      3,p1
p1_4        .btequ      4,p1
p1_5        .btequ      5,p1
p1_6        .btequ      6,p1
p1_7        .btequ      7,p1
;
pd0         .equ        00e2h       ; Port P0 direction register
pd0_0       .btequ      0,pd0
pd0_1       .btequ      1,pd0
pd0_2       .btequ      2,pd0
pd0_3       .btequ      3,pd0
pd0_4       .btequ      4,pd0
pd0_5       .btequ      5,pd0
pd0_6       .btequ      6,pd0
pd0_7       .btequ      7,pd0
;
pd1         .equ        00e3h       ; Port P1 direction register
pd1_0       .btequ      0,pd1
pd1_1       .btequ      1,pd1
pd1_2       .btequ      2,pd1
pd1_3       .btequ      3,pd1
pd1_4       .btequ      4,pd1
pd1_5       .btequ      5,pd1
pd1_6       .btequ      6,pd1
pd1_7       .btequ      7,pd1
;
p2          .equ        00e4h       ; Port P2 register
p2_0        .btequ      0,p2
p2_1        .btequ      1,p2
;
p3          .equ        00e5h       ; Port P3 register
p3_0        .btequ      0,p3
p3_1        .btequ      1,p3
p3_2        .btequ      2,p3
p3_3        .btequ      3,p3
p3_4        .btequ      4,p3
p3_5        .btequ      5,p3
p3_6        .btequ      6,p3
p3_7        .btequ      7,p3
;
pd2         .equ        00e6h       ; Port P2 direction register
pd2_0       .btequ      0,pd2
pd2_1       .btequ      1,pd2
;
pd3         .equ        00e7h       ; Port P3 direction register
pd3_0       .btequ      0,pd3
pd3_1       .btequ      1,pd3
pd3_2       .btequ      2,pd3
pd3_3       .btequ      3,pd3
pd3_4       .btequ      4,pd3
pd3_5       .btequ      5,pd3
pd3_6       .btequ      6,pd3
pd3_7       .btequ      7,pd3
;
p4          .equ        00e8h       ; Port P4 register
p4_0        .btequ      0,p4
p4_1        .btequ      1,p4
p4_2        .btequ      2,p4
p4_3        .btequ      3,p4
p4_4        .btequ      4,p4
p4_5        .btequ      5,p4
p4_6        .btequ      6,p4
p4_7        .btequ      7,p4
;
pd4         .equ        00eah       ; Port P4 direction register
pd4_0       .btequ      0,pd4
pd4_1       .btequ      1,pd4
pd4_2       .btequ      2,pd4
pd4_3       .btequ      3,pd4
pd4_4       .btequ      4,pd4
pd4_5       .btequ      5,pd4
pd4_6       .btequ      6,pd4
pd4_7       .btequ      7,pd4
;
;-------------------------------------------------------
;   Pull-up control registers
;-------------------------------------------------------
pur0        .equ        00fch       ; Pull-up control register 0
;
pu00        .btequ      0,pur0      ; P00 to P03 pull-up
pu01        .btequ      1,pur0      ; P04 to P07 pull-up
pu02        .btequ      2,pur0      ; P10 to P13 pull-up
pu03        .btequ      3,pur0      ; P14 to P17 pull-up
pu04        .btequ      4,pur0      ; P20 to P23 pull-up
pu06        .btequ      6,pur0      ; P30 to P33 pull-up
pu07        .btequ      7,pur0      ; P34 to P37 pull-up
;
pur1        .equ        00fdh       ; Pull-up control register 1
;
pu10        .btequ      0,pur1      ; P40 to P43 pull-up
pu11        .btequ      1,pur1      ; P44 to P47 pull-up
;
;-------------------------------------------------------
;   Port P1 drive capacity control register
;-------------------------------------------------------
drr         .equ        00feh
;
drr0        .btequ      0,drr       ; Port P1_0 capacity control select bit
drr1        .btequ      1,drr       ; Port P1_1 capacity control select bit
drr2        .btequ      2,drr       ; Port P1_2 capacity control select bit
drr3        .btequ      3,drr       ; Port P1_3 capacity control select bit
drr4        .btequ      4,drr       ; Port P1_4 capacity control select bit
drr5        .btequ      5,drr       ; Port P1_5 capacity control select bit
drr6        .btequ      6,drr       ; Port P1_6 capacity control select bit
drr7        .btequ      7,drr       ; Port P1_7 capacity control select bit


