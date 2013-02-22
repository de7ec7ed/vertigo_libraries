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

#ifndef __DBG_MSM8960_MSM8960_UARTDM_H__
#define __DBG_MSM8960_MSM8960_UARTDM_H__

#include <defines.h>
#include <types.h>

#define MSM8960_UARTDM_ADDRESS 0x16440000
#define MSM8960_UARTDM_SIZE    0x1000

#define MSM8960_UARTDM_MR1_OFFSET         0x0 // Mode Register 1
#define MSM8960_UARTDM_MR2_OFFSET         0x4 // Mode Register 2
#define MSM8960_UARTDM_CSR_OFFSET         0x8 // Clock Selection Register
#define MSM8960_UARTDM_TF_OFFSET          0x70 // Transmit FIFO Register
#define MSM8960_UARTDM_TF_2_OFFSET        0x74 // Transmit FIFO Register 2
#define MSM8960_UARTDM_TF_3_OFFSET        0x78 // Transmit FIFO Register 3
#define MSM8960_UARTDM_TF_4_OFFSET        0x7C // Transmit FIFO Register 4
#define MSM8960_UARTDM_CR_OFFSET          0x10 // Command Register
#define MSM8960_UARTDM_IMR_OFFSET         0x14 // Interrupt Mask Register
#define MSM8960_UARTDM_IPR_OFFSET         0x18 // Interrupt Programming Register
#define MSM8960_UARTDM_TFWR_OFFSET        0x1C // Transmit FIFO Watermark Register
#define MSM8960_UARTDM_RFWR_OFFSET        0x20 // Receive FIFO Watermark Register
#define MSM8960_UARTDM_HCR_OFFSET         0x24 // Hunt Character Register
#define MSM8960_UARTDM_MREG_OFFSET        0x28 // M Value Register
#define MSM8960_UARTDM_NREG_OFFSET        0x2C // N Value Register
#define MSM8960_UARTDM_DREG_OFFSET        0x30 // D Value Register
#define MSM8960_UARTDM_MNDREG_OFFSET      0x34 // M, N, D Extra Value Register
#define MSM8960_UARTDM_IDRA_OFFSET        0x38 // IDRA Register
#define MSM8960_UARTDM_DMEN_OFFSET        0x3C // Data Mover Enable Register
#define MSM8960_UARTDM_DMTX_OFFSET        0x40 // Data Mover Number Words Received Register
#define MSM8960_UARTDM_BADR_OFFSET        0x44 // Data Mover Base Address Register
#define MSM8960_UARTDM_TESTSL_OFFSET      0x48
#define MSM8960_UARTDM_MISR_MODE_OFFSET   0x60
#define MSM8960_UARTDM_MISR_RESET_OFFSET  0x64
#define MSM8960_UARTDM_MISR_EXPORT_OFFSET 0x68
#define MSM8960_UARTDM_MISR_VAL_OFFSET    0x6C
#define MSM8960_UARTDM_SR_OFFSET          0x8  // Status Register
#define MSM8960_UARTDM_RF_OFFSET          0x70 // Receive FIFO Register
#define MSM8960_UARTDM_RF_2_OFFSET        0x74 // Receive FIFO Register 2
#define MSM8960_UARTDM_RF_3_OFFSET        0x78 // Receive FIFO Register 3
#define MSM8960_UARTDM_RF_4_OFFSET        0x7C // Receive FIFO Register 4
#define MSM8960_UARTDM_MISR_OFFSET        0x10 // Masked Interrupt Status Register
#define MSM8960_UARTDM_ISR_OFFSET         0x14 // Interrupt Status Register
#define MSM8960_UARTDM_DMRX_OFFSET        0x38
#define MSM8960_UARTDM_TXFS_OFFSET        0x4C // Transmit FIFO State Register
#define MSM8960_UARTDM_RXFS_OFFSET        0x50 // Receive FIFO State Register

