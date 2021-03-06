//
// Generated file, do not edit! Created by opp_msgc 4.3 from networklayer/bgpv4/BGPMessage/BGPUpdate.msg.
//

#ifndef _BGPUPDATE_M_H_
#define _BGPUPDATE_M_H_

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
#include "BGPHeader_m.h"
#include "BGPUpdatePathAttributes_m.h"
#include "IPv4Address.h"

const int BGP_EMPTY_UPDATE_OCTETS = 4;
// }}



/**
 * Struct generated from networklayer/bgpv4/BGPMessage/BGPUpdate.msg by opp_msgc.
 */
struct INET_API BGPUpdateWithdrawnRoutes
{
    BGPUpdateWithdrawnRoutes();
    unsigned char length;
    IPv4Address prefix;
};

void INET_API doPacking(cCommBuffer *b, BGPUpdateWithdrawnRoutes& a);
void INET_API doUnpacking(cCommBuffer *b, BGPUpdateWithdrawnRoutes& a);

/**
 * Struct generated from networklayer/bgpv4/BGPMessage/BGPUpdate.msg by opp_msgc.
 */
struct INET_API BGPUpdateNLRI
{
    BGPUpdateNLRI();
    unsigned char length;
    IPv4Address prefix;
};

void INET_API doPacking(cCommBuffer *b, BGPUpdateNLRI& a);
void INET_API doUnpacking(cCommBuffer *b, BGPUpdateNLRI& a);

/**
 * Class generated from <tt>networklayer/bgpv4/BGPMessage/BGPUpdate.msg</tt> by opp_msgc.
 * <pre>
 * class BGPUpdatePathAttributeList
 * {
 *     BGPUpdatePathAttributesOrigin origin; 
 *     BGPUpdatePathAttributesASPath asPath[]; 
 *     BGPUpdatePathAttributesNextHop nextHop; 
 *     BGPUpdatePathAttributesLocalPref localPref[]; 
 *     BGPUpdatePathAttributesAtomicAggregate atomicAggregate[]; 
 * }
 * </pre>
 */
class INET_API BGPUpdatePathAttributeList : public ::cObject
{
  protected:
    BGPUpdatePathAttributesOrigin origin_var;
    BGPUpdatePathAttributesASPath *asPath_var; // array ptr
    unsigned int asPath_arraysize;
    BGPUpdatePathAttributesNextHop nextHop_var;
    BGPUpdatePathAttributesLocalPref *localPref_var; // array ptr
    unsigned int localPref_arraysize;
    BGPUpdatePathAttributesAtomicAggregate *atomicAggregate_var; // array ptr
    unsigned int atomicAggregate_arraysize;

  private:
    void copy(const BGPUpdatePathAttributeList& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const BGPUpdatePathAttributeList&);

  public:
    BGPUpdatePathAttributeList();
    BGPUpdatePathAttributeList(const BGPUpdatePathAttributeList& other);
    virtual ~BGPUpdatePathAttributeList();
    BGPUpdatePathAttributeList& operator=(const BGPUpdatePathAttributeList& other);
    virtual BGPUpdatePathAttributeList *dup() const {return new BGPUpdatePathAttributeList(*this);}
    virtual void parsimPack(cCommBuffer *b);
    virtual void parsimUnpack(cCommBuffer *b);

    // field getter/setter methods
    virtual BGPUpdatePathAttributesOrigin& getOrigin();
    virtual const BGPUpdatePathAttributesOrigin& getOrigin() const {return const_cast<BGPUpdatePathAttributeList*>(this)->getOrigin();}
    virtual void setOrigin(const BGPUpdatePathAttributesOrigin& origin);
    virtual void setAsPathArraySize(unsigned int size);
    virtual unsigned int getAsPathArraySize() const;
    virtual BGPUpdatePathAttributesASPath& getAsPath(unsigned int k);
    virtual const BGPUpdatePathAttributesASPath& getAsPath(unsigned int k) const {return const_cast<BGPUpdatePathAttributeList*>(this)->getAsPath(k);}
    virtual void setAsPath(unsigned int k, const BGPUpdatePathAttributesASPath& asPath);
    virtual BGPUpdatePathAttributesNextHop& getNextHop();
    virtual const BGPUpdatePathAttributesNextHop& getNextHop() const {return const_cast<BGPUpdatePathAttributeList*>(this)->getNextHop();}
    virtual void setNextHop(const BGPUpdatePathAttributesNextHop& nextHop);
    virtual void setLocalPrefArraySize(unsigned int size);
    virtual unsigned int getLocalPrefArraySize() const;
    virtual BGPUpdatePathAttributesLocalPref& getLocalPref(unsigned int k);
    virtual const BGPUpdatePathAttributesLocalPref& getLocalPref(unsigned int k) const {return const_cast<BGPUpdatePathAttributeList*>(this)->getLocalPref(k);}
    virtual void setLocalPref(unsigned int k, const BGPUpdatePathAttributesLocalPref& localPref);
    virtual void setAtomicAggregateArraySize(unsigned int size);
    virtual unsigned int getAtomicAggregateArraySize() const;
    virtual BGPUpdatePathAttributesAtomicAggregate& getAtomicAggregate(unsigned int k);
    virtual const BGPUpdatePathAttributesAtomicAggregate& getAtomicAggregate(unsigned int k) const {return const_cast<BGPUpdatePathAttributeList*>(this)->getAtomicAggregate(k);}
    virtual void setAtomicAggregate(unsigned int k, const BGPUpdatePathAttributesAtomicAggregate& atomicAggregate);
};

