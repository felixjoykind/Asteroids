#include "Random.h"
#include <stdlib.h>

float Random::Float()
{
    return static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
}

float Random::Float(const float max)
{
    return float(rand()) / float((RAND_MAX)) * max;
}
