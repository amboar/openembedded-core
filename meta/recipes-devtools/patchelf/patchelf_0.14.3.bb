SUMMARY = "Tool to allow editing of RPATH and interpreter fields in ELF binaries"
DESCRIPTION = "PatchELF is a simple utility for modifying existing ELF executables and libraries."
HOMEPAGE = "https://github.com/NixOS/patchelf"

LICENSE = "GPL-3.0-only"

SRC_URI = "git://github.com/NixOS/patchelf;protocol=https;branch=master \
           file://handle-read-only-files.patch \
           "
SRCREV = "bf3f37ec29edcdb3e2a163edaf84aeece39f8c9d"

S = "${WORKDIR}/git"

LIC_FILES_CHKSUM = "file://COPYING;md5=d32239bcb673463ab874e80d47fae504"

inherit autotools

BBCLASSEXTEND = "native nativesdk"
