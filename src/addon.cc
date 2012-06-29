#define BUILDING_NODE_EXTENSION
#include <node.h>
#include "navro.h"

using namespace v8;

void InitAll(Handle<Object> target) {
  NAvro::Init(target);
}

NODE_MODULE(navro, InitAll)
