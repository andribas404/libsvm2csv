
import pathlib
import setuptools
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

HERE = pathlib.Path(__file__).parent
README = (HERE / "README.md").read_text()

setup(
    name="libsvm2csv",
    version="0.1.3",
    description="Convert LIBSVM data to csv format.",
    long_description=README,
    long_description_content_type="text/markdown",
    author="Andrey Petukhov",
    author_email="andribas404@gmail.com",
    url="https://github.com/andribas404/libsvm2csv",
    ext_modules=[libsvm2csv_ext],
    license="MIT",
    classifiers=[
        "License :: OSI Approved :: MIT License",
        "Programming Language :: Python :: 3",
        "Programming Language :: Python :: 3.7",
    ],

)
