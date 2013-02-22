/* This file is part of VERTIGO.
 *
 * (C) Copyright 2013, Siege Technologies <http://www.siegetechnologies.com>
 *
 * VERTIGO is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * VERTIGO is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with VERTIGO. If not, see <http://www.gnu.org/licenses/>.
 *
 * Written by Kirk Swidowski <kirk@swidowski.com>
 */

#ifndef __DBG_S5L8930_UART_H__
#define __DBG_S5L8930_UART_H__

#include <config.h>
#include <defines.h>
#include <types.h>

#define S5L8930_UART_ADDRESS 0x82500000
#define S5L8930_UART_SIZE    0x1000

#define S5L8930_UART_ULCON_OFFSET    0x0 // Line Control Register
#define S5L8930_UART_UCON_OFFSET     0x4 // Control Register
#define S5L8930_UART_UFCON_OFFSET    0x8 // FIFO Control Register
#define S5L8930_UART_UMCON_OFFSET    0xC // Modem Control Register
#define S5L8930_UART_UTRSTAT_OFFSET  0x10 // TX/RX Status Register
#define S5L8930_UART_UESTAT_OFFSET   0x14 // Error Status Register
#define S5L8930_UART_UFSTAT_OFFSET   0x18 // FIFO Status Register
#define S5L8930_UART_UMSTAT_OFFSET   0x1C // Modem Status Register
#define S5L8930_UART_UTXH_OFFSET     0x20 // Transmit Buffer Register
#define S5L8930_UART_URXH_OFFSET     0x24 // Receive Buffer Register
#define S5L8930_UART_UBAUD_OFFSET    0x28 // Baud Rate Configure Register
#define S5L8930_UART_UDIVSLOT_OFFSET 0x2C // Divisor Slot Register
#define S5L8930_UART_UINTP_OFFSET    0x30 // Interrupt Pending Register
#define S5L8930_UART_UINTSP_OFFSET   0x34 // Interrupt Source Pending Register
#define S5L8930_UART_UINTM_OFFSET    0x38 // Interrupt Mask Register

#define S5L8930_UART_TX_TIMEOUT_PERIOD 0x10000
#define S5L8930_UART_RX_TIMEOUT_PERIOD 0x10000

#ifdef __C__

#ifdef __DBGLIB_S5L8930__
#define SER_INIT(a, b) s5l8930_uart_init(a, b)
#define SER_READ(a, b, c) s5l8930_uart_read(a, b, c)
#define SER_WRITE(a, b, c) s5l8930_uart_write(a, b, c)
#define SER_FINI(a) s5l8930_uart_fini(a)
typedef volatile struct s5l8930_uart_block ser_block_t;
#define SER_PHYSICAL_ADDRESS S5L8930_UART_ADDRESS
#define SER_VIRTUAL_ADDRESS 0xC0000000
#define SER_SIZE S5L8930_UART_SIZE
#endif //__DBGLIB_S5L8930__

typedef union s5l8930_uart_line_control_register s5l8930_uart_line_control_register_t;
typedef union s5l8930_uart_control_register s5l8930_uart_control_register_t;
typedef union s5l8930_uart_fifo_control_register s5l8930_uart_fifo_control_register_t;
typedef union s5l8930_uart_modem_control_register s5l8930_uart_modem_control_register_t;
typedef union s5l8930_uart_tx_rx_status_register s5l8930_uart_tx_rx_status_register_t;
typedef union s5l8930_uart_error_status_register s5l8930_uart_error_status_register_t;
typedef union s5l8930_uart_fifo_status_register s5l8930_uart_fifo_status_register_t;
typedef union s5l8930_uart_modem_status_register s5l8930_uart_modem_status_register_t;
typedef union s5l8930_uart_generic_register s5l8930_uart_transmit_buffer_register_t;
typedef union s5l8930_uart_generic_register s5l8930_uart_receive_buffer_register_t;
typedef union s5l8930_uart_generic_register s5l8930_uart_baud_rate_divisor_register_t;
typedef union s5l8930_uart_generic_register s5l8930_uart_divisor_slot_register_t;
typedef union s5l8930_uart_interrupt_register s5l8930_uart_interrupt_pending_register_t;
typedef union s5l8930_uart_interrupt_register s5l8930_uart_interrupt_source_pending_register_t;
typedef union s5l8930_uart_interrupt_register s5l8930_uart_interrupt_mask_register_t;

typedef volatile struct s5l8930_uart_block s5l8930_uart_block_t;

union s5l8930_uart_line_control_register {
	struct {
		u32_t wl    :2; // Word Length
		u32_t nsb   :1; // Number of Stop Bits
		u32_t pm    :3; // Parity Mode
		u32_t irm   :1; // Infra-Red Mode
		u32_t res_0 :1; // Reserved
	} fields;
	u32_t all;
};

