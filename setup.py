from distutils.core import (
    Extension,
    setup,
)

libsvm2csv_ext = Extension(
    "libsvm2csv",
    sources = ["libsvm2csv.cpp", "convert.cpp"],
    extra_compile_args=["-std=c++17"],
    language="c++",
)

setup(
    name="libsvm2csv",
    version="0.1.0",
    description="Python SDK for libsvm2csv.",
    author="Andrey Petukhov",
    author_email="andribas404@gmail.com",
    ext_modules=[libsvm2csv_ext],
)
