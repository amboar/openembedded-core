SUMMARY = "File type identification using libmagic"
DESCRIPTION = "This module uses ctypes to access the libmagic file type \
    identification library. It makes use of the local magic database and supports \
    both textual and MIME-type output."
HOMEPAGE = "http://github.com/ahupp/python-magic"

LICENSE = "MIT"
LIC_FILES_CHKSUM = "file://LICENSE;md5=61495c152d794e6be5799a9edca149e3"

PYPI_PACKAGE = "python-magic"

inherit pypi setuptools3

SRC_URI[sha256sum] = "88f71d04fde4318da32fa03930362f1c6127caa833614563fd53a0fd3438cc3e"

RDEPENDS_${PN} += "file \
                   ${PYTHON_PN}-ctypes \
                   ${PYTHON_PN}-io \
                   ${PYTHON_PN}-logging \
                   ${PYTHON_PN}-shell"

BBCLASSEXTEND = "native"