/* ###################################################################
**     This component module is generated by Processor Expert. Do not modify it.
**     Filename    : LEDpin3.c
**     Project     : FRDM-KL27Z_McuOnEclipseLib
**     Processor   : MKL25Z128VLK4
**     Component   : SDK_BitIO
**     Version     : Component 01.022, Driver 01.00, CPU db: 3.00.000
**     Repository  : Legacy User Components
**     Compiler    : GNU C Compiler
**     Date/Time   : 2017-03-10, 17:14, # CodeGen: 73
**     Abstract    :
**
**     Settings    :
**          Component name                                 : LEDpin3
**          SDK                                            : MCUC1
**          GPIO Name                                      : GPIOB
**          PORT Name                                      : PORTB
**          Pin Number                                     : 19
**          Pin Symbol                                     : LED_RED
**          Do Pin Muxing                                  : yes
**          Init Direction                                 : Output
**          Init Value                                     : 0
**     Contents    :
**         GetDir    - bool LEDpin3_GetDir(void);
**         SetDir    - void LEDpin3_SetDir(bool Dir);
**         SetInput  - void LEDpin3_SetInput(void);
**         SetOutput - void LEDpin3_SetOutput(void);
**         GetVal    - bool LEDpin3_GetVal(void);
**         PutVal    - void LEDpin3_PutVal(bool Val);
**         ClrVal    - void LEDpin3_ClrVal(void);
**         SetVal    - void LEDpin3_SetVal(void);
**         NegVal    - void LEDpin3_NegVal(void);
**         Init      - void LEDpin3_Init(void);
**         Deinit    - void LEDpin3_Deinit(void);
**
**     * Copyright (c) 2015-2017, Erich Styger
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
** @file LEDpin3.c
** @version 01.00
** @brief
**
*/         
/*!
**  @addtogroup LEDpin3_module LEDpin3 module documentation
**  @{
*/         

/* MODULE LEDpin3. */

#include "LEDpin3.h"
#if MCUC1_CONFIG_NXP_SDK_2_0_USED
  #include "fsl_port.h" /* include SDK header file for port muxing */
  #include "fsl_gpio.h" /* include SDK header file for GPIO */
#elif MCUC1_CONFIG_SDK_VERSION_USED == MCUC1_CONFIG_SDK_KINETIS_1_3
  #include "fsl_gpio_driver.h" /* include SDK header file for GPIO */
#else
  #error "This component only works with the Kinetis SDK!"
#endif

#if MCUC1_CONFIG_NXP_SDK_2_0_USED

  static const gpio_pin_config_t LEDpin3_configOutput = {
    kGPIO_DigitalOutput,  /* use as output pin */
    LEDpin3_CONFIG_INIT_PIN_VALUE,  /* initial value */
  };

  static const gpio_pin_config_t LEDpin3_configInput = {
    kGPIO_DigitalInput,  /* use as input pin */
    LEDpin3_CONFIG_INIT_PIN_VALUE,  /* initial value */
  };
#elif MCUC1_CONFIG_SDK_VERSION_USED == MCUC1_CONFIG_SDK_KINETIS_1_3
  const gpio_output_pin_user_config_t LEDpin3_OutputConfig[] = {
    {
      .pinName = LED_RED,
      .config.outputLogic = LEDpin3_CONFIG_INIT_PIN_VALUE,
    #if FSL_FEATURE_PORT_HAS_SLEW_RATE
      .config.slewRate = kPortSlowSlewRate,
    #endif
    #if FSL_FEATURE_PORT_HAS_OPEN_DRAIN
      .config.isOpenDrainEnabled = true,
    #endif
    #if FSL_FEATURE_PORT_HAS_DRIVE_STRENGTH
      .config.driveStrength = kPortLowDriveStrength,
    #endif
    },
    {
      .pinName = GPIO_PINS_OUT_OF_RANGE,
    }
  };

  const gpio_input_pin_user_config_t LEDpin3_InputConfig[] = {
    {
      .pinName = LED_RED,
    #if FSL_FEATURE_PORT_HAS_PULL_ENABLE
      .config.isPullEnable = true,
    #endif
    #if FSL_FEATURE_PORT_HAS_PULL_SELECTION
      .config.pullSelect = kPortPullDown,
    #endif
    #if FSL_FEATURE_PORT_HAS_PASSIVE_FILTER
      .config.isPassiveFilterEnabled = true,
    #endif
    #if FSL_FEATURE_PORT_HAS_DIGITAL_FILTER
      .config.isDigitalFilterEnabled = true,
    #endif
    #if FSL_FEATURE_GPIO_HAS_INTERRUPT_VECTOR
      .config.interrupt = kPortIntDisabled
    #endif
    },
    {
      .pinName = GPIO_PINS_OUT_OF_RANGE,
    }
  };

