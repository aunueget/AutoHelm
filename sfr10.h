/****************************************************************************
*                                                                           *
*   file name   : definition of M16C/10's SFR                               *
*                                                                           *
*   Copyright   : MITSUBISHI ELECTRIC CORPORATION                           *
*                                                                           *
*   Version     : 1.00  ( 2001-12-26 ) Initial                              *
*               : 1.01	( 2002-01-10 ) cm2 u0tb u1tb                        *
*****************************************************************************/
/*
  note:
    This data is a freeware that SFR for M16C/10 groups is described.
    Mitsubishi Electric Corporation assumes no responsibility for any damage
    that occurred by this data.
*/
/********************************************************
*   declare SFR addresses                               *
********************************************************/

#pragma ADDRESS     pm0_addr    0004H       /* Processor mode register 0 */

#pragma ADDRESS     pm1_addr    0005H       /* Processor mode register 1 */

#pragma ADDRESS     cm0_addr    0006H       /* System clock control register 0 */

#pragma ADDRESS     cm1_addr    0007H       /* System clock control register 1 */

#pragma ADDRESS     aier_addr   0009H       /* Address match interrupt enable register */

#pragma ADDRESS     prcr_addr   000aH       /* Protect register */

#pragma ADDRESS     cm2_addr    000cH       /* Oscillation stop detection register */

#pragma ADDRESS     wdts_addr   000eH       /* Watchdog timer start register */

#pragma ADDRESS     wdc_addr    000fH       /* Watchdog timer control register */

#pragma ADDRESS     rmad0_addr  0010H       /* Address match interrupt register 0 */

#pragma ADDRESS     rmad1_addr  0014H       /* Address match interrupt register 1 */

#pragma ADDRESS     int0f_addr  001eH       /* INT0 input filter select register */

#pragma ADDRESS     kupic_addr  004dH       /* Key input interrupt control register */

#pragma ADDRESS     adic_addr   004eH       /* A-D conversion interrupt control register */

#pragma ADDRESS     s0tic_addr  0051H       /* UART0 transmit interrupt control register */

#pragma ADDRESS     s0ric_addr  0052H       /* UART0 receive interrupt control register */

#pragma ADDRESS     s1tic_addr  0053H       /* UART1 transmit interrupt control register */

#pragma ADDRESS     s1ric_addr  0054H       /* UART1 receive interrupt control register */

#pragma ADDRESS     t1ic_addr   0055H       /* Timer 1 interrupt control register */

#pragma ADDRESS     txic_addr   0056H       /* Timer X interrupt control register */

#pragma ADDRESS     tyic_addr   0057H       /* Timer Y interrupt control register */

#pragma ADDRESS     tzic_addr   0058H       /* Timer Z interrupt control register */

#pragma ADDRESS     cntr0ic_addr 0059H      /* Cntr0 interrupt control register */

#pragma ADDRESS     tcinic_addr 005aH       /* Tcin interrupt control register */

#pragma ADDRESS     tcic_addr   005bH       /* Timer C interrupt control register */

#pragma ADDRESS     int3ic_addr 005cH       /* INT3~ interrupt control register */

#pragma ADDRESS     int0ic_addr 005dH       /* INT0~ interrupt control register */

#pragma ADDRESS     int1ic_addr 005eH       /* INT1~ interrupt control register */

#pragma ADDRESS     int2ic_addr 005fH       /* INT2~ interrupt control register */

#pragma ADDRESS     tyzmr_addr  0080H       /* Timer Y,Z mode register */

#pragma ADDRESS     prey_addr   0081H       /* Prescaler Y */

#pragma ADDRESS     tysc_addr   0082H       /* Timer Y secondary */

#pragma ADDRESS     typr_addr   0083H       /* Timer Y primary */

#pragma ADDRESS     pum_addr    0084H       /* Timer Y,Z waveform output control register */

#pragma ADDRESS     prez_addr   0085H       /* Prescaler Z */

#pragma ADDRESS     tzsc_addr   0086H       /* Timer Z secondary */

#pragma ADDRESS     tzpr_addr   0087H       /* Timer Z primary */

#pragma ADDRESS     pre1_addr   0088H       /* Prescaler 1 */

#pragma ADDRESS     t1_addr     0089H       /* Timer 1 */

#pragma ADDRESS     tyzoc_addr  008aH       /* Timer Y,Z ooutput control register */

#pragma ADDRESS     txmr_addr   008bH       /* Timer X mode register */

#pragma ADDRESS     prex_addr   008cH       /* Prescaler X */

#pragma ADDRESS     tx_addr     008dH       /* Timer X */

#pragma ADDRESS     tcss_addr   008eH       /* Timer count source set register */

#pragma ADDRESS     cpsrf_addr  008fH       /* Clock prescaler reset flag */

#pragma ADDRESS     tc_addr     0090H       /* Timer C counter */

#pragma ADDRESS     inten_addr  0096H       /* External input enable register */

#pragma ADDRESS     kien_addr   0098H       /* Key input enable register */

#pragma ADDRESS     tcc0_addr   009aH       /* Timer C conrtol register 0 */

#pragma ADDRESS     tcc1_addr   009bH       /* Timer C control register 1 */

#pragma ADDRESS     tm_addr     009cH       /* Time measurement register */

#pragma ADDRESS     u0mr_addr   00a0H       /* UART0 transmit/receive mode register */

#pragma ADDRESS     u0brg_addr  00a1H       /* UART0 bit rate generator */

#pragma ADDRESS     u0tb_addr   00a2H       /* UART0 transmit buffer register */

#pragma ADDRESS     u0c0_addr   00a4H       /* UART0 transmit/receive control register 0 */

#pragma ADDRESS     u0c1_addr   00a5H       /* UART0 transmit/receive control register 1 */

#pragma ADDRESS     u0rb_addr   00a6H       /* UART0 receive buffer register */

#pragma ADDRESS     u1mr_addr   00a8H       /* UART1 transmit/receive mode register */

#pragma ADDRESS     u1brg_addr  00a9H       /* UART1 bit rate generator */

#pragma ADDRESS     u1tb_addr   00aaH       /* UART1 transmit buffer register */

#pragma ADDRESS     u1c0_addr   00acH       /* UART1 transmit/receive control register 0 */

#pragma ADDRESS     u1c1_addr   00adH       /* UART1 transmit/receive control register 1 */

#pragma ADDRESS     u1rb_addr   00aeH       /* UART1 receive buffer register */

#pragma ADDRESS     ucon_addr   00b0H       /* UART transmit/receive control register 2 */

#pragma ADDRESS     ad_addr     00c0H       /* A-D register */

#pragma ADDRESS     adcon2_addr 00d4H       /* A-D control register 2 */

#pragma ADDRESS     adcon0_addr 00d6H       /* A-D control register 0 */

#pragma ADDRESS     adcon1_addr 00d7H       /* A-D control register 1 */

