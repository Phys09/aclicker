#pragma once
#include "custom_ui_elements.h"
#include "AppState.h"
#include "imgui.h"
#include "imgui_raii.h"
void MyUi::DrawMainMenuBar(AppState &appstate) {
  if (ImRAII::ImGuiMainMenuBarWidget()) {
    if (ImRAII::ImGuiMenuWidget("Options")) {
      if (ImGui::MenuItem("Show Debug Menu", nullptr, &(appstate.show_debug_window))) {
      }
    }
    if (ImRAII::ImGuiMenuWidget("Tools")) {
    }
  }
}

void MyUi::DrawDebugWindow(AppState &appstate) {
  
}
