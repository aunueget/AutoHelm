;/*********************************************************************************
;*																				 
;*	File Name:  sect30.inc                                         						 
;*                                                                  				 
;"  Description :  This file is specific to the M30102 microcontroller and adapted 
;"                 for use with the MDECE30102 Starter Kit. NC30 compiler 
;"                 sections that reference 'Near ROM' or 'Far RAM' are not 
;"                 included here as these physical memory areas do not exist
;"                 on the M30102. UART0 interrupt vectors are used for the
;"                 Starter Kit debugger.
;**********************************************************************************                                                                 				 
;*	Copyright (c) 2002 Mitsubishi Electric and Electronics USA, Inc.              *    
;*	All rights reserved															  *
;**********************************************************************************
;*	The software supplied by Mitsubishi Electric and Electronics USA, Inc. 		  *
;*	is intended and supplied for use on Mitsubishi Electric  products. 			  *
;*	This software is owned by Mitsubishi Electric and Electronics USA, Inc.  	  *
;*	or Mitsubishi Electric Corporation and is protected under applicable 		  *
;*	copyright laws. All rights are reserved. Any use of this software in 		  *
;*	violation of the use and restrictions described herein may subject user 	  *
;*	to criminal sanctions under applicable laws, as well as to civil 			  *
;*	liability for breach of the terms and conditions of this use license.		  *
;* 																				  *
;*	THIS SOFTWARE IS PROVIDED "AS IS". NO WARRANTIES, WHETHER EXPRESS, IMPLIED 	  *
;*	OR STATUTORY, INCLUDING BUT NOT LIMITED TO IMPLIED WARRANTIES OF 			  *
;*	MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE APPLY TO THIS SOFTWARE.  *
;*	MITSUBISHI ELECTRIC AND ELECTRONICS USA, INC. AND MITSUBISHI ELECTRIC 		  * 
;*	CORPORATION RESERVE THE RIGHT, WITHOUT NOTICE, TO MAKE CHANGES TO THIS 		  *
;*	SOFTWARE. NEITHER MITSUBISHI ELECTRIC AND ELECTRONICS USA, INC. NOR 		  *
;*   MITSUBISHI ELECTRIC CORPORATION SHALL, IN ANY CIRCUMSTANCES, BE LIABLE 	  *
;*	FOR SPECIAL, INCIDENTAL, OR CONSEQUENTIAL DAMAGES FOR ANY REASON WHATSOEVER   *
;*	ARISING OUT OF THE USE OR APPLICATION OF THIS SOFTWARE.	 					  *
;*                                                               				  *
;*================================================================================*
;*	$Log: sect30.inc,v $
;*	Revision 1.2  2002-06-07 14:00:18-04  bembry
;*	Fixed flicker problem.  Chang Temp conversion equation fixes problem at "0" crossover point.
;*
;*================================================================================*/

;******************************************************************************
;
;  sect30.inc     : Customized section and macro definitions for the M16C/10
;                   (M30102) microcontroller.
;
;  Description :  This file is specific to the M30102 microcontroller and adapted 
;                 for use with the MDECE30102 Starter Kit. NC30 compiler 
;                 sections that reference 'Near ROM' or 'Far RAM' are not 
;                 included here as these physical memory areas do not exist
;                 on the M30102. UART0 interrupt vectors are used for the
;                 Starter Kit debugger.
;
;
;	              Copyright 1995-2002 MITSUBISHI ELECTRIC CORPORATION
; 	             MITSUBISHI ELECTRIC SEMICONDUCTOR SYSTEMS CORPORATION AND 
;                MITSUBISHI ELECTRIC AND ELECTRONICS USA
;                All Rights Reserved.
;
;
;	
;      
;******************************************************************************

;			Definitions
;---------------------------------------------------------------------
; ROM and RAM starting addresses. The flash ROM on the M30102 starts 
; at address FA000h, RAM at 400h.
;---------------------------------------------------------------------