#pragma ADDRESS     da_addr     00d8H       /* D-A register */

#pragma ADDRESS     dacon_addr  00dcH       /* D-A control register */

#pragma ADDRESS     p0_addr     00e0H       /* Port P0 register */

#pragma ADDRESS     p1_addr     00e1H       /* Port P1 register */

#pragma ADDRESS     pd0_addr    00e2H       /* Port P0 direction register */

#pragma ADDRESS     pd1_addr    00e3H       /* Port P1 direction register */

#pragma ADDRESS     p2_addr     00e4H       /* Port P2 register */

#pragma ADDRESS     p3_addr     00e5H       /* Port P3 register */

#pragma ADDRESS     pd2_addr    00e6H       /* Port P2 direction register */

#pragma ADDRESS     pd3_addr    00e7H       /* Port P3 direction register */

#pragma ADDRESS     p4_addr     00e8H       /* Port P4 register */

#pragma ADDRESS     pd4_addr    00eaH       /* Port P4 direction register */

#pragma ADDRESS     pur0_addr   00fcH       /* Pull-up control register 0 */

#pragma ADDRESS     pur1_addr   00fdH       /* Pull-up control register 1 */

#pragma ADDRESS     drr_addr    00feH       /* Port P1 drive capacity control register */


/********************************************************
*   declare  SFR char                                   *
********************************************************/
unsigned char   wdts_addr;                  /* Watchdog timer start register */
#define     wdts     wdts_addr

unsigned char   prey_addr;                  /* Prescaler Y */
#define     prey     prey_addr

unsigned char   tysc_addr;                  /* Timer Y secondary */
#define     tysc     tysc_addr

unsigned char   typr_addr;                  /* Timer Y primary */
#define     typr     typr_addr

unsigned char   prez_addr;                  /* Prescaler Z */
#define     prez     prez_addr

unsigned char   tzsc_addr;                  /* Timer Z secondary */
#define     tzsc     tzsc_addr

unsigned char   tzpr_addr;                  /* Timer Z primary */
#define     tzpr     tzpr_addr

unsigned char   pre1_addr;                  /* Prescaler 1 */
#define     pre1     pre1_addr

unsigned char   t1_addr;                    /* Timer 1 */
#define     t1       t1_addr

unsigned char   prex_addr;                  /* Prescaler X */
#define     prex     prex_addr

unsigned char   tx_addr;                    /* Timer X */
#define     tx       tx_addr

unsigned char   u0brg_addr;                 /* UART0 bit rate generator */
#define     u0brg    u0brg_addr

unsigned char   u1brg_addr;                 /* UART1 bit rate generator */
#define     u1brg    u1brg_addr

unsigned char   da_addr;               	/* D-A register */
#define     da     da_addr

/********************************************************
*   declare SFR bit                                     *
********************************************************/
struct bit_def {
        char    b0:1;
        char    b1:1;
        char    b2:1;
        char    b3:1;
        char    b4:1;
        char    b5:1;
        char    b6:1;
        char    b7:1;
};
union byte_def{
    struct bit_def bit;
    char    byte;
};

/*------------------------------------------------------
    Processor mode register 0
------------------------------------------------------*/
union byte_def pm0_addr;
#define     pm0     pm0_addr.byte

#define     pm03        pm0_addr.bit.b3     /* Software reset bit */

/*------------------------------------------------------
    Processor mode register 1
------------------------------------------------------*/
union byte_def pm1_addr;
#define     pm1     pm1_addr.byte

#define     pm12        pm1_addr.bit.b2     /* WDT interrupt/reset switching bit */

/*------------------------------------------------------
    System clock control register 0
------------------------------------------------------*/
union byte_def cm0_addr;
#define     cm0     cm0_addr.byte

#define     cm02        cm0_addr.bit.b2     /* WAIT peripheral function clock stop bit */
#define     cm03        cm0_addr.bit.b3     /* Xcin-Xcout drive capacity select bit */
#define     cm04        cm0_addr.bit.b4     /* Port Xc select bit */
#define     cm05        cm0_addr.bit.b5     /* Main clock stop bit */
#define     cm06        cm0_addr.bit.b6     /* Main clock division select bit 0 */
#define     cm07        cm0_addr.bit.b7     /* System clock select bit */

/*------------------------------------------------------
    System clock control register 1
------------------------------------------------------*/
union byte_def cm1_addr;
#define     cm1     cm1_addr.byte

#define     cm10        cm1_addr.bit.b0     /* All clock stop control bit */
#define     cm13        cm1_addr.bit.b3     /* XIN oscillation select bit */
#define     cm14        cm1_addr.bit.b4     /* Ring oscillation stop bit */
#define     cm15        cm1_addr.bit.b5     /* Xin-Xout drive capacity select bit */
#define     cm16        cm1_addr.bit.b6     /* Main clock division select bit 1 */
#define     cm17        cm1_addr.bit.b7     /* Main clock division select bit 1 */

/*------------------------------------------------------
    Address match interrupt enable register
------------------------------------------------------*/
union byte_def aier_addr;
#define     aier        aier_addr.byte

#define     aier0       aier_addr.bit.b0    /* Address match interrupt 0 enable bit */
#define     aier1       aier_addr.bit.b1    /* Address match interrupt 1 enable bit */

/*------------------------------------------------------
    Protect register
------------------------------------------------------*/
union byte_def prcr_addr;
#define     prcr        prcr_addr.byte

#define     prc0        prcr_addr.bit.b0    /* Enables writing to system clock control registers 0/1,and oscillation stop detection register */
#define     prc1        prcr_addr.bit.b1    /* Enables writing to processor mode registers 0 and 1 */
#define     prc2        prcr_addr.bit.b2    /* Enables writing to port P0 direction register */

/*------------------------------------------------------
    Oscillation stop detection register
------------------------------------------------------*/
union byte_def cm2_addr;
#define     cm2         cm2_addr.byte

#define     cm20        cm2_addr.bit.b0     /* Oscillation stop detection bit */
#define     cm21        cm2_addr.bit.b1     /* Oscillation stop detection interrupt enable bit */
#define     cm22        cm2_addr.bit.b2     /* Main clock switch bit */
#define     cm23        cm2_addr.bit.b3     /* Clock monitor bit */

/*------------------------------------------------------
    Watchdog timer control register
------------------------------------------------------*/
union byte_def wdc_addr;
#define     wdc         wdc_addr.byte

#define     wdc7        wdc_addr.bit.b7     /* Prescaler select bit */

/*------------------------------------------------------
    INT0 input filter select register
------------------------------------------------------*/
union byte_def int0f_addr;
#define     int0f        int0f_addr.byte

#define     int0f0      int0f_addr.bit.b0     /* INT0 input filter select bit 0 */
#define     int0f1      int0f_addr.bit.b1     /* INT0 input filter select bit 1 */
#define     int0f2      int0f_addr.bit.b2     /* UART1 receive hardware interrupt enable bit */

