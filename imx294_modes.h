/*
Copyright (c) 2020, Raspberry Pi Foundation
Copyright (c) 2020, Dave Stevenson
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:
    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above copyright
      notice, this list of conditions and the following disclaimer in the
      documentation and/or other materials provided with the distribution.
    * Neither the name of the copyright holder nor the
      names of its contributors may be used to endorse or promote products
      derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#ifndef IMX294MODES_H_
#define IMX294MODES_H_

// clang-format off
// We want to preserve 1 register per line.

struct sensor_regs imx294_common_init[] =
{

    {0x3033,0x30},
    {0x303C,0x01},

    {0x31E8,0x20}, //PLRD1
    {0x31E9,0x01},

    {0x3122,0x02}, //PLRD2
    {0x3129,0x90}, //PLRD3
    {0x312A,0x02}, //PLRD4

    {0x311F,0x00}, //PLRD10
    {0x3123,0x00}, //PLRD11
    {0x3124,0x00}, //PLRD12
    {0x3125,0x01}, //PLRD13
    {0x3127,0x02}, //PLRD14
    {0x312D,0x02}, //PLRD15

    {0x3000,0x12}, //STANDBY = 0 STBLOGIC register = 1h, STBMIPI register = 0h, STBDV register = 1h
    {0x310B,0x00}, //PLL release

    {0x3047,0x01}, //PLSTMG11
    {0x304E,0x0B}, //PLSTMG12
    {0x304F,0x24}, //PLSTMG13
    {0x3062,0x25}, //PLSTMG14
    {0x3064,0x78}, //PLSTMG15
    {0x3065,0x33}, //PLSTMG16
    {0x3067,0x71}, //PLSTMG17
    {0x3088,0x75}, //PLSTMG18
    {0x308A,0x09}, //PLSTMG19
    {0x308B,0x01}, //PLSTMG19
    {0x308C,0x61}, //PLSTMG20
    {0x3146,0x00}, //PLSTMG10
    {0x3234,0x32}, //PLSTMG21
    {0x3235,0x00}, //PLSTMG21
    {0x3248,0xBC}, //PLSTMG22
    {0x3249,0x00}, //PLSTMG22
    {0x3250,0xBC}, //PLSTMG23
    {0x3251,0x00}, //PLSTMG23
    {0x3258,0xBC}, //PLSTMG24
    {0x3259,0x00}, //PLSTMG24
    {0x3260,0xBC}, //PLSTMG25
    {0x3261,0x00}, //PLSTMG25
    {0x3274,0x13}, //PLSTMG26
    {0x3275,0x00}, //PLSTMG26
    {0x3276,0x1F}, //PLSTMG27
    {0x3277,0x00}, //PLSTMG27
    {0x3278,0x30}, //PLSTMG28
    {0x3279,0x00}, //PLSTMG28
    {0x327C,0x13}, //PLSTMG29
    {0x327D,0x00}, //PLSTMG29
    {0x327E,0x1F}, //PLSTMG30
    {0x327F,0x00}, //PLSTMG30
    {0x3280,0x30}, //PLSTMG31
    {0x3281,0x00}, //PLSTMG31
    {0x3284,0x13}, //PLSTMG32
    {0x3285,0x00}, //PLSTMG32
    {0x3286,0x1F}, //PLSTMG33
    {0x3287,0x00}, //PLSTMG33
    {0x3288,0x30}, //PLSTMG34
    {0x3289,0x00}, //PLSTMG34
    {0x328C,0x13}, //PLSTMG35
    {0x328D,0x00}, //PLSTMG35
    {0x328E,0x1F}, //PLSTMG36
    {0x328F,0x00}, //PLSTMG36
    {0x3290,0x30}, //PLSTMG37
    {0x3291,0x00}, //PLSTMG37
    {0x32AE,0x00}, //PLSTMG38
    {0x32AF,0x00}, //PLSTMG39
    {0x32CA,0x5A}, //PLSTMG40
    {0x32CB,0x00}, //PLSTMG40
    {0x332F,0x00}, //PLSTMG41
    {0x334C,0x01}, //PLSTMG09
    {0x335A,0x79}, //PLSTMG43
    {0x335B,0x00}, //PLSTMG43
    {0x335E,0x56}, //PLSTMG44
    {0x335F,0x00}, //PLSTMG44
    {0x3360,0x6A}, //PLSTMG45
    {0x3361,0x00}, //PLSTMG45
    {0x336A,0x56}, //PLSTMG46
    {0x336B,0x00}, //PLSTMG46
    {0x33D6,0x79}, //PLSTMG47
    {0x33D7,0x00}, //PLSTMG47
    {0x340C,0x6E}, //PLSTMG48
    {0x340D,0x00}, //PLSTMG48
    {0x3448,0x7E}, //PLSTMG49
    {0x3449,0x00}, //PLSTMG49
    {0x348E,0x6F}, //PLSTMG50
    {0x348F,0x00}, //PLSTMG50
    {0x3492,0x11}, //PLSTMG51
    {0x34C4,0x5A}, //PLSTMG52
    {0x34C5,0x00}, //PLSTMG52
    {0x3506,0x56}, //PLSTMG53
    {0x3507,0x00}, //PLSTMG53
    {0x350C,0x56}, //PLSTMG54
    {0x350D,0x00}, //PLSTMG54
    {0x350E,0x58}, //PLSTMG55
    {0x350F,0x00}, //PLSTMG55
    {0x3549,0x04}, //PLSTMG56
    {0x355D,0x03}, //PLSTMG57
    {0x355E,0x03}, //PLSTMG58
    {0x3574,0x56}, //PLSTMG59
    {0x3575,0x00}, //PLSTMG59
    {0x3587,0x01}, //PLSTMG60
    {0x35D0,0x5E}, //PLSTMG61
    {0x35D1,0x00}, //PLSTMG61
    {0x35D4,0x63}, //PLSTMG62
    {0x35D5,0x00}, //PLSTMG62
    {0x366A,0x1A}, //PLSTMG63
    {0x366B,0x16}, //PLSTMG64
    {0x366C,0x10}, //PLSTMG65
    {0x366D,0x09}, //PLSTMG66
    {0x366E,0x00}, //PLSTMG67
    {0x366F,0x00}, //PLSTMG68
    {0x3670,0x00}, //PLSTMG69
    {0x3671,0x00}, //PLSTMG70
    {0x3676,0x83}, //PLSTMG73
    {0x3677,0x03}, //PLSTMG73
    {0x3678,0x00}, //PLSTMG74
    {0x3679,0x04}, //PLSTMG74
    {0x367A,0x2C}, //PLSTMG75
    {0x367B,0x05}, //PLSTMG75
    {0x367C,0x00}, //PLSTMG76
    {0x367D,0x06}, //PLSTMG76
    {0x367E,0x00}, //PLSTMG77
    {0x367F,0x07}, //PLSTMG77
    {0x3680,0x4B}, //PLSTMG78
    {0x3681,0x07}, //PLSTMG78
    {0x3690,0x27}, //PLSTMG79
    {0x3691,0x00}, //PLSTMG79
    {0x3692,0x65}, //PLSTMG80
    {0x3693,0x00}, //PLSTMG80
    {0x3694,0x4F}, //PLSTMG81
    {0x3695,0x00}, //PLSTMG81
    {0x3696,0xA1}, //PLSTMG82
    {0x3697,0x00}, //PLSTMG82
    {0x382B,0x68}, //PLSTMG83
    {0x3C00,0x01}, //PLSTMG84
    {0x3C01,0x01}, //PLSTMG85
    {0x3686,0x00}, //PLSTMG101
    {0x3687,0x00}, //PLSTMG101
    {0x36BE,0x01}, //PLSTMG102
    {0x36BF,0x00}, //PLSTMG102
    {0x36C0,0x01}, //PLSTMG103
    {0x36C1,0x00}, //PLSTMG103
    {0x36C2,0x01}, //PLSTMG104
    {0x36C3,0x00}, //PLSTMG104
    {0x36C4,0x01}, //PLSTMG105
    {0x36C5,0x01}, //PLSTMG106
    {0x36C6,0x01}, //PLSTMG107


    {0x3134,0xAF}, //tclkpost
    {0x3135,0x00},
    {0x3136,0xC7}, //thszero
    {0x3137,0x00},
    {0x3138,0x7F}, //thsprepare
    {0x3139,0x00},
    {0x313A,0x6F}, //tclktrail
    {0x313B,0x00},
    {0x313C,0x6F}, //thstrail
    {0x313D,0x00},
    {0x313E,0xCF}, //tclkzero
    {0x313F,0x01},
    {0x3140,0x77}, //tclkprepare
    {0x3141,0x00},
    {0x3142,0x5F}, //tlpx
    {0x3143,0x00},

    {0x3004,0x1A}, //MDSEL1
    {0x3005,0x06}, //MDSEL2
    {0x3006,0x00}, //MDSEL3
    {0x3007,0xA0}, //MDSEL4
    {0x3019,0x00}, //MDVREV
    {0x3030,0x77}, //MDSEL5
    {0x3034,0x00}, //HOPBOUT_EN
    {0x3035,0x01}, //HTRIMMING_EN
    {0x3036,0x30}, //HTRIMMING_START
    {0x3037,0x00}, //HTRIMMING_START
    {0x3038,0x60}, //HTRIMMING_END
    {0x3039,0x10}, //HTRIMMING_END
    {0x3068,0x1A}, //MDSEL15
    {0x3069,0x00}, //MDSEL15
    {0x3080,0x00}, //MDSEL6
    {0x3081,0x01}, //MDSEL7
    {0x30A8,0x02}, //MDSEL8
    {0x30E2,0x00}, //VCUTMODE
    {0x312F,0x08}, //OPB_SIZE_V
    {0x3130,0x88}, //WRITE_VSIZE
    {0x3131,0x08}, //WRITE_VSIZE
    {0x3132,0x80}, //OUT_SIZE
    {0x3133,0x08}, //Y_OUT_SIZE
    {0x357F,0x0C}, //MDSEL11
    {0x3580,0x0A}, //MDSEL12
    {0x3581,0x08}, //MDSEL13
    {0x3583,0x72}, //MDSEL14
    {0x3600,0x90}, //MDSEL16
    {0x3601,0x00}, //MDSEL16
    {0x3846,0x00}, //MDSEL9
    {0x3847,0x00}, //MDSEL9
    {0x384A,0x00}, //MDSEL10
    {0x384B,0x00}, //MDSEL10



    //SVR = 0
    {0x300E,0x00},
    {0x300F,0x00},

    //SHR = 100
    {0x302C,0x10},
    {0x302D,0x00},

    //VMAX = 5000
    {0x30A9,0x88},
    {0x30AA,0x13},
    {0x30AB,0x00},

    //HMAX = 1200
    {0x30AC,0xB0},
    {0x30AD,0x04},
    //HCOUNT1 Set the same value as HMAX
    {0x3084,0xB0},
    {0x3085,0x04},
    //HCOUNT2 Set the same value as HMAX
    {0x3086,0xB0},
    {0x3087,0x04},

    {0x332C,0x00}, //PSSLVS1 = VBLK = VMAX ¡Á (SVR value + 1) - minimum VMAX setting = VMAX - minimum VMAX
    {0x332D,0x00}, //
    {0x334A,0x00}, //PSSLVS2 = VBLK
    {0x334B,0x00}, //
    {0x35B6,0x00}, //PSSLVS3 = VBLK
    {0x35B7,0x00}, //
    {0x35B8,0x00}, //PSSLVS4 = VBLK - 5
    {0x35B9,0x00}, //
    {0x36BC,0x00}, //PSSLVS0 = VBLK
    {0x36BD,0x00}, //

    //delay 10ms
    {0xFFFE,0x0A},

    {0x3000,0x02}, //(STANDBY register = 0h, STBLOGIC register = 1h, STBMIPI register = 0h, STBDV register = 0h
    {0x35E5,0x92},
    {0x35E5,0x9A},
    {0x3000,0x00}, //(STANDBY register = 0h, STBLOGIC register = 0h, STBMIPI register = 0h, STBDV register = 0h


    //delay 10ms
    {0xFFFE,0x0A},

    {0x3033,0x20},
    {0x3017,0xA8},
};


/* 3704 x 2778 */
struct sensor_regs imx294_3704x2778_regs[] =
{
    {0x3004,0x00}, //MDSEL1
    {0x3005,0x06}, //MDSEL2
    {0x3006,0x02}, //MDSEL3
    {0x3007,0xA0}, //MDSEL4
    {0x3019,0x00}, //MDVREV
    {0x3030,0x77}, //MDSEL5
    {0x3034,0x00}, //HOPBOUT_EN
    {0x3035,0x01}, //HTRIMMING_EN
    {0x3036,0x30}, //HTRIMMING_START
    {0x3037,0x00}, //HTRIMMING_START
    {0x3038,0x00}, //HTRIMMING_END
    {0x3039,0x0F}, //HTRIMMING_END
    {0x3068,0x1A}, //MDSEL15
    {0x3069,0x00}, //MDSEL15
    {0x3080,0x00}, //MDSEL6
    {0x3081,0x01}, //MDSEL7
    {0x30A8,0x02}, //MDSEL8
    {0x30E2,0x00}, //VCUTMODE
    {0x312F,0x10}, //OPB_SIZE_V
    {0x3130,0x18}, //WRITE_VSIZE
    {0x3131,0x0B}, //WRITE_VSIZE
    {0x3132,0x08}, //OUT_SIZE
    {0x3133,0x0B}, //Y_OUT_SIZE
    {0x357F,0x0C}, //MDSEL11
    {0x3580,0x0A}, //MDSEL12
    {0x3581,0x08}, //MDSEL13
    {0x3583,0x72}, //MDSEL14
    {0x3600,0x90}, //MDSEL16
    {0x3601,0x00}, //MDSEL16
    {0x3846,0x00}, //MDSEL9
    {0x3847,0x00}, //MDSEL9
    {0x384A,0x00}, //MDSEL10
    {0x384B,0x00}, //MDSEL10
};
// clang-format on