ROM_strt 	.equ	0FA000h
RAM_strt	.equ	0400H
;---------------------------------------------------------------------
; VARIABLE INTERRUPT VECTOR TABLE ADDRESS. As the special page vectors
; are not commonly used (used by operating systems and kernal calls), the 
; variable vector table is placed in the special page vector area. About 
; 30 special page vectors are still available to the user (see below).
;---------------------------------------------------------------------

VECTOR_ADR 	.equ	0ff800h	

;---------------------------------------------------------------------
; STACK SIZE definition. Unless the system is running an RTOS, both 
; interrupts and function calls can use the istack (default startup 
; configuration). If the user stack (ustack) is required, set this 
; value accordingly, otherwise set to low value as the M30102 has 
; limited RAM.
;---------------------------------------------------------------------

USTACKSIZE	.equ	08h  ;set above zero in case of accidental use.

;---------------------------------------------------------------------
; INTERRUPT STACK SIZE definition. In the section allocation below
; the stack pointer is set to the top of user RAM (below USB
; Monitor RAM). If the user stack is required, edit the section allocation
; and set the ISTACKSIZE to allow space for all enabled interrupts.
;---------------------------------------------------------------------

;ISTACKSIZE	.equ	00h
istack_ini	.equ    077Fh ;can be set to 7FFh if not using USB Monitor

;---------------------------------------------------------------------
;  HEEP SIZE definition. Only used for memory allocate functions
;  (malloc, realloc, etc). If using memory allocate functions, set this 
;  value accordingly, otherwise leave at zero as the M30102 has limited
;  RAM 
;---------------------------------------------------------------------
HEAPSIZE	.equ	00h

;---------------------------------------------------------------------
;  Define Registers used by "ncrt0.a30"
;---------------------------------------------------------------------

protect		.equ	0ah
cm0			.equ	06h
cm1			.equ    07h
cm2			.equ    0ch
pm0			.equ	04h
pm1			.equ	05h
tcss		.equ    08eh
;====================================================================
; Initialize Macro declarations. These macros are used in "ncrt0.a30"
; for initializing C variables. Clears global variables, sets
; intialized variables, etc.
;---------------------------------------------------------------------

N_BZERO	.macro	TOP_ ,SECT_
	mov.b	#00H, R0L
	mov.w	#(TOP_ & 0FFFFH), A1
	mov.w	#sizeof SECT_ , R3
	sstr.b	
	.endm

N_BCOPY .macro	FROM_,TO_,SECT_
	mov.w	#(FROM_ & 0FFFFH),A0
	mov.b	#(FROM_ >>16),R1H
	mov.w	#TO_ ,A1
	mov.w	#sizeof SECT_ , R3
	smovf.b
	.endm

BZERO	.macro	TOP_,SECT_
	push.w	#sizeof SECT_ >> 16
	push.w	#sizeof SECT_  & 0ffffh
	pusha	TOP_ >>16
	pusha	TOP_ & 0ffffh
	.stk	8
	.glb	_bzero	
	.call	_bzero,G
	jsr.a	_bzero
	.endm


BCOPY	.macro	FROM_ ,TO_ ,SECT_
	push.w	#sizeof SECT_  >> 16
	push.w	#sizeof SECT_  & 0ffffh
	pusha	TO_ >>16
	pusha	TO_  & 0ffffh
	pusha	FROM_ >>16
	pusha	FROM_  & 0ffffh
	.stk	12
	.glb	_bcopy
	.call   _bcopy,G
	jsr.a	_bcopy
	.endm
;---------------------------------------------------------------
; Special page vectors. This macro puts the jump address of a 
; functions defined as special page into the special page vector table.
; See example calls below.  Note only the first few special
; page vectors are available (18 to 50) as the USB monitor and the 
; variable vector table use most of the special page vector table area. 
; See the M16C Software Manual and the NC30 manual for more information
; on special page vectors.
;---------------------------------------------------------------
;       macro for special page vectors
;
;Format:
;	SPECIAL	number
;

SPECIAL	.macro	NUM

	.org		0FFFFEH-(NUM*2)
	.glb		__SPECIAL_@NUM
	.word		__SPECIAL_@NUM  & 0FFFFH

.endm

