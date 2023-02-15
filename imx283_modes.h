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

#ifndef IMX283MODES_H_
#define IMX283MODES_H_

// clang-format off
// We want to preserve 1 register per line.

struct sensor_regs imx283_common_init[] = {
    {0x3000, 0x0A},

    {0x36C1, 0x02},
    {0x36C2, 0xF0},
    {0x36C3, 0x00},
    {0x36F7, 0x02},
    {0x36F8, 0xC0},

    {0x3003, 0x77},
    {0x36AA, 0x00},

    {0x320B, 0x00},
        //delay 1ms
    {0xFFFE, 0x01},

    
    //{0x3105, 0x00},
    {0x3000, 0x00},
        //delay 19ms
    {0xFFFE, 0x14},

    {0x3001, 0x10},
    {0x3105, 0x00},
    {0x3107, 0xA2},

};


// 12 mpix 10fps
struct sensor_regs imx283_4056x3040_regs[] = {
    {0x3004, 0x04}, //MDSEL1
    {0x3005, 0x03}, //MDSEL2
    {0x3006, 0x10}, //MDSEL3
    {0x3007, 0x00}, //MDSEL4

    {0x3009, 0x00}, //SVR[7:0]    *
    {0x300A, 0x00}, //SVR[15:8]   *
    {0x300B, 0x30}, // 1[5] + HTRIMMING_EN[4]=1 + MDVREV[0]=0

    {0x300F, 0x00}, //VWINPOS[7:0] = 0
    {0x3010, 0x00}, //VWINPOS[3:0] = 0

    {0x3011, 0x00}, //VWIDCUT[7:0] = 0
    {0x3012, 0x00}, //VWIDCUT[2:0] = 0
    {0x3013, 0x00}, //MDSEL7 = 0
    {0x3014, 0x00}, //MDSEL7 = 0
    {0x302F, 0x6E}, //Y_OUT_SIZE = 0E6E    1110 011 X   0 1110
    {0x3030, 0x0E},  

    {0x3031, 0x7E}, //WRITE_VSIZE = 0E7E
    {0x3032, 0x0E},

    {0x3033, 0x10}, //OB_SIZE_V = 10


    {0x3036, 0x84},  //HMAX = 900
    {0x3037, 0x03},

    {0x3038, 0xA0},  //VMAX = 4000
    {0x3039, 0x0F}, 
    {0x303A, 0x00}, 
    


    {0x303B, 0x10}, //SHR [7:0]
    {0x303C, 0x00}, //SHR [15:8]

    {0x3058, 0x78}, //HTRIMMING_START = 0078
    {0x3059, 0x00}, 


    {0x305A, 0xF0}, // HTRIMMING_END = 15F0
    {0x305B, 0x15},



};
// clang-format on

struct mode_def imx283_modes[] = {
	{
	    .regs = imx283_4056x3040_regs,
	    .num_regs = NUM_ELEMENTS(imx283_4056x3040_regs),
	    .width = 5592,
	    .height = 3694,
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

struct sensor_regs imx283_stop[] = {
	// to power down */
	{ 0x0100, 0x00 }, // disable streaming
};

struct sensor_def imx283 = {
	.name = "imx283",
	.common_init = imx283_common_init,
	.num_common_init = NUM_ELEMENTS(imx283_common_init),
	.modes = imx283_modes,
	.num_modes = NUM_ELEMENTS(imx283_modes),
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
