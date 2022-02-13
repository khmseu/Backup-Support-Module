#include "deduba_os.hh"
#include <bzlib.h>

typedef Napi::External<BZFILE> N_BZFILE;

void BZFILEfinalize(Napi::Env env, BZFILE *bzf)
{
    int dummy;
    BZ2_bzWriteClose(&dummy, bzf, 1, nullptr, nullptr);
}

Napi::Object BZFILEresult(const Napi::Env &env, BZFILE *bzf, N_BZFILE *obzf, int bzerror, int en)
{
    int dummy = 0;
    auto obj = Napi::Object::New(env);
    obj.Set("bzf", *obzf);
    obj.Set("bz2err", bzerror);
    auto es = BZ2_bzerror(bzf, &dummy);
    obj.Set("bz2errstr", es);
    if (bzerror == BZ_IO_ERROR)
    {
        obj.Set("syserrno", en);
        obj.Set("syserrstr", strerror(en));
    }
    return obj;
}

Napi::Object do_BZ2_bzWriteOpen(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    int bzerror = 0;
    auto f = fdopen(info[0].ToNumber().Unwrap().Int64Value(), "wb");
    auto result = BZ2_bzWriteOpen(&bzerror, f, 9, 0, 0);
    auto en = errno;
    auto obzf = N_BZFILE::New(env, result, &BZFILEfinalize);
    return BZFILEresult(env, result, &obzf, bzerror, en);
}

Napi::Object do_BZ2_bzWrite(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    int bzerror = 0;
    auto obzf = info[0];
    auto nbzf = static_cast<N_BZFILE *>(&obzf);
    auto bzf = nbzf->Data();
    auto obuf = info[1];
    auto nbuf = static_cast<Napi::Buffer<uint8_t> *>(&obuf);
    auto buf = nbuf->Data();
    auto len = nbuf->Length();
    BZ2_bzWrite(&bzerror, bzf, buf, len);
    auto en = errno;
    return BZFILEresult(env, nbzf, nbzf, bzerror, en);
}

Napi::Object do_BZ2_bzWriteClose(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    int bzerror = 0;
    auto obzf = info[0];
    auto nbzf = static_cast<N_BZFILE *>(&obzf);
    auto bzf = nbzf->Data();
    unsigned int nbytes_in_lo32 = 0;
    unsigned int nbytes_in_hi32 = 0;
    unsigned int nbytes_out_lo32 = 0;
    unsigned int nbytes_out_hi32 = 0;
    BZ2_bzWriteClose64(&bzerror, bzf, 0, &nbytes_in_lo32, &nbytes_out_hi32, &nbytes_out_lo32, &nbytes_out_hi32);
    auto en = errno;
    uint64_t nbytes_in = int64_t(nbytes_in_hi32) << 32 | nbytes_in_lo32;
    uint64_t nbytes_out = int64_t(nbytes_out_hi32) << 32 | nbytes_out_lo32;
    auto ret = BZFILEresult(env, nbzf, nbzf, bzerror, en);
    ret.Set("nbytes_in", nbytes_in);
    ret.Set("nbytes_out", nbytes_out);
    return ret;
}
