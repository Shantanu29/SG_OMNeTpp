// Lehrstuhl fuer Energietransport und -speicherung
// UNIVERSITAET DUISBURG-ESSEN
//
// ef.Ruhr E-DeMa AP-2
//
// Wissenschaftlicher Mitarbeiter:
// Dipl.-Ing. Holger Kellerbauer
//
// Das Linklayer-Paket "powerline" umfasst eine Sammlung von Modulen, die zur Simulation von Powerline-
// Uebertragungsstrecken in intelligenten Energieverteilsystemen programmiert worden sind.
//
// Dieser Quellcode wurde erstellt von Dipl.-Ing. Holger Kellerbauer - er basiert auf dem INET Framework-Modul
// "Linklayer/Ethernet" von Andras Varga (c) 2003. Er ist gesitiges Eigentum des Lehrstuhles fuer Energietransport
// und -speicherung der Universitaet Duisburg-Essen, und darf ohne Genehmigung weder weitergegeben, noch verwendet
// werden.

channel CENELEC_A_Channel_v2
{
    @class(PowerlineChannel_v2);

    int typeOfChannel = 0;

    int PLCdelay16 = 264;
    int PLCdelay32 = 292;
    int PLCdelay64 = 347;
    int PLCdelay128 = 457;
    int PLCdelay220 = 617;
    
    int PLCdelay16_MAX = 211;
    int PLCdelay32_MAX = 225;
    int PLCdelay64_MAX = 253;
    int PLCdelay128_MAX = 308;
    int PLCdelay220_MAX = 388;
    
    int PLCdelay16_ROBO = 537;
    int PLCdelay32_ROBO = 599;
    int PLCdelay64_ROBO = 721;
    int PLCdelay128_ROBO = 966;
    int PLCdelay220_ROBO = 1318;

    double myPER = default(0);

    double delay = 0;
    double datarate = 0.0;
    double ber = 0;
    double per = 0;
    bool disabled = false;
    @display("ls=red,,s;t=CENELEC_A_Channel,t");
}
