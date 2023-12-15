// debug.h
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#pragma once
#ifndef TRACE_DEBUG_H
#define TRACE_DEBUG_H

#ifdef TRACE_ENABLED
#include <spdlog/spdlog.h>
#define TRACE(msg) spdlog::info(msg);
#else
#define TRACE(msg)
#endif

#endif
