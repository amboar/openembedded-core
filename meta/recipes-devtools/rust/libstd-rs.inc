SUMMARY = "Rust standard libaries"
HOMEPAGE = "http://www.rust-lang.org"
SECTION = "devel"
LICENSE = "MIT | Apache-2.0"
LIC_FILES_CHKSUM = "file://../../COPYRIGHT;md5=93a95682d51b4cb0a633a97046940ef0"

RUSTLIB_DEP = ""
inherit cargo

DEPENDS:append:libc-musl = " libunwind"
# rv32 does not have libunwind ported yet
DEPENDS:remove:riscv32 = "libunwind"
DEPENDS:remove:riscv64 = "libunwind"

# Embed bitcode in order to allow compiling both with and without LTO
RUSTFLAGS += "-Cembed-bitcode=yes"
# Needed so cargo can find libbacktrace
RUSTFLAGS += "-L ${STAGING_LIBDIR} -C link-arg=-Wl,-soname,libstd.so"

S = "${RUSTSRC}/src/libstd"

CARGO_FEATURES ?= "panic-unwind backtrace"
CARGO_BUILD_FLAGS += "--features '${CARGO_FEATURES}'"
CARGO_VENDORING_DIRECTORY = "${RUSTSRC}/vendor"

do_compile:prepend () {
    export CARGO_TARGET_DIR="${B}"
    # For Rust 1.13.0 and newer
    export RUSTC_BOOTSTRAP="1"
}

do_install () {
    mkdir -p ${D}${rustlibdir}

    # With the incremental build support added in 1.24, the libstd deps directory also includes dependency
    # files that get installed. Those are really only needed to incrementally rebuild the libstd library
    # itself and don't need to be installed.
    #
    # ${B} contains two directories, one for the target architecture and one for the build mode
    # (e.g. "release"). In some cases (e.g. ARMv7) the build directory matches neither ${TARGET_SYS}
    # (due to "unknown" vendor from rust_base_triple()) nor ${RUST_TARGET_SYS} (due to architecture
    # name mangling in rust_base_triple()). Further, rust_base_triple() always assumes a linux
    # OS, so exploit both "unknown" and "linux" in a triple glob to select the right source
    # directory.
    DEPS=${B}/*-unknown-linux-*/${BUILD_DIR}/deps
    rm -f ${DEPS}/*.d
    cp ${DEPS}/* ${D}${rustlibdir}
}
