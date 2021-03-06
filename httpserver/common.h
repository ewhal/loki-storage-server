#pragma once

struct sn_record_t {
    uint16_t port;
    std::string address; // Snode address
};

namespace std {

    template<>
    struct hash<sn_record_t>
    {
        std::size_t operator()(const sn_record_t& k) const {
#ifdef INTEGRATION_TEST
            return hash<uint16_t>{}(k.port);
#else
            return hash<std::string>{}(k.address);
#endif
        }
    };

}

static std::ostream& operator<<(std::ostream& os, const sn_record_t& sn) {
#ifdef INTEGRATION_TEST
    return os << sn.port;
#else
    return os << sn.address;
#endif
}

static bool operator==(const sn_record_t& lhs, const sn_record_t& rhs) {
#ifdef INTEGRATION_TEST
    return lhs.port == rhs.port;
#else
    return lhs.address == rhs.address;
#endif
}

static bool operator!=(const sn_record_t& lhs, const sn_record_t& rhs) {
    return !operator==(lhs, rhs);
}

using swarm_id_t = uint64_t;