/*------------------------------------------------------
    Timer Y, Z output control register
------------------------------------------------------*/
union byte_def tyzmr_addr;
#define     tyzmr        tyzmr_addr.byte

#define     tymod0      tyzmr_addr.bit.b0     /* Timer Y operation mode bit */
#define     tywc        tyzmr_addr.bit.b2     /* Timer Y write control bit */
#define     tys         tyzmr_addr.bit.b3     /* Timer Y count start flag */
#define     tzmod0      tyzmr_addr.bit.b4     /* Timer Z operation mode bit */
#define     tzmod1      tyzmr_addr.bit.b5     /* Timer Z operation mode bit */
#define     tzwc        tyzmr_addr.bit.b6     /* Timer Z write control bit */
#define     tzs         tyzmr_addr.bit.b7     /* Timer Z count start flag */

/*------------------------------------------------------
    Timer Y, Z waveform output control register
------------------------------------------------------*/
union byte_def pum_addr;
#define     pum        pum_addr.byte

#define     typum0     pum_addr.bit.b0        /* Timer Y primary waveform extension control bit */
#define     typum1     pum_addr.bit.b1        /* Timer Y secondary waveform extension control bit */
#define     tzpum0     pum_addr.bit.b2        /* Timer Z primary waveform extension control bit */
#define     tzpum1     pum_addr.bit.b3        /* Timer Z secondary waveform extension control bit */
#define     tyopl      pum_addr.bit.b4        /* Timer Y output level latch */
#define     tzopl      pum_addr.bit.b5        /* Timer Z output level latch */
#define     inostg     pum_addr.bit.b6        /* INT0 pin one-shot trigger control bit */
#define     inoseg     pum_addr.bit.b7        /* INT0 pin one-shot trigger polarity select bit */

/*------------------------------------------------------
    Timer Y, Z output control register
------------------------------------------------------*/
union byte_def tyzoc_addr;
#define     tyzoc       tyzoc_addr.byte

#define     tzos        tyzoc_addr.bit.b0     /* Timer Z one-shot start bit */
#define     tyocnt      tyzoc_addr.bit.b1     /* Timer Y programmable waveform generation output switching bit */
#define     tzocnt      tyzoc_addr.bit.b1     /* Timer Z programmable waveform generation output switching bit */


/*------------------------------------------------------
    Timer X mode register
------------------------------------------------------*/
union byte_def txmr_addr;
#define     txmr        txmr_addr.byte

#define     txmod0      txmr_addr.bit.b0     /* Operation mode select bit 0 */
#define     txmod1      txmr_addr.bit.b1     /* Operation mode select bit 1 */
#define     r0edg       txmr_addr.bit.b2     /* CNTR0 polarity switching bit */
#define     txs         txmr_addr.bit.b3     /* Timer X count start flag */
#define     txocnt      txmr_addr.bit.b4     /* P30/TXOUT select bit */
#define     txmod2      txmr_addr.bit.b5     /* Operation mode select bit 2 */

/*------------------------------------------------------
    Timer count source setting register
------------------------------------------------------*/
union byte_def tcss_addr;
#define     tcss        tcss_addr.byte

#define     txck0       tcss_addr.bit.b0     /* Timer X count source select bit 0 */
#define     txck1       tcss_addr.bit.b1     /* Timer X count source select bit 1 */
#define     tyck0       tcss_addr.bit.b2     /* Timer Y count source select bit 0 */
#define     tyck1       tcss_addr.bit.b3     /* Timer Y count source select bit 1 */
#define     tzck0       tcss_addr.bit.b4     /* Timer Z count source select bit 0 */
#define     tzck1       tcss_addr.bit.b5     /* Timer Z count source select bit 1 */
#define     t1ck0       tcss_addr.bit.b6     /* Timer 1 count source select bit 0 */
#define     t1ck1       tcss_addr.bit.b7     /* Timer 1 count source select bit 1 */

/*------------------------------------------------------
    Clock prescaler reset flag
------------------------------------------------------*/
union byte_def cpsrf_addr;
#define     cpsrf       cpsrf_addr.byte

#define     cpsr        cpsrf_addr.bit.b7   /* Clock prescaler reset flag */

/*------------------------------------------------------
    External input enable register
------------------------------------------------------*/
union byte_def inten_addr;
#define     inten       inten_addr.byte

#define     int0en      inten_addr.bit.b0   /* INT0 input enable bit */
#define     int0pl      inten_addr.bit.b1   /* INT0 input polarity select bit */
#define     int1en      inten_addr.bit.b2   /* INT1 input enable bit */
#define     int1pl      inten_addr.bit.b3   /* INT1 input polarity select bit */
#define     int2en      inten_addr.bit.b4   /* INT2 input enable bit */
#define     int2pl      inten_addr.bit.b5   /* INT2 input polarity select bit */
#define     int3en      inten_addr.bit.b6   /* INT3 input enable bit */
#define     int3pl      inten_addr.bit.b7   /* INT3 input polarity select bit */

/*------------------------------------------------------
    Key input enable register
------------------------------------------------------*/
union byte_def kien_addr;
#define     kien       kien_addr.byte

#define     ki0en      kien_addr.bit.b0   /* KI0 input enable bit */
#define     ki0pl      kien_addr.bit.b1   /* KI0 input polarity select bit */
#define     ki1en      kien_addr.bit.b2   /* KI1 input enable bit */
#define     ki1pl      kien_addr.bit.b3   /* KI1 input polarity select bit */
#define     ki2en      kien_addr.bit.b4   /* KI2 input enable bit */
#define     ki2pl      kien_addr.bit.b5   /* KI2 input polarity select bit */
#define     ki3en      kien_addr.bit.b6   /* KI3 input enable bit */
#define     ki3pl      kien_addr.bit.b7   /* KI3 input polarity select bit */

/*------------------------------------------------------
    Timer C control register 0
------------------------------------------------------*/
union byte_def tcc0_addr;
#define     tcc0       tcc0_addr.byte

#define     tcc00      tcc0_addr.bit.b0   /* Time measurement control bit */
#define     tcc01      tcc0_addr.bit.b1   /* Timer C clock select bit */
#define     tcc02      tcc0_addr.bit.b2   /* Timer C clock select bit */
#define     tcc03      tcc0_addr.bit.b3   /* Time measurement input edge trigger bit */
#define     tcc04      tcc0_addr.bit.b4   /* Time measurement input edge trigger bit */
#define     tcc07      tcc0_addr.bit.b7   /* Time measurement input source switching bit */

/*------------------------------------------------------
    Timer C control register 1
------------------------------------------------------*/
union byte_def tcc1_addr;
#define     tcc1       tcc1_addr.byte

#define     tcc10      tcc1_addr.bit.b0   /* Digital filter clock select bit */
#define     tcc11      tcc1_addr.bit.b1   /* Digital filter clock select bit */

