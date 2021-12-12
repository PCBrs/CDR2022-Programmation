#include "stdint.h"
#include "stdbool.h"

#include "usart.h"
#include "string.h"
#include "dma.h"

typedef struct LD06 {
    
     uint8_t state;
     uint8_t header;
     int32_t dataLength;
     float radarSpeed;
     uint8_t radarSpeedL;
     uint8_t radarSpeedH;
     float startAngle;
     uint8_t startAngleL;
     uint8_t startAngleH;
     uint8_t data[8];     //data bytes(distance and confidence data in raw format)
     int32_t endAngle;
     int32_t timestamp;
     uint8_t crcCheck;

}LD06;