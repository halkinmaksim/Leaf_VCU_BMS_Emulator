//
// Created by Maksim on 17.02.2023.
//

#include "can_if.h"

static CAN_HandleTypeDef *phcan;


void InitCAN_if()
{
    CAN_FilterTypeDef canFilterConfig;
    canFilterConfig.FilterBank = 0;
    canFilterConfig.FilterMode = CAN_FILTERMODE_IDMASK;
    canFilterConfig.FilterScale = CAN_FILTERSCALE_32BIT;
    canFilterConfig.FilterIdHigh = 0;
    canFilterConfig.FilterIdLow = 0;
    canFilterConfig.FilterMaskIdHigh = 0;
    canFilterConfig.FilterMaskIdLow = 0;
    canFilterConfig.FilterFIFOAssignment = CAN_RX_FIFO0;
    canFilterConfig.FilterActivation = ENABLE;
    canFilterConfig.SlaveStartFilterBank = 0;
    HAL_CAN_ConfigFilter(&hcan1, &canFilterConfig);
    canFilterConfig.FilterBank = 1;
    canFilterConfig.FilterFIFOAssignment = CAN_RX_FIFO1;
    canFilterConfig.FilterActivation = ENABLE;
    canFilterConfig.SlaveStartFilterBank = 1;
    HAL_CAN_ConfigFilter(&hcan2, &canFilterConfig);
    HAL_StatusTypeDef can_status = HAL_OK;
    can_status = HAL_CAN_Start(&hcan1);
    if (can_status != HAL_OK)
    {
        //printf("HAL_CAN_Start(&hcan1) Error\n");
    }
    can_status = HAL_CAN_Start(&hcan2);
    if (can_status != HAL_OK)
    {
        //printf("HAL_CAN_Start(&hcan2) Error\n");
    }
    phcan = &hcan1;
    can_status = HAL_CAN_ActivateNotification(&hcan1, CAN_IT_RX_FIFO0_MSG_PENDING|CAN_IT_TX_MAILBOX_EMPTY);    //CAN_IT_RX_FIFO0_MSG_PENDING
    can_status = HAL_CAN_ActivateNotification(&hcan2, CAN_IT_RX_FIFO0_MSG_PENDING|CAN_IT_TX_MAILBOX_EMPTY);
    can_status = HAL_CAN_ActivateNotification(&hcan1, CAN_IT_RX_FIFO1_MSG_PENDING);    //CAN_IT_RX_FIFO0_MSG_PENDING
    can_status = HAL_CAN_ActivateNotification(&hcan2, CAN_IT_RX_FIFO1_MSG_PENDING);
}

HAL_StatusTypeDef SendCanMsg(uint32_t StdId, uint8_t aData[], uint32_t size)
{
    static CAN_TxHeaderTypeDef	TxHeader;
    uint32_t  mailBox_canTx;
    TxHeader.ExtId = 0;
    TxHeader.DLC = size;
    TxHeader.IDE = 0;
    TxHeader.RTR = 0;
    TxHeader.StdId = StdId;

    return HAL_CAN_AddTxMessage(phcan, &TxHeader, aData, &mailBox_canTx);
}


void HAL_CAN_RxFifo0MsgPendingCallback(CAN_HandleTypeDef *hcan)
{
    // read data
    uint8_t		RxData[8];
    HAL_StatusTypeDef hal_status;
    CAN_RxHeaderTypeDef RxHeader;
    hal_status = HAL_CAN_GetRxMessage(hcan, CAN_RX_FIFO0, &RxHeader, RxData);
}
//void HAL_CAN_RxFifo0FullCallback(CAN_HandleTypeDef *hcan);
void HAL_CAN_RxFifo1MsgPendingCallback(CAN_HandleTypeDef *hcan)
{
    // read data
    uint8_t		RxData[8];
    HAL_StatusTypeDef hal_status;
    CAN_RxHeaderTypeDef RxHeader;
    hal_status = HAL_CAN_GetRxMessage(hcan, CAN_RX_FIFO1, &RxHeader, RxData);
}