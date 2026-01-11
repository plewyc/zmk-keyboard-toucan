#include <zephyr/kernel.h>
#include "profile.h"

LV_IMG_DECLARE(profiles);

static void draw_inactive_profiles(lv_layer_t *layer, const struct status_state *state) {
    lv_draw_image_dsc_t img_dsc;
    lv_draw_image_dsc_init(&img_dsc);
    img_dsc.src = &profiles;

    lv_area_t coords = {85, 143, 85 + 48, 143 + 8};
    lv_draw_image(layer, &img_dsc, &coords);
}

static void draw_active_profile(lv_layer_t *layer, const struct status_state *state) {
    lv_draw_rect_dsc_t rect_white_dsc;
    init_rect_dsc(&rect_white_dsc, LVGL_FOREGROUND);

    int offset = state->active_profile_index * 10;

    lv_area_t coords = {85 + offset, 143, 85 + offset + 8, 143 + 8};
    lv_draw_rect(layer, &rect_white_dsc, &coords);
}

void draw_profile_status(lv_layer_t *layer, const struct status_state *state) {
    draw_inactive_profiles(layer, state);
    draw_active_profile(layer, state);
}