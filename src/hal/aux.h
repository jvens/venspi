/**
 * @file      aux.h
 */


#ifndef RPI_AUX_H
#define RPI_AUX_H

#include "base.h"

/* Although these values were originally from the BCM2835 Arm peripherals PDF
   it's clear that was rushed and has some glaring errors - so these values
   may appear to be different. These values have been changed due to data on
   the elinux BCM2835 datasheet errata:
   http://elinux.org/BCM2835_datasheet_errata */

#define AUX_BASE    ( PERIPHERAL_BASE + 0x215000 )

#define AUX_ENA_MINIUART            ( 1 << 0 )
#define AUX_ENA_SPI1                ( 1 << 1 )
#define AUX_ENA_SPI2                ( 1 << 2 )

#define AUX_IRQ_SPI2                ( 1 << 2 )
#define AUX_IRQ_SPI1                ( 1 << 1 )
#define AUX_IRQ_MU                  ( 1 << 0 )

#define AUX_MULCR_8BIT_MODE         ( 3 << 0 )  /* See errata for this value */
#define AUX_MULCR_BREAK             ( 1 << 6 )
#define AUX_MULCR_DLAB_ACCESS       ( 1 << 7 )

#define AUX_MUMCR_RTS               ( 1 << 1 )

#define AUX_MULSR_DATA_READY        ( 1 << 0 )
#define AUX_MULSR_RX_OVERRUN        ( 1 << 1 )
#define AUX_MULSR_TX_EMPTY          ( 1 << 5 )
#define AUX_MULSR_TX_IDLE           ( 1 << 6 )

#define AUX_MUMSR_CTS               ( 1 << 5 )

#define AUX_MUCNTL_RX_ENABLE        ( 1 << 0 )
#define AUX_MUCNTL_TX_ENABLE        ( 1 << 1 )
#define AUX_MUCNTL_RTS_FLOW         ( 1 << 2 )
#define AUX_MUCNTL_CTS_FLOW         ( 1 << 3 )
#define AUX_MUCNTL_RTS_FIFO         ( 3 << 4 )
#define AUX_MUCNTL_RTS_ASSERT       ( 1 << 6 )
#define AUX_MUCNTL_CTS_ASSERT       ( 1 << 7 )

#define AUX_MUSTAT_SYMBOL_AV        ( 1 << 0 )
#define AUX_MUSTAT_SPACE_AV         ( 1 << 1 )
#define AUX_MUSTAT_RX_IDLE          ( 1 << 2 )
#define AUX_MUSTAT_TX_IDLE          ( 1 << 3 )
#define AUX_MUSTAT_RX_OVERRUN       ( 1 << 4 )
#define AUX_MUSTAT_TX_FIFO_FULL     ( 1 << 5 )
#define AUX_MUSTAT_RTS              ( 1 << 6 )
#define AUX_MUSTAT_CTS              ( 1 << 7 )
#define AUX_MUSTAT_TX_EMPTY         ( 1 << 8 )
#define AUX_MUSTAT_TX_DONE          ( 1 << 9 )
#define AUX_MUSTAT_RX_FIFO_LEVEL    ( 7 << 16 )
#define AUX_MUSTAT_TX_FIFO_LEVEL    ( 7 << 24 )


#define FSEL0(x)        ( x )
#define FSEL1(x)        ( x << 3 )
#define FSEL2(x)        ( x << 6 )
#define FSEL3(x)        ( x << 9 )
#define FSEL4(x)        ( x << 12 )
#define FSEL5(x)        ( x << 15 )
#define FSEL6(x)        ( x << 18 )
#define FSEL7(x)        ( x << 21 )
#define FSEL8(x)        ( x << 24 )
#define FSEL9(x)        ( x << 27 )

#define FSEL10(x)       ( x )
#define FSEL11(x)       ( x << 3 )
#define FSEL12(x)       ( x << 6 )
#define FSEL13(x)       ( x << 9 )
#define FSEL14(x)       ( x << 12 )
#define FSEL15(x)       ( x << 15 )
#define FSEL16(x)       ( x << 18 )
#define FSEL17(x)       ( x << 21 )
#define FSEL18(x)       ( x << 24 )
#define FSEL19(x)       ( x << 27 )

