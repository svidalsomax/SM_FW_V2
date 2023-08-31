/*
 * ble_driver.h
 *
 *  Author: MWF
 */ 


#ifndef BLE_DRIVER_H_
#define BLE_DRIVER_H_

/******************************************************************************
**      INCLUDES
******************************************************************************/
#include <atmel_start_pins.h>
#include <hal_gpio.h>
#include <hal_usart_async.h>
#include <driver_init.h>
#include <string.h>
#include <stdio.h>




/******************************************************************************
**      VARIABLES
******************************************************************************/

typedef enum {
	BLE_BEGIN,
	BLE_RENEW,
	BLE_ROLE,
	BLE_IMME,
	BLE_RESET,
	BLE_PROCESS,
}bleStatus;

typedef struct {
	char txBuffer_[64];
	char rxBuffer_[64];
	bleStatus bleState_;
	unsigned long timer_;
	unsigned long time_;
	int tryCounter_;
	//char state_[...];
	bool role_ ;
	int scanTime_;
} Ble;




/******************************************************************************
**      FUNCTIONS
******************************************************************************/
int ble_init(void);
void ble_send(char* command);
void ble_send_and_receive(char* command, char* response);

/******************************************************************************
**      SOMAX - FUNCTIONS
******************************************************************************/
void ble_process(Ble *ble);
void ble_retry(bleStatus state, Ble *ble);

#endif /* BLE_DRIVER_H_ */