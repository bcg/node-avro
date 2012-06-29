#define BUILDING_NODE_EXTENSION
#include <node.h>
#include "navro.h"

#include "avro/Compiler.hh"
#include "avro/Encoder.hh"
#include "avro/Decoder.hh"
#include "avro/Specific.hh"

using namespace v8;

NAvro::NAvro() {};
NAvro::~NAvro() {};

void NAvro::Init(Handle<Object> target) {
  // Prepare constructor template
  Local<FunctionTemplate> tpl = FunctionTemplate::New(New);
  tpl->SetClassName(String::NewSymbol("NAvro"));
  tpl->InstanceTemplate()->SetInternalFieldCount(1);
  // Prototype
  tpl->PrototypeTemplate()->Set(String::NewSymbol("encode"),
      FunctionTemplate::New(Encode)->GetFunction());

  Persistent<Function> constructor = Persistent<Function>::New(tpl->GetFunction());
  target->Set(String::NewSymbol("NAvro"), constructor);
}

Handle<Value> NAvro::New(const Arguments& args) {
  HandleScope scope;

  v8::String::Utf8Value param1(args[0]->ToString());
  std::string schemastr = std::string(*param1);

  NAvro* obj = new NAvro();
  avro::ValidSchema cpxSchema;
  //obj->schema = avro::compileJsonSchemaFromString(schemastr);
  obj->Wrap(args.This());

  return args.This();
}

Handle<Value> NAvro::Encode(const Arguments& args) {
  HandleScope scope;

  NAvro* obj = ObjectWrap::Unwrap<NAvro>(args.This());
  //obj->counter_ += 1;

  return args.This();
}
