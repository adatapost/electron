// Copyright (c) 2019 GitHub, Inc.
// Use of this source code is governed by the MIT license that can be
// found in the LICENSE file.

#include "base/command_line.h"
#include "native_mate/converter.h"
#include "native_mate/dictionary.h"

#include "atom/common/node_includes.h"

namespace {

bool HasSwitch(const base::CommandLine::StringType& name) {
  return base::CommandLine::ForCurrentProcess()->HasSwitch(name);
}

base::CommandLine::StringType GetSwitchValue(
    const base::CommandLine::StringType& name) {
  return base::CommandLine::ForCurrentProcess()->GetSwitchValueNative(name);
}

void Initialize(v8::Local<v8::Object> exports,
                v8::Local<v8::Value> unused,
                v8::Local<v8::Context> context,
                void* priv) {
  mate::Dictionary dict(context->GetIsolate(), exports);
  dict.SetMethod("hasSwitch", &HasSwitch);
  dict.SetMethod("getSwitchValue", &GetSwitchValue);
}

}  // namespace

NODE_BUILTIN_MODULE_CONTEXT_AWARE(atom_common_command_line, Initialize)