inline void doPacking(cCommBuffer *b, BGPUpdatePathAttributeList& obj) {obj.parsimPack(b);}
inline void doUnpacking(cCommBuffer *b, BGPUpdatePathAttributeList& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>networklayer/bgpv4/BGPMessage/BGPUpdate.msg</tt> by opp_msgc.
 * <pre>
 * packet BGPUpdateMessage extends BGPHeader
 * {
 *     @customize(true);
 *     type = BGP_UPDATE;
 *     byteLength = BGP_HEADER_OCTETS + BGP_EMPTY_UPDATE_OCTETS;
 * 
 *     BGPUpdateWithdrawnRoutes withdrawnRoutes[];
 *     BGPUpdatePathAttributeList pathAttributeList[]; 
 *     BGPUpdateNLRI NLRI;
 * }
 * </pre>
 *
 * BGPUpdateMessage_Base is only useful if it gets subclassed, and BGPUpdateMessage is derived from it.
 * The minimum code to be written for BGPUpdateMessage is the following:
 *
 * <pre>
 * class INET_API BGPUpdateMessage : public BGPUpdateMessage_Base
 * {
 *   private:
 *     void copy(const BGPUpdateMessage& other) { ... }

 *   public:
 *     BGPUpdateMessage(const char *name=NULL, int kind=0) : BGPUpdateMessage_Base(name,kind) {}
 *     BGPUpdateMessage(const BGPUpdateMessage& other) : BGPUpdateMessage_Base(other) {copy(other);}
 *     BGPUpdateMessage& operator=(const BGPUpdateMessage& other) {if (this==&other) return *this; BGPUpdateMessage_Base::operator=(other); copy(other); return *this;}
 *     virtual BGPUpdateMessage *dup() const {return new BGPUpdateMessage(*this);}
 *     // ADD CODE HERE to redefine and implement pure virtual functions from BGPUpdateMessage_Base
 * };
 * </pre>
 *
 * The following should go into a .cc (.cpp) file:
 *
 * <pre>
 * Register_Class(BGPUpdateMessage);
 * </pre>
 */
class INET_API BGPUpdateMessage_Base : public ::BGPHeader
{
  protected:
    BGPUpdateWithdrawnRoutes *withdrawnRoutes_var; // array ptr
    unsigned int withdrawnRoutes_arraysize;
    BGPUpdatePathAttributeList *pathAttributeList_var; // array ptr
    unsigned int pathAttributeList_arraysize;
    BGPUpdateNLRI NLRI_var;

  private:
    void copy(const BGPUpdateMessage_Base& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const BGPUpdateMessage_Base&);
    // make constructors protected to avoid instantiation
    BGPUpdateMessage_Base(const char *name=NULL, int kind=0);
    BGPUpdateMessage_Base(const BGPUpdateMessage_Base& other);
    // make assignment operator protected to force the user override it
    BGPUpdateMessage_Base& operator=(const BGPUpdateMessage_Base& other);

  public:
    virtual ~BGPUpdateMessage_Base();
    virtual BGPUpdateMessage_Base *dup() const {throw cRuntimeError("You forgot to manually add a dup() function to class BGPUpdateMessage");}
    virtual void parsimPack(cCommBuffer *b);
    virtual void parsimUnpack(cCommBuffer *b);

    // field getter/setter methods
    virtual void setWithdrawnRoutesArraySize(unsigned int size);
    virtual unsigned int getWithdrawnRoutesArraySize() const;
    virtual BGPUpdateWithdrawnRoutes& getWithdrawnRoutes(unsigned int k);
    virtual const BGPUpdateWithdrawnRoutes& getWithdrawnRoutes(unsigned int k) const {return const_cast<BGPUpdateMessage_Base*>(this)->getWithdrawnRoutes(k);}
    virtual void setWithdrawnRoutes(unsigned int k, const BGPUpdateWithdrawnRoutes& withdrawnRoutes);
    virtual void setPathAttributeListArraySize(unsigned int size);
    virtual unsigned int getPathAttributeListArraySize() const;
    virtual BGPUpdatePathAttributeList& getPathAttributeList(unsigned int k);
    virtual const BGPUpdatePathAttributeList& getPathAttributeList(unsigned int k) const {return const_cast<BGPUpdateMessage_Base*>(this)->getPathAttributeList(k);}
    virtual void setPathAttributeList(unsigned int k, const BGPUpdatePathAttributeList& pathAttributeList);
    virtual BGPUpdateNLRI& getNLRI();
    virtual const BGPUpdateNLRI& getNLRI() const {return const_cast<BGPUpdateMessage_Base*>(this)->getNLRI();}
    virtual void setNLRI(const BGPUpdateNLRI& NLRI);
};


#endif // _BGPUPDATE_M_H_
