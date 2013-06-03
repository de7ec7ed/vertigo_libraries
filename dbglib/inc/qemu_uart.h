/* This file is part of VERTIGO.
 *
 * (C) Copyright 2013, Siege Technologies <http://www.siegetechnologies.com>
 * (C) Copyright 2013, Kirk Swidowski <http://www.swidowski.com>
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

#ifndef __DBG_QEMU_UART_H__
#define __DBG_QEMU_UART_H__

#include <config.h>
#include <defines.h>
#include <types.h>

#define QEMU_UART_ADDRESS 0xFF002000
#define QEMU_UART_SIZE    0x1000

#define QEMU_UART_NUMBER_PERIPHERAL_IDENTIFICATION_REGISTERS 4
#define QEMU_UART_NUMBER_PRIMECELL_IDENTIFICATION_REGISTERS 4

#define QEMU_UART_UARTDR_OFFSET        0x0 // Data Register
#define QEMU_UART_UARTRSR_OFFSET       0x4 // Receive Status Register
#define QEMU_UART_UARTECR_OFFSET       0x4 // Error Clear Register
#define QEMU_UART_RESERVED_0_OFFSET    0x8 // Reserved 0
#define QEMU_UART_UARTFR_OFFSET        0x18 // Flag Register
#define QEMU_UART_RESERVED_1_OFFSET    0x1C // Reserved 1
#define QEMU_UART_UARTILPR_OFFSET      0x20 // IrDA Low-power Counter Register
#define QEMU_UART_UARTIBRD_OFFSET      0x24 // Integer Baud Rate Register
#define QEMU_UART_UARTFBRD_OFFSET      0x28 // Fractional Baud Rate Register
#define QEMU_UART_UARTLCR_H_OFFSET     0x2C // Line control Register
#define QEMU_UART_UARTCR_OFFSET        0x30 // Control Register
#define QEMU_UART_UARTIFLS_OFFSET      0x34 // Interrupt FIFO Level Select Register
#define QEMU_UART_UARTIMSC_OFFSET      0x38 // Interrupt Mask Set/Clear Register
#define QEMU_UART_UARTRIS_OFFSET       0x3C // Raw Interrupt Status Register
#define QEMU_UART_UARTMIS_OFFSET       0x40 // Masked Interrupt Status Register
#define QEMU_UART_UARTICR_OFFSET       0x44 // Interrupt Clear Register
#define QEMU_UART_UARTDMACR_OFFSET     0x48 // DMA Control Register
#define QEMU_UART_RESERVED_2_OFFSET    0x4C // Reserved 2
#define QEMU_UART_UARTPERIPHID0_OFFSET 0xFE0 // UARTPeriphID0 register
#define QEMU_UART_UARTPERIPHID1_OFFSET 0xFE4 // UARTPeriphID1 register
#define QEMU_UART_UARTPERIPHID2_OFFSET 0xFE8 // UARTPeriphID2 register
#define QEMU_UART_UARTPERIPHID3_OFFSET 0xFEC // UARTPeriphID3 register
#define QEMU_UART_UARTPCELLID0_OFFSET  0xFF0 // UARTPCellID0 register
#define QEMU_UART_UARTPCELLID1_OFFSET  0xFF4 // UARTPCellID1 register
#define QEMU_UART_UARTPCELLID2_OFFSET  0xFF8 // UARTPCellID2 register
#define QEMU_UART_UARTPCELLID3_OFFSET  0xFFC // UARTPCellID3 register

#define QEMU_UART_TX_TIMEOUT_PERIOD 0x10000
#define QEMU_UART_RX_TIMEOUT_PERIOD 0x10000

#ifdef __C__

#ifdef __DBGLIB_QEMU__
#define SER_INIT(a, b) qemu_uart_init(a, b)
#define SER_PUTC(a, b) qemu_uart_putc(a, b)
#define SER_WRITE(a, b, c) qemu_uart_write(a, b, c)
#define SER_FINI(a) qemu_uart_fini(a)
typedef volatile struct qemu_uart_block ser_block_t;
#define SER_PHYSICAL_ADDRESS QEMU_UART_ADDRESS
#define SER_VIRTUAL_ADDRESS 0xFE002000
#define SER_SIZE QEMU_UART_SIZE
#endif //__DBGLIB_QEMU__

typedef union qemu_uart_data_register qemu_uart_data_register_t;
typedef union qemu_uart_generic_register qemu_uart_error_clear_register_t;
typedef union qemu_uart_receive_status_register qemu_receiver_status_register_t;
typedef union qemu_uart_flag_register qemu_uart_flag_register_t;
typedef union qemu_uart_generic_register qemu_uart_irda_low_power_counter_register_t;
typedef union qemu_uart_generic_register qemu_uart_integer_baud_rate_register_t;
typedef union qemu_uart_generic_register qemu_uart_fractional_baud_rate_register_t;
typedef union qemu_uart_line_control_register qemu_uart_line_control_register_t;
typedef union qemu_uart_control_register qemu_uart_control_register_t;
typedef union qemu_uart_interrupt_fifo_level_select_register qemu_uart_interrupt_fifo_level_select_register_t;
typedef union qemu_uart_interrupt_set_clear_register qemu_uart_interrupt_set_clear_register_t;
typedef union qemu_uart_interrupt_status_register qemu_uart_interrupt_status_register_t;
typedef union qemu_uart_masked_interrupt_status_register qemu_uart_masked_interrupt_status_register_t;
typedef union qemu_uart_masked_interrupt_clear_register qemu_uart_masked_interrupt_clear_register_t;
typedef union qemu_uart_dma_control_register qemu_uart_dma_control_register_t;
typedef union qemu_uart_generic_register qemu_uart_peripheral_identification_register_t;
typedef union qemu_uart_generic_register qemu_uart_primecell_identification_register_t;
typedef union qemu_uart_generic_register qemu_uart_reserved_register_t;

typedef volatile struct qemu_uart_block qemu_uart_block_t;

union qemu_uart_data_register {
	struct {
		u8_t data  :8; // Receive (read) data character, Transmit (write) data character
		u8_t fe    :1; // Framing error
		u8_t pe    :1; // Parity error
		u8_t be    :1; // Break error
		u8_t oe    :1; // Overrun error
		u32_t res_0 :20; // Reserved
	} fields;
	u32_t all;
};

union qemu_uart_receive_status_register {
	struct {
		u32_t fe    :1; // Framing error
		u32_t pe    :1; // Parity error
		u32_t be    :1; // Break error
		u32_t oe    :1; // Overrun error
		u32_t res_0 :28; // Reserved
	};
	u32_t all;
};

union qemu_uart_flag_register {
	struct {
		u32_t cts     :1; // Clear to send
		u32_t dsr     :1; // Data set ready
		u32_t dcd     :1; // Data carrier detect
		u32_t busy    :1; // UART busy
		u32_t rxfe    :1; // Receive FIFO empty
		u32_t txff    :1; // Transmit FIFO full
		u32_t rxff    :1; // Receive FIFO full
		u32_t txfe    :1; // Transmit FIFO empty
		u32_t ri      :1; // Ring indicator
		u32_t res_0   :23; // Reserved
		u32_t res_2   :21;
	} fields;
	u32_t all;
};

union qemu_uart_line_control_register {
	struct {
		u32_t brk   :1; // Send break
		u32_t pen   :1; // Parity enable
		u32_t eps   :1; // Even parity select
		u32_t stp2  :1; // Two stop bits select
		u32_t fen   :1; // Enable FIFOs
		u32_t wlen  :1; // Word length
		u32_t sps   :1; // Stick parity select
		u32_t res_0 :24; // Reserved
	};
	u32_t all;
};

union qemu_uart_control_register {
	struct {
		u32_t uarten :1; // UART enable
		u32_t siren  :1; // SIR enable
		u32_t sirlp  :1; // IrDA SIR low power mode
		u32_t res_0  :4; // Reserved
		u32_t lbe    :1; // Loop back enable
		u32_t txe    :1; // Transmit enable
		u32_t rxe    :1; // Receive enable
		u32_t dtr    :1; // Data transmit ready
		u32_t rtx    :1; // Request to send
		u32_t out1   :1; // This bit is the complement of the UART Out1 (nUARTOut1) modem status output
		u32_t out2   :1; // This bit is the complement of the UART Out1 (nUARTOut1) modem status output
		u32_t rtse   :1; // RTS hardware flow control enable
		u32_t ctse   :1; // CTS hardware flow control enable
		u32_t res_1  :16; // Reserved
	} fields;
	u32_t all;
};

union qemu_uart_interrupt_fifo_level_select_register {
	struct {
		u32_t txiflsel :3; // Transmit interrupt FIFO level select
		u32_t rxiflsel :3; // Transmit interrupt FIFO level select
		u32_t res_0    :26; // Reserved
	} fields;
	u32_t all;
};

union qemu_uart_interrupt_set_clear_register {
	struct {
		u32_t rimim  :1; // nUARTRI modem interrupt mask
		u32_t ctsmim :1; // nUARTCTS modem interrupt mask
		u32_t dcdmim :1; // nUARTDCD modem interrupt mask
		u32_t dsrmim :1; // nUARTDSR modem interrupt mask
		u32_t rxim   :1; // Receive interrupt mask
		u32_t txim   :1; // Transmit interrupt mask
		u32_t rtim   :1; // Receive timeout interrupt mask
		u32_t feim   :1; // Framing error interrupt mask
		u32_t peim   :1; // Parity error interrupt mask
		u32_t beim   :1; // Break error interrupt mask
		u32_t oeim   :1; // Overrun error interrupt mask
		u32_t res_0  :21; // Reserved
	};
	u32_t all;
};

union qemu_uart_interrupt_status_register {
	struct {
		u32_t rimis  :1; // nUARTRI modem interrupt status
		u32_t ctsmis :1; // nUARTCTS modem interrupt status
		u32_t dcdmis :1; // nUARTDCD modem interrupt status
		u32_t dsrmis :1; // nUARTDSR modem interrupt status
		u32_t rxis   :1; // Receive interrupt status
		u32_t txis   :1; // Transmit interrupt status
		u32_t rtis   :1; // Receive timeout interrupt status
		u32_t feis   :1; // Framing error interrupt status
		u32_t peis   :1; // Parity error interrupt status
		u32_t beis   :1; // Break error interrupt status
		u32_t oeis   :1; // Overrun error interrupt status
		u32_t res_0  :21; // Reserved
	};
	u32_t all;
};
union qemu_uart_masked_interrupt_status_register {
	struct {
		u32_t rimmis  :1; // nUARTRI modem masked interrupt status
		u32_t ctsmmis :1; // nUARTCTS modem masked interrupt status
		u32_t dcdmmis :1; // nUARTDCD modem masked interrupt status
		u32_t dsrmmis :1; // nUARTDSR modem masked interrupt status
		u32_t rxmis   :1; // Receive masked interrupt status
		u32_t txmis   :1; // Transmit masked interrupt status
		u32_t rtmis   :1; // Receive timeout masked interrupt status
		u32_t femis   :1; // Framing error masked interrupt status
		u32_t pemis   :1; // Parity error masked interrupt status
		u32_t bemis   :1; // Break error masked interrupt status
		u32_t oemis   :1; // Overrun error masked interrupt status
		u32_t res_0  :21; // Reserved
	};
	u32_t all;
};
union qemu_uart_masked_interrupt_clear_register {
	struct {
		u32_t rimic  :1; // nUARTRI modem interrupt clear
		u32_t ctsmic :1; // nUARTCTS modem interrupt clear
		u32_t dcdmic :1; // nUARTDCD modem interrupt clear
		u32_t dsrmic :1; // nUARTDSR modem interrupt clear
		u32_t rxic   :1; // Receive interrupt clear
		u32_t txic   :1; // Transmit interrupt clear
		u32_t rtic   :1; // Receive timeout interrupt clear
		u32_t feic   :1; // Framing error interrupt clear
		u32_t peic   :1; // Parity error interrupt clear
		u32_t beic   :1; // Break error interrupt clear
		u32_t oeic   :1; // Overrun error interrupt clear
		u32_t res_0  :21; // Reserved
	};
	u32_t all;
};
union qemu_uart_dma_control_register {
	struct {
		u32_t rxdmae   :1; // Receive DMA enable
		u32_t txdmae   :1; // Transmit DMA enable
		u32_t dmaonerr :1; // DMA on error
		u32_t res_0    :29; // Reserved
	};
	u32_t all;
};

union qemu_uart_generic_register {
	u8_t  u8;
	u16_t u16;
	u32_t all;
};

struct qemu_uart_block {
	qemu_uart_data_register_t uartdr;
	union {
		qemu_receiver_status_register_t uartrsr;
		qemu_uart_error_clear_register_t uartecr;
	};
	qemu_uart_reserved_register_t reserved_0[QEMU_UART_UARTFR_OFFSET - QEMU_UART_RESERVED_0_OFFSET];
	qemu_uart_flag_register_t uartfr;
	qemu_uart_reserved_register_t reserved_1[QEMU_UART_UARTILPR_OFFSET - QEMU_UART_RESERVED_1_OFFSET];
	qemu_uart_irda_low_power_counter_register_t uartilpr;
	qemu_uart_integer_baud_rate_register_t uartibrd;
	qemu_uart_fractional_baud_rate_register_t uartfbrd;
	qemu_uart_line_control_register_t uartlcr_h;
	qemu_uart_control_register_t uartcr;
	qemu_uart_interrupt_fifo_level_select_register_t uartifls;
	qemu_uart_interrupt_set_clear_register_t uartimsc;
	qemu_uart_interrupt_status_register_t uartris;
	qemu_uart_masked_interrupt_status_register_t uartmis;
	qemu_uart_masked_interrupt_clear_register_t uarticr;
	qemu_uart_dma_control_register_t uartdmacr;
	qemu_uart_reserved_register_t reserved_2[QEMU_UART_UARTPERIPHID0_OFFSET - QEMU_UART_RESERVED_2_OFFSET];
	qemu_uart_peripheral_identification_register_t uartperiphid[QEMU_UART_NUMBER_PERIPHERAL_IDENTIFICATION_REGISTERS];
	qemu_uart_primecell_identification_register_t	uartcellid[QEMU_UART_NUMBER_PRIMECELL_IDENTIFICATION_REGISTERS];
} PACKED;

result_t qemu_uart_init(qemu_uart_block_t *block, size_t options);
result_t qemu_uart_fini(qemu_uart_block_t *block);

result_t qemu_uart_write(qemu_uart_block_t *block, u8_t *buffer, size_t size);
result_t qemu_uart_putc(qemu_uart_block_t *block, u8_t c);

#endif //__C__


#endif //__DBG_QEMU_UART_H__

