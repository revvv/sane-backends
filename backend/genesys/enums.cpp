/* sane - Scanner Access Now Easy.

   Copyright (C) 2019 Povilas Kanapickas <povilas@radix.lt>

   This file is part of the SANE package.

   This program is free software; you can redistribute it and/or
   modify it under the terms of the GNU General Public License as
   published by the Free Software Foundation; either version 2 of the
   License, or (at your option) any later version.

   This program is distributed in the hope that it will be useful, but
   WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 59 Temple Place - Suite 330, Boston,
   MA 02111-1307, USA.

   As a special exception, the authors of SANE give permission for
   additional uses of the libraries contained in this release of SANE.

   The exception is that, if you link a SANE library with other files
   to produce an executable, this does not by itself cause the
   resulting executable to be covered by the GNU General Public
   License.  Your use of that executable is in no way restricted on
   account of linking the SANE library code into it.

   This exception does not, however, invalidate any other reasons why
   the executable file might be covered by the GNU General Public
   License.

   If you submit changes to SANE to the maintainers to be included in
   a subsequent release, you agree by submitting the changes that
   those changes may be distributed with this exception intact.

   If you write modifications of your own for SANE, it is your choice
   whether to permit this exception to apply to your modifications.
   If you do not wish that, delete this exception notice.
*/

#define DEBUG_DECLARE_ONLY

#include "enums.h"
#include "genesys.h"
#include <iomanip>

namespace genesys {

const char* scan_method_to_option_string(ScanMethod method)
{
    switch (method) {
        case ScanMethod::FLATBED: return STR_FLATBED;
        case ScanMethod::TRANSPARENCY: return STR_TRANSPARENCY_ADAPTER;
        case ScanMethod::TRANSPARENCY_INFRARED: return STR_TRANSPARENCY_ADAPTER_INFRARED;
    }
    throw SaneException("Unknown scan method %d", static_cast<unsigned>(method));
}

ScanMethod option_string_to_scan_method(const std::string& str)
{
    if (str == STR_FLATBED) {
        return ScanMethod::FLATBED;
    } else if (str == STR_TRANSPARENCY_ADAPTER) {
        return ScanMethod::TRANSPARENCY;
    } else if (str == STR_TRANSPARENCY_ADAPTER_INFRARED) {
        return ScanMethod::TRANSPARENCY_INFRARED;
    }
    throw SaneException("Unknown scan method option %s", str.c_str());
}

const char* scan_color_mode_to_option_string(ScanColorMode mode)
{
    switch (mode) {
        case ScanColorMode::COLOR_SINGLE_PASS: return SANE_VALUE_SCAN_MODE_COLOR;
        case ScanColorMode::GRAY: return SANE_VALUE_SCAN_MODE_GRAY;
        case ScanColorMode::HALFTONE: return SANE_VALUE_SCAN_MODE_HALFTONE;
        case ScanColorMode::LINEART: return SANE_VALUE_SCAN_MODE_LINEART;
    }
    throw SaneException("Unknown scan mode %d", static_cast<unsigned>(mode));
}

ScanColorMode option_string_to_scan_color_mode(const std::string& str)
{
    if (str == SANE_VALUE_SCAN_MODE_COLOR) {
        return ScanColorMode::COLOR_SINGLE_PASS;
    } else if (str == SANE_VALUE_SCAN_MODE_GRAY) {
        return ScanColorMode::GRAY;
    } else if (str == SANE_VALUE_SCAN_MODE_HALFTONE) {
        return ScanColorMode::HALFTONE;
    } else if (str == SANE_VALUE_SCAN_MODE_LINEART) {
        return ScanColorMode::LINEART;
    }
    throw SaneException("Unknown scan color mode %s", str.c_str());
}


std::ostream& operator<<(std::ostream& out, ColorFilter mode)
{
    switch (mode) {
        case ColorFilter::RED: out << "RED"; break;
        case ColorFilter::GREEN: out << "GREEN"; break;
        case ColorFilter::BLUE: out << "BLUE"; break;
        case ColorFilter::NONE: out << "NONE"; break;
        default: out << static_cast<unsigned>(mode); break;
    }
    return out;
}

std::ostream& operator<<(std::ostream& out, StepType type)
{
    switch (type) {
        case StepType::FULL: out << "1/1"; break;
        case StepType::HALF: out << "1/2"; break;
        case StepType::QUARTER: out << "1/4"; break;
        case StepType::EIGHTH: out << "1/8"; break;
        default: out << static_cast<unsigned>(type); break;
    }
    return out;
}

std::ostream& operator<<(std::ostream& out, ScanFlag flags)
{
    StreamStateSaver state_saver{out};
    out << "0x" << std::hex << static_cast<unsigned>(flags);
    return out;
}

} // namespace genesys