#include "inputsendcore.h"
#include <chrono>
#include <cstdlib>
#include <format>
#include <iostream>
#include <print>
#include <span>
#include <stdexcept>
#include <string>
#include <thread>
#include <vector>
#include <windows.h>

void aclicker::SendLeftClicks(int n, std::chrono::milliseconds input_delay) {
  if (n <= 0) {
    std::println(std::cerr, "Error: Negative Inputs not allowed");
    return;
  }
  using namespace std::literals;

  std::vector<INPUT> mouseInputs{
      {.type = INPUT_MOUSE, .mi = {.dwFlags = MOUSEEVENTF_LEFTDOWN}},
      {.type = INPUT_MOUSE, .mi = {.dwFlags = MOUSEEVENTF_LEFTUP}}};

  while (n-- > 0) {
    SendInput(mouseInputs.size(), mouseInputs.data(), sizeof(INPUT));
    std::this_thread::sleep_for(input_delay);
  }
}

int aclicker::ParseAndSendInputToOS(int argc, std::span<std::string> argv) {
  using namespace std::literals;
  constexpr auto wait_time = 2000ms;

  try {
    int num_clicks = std::stoi(argv[1]);
    if (num_clicks < 1) {
      std::println(std::cerr, "Error: Input must be positive");
      std::exit(-1);
    }

    std::println("Will send: {} clicks to cursor in {}", num_clicks, wait_time);
    std::this_thread::sleep_for(wait_time);
    SendLeftClicks(num_clicks);
  } catch (const std::invalid_argument &e) {
    std::println("{}", e.what());
  } catch (const std::out_of_range &e) {
    std::println("{}", e.what());
  }

  return 0;
}