#define FSEL20(x)       ( x )
#define FSEL21(x)       ( x << 3 )
#define FSEL22(x)       ( x << 6 )
#define FSEL23(x)       ( x << 9 )
#define FSEL24(x)       ( x << 12 )
#define FSEL25(x)       ( x << 15 )
#define FSEL26(x)       ( x << 18 )
#define FSEL27(x)       ( x << 21 )
#define FSEL28(x)       ( x << 24 )
#define FSEL29(x)       ( x << 27 )

#define FSEL30(x)       ( x )
#define FSEL31(x)       ( x << 3 )
#define FSEL32(x)       ( x << 6 )
#define FSEL33(x)       ( x << 9 )
#define FSEL34(x)       ( x << 12 )
#define FSEL35(x)       ( x << 15 )
#define FSEL36(x)       ( x << 18 )
#define FSEL37(x)       ( x << 21 )
#define FSEL38(x)       ( x << 24 )
#define FSEL39(x)       ( x << 27 )

#define FSEL40(x)       ( x )
#define FSEL41(x)       ( x << 3 )
#define FSEL42(x)       ( x << 6 )
#define FSEL43(x)       ( x << 9 )
#define FSEL44(x)       ( x << 12 )
#define FSEL45(x)       ( x << 15 )
#define FSEL46(x)       ( x << 18 )
#define FSEL47(x)       ( x << 21 )
#define FSEL48(x)       ( x << 24 )
#define FSEL49(x)       ( x << 27 )

#define FSEL50(x)       ( x )
#define FSEL51(x)       ( x << 3 )
#define FSEL52(x)       ( x << 6 )
#define FSEL53(x)       ( x << 9 )

typedef volatile uint32_t sfr_reg_t;

/**
 * @brief     Mini UART
 * @details   The UART1_CTS and UART1_RX inputs are synchronised and will take 2 system clock cycles 
 *            before they are processed. 
 *
 *            The module does not check for any framing errors. After receiving a start bit and 8 
 *            (or 7) data bits the receiver waits for one half bit time and then starts scanning for 
 *            the next start bit. The mini UART does not check if the stop bit is high or wait for 
 *            the stop bit to appear. As a result of this a UART1_RX input line which is 
 *            continuously low (a break condition or an error in connection or GPIO setup) causes 
 *            the receiver to continuously receive 0x00 symbols. 
 * 
 *            The mini UART uses 8-times oversampling. The Baudrate can be calculated from: 
 *            @f[baudrate = \frac{system\_clock\_freq}{8*(baudrate\_reg + 1)}@f]
 *            If the system clock is 250 MHz and the baud register is zero the baudrate is 31.25 
 *            Mega baud. (25 Mbits/sec or 3.125 Mbytes/sec). The lowest baudrate with a 250 MHz 
 *            system clock is 476 Baud. 
 * 
 *            When writing to the data register only the LS 8 bits are taken. All other bits are 
 *            ignored. When reading from the data register only the LS 8 bits are valid. All other 
 *            bits are zero. 
 */
