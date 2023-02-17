//
// Created by Maksim on 17.02.2023.
//

#include "bms_if.h"

//10ms
static void send1DBMsg(){
    /*
     * 751     86540.363 DT     01DB Rx 8  1E 00 B5 6B 36 00 00 6F
     * 757     86550.359 DT     01DB Rx 8  1E 00 B5 6B 36 00 01 EA
     * 768     86560.361 DT     01DB Rx 8  1E 00 B5 6B 36 00 02 E0
     * 774     86570.697 DT     01DB Rx 8  1E 00 B5 6B 36 00 03 65
     * */
    static int mux_1DB = 0;
    static char dataTx[8];
    dataTx[0] = 0x1E;
    dataTx[1] = 0x00;
    dataTx[2] = 0xB5;
    dataTx[3] = 0x6B;
    dataTx[4] = 0x36;
    dataTx[5] = 0x00;
    dataTx[6] = mux_1DB;
    switch (mux_1DB) {
        case 0:
            mux_1DB = 1;
            dataTx[7] = 0x6F;
            break;
        case 1:
            mux_1DB = 2;
            dataTx[7] = 0xEA;
            break;
        case 2:
            mux_1DB = 3;
            dataTx[7] = 0xE0;
            break;
        case 3:
            mux_1DB = 0;
            dataTx[7] = 0x65;
            break;
        default:
            break;
    }
    SendCanMsg(0x1DB,dataTx,8);
}
//10ms
static void send1DCMsg(){
    /*
     * 752     86540.589 DT     01DC Rx 8  6E 11 89 61 EC D4 C0 27
     * 758     86550.585 DT     01DC Rx 8  6E 11 89 61 E1 18 D5 5C
     * 769     86560.587 DT     01DC Rx 8  6E 11 89 61 E5 34 C6 2F
     * 775     86570.925 DT     01DC Rx 8  6E 11 89 61 E8 C0 C7 C5
     * */
    static int mux_1DC = 0;
    static char dataTx[8];
    dataTx[0] = 0x6E;
    dataTx[1] = 0x11;
    dataTx[2] = 0x89;
    dataTx[3] = 0x61;
    dataTx[4] = 0xEC;
    dataTx[5] = 0xD4;
    dataTx[6] = 0xC0;
    switch (mux_1DC) {
        case 0:
            mux_1DC = 1;
            dataTx[4] = 0xEC;
            dataTx[5] = 0xD4;
            dataTx[6] = 0xC0;
            dataTx[7] = 0x27;
            break;
        case 1:
            mux_1DC = 2;
            dataTx[4] = 0xE1;
            dataTx[5] = 0x18;
            dataTx[6] = 0xD5;
            dataTx[7] = 0x5C;
            break;
        case 2:
            mux_1DC = 3;
            dataTx[4] = 0xE5;
            dataTx[5] = 0x34;
            dataTx[6] = 0xC6;
            dataTx[7] = 0x2F;
            break;
        case 3:
            mux_1DC = 0;
            dataTx[4] = 0xE8;
            dataTx[5] = 0xC0;
            dataTx[6] = 0xC7;
            dataTx[7] = 0xC5;
            break;
        default:
            break;
    }
    SendCanMsg(0x1DC,dataTx,8);
}
//100ms
static void send55BMsg(){
    /*
     * 776     86571.157 DT     055B Rx 8  87 40 AA 00 4D 40 13 23
     * 850     86671.150 DT     055B Rx 8  87 80 AA 00 4D 40 10 4A
     * 924     86771.128 DT     055B Rx 8  87 80 AA 00 4D 40 11 CF
     * 998     86871.121 DT     055B Rx 8  87 80 55 00 4D 40 12 82
     * 1070     86971.108 DT     055B Rx 8  87 80 55 00 4D 40 13 07
     * 1143     87071.095 DT     055B Rx 8  87 80 55 00 4D 40 10 0D
     * 1217     87171.077 DT     055B Rx 8  87 80 55 00 4D 40 11 88
     * 1291     87271.070 DT     055B Rx 8  87 80 55 00 4D 40 12 82
     * */
    static int mux_55B = 0;
    static char dataTx[8];
    dataTx[0] = 0x87;
    dataTx[1] = 0x80;
    dataTx[2] = 0x55;
    dataTx[3] = 0x00;
    dataTx[4] = 0x4D;
    dataTx[5] = 0x40;
    dataTx[6] = 0x10;
    switch (mux_55B) {
        case 0:
            mux_55B = 1;
            dataTx[6] = 0x10;
            dataTx[7] = 0x0D;
            break;
        case 1:
            mux_55B = 2;
            dataTx[6] = 0x11;
            dataTx[7] = 0x88;
            break;
        case 2:
            mux_55B = 3;
            dataTx[6] = 0x12;
            dataTx[7] = 0x82;
            break;
        case 3:
            mux_55B = 0;
            dataTx[6] = 0x13;
            dataTx[7] = 0x07;
            break;
        default:
            break;
    }
    SendCanMsg(0x55B,dataTx,8);
}
//100ms
static void send5BCMsg(){
    /*
     * 777     86571.391 DT     05BC Rx 8  43 00 A0 78 C9 01 1F FF
     * 851     86671.386 DT     05BC Rx 8  43 00 A0 78 C9 01 7F FF
     * 925     86771.362 DT     05BC Rx 8  43 00 7C 78 C8 02 5F FF
     * 999     86871.355 DT     05BC Rx 8  43 00 7C 78 C8 02 BF FF
     * 1071     86971.343 DT     05BC Rx 8  43 00 7C 78 C8 03 1F FF
     * 1144     87071.332 DT     05BC Rx 8  43 00 7C 78 C8 00 00 1E
     * 1218     87171.315 DT     05BC Rx 8  43 00 7C 78 C8 00 BF FF
     * 1292     87271.304 DT     05BC Rx 8  43 00 A0 78 C9 01 1F FF
     * */
    static int mux_5BC = 0;
    static char dataTx[8];
    dataTx[0] = 0x43;
    dataTx[1] = 0x00;
    dataTx[2] = 0xA0;
    dataTx[3] = 0x78;
    dataTx[4] = 0xC9;
    dataTx[5] = 0x01;
    dataTx[6] = 0x1F;
    dataTx[7] = 0xFF;
    switch (mux_5BC) {
        case 0:
            mux_5BC = 1;
            dataTx[2] = 0xA0;
            dataTx[4] = 0xC9;
            dataTx[5] = 0x01;
            dataTx[6] = 0x7F;
            break;
        case 1:
            mux_5BC = 0;
            dataTx[2] = 0x7C;
            dataTx[4] = 0xC8;
            dataTx[5] = 0x02;
            dataTx[6] = 0x5F;
            break;
        default:
            break;
    }
    SendCanMsg(0x5BC,dataTx,8);
}
//500ms
static void send5C0Msg(){
    /*
     * 1229     87181.226 DT     05C0 Rx 8  40 94 94 01 C8 18 1F 00
     * 1594     87681.263 DT     05C0 Rx 8  80 92 92 01 C8 B0 1F 00
     * 1959     88181.201 DT     05C0 Rx 8  C0 92 92 01 C8 B0 1F 00
     * */
    static int mux_5C0 = 0;
    static char dataTx[8];
    dataTx[0] = 0x40;
    dataTx[1] = 0x94;
    dataTx[2] = 0x94;
    dataTx[3] = 0x01;
    dataTx[4] = 0xC8;
    dataTx[5] = 0x18;
    dataTx[6] = 0x1F;
    dataTx[7] = 0x00;
    switch (mux_5C0) {
        case 0:
            mux_5C0 = 1;
            dataTx[0] = 0x40;
            dataTx[1] = 0x94;
            dataTx[2] = 0x94;
            dataTx[5] = 0x18;
            break;
        case 1:
            mux_5C0 = 2;
            dataTx[0] = 0x80;
            dataTx[1] = 0x92;
            dataTx[2] = 0x92;
            dataTx[5] = 0xB0;
            break;
        case 2:
            mux_5C0 = 0;
            dataTx[0] = 0xC0;
            dataTx[1] = 0x92;
            dataTx[2] = 0x92;
            dataTx[5] = 0xB0;
            break;
        default:
            break;
    }
    SendCanMsg(0x5C0,dataTx,8);
}


void SendBMSDataProcess()
{
    static int tick_1DB = 3;
    static int tick_1DC = 9;
    static int tick_55B = 21;
    static int tick_5BC = 17;
    static int tick_5C0 = 111;

    if(tick_1DB >= 10)
    {
        send1DBMsg();
        tick_1DB = 0;
    }
    if(tick_1DC >= 10)
    {
        send1DCMsg();
        tick_1DC = 0;
    }
    if(tick_55B >= 100)
    {
        send55BMsg();
        tick_55B = 0;
    }
    if(tick_5BC >= 100)
    {
        send5BCMsg();
        tick_5BC = 0;
    }
    if(tick_5C0 >= 500)
    {
        send5C0Msg();
        tick_5C0 = 0;
    }

    tick_1DB++;
    tick_1DC++;
    tick_55B++;
    tick_5BC++;
    tick_5C0++;
}