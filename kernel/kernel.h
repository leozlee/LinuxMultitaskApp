/**
  ******************************************************************************
  * @file kernel.h 
  * @author leon.xie
  * @version v1.0.0
  * @date 2018-11-6 23:22:40
  * @brief This file contains all the functions prototypes for the BOARD 
  *  kernel 
  ******************************************************************************
  * @attention
  *
  * File For Yunin Software Team Only
  *
  * Copyright (C), 2017-2027, Yunin Software Team
  ******************************************************************************
  */ 

/* Define to prevent recursive inclusion -------------------------------------*/

#ifndef __KERNEL_H
#define __KERNEL_H

/* Includes ------------------------------------------------------------------*/

#include "configs.h" 
#include "type.h" 

#ifdef  __cplusplus
extern "C" {
#endif

/* Exported typedef ----------------------------------------------------------*/
/* Exported variables --------------------------------------------------------*/
/* Exported macro ------------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */
void kernel_init(void);
void kernel_exit(void);
void main_loop_start(void);

#ifdef  __cplusplus
}
#endif

#endif  /* __KERNEL_H */