;---------------------------------------------------------------
; 	Section allocation. The following declarations sets the location of the
;   sections in the physical memory map. DO NOT change these settings
;   without refering to the NC30 manual on startup files.
;
;---------------------------------------------------------------
; Near RAM data area
;---------------------------------------------------------------
; SBDATA area

	.section	data_SE,DATA
	.org	    RAM_strt
data_SE_top:

	.section	bss_SE,DATA,ALIGN
bss_SE_top:

	.glb	__SB__               ; declare sb 'section' here
__SB__:

	.section	data_SO,DATA
data_SO_top:

	.section	bss_SO,DATA
bss_SO_top:

; near RAM area
	.section	data_NE,DATA,ALIGN
data_NE_top:

	.section	bss_NE,DATA,ALIGN
bss_NE_top:

	.section	data_NO,DATA
data_NO_top:

	.section	bss_NO,DATA
bss_NO_top:
;---------------------------------------------------------------
; Stack area. USTACK not used. Istack set to top of available RAM
;---------------------------------------------------------------
	.section	ustack,DATA
	.blkb	USTACKSIZE
stack_top:

	.section   istack,DATA
	.org       istack_ini	; By removing this line and uncommenting
;	.blkb	   ISTACKSIZE   ; this line (set ISTACKSIZE > 0 ), 
							; the stack area will immediately 
							; follow global variables in RAM.
istack_top:
	.blkb	1 ; Holder for map viewer. Can (and should) be removed if 
	          ; ISTACKSIZE uncommented and set > 0

;---------------------------------------------------------------
;	heap section. HEAPSIZE is set to zero above
;---------------------------------------------------------------
	.section	heap,DATA
heap_top:
	.blkb	HEAPSIZE
;---------------------------------------------------------------
; Near ROM data area
;---------------------------------------------------------------
; there is no near ROM on the M30102

;---------------------------------------------------------------
; Far RAM data area
;---------------------------------------------------------------
; there is no far RAM on the M30102

;---------------------------------------------------------------
; Far ROM data area. Constants and initialized data are stored
; at the beginning of ROM, then code follows. Within a program, 
; constants are referenced directly from ROM, whereas the startup
; file copies the initialized data to RAM and the data is 
; referenced as initialized variables in RAM.
;---------------------------------------------------------------
	.section	rom_FE,ROMDATA
	.org		ROM_strt
rom_FE_top:
	.section	rom_FO,ROMDATA
rom_FO_top:
;---------------------------------------------------------------
; Initial data of 'data' section
;---------------------------------------------------------------
	.section	data_SEI,ROMDATA
data_SEI_top:
	.section	data_SOI,ROMDATA
data_SOI_top:
	.section	data_NEI,ROMDATA
data_NEI_top:
	.section	data_NOI,ROMDATA
data_NOI_top:
;	.section	data_FEI,ROMDATA
;data_FEI_top:
;	.section	data_FOI,ROMDATA
;data_FOI_top:
;---------------------------------------------------------------
; Switch Table Section
;---------------------------------------------------------------
	.section        switch_table,ROMDATA
switch_table_top:
;---------------------------------------------------------------
; code area
;---------------------------------------------------------------
	.section	interrupt
	.section	program		  
	.section	program_S

;---------------------------------------------------------------
; variable vector section
;---------------------------------------------------------------

