//
// Created by Maksim on 17.02.2023.
//

#include "vcu_if.h"

static bool _vcm_data_enable = true;


static void send11AMsg(){
    static int mux_11A = 0;
    static char dataTx[8];
    dataTx[0] = 0x01;
    dataTx[1] = 0x80;
    dataTx[2] = 0x00;
    dataTx[5] = 0x00;
    dataTx[6] = mux_11A;
    switch (mux_11A) {
        case 0:
            mux_11A = 1;
            dataTx[3] = 0xAA;
            dataTx[4] = 0xC0;
            dataTx[7] = 0x60;
            break;
        case 1:
            mux_11A = 2;
            dataTx[3] = 0x55;
            dataTx[4] = 0x00;
            dataTx[7] = 0x76;
            break;
        case 2:
            mux_11A = 3;
            dataTx[3] = 0x55;
            dataTx[4] = 0x40;
            dataTx[7] = 0xBB;
            break;
        case 3:
            mux_11A = 0;
            dataTx[3] = 0xAA;
            dataTx[4] = 0x80;
            dataTx[7] = 0xAD;
            break;
        default:
            break;
    }
    SendCanMsg(0x11a,dataTx,8);
}

static void send1F2Msg(){
    static int mux_1F2 = 0;
    static char dataTx[8];
    dataTx[0] = 0x30;
    dataTx[1] = 0x95;
    dataTx[2] = 0x20;
    dataTx[3] = 0xAC;
    dataTx[4] = 0x00;
    dataTx[5] = 0x3C;
    switch (mux_1F2) {
        case 0:
            mux_1F2 = 1;

            dataTx[6] = 0x00;
            dataTx[7] = 0x82;
            break;
        case 1:
            mux_1F2 = 2;
            dataTx[6] = 0x01;
            dataTx[7] = 0x83;
            break;
        case 2:
            mux_1F2 = 3;
            dataTx[6] = 0x02;
            dataTx[7] = 0x84;
            break;
        case 3:
            mux_1F2 = 0;
            dataTx[6] = 0x03;
            dataTx[7] = 0x85;
            break;
        default:
            break;
    }
    SendCanMsg(0x1F2,dataTx,8);
}

static void send50BMsg(){

    static char dataTx[7];
    dataTx[0] = 0x00;
    dataTx[1] = 0x00;
    dataTx[2] = 0x00;
    dataTx[3] = 0xC0;
    dataTx[4] = 0x00;
    dataTx[5] = 0x00;
    dataTx[6] = 0x00;
    SendCanMsg(0x50B,dataTx,7);
}

static void send1D4Msg(){
    static int mux_1D4 = 0;
    static char dataTx[8];
    dataTx[0] = 0x6E;
    dataTx[1] = 0x6E;
    dataTx[2] = 0x00;
    dataTx[3] = 0x04;
    dataTx[5] = 0x46;
    dataTx[6] = 0xE0;
    switch (mux_1D4) {
        case 0:
            mux_1D4 = 1;

            dataTx[4] = 0x07;
            dataTx[7] = 0x12;
            break;
        case 1:
            mux_1D4 = 2;
            dataTx[4] = 0x47;
            dataTx[7] = 0xD5;
            break;
        case 2:
            mux_1D4 = 3;
            dataTx[4] = 0x87;
            dataTx[7] = 0x19;
            break;
        case 3:
            mux_1D4 = 0;
            dataTx[4] = 0xC7;
            dataTx[7] = 0xDE;
            break;
        default:
            break;
    }
    SendCanMsg(0x1D4,dataTx,8);
}


void SendVCMDataProcess()
{
    if(!_vcm_data_enable)
        return;
    static int tick_11A = 0;
    static int tick_1F2 = 2;
    static int tick_50B = 4;
    static int tick_1D4 = 6;

    if(tick_11A >= 10)
    {
        send11AMsg();
        tick_11A = 0;
    }
    if(tick_1F2 >= 10)
    {
        send1F2Msg();
        tick_1F2 = 0;
    }
    if(tick_50B >= 10)
    {
        send50BMsg();
        tick_50B = 0;
    }
    if(tick_1D4 >= 10)
    {
        send1D4Msg();
        tick_1D4 = 0;
    }

    tick_11A++;
    tick_1F2++;
    tick_50B++;
    tick_1D4++;
}