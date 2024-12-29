from pybind11.setup_helpers import Pybind11Extension, build_ext
from setuptools import setup

ext_modules = [
    Pybind11Extension("libGraph", ["../GraphBindings.cc", "../Graph.cc"]),
]

setup(
    name="libGraph",
    ext_modules=ext_modules,
    cmdclass={"build_ext": build_ext},
)
