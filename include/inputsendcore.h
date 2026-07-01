#pragma once
#include <chrono>
#include <span>
#include <string>
#include <windows.h>
namespace aclicker {

void SendLeftClicks(int n = 1, std::chrono::milliseconds input_delay =
                                   std::chrono::milliseconds(25));
int ParseAndSendInputToOS(int argc, std::span<std::string> argv);
} // namespace aclicker