/*------------------------------------------------------
    UART transmit/receive control register 2
------------------------------------------------------*/
union byte_def ucon_addr;
#define     ucon        ucon_addr.byte

#define     u0irs       ucon_addr.bit.b0    /* UART0 transmit interrupt cause select bit */
#define     u1irs       ucon_addr.bit.b1    /* UART1 transmit interrupt cause select bit */
#define     u0rrm       ucon_addr.bit.b2    /* UART0 continuous receive mode enable bit */
#define     u1rrm       ucon_addr.bit.b3    /* UART1 continuous receive mode enable bit */
#define     clkmd0      ucon_addr.bit.b4    /* CLK/CLKS select bit 0 */
#define     clkmd1      ucon_addr.bit.b5    /* CLK/CLKS select bit 1 */
#define     rxd1en      ucon_addr.bit.b6    /* RXD1 input port select bit */

/*------------------------------------------------------
    A-D control register 0
------------------------------------------------------*/
union byte_def adcon0_addr;
#define     adcon0      adcon0_addr.byte

#define     ch0         adcon0_addr.bit.b0  /* Analog input pin select bit */
#define     ch1         adcon0_addr.bit.b1  /* Analog input pin select bit */
#define     ch2         adcon0_addr.bit.b2  /* Analog input pin select bit */
#define     md          adcon0_addr.bit.b3  /* A-D operation mode select bit */
#define     adgsel0     adcon0_addr.bit.b4  /* A-D input group select bit */
#define     adst        adcon0_addr.bit.b6  /* A-D conversion start flag */
#define     cks0        adcon0_addr.bit.b7  /* Frequency select bit 0 */

/*------------------------------------------------------
    A-D control register 1
------------------------------------------------------*/
union byte_def adcon1_addr;
#define     adcon1      adcon1_addr.byte

#define     bits        adcon1_addr.bit.b3  /* 8/10-bit mode select bit */
#define     cks1        adcon1_addr.bit.b4  /* Frequency select bit 1 */
#define     vcut        adcon1_addr.bit.b5  /* Vref connect bit */
#define     opa0        adcon1_addr.bit.b6  /* External op-amp connection mode bit */
#define     opa1        adcon1_addr.bit.b7  /* External op-amp connection mode bit */

/*------------------------------------------------------
    A-D control register 2
------------------------------------------------------*/
union byte_def adcon2_addr;
#define     adcon2      adcon2_addr.byte

#define     smp         adcon2_addr.bit.b0  /* A-D conversion method select bit */

/*------------------------------------------------------
    D-A control register
------------------------------------------------------*/
union byte_def dacon_addr;
#define     dacon       dacon_addr.byte

#define     dae         dacon_addr.bit.b0   /* D-A output enable bit */

/*------------------------------------------------------
    Port P0 register
------------------------------------------------------*/
union byte_def p0_addr;
#define     p0      p0_addr.byte

#define     p0_0        p0_addr.bit.b0      /* Port P00 register */
#define     p0_1        p0_addr.bit.b1      /* Port P01 register */
#define     p0_2        p0_addr.bit.b2      /* Port P02 register */
#define     p0_3        p0_addr.bit.b3      /* Port P03 register */
#define     p0_4        p0_addr.bit.b4      /* Port P04 register */
#define     p0_5        p0_addr.bit.b5      /* Port P05 register */
#define     p0_6        p0_addr.bit.b6      /* Port P06 register */
#define     p0_7        p0_addr.bit.b7      /* Port P07 register */

/*------------------------------------------------------
    Port P0 direction register
------------------------------------------------------*/
union byte_def pd0_addr;
#define     pd0     pd0_addr.byte

#define     pd0_0       pd0_addr.bit.b0     /* Port P00 direction register */
#define     pd0_1       pd0_addr.bit.b1     /* Port P01 direction register */
#define     pd0_2       pd0_addr.bit.b2     /* Port P02 direction register */
#define     pd0_3       pd0_addr.bit.b3     /* Port P03 direction register */
#define     pd0_4       pd0_addr.bit.b4     /* Port P04 direction register */
#define     pd0_5       pd0_addr.bit.b5     /* Port P05 direction register */
#define     pd0_6       pd0_addr.bit.b6     /* Port P06 direction register */
#define     pd0_7       pd0_addr.bit.b7     /* Port P07 direction register */

/*------------------------------------------------------
    Port P1 register
------------------------------------------------------*/
union byte_def p1_addr;
#define     p1      p1_addr.byte

#define     p1_0        p1_addr.bit.b0      /* Port P10 register */
#define     p1_1        p1_addr.bit.b1      /* Port P11 register */
#define     p1_2        p1_addr.bit.b2      /* Port P12 register */
#define     p1_3        p1_addr.bit.b3      /* Port P13 register */
#define     p1_4        p1_addr.bit.b4      /* Port P14 register */
#define     p1_5        p1_addr.bit.b5      /* Port P15 register */
#define     p1_6        p1_addr.bit.b6      /* Port P16 register */
#define     p1_7        p1_addr.bit.b7      /* Port P17 register */

/*------------------------------------------------------
    Port P1 direction register
------------------------------------------------------*/
union byte_def pd1_addr;
#define     pd1     pd1_addr.byte

#define     pd1_0       pd1_addr.bit.b0     /* Port P10 direction register */
#define     pd1_1       pd1_addr.bit.b1     /* Port P11 direction register */
#define     pd1_2       pd1_addr.bit.b2     /* Port P12 direction register */
#define     pd1_3       pd1_addr.bit.b3     /* Port P13 direction register */
#define     pd1_4       pd1_addr.bit.b4     /* Port P14 direction register */
#define     pd1_5       pd1_addr.bit.b5     /* Port P15 direction register */
#define     pd1_6       pd1_addr.bit.b6     /* Port P16 direction register */
#define     pd1_7       pd1_addr.bit.b7     /* Port P17 direction register */

/*------------------------------------------------------
    Port P2 register
------------------------------------------------------*/
union byte_def p2_addr;
#define     p2      p2_addr.byte

#define     p2_0        p2_addr.bit.b0      /* Port P20 register */
#define     p2_1        p2_addr.bit.b1      /* Port P21 register */
//#define     p2_2        p2_addr.bit.b2      /* Port P22 register */
//#define     p2_3        p2_addr.bit.b3      /* Port P23 register */
//#define     p2_4        p2_addr.bit.b4      /* Port P24 register */
//#define     p2_5        p2_addr.bit.b5      /* Port P25 register */
//#define     p2_6        p2_addr.bit.b6      /* Port P26 register */
//#define     p2_7        p2_addr.bit.b7      /* Port P27 register */

/*------------------------------------------------------
    Port P2 direction register
------------------------------------------------------*/
union byte_def pd2_addr;
#define     pd2     pd2_addr.byte

