//
// Generated file, do not edit! Created by opp_msgc 4.3 from linklayer/rstp/bpdu.msg.
//

#ifndef _BPDU_M_H_
#define _BPDU_M_H_

#include <omnetpp.h>

// opp_msgc version check
#define MSGC_VERSION 0x0403
#if (MSGC_VERSION!=OMNETPP_VERSION)
#    error Version mismatch! Probably this file was generated by an earlier version of opp_msgc: 'make clean' should help.
#endif

// dll export symbol
#ifndef INET_API 
#  if defined(INET_EXPORT)
#    define INET_API  OPP_DLLEXPORT
#  elif defined(INET_IMPORT)
#    define INET_API  OPP_DLLIMPORT
#  else
#    define INET_API 
#  endif
#endif

// cplusplus {{
#include "STPDefinitions.h"
// }}



/**
 * Class generated from <tt>linklayer/rstp/bpdu.msg</tt> by opp_msgc.
 * <pre>
 * packet BPDU {
 *     BPDUType type;
 *     BridgeID rootBID;
 *     int rootPathCost;
 *     BridgeID senderBID;
 *     int portId;
 *     int messageAge;
 *     int maxAge;
 *     int helloTime;
 *     int forwardDelay;
 *     bool topologyChangeFlag;
 *     bool ackFlag;
 *     bool proposal;
 *     bool agreement;
 *     PortRole portRole;
 *     bool learning;
 *     bool forwarding;
 * };
 * </pre>
 */
class INET_API BPDU : public ::cPacket
{
  protected:
    BPDUType type_var;
    BridgeID rootBID_var;
    int rootPathCost_var;
    BridgeID senderBID_var;
    int portId_var;
    int messageAge_var;
    int maxAge_var;
    int helloTime_var;
    int forwardDelay_var;
    bool topologyChangeFlag_var;
    bool ackFlag_var;
    bool proposal_var;
    bool agreement_var;
    PortRole portRole_var;
    bool learning_var;
    bool forwarding_var;

  private:
    void copy(const BPDU& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const BPDU&);

  public:
    BPDU(const char *name=NULL, int kind=0);
    BPDU(const BPDU& other);
    virtual ~BPDU();
    BPDU& operator=(const BPDU& other);
    virtual BPDU *dup() const {return new BPDU(*this);}
    virtual void parsimPack(cCommBuffer *b);
    virtual void parsimUnpack(cCommBuffer *b);

    // field getter/setter methods
    virtual BPDUType& getType();
    virtual const BPDUType& getType() const {return const_cast<BPDU*>(this)->getType();}
    virtual void setType(const BPDUType& type);
    virtual BridgeID& getRootBID();
    virtual const BridgeID& getRootBID() const {return const_cast<BPDU*>(this)->getRootBID();}
    virtual void setRootBID(const BridgeID& rootBID);
    virtual int getRootPathCost() const;
    virtual void setRootPathCost(int rootPathCost);
    virtual BridgeID& getSenderBID();
    virtual const BridgeID& getSenderBID() const {return const_cast<BPDU*>(this)->getSenderBID();}
    virtual void setSenderBID(const BridgeID& senderBID);
    virtual int getPortId() const;
    virtual void setPortId(int portId);
    virtual int getMessageAge() const;
    virtual void setMessageAge(int messageAge);
    virtual int getMaxAge() const;
    virtual void setMaxAge(int maxAge);
    virtual int getHelloTime() const;
    virtual void setHelloTime(int helloTime);
    virtual int getForwardDelay() const;
    virtual void setForwardDelay(int forwardDelay);
    virtual bool getTopologyChangeFlag() const;
    virtual void setTopologyChangeFlag(bool topologyChangeFlag);
    virtual bool getAckFlag() const;
    virtual void setAckFlag(bool ackFlag);
    virtual bool getProposal() const;
    virtual void setProposal(bool proposal);
    virtual bool getAgreement() const;
    virtual void setAgreement(bool agreement);
    virtual PortRole& getPortRole();
    virtual const PortRole& getPortRole() const {return const_cast<BPDU*>(this)->getPortRole();}
    virtual void setPortRole(const PortRole& portRole);
    virtual bool getLearning() const;
    virtual void setLearning(bool learning);
    virtual bool getForwarding() const;
    virtual void setForwarding(bool forwarding);
};

inline void doPacking(cCommBuffer *b, BPDU& obj) {obj.parsimPack(b);}
inline void doUnpacking(cCommBuffer *b, BPDU& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>linklayer/rstp/bpdu.msg</tt> by opp_msgc.
 * <pre>
 * packet CBPDU extends BPDU {
 *     type = CONF_BPDU;
 * };
 * </pre>
 */
class INET_API CBPDU : public ::BPDU
{
  protected:

  private:
    void copy(const CBPDU& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const CBPDU&);

  public:
    CBPDU(const char *name=NULL, int kind=0);
    CBPDU(const CBPDU& other);
    virtual ~CBPDU();
    CBPDU& operator=(const CBPDU& other);
    virtual CBPDU *dup() const {return new CBPDU(*this);}
    virtual void parsimPack(cCommBuffer *b);
    virtual void parsimUnpack(cCommBuffer *b);

    // field getter/setter methods
};

inline void doPacking(cCommBuffer *b, CBPDU& obj) {obj.parsimPack(b);}
inline void doUnpacking(cCommBuffer *b, CBPDU& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>linklayer/rstp/bpdu.msg</tt> by opp_msgc.
 * <pre>
 * packet TCNBPDU extends BPDU {
 *     type = TCN_BPDU;
 * };
 * </pre>
 */
class INET_API TCNBPDU : public ::BPDU
{
  protected:

  private:
    void copy(const TCNBPDU& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const TCNBPDU&);

  public:
    TCNBPDU(const char *name=NULL, int kind=0);
    TCNBPDU(const TCNBPDU& other);
    virtual ~TCNBPDU();
    TCNBPDU& operator=(const TCNBPDU& other);
    virtual TCNBPDU *dup() const {return new TCNBPDU(*this);}
    virtual void parsimPack(cCommBuffer *b);
    virtual void parsimUnpack(cCommBuffer *b);

    // field getter/setter methods
};

inline void doPacking(cCommBuffer *b, TCNBPDU& obj) {obj.parsimPack(b);}
inline void doUnpacking(cCommBuffer *b, TCNBPDU& obj) {obj.parsimUnpack(b);}


#endif // _BPDU_M_H_