union s5l8930_uart_control_register {
	struct {
		u32_t rm    :2; // Receive Mode
		u32_t tm    :2; // Transmit Mode
		u32_t sbs   :1; // Send Break Signal
		u32_t lbm   :1; // Loop-back Mode
		u32_t resie :1; // Rx Error Status Interrupt Enable
		u32_t rtoe  :1; // Rx Time Out Enable
		u32_t rit   :1; // Rx Interrupt Type
		u32_t tit   :1; // Tx Interrupt Type
		u32_t cs    :2; // Clock Selection
	} fields;
	u32_t all;
};

union s5l8930_uart_fifo_control_register {
	struct {
		u32_t fifoe   :1; // FIFO Enable
		u32_t rfifor  :1; // Rx FIFO Reset
		u32_t tfifor  :1; // Tx FIFO Reset
		u32_t res_0   :1; // Reserved
		u32_t rfifotl :2; // Rx FIFO Trigger Level
		u32_t tfifotl :2; // Tx FIFO Trigger Level
	} fields;
	u32_t all;
};

union s5l8930_uart_modem_control_register {
	struct {
		u32_t rs    :1; // Request to Send
		u32_t res_0 :2; // Reserved
		u32_t mie   :1; // Modem Interrupt Enable
		u32_t afc   :1; // Auto Flow Control
		u32_t rtstl :3; // RTS Trigger Level
	} fields;
	u32_t all;
};

union s5l8930_uart_tx_rx_status_register {
	struct {
		u32_t rbdr :1; // Receive Buffer Data Ready
		u32_t tbe  :1; // Transmit Buffer Empty
		u32_t te   :1; // Transmitter Empty
	} fields;
	u32_t all;
};

union s5l8930_uart_error_status_register {
	struct {
		u32_t oe :1; // Overrun Error
		u32_t pe :1; // Parity Error
		u32_t fe :1; // Frame Error
		u32_t bd :1; // Break Detect
	} fields;
	u32_t all;
};

union s5l8930_uart_fifo_status_register {
	struct {
		u32_t rfifoc :6; // Rx FIFO Count
		u32_t rfifof :1; // Rx FIFO Full
		u32_t tfifoc :6; // Tx FIFO Count
		u32_t tfifof :1; // Tx FIFO Full
		u32_t res_0  :1; // Reserved
	} fields;
	u32_t all;
};

union s5l8930_uart_modem_status_register {
	struct {
		u32_t cs :1; // Clear to Send
		u32_t res_0 :4; // Reserved
		u32_t dcts :1; // Delta CTS
		u32_t res_1 :3; // Reserved
	} fields;
	u32_t all;
};

union s5l8930_uart_generic_register {
	u8_t  u8;
	u16_t u16;
	u32_t all;
};

union s5l8930_uart_interrupt_register {
	struct {
		u32_t rxd   :1; // Receive Interrupt Generated
		u32_t error :1; // Error Interrupt Generated
		u32_t txd   :1; // Transmit Interrupt Generated
		u32_t modem :1; // Modem Interrupt Generated
	} fields;
	u32_t all;
};

struct s5l8930_uart_block {
	s5l8930_uart_line_control_register_t ulcon;
	s5l8930_uart_control_register_t ucon;
	s5l8930_uart_fifo_control_register_t ufcon;
	s5l8930_uart_modem_control_register_t umcon;
	s5l8930_uart_tx_rx_status_register_t utrstat;
	s5l8930_uart_error_status_register_t uerstat;
	s5l8930_uart_fifo_status_register_t ufstat;
	s5l8930_uart_modem_status_register_t umstat;
	s5l8930_uart_transmit_buffer_register_t utxh;
	s5l8930_uart_receive_buffer_register_t urxh;
	s5l8930_uart_baud_rate_divisor_register_t ubrdiv;
	s5l8930_uart_divisor_slot_register_t udivslot;
	s5l8930_uart_interrupt_pending_register_t uintp;
	s5l8930_uart_interrupt_source_pending_register_t uintsp;
	s5l8930_uart_interrupt_mask_register_t uintm;
} PACKED;

result_t s5l8930_uart_init(s5l8930_uart_block_t *block, size_t options);
result_t s5l8930_uart_fini(s5l8930_uart_block_t *block);

result_t s5l8930_uart_set_clock(s5l8930_uart_block_t *block);

result_t s5l8930_uart_write(s5l8930_uart_block_t *block, u8_t *buffer, size_t size);
result_t s5l8930_uart_read(s5l8930_uart_block_t *block, u8_t *buffer, size_t size);

result_t s5l8930_uart_putc(s5l8930_uart_block_t *block, u8_t c);
result_t s5l8930_uart_getc(s5l8930_uart_block_t *block, u8_t *c);

#endif //__C__


#endif //__DBG_S5L8930_UART_H__