#define     pd2_0       pd2_addr.bit.b0     /* Port P20 direction register */
#define     pd2_1       pd2_addr.bit.b1     /* Port P21 direction register */
//#define     pd2_2       pd2_addr.bit.b2     /* Port P22 direction register */
//#define     pd2_3       pd2_addr.bit.b3     /* Port P23 direction register */
//#define     pd2_4       pd2_addr.bit.b4     /* Port P24 direction register */
//#define     pd2_5       pd2_addr.bit.b5     /* Port P25 direction register */
//#define     pd2_6       pd2_addr.bit.b6     /* Port P26 direction register */
//#define     pd2_7       pd2_addr.bit.b7     /* Port P27 direction register */

/*------------------------------------------------------
    Port P3 register
------------------------------------------------------*/
union byte_def p3_addr;
#define     p3      p3_addr.byte

#define     p3_0        p3_addr.bit.b0      /* Port P30 register */
#define     p3_1        p3_addr.bit.b1      /* Port P31 register */
#define     p3_2        p3_addr.bit.b2      /* Port P32 register */
#define     p3_3        p3_addr.bit.b3      /* Port P33 register */
#define     p3_4        p3_addr.bit.b4      /* Port P34 register */
#define     p3_5        p3_addr.bit.b5      /* Port P35 register */
#define     p3_6        p3_addr.bit.b6      /* Port P36 register */
#define     p3_7        p3_addr.bit.b7      /* Port P37 register */

/*------------------------------------------------------
    Port P3 direction register
------------------------------------------------------*/
union byte_def pd3_addr;
#define     pd3     pd3_addr.byte

#define     pd3_0       pd3_addr.bit.b0     /* Port P30 direction register */
#define     pd3_1       pd3_addr.bit.b1     /* Port P31 direction register */
#define     pd3_2       pd3_addr.bit.b2     /* Port P32 direction register */
#define     pd3_3       pd3_addr.bit.b3     /* Port P33 direction register */
#define     pd3_4       pd3_addr.bit.b4     /* Port P34 direction register */
#define     pd3_5       pd3_addr.bit.b5     /* Port P35 direction register */
#define     pd3_6       pd3_addr.bit.b6     /* Port P36 direction register */
#define     pd3_7       pd3_addr.bit.b7     /* Port P37 direction register */

/*------------------------------------------------------
    Port P4 register
------------------------------------------------------*/
union byte_def p4_addr;
#define     p4      p4_addr.byte

#define     p4_0        p4_addr.bit.b0      /* Port P40 register */
#define     p4_1        p4_addr.bit.b1      /* Port P41 register */
#define     p4_2        p4_addr.bit.b2      /* Port P42 register */
#define     p4_3        p4_addr.bit.b3      /* Port P43 register */
#define     p4_4        p4_addr.bit.b4      /* Port P44 register */
#define     p4_5        p4_addr.bit.b5      /* Port P45 register */
#define     p4_6        p4_addr.bit.b6      /* Port P46 register */
#define     p4_7        p4_addr.bit.b7      /* Port P47 register */

/*------------------------------------------------------
    Port P4 direction register
------------------------------------------------------*/
union byte_def pd4_addr;
#define     pd4     pd4_addr.byte

#define     pd4_0       pd4_addr.bit.b0     /* Port P40 direction register */
#define     pd4_1       pd4_addr.bit.b1     /* Port P41 direction register */
#define     pd4_2       pd4_addr.bit.b2     /* Port P42 direction register */
#define     pd4_3       pd4_addr.bit.b3     /* Port P43 direction register */
#define     pd4_4       pd4_addr.bit.b4     /* Port P44 direction register */
#define     pd4_5       pd4_addr.bit.b5     /* Port P45 direction register */
#define     pd4_6       pd4_addr.bit.b6     /* Port P46 direction register */
#define     pd4_7       pd4_addr.bit.b7     /* Port P47 direction register */

/*------------------------------------------------------
    Pull-up control register 0
------------------------------------------------------*/
union byte_def pur0_addr;
#define     pur0        pur0_addr.byte

#define     pu00        pur0_addr.bit.b0    /* P00 to P03 pull-up */
#define     pu01        pur0_addr.bit.b1    /* P04 to P07 pull-up */
#define     pu02        pur0_addr.bit.b2    /* P10 to P13 pull-up */
#define     pu03        pur0_addr.bit.b3    /* P14 to P17 pull-up */
#define     pu04        pur0_addr.bit.b4    /* P20 to P21 pull-up */
//#define     pu05        pur0_addr.bit.b5    /* P24 to P27 pull-up */
#define     pu06        pur0_addr.bit.b6    /* P30 to P33 pull-up */
#define     pu07        pur0_addr.bit.b7    /* P34 to P37 pull-up */

/*------------------------------------------------------
    Pull-up control register 1
------------------------------------------------------*/
union byte_def pur1_addr;
#define     pur1        pur1_addr.byte

#define     pu10        pur1_addr.bit.b0    /* P40 to P43 pull-up */
#define     pu11        pur1_addr.bit.b1    /* P44 to P47 pull-up */

/*------------------------------------------------------
    Port P1 drive capacity control register
------------------------------------------------------*/
union byte_def drr_addr;
#define     drr     drr_addr.byte

#define     drr0    drr_addr.bit.b0         /* Port P10 drive capacuty */
#define     drr1    drr_addr.bit.b1         /* Port P11 drive capacuty */
#define     drr2    drr_addr.bit.b2         /* Port P12 drive capacuty */
#define     drr3    drr_addr.bit.b3         /* Port P13 drive capacuty */
#define     drr4    drr_addr.bit.b4         /* Port P14 drive capacuty */
#define     drr5    drr_addr.bit.b5         /* Port P15 drive capacuty */
#define     drr6    drr_addr.bit.b6         /* Port P16 drive capacuty */
#define     drr7    drr_addr.bit.b7         /* Port P17 drive capacuty */

/********************************************************
*   declare SFR union                                   *
********************************************************/

/*------------------------------------------------------
    interrupt control registers
------------------------------------------------------*/
union{
    struct{
        char    ilvl0:1;            /* Interrupt priority level select bit */
        char    ilvl1:1;            /* Interrupt priority level select bit */
        char    ilvl2:1;            /* Interrupt priority level select bit */
        char    ir:1;               /* Interrupt request bit */
        char    pol:1;              /* Polarity select bit */
        char    b5:1;
        char    b6:1;
        char    b7:1;
    }bit;
    char    byte;
}kupic_addr,adic_addr,
 s0tic_addr,s0ric_addr,s1tic_addr,s1ric_addr,
 t1ic_addr,txic_addr,tyic_addr,tzic_addr,cntr0ic_addr,tcinic_addr,tcic_addr,
 int0ic_addr,int1ic_addr,int2ic_addr,int3ic_addr;

