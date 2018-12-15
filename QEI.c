/*
 * QEI.c
 *
 *  Created on: Dec 15, 2018
 *      Author: Abdelaziz
 */

#include"QEI.h"

/**
 *  @file  <QEI.c>
 *  @brief <Implements the functions defined in the header file.>
 *
 *  @author<Eng/Abdelaziz Moustafa Abdelazem>
 *  @date  <15-Dec-18>
 *
 */

void QEI_Init(uint32 QEI_Base, QEI_CLOCKS Clock, GPIO_CLOCKS PORT_CLOCK)
{
      REG32_ACCESS((QEI_Base),(QEI_CLOCK_offset)) |= (Clock);
      GPIO_CLOCK_ENABLE(PORT_CLOCK);
}

void GPIO_AFSEL_FOR_QEI(uint32 PORT_BASE, uint8 PhA_PIN_NO, uint8 PhB_PIN_NO)
{
    /* Configures the Pins as inputs*/
    GPIO_DIR_SELECT(PORT_BASE,PhA_PIN_NO,INPUT);
    GPIO_DIR_SELECT(PORT_BASE,PhA_PIN_NO,INPUT);
    /* Enable The Digital function*/
    GPIO_DIGITAL_ENABLE(PORT_BASE, PhA_PIN_NO);
    GPIO_DIGITAL_ENABLE(PORT_BASE, PhA_PIN_NO);
    /* Configure the pins to work as alternative function*/
    GPIO_ALFUN_ENABLE(PORT_BASE, PhA_PIN_NO);
    GPIO_ALFUN_ENABLE(PORT_BASE, PhA_PIN_NO);
    /* Selects the QEI alternative function for the PhA, PhB  GPIO pins.*/
    GPIO_ALF_CONTROL(PORT_BASE,GPIO_PORT_CTL_offset,PhA_PIN_NO,QEI_Digital_Code);
    GPIO_ALF_CONTROL(PORT_BASE,GPIO_PORT_CTL_offset,PhB_PIN_NO,QEI_Digital_Code);
}

void QEI_Configuration(uint32 QEI_Base, QEI_SIG_MODE Signal_Mode, Signal_CAP_Mode Capture_Mode, Reset_State Reset_State,
                           SWAP_State Swap_State,Signal_invert_State INV_state, uint32 MAX_Postion)
{
    /*Disable the Desired QEI Module before configuration.*/
    CLEAR_BIT(QEI_Base, QEI_CTL_offset, QEI_ENABLE_BIT);

    REG32_ACCESS((QEI_Base),(QEI_CTL_offset)) |= Signal_Mode |Capture_Mode |Reset_State |Swap_State |INV_state;
    REG32_ACCESS((QEI_Base),(QEI_MAX_POS_offset)) |= MAX_Postion-1;
}

void QEI_VELOCITY_Configuration(uint32 QEI_Base, Velocity_PreDevide Pre_Devision, uint32 Vel_LOAD_Value)
{
    REG32_ACCESS((QEI_Base),(QEI_CTL_offset)) |= Pre_Devision;
    REG32_ACCESS((QEI_Base),(QEI_TIMER_LOAD_offset)) |= Vel_LOAD_Value-1;

    /*ENABLE the velocity Capture for the QEI.*/
    CLEAR_BIT(QEI_Base, QEI_CTL_offset, QEI_VEL_ENABLE_BIT);
}

void QEI_INPUT_Filter_CONFIGURE(uint32 QEI_Base, Input_Filter_State Filter_Select)
{
    REG32_ACCESS((QEI_Base),(QEI_CTL_offset)) |= Filter_Select;
}

void QEI_Interrupts_Configure(uint32 QEI_Base, Interrupt_State Int_state)
{
    REG32_ACCESS((QEI_Base),(QEI_INT_ENABLE_offset)) |= Int_state;
}

uint32 QEI_GET_POSITION(uint32 QEI_Base)
{

    return REG32_ACCESS((QEI_Base),(QEI_POSITION_offset));
}

uint32 QEI_GET_VELOCITY(uint32 QEI_Base)
{

    return REG32_ACCESS((QEI_Base),(QEI_VELOCITY_offset));
}

sint32 QEI_GET_DIRECTION(uint32 QEI_Base)
{
    if(IS_BIT_SET(QEI_Base, QEI_STATUS_offset, QEI_ROTATION_DIR_BIT))
    {
        return -1;
    }
    else
    {
        return 1;
    }
}
