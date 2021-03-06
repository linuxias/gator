/* Copyright (C) 2019-2020 by Arm Limited. All rights reserved. */

#ifndef ARMNN_PACKETENCODER_H_
#define ARMNN_PACKETENCODER_H_
#include "armnn/ByteOrder.h"
#include "armnn/IEncoder.h"
#include "armnn/PacketUtility.h"
#include "armnn/PacketUtilityModels.h"

#include <map>
#include <set>
#include <vector>

namespace armnn {
    class PacketEncoder : public IEncoder {
    public:
        PacketEncoder(ByteOrder byteOrder);

        // IEncoder:
        std::vector<std::uint8_t> encodePeriodicCounterSelectionRequest(
            std::uint32_t period,
            const std::set<std::uint16_t> & eventUids) override;
        std::vector<std::uint8_t> encodePerJobCounterSelectionRequest(
            std::uint64_t objectId,
            const std::set<std::uint16_t> & eventUids) override;
        std::vector<std::uint8_t> encodeConnectionAcknowledge() override;
        std::vector<std::uint8_t> encodeCounterDirectoryRequest() override;
        std::vector<std::uint8_t> encodeActivateTimelineReportingPacket() override;
        std::vector<std::uint8_t> encodeDeactivateTimelineReportingPacket() override;

        /**
         * Currently support 1.x.x version of packet decoders only.
         */
        static bool isValidPacketVersions(const std::vector<PacketVersionTable> & pktVersionTable);

    private:
        ByteOrder byteOrder;
        void appendHeader(std::uint32_t packetIdentifier,
                          std::uint32_t dataLength,
                          std::vector<std::uint8_t> & payload);
    };

} /* namespace armnn */

#endif /* ARMNN_PACKETENCODER_H_ */
