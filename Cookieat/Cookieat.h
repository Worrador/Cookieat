// Cookieat.h : Include file for standard system include files,
// or project specific include files.

#pragma once

#include <iostream>
#include <OpenXLSX.hpp>
#include <nowide/iostream.hpp>
#include <conio.h>
#include <random>
#include <windows.h>

// TODO: Reference additional headers your program requires here.
inline std::mt19937 randomNumberGenerator(std::random_device{}());