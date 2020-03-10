#pragma once

#include <esp_err.h>
#include <esp_log.h>

#ifndef MIN
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#endif

#ifndef MAX
#define MAX(a, b) (((a) > (b)) ? (a) : (b))
#endif

#ifndef ESP_CHECK_RET
#define ESP_CHECK_RET(f)                                                                                    \
    {                                                                                                       \
        esp_err_t _ret = (f);                                                                               \
        if (_ret != ESP_OK)                                                                                 \
        {                                                                                                   \
            ESP_LOGE(LOG_TAG, "Error %s (0x%X) at %s:%d", esp_err_to_name(_ret), _ret, __FILE__, __LINE__); \
            return _ret;                                                                                    \
        }                                                                                                   \
    }
#endif

#ifndef STRING_BUFFER_STRUCT
#define STRING_BUFFER_STRUCT(name, val_len) \
    struct                                  \
    {                                       \
        char val[val_len];                  \
        size_t len;                         \
    } name;
#endif

#ifndef BYTE_BUFFER_STRUCT
#define BYTE_BUFFER_STRUCT(name, val_len) \
    struct                                \
    {                                     \
        uint8_t val[val_len];             \
        size_t len;                       \
    } name;
#endif