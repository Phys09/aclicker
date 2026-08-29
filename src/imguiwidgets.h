#pragma once
#include "imgui.h"

namespace ImRAII {
/** Unused, instead of inheriting, explicitly disable copy/move in each class directly */
struct ImGuiWidget {

  // Move and Copy disallowed for self, and anything that inherits from self
  ImGuiWidget(const ImGuiWidget &other) = delete;
  ImGuiWidget(ImGuiWidget &&other) noexcept = delete;
  ImGuiWidget &operator=(const ImGuiWidget &other) = delete;
  ImGuiWidget &operator=(ImGuiWidget &&other) noexcept = delete;
};

struct ImGuiTableWidget {
public:
  ImGuiTableWidget(const char *str_id, int columns, ImGuiTableFlags flags = 0, const ImVec2 &outer_size = ImVec2(0.0f, 0.0f), float inner_width = 0.0f)
      : is_visible_{ImGui::BeginTable(str_id, columns, flags, outer_size, inner_width)} {}

  ~ImGuiTableWidget() { ImGui::EndTable(); }
  // bool BeginTable(const char* str_id, int columns, ImGuiTableFlags flags = 0, const ImVec2& outer_size = ImVec2(0.0f, 0.0f), float inner_width = 0.0f);
  explicit operator bool() { return is_visible_; }

  // Move and Copy disallowed
  ImGuiTableWidget(const ImGuiTableWidget &other) = delete;
  ImGuiTableWidget(ImGuiTableWidget &&other) noexcept = delete;
  ImGuiTableWidget &operator=(const ImGuiTableWidget &other) = delete;
  ImGuiTableWidget &operator=(ImGuiTableWidget &&other) noexcept = delete;

private:
  bool is_visible_;
};

struct ImGuiWindowWidget {
public:
  ImGuiWindowWidget(const char *name, bool *p_open = nullptr, ImGuiWindowFlags flags = 0) : is_visible_(ImGui::Begin(name, p_open, flags)) {}
  ~ImGuiWindowWidget() { ImGui::End(); }

  // Disallow copy and move
  ImGuiWindowWidget(const ImGuiWindowWidget &other) = delete;
  ImGuiWindowWidget(ImGuiWindowWidget &&other) noexcept = delete;
  ImGuiWindowWidget &operator=(const ImGuiWindowWidget &other) = delete;
  ImGuiWindowWidget &operator=(ImGuiWindowWidget &&other) noexcept = delete;

  explicit operator bool() { return is_visible_; }

private:
  bool is_visible_;
};
} // namespace ImRAII