// Command Register Channel Commands
#define MSM8960_UARTDM_CR_NULL_COMMAND                 0x0
#define MSM8960_UARTDM_CR_RESET_RECEIVER               0x1
#define MSM8960_UARTDM_CR_RESET_TRANSMITTER            0x2
#define MSM8960_UARTDM_CR_RESET_ERROR_STATUS           0x3
#define MSM8960_UARTDM_CR_RESET_BREAK_CHANGE_INTERRUPT 0x4
#define MSM8960_UARTDM_CR_START_BREAK                  0x5
#define MSM8960_UARTDM_CR_STOP_BREAK                   0x6
#define MSM8960_UARTDM_CR_RESET_CTS_N                  0x7
#define MSM8960_UARTDM_CR_RESET_STALE_INTERRUPT        0x8
#define MSM8960_UARTDM_CR_PACKET_MODE                  0x9
#define MSM8960_UARTDM_CR_MODE_RESET                   0xC
#define MSM8960_UARTDM_CR_SET_RFR_N                    0xD
#define MSM8960_UARTDM_CR_RESET_RFR_ND                 0xE

#define MSM8960_UARTDM_TX_TIMEOUT_PERIOD 0x10000
#define MSM8960_UARTDM_RX_TIMEOUT_PERIOD 0x10000

#ifdef __C__

#ifdef __DBGLIB_MSM8960__
#define SER_INIT(a, b) msm8960_uartdm_init(a, b)
#define SER_READ(a, b, c) msm8960_uartdm_read(a, b, c)
#define SER_WRITE(a, b, c) msm8960_uartdm_write(a, b, c)
#define SER_FINI(a) msm8960_uartdm_fini(a)
typedef volatile struct msm8960_uartdm_block ser_block_t;
#define SER_PHYSICAL_ADDRESS MSM8960_UARTDM_ADDRESS
#define SER_VIRTUAL_ADDRESS 0xE5872000
#define SER_SIZE MSM8960_UARTDM_SIZE
#endif //__DBGLIB_MSM8960__

typedef union msm8960_uartdm_generic_register msm8960_uartdm_generic_register_t;
typedef union msm8960_uartdm_generic_register msm8960_uartdm_unused_register_t;
typedef union msm8960_uartdm_mode_register_1 msm8960_uartdm_mode_register_1_t;
typedef union msm8960_uartdm_mode_register_2 msm8960_uartdm_mode_register_2_t;
typedef union msm8960_uartdm_clock_selection_register msm8960_uartdm_clock_selection_register_t;
typedef union msm8960_uartdm_generic_register msm8960_uartdm_transmit_fifo_register_t;
typedef union msm8960_uartdm_generic_register msm8960_uartdm_receive_fifo_register_t;
typedef union msm8960_uartdm_command_register msm8960_uartdm_command_register_t;
typedef union msm8960_uartdm_interrupt_mask_register msm8960_uartdm_interrupt_mask_register_t;
typedef union msm8960_uartdm_interrupt_programming_register msm8960_uartdm_interrupt_programming_register_t;
typedef union msm8960_uartdm_tx_fifo_watermark_register msm8960_uartdm_tx_fifo_watermark_register_t;
typedef union msm8960_uartdm_rx_fifo_watermark_register msm8960_uartdm_rx_fifo_watermark_register_t;
typedef union msm8960_uartdm_hunt_character_register msm8960_uartdm_hunt_character_register_t;
typedef union msm8960_uartdm_m_register msm8960_uartdm_m_register_t;
typedef union msm8960_uartdm_n_register msm8960_uartdm_n_register_t;
typedef union msm8960_uartdm_d_register msm8960_uartdm_d_register_t;
typedef union msm8960_uartdm_mnd_register msm8960_uartdm_mnd_register_t;
typedef union msm8960_uartdm_irda_register msm8960_uartdm_irda_register_t;
typedef union msm8960_uartdm_data_mover_enable_register msm8960_uartdm_data_mover_enable_register_t;
typedef union msm8960_uartdm_data_mover_tx_length_register msm8960_uartdm_data_mover_tx_length_register_t;
typedef union msm8960_uartdm_data_mover_base_address_register msm8960_uartdm_data_mover_base_address_register_t;
typedef union msm8960_uartdm_status_register msm8960_uartdm_status_register_t;
typedef union msm8960_uartdm_masked_interrupt_status_register msm8960_uartdm_masked_interrupt_status_register_t;
typedef union msm8960_uartdm_interrupt_status_register msm8960_uartdm_interrupt_status_register_t;
typedef union msm8960_uartdm_data_mover_rx_length_register msm8960_uartdm_data_mover_rx_length_register_t;
typedef union msm8960_uartdm_tx_fifo_state_register msm8960_uartdm_tx_fifo_state_register_t;
typedef union msm8960_uartdm_rx_fifo_state_register msm8960_uartdm_rx_fifo_state_register_t;

