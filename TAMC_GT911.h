#ifndef _TAMC_GT911_H_
#define _TAMC_GT911_H_

#include <Arduino.h>
#include <Wire.h>

#define GT911_MAX_TOUCHES 5

typedef struct {
  uint16_t x;
  uint16_t y;
} TP_Point;

class TAMC_GT911 {
  public:
    TAMC_GT911(uint8_t sda, uint8_t scl, int irq, int rst, uint16_t width, uint16_t height);
    bool begin();
    void read();
    bool isTouched();
    uint8_t getPointNum();
    TP_Point getPoint(uint8_t id);
  private:
    TP_Point _points[GT911_MAX_TOUCHES];
    uint8_t _sda, _scl;
    int _irq, _rst;
    uint16_t _width, _height;
    uint8_t _pointCount;
};

#endif