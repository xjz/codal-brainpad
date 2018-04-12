#ifndef BRAINPADLIGHTSENSOR_H
#define BRAINPADLIGHTSENSOR_H

#include "Pin.h"

namespace codal
{
   class BrainPadLightSensor {
        Pin& pin;

    public:

        BrainPadLightSensor(Pin& pin, uint16_t id);
        int readLightLevel();

   };
}

#endif
