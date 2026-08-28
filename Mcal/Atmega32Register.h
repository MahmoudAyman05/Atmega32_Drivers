/*
 * Atmega32Register.h
 *
 *  Created on: Aug 17, 2026
 *      Author: mahmo
 */

#ifndef MCAL_ATMEGA32REGISTER_H_
#define MCAL_ATMEGA32REGISTER_H_

#include <stdint.h>
// IO
#define DDRA_Reg *((volatile uint8_t*)0x3A)
#define DDRB_Reg *((volatile uint8_t*)0x37)
#define DDRC_Reg *((volatile uint8_t*)0x34)
#define DDRD_Reg *((volatile uint8_t*)0x31)

#define PORTA_Reg *((volatile uint8_t*)0x3B)
#define PORTB_Reg *((volatile uint8_t*)0x38)
#define PORTC_Reg *((volatile uint8_t*)0x35)
#define PORTD_Reg *((volatile uint8_t*)0x32)

#define PINA_Reg *((volatile uint8_t*)0x39)
#define PINB_Reg *((volatile uint8_t*)0x36)
#define PINC_Reg *((volatile uint8_t*)0x33)
#define PIND_Reg *((volatile uint8_t*)0x30)

//CPU / Stack / Status
#define SREG_Reg *((volatile uint8_t*)0x5F)
#define SPH_Reg  *((volatile uint8_t*)0x5E)
#define SPL_Reg  *((volatile uint8_t*)0x5D)

// Timer/Counter0
#define OCR0_Reg  *((volatile uint8_t*)0x5C)
#define TCCR0_Reg *((volatile uint8_t*)0x53)
#define TCNT0_Reg *((volatile uint8_t*)0x52)

// External Interrupts
#define GICR_Reg  *((volatile uint8_t*)0x5B)
#define GIFR_Reg  *((volatile uint8_t*)0x5A)

// Timer Interrupt Mask/Flags
#define TIMSK_Reg *((volatile uint8_t*)0x59)
#define TIFR_Reg  *((volatile uint8_t*)0x58)

//Store Program Memory / TWI Control
#define SPMCR_Reg   *((volatile uint8_t*)0x57)
#define TWCR_Reg    *((volatile uint8_t*)0x56)

// MCU Control
#define MCUCR_Reg   *((volatile uint8_t*)0x55)
#define MCUCSR_Reg  *((volatile uint8_t*)0x54)

// Oscillator Calibration / On-Chip Debug
#define OSCCAL_Reg  *((volatile uint8_t*)0x51)
#define OCDR_Reg    *((volatile uint8_t*)0x51)

//Special Function I/O
#define SFIOR_Reg   *((volatile uint8_t*)0x50)

//Timer/Counter1
#define TCCR1A_Reg  *((volatile uint8_t*)0x4F)
#define TCCR1B_Reg  *((volatile uint8_t*)0x4E)
#define TCNT1H_Reg  *((volatile uint8_t*)0x4D)
#define TCNT1L_Reg  *((volatile uint8_t*)0x4C)
#define OCR1AH_Reg  *((volatile uint8_t*)0x4B)
#define OCR1AL_Reg  *((volatile uint8_t*)0x4A)
#define OCR1BH_Reg  *((volatile uint8_t*)0x49)
#define OCR1BL_Reg  *((volatile uint8_t*)0x48)
#define ICR1H_Reg   *((volatile uint8_t*)0x47)
#define ICR1L_Reg   *((volatile uint8_t*)0x46)

// Timer/Counter2
#define TCCR2_Reg   *((volatile uint8_t*)0x45)
#define TCNT2_Reg   *((volatile uint8_t*)0x44)
#define OCR2_Reg    *((volatile uint8_t*)0x43)
#define ASSR_Reg    *((volatile uint8_t*)0x42)

//Watch dog
#define WDTCR_Reg   *((volatile uint8_t*)0x41)

// USART Baud Rate / Control
#define UBRRH_Reg   *((volatile uint8_t*)0x40)
#define UCSRC_Reg   *((volatile uint8_t*)0x40)

// EEPROM
#define EEARH_Reg   *((volatile uint8_t*)0x3F)
#define EEARL_Reg   *((volatile uint8_t*)0x3E)
#define EEDR_Reg    *((volatile uint8_t*)0x3D)
#define EECR_Reg    *((volatile uint8_t*)0x3C)

//SPI
#define SPDR_Reg    *((volatile uint8_t*)0x2F)
#define SPSR_Reg    *((volatile uint8_t*)0x2E)
#define SPCR_Reg    *((volatile uint8_t*)0x2D)

// USART
#define UDR_Reg     *((volatile uint8_t*)0x2C)
#define UCSRA_Reg   *((volatile uint8_t*)0x2B)
#define UCSRB_Reg   *((volatile uint8_t*)0x2A)
#define UBRRL_Reg   *((volatile uint8_t*)0x29)

//Analog Comparator
#define ACSR_Reg    *((volatile uint8_t*)0x28)

//ADC
#define ADMUX_Reg   *((volatile uint8_t*)0x27)
#define ADCSRA_Reg  *((volatile uint8_t*)0x26)
#define ADCH_Reg    *((volatile uint8_t*)0x25)
#define ADCL_Reg    *((volatile uint8_t*)0x24)

//Two-Wire Interface (TWI/I2C)
#define TWDR_Reg    *((volatile uint8_t*)0x23)
#define TWAR_Reg    *((volatile uint8_t*)0x22)
#define TWSR_Reg    *((volatile uint8_t*)0x21)
#define TWBR_Reg    *((volatile uint8_t*)0x20)

#endif /* MCAL_ATMEGA32REGISTER_H_ */
