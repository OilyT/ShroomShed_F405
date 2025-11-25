#include "styles.h"
#include "images.h"
#include "fonts.h"

#include "ui.h"
#include "screens.h"

//
// Style: ShroomShed_Header
//

void init_style_shroom_shed_header_MAIN_DEFAULT(lv_style_t *style) {
    lv_style_set_text_color(style, lv_color_hex(0xff11c8da));
    lv_style_set_text_font(style, &lv_font_montserrat_18);
    lv_style_set_text_align(style, LV_TEXT_ALIGN_CENTER);
};

lv_style_t *get_style_shroom_shed_header_MAIN_DEFAULT() {
    static lv_style_t *style;
    if (!style) {
        style = lv_malloc(sizeof(lv_style_t));
        lv_style_init(style);
        init_style_shroom_shed_header_MAIN_DEFAULT(style);
    }
    return style;
};

void add_style_shroom_shed_header(lv_obj_t *obj) {
    (void)obj;
    lv_obj_add_style(obj, get_style_shroom_shed_header_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
};

void remove_style_shroom_shed_header(lv_obj_t *obj) {
    (void)obj;
    lv_obj_remove_style(obj, get_style_shroom_shed_header_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
};

//
// Style: ShroomShed_SubHeading
//

void init_style_shroom_shed_sub_heading_MAIN_DEFAULT(lv_style_t *style) {
    lv_style_set_text_color(style, lv_color_hex(0xff11c8da));
    lv_style_set_text_opa(style, 255);
    lv_style_set_text_font(style, &lv_font_montserrat_14);
    lv_style_set_text_align(style, LV_TEXT_ALIGN_CENTER);
};

lv_style_t *get_style_shroom_shed_sub_heading_MAIN_DEFAULT() {
    static lv_style_t *style;
    if (!style) {
        style = lv_malloc(sizeof(lv_style_t));
        lv_style_init(style);
        init_style_shroom_shed_sub_heading_MAIN_DEFAULT(style);
    }
    return style;
};

void add_style_shroom_shed_sub_heading(lv_obj_t *obj) {
    (void)obj;
    lv_obj_add_style(obj, get_style_shroom_shed_sub_heading_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
};

void remove_style_shroom_shed_sub_heading(lv_obj_t *obj) {
    (void)obj;
    lv_obj_remove_style(obj, get_style_shroom_shed_sub_heading_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
};

//
// Style: ShroomShed_SmallLabel
//

void init_style_shroom_shed_small_label_MAIN_DEFAULT(lv_style_t *style) {
    lv_style_set_text_color(style, lv_color_hex(0xff11c8da));
    lv_style_set_text_opa(style, 255);
    lv_style_set_text_font(style, &lv_font_montserrat_10);
    lv_style_set_text_align(style, LV_TEXT_ALIGN_CENTER);
};

lv_style_t *get_style_shroom_shed_small_label_MAIN_DEFAULT() {
    static lv_style_t *style;
    if (!style) {
        style = lv_malloc(sizeof(lv_style_t));
        lv_style_init(style);
        init_style_shroom_shed_small_label_MAIN_DEFAULT(style);
    }
    return style;
};

void add_style_shroom_shed_small_label(lv_obj_t *obj) {
    (void)obj;
    lv_obj_add_style(obj, get_style_shroom_shed_small_label_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
};

void remove_style_shroom_shed_small_label(lv_obj_t *obj) {
    (void)obj;
    lv_obj_remove_style(obj, get_style_shroom_shed_small_label_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
};

//
//
//

void add_style(lv_obj_t *obj, int32_t styleIndex) {
    typedef void (*AddStyleFunc)(lv_obj_t *obj);
    static const AddStyleFunc add_style_funcs[] = {
        add_style_shroom_shed_header,
        add_style_shroom_shed_sub_heading,
        add_style_shroom_shed_small_label,
    };
    add_style_funcs[styleIndex](obj);
}

void remove_style(lv_obj_t *obj, int32_t styleIndex) {
    typedef void (*RemoveStyleFunc)(lv_obj_t *obj);
    static const RemoveStyleFunc remove_style_funcs[] = {
        remove_style_shroom_shed_header,
        remove_style_shroom_shed_sub_heading,
        remove_style_shroom_shed_small_label,
    };
    remove_style_funcs[styleIndex](obj);
}

