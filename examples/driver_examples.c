/*
 * Code generated from Atmel Start.
 *
 * This file will be overwritten when reconfiguring your Atmel Start project.
 * Please copy examples or other code you want to keep to a separate file
 * to avoid losing it when reconfiguring.
 */

#include "driver_examples.h"
#include "driver_init.h"
#include "utils.h"

static void convert_cb_ADC_0_CHANNEL_9(const struct adc_async_descriptor *const descr, const uint8_t channel)
{
}

/**
 * Example of using ADC_0 to generate waveform.
 */
void ADC_0_example(void)
{
	adc_async_register_callback(&ADC_0, CONF_ADC_0_CHANNEL_9, ADC_ASYNC_CONVERT_CB, convert_cb_ADC_0_CHANNEL_9);
	adc_async_enable_channel(&ADC_0, CONF_ADC_0_CHANNEL_9);
	adc_async_start_conversion(&ADC_0);
}

/**
 * Example of using SPI_0 to write "Hello World" using the IO abstraction.
 */
static uint8_t example_SPI_0[12] = "Hello World!";

void SPI_0_example(void)
{
	struct io_descriptor *io;
	spi_m_sync_get_io_descriptor(&SPI_0, &io);

	spi_m_sync_enable(&SPI_0);
	io_write(io, example_SPI_0, 12);
}

/**
 * Example of using SPI_1 to write "Hello World" using the IO abstraction.
 *
 * Since the driver is asynchronous we need to use statically allocated memory for string
 * because driver initiates transfer and then returns before the transmission is completed.
 *
 * Once transfer has been completed the tx_cb function will be called.
 */

static uint8_t example_SPI_1[12] = "Hello World!";

static void complete_cb_SPI_1(const struct spi_m_async_descriptor *const io_descr)
{
	/* Transfer completed */
}

void SPI_1_example(void)
{
	struct io_descriptor *io;
	spi_m_async_get_io_descriptor(&SPI_1, &io);

	spi_m_async_register_callback(&SPI_1, SPI_M_ASYNC_CB_XFER, (FUNC_PTR)complete_cb_SPI_1);
	spi_m_async_enable(&SPI_1);
	io_write(io, example_SPI_1, 12);
}

void delay_example(void)
{
	delay_ms(5000);
}

/**
 * Example of using TARGET_IO to write "Hello World" using the IO abstraction.
 */
void TARGET_IO_example(void)
{
	struct io_descriptor *io;
	usart_sync_get_io_descriptor(&TARGET_IO, &io);
	usart_sync_enable(&TARGET_IO);

	io_write(io, (uint8_t *)"Hello World!", 12);
}

/**
 * Example of using WDT_0.
 */
void WDT_0_example(void)
{
	/**
	 * ATSAMV71Q21B do not support wdt_set_timeout_period()
	 * and wdt_enable(), the watch dog will start counting once
	 * wdt_init() been called.
	 * The application should call wdt_feed(&WDT_0) at
	 * regular intervals before the timer underflow.
	 */
	wdt_feed(&WDT_0);
}
