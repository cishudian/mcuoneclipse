/* ###################################################################
**     This component module is generated by Processor Expert. Do not modify it.
**     Filename    : LEDB.h
**     Project     : FRDM-KL27Z_McuOnEclipseLib
**     Processor   : MKL25Z128VLK4
**     Component   : LED
**     Version     : Component 01.074, Driver 01.00, CPU db: 3.00.000
**     Repository  : Legacy User Components
**     Compiler    : GNU C Compiler
**     Date/Time   : 2017-03-10, 16:49, # CodeGen: 71
**     Abstract    :
**          This component implements a universal driver for a single LED.
**     Settings    :
**          Component name                                 : LEDB
**          SDK                                            : MCUC1
**          Turned On with initialization                  : no
**          HW Interface                                   : 
**            Anode on port side, HIGH is ON               : no
**            On/Off                                       : Enabled
**              Pin                                        : SDK_BitIO
**            PWM                                          : Disabled
**          Shell                                          : Enabled
**            Shell                                        : CLS1
**            Utility                                      : UTIL1
**     Contents    :
**         On           - void LEDB_On(void);
**         Off          - void LEDB_Off(void);
**         Neg          - void LEDB_Neg(void);
**         Get          - uint8_t LEDB_Get(void);
**         Put          - void LEDB_Put(uint8_t val);
**         SetRatio16   - void LEDB_SetRatio16(uint16_t ratio);
**         ParseCommand - uint8_t LEDB_ParseCommand(const unsigned char *cmd, bool *handled, const...
**         Deinit       - void LEDB_Deinit(void);
**         Init         - void LEDB_Init(void);
**
**     * Copyright (c) 2013-2017, Erich Styger
**      * Web:         https://mcuoneclipse.com
**      * SourceForge: https://sourceforge.net/projects/mcuoneclipse
**      * Git:         https://github.com/ErichStyger/McuOnEclipse_PEx
**      * All rights reserved.
**      *
**      * Redistribution and use in source and binary forms, with or without modification,
**      * are permitted provided that the following conditions are met:
**      *
**      * - Redistributions of source code must retain the above copyright notice, this list
**      *   of conditions and the following disclaimer.
**      *
**      * - Redistributions in binary form must reproduce the above copyright notice, this
**      *   list of conditions and the following disclaimer in the documentation and/or
**      *   other materials provided with the distribution.
**      *
**      * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
**      * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
**      * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
**      * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
**      * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
**      * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
**      * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
**      * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
**      * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
**      * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
** ###################################################################*/
/*!
** @file LEDB.h
** @version 01.00
** @brief
**          This component implements a universal driver for a single LED.
*/         
/*!
**  @addtogroup LEDB_module LEDB module documentation
**  @{
*/         

#ifndef __LEDB_H
#define __LEDB_H

/* MODULE LEDB. */
#include "MCUC1.h" /* SDK and API used */
#include "LEDBconfig.h" /* configuration */

/* Include inherited components */
#include "MCUC1.h"
#include "LEDpin1.h"
#include "CLS1.h"
#include "UTIL1.h"

#define LEDB_ClrVal()    LEDpin1_ClrVal() /* put the pin on low level */
#define LEDB_SetVal()    LEDpin1_SetVal() /* put the pin on high level */
#define LEDB_SetInput()  LEDpin1_SetInput() /* use the pin as input pin */
#define LEDB_SetOutput() LEDpin1_SetOutput() /* use the pin as output pin */

#define LEDB_PARSE_COMMAND_ENABLED  1 /* set to 1 if method ParseCommand() is present, 0 otherwise */


#define LEDB_On() LEDpin1_ClrVal()
/*
** ===================================================================
**     Method      :  LEDB_On (component LED)
**     Description :
**         This turns the LED on.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

#define LEDB_Off() LEDpin1_SetVal()
/*
** ===================================================================
**     Method      :  LEDB_Off (component LED)
**     Description :
**         This turns the LED off.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

#define LEDB_Neg() LEDpin1_NegVal()
/*
** ===================================================================
**     Method      :  LEDB_Neg (component LED)
**     Description :
**         This negates/toggles the LED
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

#define LEDB_Get() (!(LEDpin1_GetVal()))
/*
** ===================================================================
**     Method      :  LEDB_Get (component LED)
**     Description :
**         This returns logical 1 in case the LED is on, 0 otherwise.
**     Parameters  : None
**     Returns     :
**         ---             - Status of the LED (on or off)
** ===================================================================
*/

void LEDB_Init(void);
/*
** ===================================================================
**     Method      :  LEDB_Init (component LED)
**     Description :
**         Performs the LED driver initialization.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

#define LEDB_Put(val)  ((val) ? LEDB_On() : LEDB_Off())
/*
** ===================================================================
**     Method      :  LEDB_Put (component LED)
**     Description :
**         Turns the LED on or off.
**     Parameters  :
**         NAME            - DESCRIPTION
**         val             - value to define if the LED has to be on or
**                           off.
**     Returns     : Nothing
** ===================================================================
*/

void LEDB_Deinit(void);
/*
** ===================================================================
**     Method      :  LEDB_Deinit (component LED)
**     Description :
**         Deinitializes the driver
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

uint8_t LEDB_ParseCommand(const unsigned char *cmd, bool *handled, const CLS1_StdIOType *io);
/*
** ===================================================================
**     Method      :  LEDB_ParseCommand (component LED)
**     Description :
**         Shell Command Line parser. This method is enabled/disabled
**         depending on if you have the Shell enabled/disabled in the
**         properties.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * cmd             - Pointer to command string
**       * handled         - Pointer to variable which tells if
**                           the command has been handled or not
**       * io              - Pointer to I/O structure
**     Returns     :
**         ---             - Error code
** ===================================================================
*/

void LEDB_SetRatio16(uint16_t ratio);
/*
** ===================================================================
**     Method      :  LEDB_SetRatio16 (component LED)
**     Description :
**         Method to specify the duty cycle. If using a PWM pin, this
**         means the duty cycle is set. For On/off pins, values smaller
**         0x7FFF means off, while values greater means on.
**     Parameters  :
**         NAME            - DESCRIPTION
**         ratio           - Ratio value, where 0 means 'off' and
**                           0xffff means 'on'
**     Returns     : Nothing
** ===================================================================
*/

/* END LEDB. */

#endif
/* ifndef __LEDB_H */
/*!
** @}
*/
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.5 [05.21]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/
