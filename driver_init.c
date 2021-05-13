/*
 * Code generated from Atmel Start.
 *
 * This file will be overwritten when reconfiguring your Atmel Start project.
 * Please copy examples or other code you want to keep to a separate file
 * to avoid losing it when reconfiguring.
 */

#include "driver_init.h"
#include <hal_init.h>
#include <hpl_pmc.h>
#include <peripheral_clk_config.h>
#include <utils.h>
#include <hpl_spi_base.h>
#include <hpl_spi_base.h>

/* The channel amount for ADC */
#define ADC_0_CH_AMOUNT 1

/* The buffer size for ADC */
#define ADC_0_CH9_BUF_SIZE 16

/* The maximal channel number of enabled channels */
#define ADC_0_CH_MAX 9

struct adc_async_descriptor ADC_0;
#if ADC_0_CH_AMOUNT < 1
/* Avoid compiling errors. */
struct adc_async_channel_descriptor ADC_0_ch[1];
#warning none of ADC channel is enabled, please check
#else
struct adc_async_channel_descriptor ADC_0_ch[ADC_0_CH_AMOUNT];
#endif
struct spi_m_sync_descriptor SPI_0;

static uint8_t ADC_0_ch9_buf[ADC_0_CH9_BUF_SIZE];

#ifdef ADC_0_CH_MAX
static uint8_t ADC_0_map[ADC_0_CH_MAX + 1];
#endif

struct spi_m_async_descriptor SPI_1;

struct usart_sync_descriptor TARGET_IO;

struct wdt_descriptor WDT_0;

/**
 * \brief ADC initialization function
 *
 * Enables ADC peripheral, clocks and initializes ADC driver
 */
static void ADC_0_init(void)
{
	_pmc_enable_periph_clock(ID_AFEC1);
#ifdef ADC_0_CH_MAX
	adc_async_init(&ADC_0, AFEC1, ADC_0_map, ADC_0_CH_MAX, ADC_0_CH_AMOUNT, &ADC_0_ch[0], (void *)NULL);
#endif

	adc_async_register_channel_buffer(&ADC_0, CONF_ADC_0_CHANNEL_9, ADC_0_ch9_buf, ADC_0_CH9_BUF_SIZE);

	gpio_set_pin_function(AD0_CH9, GPIO_PIN_FUNCTION_OFF);
}

void SPI_0_PORT_init(void)
{

	gpio_set_pin_function(SPI0_MISO, MUX_PD20B_SPI0_MISO);

	gpio_set_pin_function(SPI0_MOSI, MUX_PD21B_SPI0_MOSI);

	gpio_set_pin_function(SPI0_SPCK, MUX_PD22B_SPI0_SPCK);
}

void SPI_0_CLOCK_init(void)
{
	_pmc_enable_periph_clock(ID_SPI0);
}

void SPI_0_init(void)
{
	SPI_0_CLOCK_init();
	spi_m_sync_set_func_ptr(&SPI_0, _spi_get_spi_m_sync());
	spi_m_sync_init(&SPI_0, SPI0);
	SPI_0_PORT_init();
}

void SPI_1_PORT_init(void)
{

	gpio_set_pin_function(SPI1_MISO, MUX_PC26C_SPI1_MISO);

	gpio_set_pin_function(SPI1_MOSI, MUX_PC27C_SPI1_MOSI);

	gpio_set_pin_function(SPI1_SPCK, MUX_PC24C_SPI1_SPCK);
}

void SPI_1_CLOCK_init(void)
{
	_pmc_enable_periph_clock(ID_SPI1);
}

void SPI_1_init(void)
{
	SPI_1_CLOCK_init();
	spi_m_async_set_func_ptr(&SPI_1, _spi_get_spi_m_async());
	spi_m_async_init(&SPI_1, SPI1);
	SPI_1_PORT_init();
}

void delay_driver_init(void)
{
	delay_init(SysTick);
}

void TARGET_IO_PORT_init(void)
{

	gpio_set_pin_function(UART_RX, MUX_PA5C_UART1_URXD1);

	gpio_set_pin_function(UART_TX, MUX_PA4C_UART1_UTXD1);
}

void TARGET_IO_CLOCK_init(void)
{
	_pmc_enable_periph_clock(ID_UART1);
}

void TARGET_IO_init(void)
{
	TARGET_IO_CLOCK_init();
	usart_sync_init(&TARGET_IO, UART1, _uart_get_usart_sync());
	TARGET_IO_PORT_init();
}

void WDT_0_init(void)
{
	wdt_init(&WDT_0, WDT);
}

void system_init(void)
{
	init_mcu();

	_pmc_enable_periph_clock(ID_PIOB);

	/* GPIO on PB0 */

	gpio_set_pin_level(silent0,
	                   // <y> Initial level
	                   // <id> pad_initial_level
	                   // <false"> Low
	                   // <true"> High
	                   false);

	// Set pin direction to output
	gpio_set_pin_direction(silent0, GPIO_DIRECTION_OUT);

	gpio_set_pin_function(silent0, GPIO_PIN_FUNCTION_OFF);

	/* GPIO on PB1 */

	gpio_set_pin_level(silent1,
	                   // <y> Initial level
	                   // <id> pad_initial_level
	                   // <false"> Low
	                   // <true"> High
	                   false);

	// Set pin direction to output
	gpio_set_pin_direction(silent1, GPIO_DIRECTION_OUT);

	gpio_set_pin_function(silent1, GPIO_PIN_FUNCTION_OFF);

	ADC_0_init();

	SPI_0_init();

	SPI_1_init();

	delay_driver_init();

	TARGET_IO_init();

	//WDT_0_init();
}
