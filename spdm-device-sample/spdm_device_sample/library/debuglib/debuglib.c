/**
 *  Copyright Notice:
 *  Copyright 2021-2022 DMTF. All rights reserved.
 *  License: BSD 3-Clause License. For full text see link: https://github.com/DMTF/libspdm/blob/main/LICENSE.md
 **/

#include <base.h>

#include "library/debuglib.h"

void libspdm_debug_assert(const char *file_name, size_t line_number,
                          const char *description)
{
    LIBSPDM_ASSERT(false);
}

void libspdm_debug_print(size_t error_level, const char *format, ...)
{
    LIBSPDM_ASSERT(false);
}
