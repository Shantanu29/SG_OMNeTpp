//
// Copyright (C) 2005 Andras Varga
// Copyright (C) 2005 Wei Yang, Ng
//
// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public License
// as published by the Free Software Foundation; either version 2
// of the License, or (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public License
// along with this program; if not, see <http://www.gnu.org/licenses/>.
//
// Edited with OMNeT++ Academic/Noncommercial Edition.
//
package inet.nodes.ipv6;

import inet.networklayer.ipv6.IPv6ErrorHandling;
import inet.networklayer.ipv6.IPv6;
import inet.networklayer.icmpv6.IPv6NeighbourDiscovery;
import inet.networklayer.icmpv6.ICMPv6;
import inet.networklayer.IxMIPv6Support;
import inet.networklayer.IIPv6Tunneling;
import inet.base.IHook;
// including the 6LoWPAN wrapper
import inet.networklayer.ipv6._6lowpan._6lowpan;

//
// Represents an IPv6 network layer (L3).
//
// The module has ports to connect to a higher layer (TCP, UDP) and
// several network interfaces.
//
module NetworkLayer6
{
    parameters:
        bool xMIPv6Support = default(false);
        @display("i=block/fork");
    gates:
        input ifIn[] @labels(IPv6Datagram);
        output ifOut[] @labels(IPv6Datagram);
        input sctpIn @labels(IPv4ControlInfo/down,SCTPPacket);
        output sctpOut @labels(IPv4ControlInfo/up,SCTPPacket);
        input tcpIn @labels(TCPSegment,IPv6ControlInfo/down);
        output tcpOut @labels(TCPSegment,IPv6ControlInfo/up);
        input udpIn @labels(UDPPacket,IPv6ControlInfo/down);
        output udpOut @labels(UDPPacket,IPv6ControlInfo/up);
        input rsvpIn @labels(IPv6ControlInfo/down);
        output rsvpOut @labels(IPv6ControlInfo/up);
        input ospfIn @labels(IPv6ControlInfo/down);
        output ospfOut @labels(IPv6ControlInfo/up);
        input pingIn[];
        output pingOut[];
    submodules:
        ipv6: IPv6 {
            parameters:
                protocolMapping = "6:0,17:1,46:2,89:3,132:4"; // TODO register 132 as sctp in ipv6 code
                @display("p=135,150");
            gates:
                transportIn[5];
                transportOut[5];
                queueIn[sizeof(ifIn)];
                queueOut[sizeof(ifIn)];
        }
        icmpv6: ICMPv6 {
            parameters:
                @display("p=197,79");
        }
        ipv6ErrorHandling: IPv6ErrorHandling {
            parameters:
                @display("p=280,79");
        }
        neighbourDiscovery: IPv6NeighbourDiscovery {
            parameters:
                minIntervalBetweenRAs = 10s;
                maxIntervalBetweenRAs = 20s;
                @display("p=257,149");
        }
        iptunneling: <default(firstAvailable("IPv6Tunneling","IPv6Tunneling_None"))> like IIPv6Tunneling {
            parameters:
                @display("p=44,168");
        }
        mipv6support: <default(xMIPv6Support?"xMIPv6Support":"xMIPv6Support_None")> like IxMIPv6Support {
            parameters:
                @display("p=44,79");
        }
        sixlowpan: _6lowpan {
            @display("p=135,251;is=s");
            gates:
                fromIPv6[sizeof(ifIn)];
                toIPv6[sizeof(ifIn)];
                fromMac[sizeof(ifIn)];
                toMac[sizeof(ifIn)];
        }
    connections allowunconnected:  // FIXME remove 'nocheck'!
        // IPv6 to transport Layer
        ipv6.transportOut[0] --> { @display("m=n"); } --> tcpOut;
        ipv6.transportIn[0] <-- { @display("m=n"); } <-- tcpIn;

        ipv6.transportOut[1] --> { @display("m=n"); } --> udpOut;
        ipv6.transportIn[1] <-- { @display("m=n"); } <-- udpIn;

        ipv6.transportOut[2] --> { @display("m=n"); } --> rsvpOut;
        ipv6.transportIn[2] <-- { @display("m=n"); } <-- rsvpIn;

        ipv6.transportOut[3] --> { @display("m=n"); } --> ospfOut;
        ipv6.transportIn[3] <-- { @display("m=n"); } <-- ospfIn;

        ipv6.transportOut[4] --> { @display("m=n"); } --> sctpOut;
        ipv6.transportIn[4] <-- { @display("m=n"); } <-- sctpIn;

        // IPv6 to IPv6 Tunneling
        iptunneling.upperLayerIn <-- ipv6.upperTunnelingOut;
        iptunneling.upperLayerOut --> ipv6.upperTunnelingIn;
        iptunneling.linkLayerIn <-- ipv6.lowerTunnelingOut;
        iptunneling.linkLayerOut --> ipv6.lowerTunnelingIn;

        // IPv6 to ICMPv6
        ipv6.icmpOut --> icmpv6.ipv6In;
        ipv6.icmpIn <-- icmpv6.ipv6Out;

        // ICMPv6 to IPv6ErrorHandling
        icmpv6.errorOut --> ipv6ErrorHandling.in;

        // ICMPv6 to ping I/O
        for i=0..sizeof(pingOut)-1 {
            icmpv6.pingOut++ --> { @display("m=n"); } --> pingOut[i];
        }
        for i=0..sizeof(pingIn)-1 {
            icmpv6.pingIn++ <-- { @display("m=n"); } <-- pingIn[i];
        }

        // IPv6 to Neighbour Discovery
        ipv6.ndOut --> neighbourDiscovery.ipv6In;
        ipv6.ndIn <-- neighbourDiscovery.ipv6Out;

        //IPv6 to Mobile IPv6
        ipv6.xMIPv6Out --> mipv6support.fromIPv6;
        ipv6.xMIPv6In <-- mipv6support.toIPv6;

//        // IPv6 to L2 (original)
//        for i=0..sizeof(ifIn)-1 {
//            ifIn[i] --> { @display("m=s"); } --> ipv6.queueIn[i];
//        }
//        for i=0..sizeof(ifOut)-1 {
//            ipv6.queueOut[i] --> { @display("m=s"); } --> ifOut[i];
//        }
		// IPv6 to L2 (with 6LoWPAN integration)
        for i=0..sizeof(ifIn)-1 {
            ifIn[i] --> sixlowpan.fromMac[i];
            sixlowpan.toIPv6[i] --> { @display("m=s"); } --> ipv6.queueIn[i];
        }
        for i=0..sizeof(ifOut)-1 {
            ipv6.queueOut[i] --> sixlowpan.fromIPv6[i];
            sixlowpan.toMac[i] --> { @display("m=s"); } --> ifOut[i];
        }
}

