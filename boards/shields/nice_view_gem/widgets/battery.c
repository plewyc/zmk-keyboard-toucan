#include <zephyr/kernel.h>
#include "battery.h"
#include "../assets/custom_fonts.h"

LV_IMG_DECLARE(bolt);
LV_IMG_DECLARE(l_battery_100);
LV_IMG_DECLARE(l_battery_90);
LV_IMG_DECLARE(l_battery_75);
LV_IMG_DECLARE(l_battery_50);
LV_IMG_DECLARE(l_battery_25);
LV_IMG_DECLARE(l_battery_10);


static void draw_level(lv_layer_t *layer, const struct status_state *state) {
    lv_draw_image_dsc_t img_dsc_l;
    lv_draw_image_dsc_init(&img_dsc_l);

    const lv_img_dsc_t *img = NULL;
    uint8_t level = state->battery;

    if (level > 90) {
        img = &l_battery_100;
    } else if (level > 75) {
        img = &l_battery_90;
    } else if (level > 50) {
        img = &l_battery_75;
    } else if (level > 25) {
        img = &l_battery_50;
    } else if (level > 10) {
        img = &l_battery_25;
    } else if (level > 1) {
        img = &l_battery_10;
    }

    if (img != NULL) {
        img_dsc_l.src = img;
        lv_area_t coords = {8, 10, 8 + 59, 10 + 16};
        lv_draw_image(layer, &img_dsc_l, &coords);
    }
}

void draw_battery_status(lv_layer_t *layer, const struct status_state *state) {
    draw_level(layer, state);
}