struct mode_def imx294_modes[] =
{
    {
        .regs = imx294_3704x2778_regs,
        .num_regs = NUM_ELEMENTS(imx294_3704x2778_regs),
        .width = 3792,
        .height = 3792,
        .encoding = 0,
        .order = BAYER_ORDER_RGGB,
        .native_bit_depth = 12,
        .image_id = 0x2C,
        .data_lanes = 4,
        .min_vts = 0xFFFF,
        .line_time_ns = 0xFFFF,
        .timing = { 0, 0, 0, 0, 0 },
        .term = { 0, 0 },
        .black_level = 256,
    },
};

struct sensor_regs imx294_stop[] =
{
    // to power down */
    { 0x0100, 0x00 }, // disable streaming
};

struct sensor_def imx294 =
{
    .name = "imx294",
    .common_init = imx294_common_init,
    .num_common_init = NUM_ELEMENTS(imx294_common_init),
    .modes = imx294_modes,
    .num_modes = NUM_ELEMENTS(imx294_modes),
    .stop = NULL,
    .num_stop_regs = 0,

    .i2c_addr = 0x1A,
    .i2c_addressing = 2,
    .i2c_ident_length = 2,
    .i2c_ident_reg = 0x3009,
    .i2c_ident_value = 0xFFFF, // Bytes reversed

    .vflip_reg = 0x300B,
    .vflip_reg_bit = 1,

    .exposure_reg = 0x3009,
    .exposure_reg_num_bits = 16,

    .vts_reg = 0x0340,
    .vts_reg_num_bits = 0,

    .gain_reg = 0x3044,
    .gain_reg_num_bits = 2,
};

#endif