/*------------------------------------------------------
     kupic
------------------------------------------------------*/
#define     kupic       kupic_addr.byte

#define     ilvl0_kupic kupic_addr.bit.ilvl0    /* Interrupt priority level select bit */
#define     ilvl1_kupic kupic_addr.bit.ilvl1    /* Interrupt priority level select bit */
#define     ilvl2_kupic kupic_addr.bit.ilvl2    /* Interrupt priority level select bit */
#define     ir_kupic    kupic_addr.bit.ir       /* Interrupt request bit */

/*------------------------------------------------------
     adic
------------------------------------------------------*/
#define     adic        adic_addr.byte

#define     ilvl0_adic  adic_addr.bit.ilvl0     /* Interrupt priority level select bit */
#define     ilvl1_adic  adic_addr.bit.ilvl1     /* Interrupt priority level select bit */
#define     ilvl2_adic  adic_addr.bit.ilvl2     /* Interrupt priority level select bit */
#define     ir_adic     adic_addr.bit.ir        /* Interrupt request bit */

/*------------------------------------------------------
     s0tic
------------------------------------------------------*/
#define     s0tic       s0tic_addr.byte

#define     ilvl0_s0tic s0tic_addr.bit.ilvl0    /* Interrupt priority level select bit */
#define     ilvl1_s0tic s0tic_addr.bit.ilvl1    /* Interrupt priority level select bit */
#define     ilvl2_s0tic s0tic_addr.bit.ilvl2    /* Interrupt priority level select bit */
#define     ir_s0tic    s0tic_addr.bit.ir       /* Interrupt request bit */

/*------------------------------------------------------
     s0ric
------------------------------------------------------*/
#define     s0ric       s0ric_addr.byte

#define     ilvl0_s0ric s0ric_addr.bit.ilvl0    /* Interrupt priority level select bit */
#define     ilvl1_s0ric s0ric_addr.bit.ilvl1    /* Interrupt priority level select bit */
#define     ilvl2_s0ric s0ric_addr.bit.ilvl2    /* Interrupt priority level select bit */
#define     ir_s0ric    s0ric_addr.bit.ir       /* Interrupt request bit */

/*------------------------------------------------------
     s1tic
------------------------------------------------------*/
#define     s1tic       s1tic_addr.byte

#define     ilvl0_s1tic s1tic_addr.bit.ilvl0    /* Interrupt priority level select bit */
#define     ilvl1_s1tic s1tic_addr.bit.ilvl1    /* Interrupt priority level select bit */
#define     ilvl2_s1tic s1tic_addr.bit.ilvl2    /* Interrupt priority level select bit */
#define     ir_s1tic    s1tic_addr.bit.ir       /* Interrupt request bit */

/*------------------------------------------------------
     s1ric
------------------------------------------------------*/
#define     s1ric       s1ric_addr.byte

#define     ilvl0_s1ric s1ric_addr.bit.ilvl0    /* Interrupt priority level select bit */
#define     ilvl1_s1ric s1ric_addr.bit.ilvl1    /* Interrupt priority level select bit */
#define     ilvl2_s1ric s1ric_addr.bit.ilvl2    /* Interrupt priority level select bit */
#define     ir_s1ric    s1ric_addr.bit.ir       /* Interrupt request bit */

/*------------------------------------------------------
     t1ic
------------------------------------------------------*/
#define     t1ic       t1ic_addr.byte

#define     ilvl0_t1ic t1ic_addr.bit.ilvl0    /* Interrupt priority level select bit */
#define     ilvl1_t1ic t1ic_addr.bit.ilvl1    /* Interrupt priority level select bit */
#define     ilvl2_t1ic t1ic_addr.bit.ilvl2    /* Interrupt priority level select bit */
#define     ir_t1ic    t1ic_addr.bit.ir       /* Interrupt request bit */

/*------------------------------------------------------
     txic
------------------------------------------------------*/
#define     txic       txic_addr.byte

#define     ilvl0_txic txic_addr.bit.ilvl0    /* Interrupt priority level select bit */
#define     ilvl1_txic txic_addr.bit.ilvl1    /* Interrupt priority level select bit */
#define     ilvl2_txic txic_addr.bit.ilvl2    /* Interrupt priority level select bit */
#define     ir_txic    txic_addr.bit.ir       /* Interrupt request bit */

/*------------------------------------------------------
     tyic
------------------------------------------------------*/
#define     tyic       tyic_addr.byte

#define     ilvl0_tyic tyic_addr.bit.ilvl0    /* Interrupt priority level select bit */
#define     ilvl1_tyic tyic_addr.bit.ilvl1    /* Interrupt priority level select bit */
#define     ilvl2_tyic tyic_addr.bit.ilvl2    /* Interrupt priority level select bit */
#define     ir_tyic    tyic_addr.bit.ir       /* Interrupt request bit */

/*------------------------------------------------------
     tzic
------------------------------------------------------*/
#define     tzic       tzic_addr.byte

#define     ilvl0_tzic tzic_addr.bit.ilvl0    /* Interrupt priority level select bit */
#define     ilvl1_tzic tzic_addr.bit.ilvl1    /* Interrupt priority level select bit */
#define     ilvl2_tzic tzic_addr.bit.ilvl2    /* Interrupt priority level select bit */
#define     ir_tzic    tzic_addr.bit.ir       /* Interrupt request bit */

/*------------------------------------------------------
     cntr0ic
------------------------------------------------------*/
#define     cntr0ic       cntr0ic_addr.byte

#define     ilvl0_cntr0ic cntr0ic_addr.bit.ilvl0    /* Interrupt priority level select bit */
#define     ilvl1_cntr0ic cntr0ic_addr.bit.ilvl1    /* Interrupt priority level select bit */
#define     ilvl2_cntr0ic cntr0ic_addr.bit.ilvl2    /* Interrupt priority level select bit */
#define     ir_cntr0ic    cntr0ic_addr.bit.ir       /* Interrupt request bit */

/*------------------------------------------------------
     tcinic
------------------------------------------------------*/
#define     tcinic       tcinic_addr.byte

#define     ilvl0_tcinic tcinic_addr.bit.ilvl0    /* Interrupt priority level select bit */
#define     ilvl1_tcinic tcinic_addr.bit.ilvl1    /* Interrupt priority level select bit */
#define     ilvl2_tcinic tcinic_addr.bit.ilvl2    /* Interrupt priority level select bit */
#define     ir_tcinic    tcinic_addr.bit.ir       /* Interrupt request bit */

/*------------------------------------------------------
     tcic
------------------------------------------------------*/
#define     tcic       tcic_addr.byte

#define     ilvl0_tcic tcic_addr.bit.ilvl0    /* Interrupt priority level select bit */
#define     ilvl1_tcic tcic_addr.bit.ilvl1    /* Interrupt priority level select bit */
#define     ilvl2_tcic tcic_addr.bit.ilvl2    /* Interrupt priority level select bit */
#define     ir_tcic    tcic_addr.bit.ir       /* Interrupt request bit */