typedef volatile struct msm8960_uartdm_block msm8960_uartdm_block_t;

union msm8960_uartdm_generic_register {
	u8_t  u8;
	u16_t u16;
	u32_t all;
};

union msm8960_uartdm_mode_register_1 {
	struct {
		u32_t auto_rfr_level0 :5;
		u32_t cts_ctl         :1;
		u32_t rx_rdy_ctl      :1;
		u32_t auto_rfr_level1 :2;
		u32_t res_0           :2;
	} fields;
	u32_t all;
};

union msm8960_uartdm_mode_register_2 {
	struct {
		u32_t parity_mode   :2;
		u32_t stop_bit_len  :2;
		u32_t bits_per_char :2;
		u32_t error_mode    :1;
		u32_t num_char      :1;
	} fields;
	u32_t all;
};

union msm8960_uartdm_clock_selection_register {
	struct {
		u32_t rx_clk_sel :4;
		u32_t tx_clk_sel :4;
	} fields;
	u32_t all;
};

union msm8960_uartdm_command_register {
	struct {
		u32_t rx_en           :1;
		u32_t rx_disable      :1;
		u32_t tx_en           :1;
		u32_t tx_disable      :1;
		u32_t command_channel :4;
		u32_t cr_prot_en      :1;
	} fields;
	u32_t all;
};

union msm8960_uartdm_interrupt_mask_register {
	struct {
		u32_t txlev :1;
		u32_t rxhunt :1;
		u32_t rxbreak :1;
		u32_t rxstale :1;
		u32_t rxlev :1;
		u32_t delta_cts :1;
		u32_t current_cts :1;
	} fields;
	u32_t all;
};

union msm8960_uartdm_interrupt_programming_register {
	struct {
		u32_t stale_timeout_lsb :5;
		u32_t res_0 :1;
		u32_t sample_data :1;
		u32_t stale_timeout_msb :4;
	} fields;
	u32_t all;
};

union msm8960_uartdm_tx_fifo_watermark_register {
	struct {
		u32_t tfw :7;
	} fields;
	u32_t all;
};

union msm8960_uartdm_rx_fifo_watermark_register {
	struct {
		u32_t rfw :7;
	} fields;
	u32_t all;
};

union msm8960_uartdm_hunt_character_register {
	struct {
		u32_t data :8;
	} fields;
	u32_t all;
};

union msm8960_uartdm_m_register {
	struct {
		u32_t data :12;
	} fields;
	u32_t all;
};

union msm8960_uartdm_n_register {
	struct {
		u32_t nreg :12;
	} fields;
};

union msm8960_uartdm_d_register {
	struct {
		u32_t data :12;
	} fields;
	u32_t all;
};

union msm8960_uartdm_mnd_register {
	struct {
		u32_t dreg_lsb :2;
		u32_t nreg_lsb :3;
		u32_t mreg_lsb :1;
	} fields;
	u32_t all;
};

union msm8960_uartdm_irda_register {
	struct {
		u32_t irda_en :1;
		u32_t invert_irda_rx :1;
		u32_t invert_irda_tx :1;
		u32_t irda_loopback :1;
		u32_t medium_rate_en :1;
	} fields;
	u32_t all;
};

union msm8960_uartdm_data_mover_enable_register {
	struct {
		u32_t tx_dm_en :1;
		u32_t rx_dm_en :1;
	} fields;
	u32_t all;
};