#endif

static bool LEDpin3_isOutput = false;
/*
** ===================================================================
**     Method      :  LEDpin3_ClrVal (component SDK_BitIO)
**     Description :
**         Clears the pin value (sets it to a low level)
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void LEDpin3_ClrVal(void)
{
#if MCUC1_CONFIG_NXP_SDK_2_0_USED
  GPIO_ClearPinsOutput(LEDpin3_CONFIG_GPIO_NAME, 1<<LEDpin3_CONFIG_PIN_NUMBER);
#elif MCUC1_CONFIG_SDK_VERSION_USED == MCUC1_CONFIG_SDK_KINETIS_1_3
  GPIO_DRV_ClearPinOutput(LED_RED);
#endif
}

/*
** ===================================================================
**     Method      :  LEDpin3_SetVal (component SDK_BitIO)
**     Description :
**         Sets the pin value to a high value.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void LEDpin3_SetVal(void)
{
#if MCUC1_CONFIG_NXP_SDK_2_0_USED
  GPIO_SetPinsOutput(LEDpin3_CONFIG_GPIO_NAME, 1<<LEDpin3_CONFIG_PIN_NUMBER);
#elif MCUC1_CONFIG_SDK_VERSION_USED == MCUC1_CONFIG_SDK_KINETIS_1_3
  GPIO_DRV_SetPinOutput(LED_RED);
#endif
}

/*
** ===================================================================
**     Method      :  LEDpin3_NegVal (component SDK_BitIO)
**     Description :
**         Toggles/negates the pin value
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void LEDpin3_NegVal(void)
{
#if MCUC1_CONFIG_NXP_SDK_2_0_USED
  GPIO_TogglePinsOutput(LEDpin3_CONFIG_GPIO_NAME, 1<<LEDpin3_CONFIG_PIN_NUMBER);
#elif MCUC1_CONFIG_SDK_VERSION_USED == MCUC1_CONFIG_SDK_KINETIS_1_3
  GPIO_DRV_TogglePinOutput(LED_RED);
#endif
}

/*
** ===================================================================
**     Method      :  LEDpin3_GetVal (component SDK_BitIO)
**     Description :
**         Returns the pin value
**     Parameters  : None
**     Returns     :
**         ---             - Returns the value of the pin:
**                           FALSE/logical level '0' or TRUE/logical
**                           level '1'
** ===================================================================
*/
bool LEDpin3_GetVal(void)
{
#if MCUC1_CONFIG_NXP_SDK_2_0_USED
  return GPIO_ReadPinInput(LEDpin3_CONFIG_GPIO_NAME, LEDpin3_CONFIG_PIN_NUMBER)!=0;
#elif MCUC1_CONFIG_SDK_VERSION_USED == MCUC1_CONFIG_SDK_KINETIS_1_3
  return GPIO_DRV_ReadPinInput(LED_RED)!=0;
#else
  return FALSE;
#endif
}

/*
** ===================================================================
**     Method      :  LEDpin3_GetDir (component SDK_BitIO)
**     Description :
**         Return the direction of the pin (input/output)
**     Parameters  : None
**     Returns     :
**         ---             - FALSE if port is input, TRUE if port is
**                           output
** ===================================================================
*/
bool LEDpin3_GetDir(void)
{
  return LEDpin3_isOutput;
}

/*
** ===================================================================
**     Method      :  LEDpin3_SetDir (component SDK_BitIO)
**     Description :
**         Sets the direction of the pin (input or output)
**     Parameters  :
**         NAME            - DESCRIPTION
**         Dir             - FALSE: input, TRUE: output
**     Returns     : Nothing
** ===================================================================
*/
void LEDpin3_SetDir(bool Dir)
{
  if (Dir) {
    LEDpin3_SetOutput();
  } else {
    LEDpin3_SetInput();
  }
}

