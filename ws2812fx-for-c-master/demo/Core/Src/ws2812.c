#include "ws2812.h"

// WS2812复位数据
static uint8_t WS2812_RET_Buf[WS2812_RET_COUNT]=
    {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
     0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
     0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
     0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
     0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
     0x00};

// WS2812发送数据缓存区(每位占用24个字节)
static uint8_t WS2812_Data_Buf[WS2812_LINK_COUNT * 3 * 8];

void WS2812_send(uint8_t *pixels, uint16_t numBytes)
{
    uint16_t pos;
    uint8_t pos_bit;
    uint8_t temp;
    
    // 发送WS2812复位
    HAL_SPI_Transmit_DMA(&WS2812_SPI, WS2812_RET_Buf, sizeof(WS2812_RET_Buf));
    
    // 发送WS2812数据
    for(pos=0;pos<numBytes;pos++)
    {
        temp = *pixels;
        for(pos_bit=0;pos_bit<8;pos_bit++)
        {
           if(temp & 0x80) WS2812_Data_Buf[pos * 8 + pos_bit] = WS2812_1_CODE;
           else WS2812_Data_Buf[pos * 8 + pos_bit] = WS2812_0_CODE;
           temp <<= 1;
        }
        pixels++;
    }
    HAL_SPI_Transmit_DMA(&WS2812_SPI, WS2812_Data_Buf, sizeof(WS2812_Data_Buf));
}


