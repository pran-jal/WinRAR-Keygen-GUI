#include <stddef.h>
#include <stdint.h>

namespace accel::algorithm::hash::SHA1 {

    void Initialize(uint32_t hashResult[5]);
    void MainCycle(const uint8_t srcBytes[], size_t srcBytesLength, uint32_t hashResult[5]);
    void Final(const uint8_t srcBytes[], size_t srcBytesLength, uint32_t hashResult[5]);

}