//
// Created by Maksim on 17.02.2023.
//

#ifndef LEAF_VCU_BMS_EMULATOR_VCU_IF_H
#define LEAF_VCU_BMS_EMULATOR_VCU_IF_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>
#include "can_if.h"
/* Exported types ------------------------------------------------------------*/
/* Exported variables --------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
/* External variables --------------------------------------------------------*/
/* Exported macros -----------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */
/** @defgroup VCU_Exported_function
 *  @{
 */

/**
 * @brief  This function sends VCU emulation data.
 *
 * @note    It should be called every ms.
 *
 */
void SendVCMDataProcess();

/**
  * @}
 */
#ifdef __cplusplus
}
#endif
#endif //LEAF_VCU_BMS_EMULATOR_VCU_IF_H