struct AUX_UART_REGISTERS {
	/**
	 * @brief      Mini Uart I/O Data 
	 * @details    The AUX_MU_IO_REG register is primary used to write data to and read data from 
	 *             the UART FIFOs. If the DLAB bit in the line control register is set this register 
	 *             gives access to the LS 8 bits of the baud rate. (Note: there is easier access to 
	 *             the baud rate register)
	 * 
	 * @bits
	 * @bitn{7:0}  LS 8 bits Baudrate read/write, DLAB=1
	 *      @bit        
	 *                  Access to the LS 8 bits of the 16-bit baudrate register. (Only if bit 7 of 
	 *                  the line control register (DLAB bit) if set)
	 *      @endbit
	 * 
	 * @bitn{7:0}   Transmit data write, DLAB=0
	 *      @bit        
	 *                  Data written is put in the transmit FIFO (Provided it is not full) (Only If 
	 *                  bit 7 of the line control register (DLAB bit) is clear)
	 *      @endbit
	 * 
	 * <dt>        7:0,  Recieve data read, DLAB=0
	 *      @bit        
	 *                  Data read is taken from the receive FIFO (Provided it is not empty) (Only If 
	 *                  bit 7 of the line control register (DLAB bit) is clear)
	 *      @endbit
	 * @endbits
	 */
	sfr_reg_t io;
	/**
	 * @brief      Mini Uart Interrupt Enable 
	 * @details    The AUX_MU_IER_REG register is primary used to enable interrupts. If the DLAB bit 
	 *             in the line control register is set this register gives access to the MS 8 bits 
	 *             of the baud rate. (Note: there is easier access to the baud rate register)
	 *
	 * @bits
	 * @bitn{7:0}  MS 8 bits Baudrate read/write, DLAB=1
	 *      @bit        
	 *                  Access to the MS 8 bits of the 16-bit baudrate register. (Only If bit 7 of 
	 *                  the line control register (DLAB bit) is set)
	 *      @endbit
	 * 
	 * @bitn{1}   Enable receive interrupt (DLAB=0)
	 *      @bit        
	 *                  If this bit is set the interrupt line is asserted whenever the receive FIFO 
	 *                  holds at least 1 byte. If this bit is clear no receive interrupts are 
	 *                  generated.
	 *      @endbit
	 * 
	 * @bitn{0}    Enable transmit interrupt (DLAB=0)
	 *      @bit        
	 *                  If this bit is set the interrupt line is asserted whenever the transmit FIFO 
	 *                  is empty. If this bit is clear no transmit interrupts are generated. 
	 *      @endbit
	 * @endbits
	 */
	sfr_reg_t ier;
	/**
	 * @brief      Mini Uart Interrupt Identify 
	 * @details    The AUX_MU_IIR_REG register shows the interrupt status. It also has two FIFO 
	 *             enable status bits and (when writing) FIFO clear bits. 
	 *
	 * @bits
	 * @bitn{7:6}  FIFO enables
	 * @bit             
	 *                  Both bits always read as 1 as the FIFOs are always enabled 
	 * @endbit
	 *
	 * @bitn{2:1}  Interrupt ID
	 *      @bit        
	 *                  On read this register shows the interrupt ID bit
	 *                   - 00: No interrupts
	 *                   - 01: Transmit holding register empty
	 *                   - 10: Receiver holds valid byte
	 *                   - 11: \<Not possible\>
	 *      @endbit
	 *
	 * @bitn{2:1}  FIFO clear
	 *      @bit        
	 *                  On write:
	 *                   - Writing with bit 1 set will clear the receive FIFO
	 *                   - Writing with bit 2 set will clear the transmit FIFO
	 *      @endbit
	 *
	 * @bitn{0}    Interrupt pending
	 *      @bit        
	 *                  This bit is clear whenever an interrupt is pending
	 *      @endbit
	 */
	sfr_reg_t iir;
	/**
	 * @brief      Mini Uart Line Control 
	 * @details    The AUX_MU_LCR_REG register controls the line data format and gives access to the
	 *             baudrate register.
	 * 
	 * @bits
	 * @bitn{7}   DLAB access
	 *      @bit        
	 *                  If set the first to Mini UART register give access the the Baudrate 
	 *                  register. During operation this bit must be cleared. 
	 *      @endbit
	 *
	 * @bitn{6}   Break
	 *      @bit        
	 *                  If set high the UART1_TX line is pulled low continuously. If held for at 
	 *                  least 12 bits times that will indicate a break condition.
	 *      @endbit
	 *
	 * @bitn{0}   Data size
	 *      @bit        
	 *                  If clear the UART works in 7-bit mode. If set the UART works in 8-bit mode 
	 *      @endbit
	 * @endbits
	 */
	sfr_reg_t lcr;
	/**
	 * @brief      Mini Uart Modem Control 
	 * @details    The AUX_MU_MCR_REG register controls the 'modem' signals. 
	 * 
	 * @bits
	 * @bitn{1}    RTS
	 *      @bit        
	 *                  If clear the UART1_RTS line is high If set the UART1_RTS line is low This 
	 *                  bit is ignored if the RTS is used for auto-flow control. See the Mini Uart 
	 *                  Extra Control register description) 
	 *      @endbit
	 * @endbits
	 */
	sfr_reg_t mcr;
	/**
	 * @brief      Mini Uart Line Status
	 * @details    The AUX_MU_LSR_REG register shows the data status. 
	 * 
	 * @bits
	 * @bitn{6}    Transmitter idle
	 *      @bit        
	 *                  This bit is set if the transmit FIFO is empty and the transmitter is idle. 
	 *                  (Finished shifting out the last bit).
	 *      @endbit
	 *
	 * @bitn{5}    Transmitter empty
	 *      @bit        
	 *                  This bit is set if the transmit FIFO can accept at least one byte. 
	 *      @endbit
	 *
	 * @bitn{1}    Receiver Overrun
	 *      @bit        
	 *                  This bit is set if there was a receiver overrun. That is: one or more 
	 *                  characters arrived whilst the receive FIFO was full. The newly arrived 
	 *                  charters have been discarded. This bit is cleared each time this register 
	 *                  is read. To do a non-destructive read of this overrun bit use the Mini Uart 
	 *                  Extra Status register. 
	 *      @endbit
	 *
	 * @bitn{0}   Data ready
	 *      @bit        
	 *                  This bit is set if the receive FIFO holds at least 1 symbol. 
	 *      @endbit
	 * @endbits
	 */
	sfr_reg_t lsr;
	/**
	 * @brief      Mini Uart Modem Status
	 * @details    The AUX_MU_MSR_REG register shows the 'modem' status. 
	 * 
	 * @bits
	 * @bitn{5}    CTS status
	 *      @bit        
	 *                  This bit is the inverse of the UART1_CTS input thus:
	 *                   - If set the UART1_CTS pin is low
	 *                   - If clear the UART1_CTS pin is high
	 *      @endbit
	 * @endbits
	 */
	sfr_reg_t msr;
	/**
	 * @brief      Mini Uart Scratch 
	 * @details    The AUX_MU_SCRATCH is a single byte storage. 
	 * 
	 * @bits
	 * @bitn{7:0}  Scratch
	 *      @bit        
	 *                  One whole byte extra on top of the 134217728 provided by the SDC 
	 *      @endbit
	 * @endbits
	 */
	sfr_reg_t scratch;
	/**
	 * @brief      Mini Uart Extra Control 
	 * @details    The AUX_MU_CNTL_REG provides access to some extra useful and nice features not
	 *             found on a normal 16550 UART. 
	 * 
	 * @bits
	 * @bitn{7}    CTS assert level
	 *      @bit        
	 *                  This bit allows one to invert the CTS auto flow operation polarity. 
	 *                   - If set the CTS auto flow assert level is low*
	 *                   - If clear the CTS auto flow assert level is high* 
	 *      @endbit
	 *
	 * @bitn{6}    RTS assert level
	 *      @bit        
	 *                  This bit allows one to invert the RTS auto flow operation polarity.
	 *                   - If set the RTS auto flow assert level is low*
	 *                   - If clear the RTS auto flow assert level is high* 
	 *      @endbit
	 *
	 * @bitn{5:4}  RTS AUTO flow level
	 *      @bit        
	 *                  These two bits specify at what receiver FIFO level the RTS line is 
	 *                  de-asserted in auto-flow mode.
	 *                   - 00: De-assert RTS when the receive FIFO has 3 empty spaces left.
	 *                   - 01: De-assert RTS when the receive FIFO has 2 empty spaces left.
	 *                   - 10: De-assert RTS when the receive FIFO has 1 empty space left.
	 *                   - 11: De-assert RTS when the receive FIFO has 4 empty spaces left. 
	 *      @endbit
	 *
	 * @bitn{3}    Enable transmit Auto flow-control using CTS
	 *      @bit        
	 *                  If this bit is set the transmitter will stop if the CTS line is de-asserted. 
	 *                  If this bit is clear the transmitter will ignore the status of the CTS line. 
	 *      @endbit
	 *
	 * @bitn{2}    Enable receive Auto flow-control using RTS
	 *      @bit        
	 *                  If this bit is set the RTS line will de-assert if the receive FIFO reaches 
	 *                  it 'auto flow' level. In fact the RTS line will behave as an RTR (Ready To 
	 *                  Receive) line. If this bit is clear the RTS line is controlled by the 
	 *                  AUX_MU_MCR_REG register bit 1. 
	 *      @endbit
	 *
	 * @bitn{1}    Transmitter enable
	 *      @bit        
	 *                  If this bit is set the mini UART transmitter is enabled. If this bit is 
	 *                  clear the mini UART transmitter is disabled 
	 *      @endbit
	 *
	 * @bitn{0}    Receiver enable
	 *      @bit        
	 *                  If this bit is set the mini UART receiver is enabled. If this bit is clear 
	 *                  the mini UART receiver is disabled
	 *      @endbit
	 * @endbits
	 * 
	 * @par        Receiver enable 
	 *                  If this bit is set no new symbols will be accepted by the receiver. Any symbols in progress of reception will be finished. 
	 * @par        Transmitter enable
	 *                  If this bit is set no new symbols will be send the transmitter. Any symbols in progress of transmission will be finished. 
	 * @par        Auto flow control
	 *                  Automatic flow control can be enabled independent for the receiver and the transmitter. 
	 * 
	 *                  CTS auto flow control impacts the transmitter only. The transmitter will not send out new symbols when the CTS line is de-asserted. Any symbols in progress of transmission when the CTS line becomes de-asserted will be finished. 
	 * 
	 *                  RTS auto flow control impacts the receiver only. In fact the name RTS for the control line is incorrect and should be RTR (Ready to Receive). The receiver will de-asserted the RTS (RTR) line when its receive FIFO has a number of empty spaces left. Normally 3 empty spaces should be enough. 
	 * 
	 *                  If looping back a mini UART using full auto flow control the logic is fast enough to allow the RTS auto flow level of '10' (De-assert RTS when the receive FIFO has 1 empty space left). 
	 * 
	 * @par        Auto flow polarity
	 *                  To offer full flexibility the polarity of the CTS and RTS (RTR) lines can be programmed. This should allow the mini UART to interface with any existing hardware flow control available. 
	 */
	sfr_reg_t cntl;
	/**
	 * @brief      Mini Uart Extra Status 
	 * @details    The AUX_MU_STAT_REG provides a lot of useful information about the internal 
	 *             status of the mini UART not found on a normal 16550 UART. 
	 * 
	 * @bits
	 * @bitn{27:24} Transmit FIFO fill level
	 *      @bit        
	 *                  These bits shows how many symbols are stored in the transmit FIFO The value 
	 *                  is in the range 0-8 
	 *      @endbit
	 *
	 * @bitn{19:16} Receive FIFO fill level
	 *      @bit        
	 *                  These bits shows how many symbols are stored in the receive FIFO The value 
	 *                  is in the range 0-8 
	 *      @endbit
	 *
	 * @bitn{9}    Transmitter done
	 *      @bit        
	 *                  This bit is set if the transmitter is idle and the transmit FIFO is empty. 
	 *                  It is a logic AND of bits 2 and 8 
	 *      @endbit
	 *
	 * @bitn{8}    Transmit FIFO is empty
	 *      @bit        
	 *                  If this bit is set the transmitter FIFO is empty. Thus it can accept 8 
	 *                  symbols. 
	 *      @endbit
	 *
	 * @bitn{7}    CTS line
	 *      @bit        
	 *                  This bit shows the status of the UART1_CTS line. 
	 *      @endbit
	 *
	 * @bitn{6}    RTS status
	 *      @bit        
	 *                  This bit shows the status of the UART1_RTS line. 
	 *      @endbit
	 *
	 * @bitn{5}    Transmit FIFO is full
	 *      @bit        
	 *                  This is the inverse of bit 1 
	 *      @endbit
	 *
	 * @bitn{4}    Receiver overrun
	 *      @bit        
	 *                  This bit is set if there was a receiver overrun. That is: one or more 
	 *                  characters arrived whilst the receive FIFO was full. The newly arrived 
	 *                  characters have been discarded. This bit is cleared each time the 
	 *                  AUX_MU_LSR_REG register is read. 
	 *      @endbit
	 *
	 * @bitn{3}    Transmitter is idle
	 *      @bit        
	 *                  If this bit is set the transmitter is idle. If this bit is clear the 
	 *                  transmitter is idle. 
	 *      @endbit
	 *
	 * @bitn{2}    Receiver is idle
	 *      @bit        
	 *                  If this bit is set the receiver is idle. If this bit is clear the receiver 
	 *                  is busy. This bit can change unless the receiver is disabled 
	 *      @endbit
	 *
	 * @bitn{1}    Space available
	 *      @bit        
	 *                  If this bit is set the mini UART transmitter FIFO can accept at least one 
	 *                  more symbol. If this bit is clear the mini UART transmitter FIFO is full 
	 *      @endbit
	 *
	 * @bitn{0}    Symbol available
	 *      @bit        
	 *                  If this bit is set the mini UART receive FIFO contains at least 1 symbol If 
	 *                  this bit is clear the mini UART receiver FIFO is empty       
	 *      @endbit
	 * @endbits          
	 * 
	 * @par        Receiver is idle
	 *                  This bit is only useful if the receiver is disabled. The normal use is to disable the receiver. Then check (or wait) until the bit is set. Now you can be sure that no new symbols will arrive. (e.g. now you can change the baudrate...) 
	 * 
	 * @par        Transmitter is idle
	 *                  This bit tells if the transmitter is idle. Note that the bit will set only for a short time if the transmit FIFO contains data. Normally you want to use bit 9: Transmitter done. 
	 * 
	 * @par        RTS status
	 *                  This bit is useful only in receive Auto flow-control mode as it shows the status of the RTS line.
	 */
	sfr_reg_t stat;
	/**
	 * @brief      Mini Uart Baudrate 
	 * @details    The AUX_MU_BAUD register allows direct access to the 16-bit wide baudrate 
	 *             counter. 
	 * 
	 * @bits
	 * @bitn{15:0} Baudrate
	 *      @bit        
	 *                  mini UART baudrate counter
	 *      @endbit
	 * @endbits
	 * 
	 * @par        This is the same register as is accessed using the LABD bit and the first two register, but much easier to access. 
	 */
	sfr_reg_t baud;
};





