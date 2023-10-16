include(ExternalProject)

ExternalProject_Add(
    libgmp
    URL https://gmplib.org/download/gmp/gmp-6.3.0.tar.xz
    URL_HASH SHA512=e85a0dab5195889948a3462189f0e0598d331d3457612e2d3350799dba2e244316d256f8161df5219538eb003e4b5343f989aaa00f96321559063ed8c8f29fd2
    CONFIGURE_COMMAND <SOURCE_DIR>/configure --prefix=<INSTALL_DIR>
    TEST_COMMAND make check
    TEST_BEFORE_INSTALL true
)
