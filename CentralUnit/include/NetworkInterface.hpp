#pragma once

#include <string>

namespace SH
{
    class NetworkInterface
    {
    public:
        virtual string receive() const = delete;
        virtual string send(const string &data) const = delete;
        virtual string ping() const = delete; // is it needed?
        // TODO add more network methods
        // TODO add move constructor here and other classes if needed
    };
} // namespace SH
