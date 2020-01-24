import os
import setuptools  # noqa: F401  used for build_wheel
from distutils.core import (
    Extension,
    setup,
)


def get_readme():
    BASE_DIR = os.path.dirname(__file__)
    filename = os.path.join(BASE_DIR, "README.md")
    with open(filename) as fin:
        return fin.read()


libsvm2csv_ext = Extension(
    "libsvm2csv",
    sources=["libsvm2csv.cpp", "convert.cpp"],
    extra_compile_args=["-std=c++17"],
    language="c++",
)


setup(
    name="libsvm2csv",
    version="0.1.4",
    description="Convert LIBSVM data to csv format.",
    long_description=get_readme(),
    long_description_content_type="text/markdown",
    author="Andrey Petukhov",
    author_email="andribas404@gmail.com",
    url="https://github.com/andribas404/libsvm2csv",
    ext_modules=[libsvm2csv_ext],
    license="MIT",
    classifiers=[
        "License :: OSI Approved :: MIT License",
        "Programming Language :: Python :: 3",
    ],

)
