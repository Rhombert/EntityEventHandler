#!/usr/bin/env python
import os
import sys

env = SConscript("godot-cpp/SConstruct",
                 duplicate=0)

env_test = env.Clone()

env.Append(
    CXXFLAGS=["-std=c++17"],
    CPPPATH=[
        "src/",
    ]
)

sources = (
    Glob("src/*.cpp") + 
    Glob("src/**/*.cpp")
)

lib_filename = "{}entity_event_handler{}{}".format(
                    env.subst('$SHLIBPREFIX'), 
                    env["suffix"], 
                    env.subst('$SHLIBSUFFIX'))

# Creates a SCons target for the path with our sources.
library = env.SharedLibrary(
    "project/bin/{}".format(lib_filename),
    source=sources,
)

Export("library")
Export("env_test")
# Selects the shared library as the default target.
# Default(library)
prog_test = SConscript("tests/SConscript",
                       duplicate=0)
Default(library, prog_test)