/*
** ===================================================================
**     Method      :  LEDpin3_SetInput (component SDK_BitIO)
**     Description :
**         Sets the pin as input
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void LEDpin3_SetInput(void)
{
#if MCUC1_CONFIG_NXP_SDK_2_0_USED
  GPIO_PinInit(LEDpin3_CONFIG_GPIO_NAME, LEDpin3_CONFIG_PIN_NUMBER, &LEDpin3_configInput);
#elif MCUC1_CONFIG_SDK_VERSION_USED == MCUC1_CONFIG_SDK_KINETIS_1_3
  GPIO_DRV_SetPinDir(LED_RED, kGpioDigitalInput);
#endif
  LEDpin3_isOutput = false;
}

/*
** ===================================================================
**     Method      :  LEDpin3_SetOutput (component SDK_BitIO)
**     Description :
**         Sets the pin as output
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void LEDpin3_SetOutput(void)
{
#if MCUC1_CONFIG_NXP_SDK_2_0_USED
  GPIO_PinInit(LEDpin3_CONFIG_GPIO_NAME, LEDpin3_CONFIG_PIN_NUMBER, &LEDpin3_configOutput);
#elif MCUC1_CONFIG_SDK_VERSION_USED == MCUC1_CONFIG_SDK_KINETIS_1_3
  GPIO_DRV_SetPinDir(LED_RED, kGpioDigitalOutput);
#endif
  LEDpin3_isOutput = true;
}

/*
** ===================================================================
**     Method      :  LEDpin3_PutVal (component SDK_BitIO)
**     Description :
**         Sets the pin value
**     Parameters  :
**         NAME            - DESCRIPTION
**         Val             - Value to set. FALSE/logical '0' or
**                           TRUE/logical '1'
**     Returns     : Nothing
** ===================================================================
*/
void LEDpin3_PutVal(bool Val)
{
#if MCUC1_CONFIG_NXP_SDK_2_0_USED
  if (Val) {
    GPIO_SetPinsOutput(LEDpin3_CONFIG_GPIO_NAME, 1<<LEDpin3_CONFIG_PIN_NUMBER);
  } else {
    GPIO_ClearPinsOutput(LEDpin3_CONFIG_GPIO_NAME, 1<<LEDpin3_CONFIG_PIN_NUMBER);
  }
#elif MCUC1_CONFIG_SDK_VERSION_USED == MCUC1_CONFIG_SDK_KINETIS_1_3
  GPIO_DRV_WritePinOutput(LED_RED, Val);
#endif
}

/*
** ===================================================================
**     Method      :  LEDpin3_Init (component SDK_BitIO)
**     Description :
**         Driver initialization method
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void LEDpin3_Init(void)
{
#if MCUC1_CONFIG_NXP_SDK_2_0_USED
  #if LEDpin3_CONFIG_DO_PIN_MUXING
  PORT_SetPinMux(LEDpin3_CONFIG_PORT_NAME, LEDpin3_CONFIG_PIN_NUMBER, kPORT_MuxAsGpio); /* mux as GPIO */
  #endif
#if LEDpin3_CONFIG_INIT_PIN_DIRECTION == LEDpin3_CONFIG_INIT_PIN_DIRECTION_INPUT
  LEDpin3_SetInput();
#elif LEDpin3_CONFIG_INIT_PIN_DIRECTION == LEDpin3_CONFIG_INIT_PIN_DIRECTION_OUTPUT
  LEDpin3_SetOutput();
#endif
#elif MCUC1_CONFIG_SDK_VERSION_USED == MCUC1_CONFIG_SDK_KINETIS_1_3
  /*! \todo Pin Muxing not implemented */
  GPIO_DRV_Init(LEDpin3_InputConfig, LEDpin3_OutputConfig);
#endif
}

/*
** ===================================================================
**     Method      :  LEDpin3_Deinit (component SDK_BitIO)
**     Description :
**         Driver de-initialization method
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void LEDpin3_Deinit(void)
{
  /* nothing needed */
}

/* END LEDpin3. */

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
