#include "deduba_os.hh"

#define EXPORT(func) exports.Set(Napi::String::New(env, #func), Napi::Function::New(env, do_##func));

Napi::Object Init(Napi::Env env, Napi::Object exports)
{
  EXPORT(BZ2_bzWrite);
  EXPORT(BZ2_bzWriteClose);
  EXPORT(BZ2_bzWriteOpen);
  EXPORT(getgrgid);
  EXPORT(getpwuid);
  return exports;
}

NODE_API_MODULE(deduba_os, Init)