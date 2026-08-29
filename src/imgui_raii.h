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

struct ImGuiMainMenuBarWidget {
public:
  ImGuiMainMenuBarWidget() : is_visible_{ImGui::BeginMainMenuBar()} {}

  ~ImGuiMainMenuBarWidget() { ImGui::EndMainMenuBar(); }
  explicit operator bool() const noexcept { return is_visible_; }

  // Move and Copy disallowed
  ImGuiMainMenuBarWidget(const ImGuiMainMenuBarWidget &other) = delete;
  ImGuiMainMenuBarWidget(ImGuiMainMenuBarWidget &&other) noexcept = delete;
  ImGuiMainMenuBarWidget &operator=(const ImGuiMainMenuBarWidget &other) = delete;
  ImGuiMainMenuBarWidget &operator=(ImGuiMainMenuBarWidget &&other) noexcept = delete;

private:
  bool is_visible_;
};

struct ImGuiMenuWidget {
public:
  ImGuiMenuWidget(const char *label) : is_visible_{ImGui::BeginMenu(label)} {}

  ~ImGuiMenuWidget() { ImGui::EndMenu(); }
  explicit operator bool() const noexcept { return is_visible_; }

  // Move and Copy disallowed
  ImGuiMenuWidget(const ImGuiMenuWidget &other) = delete;
  ImGuiMenuWidget(ImGuiMenuWidget &&other) noexcept = delete;
  ImGuiMenuWidget &operator=(const ImGuiMenuWidget &other) = delete;
  ImGuiMenuWidget &operator=(ImGuiMenuWidget &&other) noexcept = delete;

private:
  bool is_visible_;
};

struct ImGuiTableWidget {
public:
  ImGuiTableWidget(const char *str_id, int columns, ImGuiTableFlags flags = 0, const ImVec2 &outer_size = ImVec2(0.0F, 0.0F), float inner_width = 0.0F)
      : is_visible_{ImGui::BeginTable(str_id, columns, flags, outer_size, inner_width)} {}

  ~ImGuiTableWidget() { ImGui::EndTable(); }
  explicit operator bool() const noexcept { return is_visible_; }

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

  explicit operator bool() const noexcept { return is_visible_; }

private:
  bool is_visible_;
};
} // namespace ImRAII