union msm8960_uartdm_data_mover_tx_length_register {
	struct {
		u32_t tx_dm_last_char_length :2;
		u32_t tx_dm_word_length :14;
	} fields;
	u32_t all;
};

union msm8960_uartdm_data_mover_base_address_register {
	struct {
		u32_t unused_0 :2;
		u32_t rx_base_addr :5;
	} fields;
	u32_t all;
};

union msm8960_uartdm_status_register {
	struct {
		u32_t rxrdy :1;
		u32_t rxfull :1;
		u32_t txrdy :1;
		u32_t txemt :1;
		u32_t overrun :1;
		u32_t par_frame_err :1;
		u32_t rx_break :1;
		u32_t hunt_char :1;
	} fields;
	u32_t all;
};

union msm8960_uartdm_masked_interrupt_status_register {
	struct {
		u32_t misr :7;
	} fields;
	u32_t all;
};

union msm8960_uartdm_interrupt_status_register {
	struct {
		u32_t txlev :1;
		u32_t rxhunt :1;
		u32_t rxbreak :1;
		u32_t rxstale :1;
		u32_t rxlev :1;
		u32_t delta_cts :1;
		u32_t current_cts :1;
	} fields;
	u32_t all;
};

union msm8960_uartdm_data_mover_rx_length_register {
	struct {
		u32_t rx_dm_length :16;
	} fields;
	u32_t all;
};

union msm8960_uartdm_tx_fifo_state_register {
	struct {
		u32_t tx_fifo_state :7;
	} fields;
	u32_t all;
};

union msm8960_uartdm_rx_fifo_state_register {
	struct {
		u32_t rx_fifo_state :7;
	} fields;
	u32_t all;
};

