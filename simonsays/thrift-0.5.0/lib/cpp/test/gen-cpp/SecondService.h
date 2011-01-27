/**
 * Autogenerated by Thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 */
#ifndef SecondService_H
#define SecondService_H

#include <TProcessor.h>
#include "ThriftTest_types.h"

namespace thrift { namespace test {

class SecondServiceIf {
 public:
  virtual ~SecondServiceIf() {}
  virtual void blahBlah() = 0;
};

class SecondServiceNull : virtual public SecondServiceIf {
 public:
  virtual ~SecondServiceNull() {}
  void blahBlah() {
    return;
  }
};


class SecondService_blahBlah_args {
 public:

  SecondService_blahBlah_args() {
  }

  virtual ~SecondService_blahBlah_args() throw() {}

  static ::apache::thrift::reflection::local::TypeSpec* local_reflection;


  bool operator == (const SecondService_blahBlah_args & /* rhs */) const
  {
    return true;
  }
  bool operator != (const SecondService_blahBlah_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const SecondService_blahBlah_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class SecondService_blahBlah_pargs {
 public:


  virtual ~SecondService_blahBlah_pargs() throw() {}

  static ::apache::thrift::reflection::local::TypeSpec* local_reflection;


  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class SecondService_blahBlah_result {
 public:

  SecondService_blahBlah_result() {
  }

  virtual ~SecondService_blahBlah_result() throw() {}

  static ::apache::thrift::reflection::local::TypeSpec* local_reflection;


  bool operator == (const SecondService_blahBlah_result & /* rhs */) const
  {
    return true;
  }
  bool operator != (const SecondService_blahBlah_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const SecondService_blahBlah_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class SecondService_blahBlah_presult {
 public:


  virtual ~SecondService_blahBlah_presult() throw() {}

  static ::apache::thrift::reflection::local::TypeSpec* local_reflection;


  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

class SecondServiceClient : virtual public SecondServiceIf {
 public:
  SecondServiceClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) :
    piprot_(prot),
    poprot_(prot) {
    iprot_ = prot.get();
    oprot_ = prot.get();
  }
  SecondServiceClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, boost::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) :
    piprot_(iprot),
    poprot_(oprot) {
    iprot_ = iprot.get();
    oprot_ = oprot.get();
  }
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> getInputProtocol() {
    return piprot_;
  }
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> getOutputProtocol() {
    return poprot_;
  }
  void blahBlah();
  void send_blahBlah();
  void recv_blahBlah();
 protected:
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> piprot_;
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> poprot_;
  ::apache::thrift::protocol::TProtocol* iprot_;
  ::apache::thrift::protocol::TProtocol* oprot_;
};

class SecondServiceProcessor : virtual public ::apache::thrift::TProcessor {
 protected:
  boost::shared_ptr<SecondServiceIf> iface_;
  virtual bool process_fn(::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, std::string& fname, int32_t seqid);
 private:
  std::map<std::string, void (SecondServiceProcessor::*)(int32_t, ::apache::thrift::protocol::TProtocol*, ::apache::thrift::protocol::TProtocol*)> processMap_;
  void process_blahBlah(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot);
 public:
  SecondServiceProcessor(boost::shared_ptr<SecondServiceIf> iface) :
    iface_(iface) {
    processMap_["blahBlah"] = &SecondServiceProcessor::process_blahBlah;
  }

  virtual bool process(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> piprot, boost::shared_ptr< ::apache::thrift::protocol::TProtocol> poprot);
  virtual ~SecondServiceProcessor() {}
};

class SecondServiceMultiface : virtual public SecondServiceIf {
 public:
  SecondServiceMultiface(std::vector<boost::shared_ptr<SecondServiceIf> >& ifaces) : ifaces_(ifaces) {
  }
  virtual ~SecondServiceMultiface() {}
 protected:
  std::vector<boost::shared_ptr<SecondServiceIf> > ifaces_;
  SecondServiceMultiface() {}
  void add(boost::shared_ptr<SecondServiceIf> iface) {
    ifaces_.push_back(iface);
  }
 public:
  void blahBlah() {
    uint32_t sz = ifaces_.size();
    for (uint32_t i = 0; i < sz; ++i) {
      ifaces_[i]->blahBlah();
    }
  }

};

}} // namespace

#endif
