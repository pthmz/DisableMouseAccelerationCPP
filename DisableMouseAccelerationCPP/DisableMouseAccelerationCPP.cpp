#include <windows.h>
#include <iostream>

// Define SPI action codes
#define SPI_GETMOUSE 0x0003
#define SPI_SETMOUSE 0x0004
#define SPIF_UPDATEINIFILE 0x01
#define SPIF_SENDCHANGE 0x02

bool DisableEnhancedPointerPrecision() {
    // Create an integer array to store mouse parameters
    int mouseParams[3];

    // Get the current mouse parameters
    if (!SystemParametersInfo(SPI_GETMOUSE, 0, &mouseParams, 0)) {
        return false;
    }

    // Set the acceleration value to 0 to disable enhanced pointer precision
    mouseParams[2] = 0;

    // Update the system settings
    return SystemParametersInfo(SPI_SETMOUSE, 0, &mouseParams, SPIF_UPDATEINIFILE | SPIF_SENDCHANGE);
}

int main() {
    std::cout << "Disabling enhanced pointer precision..." << std::endl;
    bool result = DisableEnhancedPointerPrecision();
    if (result) {
        std::cout << "Enhanced pointer precision disabled successfully." << std::endl;
    }
    else {
        std::cout << "Failed to disable enhanced pointer precision." << std::endl;
    }
    return 0;
}