#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// -------------------------------------------------------------------
// Problem 1: Inventory Item Packing/Unpacking
// -------------------------------------------------------------------

// Max values to ensure proper masking
#define MAX_ITEM_ID 16383 // 14 bits
#define MAX_STATUS    15 //  4 bits
#define MAX_LOCATION  63 //  6 bits

// Bit masks and positions (indexed from LSB = 0)
#define LOCATION_POS  0
#define STATUS_POS    6
#define ITEM_ID_POS  10
#define RESERVED_POS 24

/**
 * @brief Packs three integer fields into a single 32-bit unsigned integer.
 */
unsigned int packItem(int itemID, int status, int location) {
    unsigned int packedWord = 0;
    
    packedWord |=  (unsigned int)location;
    
    packedWord |= (unsigned int)status << STATUS_POS;
    
    packedWord |= (unsigned int)itemID << ITEM_ID_POS;
    
    
    
    // 1. Pack Location (6 bits @ Pos 0)
    // 2. Pack Status (4 bits @ Pos 6)
    // 3. Pack Item ID (14 bits @ Pos 10)
    
    // The reserved bits (31-24) will automatically be 0 since packedWord started at 0.
    
    /* YOUR CODE HERE */
    
    return packedWord;
}

/**
 * @brief Extracts the three integer fields from a single 32-bit unsigned integer.
 */
void unpackItem(unsigned int packedWord, int *itemID, int *status, int *location) {
    
    // 1. Unpack Location (6 bits @ Pos 0)
    // 2. Unpack Status (4 bits @ Pos 6)
    // 3. Unpack Item ID (14 bits @ Pos 10)
    
    /* YOUR CODE HERE */
    unsigned int locationMask = (1 << 6) - 1;
    unsigned int statusMask = (1 << 4) - 1;
    unsigned int itemIDMask = (1 << 14) - 1;
    
    
  *location = (packedWord >> LOCATION_POS) & locationMask;
  *status = (packedWord >> STATUS_POS) & statusMask;
  *itemID = (packedWord >> ITEM_ID_POS) & itemIDMask;
    
}

// -------------------------------------------------------------------
// Problem 2: System Status Flags (Computer Word Set)
// -------------------------------------------------------------------

// Flag masks (1 shifted to the relevant bit position)
#define POWER_ON          (1 << 0)
#define ERROR_MODE        (1 << 1)
#define WIFI_CONNECTED    (1 << 2)
#define BATTERY_LOW       (1 << 3)
#define UPDATE_AVAILABLE  (1 << 4)

/**
 * @brief Sets a specific flag (turns the bit ON) in the status byte.
 */
void setFlag(unsigned char *status, unsigned char flagMask) {
    /* YOUR CODE HERE */

    *status |= flagMask;
}

/**
 * @brief Clears a specific flag (turns the bit OFF) in the status byte.
 */
void clearFlag(unsigned char *status, unsigned char flagMask) {
    /* YOUR CODE HERE */
    *status &= ~flagMask;
}

/**
 * @brief Checks if a specific flag is ON.
 * @return 1 if the flag is ON, 0 otherwise.
 */
int checkFlag(unsigned char status, unsigned char flagMask) {
    /* YOUR CODE HERE */
    
    return (status & flagMask); // Placeholder
}

// -------------------------------------------------------------------
// MAIN FUNCTION (Testing Menu)
// -------------------------------------------------------------------

void run_problem_1_test() {
    printf("--- Problem 1: Inventory Packing ---\n");
    int test_itemID = 12345;
    int test_status = 12;
    int test_location = 42;
    
    printf("Input: ID=%d, Status=%d, Loc=%d\n", test_itemID, test_status, test_location);

    unsigned int packed = packItem(test_itemID, test_status, test_location);
    printf("Packed Hex: 0x%X\n", packed);

    int out_itemID, out_status, out_location;
    unpackItem(packed, &out_itemID, &out_status, &out_location);

    printf("Unpacked: ID=%d, Status=%d, Loc=%d\n", out_itemID, out_status, out_location);
}

void run_problem_2_test() {
    printf("\n--- Problem 2: System Status Flags ---\n");
    unsigned char status = 0; // Initial state: 0000 0000
    
    printf("Initial Status: 0x%02X\n", status);
    
    // Action 1: Set POWER_ON and WIFI_CONNECTED
    setFlag(&status, POWER_ON);
    setFlag(&status, WIFI_CONNECTED);
    printf("After Set (Power, WiFi): 0x%02X\n", status);
    
    // Action 2: Set ERROR_MODE and BATTERY_LOW
    setFlag(&status, ERROR_MODE | BATTERY_LOW);
    printf("After Set (Error, Batt): 0x%02X\n", status);
    
    // Action 3: Clear WIFI_CONNECTED
    clearFlag(&status, WIFI_CONNECTED);
    printf("After Clear (WiFi): 0x%02X\n", status);
    
    // Action 4: Check flags
    printf("Check ERROR_MODE: %s\n", checkFlag(status, ERROR_MODE) ? "ON" : "OFF");
    printf("Check UPDATE_AVAILABLE: %s\n", checkFlag(status, UPDATE_AVAILABLE) ? "ON" : "OFF");
}

int main() {
    run_problem_1_test();
    run_problem_2_test();
    return 0;
}
