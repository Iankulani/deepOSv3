#include "ip.h"

struct tcp_header {
    uint16_t src_port;
    uint16_t dst_port;
    uint32_t seq_num;
    // ... (other fields)
};

void send_tcp_packet(uint32_t dest_ip, uint16_t dest_port, const char* data) {
    struct tcp_header header;
    header.src_port = htons(8080);
    header.dst_port = htons(dest_port);
    // ... (fill other fields)
    
    ip_send(dest_ip, IP_PROTO_TCP, &header, sizeof(header));
}