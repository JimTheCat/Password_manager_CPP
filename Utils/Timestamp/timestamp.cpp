//
// Created by Jimmy on 27.05.2022.
//

#include "timestamp.h"

#include <time.h>

int timestamp::randomTS() {
    return (int) time(nullptr);
}
