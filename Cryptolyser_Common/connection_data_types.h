#pragma once

#ifndef __cplusplus

#include <stdint.h>

#define PACKET_BYTE_DATA_SIZE 256
#define PACKET_KEY_SIZE 16
#define PACKET_AES_BLOCK_SIZE 16
#define RESPONSE_DATA_SIZE PACKET_AES_BLOCK_SIZE

enum packet_type_e
{
    packet_type_e_ECB = 0,
    packet_type_e_CBC = 1,
    packet_type_e_CTR = 2,
    packet_type_e_COUNT,
};

static const char *const packet_type_names[packet_type_e_COUNT] = {"ECB", "CBC", "CTR"};

#else

#include <array>
#include <cstdint>
#include <string_view>

constexpr unsigned PACKET_BYTE_DATA_SIZE {256u};
constexpr unsigned PACKET_KEY_SIZE {16u};
constexpr unsigned PACKET_AES_BLOCK_SIZE {16u};
constexpr unsigned RESPONSE_DATA_SIZE {PACKET_AES_BLOCK_SIZE};

enum class packet_type_e : uint8_t
{
    ECB = 0,
    CBC = 1,
    CTR = 2,
    COUNT,
};

constexpr std::array<const std::string_view, static_cast<uint8_t>(packet_type_e::COUNT)>
    packet_type_names = {"ECB", "CBC", "CTR"};

// It is not needed in this case as it only contains structs. Nevertheless, it is kept to highlight
// intent.
extern "C"
{
#endif

#pragma pack(push, 1)
// Be careful with the order of members. Maximise the number of well alligned (to 4 bytes)
// variables.

struct connection_packet_t
{
    uint32_t packet_id;
    uint32_t data_length;
    uint8_t byte_data[PACKET_BYTE_DATA_SIZE];
    uint8_t packet_type;
    uint8_t key[PACKET_KEY_SIZE];
};

struct connection_response_t
{
    uint32_t packet_id;
    uint64_t inbound_t1;
    uint64_t inbound_t2;
    uint64_t outbound_t1;
    uint64_t outbound_t2;
    uint8_t data[RESPONSE_DATA_SIZE];
    uint8_t iv[PACKET_AES_BLOCK_SIZE];
};

#pragma pack(pop)

#ifdef __cplusplus
}
#endif
