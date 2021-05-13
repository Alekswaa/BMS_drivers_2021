/*
 * Code generated from Atmel Start.
 *
 * This file will be overwritten when reconfiguring your Atmel Start project.
 * Please copy examples or other code you want to keep to a separate file
 * to avoid losing it when reconfiguring.
 */
#ifndef ATMEL_START_PINS_H_INCLUDED
#define ATMEL_START_PINS_H_INCLUDED

#include <hal_gpio.h>

// SAMV71 has 4 pin functions

#define GPIO_PIN_FUNCTION_A 0
#define GPIO_PIN_FUNCTION_B 1
#define GPIO_PIN_FUNCTION_C 2
#define GPIO_PIN_FUNCTION_D 3

#define UART_TX GPIO(GPIO_PORTA, 4)
#define UART_RX GPIO(GPIO_PORTA, 5)
#define silent0 GPIO(GPIO_PORTB, 0)
#define silent1 GPIO(GPIO_PORTB, 1)
#define AD0_CH9 GPIO(GPIO_PORTC, 0)
#define SPI1_SPCK GPIO(GPIO_PORTC, 24)
#define SPI1_MISO GPIO(GPIO_PORTC, 26)
#define SPI1_MOSI GPIO(GPIO_PORTC, 27)
#define SPI0_MISO GPIO(GPIO_PORTD, 20)
#define SPI0_MOSI GPIO(GPIO_PORTD, 21)
#define SPI0_SPCK GPIO(GPIO_PORTD, 22)

#endif // ATMEL_START_PINS_H_INCLUDED