struct msm8960_uartdm_block {
	msm8960_uartdm_mode_register_1_t mr1;                           // MSM8960_UARTDM_MR1_OFFSET = 0x0
	msm8960_uartdm_mode_register_2_t mr2;                           // MSM8960_UARTDM_MR2_OFFSET = 0x4
	union {
		msm8960_uartdm_clock_selection_register_t csr;              // MSM8960_UARTDM_CSR_OFFSET = 0x8
		msm8960_uartdm_status_register_t sr;                        // MSM8960_UARTDM_SR_OFFSET = 0x8
	};
	msm8960_uartdm_unused_register_t unused_0;
	union {
		msm8960_uartdm_command_register_t cr;                       // MSM8960_UARTDM_CR_OFFSET = 0x10
		msm8960_uartdm_masked_interrupt_status_register_t misr;     // MSM8960_UARTDM_MISR_OFFSET = 0x10
	};
	union {
		msm8960_uartdm_interrupt_mask_register_t imr;               // MSM8960_UARTDM_IMR_OFFSET = 0x14
		msm8960_uartdm_interrupt_status_register_t isr;             // MSM8960_UARTDM_ISR_OFFSET = 0x14
	};
	msm8960_uartdm_interrupt_programming_register_t ipr;            // MSM8960_UARTDM_IPR_OFFSET = 0x18
	msm8960_uartdm_tx_fifo_watermark_register_t txwr;               // MSM8960_UARTDM_TFWR_OFFSET = 0x1C
	msm8960_uartdm_rx_fifo_watermark_register_t rxwr;               // MSM8960_UARTDM_RFWR_OFFSET = 0x20
	msm8960_uartdm_hunt_character_register_t hcr;                   // MSM8960_UARTDM_HCR_OFFSET = 0x24
	msm8960_uartdm_m_register_t m;                                  // MSM8960_UARTDM_MREG_OFFSET = 0x28
	msm8960_uartdm_n_register_t n;                                  // MSM8960_UARTDM_NREG_OFFSET = 0x2C
	msm8960_uartdm_d_register_t d;                                  // MSM8960_UARTDM_DREG_OFFSET = 0x30
	msm8960_uartdm_mnd_register_t mnd;                              // MSM8960_UARTDM_MNDREG_OFFSET = 0x34
	union {
		msm8960_uartdm_irda_register_t irda;                        // MSM8960_UARTDM_IDRA_OFFSET = 0x38
		msm8960_uartdm_data_mover_rx_length_register_t dmrx;        // MSM8960_UARTDM_DMRX_OFFSET = 0x38
	};
	msm8960_uartdm_data_mover_enable_register_t dmen;               // MSM8960_UARTDM_DMEN_OFFSET = 0x3C
	msm8960_uartdm_data_mover_tx_length_register_t dmtx;            // MSM8960_UARTDM_DMTX_OFFSET = 0x40
	msm8960_uartdm_data_mover_base_address_register_t badr;         // MSM8960_UARTDM_BADR_OFFSET = 0x44
	msm8960_uartdm_generic_register_t testsl;                       // MSM8960_UARTDM_TESTSL_OFFSET = 0x48
	msm8960_uartdm_tx_fifo_state_register_t txfs;                   // MSM8960_UARTDM_TXFS_OFFSET = 0x4C
	msm8960_uartdm_rx_fifo_state_register_t rxfs;                   // MSM8960_UARTDM_RXFS_OFFSET = 0x50
	msm8960_uartdm_unused_register_t unused_1[(MSM8960_UARTDM_MISR_MODE_OFFSET - (MSM8960_UARTDM_RXFS_OFFSET + 1)) / BYTES_PER_LONG];
	msm8960_uartdm_generic_register_t misr_mode;                    // MSM8960_UARTDM_MISR_MODE_OFFSET = 0x60
	msm8960_uartdm_generic_register_t misr_reset;                   // MSM8960_UARTDM_MISR_RESET_OFFSET = 0x64
	msm8960_uartdm_generic_register_t misr_export;                  // MSM8960_UARTDM_MISR_EXPORT_OFFSET = 0x68
	msm8960_uartdm_generic_register_t misr_val;                     // MSM8960_UARTDM_MISR_VAL_OFFSET = 0x6C
	msm8960_uartdm_unused_register_t unused_2[(MSM8960_UARTDM_TF_OFFSET - (MSM8960_UARTDM_MISR_VAL_OFFSET + 1)) / BYTES_PER_LONG];
	union {
		msm8960_uartdm_transmit_fifo_register_t tf;                 // MSM8960_UARTDM_TF_OFFSET = 0x70
		msm8960_uartdm_receive_fifo_register_t rf;                  // MSM8960_UARTDM_RF_OFFSET = 0x70
	};
	union {
		msm8960_uartdm_transmit_fifo_register_t tf_2;               // MSM8960_UARTDM_TF_2_OFFSET = 0x74
		msm8960_uartdm_receive_fifo_register_t rf_2;                // MSM8960_UARTDM_RF_2_OFFSET = 0x74
	};
	union {
		msm8960_uartdm_transmit_fifo_register_t tf_3;              // MSM8960_UARTDM_TF_3_OFFSET = 0x78
		msm8960_uartdm_receive_fifo_register_t rf_3;               // MSM8960_UARTDM_RF_3_OFFSET = 0x78
	};
	union {
		msm8960_uartdm_transmit_fifo_register_t tf_4;              // MSM8960_UARTDM_TF_4_OFFSET = 0x7C
		msm8960_uartdm_receive_fifo_register_t rf_4;               // MSM8960_UARTDM_RF_4_OFFSET = 0x7C
	};
} PACKED;

result_t msm8960_uartdm_init(msm8960_uartdm_block_t *block, size_t options);
result_t msm8960_uartdm_fini(msm8960_uartdm_block_t *block);

result_t msm8960_uartdm_set_clock(msm8960_uartdm_block_t *block);

result_t msm8960_uartdm_write(msm8960_uartdm_block_t *block, u8_t *buffer, size_t size);
result_t msm8960_uartdm_read(msm8960_uartdm_block_t *block, u8_t *buffer, size_t size);

result_t msm8960_uartdm_putc(msm8960_uartdm_block_t *block, u8_t c);
result_t msm8960_uartdm_getc(msm8960_uartdm_block_t *block, u8_t *c);

#endif //__C__

#endif //__DBG_MSM8960_MSM8960_UARTDM_H__