/**
 * @brief     
 * @details   
 */
struct AUX_SPI_REGISTERS {
	/**
	 * @brief      SPI Control register 0 
	 * @details    The AUXSPIx_CNTL0 register control many features of the SPI interfaces. 
	 * 
	 * @bits
	 * @bitn{31:20} Speed
	 *      @bit
	 *                  Sets the SPI clock speed. 
	 *                  @f$spi\_clk\_freq=frac{system\_clock\_freq}{2*(speed+1)}@f$
	 *      @endbit
	 * 
	 * @bitn{19:17} Chip Selects
	 *      @bit
	 *                  The pattern output on the CS pins when active. 
	 *      @endbit
	 * 
	 * @bitn{16}   Post-input mode
	 *      @bit
	 *                  If set the SPI input works in post input mode. For details see text further 
	 *                  down 
	 *      @endbit
	 * 
	 * @bitn{15}   Variable CS
	 *      @bit
	 *                  If 1 the SPI takes the CS pattern and the data from the TX fifo. If 0 the 
	 *                  SPI takes the CS pattern from bits 17-19 of this register. Set this bit only 
	 *                  if also bit 14 (variable width) is set 
	 *      @endbit
	 * 
	 * @bitn{14}   Variable width
	 *      @bit
	 *                  If 1 the SPI takes the shift length and the data from the TX fifo. If 0 the 
	 *                  SPI takes the shift length from bits 0-5 of this register.
	 *      @endbit
	 * 
	 * @bitn{13:12} DOUT Hold time
	 *      @bit
	 *                  Controls the extra DOUT hold time in system clock cycles.
	 *                   - 00: No extra hold time
	 *                   - 01: 1 system clock extra hold time
	 *                   - 10: 4 system clocks extra hold time
	 *                   - 11: 7 system clocks extra hold time 
	 *      @endbit
	 * 
	 * @bitn{11}   Enable
	 *      @bit
	 *                  Enables the SPI interface. Whilst disabled the FIFOs can still be written to 
	 *                  or read from. This bit should be 1 during normal operation. 
	 *      @endbit
	 * 
	 * @bitn{10}   In rising
	 *      @bit
	 *                  If 1 data is clocked in on the rising edge of the SPI clock. If 0 data is 
	 *                  clocked in on the falling edge of the SPI clock.
	 *      @endbit
	 * 
	 * @bitn{9}    Clear FIFOs
	 *      @bit
	 *                  If 1 the receive and transmit FIFOs are held in reset (and thus flushed.). 
	 *                  This bit should be 0 during normal operation. 
	 *      @endbit
	 * 
	 * @bitn{8}    Out rising
	 *      @bit
	 *                  If 1 data is clocked out on the rising edge of the SPI clock. If 0 data is 
	 *                  clocked out on the falling edge of the SPI clock.
	 *      @endbit
	 * 
	 * @bitn{7}    Invert SPI CLK
	 *      @bit
	 *                  If 1 the 'idle' clock line state is high. If 0 the 'idle' clock line state 
	 *                  is low. 
	 *      @endbit
	 * 
	 * @bitn{6}    Shift out MS bit first
	 *      @bit
	 *                  If 1 the data is shifted out starting with the MS bit. (bit 15 or bit 11). 
	 *                  If 0 the data is shifted out starting with the LS bit. (bit 0).
	 *      @endbit
	 * 
	 * @bitn{5:0}  Shift length
	 *      @bit
	 *                  Specifies the number of bits to shift. This field is ignored when using 
	 *                  'variable shift' mode.
	 *      @endbit
	 * @endbits
	 */
	sfr_reg_t cntl0;
	/**
	 * @brief      SPI Control register 1 
	 * @details    The AUXSPIx_CNTL1 registers control more features of the SPI interfaces. 
	 * 
	 * @bits
	 * @bitn{10:8} CS high time
	 *      @bit
	 *                  Additional SPI clock cycles where the CS is high.
	 *      @endbit
	 * @bitn{7}    TX empty IRQ
	 *      @bit
	 *                  If 1 the interrupt line is high when the transmit FIFO is empty 
	 *      @endbit
	 * @bitn{6}    Done IRQ
	 *      @bit
	 *                  If 1 the interrupt line is high when the interface is idle
	 *      @endbit
	 * @bitn{1}    Shift in MS bit first
	 *      @bit
	 *                  If 1 the data is shifted in starting with the MS bit (bit 15). If 0 the data 
	 *                  is shifted in starting with the LS bit (bit 0) 
	 *      @endbit
	 * @bitn{0}    Key input
	 *      @bit
	 *                  If 1 the receiver shift register is NOT cleared. Thus new data is 
	 *                  concatenated to old data. If 0 the receiver shift register is cleared before 
	 *                  each transaction. 
	 *      @endbit
	 * @endbits
	 */
	sfr_reg_t cntl1;
	/**
	 * @brief      SPI Status 
	 * @details    The AUXSPIx_STAT registers show the status of the SPI interfaces. 
	 * 
	 * @bits
	 * @bitn{31:24} TX FIFO level
	 *      @bit
	 *                  The number of data units in the transmit data FIFO. 
	 *      @endbit
	 * @bitn{23:12} RX FIFO level
	 *      @bit
	 *                  The number of data units in the receive data FIFO. 
	 *      @endbit
	 * @bitn{4}    TX Full
	 *      @bit
	 *                  If 1 the transmit FIFO is full. If 0 the transmit FIFO can accept at least 
	 *      @endbit
	 *                  1 data unit. 
	 * @bitn{3}    TX Empty
	 *      @bit
	 *                  If 1 the transmit FIFO is empty. If 0 the transmit FIFO holds at least 1 
	 *                  data unit. 
	 *      @endbit
	 * @bitn{2}    RX Empty
	 *      @bit
	 *                  If 1 the receiver FIFO is empty. If 0 the receiver FIFO holds at least 1 
	 *                  data unit. 
	 *      @endbit
	 * @bitn{6}    Busy
	 *      @bit
	 *                  Indicates the module is busy transferring data. 
	 *      @endbit
	 * @bitn{5:0}  Bit count
	 *      @bit
	 *                  The number of bits still to be processed. Starts with 'shift-length' and 
	 *                  counts down. 
	 *      @endbit
	 * @endbits
	 */
	sfr_reg_t stat;
	/**
	 * @brief      SPI Data
	 * @details    The AUXSPIx_PEEK registers show received data of the SPI interfaces. 
	 * 
	 * @bits
	 * @bitn{15:0} Data
	 *      @bit
	 *                  Reads from this address will show the top entry from the receive FIFO, but 
	 *                  the data is not taken from the FIFO. This provides a means of inspecting the 
	 *                  data but not removing it from the FIFO. 
	 *      @endbit
	 * @endbits
	 */
	sfr_reg_t io;
	/**
	 * @brief      SPI Peek 
	 * @details    The AUXSPIx_IO registers are the primary data port of the SPI interfaces. These 
	 *             four addresses all write to the same FIFO. 
	 * 
	 * @bits
	 * @bitn{15:0} Data
	 *      @bit
	 *                  Writes to this address range end up in the transmit FIFO. Data is lost when 
	 *                  writing whilst the transmit FIFO is full. Reads from this address will take 
	 *                  the top entry from the receive FIFO. Reading whilst the receive FIFO is will 
	 *                  return the last data received. 
	 *      @endbit
	 * @endbits
	 */
	sfr_reg_t peek;
};

