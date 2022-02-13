#include <napi.h>

Napi::Object do_BZ2_bzWrite(const Napi::CallbackInfo &info);
Napi::Object do_BZ2_bzWriteClose(const Napi::CallbackInfo &info);
Napi::Object do_BZ2_bzWriteOpen(const Napi::CallbackInfo &info);

Napi::Object do_getgrgid(const Napi::CallbackInfo &info);
Napi::Object do_getpwuid(const Napi::CallbackInfo &info);