"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
exports.getgrgid = exports.getpwuid = void 0;
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
// globalThis["exports"] = binding;
module.exports = binding;
