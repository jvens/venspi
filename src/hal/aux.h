/**
 * @file      aux.h
 */

/*

    Part of the Raspberry-Pi Bare Metal Tutorials
    Copyright (c) 2013-2015, Brian Sidebotham
    All rights reserved.

    Redistribution and use in source and binary forms, with or without
    modification, are permitted provided that the following conditions are met:

    1. Redistributions of source code must retain the above copyright notice,
        this list of conditions and the following disclaimer.

    2. Redistributions in binary form must reproduce the above copyright notice,
        this list of conditions and the following disclaimer in the
        documentation and/or other materials provided with the distribution.

    THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
    AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
    IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
    ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
    LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
    CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
    SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
    INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
    CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
    ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
    POSSIBILITY OF SUCH DAMAGE.

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
	 * <dl>
	 * <dt>        7:0,  LS 8 bits Baudrate read/write, DLAB=1</dt>
	 *              <dd>Access to the LS 8 bits of the 16-bit baudrate register. (Only if bit 7 of 
	 *                  the line control register (DLAB bit) if set)</dd>
	 * <dt>        7:0,  Transmit data write, DLAB=0</dt>
	 *              <dd>Data written is put in the transmit FIFO (Provided it is not full) (Only If 
	 *                  bit 7 of the line control register (DLAB bit) is clear)</dd>
	 * <dt>        7:0,  Recieve data read, DLAB=0</dt>
	 *              <dd>Data read is taken from the receive FIFO (Provided it is not empty) (Only If 
	 *                  bit 7 of the line control register (DLAB bit) is clear) </dd>
	 * </dl>
	 */
	sfr_reg_t io;
	/**
	 * @brief      Mini Uart Interrupt Enable 
	 * @details    The AUX_MU_IER_REG register is primary used to enable interrupts. If the DLAB bit 
	 *             in the line control register is set this register gives access to the MS 8 bits 
	 *             of the baud rate. (Note: there is easier access to the baud rate register)
	 *
	 * @bits
	 *             @bitn{7:0}  MS 8 bits Baudrate read/write, DLAB=1
	 *             @bit Access to the MS 8 bits of the 16-bit baudrate register. (Only If bit 7 of 
	 *                  the line control register (DLAB bit) is set)
	 *             @endbit
	 *             @bitn{1}  Enable receive interrupt (DLAB=0)
	 *             @bit If this bit is set the interrupt line is asserted whenever the receive FIFO 
	 *                  holds at least 1 byte. If this bit is clear no receive interrupts are 
	 *             @endbit
	 *                  generated.
	 *             @bitn{0}  Enable transmit interrupt (DLAB=0)
	 *             @bit If this bit is set the interrupt line is asserted whenever the transmit FIFO 
	 *                  is empty. If this bit is clear no transmit interrupts are generated. 
	 *             @endbit
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
	 * @bit             Both bits always read as 1 as the FIFOs are always enabled 
	 * @endbit
	 *
	 * @bitn{2:1}  Interrupt ID
	 * @bit             On read this register shows the interrupt ID bit
	 *                   - 00: No interrupts
	 *                   - 01: Transmit holding register empty
	 *                   - 10: Receiver holds valid byte
	 *                   - 11: \<Not possible\>
	 * @endbit
	 *
	 * @bitn{2:1}  FIFO clear
	 * @bit             On write:
	 *                   - Writing with bit 1 set will clear the receive FIFO
	 *                   - Writing with bit 2 set will clear the transmit FIFO
	 * @endbit
	 *
	 * @bitn{0}    Interrupt pending
	 * @bit             This bit is clear whenever an interrupt is pending
	 * @endbit
	 */
	sfr_reg_t iir;
	/**
	 * @brief      Mini Uart Line Control 
	 * @details    The AUX_MU_LCR_REG register controls the line data format and gives access to the
	 *             baudrate register.
	 * @bit        7  DLAB access
	 *                  If set the first to Mini UART register give access the the Baudrate 
	 *                  register. During operation this bit must be cleared. 
	 * @bit        6  Break
	 *                  If set high the UART1_TX line is pulled low continuously. If held for at 
	 *                  least 12 bits times that will indicate a break condition.
	 * @bit        0 Data size
	 *                  If clear the UART works in 7-bit mode. If set the UART works in 8-bit mode 
	 */
	sfr_reg_t lcr;
	/**
	 * @brief      Mini Uart Modem Control 
	 * @details    The AUX_MU_MCR_REG register controls the 'modem' signals. 
	 * @bit        1  RTS
	 *                  If clear the UART1_RTS line is high If set the UART1_RTS line is low This 
	 *                  bit is ignored if the RTS is used for auto-flow control. See the Mini Uart 
	 *                  Extra Control register description) 
	 */
	sfr_reg_t mcr;
	/**
	 * @brief      Mini Uart Line Status
	 * @details    The AUX_MU_LSR_REG register shows the data status. 
	 * @bit        6  Transmitter idle
	 *                  This bit is set if the transmit FIFO is empty and the transmitter is idle. 
	 *                  (Finished shifting out the last bit).
	 * @bit        5  Transmitter empty
	 *                  This bit is set if the transmit FIFO can accept at least one byte. 
	 * @bit        1  Receiver Overrun
	 *                  This bit is set if there was a receiver overrun. That is: one or more 
	 *                  characters arrived whilst the receive FIFO was full. The newly arrived 
	 *                  charters have been discarded. This bit is cleared each time this register 
	 *                  is read. To do a non-destructive read of this overrun bit use the Mini Uart 
	 *                  Extra Status register. 
	 * @bit        0  Data ready
	 *                  This bit is set if the receive FIFO holds at least 1 symbol. 
	 */
	sfr_reg_t lsr;
	/**
	 * @brief      Mini Uart Modem Status
	 * @details    The AUX_MU_MSR_REG register shows the 'modem' status. 
	 * @bit        5  CTS status
	 *                  This bit is the inverse of the UART1_CTS input thus:
	 *                   - If set the UART1_CTS pin is low
	 *                   - If clear the UART1_CTS pin is high
	 */
	sfr_reg_t msr;
	/**
	 * @brief      Mini Uart Scratch 
	 * @details    The AUX_MU_SCRATCH is a single byte storage. 
	 * @bit        7:0  Scratch
	 *                  One whole byte extra on top of the 134217728 provided by the SDC 
	 */
	sfr_reg_t scratch;
	/**
	 * @brief      Mini Uart Extra Control 
	 * @details    The AUX_MU_CNTL_REG provides access to some extra useful and nice features not
	 *             found on a normal 16550 UART. 
	 * @bit        7  CTS assert level
	 *                  This bit allows one to invert the CTS auto flow operation polarity. 
	 *                   - If set the CTS auto flow assert level is low*
	 *                   - If clear the CTS auto flow assert level is high* 
	 * @bit        6  RTS assert level
	 *                  This bit allows one to invert the RTS auto flow operation polarity.
	 *                   - If set the RTS auto flow assert level is low*
	 *                   - If clear the RTS auto flow assert level is high* 
	 * @bit        5:4  RTS AUTO flow level
	 *                  These two bits specify at what receiver FIFO level the RTS line is 
	 *                  de-asserted in auto-flow mode.
	 *                   - 00: De-assert RTS when the receive FIFO has 3 empty spaces left.
	 *                   - 01: De-assert RTS when the receive FIFO has 2 empty spaces left.
	 *                   - 10: De-assert RTS when the receive FIFO has 1 empty space left.
	 *                   - 11: De-assert RTS when the receive FIFO has 4 empty spaces left. 
	 * @bit        3  Enable transmit Auto flow-control using CTS
	 *                  If this bit is set the transmitter will stop if the CTS line is de-asserted. 
	 *                  If this bit is clear the transmitter will ignore the status of the CTS line 
	 * @bit        2  Enable receive Auto flow-control using RTS
	 *                  If this bit is set the RTS line will de-assert if the receive FIFO reaches 
	 *                  it 'auto flow' level. In fact the RTS line will behave as an RTR (Ready To 
	 *                  Receive) line. If this bit is clear the RTS line is controlled by the 
	 *                  AUX_MU_MCR_REG register bit 1. 
	 * @bit        1  Transmitter enable
	 *                  If this bit is set the mini UART transmitter is enabled. If this bit is 
	 *                  clear the mini UART transmitter is disabled 
	 * @bit        0  Receiver enable
	 *                  If this bit is set the mini UART receiver is enabled. If this bit is clear 
	 *                  the mini UART receiver is disabled
	 */
	sfr_reg_t cntl;
	/**
	 * @brief      Mini Uart Extra Status 
	 * @details    The AUX_MU_STAT_REG provides a lot of useful information about the internal 
	 *             status of the mini UART not found on a normal 16550 UART. 
	 * @bit        27:24  Transmit FIFO fill level
	 *                  These bits shows how many symbols are stored in the transmit FIFO The value 
	 *                  is in the range 0-8 
	 * @bit        19:16  Receive FIFO fill level
	 *                  These bits shows how many symbols are stored in the receive FIFO The value 
	 *                  is in the range 0-8 
	 * @bit        9  Transmitter done
	 *                  This bit is set if the transmitter is idle and the transmit FIFO is empty. 
	 *                  It is a logic AND of bits 2 and 8 
	 * @bit        8  Transmit FIFO is empty
	 *                  If this bit is set the transmitter FIFO is empty. Thus it can accept 8 
	 *                  symbols. 
	 * @bit        7  CTS line
	 *                  This bit shows the status of the UART1_CTS line. 
	 * @bit        6  RTS status
	 *                  This bit shows the status of the UART1_RTS line. 
	 * @bit        5  Transmit FIFO is full
	 *                  This is the inverse of bit 1 
	 * @bit        4  Receiver overrun
	 *                  This bit is set if there was a receiver overrun. That is: one or more 
	 *                  characters arrived whilst the receive FIFO was full. The newly arrived 
	 *                  characters have been discarded. This bit is cleared each time the 
	 *                  AUX_MU_LSR_REG register is read. 
	 * @bit        3  Transmitter is idle
	 *                  If this bit is set the transmitter is idle. If this bit is clear the 
	 *                  transmitter is idle. 
	 * @bit        2  Receiver is idle
	 *                  If this bit is set the receiver is idle. If this bit is clear the receiver 
	 *                  is busy. This bit can change unless the receiver is disabled 
	 * @bit        1  Space available
	 *                  If this bit is set the mini UART transmitter FIFO can accept at least one 
	 *                  more symbol. If this bit is clear the mini UART transmitter FIFO is full 
	 * @bit        0  Symbol available
	 *                  If this bit is set the mini UART receive FIFO contains at least 1 symbol If 
	 *                  this bit is clear the mini UART receiver FIFO is empty                  	 
	 */
	sfr_reg_t stat;
	/**
	 * @brief      Mini Uart Baudrate 
	 * @details    The AUX_MU_BAUD register allows direct access to the 16-bit wide baudrate 
	 *             counter. 
	 * @bit        15:0  Baudrate
	 *                  mini UART baudrate counter
	 */
	sfr_reg_t baud;
};

