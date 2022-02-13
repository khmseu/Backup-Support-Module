#include <grp.h>
#include <napi.h>
#include <pwd.h>

Napi::Object do_getpwuid(const Napi::CallbackInfo &info)
{
  Napi::Env env = info.Env();
  auto pwd = getpwuid(info[0].ToNumber().Unwrap().Int64Value());
  auto obj = Napi::Object::New(env);
  obj.Set("name", pwd->pw_name);
  obj.Set("uid", pwd->pw_uid);
  obj.Set("gid", pwd->pw_gid);
  obj.Set("dir", pwd->pw_dir);
  obj.Set("shell", pwd->pw_shell);
  return obj;
}

Napi::Object do_getgrgid(const Napi::CallbackInfo &info)
{
  Napi::Env env = info.Env();
  auto grp = getgrgid(info[0].ToNumber().Unwrap().Int64Value());
  auto obj = Napi::Object::New(env);
  obj.Set("name", grp->gr_name);
  obj.Set("gid", grp->gr_gid);
  auto mem = Napi::Array::New(env);
  // char dbg[100];
  // for (size_t i = 0; i < 40; i++)
  // {
  //   sprintf(&dbg[i * 2], "%02x", *(((char *)grp->gr_mem) + i));
  // }
  // obj.Set("dbg", dbg);
  for (auto i = 0; grp->gr_mem[i]; i++)
  {
    mem.Set(i, grp->gr_mem[i]);
  }
  obj.Set("mem", mem);
  return obj;
}

Napi::Object Init(Napi::Env env, Napi::Object exports)
{
  exports.Set(Napi::String::New(env, "getpwuid"),
              Napi::Function::New(env, do_getpwuid));
  exports.Set(Napi::String::New(env, "getgrgid"),
              Napi::Function::New(env, do_getgrgid));
  return exports;
}

NODE_API_MODULE(deduba_os, Init)