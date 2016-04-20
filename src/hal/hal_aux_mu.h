/**
 * @file      hal_aux_mu.h
 */

#include "hardware.h"

namespace hal
{
namespace aux
{
namespace mu
{
enum AUX_MU_INTERRUPT_SOURCE {none = 0, tx, rx};
enum AUX_MU_DATASIZE {mode7bit = 0, mode8bit = 1};

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
struct mini_uart_reg {
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
	 *                  If this bit is set no new symbols will be accepted by the receiver. Any 
	 *                  symbols in progress of reception will be finished. 
	 * @par        Transmitter enable
	 *                  If this bit is set no new symbols will be send the transmitter. Any symbols 
	 *                  in progress of transmission will be finished. 
	 * @par        Auto flow control
	 *                  Automatic flow control can be enabled independent for the receiver and the 
	 *                  transmitter. 
	 * @par
	 *                  CTS auto flow control impacts the transmitter only. The transmitter will not 
	 *                  send out new symbols when the CTS line is de-asserted. Any symbols in 
	 *                  progress of transmission when the CTS line becomes de-asserted will be 
	 *                  finished. 
	 * @par
	 *                  RTS auto flow control impacts the receiver only. In fact the name RTS for 
	 *                  the control line is incorrect and should be RTR (Ready to Receive). The 
	 *                  receiver will de-asserted the RTS (RTR) line when its receive FIFO has a 
	 *                  number of empty spaces left. Normally 3 empty spaces should be enough. 
	 * @par
	 *                  If looping back a mini UART using full auto flow control the logic is fast 
	 *                  enough to allow the RTS auto flow level of '10' (De-assert RTS when the 
	 *                  receive FIFO has 1 empty space left). 
	 * @par        Auto flow polarity
	 *                  To offer full flexibility the polarity of the CTS and RTS (RTR) lines can be 
	 *                  programmed. This should allow the mini UART to interface with any existing 
	 *                  hardware flow control available. 
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
	 *                  This bit is only useful if the receiver is disabled. The normal use is to 
	 *                  disable the receiver. Then check (or wait) until the bit is set. Now you can 
	 *                  be sure that no new symbols will arrive. (e.g. now you can change the 
	 *                  baudrate...) 
	 * 
	 * @par        Transmitter is idle
	 *                  This bit tells if the transmitter is idle. Note that the bit will set only 
	 *                  for a short time if the transmit FIFO contains data. Normally you want to 
	 *                  use bit 9: Transmitter done. 
	 * 
	 * @par        RTS status
	 *                  This bit is useful only in receive Auto flow-control mode as it shows the 
	 *                  status of the RTS line.
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
	 * @par        Note
	 *                  This is the same register as is accessed using the LABD bit and the first two 
	 *                  register, but much easier to access. 
	 */
	sfr_reg_t baud;
};

/*
inline void Enable(struct mini_uart_reg * this)
{
	aux->enables |= BIT0;
}
inline void Disable(struct mini_uart_reg * this)
{
	aux->enables &= ~BIT0;
}
inline void aux_mu_EnableInterrupt()
{
	aux->enables |= BIT0;
}
inline void aux_mu_DisableInterrupt()
{
	aux->enables &= ~BIT0;
}
*/


//-- DATA --//

/**
 * @brief     Write a byte of data to the Tx FIFO.
 */
inline void WriteData(struct mini_uart_reg * reg, char data)
{
	reg->io = data;
}

/**
 * @brief     Read a byte of data from the Rx FIFO.
 */
inline char ReadData(struct mini_uart_reg * reg)
{
	return reg->io;
}

/**
 * @brief     Clear all data from the Tx FIFO.
 */
inline void ClearTxFifo(struct mini_uart_reg * reg)
{
	reg->ier |= BIT2;
}

/**
 * @brief     Clear all data from the Rx FIFO.
 */
inline void ClearRxFifo(struct mini_uart_reg * reg)
{
	reg->ier |= BIT1;
}

/**
 * @brief     Write a byte of data to the scratch register.
 */
inline void WriteScratch(struct mini_uart_reg * reg, char data)
{
	reg->scratch = data;
}

/**
 * @brief     Read the byte in the scratch register.
 */
inline char ReadData(struct mini_uart_reg * reg)
{
	return reg->scratch;
}


//-- INTERRUPTS --//

/**
 * @brief     Enable interrupt on byte received.
 * @details   This will trigger an interrupt anytime there is a byte in the Rx FIFO.
 */
inline void EnableRxInterrupt(struct mini_uart_reg * reg)
{
	reg->iir |= BIT1;
}

/**
 * @brief     Disable interrupt on byte received.
 */
inline void DisableRxInterrupt(struct mini_uart_reg * reg)
{
	reg->iir &= ~BIT1;
}

/**
 * @brief     Enable interrupt on byte transmit.
 * @details   This will trigger an interrupt anytime there is space in the Tx FIFO.
 */
inline void EnableTxInterrupt(struct mini_uart_reg * reg)
{
	reg->iir |= BIT0;
}

/**
 * @brief     Disable interrupt on byte transmit.
 */
inline void DisableTxInterrupt(struct mini_uart_reg * reg)
{
	reg->iir &= ~BIT0;
}

/**
 * @brief     Return true if there is an interrupt pending.
 * @details   To find the source of the interrupt call GetInterruptSource(struct mini_uart_reg*).
 */
inline bool IsIntteruptPending(struct mini_uart_reg * reg)
{
	return !(reg->ier & BIT0);
}

/**
 * @brief     Get the source of the interrupt.
 */
inline enum AUX_MU_INTERRUPT_SOURCE GetItterruptSource(struct mini_uart_reg * reg)
{
	return (reg->ier & (BIT2 | BIT1)) >> 1;
}

//-- FLOW CONTROL --//

/**
 * @brief     Pull the Tx line low. If held for at least 12 bits that will indicate break condition.
 */
inline void AssertBreak(struct mini_uart_reg * reg)
{
	reg->lcr |= BIT6;
}

/**
 * @brief     Release the break condition from the Tx line.
 */
inline void DeassertBreak(struct mini_uart_reg * reg)
{
	reg->lcr &= ~BIT6;
}

/**
 * @brief     Assert the RTS condition.
 */
inline void AssertRts(struct mini_uart_reg * reg)
{
	reg->mcr |= BIT1;
}

/**
 * @brief     Released the RTS condition.
 */
inline void DeassertRts(struct mini_uart_reg * reg)
{
	reg->mcr &= ~BIT1;
}

/**
 * @brief     Get the current status of the CTS line.
 */
inline bool GetCtsStatus(struct mini_uart_reg * reg)
{
	return reg->stat & BIT7;
}

/**
 * @brief     Get the current status of the RTS line.
 */
inline bool GetRtsStatus(struct mini_uart_reg * reg)
{
	return reg->stat & BIT6;
}

/**
 * @brief     Enable the automatic flow control CTS line.
 * @param     invert
 *                 Make CTS logic active low.
 */
inline void EnableCtsAutoFlow(struct mini_uart_reg * reg, bool invert)
{
	if(invert)
		reg->cntl |= BIT7;
	else
		reg->cntl &= ~BIT7;
	reg->cntl |= BIT3;
}

/**
 * @brief     Disable the automatic flow control CTS line.
 */
inline void DisableCtsAutoFlow(struct mini_uart_reg * reg)
{
	reg->cntl &= ~BIT3;
}

/**
 * @brief     Enable the automatic flow control on the RTS line.
 * @param     invert
 *                 Make RTS logic active low.
 * @param     level
 *                 The number of free spots in the Rx FIFO before RTS is asserted. level := [1,4]
 */
inline void EnableRtsAutoFlow(struct mini_uart_reg * reg, bool invert, unsigned char level)
{
	assert(level >= 1 && level <=4);
	if(invert)
		reg->cntl |= BIT6;
	else
		reg->cntl &= ~BIT6;
		
	reg->cntl &= ~(BIT5 | BIT4);
	if(level == 1)
		reg->cntl |= BIT5;
	else if(level == 2)
		reg->cntl |= BIT4;
	else if(level == 4)
		reg->cntl |= BIT4 | BIT5;
	
	reg->cntl |= BIT2;
}

/**
 * @brief     Disable the automatic flow control on the RTS line.
 */
inline void DisableRtsAutoFlow(struct mini_uart_reg * reg)
{
	reg->cntl &= ~BIT2;
}








//-- CONTROL --//
/**
 * @brief     Set the data size to 7 or 8 bits.
 */
inline void SetDataSize(struct mini_uart_reg * reg, enum AUX_MU_DATASIZE size)
{
	reg->lcr |= size;
}

/**
 * @brief     Enable the transmitter part of the mini UART.
 */
inline void EnableTx(struct mini_uart_reg * reg)
{
	reg->cntl |= BIT1;
}

/**
 * @brief     Disable the transmitter part of the mini UART.
 */
inline void DisableTx(struct mini_uart_reg * reg)
{
	reg->cntl &= ~BIT1;
}

/**
 * @brief     Enable the reciever part of the mini UART.
 */
inline void EnableRx(struct mini_uart_reg * reg)
{
	reg->cntl |= BIT0;
}

/**
 * @brief     Disable the reciever par of the mini UART.
 */
inline void DisableRx(struct mini_uart_reg * reg)
{
	reg->cntl &= ~BIT0;
}

/**
 * @brief     Set the UART baudrate.
 */
inline void SetBaudrate(struct mini_uart_reg * reg, unsigned short rate)
{
	reg->baudrate = rate;
}

/**
 * @brief     Get the current UART baudrate value.
 */
inline unsigned short GetBaudrate(struct mini_uart_reg * reg)
{
	return reg->buadrate;
}





//-- STATUS --//

/**
 * @brief     Find if the Rx recieved data when the Rx FIFO was full.
 * @param     clear
 *                 Clear the overrun bit in the register.
 */
inline bool IsRxOverrun(struct mini_uart_reg * reg, bool clear)
{
	if(clear)
		return reg->lsr & BIT1;
	else
		return reg->cntl & BIT4;
}

/**
 * @brief     Get the number of symbols in the Tx FIFO.
 */
inline unsigned char GetTxFifoLevel(struct mini_uart_reg * reg)
{
	return (reg->stat >> 24) & (BIT0 | BIT1 | BIT2 | BIT3);
}

/**
 * @brief     Get the number of symbols in the Rx FIFO.
 */
inline unsigned char GetRxFifoLevel(struct mini_uart_reg * reg)
{
	return (reg->stat >> 16) & (BIT0 | BIT1 | BIT2 | BIT3);
}

/**
 * @brief     Return true if the Tx FIFO is empty.
 */
inline bool IsTxFifoEmpty(struct mini_uart_reg * reg)
{
	return reg->stat & BIT8;
}

/**
 * @brief     Return true if the Tx FIFO is full.
 */
inline bool IsTxFull(struct mini_uart_reg * reg)
{
	return reg->stat & BIT5;
}

/**
 * @brief     Return true if there is space for a new byte in the Tx FIFO.
 */
inline bool IsTxFifoRdy(struct mini_uart_reg * reg)
{
	return reg->stat & BIT1;
}

/**
 * @brief     Return true if there is a byte in the Rx FIFO to be read.
 */
inline bool IsRxFifoRdy(struct mini_uart_reg * reg)
{
	return reg->stat & BIT0;
}

/**
 * @brief     Return true if the Tx is not transmitting and the Tx FIFO is empty.
 */
inline bool IsTxIdle(struct mini_uart_reg * reg)
{
	return reg->stat & BIT9;
}

/**
 * @brief     Return true if the Rx is not recieving.
 */
inline bool IsRxIdle(struct mini_uart_reg * reg)
{
	return reg->stat & BIT2;
}




}; // namespace mu
}; // namespace aux
}; // namespace hal











