const deduba_os = require("./prebuilds/linux-x64/node.napi");

module.exports = { getpwuid: deduba_os.getpwuid, getgrgid: deduba_os.getgrgid };

function testuser(u) {
  usr = deduba_os.getpwuid(u);
  grp = deduba_os.getgrgid(usr.gid);
  console.log({ usr, grp });
}
testuser(0);
testuser(1000);
testuser(152);
testuser();