USBmon   .equ	0FF900h		;USB Monitor vector for UART0

	.section	vector		; variable vector table
	.org	VECTOR_ADR 

	.lword	dummy_int		; BRK	(vector 0)
	.lword	dummy_int		; Software INT #01
	.lword	dummy_int		; Software INT #02
	.lword	dummy_int		; Software INT #03
	.lword	dummy_int		; Software INT #04
	.lword	dummy_int		; Software INT #05
	.lword	dummy_int		; Software INT #06
	.lword	dummy_int		; Software INT #07
	.lword	dummy_int		; Software INT #08
	.lword	dummy_int		; Software INT #09
	.lword	dummy_int		; Software INT #10
	.lword	dummy_int		; Software INT #11
	.lword	dummy_int		; Software INT #12
	.lword	dummy_int		; Key input interrupt(for user)(vect 13)
	.lword	dummy_int       ; _ad_intr_handler ; A-D(for user)(vector 14) 	.glb _ad_intr_handler
	.lword	dummy_int		; Software INT #15
	.lword	dummy_int		; Software INT #16
	.lword	dummy_int		; uart0 transmit(for user)(vector 17)
	.lword	USBmon		  	; uart0 receive For USB Monitor DO NOT CHANGE

	.lword	dummy_int		; uart1 transmit(for user)(vector 19)
  	.lword  dummy_int   	; uart1 receive (vector 20)
	.glb _tick_timer_intr	
	.lword	_tick_timer_intr; Timer1 Interrupt (vector 21)	
	.glb _motorToggle
	.lword	_motorToggle	; TimerX Interrupt (vector 22)electric motor start onesho
	.glb _delay_ticker
	.lword	_delay_ticker	; TimerY Interrupt (vector 23)
	.glb _motorKill
	.lword	_motorKill		; TimerZ Interrupt (vector 24)	one-shot electric motor stop
	.lword	dummy_int		; CNTR0 Interrupt  (vector 25)
	.lword	dummy_int		; TCIN Interrupt   (vector 26)
	.lword	dummy_int 		; TimerC Interrupt (vector 27)
	.lword	dummy_int		; INT3 Interrupt   (vector 28)
	.lword	dummy_int		; INT0 Interrupt   (vector 29)
	.lword	dummy_int		; INT1 Interrupt   (vector 30)
	.lword	dummy_int		; INT2 Interrupt   (vector 31)
  	.lword  dummy_int       ; vector 32 (for user or MR30)
	.lword	dummy_int		; vector 33 (for user or MR30)
	.lword	dummy_int		; vector 34 (for user or MR30)
	.lword	dummy_int		; vector 35 (for user or MR30)
	.lword	dummy_int		; vector 36 (for user or MR30)
	.lword	dummy_int		; vector 37 (for user or MR30)
	.lword	dummy_int		; vector 38 (for user or MR30)
	.lword	dummy_int		; vector 39 (for user or MR30)
	.lword	dummy_int		; vector 40 (for user or MR30)
	.lword	dummy_int		; vector 41 (for user or MR30)
	.lword	dummy_int		; vector 42 (for user or MR30)
	.lword	dummy_int		; vector 43 (for user or MR30)	
	.lword  dummy_int		; vector 44 (for user or MR30)
	.lword	dummy_int		; vector 45 (for user or MR30)
	.lword	dummy_int		; vector 46 (for user or MR30)
	.lword	dummy_int 		; vector 47 (for user or MR30)
	; ....
	; etc to vector 63 


;===============================================================
; fixed vector section
;---------------------------------------------------------------
	.section	fvector	
;===============================================================
; special page definition
;---------------------------------------------------------------
;====================================================================
; Set-up special page vector table. Call the macro "SPECIAL" to put
; the jump addresses of functions defined as special page into the 
; special page vector table. Note only the first few special
; page vectors are available (18 to 50) as the USB monitor and the 
; variable vector table use most of the special page vector table area. 
; If more special page vectors are required, the variable vector table
; can be moved. See the M16C Software Manual and the NC30 manual for 
; more information on special page vectors.
;---------------------------------------------------------------------
;
;	Format: SPECIAL number
;
;---------------------------------------------------------------
;	.section	vector_s
;	SPECIAL 50    ;example use
;	SPECIAL 49
;   SPECIAL 48
;   ...ETC....
;	SPECIAL 18


;
;===============================================================
; fixed vector section
;---------------------------------------------------------------

	.org	0fffdch
UDI:
	.lword	dummy_int
OVER_FLOW:
	.lword	dummy_int
BRKI:
	.lword	dummy_int
ADDRESS_MATCH:
	.lword	dummy_int
SINGLE_STEP:
	.lword	dummy_int
WDT_OS:
	.lword	basic_oscstop ; minimal service routine if OSC STOP 
                          ; interrupt is enabled. See "NCRT0.A30"
DBC:
	.lword	dummy_int
NMI:
	.lword	dummy_int
RESET:
	.lword	start
;