struct AUX_SPI_REGISTERS {
	/**
	 * @brief      SPI Control register 0 
	 * @details    The AUXSPIx_CNTL0 register control many features of the SPI interfaces. 
	 * @bit        31:20  Speed
	 *                  Sets the SPI clock speed. 
	 *                  @f$spi clk freq=frac{system clock freq}{2*(speed+1)}@f$
	 * @bit        19:17  Chip Selects
	 *                  The pattern output on the CS pins when active. 
	 * @bit        16  Post-input mode
	 *                  If set the SPI input works in post input mode. For details see text further 
	 *                  down 
	 * @bit        15  Variable CS
	 *                  If 1 the SPI takes the CS pattern and the data from the TX fifo. If 0 the 
	 *                  SPI takes the CS pattern from bits 17-19 of this register. Set this bit only 
	 *                  if also bit 14 (variable width) is set 
	 * @bit        14  Variable width
	 *                  If 1 the SPI takes the shift length and the data from the TX fifo. If 0 the 
	 *                  SPI takes the shift length from bits 0-5 of this register.
	 * @bit        13:12  DOUT Hold time
	 *                  Controls the extra DOUT hold time in system clock cycles.
	 *                   - 00: No extra hold time
	 *                   - 01: 1 system clock extra hold time
	 *                   - 10: 4 system clocks extra hold time
	 *                   - 11: 7 system clocks extra hold time 
	 * @bit        11  Enable
	 *                  Enables the SPI interface. Whilst disabled the FIFOs can still be written to 
	 *                  or read from. This bit should be 1 during normal operation. 
	 * @bit        10  In rising
	 *                  If 1 data is clocked in on the rising edge of the SPI clock. If 0 data is 
	 *                  clocked in on the falling edge of the SPI clock.
	 * @bit        9  Clear FIFOs
	 *                  If 1 the receive and transmit FIFOs are held in reset (and thus flushed.). 
	 *                  This bit should be 0 during normal operation. 
	 * @bit        8  Out rising
	 *                  If 1 data is clocked out on the rising edge of the SPI clock. If 0 data is 
	 *                  clocked out on the falling edge of the SPI clock.
	 * @bit        7  Invert SPI CLK
	 *                  If 1 the 'idle' clock line state is high. If 0 the 'idle' clock line state 
	 *                  is low. 
	 * @bit        6  Shift out MS bit first
	 *                  If 1 the data is shifted out starting with the MS bit. (bit 15 or bit 11). 
	 *                  If 0 the data is shifted out starting with the LS bit. (bit 0).
	 * @bit        5:0  Shift length
	 *                  Specifies the number of bits to shift. This field is ignored when using 
	 *                  'variable shift' mode.
	 */
	sfr_reg_t cntl0;
	/**
	 * @brief      SPI Control register 1 
	 * @details    The AUXSPIx_CNTL1 registers control more features of the SPI interfaces. 
	 * @bit        10:8  CS high time
	 *                  Additional SPI clock cycles where the CS is high.
	 * @bit        7  TX empty IRQ
	 *                  If 1 the interrupt line is high when the transmit FIFO is empty 
	 * @bit        6  Done IRQ
	 *                  If 1 the interrupt line is high when the interface is idle
	 * @bit        1  Shift in MS bit first
	 *                  If 1 the data is shifted in starting with the MS bit (bit 15). If 0 the data 
	 *                  is shifted in starting with the LS bit (bit 0) 
	 * @bit        0  Key input
	 *                  If 1 the receiver shift register is NOT cleared. Thus new data is 
	 *                  concatenated to old data. If 0 the receiver shift register is cleared before 
	 *                  each transaction. 
	 */
	sfr_reg_t cntl1;
	/**
	 * @brief      SPI Status 
	 * @details    The AUXSPIx_STAT registers show the status of the SPI interfaces. 
	 * @bit        31:24  TX FIFO level
	 *                  The number of data units in the transmit data FIFO. 
	 * @bit        23:12  RX FIFO level
	 *                  The number of data units in the receive data FIFO. 
	 * @bit        4  TX Full
	 *                  If 1 the transmit FIFO is full. If 0 the transmit FIFO can accept at least 
	 *                  1 data unit. 
	 * @bit        3  TX Empty
	 *                  If 1 the transmit FIFO is empty. If 0 the transmit FIFO holds at least 1 
	 *                  data unit. 
	 * @bit        2  RX Empty
	 *                  If 1 the receiver FIFO is empty. If 0 the receiver FIFO holds at least 1 
	 *                  data unit. 
	 * @bit        6  Busy
	 *                  Indicates the module is busy transferring data. 
	 * @bit        5:0  Bit count
	 *                  The number of bits still to be processed. Starts with 'shift-length' and 
	 *                  counts down. 
	 */
	sfr_reg_t stat;
	/**
	 * @brief      SPI Data
	 * @details    The AUXSPIx_PEEK registers show received data of the SPI interfaces. 
	 * @bit        15:0  Data
	 *                  Reads from this address will show the top entry from the receive FIFO, but 
	 *                  the data is not taken from the FIFO. This provides a means of inspecting the 
	 *                  data but not removing it from the FIFO. 
	 */
	sfr_reg_t io;
	/**
	 * @brief      SPI Peek 
	 * @details    The AUXSPIx_IO registers are the primary data port of the SPI interfaces. These 
	 *             four addresses all write to the same FIFO. 
	 * @bit        15:0  Data
	 *                  Writes to this address range end up in the transmit FIFO. Data is lost when 
	 *                  writing whilst the transmit FIFO is full. Reads from this address will take 
	 *                  the top entry from the receive FIFO. Reading whilst the receive FIFO is will 
	 *                  return the last data received. 
	 */
	sfr_reg_t peek;
};

