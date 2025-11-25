#include "vars.h"
#include "shroom_shed.h"


float get_var_display_var_humidity() {
    return shroomShed.humidityCurrent;
}

void set_var_display_var_humidity(float value) {
    shroomShed.humidityCurrent = value;
}
