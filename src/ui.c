#pragma once
#include "includes.h"

/** The UI! <<It has to be rendered for each frame. (put it in the loop)>> **/
static void create_main_menu_ui(struct nk_context *ctx, bool *show_main_ui, bool *divide, bool *greedy) {
  if (nk_begin(ctx, "Main_Menu", nk_rect(0, 0, 1200, 900), 0)) {
    nk_layout_row_dynamic(ctx, 500.0f, 1);
    nk_label(ctx, "Select the method", NK_TEXT_CENTERED);

    // Buttons
    nk_layout_row_dynamic(ctx, 60.0f, 2);
    if (nk_button_label(ctx, "Greedy Algorithm")) {
      *greedy = true;
      *show_main_ui = false;
    }
    if (nk_button_label(ctx, "Divide & Conquer Algorithm")) {
      *divide = true;
      *show_main_ui = false;
    }
  }
  nk_end(ctx);
}
/** The UI! <<It has to be rendered for each frame. (put it in the loop)>> **/
static void create_back_option(struct nk_context *ctx, bool *show_main_ui, bool *divide, bool *greedy) {
  if (nk_begin(ctx, "back_option", nk_rect(1000, 800, 100, 50), 0)) {
    nk_layout_row_dynamic(ctx, 0.0f, 1);
    if (nk_button_label(ctx, "back")) {
      *divide = false;
      *greedy = false;
      *show_main_ui = true;
    }
  }
  nk_end(ctx);
}
