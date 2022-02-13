"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
exports.BZ2_bzWriteClose = exports.BZ2_bzWrite = exports.BZ2_bzWriteOpen = exports.getgrgid = exports.getpwuid = void 0;
// Will load a compiled build if present or a prebuild.
// If no build if found it will throw an exception
var binding = require("node-gyp-build")(__dirname);
// module.exports = binding;
function getpwuid(user) {
    return binding.getpwuid(user);
}
exports.getpwuid = getpwuid;
function getgrgid(group) {
    return binding.getgrgid(group);
}
exports.getgrgid = getgrgid;
const isBZFILE = Symbol("isBZFILE");
function BZ2_bzWriteOpen(f) {
    return binding.BZ2_bzWriteOpen(f);
}
exports.BZ2_bzWriteOpen = BZ2_bzWriteOpen;
function BZ2_bzWrite(b, buf) {
    return binding.BZ2_bzWrite(b, buf);
}
exports.BZ2_bzWrite = BZ2_bzWrite;
function BZ2_bzWriteClose(b) {
    return binding.BZ2_bzWriteClose(b);
}
exports.BZ2_bzWriteClose = BZ2_bzWriteClose;
// globalThis["exports"] = binding;
module.exports = binding;
