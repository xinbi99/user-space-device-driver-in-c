#ifndef LCLOUD_CONTROLLER_INCLUDED
#define LCLOUD_CONTROLLER_INCLUDED

////////////////////////////////////////////////////////////////////////////////
//
//  File           : lcloud_controller.c
//  Description    : This is the controller definitions that provides an
//                   interface and simulation of the cloud devices.
//
//   Author        : Patrick McDaniel
//   Last Modified : Fri 10 Jan 2020 04:42:03 PM EST
//

// Includes 

// Defines
#define LC_DEVICE_BLOCK_SIZE 256 // Device block size (in bytes)
#define LC_MAX_OPERATION_SIZE 4096 // Maximum size for any read or write
#define LC_XFER_READ 0
#define LC_XFER_WRITE 1

/* Lion Cloud Device Type Definitions */
typedef uint8_t LcDeviceId; /* The hardware device identifier */
typedef uint64_t LCloudRegisterFrame; 

/*

LCloudRegisterFrame

Bits   Register
------ --------------------------------------------------
   0-3 B0 - first 4 bit register
   4-7 B1 - second 4 bit register
  8-15 C0 - first 8 bit register
 16-23 C1 - second 8 bit register
 24-31 C2 - third 8 bit register
 32-47 D0 - first 16 bit register
 48-63 D1 - second 16 bit register

 */

// These are unumerated types identifying the registers
typedef enum {

  LCLOUD_REG_B0 = 0,     // first 4 bit register
  LCLOUD_REG_B1 = 1,     // second 4 bit register
  LCLOUD_REG_C0 = 2,     // first 8 bit register
  LCLOUD_REG_C1 = 3,     // second 8 bit register
  LCLOUD_REG_C2 = 4,     // third 8 bit register
  LCLOUD_REG_D0 = 5,     // first 16 bit register
  LCLOUD_REG_D1 = 6,     // second 16 bit register
  LCLOUD_REG_MAXVAL = 7  // Unused MAX value

} LCloudRegister;

// These are the states of the devices
typedef enum {
    LC_DEVICE_UNINITIALIZED = 0,   // The device is uninitialized
    LC_DEVICE_ONLINE        = 1,   // The device is formatted and ready for xfers
    LC_DEVICE_ERRORED       = 2,   // The device is an error state
} LcDeviceState;

/* These are the operations supported by the device */
typedef enum {
    LC_POWER_ON       = 0,  // Initialize interface to a given device
    LC_DEVPROBE       = 1,  // Probe the bus to see what devices are
    LC_BLOCK_XFER     = 2,  // Transfer a block to the device
    LC_POWER_OFF      = 3,  // Power off the device
    LC_MAX_OPERATION  = 4   // Maximum operation number
} LcOperationCode;


/* These are error values for the device */
typedef enum {
    LC_NO_STATUS  = 0, // No status (used by controller)
    LC_SUCCESS    = 1, // Request successful 
    LC_NO_DEVICE  = 2, // The device requested is unknown
    LC_BAD_PARAMS = 3, // Bad parameters in request
    LC_MAX_STATUS = 4  // Maximum status number
} LcStatusCode;

//
// Static Data

/* C string labels for the operations */
extern const char *LC_OPERATION_CODE_FIELD_LABLES[LC_MAX_OPERATION+1];
extern const char *LC_STATUS_CODE_FIELD_LABLES[LC_MAX_STATUS+1];

/* Log levels to log events within the simulator */
extern unsigned long LcControllerLLevel; // Controller log level
extern unsigned long LcDriverLLevel;     // Driver log level
extern unsigned long LcSimulatorLLevel;  // Driver log level

//
// Functional Prototypes

LCloudRegisterFrame lcloud_io_bus( LCloudRegisterFrame frm, void *xfer );
    // this is the bus interface with the local/remote devices

// Support functions (NOT for student use)

int check_honors_option( void );
    // Check to see if the honors option completed successfully

int readLionCloudHardwareManifest( char *hwdef ); 
    //Read the LionCloud hardware spec

int lcloud_unit_test( void ); 
    // Unit test for simulation framework

#endif
