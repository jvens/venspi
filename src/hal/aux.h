/**
 * @file      aux.h
 */


#ifndef RPI_AUX_H
#define RPI_AUX_H









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
 * @details   There are two Auxiliary registers which control all three devices. One is the 
 *            interrupt status register, the second is the Auxiliary enable register. The Auxiliary 
 *            IRQ status register can help to hierarchically determine the source of an interrupt.
 * 
 *            If the enable bits are clear you will have no access to a peripheral. You can not even 
 *            read or write the registers!
 * 
 *            GPIO pins should be set up first the before enabling the UART. The UART core is build 
 *            to emulate 16550 behaviour. So when it is enabled any data at the inputs will 
 *            immediately be received . If the UART1_RX line is low (because the GPIO pins have not 
 *            been set-up yet) that will be seen as a start bit and the UART will start receiving 
 *            0x00-characters. 
 *
 *            Valid stops bits are not required for the UART. (See also Implementation details). 
 *            Hence any bit status is acceptable as stop bit and is only used so there is clean 
 *            timing start for the next bit. 
 *
 *            Looking after a reset: the baudrate will be zero and the system clock will be 250 MHz. 
 *            So only 2.5 µseconds suffice to fill the receive FIFO. The result will be that the 
 *            FIFO is full and overflowing in no time flat. 
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
