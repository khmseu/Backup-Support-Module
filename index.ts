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
// globalThis["exports"] = binding;
module.exports = binding;
