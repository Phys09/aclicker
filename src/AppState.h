#pragma once
#include "imgui.h"
struct AppState {
  bool show_debug_window = true;
  bool show_demo_window = true;
  bool show_another_window = false;
  bool hold_left_clicks = false;
  bool hold_right_clicks = false;
  bool do_left_clicks = false;
  bool do_right_clicks = false;
  int num_left_clicks = 0;
  int num_right_clicks = 0;
  unsigned int left_click_delay_ms = 250;
  unsigned int right_click_delay_ms = 250;
  ImVec4 clear_color = ImVec4(0.45F, 0.55F, 0.60F, 1.00F);
};
