from distutils.core import (
    Extension,
    setup,
)

mymodule = Extension(
    "libsvm2csv",
    sources = ["libsvm2csv.cpp", "convert.cpp"],
    extra_compile_args=["-std=c++11"],
    language="c++",
)

setup(
    name="libsvm2csv",
    version="0.1.0",
    description="Python SDK for libsvm.",
    ext_modules=[mymodule],
)
