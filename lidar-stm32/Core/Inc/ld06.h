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
     float distance; 
     uint8_t data[100];
     uint8_t confidence;
     float endAngle;
     uint8_t endAngleL;
     uint8_t endAngleM;
     float timestamp;
     uint8_t timestampL;
     uint8_t timestampM;
     uint8_t * crcCheck;

}LD06;

void readLidarData(UART_HandleTypeDef *huart,LD06 *lidar,uint8_t * buffer);