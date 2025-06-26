#include "TAMC_GT911.h"

TAMC_GT911::TAMC_GT911(uint8_t sda, uint8_t scl, int irq, int rst, uint16_t width, uint16_t height) :
  _sda(sda), _scl(scl), _irq(irq), _rst(rst), _width(width), _height(height), _pointCount(0) {}

bool TAMC_GT911::begin() {
  Wire.begin(_sda, _scl);
  return true; // Simulated success
}

void TAMC_GT911::read() {
  _pointCount = 1;
  _points[0].x = 400;
  _points[0].y = 240;
}

bool TAMC_GT911::isTouched() {
  return _pointCount > 0;
}

uint8_t TAMC_GT911::getPointNum() {
  return _pointCount;
}

TP_Point TAMC_GT911::getPoint(uint8_t id) {
  return _points[id];
}