/*------------------------------------------------------
     int0ic
------------------------------------------------------*/
#define     int0ic      int0ic_addr.byte

#define     ilvl0_int0ic    int0ic_addr.bit.ilvl0  /* Interrupt priority level select bit */
#define     ilvl1_int0ic    int0ic_addr.bit.ilvl1  /* Interrupt priority level select bit */
#define     ilvl2_int0ic    int0ic_addr.bit.ilvl2  /* Interrupt priority level select bit */
#define     ir_int0ic       int0ic_addr.bit.ir     /* Interrupt request bit */
#define     pol_int0ic      int0ic_addr.bit.pol    /* Polarity select bit */

/*------------------------------------------------------
     int1ic
------------------------------------------------------*/
#define     int1ic      int1ic_addr.byte

#define     ilvl0_int1ic    int1ic_addr.bit.ilvl0  /* Interrupt priority level select bit */
#define     ilvl1_int1ic    int1ic_addr.bit.ilvl1  /* Interrupt priority level select bit */
#define     ilvl2_int1ic    int1ic_addr.bit.ilvl2  /* Interrupt priority level select bit */
#define     ir_int1ic       int1ic_addr.bit.ir     /* Interrupt request bit */
#define     pol_int1ic      int1ic_addr.bit.pol    /* Polarity select bit */

/*------------------------------------------------------
     int2ic
------------------------------------------------------*/
#define     int2ic      int2ic_addr.byte

#define     ilvl0_int2ic    int2ic_addr.bit.ilvl0  /* Interrupt priority level select bit */
#define     ilvl1_int2ic    int2ic_addr.bit.ilvl1  /* Interrupt priority level select bit */
#define     ilvl2_int2ic    int2ic_addr.bit.ilvl2  /* Interrupt priority level select bit */
#define     ir_int2ic       int2ic_addr.bit.ir     /* Interrupt request bit */
#define     pol_int2ic      int2ic_addr.bit.pol    /* Polarity select bit */

/*------------------------------------------------------
     int3ic
------------------------------------------------------*/
#define     int3ic      int3ic_addr.byte

#define     ilvl0_int3ic    int3ic_addr.bit.ilvl0  /* Interrupt priority level select bit */
#define     ilvl1_int3ic    int3ic_addr.bit.ilvl1  /* Interrupt priority level select bit */
#define     ilvl2_int3ic    int3ic_addr.bit.ilvl2  /* Interrupt priority level select bit */
#define     ir_int3ic       int3ic_addr.bit.ir     /* Interrupt request bit */

/*------------------------------------------------------
    UARTi transmit/receive mode register
------------------------------------------------------*/
union{
    struct{
        char    smd0:1;             /* Serial I/O mode select bit */
        char    smd1:1;             /* Serial I/O mode select bit */
        char    smd2:1;             /* Serial I/O mode select bit */
        char    ckdir:1;            /* Internal/external clock select bit */
        char    stps:1;             /* Stop bit length select bit */
        char    pry:1;              /* Odd/even parity select bit */
        char    prye:1;             /* Parity enable bit */
        char    slep:1;             /* Sleep select bit */
    }bit;
    char    byte;
}u0mr_addr,u1mr_addr;

/*------------------------------------------------------
     u0mr
------------------------------------------------------*/
#define     u0mr        u0mr_addr.byte

#define     smd0_u0mr   u0mr_addr.bit.smd0           /* Serial I/O mode select bit */
#define     smd1_u0mr   u0mr_addr.bit.smd1           /* Serial I/O mode select bit */
#define     smd2_u0mr   u0mr_addr.bit.smd2           /* Serial I/O mode select bit */
#define     ckdir_u0mr  u0mr_addr.bit.ckdir          /* Internal/external clock select bit */
#define     stps_u0mr   u0mr_addr.bit.stps           /* Stop bit length select bit */
#define     pry_u0mr    u0mr_addr.bit.pry            /* Odd/even parity select bit */
#define     prye_u0mr   u0mr_addr.bit.prye           /* Parity enable bit */
#define     slep_u0mr   u0mr_addr.bit.slep           /* Sleep select bit */

/*------------------------------------------------------
     u1mr
------------------------------------------------------*/
#define     u1mr        u1mr_addr.byte

#define     smd0_u1mr   u1mr_addr.bit.smd0          /* Serial I/O mode select bit */
#define     smd1_u1mr   u1mr_addr.bit.smd1          /* Serial I/O mode select bit */
#define     smd2_u1mr   u1mr_addr.bit.smd2          /* Serial I/O mode select bit */
#define     ckdir_u1mr  u1mr_addr.bit.ckdir         /* Internal/external clock select bit */
#define     stps_u1mr   u1mr_addr.bit.stps          /* Stop bit length select bit */
#define     pry_u1mr    u1mr_addr.bit.pry           /* Odd/even parity select bit */
#define     prye_u1mr   u1mr_addr.bit.prye          /* Parity enable bit */
#define     slep_u1mr   u1mr_addr.bit.slep          /* Sleep select bit */

/*------------------------------------------------------
    UARTi transmit/receive control register 0
------------------------------------------------------*/
union{
    struct{
        char    clk0:1;             /* BRG count source select bit */
        char    clk1:1;             /* BRG count source select bit */
        char    b2:1;
        char    txept:1;            /* Transmit register empty flag */
        char    b4:1;
        char    nch:1;              /* Data output select bit */
        char    ckpol:1;            /* CLK polarity select bit */
        char    uform:1;            /* Transfer format select bit */
    }bit;
    char    byte;
}u0c0_addr,u1c0_addr;

/*------------------------------------------------------
     u0c0
------------------------------------------------------*/
#define     u0c0        u0c0_addr.byte

#define     clk0_u0c0   u0c0_addr.bit.clk0          /* BRG count source select bit */
#define     clk1_u0c0   u0c0_addr.bit.clk1          /* BRG count source select bit */
#define     txept_u0c0  u0c0_addr.bit.txept         /* Transmit register empty flag */
#define     nch_u0c0    u0c0_addr.bit.nch           /* Data output select bit */
#define     ckpol_u0c0  u0c0_addr.bit.ckpol         /* CLK polarity select bit */
#define     uform_u0c0  u0c0_addr.bit.uform         /* Transfer format select bit */

/*------------------------------------------------------
     u1c0
------------------------------------------------------*/
#define     u1c0        u1c0_addr.byte

#define     clk0_u1c0   u1c0_addr.bit.clk0          /* BRG count source select bit */
#define     clk1_u1c0   u1c0_addr.bit.clk1          /* BRG count source select bit */
#define     txept_u1c0  u1c0_addr.bit.txept         /* Transmit register empty flag */
#define     nch_u1c0    u1c0_addr.bit.nch           /* Data output select bit */
#define     ckpol_u1c0  u1c0_addr.bit.ckpol         /* CLK polarity select bit */
#define     uform_u1c0  u1c0_addr.bit.uform         /* Transfer format select bit */

