enum theme {
  THEME_CATPPUCCIN_MOCHA
};

static void set_style(struct nk_context *ctx, enum theme theme) {
  struct nk_color table[NK_COLOR_COUNT];
  if (theme == THEME_CATPPUCCIN_MOCHA) {
    /*struct nk_color rosewater = nk_rgba(245, 224, 220, 255);*/
    /*struct nk_color flamingo = nk_rgba(242, 205, 205, 255);*/
    struct nk_color pink = nk_rgba(245, 194, 231, 180);
    /*struct nk_color mauve = nk_rgba(203, 166, 247, 255);*/
    /*struct nk_color red = nk_rgba(243, 139, 168, 255);*/
    /*struct nk_color maroon = nk_rgba(235, 160, 172, 255);*/
    /*struct nk_color peach = nk_rgba(250, 179, 135, 255);*/
    /*struct nk_color yellow = nk_rgba(249, 226, 175, 255);*/
    struct nk_color green = nk_rgba(166, 227, 161, 180);
    /*struct nk_color teal = nk_rgba(148, 226, 213, 255);*/
    /*struct nk_color sky = nk_rgba(137, 220, 235, 255);*/
    /*struct nk_color sapphire = nk_rgba(116, 199, 236, 255);*/
    /*struct nk_color blue = nk_rgba(137, 180, 250, 255);*/
    struct nk_color lavender = nk_rgba(180, 190, 254, 180);
    struct nk_color text = nk_rgba(205, 214, 244, 255);
    /*struct nk_color subtext1 = nk_rgba(186, 194, 222, 255);*/
    /*struct nk_color subtext0 = nk_rgba(166, 173, 200, 255);*/
    struct nk_color overlay2 = nk_rgba(147, 153, 178, 180);
    struct nk_color overlay1 = nk_rgba(127, 132, 156, 180);
    struct nk_color overlay0 = nk_rgba(108, 112, 134, 180);
    struct nk_color surface2 = nk_rgba(88, 91, 112, 180);
    struct nk_color surface1 = nk_rgba(69, 71, 90, 180);
    struct nk_color surface0 = nk_rgba(49, 50, 68, 180);
    struct nk_color base = nk_rgba(30, 30, 46, 150);
    struct nk_color mantle = nk_rgba(24, 24, 37, 150);
    /*struct nk_color crust = nk_rgba(17, 17, 27, 255);*/
    table[NK_COLOR_TEXT] = text;
    table[NK_COLOR_WINDOW] = base;
    table[NK_COLOR_HEADER] = mantle;
    table[NK_COLOR_BORDER] = mantle;
    table[NK_COLOR_BUTTON] = surface0;
    table[NK_COLOR_BUTTON_HOVER] = overlay1;
    table[NK_COLOR_BUTTON_ACTIVE] = overlay0;
    table[NK_COLOR_TOGGLE] = surface2;
    table[NK_COLOR_TOGGLE_HOVER] = overlay2;
    table[NK_COLOR_TOGGLE_CURSOR] = lavender;
    table[NK_COLOR_SELECT] = surface0;
    table[NK_COLOR_SELECT_ACTIVE] = overlay0;
    table[NK_COLOR_SLIDER] = surface1;
    table[NK_COLOR_SLIDER_CURSOR] = green;
    table[NK_COLOR_SLIDER_CURSOR_HOVER] = green;
    table[NK_COLOR_SLIDER_CURSOR_ACTIVE] = green;
    table[NK_COLOR_PROPERTY] = surface0;
    table[NK_COLOR_EDIT] = surface0;
    table[NK_COLOR_EDIT_CURSOR] = lavender;
    table[NK_COLOR_COMBO] = surface0;
    table[NK_COLOR_CHART] = surface0;
    table[NK_COLOR_CHART_COLOR] = lavender;
    table[NK_COLOR_CHART_COLOR_HIGHLIGHT] = pink;
    table[NK_COLOR_SCROLLBAR] = surface0;
    table[NK_COLOR_SCROLLBAR_CURSOR] = overlay0;
    table[NK_COLOR_SCROLLBAR_CURSOR_HOVER] = lavender;
    table[NK_COLOR_SCROLLBAR_CURSOR_ACTIVE] = pink;
    table[NK_COLOR_TAB_HEADER] = surface0;
    table[NK_COLOR_KNOB] = table[NK_COLOR_SLIDER];
    table[NK_COLOR_KNOB_CURSOR] = pink;
    table[NK_COLOR_KNOB_CURSOR_HOVER] = pink;
    table[NK_COLOR_KNOB_CURSOR_ACTIVE] = pink;
    nk_style_from_table(ctx, table);   
  } else {
    nk_style_default(ctx);
  }
}
