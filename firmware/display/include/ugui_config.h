#pragma once

#include <stdbool.h>
#include <stdint.h>
#include "main.h"

/* -------------------------------------------------------------------------------- */
/* -- CONFIG SECTION                                                             -- */
/* -------------------------------------------------------------------------------- */

//#define USE_MULTITASKING    
/* Enable color mode */
//#define USE_COLOR_RGB888   // RGB = 0xFF,0xFF,0xFF
#define USE_COLOR_RGB565   // RGB = 0bRRRRRGGGGGGBBBBB

// A special color which means "do not draw", used to let fonts have transparent backgrounds (also to save the cost of rendering when we know the area is already blank)
#define C_TRANSPARENT 0xC1C2

/* Enable needed fonts here */
#define USE_FONT_CURSORS // Used for selection marker

#define  USE_MY_FONT_8X12
#define  USE_MY_FONT_NUM_10X16
#define  USE_MY_FONT_NUM_24X40
#define  USE_MY_FONT_BATTERY
#define  USE_FONT_5X12

#define SCREEN_WIDTH 64
#define SCREEN_HEIGHT 128

// Standard default font selections used most of the time
#define  MICRO_TEXT_FONT              FONT_5X8
#define  SMALL_TEXT_FONT              FONT_5X12
#define  MEDIUM_TEXT_FONT             FONT_8X14
#define  REGULAR_TEXT_FONT            FONT_5X12

#define  TITLE_TEXT_FONT              MY_FONT_8X12
#define  MEDIUM_NUMBERS_TEXT_FONT     MY_FONT_NUM_10X16
#define  BIG_NUMBERS_TEXT_FONT        MY_FONT_NUM_24X40

#define  CONFIGURATIONS_TEXT_FONT     FONT_5X12

#define HEADING_BACKGROUND 			C_BLACK
#define HEADING_BORDER				(BorderBottom | BorderFat)

#define C_WARNING	 				C_WHITE
#define C_ERROR						C_WHITE

#define LABEL_COLOR C_WHITE

//#define  USE_FONT_4X6
#define  USE_FONT_5X8
//#define  USE_FONT_6X8
//#define  USE_FONT_6X10
//#define  USE_FONT_7X12
//#define  USE_FONT_8X8
//#define  USE_FONT_8X12_CYRILLIC
//#define  USE_FONT_8X12
#define  USE_FONT_8X14
// #define  USE_FONT_10X16  // a max of 5 chars per line on SW102 (including padding)
// #define  USE_FONT_12X16
// #define  USE_FONT_12X20
// #define  USE_FONT_16X26
//#define  USE_FONT_22X36
//#define  USE_FONT_24X40 // NOTE: this font burns 30K of of FLASH - huge.  @lowPerformer had the good idea that someday we can strip just the numbers
//#define  USE_FONT_32X53

/* Specify platform-dependent integer types here */

#define __UG_FONT_DATA const
typedef uint8_t UG_U8;
typedef int8_t UG_S8;
typedef uint16_t UG_U16;
typedef int16_t UG_S16;
typedef uint32_t UG_U32;
typedef int32_t UG_S32;

/* Example for dsPIC33
 typedef unsigned char         UG_U8;
 typedef signed char           UG_S8;
 typedef unsigned int          UG_U16;
 typedef signed int            UG_S16;
 typedef unsigned long int     UG_U32;
 typedef signed long int       UG_S32;
 */

/* -------------------------------------------------------------------------------- */
/* -------------------------------------------------------------------------------- */

/* Feature enablers */
#define USE_PRERENDER_EVENT
#define USE_POSTRENDER_EVENT

