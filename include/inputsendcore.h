#pragma once
#include <chrono>
#include <span>
#include <string>
#include <windows.h>
namespace aclicker {

void SendLeftClicks(int number_of_clicks = 1, std::chrono::milliseconds delay_between_clicks_ms = std::chrono::milliseconds(25),
                    std::chrono::milliseconds start_delay = std::chrono::milliseconds(3000));
int ParseAndSendInputToOS(int argc, std::span<std::string> argv);
} // namespace aclicker
