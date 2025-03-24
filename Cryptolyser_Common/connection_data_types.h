#ifndef CRYPTOLYSER_CONNECTION_DATA_TYPES_H
#define CRYPTOLYSER_CONNECTION_DATA_TYPES_H

#include <stdint.h>

#define CONNECTION_DATA_MAX_SIZE (1024 - 3 * sizeof(uint32_t))

#pragma pack(1)
struct connection_packet_t
{
    uint32_t packet_id;
    uint32_t data_length;
    uint8_t byte_data[CONNECTION_DATA_MAX_SIZE];
};
#pragma pack(0)

#define PACKET_KEY_BYTE_SIZE 16
#define AES_BLOCK_BYTE_SIZE 16
#pragma pack(1)
struct connection_key_packet_t
{
    uint32_t packet_id;
    uint8_t key[PACKET_KEY_BYTE_SIZE];
    uint32_t data_length;
    uint8_t byte_data[CONNECTION_DATA_MAX_SIZE];
};
#pragma pack(0)

#define PACKET_RESPONSE_DATA_SIZE AES_BLOCK_BYTE_SIZE
#pragma pack(1)
struct connection_response_t
{
    uint32_t packet_id;
    uint8_t data[PACKET_RESPONSE_DATA_SIZE];
    uint64_t inbound_t1;
    uint64_t inbound_t2;
    uint64_t outbound_t1;
    uint64_t outbound_t2;
};
#pragma pack(0)

#endif // CRYPTOLYSER_CONNECTION_DATA_TYPES_H
