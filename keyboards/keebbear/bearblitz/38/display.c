// SPDX-License-Identifier: GPL-2.0-or-later

#include "display.h"
#include "qp.h"
#include "lvgl_helpers.h"

/* shared styles */
lv_style_t style_screen;
lv_style_t style_container;
lv_style_t style_button;
lv_style_t style_button_active;

/* screens */
static lv_obj_t *screen_home;

/* home screen content */
// static lv_obj_t *label_shift;
// static lv_obj_t *label_ctrl;
// static lv_obj_t *label_alt;
// static lv_obj_t *label_gui;
// static lv_obj_t *label_caps;
static lv_obj_t *img_layout;
// static lv_obj_t *label_layer;

LV_IMG_DECLARE(keebbear);

void init_styles(void) {
    lv_style_init(&style_screen);
    lv_style_set_bg_color(&style_screen, lv_color_white());
    lv_style_set_pad_all(&style_screen, 0);

    lv_style_init(&style_container);
    lv_style_set_pad_all(&style_container, 0);
    lv_style_set_bg_opa(&style_container, 0);
    lv_style_set_border_width(&style_container, 0);
    lv_style_set_width(&style_container, lv_pct(100));
    lv_style_set_height(&style_container, LV_SIZE_CONTENT);

    lv_style_init(&style_button);
    lv_style_set_pad_all(&style_button, 4);
    lv_style_set_radius(&style_button, 6);
    lv_style_set_text_color(&style_button, lv_palette_main(LV_PALETTE_CYAN));

    lv_style_init(&style_button_active);
    lv_style_set_bg_color(&style_button_active, lv_palette_main(LV_PALETTE_CYAN));
    lv_style_set_bg_opa(&style_button_active, LV_OPA_100);
    lv_style_set_text_color(&style_button_active, lv_color_black());
}

void init_screen_home(void) {
    screen_home = lv_scr_act();

    lv_obj_add_style(screen_home, &style_screen, LV_PART_MAIN);
    // use_flex_column(screen_home);

    // lv_obj_t *top_row = lv_obj_create(screen_home);
    // lv_obj_add_style(top_row, &style_container, LV_PART_MAIN);
    // lv_obj_set_style_pad_hor(top_row, 10, LV_PART_MAIN);
    // use_flex_row(top_row);
    // label_ctrl  = create_button(top_row, "CTL", &style_button, &style_button_active);
    // label_alt = create_button(top_row, "ALT", &style_button, &style_button_active);
    // label_gui = create_button(top_row, "GUI", &style_button, &style_button_active);
    // label_shift = create_button(top_row, "SFT", &style_button, &style_button_active);

    lv_obj_t *img_row = lv_obj_create(screen_home);
    lv_obj_add_style(img_row, &style_container, LV_PART_MAIN);
    img_layout = lv_img_create(img_row);
    lv_obj_align(img_layout, LV_ALIGN_TOP_MID, 0, 0);

    // lv_obj_t *text_row = lv_obj_create(screen_home);
    // lv_obj_add_style(text_row, &style_container, LV_PART_MAIN);
    // label_layer = lv_label_create(text_row);
    // lv_obj_align(label_layer, LV_ALIGN_TOP_MID, 0, 0);
    // lv_label_set_text(label_layer, "");

    // lv_obj_t *bottom_row = lv_obj_create(screen_home);
    // lv_obj_add_style(bottom_row, &style_container, LV_PART_MAIN);
    // label_caps = create_button(bottom_row, "CAPS", &style_button, &style_button_active);
    // lv_obj_align(label_caps, LV_ALIGN_TOP_MID, 0, 0);

    lv_img_set_src(img_layout, &keebbear);

}

void display_process_layer_state(uint8_t layer) {
    // switch (layer) {
    //     case _DESIGN:
    //         lv_img_set_src(img_layout, &design);
    //         lv_label_set_text(label_layer, "Design");
    //         lv_obj_set_style_text_font(label_layer, &lv_font_montserrat_20, LV_PART_MAIN);
    //         break;
    //     case _DEV:
    //         lv_img_set_src(img_layout, &code);
    //         lv_label_set_text(label_layer, "Code");
    //         lv_obj_set_style_text_font(label_layer, &lv_font_montserrat_20, LV_PART_MAIN);
    //         break;
    //     case _GAME:
    //         lv_img_set_src(img_layout, &game);
    //         lv_label_set_text(label_layer, "Game");
    //         lv_obj_set_style_text_font(label_layer, &lv_font_montserrat_20, LV_PART_MAIN);
    //         break;
    //     case _ARRPAD:
    //         lv_img_set_src(img_layout, &arrpad);
    //         lv_label_set_text(label_layer, "Arrow & Numpad");
    //         lv_obj_set_style_text_font(label_layer, &lv_font_montserrat_20, LV_PART_MAIN);
    //         break;
    //     case _ADJUST:
    //         lv_img_set_src(img_layout, &cog);
    //         lv_label_set_text(label_layer, "Adjust");
    //         lv_obj_set_style_text_font(label_layer, &lv_font_montserrat_20, LV_PART_MAIN);
    //         break;
    //     case _LOWER:
    //         lv_img_set_src(img_layout, &lower);
    //         lv_label_set_text(label_layer, "Lower");
    //         lv_obj_set_style_text_font(label_layer, &lv_font_montserrat_20, LV_PART_MAIN);
    //         break;
    //     case _RAISE:
    //         lv_img_set_src(img_layout, &raise);
    //         lv_label_set_text(label_layer, "Raise");
    //         lv_obj_set_style_text_font(label_layer, &lv_font_montserrat_20, LV_PART_MAIN);
    //         break;
    // }
}

bool display_init_kb(void) {
    dprint("display_init_kb - start\n");

    painter_device_t display = qp_st7789_make_spi_device(240, 300, LCD_CS_PIN, LCD_DC_PIN, LCD_RST_PIN, 16, 3);
    qp_set_viewport_offsets(display, 0, 20);

    if (!qp_init(display, QP_ROTATION_180) || !qp_power(display, true) || !qp_lvgl_attach(display)) return false;

    dprint("display_init_kb - initialised\n");

    lv_disp_t  *lv_display = lv_disp_get_default();
    lv_theme_t *lv_theme   = lv_theme_default_init(lv_display, lv_palette_main(LV_PALETTE_AMBER), lv_palette_main(LV_PALETTE_BLUE), true, LV_FONT_DEFAULT);
    lv_disp_set_theme(lv_display, lv_theme);
    init_styles();

    display_init_user();

    return true;
}

bool display_init_user(void) {
    init_screen_home();

    return false;
}

__attribute__((weak)) void display_housekeeping_task(void) {
    dprint("display_housekeeping_task_kb\n");

    // toggle_state(label_shift, LV_STATE_PRESSED, MODS_SHIFT);
    // toggle_state(label_ctrl, LV_STATE_PRESSED, MODS_CTRL);
    // toggle_state(label_alt, LV_STATE_PRESSED, MODS_ALT);
    // toggle_state(label_gui, LV_STATE_PRESSED, MODS_GUI);
}

__attribute__((weak)) void display_process_caps(bool active) {
    dprint("display_process_caps\n");
    // toggle_state(label_caps, LV_STATE_PRESSED, active);
}
