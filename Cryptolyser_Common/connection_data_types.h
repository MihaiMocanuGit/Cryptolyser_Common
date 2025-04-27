#pragma once

#include <stdint.h>

#define CONNECTION_DATA_MAX_SIZE (1024 - 3 * sizeof(uint32_t))
#define PACKET_KEY_BYTE_SIZE 16
#define AES_BLOCK_BYTE_SIZE 16
#define PACKET_RESPONSE_DATA_SIZE AES_BLOCK_BYTE_SIZE

static_assert(true); // dummy declaration, ends the preamble https://stackoverflow.com/a/72907523
                     // (Known bug in clangd causes "1. Unterminated '#pragma pack (push, ...)' at
                     // end of file [-Wpragma-pack]" warning.
#pragma pack(push, 1)

struct connection_packet_t
{
    uint32_t packet_id;
    uint32_t data_length;
    uint8_t byte_data[CONNECTION_DATA_MAX_SIZE];
};

struct connection_key_packet_t
{
    uint32_t packet_id;
    uint8_t key[PACKET_KEY_BYTE_SIZE];
    uint32_t data_length;
    uint8_t byte_data[CONNECTION_DATA_MAX_SIZE];
};

struct connection_response_t
{
    uint32_t packet_id;
    uint8_t data[PACKET_RESPONSE_DATA_SIZE];
    uint64_t inbound_t1;
    uint64_t inbound_t2;
    uint64_t outbound_t1;
    uint64_t outbound_t2;
};

#pragma pack(pop)
