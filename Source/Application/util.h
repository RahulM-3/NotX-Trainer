#include <pch.h>

// Debug logs
#include <fstream>
std::ofstream logfile("debug.log");


// concat multiple char*
const char* concatCharArr(int count, ...) {
    // Define a maximum buffer size (adjust based on your requirements)
    const size_t BUFFER_SIZE = 1024;

    // Allocate a buffer for the result
    char* result = new char[BUFFER_SIZE];
    result[0] = '\0'; // Initialize the buffer as an empty string

    // Initialize the variable argument list
    va_list args;
    va_start(args, count);

    for (int i = 0; i < count; ++i) {
        const char* str = va_arg(args, const char*);

        // Concatenate the current string into the result buffer
        errno_t err = strcat_s(result, BUFFER_SIZE, str);
        if (err != 0) {
            std::cerr << "String concatenation failed!" << std::endl;
            delete[] result;
            va_end(args);
            return nullptr; // Return null on failure
        }
    }

    va_end(args);
    return result; // Return the concatenated result
}