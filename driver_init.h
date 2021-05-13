/*
 * Code generated from Atmel Start.
 *
 * This file will be overwritten when reconfiguring your Atmel Start project.
 * Please copy examples or other code you want to keep to a separate file
 * to avoid losing it when reconfiguring.
 */
#ifndef DRIVER_INIT_H_INCLUDED
#define DRIVER_INIT_H_INCLUDED

#include "atmel_start_pins.h"

#ifdef __cplusplus
extern "C" {
#endif

#include <hal_atomic.h>
#include <hal_delay.h>
#include <hal_gpio.h>
#include <hal_init.h>
#include <hal_io.h>
#include <hal_sleep.h>

#include <hal_adc_async.h>

#include <hal_spi_m_sync.h>

#include <hal_spi_m_async.h>

#include <hal_delay.h>

#include <hal_usart_sync.h>
#include <hpl_uart_base.h>

#include <hal_wdt.h>

extern struct adc_async_descriptor ADC_0;

/* The enabled channel for ADC */

#define CONF_ADC_0_CHANNEL_9 9

extern struct spi_m_sync_descriptor SPI_0;

extern struct spi_m_async_descriptor SPI_1;

extern struct usart_sync_descriptor TARGET_IO;

extern struct wdt_descriptor WDT_0;

void SPI_0_PORT_init(void);
void SPI_0_CLOCK_init(void);
void SPI_0_init(void);

void SPI_1_PORT_init(void);
void SPI_1_CLOCK_init(void);
void SPI_1_init(void);

void delay_driver_init(void);

void TARGET_IO_PORT_init(void);
void TARGET_IO_CLOCK_init(void);
void TARGET_IO_init(void);
void TARGET_IO_example(void);

void WDT_0_init(void);

/**
 * \brief Perform system initialization, initialize pins and clocks for
 * peripherals
 */
void system_init(void);

#ifdef __cplusplus
}
#endif
#endif // DRIVER_INIT_H_INCLUDED
