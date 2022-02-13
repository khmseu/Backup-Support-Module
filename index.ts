// Will load a compiled build if present or a prebuild.
// If no build if found it will throw an exception
var binding = require("node-gyp-build")(__dirname);

// module.exports = binding;

export function getpwuid(user: number): {
  name: string;
  uid: number;
  gid: number;
  dir: string;
  shell: string;
} {
  return binding.getpwuid(user);
}
export function getgrgid(group: number): {
  name: string;
  gid: number;
  mem: Array<string>;
} {
  return binding.getgrgid(group);
}
const isBZFILE = Symbol("isBZFILE");
type BZFILE = { [isBZFILE]: true };
export function BZ2_bzWriteOpen(f: number): {
  bzf: BZFILE;
  bz2err: number;
  bz2errstr: string;
  syserrno?: number;
  syserrstr?: string;
} {
  return binding.BZ2_bzWriteOpen(f);
}
export function BZ2_bzWrite(
  b: BZFILE,
  buf: Buffer
): {
  bzf: BZFILE;
  bz2err: number;
  bz2errstr: string;
  syserrno?: number;
  syserrstr?: string;
} {
  return binding.BZ2_bzWrite(b, buf);
}
export function BZ2_bzWriteClose(b: BZFILE): {
  bzf: BZFILE;
  bz2err: number;
  bz2errstr: string;
  syserrno?: number;
  syserrstr?: string;
  nbytes_in: number;
  nbytes_out: number;
} {
  return binding.BZ2_bzWriteClose(b);
}

// globalThis["exports"] = binding;
module.exports = binding;
