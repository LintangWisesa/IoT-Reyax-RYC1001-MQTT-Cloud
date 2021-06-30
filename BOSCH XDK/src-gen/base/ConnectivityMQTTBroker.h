/**
 * Generated by Eclipse Mita 0.1.0.
 * @date 2021-06-29 11:06:59
 */


#ifndef CONNECTIVITYMQTT_MQTT_H
#define CONNECTIVITYMQTT_MQTT_H

#include <BCDS_Retcode.h>


/**
 * Sets up the MQTT.
 */
Retcode_T ConnectivityMQTTBroker_Setup(void);

/**
 * Enables the MQTT sensor.
 */
Retcode_T ConnectivityMQTTBroker_Enable(void);

/**
 * Provides read access to topik.
 */
Retcode_T ConnectivityMQTTBroker_Topik_Read(char** result);

/**
 * Provides write access to topik.
 */
Retcode_T ConnectivityMQTTBroker_Topik_Write(char** result);


#endif