/**
 * @brief     
 * @details   There are two Auxiliary registers which control all three devices. One is the interrupt status register, the second is the Auxiliary enable register. The Auxiliary IRQ status register can help to hierarchically determine the source of an interrupt.
 * 
 *            If the enable bits are clear you will have no access to a peripheral. You can not even read or write the registers!
 * 
 *            GPIO pins should be set up first the before enabling the UART. The UART core is build to emulate 16550 behaviour. So when it is enabled any data at the inputs will immediately be received . If the UART1_RX line is low (because the GPIO pins have not been set-up yet) that will be seen as a start bit and the UART will start receiving 0x00-characters. 
 *
 *            Valid stops bits are not required for the UART. (See also Implementation details). Hence any bit status is acceptable as stop bit and is only used so there is clean timing start for the next bit. 
 *
 *            Looking after a reset: the baudrate will be zero and the system clock will be 250 MHz. So only 2.5 µseconds suffice to fill the receive FIFO. The result will be that the FIFO is full and overflowing in no time flat. 
 */
struct AUX_REGISTERS {
	/**
	 * @brief      Auxiliary Interrupt status 
	 * @details    The AUXIRQ register is used to check any pending interrupts which may be 
	 *             asserted by the three Auxiliary sub blocks. 
	 * 
	 * @bits
	 * @bitn{2}    SPI 2 IRQ
	 *      @bit
	 *                  If set the SPI2 module has an interrupt pending.
	 *      @endbit
	 * @bitn{1}    SPI 1 IRQ
	 *      @bit
	 *                  If set the SPI1 module has an interrupt pending.
	 *      @endbit
	 * @bitn{0}    Mini UART IRQ 
	 *      @bit
	 *                  If set the mini UART has an interrupt pending. 
	 *      @endbit
	 * @endbits
	 */
	sfr_reg_t irq;
	/**
	 * @brief      Auxiliary enables 
	 * @details    The AUXENB register is used to enable the three modules; UART, SPI1, SPI2. 
	 * 
	 * @bits
	 * @bitn{2}    SPI 2 enable
	 *      @bit
	 *                  If set the SPI 2 module is enabled. If clear the SPI 2 module is disabled. 
	 *                  That also disables any SPI 2 module register access
	 *      @endbit
	 * @bitn{1}    SPI 1 enable
	 *      @bit
	 *                  If set the SPI 1 module is enabled. If clear the SPI 1 module is disabled. 
	 *                  That also disables any SPI 1 module register access
	 *      @endbit
	 * @bitn{0}    Mini UART enable
	 *      @bit
	 *                  If set the mini UART is enabled. The UART will immediately start receiving 
	 *                  data, especially if the UART1_RX line is low. If clear the mini UART is 
	 *                  disabled. That also disables any mini UART register access 
	 *      @endbit
	 * @endbits
	 */
	sfr_reg_t enables;

	/**
	 * @brief      Mini UART register set
	 * @details    
	 */
	sfr_reg_t reserved1[((0x40 - 0x04) / 4) - 1];

	struct AUX_UART_REGISTERS mini_uart;

	sfr_reg_t reserved2[(0x80 - 0x68) / 4];

	/**
	 * @brief      SPI 0 register set 
	 * @details    
	 */
	struct AUX_SPI_REGISTERS spi0;

	sfr_reg_t reserved3[(0xC0 - 0x94) / 4];

	/**
	 * @brief      SPI 1 register set 
	 * @details    
	 */
	struct AUX_SPI_REGISTERS spi1;
};


typedef void aux_t;
extern aux_t* RPI_GetAux( void );
extern void RPI_AuxMiniUartInit( int baud, int bits );
extern void RPI_AuxMiniUartWrite( char c );

#endif
