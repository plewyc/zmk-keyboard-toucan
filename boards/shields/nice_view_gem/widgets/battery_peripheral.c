#include <zephyr/kernel.h>
#include "battery_peripheral.h"
#include "../assets/custom_fonts.h"

LV_IMG_DECLARE(bolt);
LV_IMG_DECLARE(r_battery_100);
LV_IMG_DECLARE(r_battery_90);
LV_IMG_DECLARE(r_battery_75);
LV_IMG_DECLARE(r_battery_50);
LV_IMG_DECLARE(r_battery_25);
LV_IMG_DECLARE(r_battery_10);


static void draw_level_peripheral(lv_layer_t *layer, const struct status_state *state) {
    lv_draw_image_dsc_t img_dsc_r;
    lv_draw_image_dsc_init(&img_dsc_r);

    const lv_img_dsc_t *img = NULL;
    uint8_t level = state->battery_p;

    if (level > 90) {
        img = &r_battery_100;
    } else if (level > 75) {
        img = &r_battery_90;
    } else if (level > 50) {
        img = &r_battery_75;
    } else if (level > 25) {
        img = &r_battery_50;
    } else if (level > 10) {
        img = &r_battery_25;
    } else if (level > 1) {
        img = &r_battery_10;
    }

    if (img != NULL) {
        img_dsc_r.src = img;
        lv_area_t coords = {80, 10, 80 + 59, 10 + 16};
        lv_draw_image(layer, &img_dsc_r, &coords);
    }
}

void draw_battery_peripheral_status(lv_layer_t *layer, const struct status_state *state) {
    draw_level_peripheral(layer, state);
}
