# Convert a normal arch (HOST_ARCH, TARGET_ARCH, BUILD_ARCH, etc) to something
# rust's internals won't choke on.
def arch_to_rust_arch(arch):
    if arch == "i586" or arch == "i686":
        return "x86"
    elif arch == "mipsel":
        return "mips"
    elif arch == "mip64sel":
        return "mips64"
    elif arch == "armv7":
        return "arm"
    elif arch == "ppc64":
        return "powerpc64"
    elif arch == "ppc64le":
        return "powerpc64le"
    else:
        return arch

