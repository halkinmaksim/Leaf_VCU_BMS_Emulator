//
// Created by Maksim on 17.02.2023.
//

#ifndef LEAF_VCU_BMS_EMULATOR_CAN_IF_H
#define LEAF_VCU_BMS_EMULATOR_CAN_IF_H
#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>
#include "can.h"
/* Exported types ------------------------------------------------------------*/
/* Exported variables --------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
/* External variables --------------------------------------------------------*/
/* Exported macros -----------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */
/** @defgroup CAN_Exported_function
 *  @{
 */

/**
 * @brief  Init CAN bus interface
 *
 * @note    It should be called from main func
 *
 */

void InitCAN_if();
HAL_StatusTypeDef SendCanMsg(uint32_t StdId, uint8_t aData[], uint32_t size);

/**
  * @}
 */
#ifdef __cplusplus
}
#endif
#endif //LEAF_VCU_BMS_EMULATOR_CAN_IF_H
