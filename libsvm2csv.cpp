/*

Copyright 2019 Andrey Petukhov

*/

#define PY_SSIZE_T_CLEAN
#include <Python.h>
#include <cerrno>
#include <cstdio>

#include "libsvm2csv.h"

static PyObject* wrapper_convert(PyObject *self, PyObject *args) {
    char *src, *dst;

    /* Parse arguments */
    if (!PyArg_ParseTuple(args, "ss", &src, &dst)) {
        Py_RETURN_NONE;
    }

    FILE *fin = fopen(src, "r");
    FILE *fout = fopen(dst, "w");

    if (fin == NULL || fout == NULL) {
        return PyErr_SetFromErrno(PyExc_OSError);
    }

    convert(fin, fout);
    fclose(fin);
    fclose(fout);
    Py_RETURN_NONE;
}

static PyMethodDef extMethods[] = {
    { "convert",
      wrapper_convert,
      METH_VARARGS,
      "Python interface for C++ convert() function" },
    { NULL, NULL, 0, NULL }
};

static struct PyModuleDef extModule = {
    PyModuleDef_HEAD_INIT,
    "libsvm2csv",
    "A Python module extension for C++ libsvm2csv",
    -1,
    extMethods
};

PyMODINIT_FUNC PyInit_libsvm2csv(void) {
    Py_Initialize();
    return PyModule_Create(&extModule);
}
