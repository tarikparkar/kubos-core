/***************************************************************************
  This is a library for the BME280 humidity, temperature & pressure sensor

  Designed specifically to work with the Adafruit BME280 Breakout
  ----> http://www.adafruit.com/products/2650

  These sensors use I2C or SPI to communicate, 2 or 4 pins are required
  to interface.

  Adafruit invests time and resources providing this open source code,
  please support Adafruit andopen-source hardware by purchasing products
  from Adafruit!

  Written by Limor Fried & Kevin Townsend for Adafruit Industries.
  BSD license, all text above must be included in any redistribution

  Modified by KubOS Corporation 2016 for integration into Kubos Core
 ***************************************************************************/
 /**
  * @defgroup BME280
  * @addgroup BME280
  * @{
  */
 /**
  * @brief BME280 Temperature, Humidty and Pressure Sensor
  */

#ifdef YOTTA_CFG_SENSORS_BME280

#ifndef BME280_H
#define BME280_H

#include <stdint.h>
#include "kubos-hal/spi.h"
#include "kubos-core/modules/sensors/sensors.h"

/**
 * register map for BME280 sensor
 */
 enum
 {
   BME280_REGISTER_DIG_T1              = 0x88,
   BME280_REGISTER_DIG_T2              = 0x8A,
   BME280_REGISTER_DIG_T3              = 0x8C,

   BME280_REGISTER_DIG_P1              = 0x8E,
   BME280_REGISTER_DIG_P2              = 0x90,
   BME280_REGISTER_DIG_P3              = 0x92,
   BME280_REGISTER_DIG_P4              = 0x94,
   BME280_REGISTER_DIG_P5              = 0x96,
   BME280_REGISTER_DIG_P6              = 0x98,
   BME280_REGISTER_DIG_P7              = 0x9A,
   BME280_REGISTER_DIG_P8              = 0x9C,
   BME280_REGISTER_DIG_P9              = 0x9E,

   BME280_REGISTER_DIG_H1              = 0xA1,
   BME280_REGISTER_DIG_H2              = 0xE1,
   BME280_REGISTER_DIG_H3              = 0xE3,
   BME280_REGISTER_DIG_H4              = 0xE4,
   BME280_REGISTER_DIG_H5              = 0xE5,
   BME280_REGISTER_DIG_H6              = 0xE7,

   BME280_REGISTER_CHIPID             = 0xD0,
   BME280_REGISTER_VERSION            = 0xD1,
   BME280_REGISTER_SOFTRESET          = 0xE0,

   /* calibration stored in 0xE1-0xF0 */
   BME280_REGISTER_CAL26              = 0xE1,

   BME280_REGISTER_CONTROLHUMID       = 0xF2,
   BME280_REGISTER_CONTROL            = 0xF4,
   BME280_REGISTER_CONFIG             = 0xF5,
   BME280_REGISTER_PRESSUREDATA       = 0xF7,
   BME280_REGISTER_TEMPDATA           = 0xFA,
   BME280_REGISTER_HUMIDDATA          = 0xFD,
 };

 /**
  * calibration data structure to hold coefficients
  */
 typedef struct
 {
   uint16_t dig_T1;
   int16_t  dig_T2;
   int16_t  dig_T3;

   uint16_t dig_P1;
   int16_t  dig_P2;
   int16_t  dig_P3;
   int16_t  dig_P4;
   int16_t  dig_P5;
   int16_t  dig_P6;
   int16_t  dig_P7;
   int16_t  dig_P8;
   int16_t  dig_P9;

   uint8_t  dig_H1;
   int16_t  dig_H2;
   uint8_t  dig_H3;
   int16_t  dig_H4;
   int16_t  dig_H5;
   int8_t   dig_H6;
 } bme280_calib_data;

 /**
  * Setup the SPI interface for talking with the BME280 and init sensor
  */
KSensorStatus bme280_setup(void);

/**
 * Reset the bme280 to default conditions
 */
KSensorStatus bme280_soft_reset(void);

/**
 * Sends temperature command and reads back temperature data
 * @return float temperature in celsius (-40.0 to 85.0)
 */
float bme280_read_temperature(void);

/**
 * Sends pressure command and reads back pressure data
 * @return float pressure reading in hPa (300.0 - 1100.0)
 */
float bme280_read_pressure(void);

/**
 * Sends humidity command and reads back humidity data
 * @return float relative humidity in percentage (0.0 - 100.0)
 */
float bme280_read_humidity(void);

/**
 * converts pressure to absolute altitude in meters
 */
float bme280_read_altitude(float sea_level);


#endif
#endif