struct AUX_REGISTERS {
	/**
	 * @brief      Auxiliary Interrupt status 
	 * @details    The AUXIRQ register is used to check any pending interrupts which may be 
	 *             asserted by the three Auxiliary sub blocks. 
	 * @bit        0  Mini UART IRQ 
	 *                  If set the mini UART has an interrupt pending. 
	 * @bit        1  SPI 1 IRQ
	 *                  If set the SPI1 module has an interrupt pending.
	 * @bit        2  SPI 2 IRQ
	 *                  If set the SPI2 module has an interrupt pending.
	 */
	sfr_reg_t irq;
	/**
	 * @brief      Auxiliary enables 
	 * @details    The AUXENB register is used to enable the three modules; UART, SPI1, SPI2. 
	 * @bit        0  Mini UART enable
	 *                  If set the mini UART is enabled. The UART will immediately start receiving 
	 *                  data, especially if the UART1_RX line is low. If clear the mini UART is 
	 *                  disabled. That also disables any mini UART register access 
	 * @bit        1  SPI 1 enable
	 *                  If set the SPI 1 module is enabled. If clear the SPI 1 module is disabled. 
	 *                  That also disables any SPI 1 module register access
	 * @bit        2  SPI 2 enable
	 *                  If set the SPI 2 module is enabled. If clear the SPI 2 module is disabled. 
	 *                  That also disables any SPI 2 module register access
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