/*------------------------------------------------------
    UARTi transmit/receive control register 1
------------------------------------------------------*/
union{
    struct{
        char    te:1;               /* Transmit enable bit */
        char    ti:1;               /* Transmit buffer empty flag */
        char    re:1;               /* Receive enable bit */
        char    ri:1;               /* Receive complete flag */
        char    b4:1;
        char    b5:1;
        char    b6:1;
        char    b7:1;
    }bit;
    char    byte;
}u0c1_addr,u1c1_addr;

/*------------------------------------------------------
     u0c1
------------------------------------------------------*/
#define     u0c1        u0c1_addr.byte

#define     te_u0c1     u0c1_addr.bit.te            /* Transmit enable bit */
#define     ti_u0c1     u0c1_addr.bit.ti            /* Transmit buffer empty flag */
#define     re_u0c1     u0c1_addr.bit.re            /* Receive enable bit */
#define     ri_u0c1     u0c1_addr.bit.ri            /* Receive complete flag */

/*------------------------------------------------------
     u1c1
------------------------------------------------------*/
#define     u1c1        u1c1_addr.byte

#define     te_u1c1     u1c1_addr.bit.te            /* Transmit enable bit */
#define     ti_u1c1     u1c1_addr.bit.ti            /* Transmit buffer empty flag */
#define     re_u1c1     u1c1_addr.bit.re            /* Receive enable bit */
#define     ri_u1c1     u1c1_addr.bit.ri            /* Receive complete flag */

/*------------------------------------------------------
    UARTi receive buffer registers
------------------------------------------------------*/
union{
    struct{
        char    b0:1;
        char    b1:1;
        char    b2:1;
        char    b3:1;
        char    b4:1;
        char    b5:1;
        char    b6:1;
        char    b7:1;
        char    b8:1;
        char    b9:1;
        char    b10:1;
        char    b11:1;
        char    oer:1;              /* Overrun error flag */
        char    fer:1;              /* Framing error flag*/
        char    per:1;              /* Parity error flag */
        char    sum:1;              /* Error sum flag */
    }bit;
    struct{
        char    low;                /* Low  8 bit */
        char    high;               /* High 8 bit */
    }byte;
/*  unsigned short  word;           don't access using word size */
}u0rb_addr,u1rb_addr;

/*------------------------------------------------------
     u0rb
------------------------------------------------------*/
#define     u0rbl       u0rb_addr.byte.low
#define     u0rbh       u0rb_addr.byte.high

#define     oer_u0rb    u0rb_addr.bit.oer           /* Overrun error flag */
#define     fer_u0rb    u0rb_addr.bit.fer           /* Framing error flag*/
#define     per_u0rb    u0rb_addr.bit.per           /* Parity error flag */
#define     sum_u0rb    u0rb_addr.bit.sum           /* Error sum flag */

/*------------------------------------------------------
     u1rb
------------------------------------------------------*/
#define     u1rbl       u1rb_addr.byte.low
#define     u1rbh       u1rb_addr.byte.high

#define     oer_u1rb    u1rb_addr.bit.oer           /* Overrun error flag */
#define     fer_u1rb    u1rb_addr.bit.fer           /* Framing error flag*/
#define     per_u1rb    u1rb_addr.bit.per           /* Parity error flag */
#define     sum_u1rb    u1rb_addr.bit.sum           /* Error sum flag */





/********************************************************
*   declare SFR union                                   *
********************************************************/

union{
    struct{
        char    b0:1;
        char    b1:1;
        char    b2:1;
        char    b3:1;
        char    b4:1;
        char    b5:1;
        char    b6:1;
        char    b7:1;
        char    b8:1;
        char    b9:1;
        char    b10:1;
        char    b11:1;
        char    b12:1;
        char    b13:1;
        char    b14:1;
        char    b15:1;
        char    b16:1;
        char    b17:1;
        char    b18:1;
        char    b19:1;
    }bit;
    struct{
        char    low;                /* low  8 bit */
        char    mid;                /* mid  8 bit */
        char    high;               /* high 8 bit */
        char    nc;                 /* non use */
    }byte;
    unsigned long   dword;
}rmad0_addr,rmad1_addr;

#define     rmad0       rmad0_addr.dword        /* Address match interrupt register 0 32 bit */
#define     rmad0l      rmad0_addr.byte.low         /* Address match interrupt register 0 low  8 bit */
#define     rmad0m      rmad0_addr.byte.mid         /* Address match interrupt register 0 mid  8 bit */
#define     rmad0h      rmad0_addr.byte.high        /* Address match interrupt register 0 high 8 bit */

#define     rmad1       rmad1_addr.dword        /* Address match interrupt register 1 32 bit */
#define     rmad1l      rmad1_addr.byte.low         /* Address match interrupt register 1 low  8 bit */
#define     rmad1m      rmad1_addr.byte.mid         /* Address match interrupt register 1 mid  8 bit */
#define     rmad1h      rmad1_addr.byte.high        /* Address match interrupt register 1 high 8 bit */

union{
    struct{
        char    b0:1;
        char    b1:1;
        char    b2:1;
        char    b3:1;
        char    b4:1;
        char    b5:1;
        char    b6:1;
        char    b7:1;
        char    b8:1;
        char    b9:1;
        char    b10:1;
        char    b11:1;
        char    b12:1;
        char    b13:1;
        char    b14:1;
        char    b15:1;
    }bit;
    struct{
        char    low;                /* low  8 bit */
        char    high;               /* high 8 bit */
    }byte;
    unsigned short  word;
} tc_addr,tm_addr,ad_addr,u0tb_addr,u1tb_addr;

#define     tc     tc_addr.word               /* Timer C register  16 bit */
#define     tcl    tc_addr.byte.low           /* Timer C register  low  8 bit */
#define     tch    tc_addr.byte.high          /* Timer C register  high 8 bit */

#define     tm     tm_addr.word               /* Time measurement register 16 bit */
#define     tml    tm_addr.byte.low           /* Time measurement register  low  8 bit */
#define     tmh    tm_addr.byte.high          /* Time measurement register  high 8 bit */

#define     u0tbl    u0tb_addr.byte.low       /*  don't access using word size */
#define     u0tbh    u0tb_addr.byte.high      /*  don't access using word size */

#define     u1tbl    u1tb_addr.byte.low       /*  don't access using word size */
#define     u1tbh    u1tb_addr.byte.high      /*  don't access using word size */

#define     ad     ad_addr.word               /* A-D register  16 bit */
#define     adl    ad_addr.byte.low           /* A-D register  low  8 bit */
#define     adh    ad_addr.byte.high          /* A-D register  high 8 bit */


