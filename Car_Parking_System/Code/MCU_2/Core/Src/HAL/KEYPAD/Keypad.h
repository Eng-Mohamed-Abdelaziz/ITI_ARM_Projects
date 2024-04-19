/*******************************************************************************/

#ifndef KEYPAD_H_
#define KEYPAD_H_

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../MCAL/MGPIO/MGPIO_interface.h"
#include "../../MCAL/MRCC/MRCC_Int.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/

/* Keypad configurations for number of rows and columns */
#define KEYPAD_NUM_COLS                   4
#define KEYPAD_NUM_ROWS                   4

/* Keypad Port Configurations */
#define KEYPAD_ROW_PORT_ID                _GPIOB_PORT
#define KEYPAD_FIRST_ROW_PIN_ID           _PIN_5

#define KEYPAD_COL_PORT_ID                _GPIOB_PORT
#define KEYPAD_FIRST_COL_PIN_ID           _PIN_12

/* Keypad button logic configurations */
#define KEYPAD_BUTTON_PRESSED            LOW
#define KEYPAD_BUTTON_RELEASED           HIGH

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * Description :
 * Get the Keypad pressed button
 */
u8 KEYPAD_getPressedKey(void);

#endif /* KEYPAD_H_ */
