#ifndef NAVRO_H
#define NAVRO_H

#include <node.h>

#include "avro/Compiler.hh"
#include "avro/Encoder.hh"
#include "avro/Decoder.hh"
#include "avro/Specific.hh"

class NAvro : public node::ObjectWrap {
 public:
  static void Init(v8::Handle<v8::Object> target);

 private:
  NAvro();
  ~NAvro();

  static v8::Handle<v8::Value> New(const v8::Arguments& args);
  static v8::Handle<v8::Value> Encode(const v8::Arguments& args);
  avro::ValidSchema schema;
};

#endif
