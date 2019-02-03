#ifndef __MAX_7219_H
#define __MAX_7219_H

#include "stm8s.h"

typedef enum Max7219Number {
	MAX7219_NUMBER_0,
	MAX7219_NUMBER_1,
	MAX7219_NUMBER_2,
	MAX7219_NUMBER_3,
	MAX7219_NUMBER_COUNT,
} Max7219Number;

#define MAX7219_COMMAND_SIZE_IN_BYTES		2
#define MAX7219_COMMAND_BUFF_SIZE			(MAX7219_COMMAND_SIZE_IN_BYTES * MAX7219_NUMBER_COUNT)
#define MAX7219_ROWS_NUMBER					8
#define MAX7219_BUFF_SIZE					(MAX7219_COMMAND_BUFF_SIZE * MAX7219_ROWS_NUMBER)
#define MAX7219_INTENSITY_LEVEL_DEFAULT 	MAX7219_INTENSITY_LEVEL_1
#define FONT_SYMBOL_SIZE_IN_BYTES			8	// TODO: ADD FONT ??

typedef enum Max7219Command {
	MAX7219_SET_STATE,
	MAX7219_SET_TEST_MODE,
	MAX7219_SET_INTENSITY_LEVEL,
} Max7219Command;

typedef enum Max7219CommandArgument {
	MAX7219_STATE_ENABLE = 0x01,
	MAX7219_STATE_DISABLE = 0x00,
	MAX7219_TEST_ENABLE = 0x01,
	MAX7219_TEST_DISABLE = 0x00,
	MAX7219_INTENSITY_LEVEL_0 = 0x00,
	MAX7219_INTENSITY_LEVEL_1 = 0x01,
	MAX7219_INTENSITY_LEVEL_2 = 0x02,
	MAX7219_INTENSITY_LEVEL_3 = 0x03,
	MAX7219_INTENSITY_LEVEL_4 = 0x04,
	MAX7219_INTENSITY_LEVEL_5 = 0x05,
	MAX7219_INTENSITY_LEVEL_6 = 0x06,
	MAX7219_INTENSITY_LEVEL_7 = 0x07,
	MAX7219_INTENSITY_LEVEL_8 = 0x08,
	MAX7219_INTENSITY_LEVEL_9 = 0x09,
	MAX7219_INTENSITY_LEVEL_10 = 0x0A,
	MAX7219_INTENSITY_LEVEL_11 = 0x0B,
	MAX7219_INTENSITY_LEVEL_12 = 0x0C,
	MAX7219_INTENSITY_LEVEL_13 = 0x0D,
	MAX7219_INTENSITY_LEVEL_14 = 0x0E,
	MAX7219_INTENSITY_LEVEL_15 = 0x0F,
} Max7219CommandArgument;

bool max7219Init(uint8_t dataBuff[MAX7219_BUFF_SIZE], uint16_t dataBuffSize);
bool max7219SendCommand(Max7219Number max7219Number, Max7219Command cmd, Max7219CommandArgument arg);
void max7219SendSymbol(Max7219Number max7219Number, const uint8_t symbol[FONT_SYMBOL_SIZE_IN_BYTES]);

#endif // __MAX_7219_H